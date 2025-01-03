#include <iostream>
using namespace std;
void nhap(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << "Nhap phan tu thu " << i+1 << " : ";
        cin >> arr[i];
    }
}
void xuat(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << " " << arr[i];
    }
}
void merge(int a[], int sizeA, int b[], int sizeB, int C[]){
    int i=0; int j=0; int k=0;

    while (i<sizeA && i<sizeB){
        if(a[i] <= b[j]){
            C[k++]=a[i++];
        }else{
            C[k++]=b[j++];
        }
    }

    while(i<sizeA){
        C[k++]=a[i++];
    }

    while(j<sizeB){
        C[k++]=b[j++];
    }
}
int main(){
    int sizeA, sizeB;

    cout << "Nhap kich thuoc mang A: ";
    cin >> sizeA;
    int A[sizeA];
    nhap(A,sizeA);

    cout << "Nhap kich thuoc mang B: ";
    cin >> sizeB;
    int B[sizeB];
    nhap(B,sizeB);

    int sizeC = sizeA + sizeB;
    int C[sizeC];

    merge(A, sizeA, B, sizeB, C);
    cout << "Mang sau khi tron la: " << endl;
    xuat(C,sizeC);
    return 0;
}
