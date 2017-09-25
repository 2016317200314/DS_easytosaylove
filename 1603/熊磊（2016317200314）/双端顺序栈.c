#include<stdio.h>
#define M 10
typedef int StackElementType;
typedef struct Dqstack
{
    StackElementType elem[M];
    int top[2];

}Dqstack;
void Initstack(Dqstack *L)
{
    L->top[0]=-1;
    L->top[1]=M;
}

int Push(Dqstack *L,int i,StackElementType x)
{
    if(L->top[0]+1==L->top[1])/*ջ����*/
        return 0;
    else
    {
        switch(i)
        {
        case 0:
            L->top[0]++;
            L->elem[L->top[0]]=x;
            break;
        case 1:
            L->top[1]--;
            L->elem[L->top[1]]=x;
            break;
        default:
            return 0;
        }
    }
}

int Pop(Dqstack *L,int i,StackElementType *x)
{
    if(L->top[0]>-1||L->top[1]<M)
    {
        switch(i)
        {
        case 0:
            *x=L->elem[L->top[0]];
            L->top[0]--;
            break;
        case 1:
            *x=L->elem[L->top[1]];
            L->top[1]++;
            break;
        default:
            return 0;
        }
    }
    else
        return 0;
    return 1;
}

int GetTop(Dqstack *L,StackElementType *x,StackElementType *y)
{
    if(L->top[0]>-1||L->top[1]<M)
    {
        if(L->top[0]>-1&&L->top[1]==M)
            *x=L->elem[L->top[0]],*y=-1;
        else if(L->top[0]==-1&&L->top[1]<M)
            *y=L->elem[L->top[1]],*x=-1;
        else
            *x=L->elem[L->top[0]],*y=L->elem[L->top[1]];
        return 1;
    }
    else
        return 0;
}

int main()
{
    int i,a[10]={10,9,1,4,2,5,7,8,3,6};
    StackElementType x,y;
    Dqstack L;
    Initstack(&L);

    for(i=0;i<10;i++)
    {
        if(i<5)
            Push(&L,0,a[i]);
        else
            Push(&L,1,a[i]);
    }
    if(Push(&L,0,11)==0)
        printf("��������!\n");

    Pop(&L,0,&x);
    Pop(&L,1,&y);
    printf("%d %d\n",x,y);

    GetTop(&L,&x,&y);
    if(x!=-1&&y!=-1)
        printf("%d %d\n",x,y);
    else if(x==-1&&y!=-1)
        printf("%d\n",y);
    else if(x!=-1&&y==-1)
        printf("%d\n",x);
    return 0;
}
