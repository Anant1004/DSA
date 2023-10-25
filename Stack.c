#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty (struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull (struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push (struct stack*ptr,int val){
    if(isFull(ptr)){
        printf("Stack overflow\n");
        printf("cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop (struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow");
        printf("Cannot pop from the stack");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s,10);
    push(s,9);
    push(s,8);
    push(s,7);
    push(s,6);
    push(s,5);
    push(s,4);
    push(s,3);
    push(s,2);
    push(s,1);

    printf("popped the first item you pushed : %d \n",pop(s));
    printf("popped the first item you pushed : %d \n",pop(s));
    printf("popped the first item you pushed : %d \n",pop(s));
    printf("popped the first item you pushed : %d \n",pop(s));


    if(isEmpty(s)){
        printf("The stack in empty\n");
    }
    else{
        printf("The stack is full\n");
    }
    return 0;
}