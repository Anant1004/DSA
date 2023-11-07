#include<stdio.h>

void PrintArray(int *A,int n){
    for (int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    
}
void SelectionSort(int *A, int n){
    int IndexofMin, temp;
    for (int i = 0; i < n-1; i++){
        IndexofMin = i;
        for (int j = i+1; j < n; j++){
            if(A[j]<A[IndexofMin]){
                IndexofMin = j;
            }
        }
        temp = A[i];
        A[i] = A[IndexofMin];
        A[IndexofMin] = temp;
        
    }
    
}

int main(){
    int A[] = {12,34,23,35,45,56,67,87};
    int n = 8;
    PrintArray(A,8);
    SelectionSort(A,8);
    PrintArray(A,8);
}