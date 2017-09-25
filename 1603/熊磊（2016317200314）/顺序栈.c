#include<stdio.h>

typedef int StackElementType;
#define StackSize 20

typedef struct Stack
{
    StackElementType elem[StackSize];
    int top;
}Stack;
void InitStack(Stack *L)
{
    L->top=-1;
}

void Push(Stack *L,StackElementType *x)
{
    L->top++;
    L->elem[L->top]=*x;
}
int Pop(Stack *L,StackElementType *x)
{
    if(L->top==-1)//��ջ
    {
        return 0;
    }
    else
    {
        *x=L->elem[L->top];
        L->top--;
        return 1;
    }
}
int IsEmpty(Stack *L)
{
    if(L->top==-1)
        return 1;
    else
        return 0;
}
int IsFull(Stack *L)
{
    if(L->top==-1)
        return 0;
    else
        return 1;
}
int GetTop(Stack *L,StackElementType *x)
{
    if(L->top==-1)
    {
        return 0;
    }
    else
    {
       *x=L->elem[L->top];
       return 1;
    }
}

int main()
{
    int i;
    StackElementType x,a[10]={1,10,8,9,6,7,2,5,4,3};
    Stack L;
    InitStack(&L);
    for(i=0;i<10;i++)
    {
        if(L.top<StackSize-1)
            Push(&L,&a[i]);
        else
            printf("ջ����!\n");
    }


    Pop(&L,&x)==1?printf("%d\n",x):printf("ջΪ��!\n");
    GetTop(&L,&x)==1?printf("%d\n",x):printf("ջΪ��!\n");
    while(L.top>=0)
    {
         if(Pop(&L,&x)==1)
            printf("%d ",x);
    }
    printf("\n");
    return 0;
}
