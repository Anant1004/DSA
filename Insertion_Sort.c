#include<stdio.h>

void PrintArray(int* A,int n){
    for (int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n"); 
}
void InsertionSort(int *A,int n){
    int key ,j;
    for (int i = 0; i < n; i++)
    {
        key = A[i];
        j = i-1;
        while (j>=0 && A[j] > key)       
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=key;
    }
    
}

int main(){
    int A[]={12,34,65,76,87,54,56,78,90,33,};
    int n = 10;
    PrintArray(A,n);
    InsertionSort(A,n);
    PrintArray(A,n);
    return 0;
}