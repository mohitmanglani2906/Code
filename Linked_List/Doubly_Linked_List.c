// Doubly linked list Deletion and insertion
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void create(int n);
void display();
void deleteatlast();
void deleteatfirst();
void deleteafternum();
void deletebeforenum();
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

                printf("\n now we delete a node before num ");
                deletebeforenum();
                display();

                printf("\n now we delete a node after a num ");
                deleteafternum();
                display();

                printf("\n  now we delete a first node");
                deleteatfirst();
                display();

                printf("\n now we delete a last node");
                deleteatlast();
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
void deleteatlast()
{
    struct node *temp,*curr;
    temp=head;
            do
            {
                curr=temp;
                temp=temp->next;
            }while(temp->next!=NULL);
                curr->next=NULL;
                free(temp);
}
void deleteatfirst()
{
        struct  node *temp;
        temp=head;
        temp->next->pre=NULL;
        head=temp->next;
}
void deleteafternum()
{
        struct node *temp,*curr,*ptr;
        int val;
        printf("\n enter a  value after that you want to delete a node ");
        scanf("%d",&val);
        ptr=head;
        while(ptr->data!=val)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=temp->next;
        temp->next->pre=ptr;
}
void deletebeforenum()
{
        struct  node *curr,*temp,*ptr;
        int val;
        printf("\n enter a value before you want to delete an element");
        scanf("%d",&val);
        ptr=head;
        while(ptr->data!=val)
        {
            ptr=ptr->next;
        }
        temp=ptr->pre;
        if(temp==head)
        {
            deleteatfirst();
        }
        else
        {
            ptr->pre=temp->pre;
            temp->pre->next=ptr;
        }
}









