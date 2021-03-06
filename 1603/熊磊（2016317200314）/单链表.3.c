#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*Linklist;

void Initlist(Linklist *L)
{
    *L=(Linklist)malloc(sizeof(Node));
    (*L)->next=NULL;
}

void CreatFromHead(Linklist L)
{
    Node *s;
    char c;
    int flag=1;
    while(flag)
    {
        c=getchar();
        if(c!='h')
        {
            s=(Node*)malloc(sizeof(Node));
            s->data=c;
            s->next=L->next;
            L->next=s;/*此处错了*/
        }
        else
            flag=0;
    }
}

void CreatFromTail(Linklist L)
{
    Node *s,*r;
    char c;
    int flag=1;
    r=L;/*此处易错*/
    while(flag)
    {
        c=getchar();
        if(c!='h')
        {
            s=(Node*)malloc(sizeof(Node));
            s->data=c;
            r->next=s;
            r=s;
        }
        else
        {
            flag=0;
            r->next=NULL;
        }
    }
}

void Display(Linklist L)
{
    if(L->next==NULL)
        printf("单链表为空!\n");
    else
    {
        while(L->next!=NULL)
        {
            L=L->next;
            printf("%c",L->data);
        }
        printf("\n");
    }
}

void Insert(Linklist L,int num,char c)
{
    int i=0;
    Node *s;
    s->data=c;

    if(num<1)
        printf("插入位置错误!\n");
    else if(num==1)
    {
        s->next=L->next;
        L->next=s;
    }
    else
    {
       while(L->next!=NULL)
       {
           i++;
           if(i==num)
              break;
           L=L->next;
       }
       s->next=L->next;
       L->next=s;
    }

}

int main()
{
    Linklist L1,L2;
    Initlist(&L1);
    Initlist(&L2);

    CreatFromHead(L1);
    Display(L1);
    Insert(L1,5,'k');
    Display(L1);

    CreatFromTail(L2);
    Display(L2);

    return 0;
}
