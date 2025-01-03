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
void merge(int a[], int left, int mid, int right) {
    int sizeA = mid - left + 1;
    int sizeB = right - mid;
    int L[sizeA], R[sizeB];
    for (int i = 0; i < sizeA; i++)
        L[i] = a[left + i];
    for (int j = 0; j < sizeB; j++)
        R[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < sizeA && j < sizeB) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < sizeA) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < sizeB) {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int left, int right) {
    if (left >= right) return; 

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, mid, right);
}
int main(){
    int sizeA;
    cout << "Nhap kich thuoc mang A: ";
    cin >> sizeA;
    int A[sizeA];
    nhap(A, sizeA);
    mergeSort(A, 0, sizeA - 1);
    cout << "Mang sau khi sap xep la: " << endl;
    xuat(A, sizeA);

    return 0;
}
