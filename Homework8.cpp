#include <stdio.h>
#include <stdlib.h>
//Ðinh nghia cau truc 
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

typedef struct Node Node;
//tao va tra ve mot nut voi he so va so mu duoc chi dinh 
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}
//them mot nut moi, neu he so bang 0 thi khong thuc hien nua
void insert(Node** head, int coefficient, int exponent) {
    if (coefficient == 0) return; // Không thêm n?u h? s? là 0

    Node* newNode = createNode(coefficient, exponent);
    newNode->next = *head;
    *head = newNode;
}
//in da thuc
void printPolynomial(Node* head) {
    Node* current = head;
    while (current) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next) {
            printf(" + ");
        }
        current = current->next;
    }
    if (!head) {
        printf("0");
    }
    printf("\n");
}
//giai phong bo nho da cap phat
void freePolynomial(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* polynomial = NULL;
    int coeff, exp;

    printf("Nhap he so va mu (Nhap -1 de ket thuc):\n");
    while (1) {
        printf("He so: ");
        scanf("%d", &coeff);
        if (coeff == -1) break;

        printf("Mu: ");
        scanf("%d", &exp);

        insert(&polynomial, coeff, exp);
    }

    printf("Da thuc: ");
    printPolynomial(polynomial);

    freePolynomial(polynomial);
    return 0;
}

