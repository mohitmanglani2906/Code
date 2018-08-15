#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void create(int n);
void display();
void displayend();
void insertatlast();
void insertatbig();
void insertafternum();
void insertbeforenum();
struct node
{
    int data;
    struct node *next;
    struct node *pre;
}*head,*last;

int main()
{
        int n;
        printf("\nenter no of nodes");
        scanf("%d",&n);
        printf("\n now we create a doubly link list\n");
        create(n);
        printf("\n now we display a link list\n");
        display();
        printf("\n display a data from end ");
        displayend();
        printf("\n now we insert a node at last");
        insertatlast();
        printf("\n\n");
        display();
        printf("\n now we insert a node at first ");
        insertatbig();
        printf("\n\n");
        display();
        printf("\n now we enter a value a node after num ");
        insertafternum();
        printf("\n\n displaying of the data");
        display();
        printf("\n now we enter an element before num");
        insertbeforenum();
        display();

                 return 0;
            }
void create(int n)
{
            int i,data;
            struct node *nnode;
            head=(struct node *)malloc(sizeof(struct node));

            printf("\n enter a data of node 1");
            scanf("%d",&data);
            if(head==NULL)
            {
                printf("\n unable to allocate a memory");
            }
            else
            {
                head->data=data;
                head->next=NULL;
                head->pre=NULL;
                last=head;
            }
            for(i=2;i<=n;i++)
            {
                nnode=(struct node *)malloc(sizeof(struct node));
                printf("\n enter a data of bode %d ", i);
                scanf("%d",&data);
                if(nnode==NULL)
                {
                    printf("\n unable to allocate memory ");
                }
                else
                {
                    nnode->data=data;
                    nnode->next=NULL;
                    nnode->pre=last;
                    last->next=nnode;
                    last=nnode;
                }

            }
}
void displayend()
{
     struct node *temp;
     if(last==NULL)
    {
        printf("\n empty list");
    }
    else
    {

        temp=last;
        while(temp!=NULL)
       {
            printf("\n data= %d",temp->data);
            temp=temp->pre;
       }
        free(temp);
    }

}
void insertatlast()
{
    struct node *nnode,*temp;
    int data;
    printf("\n enter a data you want to insert at last ");
    scanf("%d",&data);
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=data;
    nnode->next=NULL;
    nnode->pre=last;
    last->next=nnode;
    last=nnode;
}
void insertatbig()
{
    int data;
    struct node *fnode;
    fnode=(struct node *)malloc(sizeof(struct node));
    printf("\n enter a data you want to insert at first");
    scanf("%d",&data);
    fnode->data=data;
    fnode->pre=NULL;
    fnode->next=head;
    head->pre=fnode;
    head=fnode;
}
void insertafternum()
{
    struct node *nnode,*temp;
    int data,num;
    nnode=(struct node *)malloc(sizeof(struct node));
    printf("\n enter a value that after you want to insert a value");
    scanf("%d",&num);
    printf("\n enter a value you want to insert");
    scanf("%d",&data);
    nnode->data=data;
    temp=head;
    while(temp->data!=num)
    {
        temp=temp->next;
    }
        nnode->next=temp->next;
        nnode->pre=temp;
        temp->next=nnode;
        temp->next->pre=nnode;
}
void insertbeforenum()
{
    struct node *nnode,*temp;
    int val;
    printf("\n enter a value you want to insert");
    scanf("%d",&val);
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=val;
    temp=head;
    while(temp->data!=val)
    {
        temp=temp->next;
    }
    nnode->next=temp;
    nnode->pre=temp->pre;
    temp->pre=nnode;
    temp->pre->next=nnode;

}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nempty list");
        printf("\nempty list");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("\n data= %d ",temp->data);
            temp=temp->next;

        }
    }


}


