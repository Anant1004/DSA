#include<stdio.h>

void PrintArray(int* A,int n){
    for (int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n"); 
}
void BubbleSort(int* A,int n){
    int temp;
    int issorted = 0; 
    for (int i = 0; i < n-1; i++)
    {
        printf("passed : %d\n",i+1);
        issorted = 1;
        for (int j = 0; j < n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                issorted = 0;
            }
        }
        if(issorted){
            return;
        }
        
    }
}
int main(){
    int A[]={1,2,3,4,45,12,14,27,89,54};
    // int A[]={14,12,23,34,55,76,47,58,39,67};
    int n =10;

    PrintArray(A,n);
    BubbleSort(A,n);
    PrintArray(A,n);
    return 0;
}