// Deletion in Circular Linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
    struct node
    {
        int data;
        struct node *next;
    }*head;
    void create(int n);
    void display();
    void deletelastnode();
    void deletebignode();
    void deletenumnode();
        int main()
            {
                    int n;
                        printf("\n enter no of nodes:");
                        scanf("%d",&n);
                        printf("\n now we create a link  list:");
                    create(n);
                        printf("\n now we display a link list");
                    display();
                        printf("\ndeletion of num node");
                    deletenumnode();
                        printf("\n\n");
                    display();
                        printf("\n now we delete the node at first");
                    deletebignode();
                            printf("\n\n");
                    display();
                        printf("\n now we delete a last node");
                    deletelastnode();
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
                        printf("\nunable to allocate a memory");
                    }
                    else
                  {
                    printf("\n enter a data of 1st node: ");
                    scanf("%d",&data);
                        head->data=data;
                        head->next=NULL;
                        temp=head;

                        for(i=2;i<=n;i++)
                        {
                              nnode=(struct node *)malloc(sizeof(struct node));
                            printf("\n enter a data of node %d ",i);
                            scanf("%d",&data);
                                if(nnode==NULL)
                                {
                                    printf("\nunable to allocate a memory");
                                    break;
                                }
                            nnode->data=data;
                            nnode->next=NULL;
                            temp->next=nnode;
                            temp=nnode;

                        }

                    }
                    temp->next=head;
                        printf("\n circular link list created successfully ");

                }
                void deletelastnode()
        {

            struct node *curr,*pre;
            if(curr==head)
            {
                printf("\n empty list");
            }
            else
            {
            curr=head;
                do
                {
                    pre=curr;
                    curr=curr->next;
                }while(curr->next!=head);
                pre->next=head;


                free(curr);

        }
        }
        void deletebignode()
            {
                struct node *curr,*temp;
                    if(curr==head)
                    {
                        printf("\n empty list");
                    }
                    else{
                    temp=head;
                        curr=head;
                            while(curr->next!=head)
                            {
                                curr=curr->next;

                            }
                            curr->next=head->next;
                            head=head->next;
                            free(temp);


                        }


            }
            void deletenumnode()
                {

                    int num;
                     printf("\nenter a data you want to delete");
                            scanf("%d",&num);
                    struct node *curr,*temp;
                        if(curr==head)
                        {
                            printf("\n empty list");
                        }
                        else
                        {

                            curr=head;
                            temp=head;
                                while(curr->data!=num)
                                {
                                    temp=curr;
                                    curr=curr->next;


                                }
                                if(curr->data==num)
                                {

                                    temp->next=curr->next;
                                    free(curr);

                                }



                        }


                }
                void display()
                    {
                        struct node *curr;
                        if(head==NULL)
                        {
                            printf("\n list is empty");
                        }
                        else
                        {
                        curr=head;
                            do
                            {
                                 printf("\n data= %d",curr->data);
                                  curr=curr->next;
                            }while(curr!=head);
                        }

                    }
