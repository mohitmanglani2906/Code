#include<stdio.h>
#include<stdlib.h>

struct dbl
{	int data;
	struct dbl *prev, *next;
};
typedef struct dbl node;
node *first, *curr, *last, *temp;

void create();
void ins(int);
void disp();
void del(int);
int i=0;

void main()
{	int n,ch;
	first = NULL;
	last = NULL;
	curr = NULL;
	repeat:
	printf("\nEnter Your Choice :");
	printf("\n1. Create  2. Insert  3. Delete  4. Print  5. Exit \n");
	scanf("%d",&ch);
	switch (ch)
	{
		case 1 :
			first = NULL;
			last = NULL;
			curr = NULL;
			create();
	    break;

		case 2 :
			if(first == NULL && last == NULL && curr== NULL)
				printf("\n Empty List");
			else
			{	printf("\n Enter The Value :");
				scanf("%d",&n);
				ins(n);
			}

		break;

		case 3 :
			if(first == NULL && last == NULL && curr== NULL)
				printf("\n Empty List");
			else
			{	printf("\n Enter Node To Delete : ");
				scanf("%d",&n);
				del(n);
			}
		break;

		case 4 :
			if(first == NULL && last == NULL && curr== NULL)
				printf("\n Empty List");
			else
				disp();
		break;

		case 5 : exit(1);
	}
	goto repeat;
}

void create()
{	int n,no_ofnodes;
	first = (node*) malloc (sizeof(node));
	printf("Enter no of nodes: ");
	scanf("%d",&no_ofnodes);
	printf("\n Enter The Value :");
	scanf("%d",&n);
	first->data=n;
	first->next=NULL;
	first->prev=NULL;
	temp=curr=first;
	i++;
	while(i<=no_ofnodes)
	{	scanf("%d",&n);
		last=(node*)malloc(sizeof(node));
		last->data=n;
		last->next=NULL;
		last->prev=first;
		first->next=last;
		first=last;
		i++;
	}
	first=temp;
}

void ins(int n)
{	node *nxt;
	int p,j,k;
	printf("\nEnter The Position 1.First 2.At given position 3.Last: ");
	scanf("%d",&p);
	nxt=(node *)malloc(sizeof(node));
	i++;
	nxt->data=n;
	nxt->prev=NULL;
	nxt->next=NULL;
	switch(p)
	{	case 1:	nxt->next=temp;
				temp->prev=nxt;
				temp=nxt;
			break;
		case 2:	curr=temp;
				printf("Enter position:");
				scanf("%d",&j);
				k=0;
				while(k<j-1 && curr->next!= NULL)
				{	curr=curr->next;
					k++;
				}
				nxt->prev=curr;
				nxt->next=curr->next;
				curr->next->prev=nxt;
				curr->next=nxt;
			break;
		case 3:	last->next=nxt;
				nxt->prev=last;
				last=nxt;
			break;
		default:	printf("Wrong choice!!!");
			break;
	}
	/*if(p==1)
	{	nxt->next=temp;
		temp->prev=nxt;
		temp=nxt;
	}
	else
	{	temp1=curr;
		i=1;
		while(i<p-1 && temp1->next!= NULL)
		{	temp1=temp1->next;
			i++;
		}
		t->prev=temp1;
		t->next=temp1->next;
		temp1->next->prev=t;
		temp1->next=t;
	}*/
}

void disp()
{	int d;
	printf("\n Choice Your Output :");
	printf("\t1. FIFO(L->R) 2. LIFO(R->L)");
	scanf("%d",&d);
	if(d==1)
	{	curr=temp;
		while(curr!=NULL)
		{	printf("%d ",curr->data);
			curr=curr->next;
		}
	}
	else
	{	curr=last;
		while(curr!=NULL)
		{	printf("%d ",curr->data);
			curr=curr->prev;
		}
	}
}

void del(int x)
{	node *s;
	curr=temp;
	s=temp;

	if(temp->data==x)
	{	i--;
		temp=temp->next;
		temp->prev = NULL;
		printf("first node deleted...");
		curr=temp;
	}
	else
	{	while(curr->data!=x && curr->next!=NULL)
		{	s=curr;
			curr=curr->next;
		}
		if(curr->data==x)
		{	s->next = curr->next;
			curr->next->prev = s;
			free(curr);
			printf("node deleted: %d",x);
			i--;
		}
		else
			printf("\n node is not find:");
	}
	curr=temp;
}
