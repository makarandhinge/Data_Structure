#include<stdio.h>
#include<stdlib.h>
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
	
	do
	{
		printf("\n\t 1.Insert\n\t 2.Delete\n\t 3.Traverse\n\t 4.Exit\n");
		printf("\n Enter your choice:\t");
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
				break;
		}
		printf("\n Wanna continue: (press 0 to exit)\t");
		scanf("%i", &c);
	}
	while(c!=0);
}
void ins()
{
	int item;
	if(rear==max-1)
	{
		printf("\n\tQueue Overflow\n");
	}
	else
	{
		printf("\n Enter queue element:\t");
		scanf("%d", &item);
		
		if(front==-1)
		{
			front=rear=0;
			queue[rear]=item;
		}
		else
		{
			rear=rear+1;
			queue[rear]=item;
		}
	}
} 
void del()
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("\n\tQueue Underflow\n");
	}
	else
	{
		item=queue[front];
		front=front+1;
		printf("\n %d item deleted\n", item);
	}
}
void exitt()
{
	exit(0);
}
void traverse()
{
	int i;
	if(rear==-1 || front>rear)
	{
		printf("\n\tQueue Underflow\n");
	}
	else
	{
		printf("\n\tQueue elements are:");
		for(i=front; i<=rear; i++)
			{
				printf("\t%d", queue[i]);
			}
	}
}
