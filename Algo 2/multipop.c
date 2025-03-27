#include<stdio.h>
#include<stdlib.h>

struct stack {
    int *arr;
    int size;
    int top;
};

int isfull(struct stack *ptr){
    return(ptr->top== ptr->size -1);     
}
int isempty(struct stack *ptr){
    return(ptr->top == -1);     
}

int push(struct stack *ptr,int val){
    if(isfull(ptr)){
        printf("stack Overflow!\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack Underrflow!\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;      
        return val;  
    }
}

int multipop(struct stack *ptr,int n){
    for(int j=0;j<n;j++)
    pop(ptr);
}

void display(struct stack *ptr){
    for(int i=0;i<=ptr->top;i++){
        printf("%d\t",ptr->arr[i]);
    }
}

int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    push(s,5);
    push(s,6);
    push(s,8);
    push(s,1);
    push(s,9);
    display(s);

    printf("\n");


    multipop(s,3);
    display(s);
}