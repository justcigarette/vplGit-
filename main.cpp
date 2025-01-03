#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100


typedef struct {
    char name[50];
    int price;
    int quantity;
} Product;


typedef struct CartNode {
    Product products[MAX_PRODUCTS];
    int product_count; 
    struct CartNode* next;  
} CartNode;

typedef struct {
    CartNode* front; 
    CartNode* rear;   
} Queue;

Product create_product(char* name, int price, int quantity) {
    Product product;
    int i = 0;
   
    while (name[i] != '\0' && i < 49) {
        product.name[i] = name[i];
        i++;
    }
    product.name[i] = '\0';  
    product.price = price;
    product.quantity = quantity;
    return product;
}

CartNode* create_cart() {
    CartNode* new_cart = (CartNode*)malloc(sizeof(CartNode));
    new_cart->product_count = 0;
    new_cart->next = NULL;
    return new_cart;
}

void add_product_to_cart(CartNode* cart, Product product) {
    cart->products[cart->product_count] = product;
    cart->product_count++;
}

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, CartNode* cart) {
    if (q->rear == NULL) {
        q->front = q->rear = cart;
    } else {
        q->rear->next = cart;
        q->rear = cart;
    }
}

CartNode* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    CartNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return temp;
}

int total_amount_collected(Queue* q) {
    int total = 0;
    CartNode* current = q->front;
    while (current != NULL) {
        for (int i = 0; i < current->product_count; i++) {
            total += current->products[i].price * current->products[i].quantity;
        }
        current = current->next;
    }
    return total;
}

int count_product_sold(Queue* q, char* product_name) {
    int count = 0;
    CartNode* current = q->front;
    while (current != NULL) {
        for (int i = 0; i < current->product_count; i++) {
            int j = 0;
            int match = 1;
            while (product_name[j] != '\0' && current->products[i].name[j] != '\0') {
                if (product_name[j] != current->products[i].name[j]) {
                    match = 0;
                    break;
                }
                j++;
            }
            if (match && product_name[j] == '\0' && current->products[i].name[j] == '\0') {
                count += current->products[i].quantity;
            }
        }
        current = current->next;
    }
    return count;
}

void free_cart(CartNode* cart) {
    free(cart);
}

int main() {

    Product product_a = create_product("San pham A", 100, 2);
    Product product_b = create_product("San pham B", 200, 3);
    Product product_c = create_product("San pham C", 50, 5);

    CartNode* cart1 = create_cart();
    add_product_to_cart(cart1, product_a);
    add_product_to_cart(cart1, product_b);

    CartNode* cart2 = create_cart();
    add_product_to_cart(cart2, product_c);
    add_product_to_cart(cart2, product_a);
    
    Queue* queue = create_queue();
    enqueue(queue, cart1);
    enqueue(queue, cart2);

   
    printf("Tong so tien thu duoc: %d\n", total_amount_collected(queue));

 
    printf("So luong san pham A da bán: %d\n", count_product_sold(queue, "San pham A"));

    CartNode* processed_cart = dequeue(queue);
    printf("Gio hang dau tien da duoc thanh toan\n");

    printf("Tong so tien sau khi loai bo gio hang dau tien: %d\n", total_amount_collected(queue));

 
    printf("So luong san pham con lai trong hang doi la: %d\n", count_product_sold(queue, "S?n ph?m A"));


    free_cart(processed_cart);
    free(queue);

    return 0;
}
