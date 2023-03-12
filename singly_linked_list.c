#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data_field;
	struct node *next;
	//struct node *prev;
} *new_node, *temp, *b, *e;

typedef struct node Node;

void traverse_in_order();
void ins_at_beg(int);
void ins_at_end(int);
void del(int);
void search(int);

int count=0;

int main()
{
	int choice, item, after, ch, num;

	temp=new_node=b=e=NULL;

	do
	{
		printf("\n1.\tInsert at begining\n");
		printf("\n2.\tInsert at end\n");
		printf("\n3.\tTraverse\n");
		printf("\n4.\tDelete\n");
		printf("\n5.\tSearch\n");
		printf("\n6.\tExit\n");

		printf("\nEnter your choice:\t");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\n\nEnter the item:\t");
				scanf("%d", &item);
				ins_at_beg(item);
				break;
			case 2:
				printf("\n\nEnter the item:\t");
				scanf("%d", &item);
				ins_at_end(item);
				break;
			case 3:
				traverse_in_order();
				break;
			case 4:
				printf("\n\nEnter the item to be deleted:\t");
				scanf("%d", &num);
				del(num);
				break;
			case 5:
				printf("\n\nEnter the number to be searched:\t");
				scanf("%i", &num);
				search(num);
				break;
			case 6:
				exit(0);
			default:
				printf("\n\nWrong choice");
		}
		//fflush(stdin);
		//printf("\n\nWanna continue:\t");
		//scanf("%i", &ch);
	}
	while(ch!=6);

return 0;
}
void traverse_in_order()
{
	Node *t;

	t=b;

	if(t==NULL)
	{
		printf("\n\nLL underflow");
	}

	printf("\n");

	while(t!=NULL)
	{
		printf("%d\n", t->data_field);
		t=t->next;
	}
}
void ins_at_beg(int item)
{
	new_node=(Node *)malloc(sizeof(Node));
	new_node->data_field=item;

	if(b==NULL)
	{
		e=b=temp=new_node;
		temp->next=NULL;
		//temp->prev=NULL;

	}
	else
	{
		temp=b;

		/*temp->prev=new_node;
		new_node->next=temp;
		new_node->prev=NULL;
		temp=new_node;
		b=new_node;*/

		new_node->next=temp;
		temp=new_node;
		b=new_node;
	}

	count++;
}
void ins_at_end(int item)
{
	new_node=(Node *)malloc(sizeof(Node));
	new_node->data_field=item;

	if(e==NULL)
	{
		e=b=temp=new_node;
		temp->next=NULL;
		//temp->prev=NULL;

	}
	else
	{
		temp=e;

		temp->next=new_node;
		//new_node->prev=temp;
		new_node->next=NULL;
		temp=new_node;
		e=new_node;

	}

	count++;
}
void del(int num)
{
	Node *p, *d;

	temp=b;

	if(b==NULL)
		printf("\n\nLL underflow\n");
	else
	{
		while(temp->data_field!=num)
		{
			temp=temp->next;

			if(temp==NULL)
			{
				break;
			}
		}

		if(temp==NULL)
		{
			printf("\n\nSorry...required number not found");
		}
		else if(temp==b && temp==e)
		{
			temp=new_node=e=b=NULL;

			printf("\n\nCongrats...Num deleted (LL totally empty)");

		}

		else
		{
			if(temp==b)
			{
				temp=temp->next;
				//temp->prev=NULL;

				b=temp;

				printf("\n\nCongrats...Num deleted");

				count--;
			}
			else if(temp==e)
			{
				//temp=temp->prev;

				d=b;

				while(d->next!=temp)
				{
					d=d->next;
				}

				d->next=NULL;

				e=d;

				printf("\n\nCongrats...Num deleted");

				count--;
			}
			else
			{
				p=temp->next;

				d=b;

				while(d->next!=temp)
				{
					d=d->next;
				}

				/*temp=temp->prev;
				temp->next=p;*/

				d->next=p;

				printf("\n\nCongrats...Num deleted");

				count--;
			}
		}
	}
}
void search(int num)
{
	temp=b;

	if(temp==NULL)
	{
		printf("\n\nLL underflow");
	}
	else
	{
		while(temp->data_field!=num)
		{
			temp=temp->next;

			if(temp==NULL)
			{
				break;
			}
		}
		if(temp==NULL)
		{
			printf("\n\nSorry.......number not found");
		}
		else
		{
			printf("\n\n%i found at %p location (node %i)", num, temp, count);
		}
	}
}
