#include <stdio.h>
void selection_sort (int colors[],int n);
	for (int i = 0; i < n-1; i++){
		int min = i;
		//tim chi so cua phan tu nho nhat
		for (int  = i+1;j < n ; j ++){
			if(colors[j]<colors[min])
			min = j;
		}
	//doi cho
	if (min !=i){
		int temp = colors[i];
		colors[i] = colors[min];
		colors[min] = temp ;
	}
}
int main (){
	//ma hoa do = 0, xanh = 1, trang =2
	int colors[]={1, 0, 1, 0, 0, 0, 2, 0, 1, 2};
	int n = sizeof(colors)/sizeof(colors[0]);
	selection_sort (colors, n);
	printf ("Ket qua sap xep :");
	for (int i=0;i<n;i++){
		printf	("%d", colors[i]);
	}
	return 0;
	
	
}
