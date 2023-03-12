#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5
void ins();
void del();
void exitt();
void traverse();
int rear=-1;
int front=-1;
int queue[max];
void main()
{
	int choice, c;
	clrscr();
	do
	{
                  printf("\n\t 1.Insert\n\t 2.Delete\n\t       	3.Traverse\n\t 4.Exit\n");
		printf("\nEnter your choice:\t");
		scanf("%d", &choice);
switch(choice)
		{
			case 1:
				ins();
				break;
			case 2:
				del();
				break;
			case 3:
				traverse();
				break;
			case 4:
				exitt();
				break;
			defalut:
				printf("\nWrong choice");
		}
		printf("\n\nWanna continue: (Press 0 to exit)\t");
		scanf("%i", &c);
	}
	while(c!=0);
}
void ins()
{
	int item;
	if(front==(1+rear)%max)
	{
		printf("\n\tQueue Overflow\n");
	}
	else
	{
	printf("\n\tEnter queue element:\t");
		scanf("%d", &item);
		if(front==-1)
		{
			front=rear=0;
			queue[rear]=item;
		}
		else
		{
			rear=(rear+1)%max;
			queue[rear]=item;
		}
	}
} 
void del()
{
	int item;
	if(front==-1)
	{
		printf("\n\tQueue Underflow\n");
	}
	else
	{
		item=queue[front];
		printf("\n%d item deleted\n", item);
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%max;
		}
	}
} 
void exitt()
{
	exit(0);
}
void traverse()
{
	int i;
	if(front==-1)
	{
	printf("\n\tQueue Underflow\n");
	}
else
	{
		if(rear>front || rear==front)
		{
			printf("\n\tQueue elements are:");
			for(i=front; i<=rear; i++)
			{
				printf("\t%d", queue[i]);
			}
		}
		else
		{
			for(i=front; i<max; i++)
			{
				printf("\t%d", queue[i]);
			}
			for(i=0; i<=rear; i++)
			{
				printf("\t%d", queue[i]);
			}
		}
	}
}
