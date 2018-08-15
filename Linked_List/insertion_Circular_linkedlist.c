// Insertion in Circular linked list
#include<stdio.h>
#include<stdlib.h>
        struct node
            {
                int data;
                struct node *next;
            }*head;
            void create(int n);
            void insertatbig();
            void insertatlast();
            void insertafternum();
            void display();
            int main()
                {
                    int n;
                    printf("\nenter no of nodes ");
                    scanf("%d",&n);
                    create(n);
                    printf("\n the circular list is as below ");
                    display();
                    printf("\n\n now we insert a node at the begning of link list");
                    insertatbig();
                    printf("\n\n");
                    display();
                    insertatlast();
                    printf("\nnow we insert a data at last");
                    display();
                    printf("\nnow we enter a node after a value");
                    insertafternum();
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
            void insertatbig()
                {
                    int data;
                    struct node *nnode,*curr;
                    nnode=(struct node *)malloc(sizeof(struct node));
                    printf("\n\nenter a data you want to insert at first");
                    scanf("%d",&data);
                        if(head==NULL)
                           {
                               printf("\n\nlist is empty");
                           }
                           else
                           {
                            nnode->data=data;
                            nnode->next=head;
                            curr=head;
                            do
                            {
                                curr=curr->next;


                            }while(curr->next!=head);
                            curr->next=nnode;
                            head=nnode;

                           }


                }
                void insertatlast()
                    {
                        int data;
                        struct node *curr,*last;
                        last=(struct node *)malloc(sizeof(struct node));
                        printf("\ninsert a data you want to insert at last");
                        scanf("%d",&data);
                            if(head==NULL)
                            {
                                printf("\noverflow");

                            }
                            else
                            {

                                last->data=data;
                                last->next=head;
                                curr=head;
                                    do
                                    {
                                        curr=curr->next;
                                    }while(curr->next!=head);
                                    curr->next=last;





                            }



                    }
                    void insertafternum()
                        {

                            int num,data;
                            struct node *curr,*numnode;
                            numnode=(struct node *)malloc(sizeof(struct node));
                            printf("\n\nenter a node after that you want to insert a  node");
                            scanf("%d",&num);
                            printf("\nenter a data you want to insert after a num value");
                            scanf("%d",&data);
                                if(head==NULL)
                                   {
                                       printf("\n\noverflow");
                                   }
                                   else
                                    {

                                        numnode->data=data;
                                        curr=head;
                                        while(curr->data!=num)
                                        {
                                            curr=curr->next;
                                        }
                                        numnode->next=curr->next;
                                        curr->next=numnode;



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







