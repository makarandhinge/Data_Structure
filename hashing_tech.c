#include<stdio.h>
#include<stdlib.h>

void division();
void collision();
void folding();
void mid_square();

int i, no, key, records[100];

void main()
{
	int ch;

	for(i=0;i<100;i++)
	{
		records[i]=NULL;
	}

	do
	{
		printf("\n\n1. division\n\n2. folding\n\n3. mid_square\n\n4. exit\n\n");

		printf("\nEnter your choice:\t");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				division();
				break;
			case 2:
				folding();
				break;
			case 3:
				mid_square();
				break;
			case 4:
				exit(0);
			default :
				printf("\n\n\tDear user, it's a wrong choice\n");
		}
	}while(ch!=4);
}
void division()
{
	printf("\n\nEnter  four digit number:\t");
	scanf("%d",&no);

	key=no%97;

	if(records[key]==NULL)
	{
	    records[key]=no;

		printf("\n\n\tElement %d inserted at position %d\n", no, key);
	}
	else
	{
		printf("\n\n\tError.......collision......Alert\n");

		collision();
	}
}
void collision()
{
	while(records[key]!=NULL)
	{
		static int s=0;

		key=s++;

	}

	records[key]=no;

	printf("\n\n\tElement %d inserted at position %d\n", no, key);
}
void folding()
{
	int rem, div;

	printf("\n\nEnter four digit number:\t");
	scanf("\n%d",&no);

	div=no/100;

	rem=no%100;

	key=rem+div;

	while(key>99)
	{
	    key=key%100;
	}

	if(records[key]==NULL)
	{
		records[key]=no;
		printf("\n\n\tElement %d is inserted at position %d\n", no, key);
	}
	else
	{
		printf("\n\n\tError.......collision......Alert\n");

		collision();

	}
}
void mid_square()
{
	char s[10], s1[2];
	long int sqno;

	printf("\n\nEnter four digit number:\t");
	scanf("%d",&no);

	sqno=no;

	sqno=sqno*no;

	sprintf(s,"%ld",sqno);

	strncpy(s1,s+3,2);

	s1[2]='\0';

	key=atoi(s1);

	if(records[key]==NULL)
	{
		records[key]=no;

		printf("\n\n\tElement %d inserted at position %d\n", no, key);
	}
	else
	{
		printf("\n\n\tError.......collision......Alert\n");

		collision();
	}
}
