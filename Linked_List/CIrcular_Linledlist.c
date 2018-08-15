// Circular linked list
#include<stdio.h>
#include<stdlib.h>
        struct node
            {
                int data;
                struct node *next;
            }*head;
            void create(int n);
            void display();
            void insertatpos();
            int main()
                {
                    int n;
                    printf("\nenter no of nodes ");
                    scanf("%d",&n);
                    create(n);

                    printf("\n the circular list is as below ");
                    display();
                        insertatpos();
    printf("\n\n");

    display();

                    return 0;
                }
        void create(int n)
            {
                struct node *nnode,*temp;
                int data,i;
                head=(struct node *)malloc(sizeof(struct node));
                    if(head==NULL)
                    {
                        printf("\nunable to allocate memory ");
                    }
                    else
                    {
                        printf("enter a data of 1st node ");
                        scanf("%d",&data);
                        head->data=data;
                        head->next=NULL;
                        temp=head;
                            for(i=2;i<=n;i++)
                            {
                                nnode=(struct node *)malloc(sizeof(struct node));
                                    if(nnode==NULL)
                                    {
                                        printf("\n unable to allocate memory ");
                                        break;
                                    }
                                    else
                                    {
                                        printf("\nenter the data of node %d  ",i);
                                        scanf("%d",&data);
                                        nnode->data=data;
                                        nnode->next=NULL; //link the last nod of address to the first node
                                        temp->next=nnode;
                                        temp=nnode;

                                    }
                            }

                    }
                     temp->next=head;
                            printf("\n\n circular link list created");


            }

void insertatpos()
        {
                struct node *temp,*nnode;
                nnode=(struct node *)malloc(sizeof(struct node));
            int data,pos,i;
            printf("\n eneter pos");
            scanf("%d",&pos);
            printf("\n enter  a data");
            scanf("%d",&data);
            if(head==NULL)
            {
                printf("\n reva de");
            }
            else
            {
               nnode->data=data;
               nnode->next=NULL;
                   temp=head;
                   for(i=1;i<pos-1;i++)
                   {
                       if(temp->next!=NULL)
                       {
                           temp=temp->next;
                       }
                    nnode->next=temp->next;
                       temp->next=nnode;
                    }

            }

        }

            void display()
            {
                printf("\nhere is the display of link list");


                struct node *curr;
                    if(head==NULL)
                    {
                        printf("\nlist is empty");
                    }
                    else
                    {
                        curr=head;
                         do
                            {
                                printf("\ndata = %d",curr->data);
                              curr=curr->next;

                            }   while(curr!=head);
                    }
            }







