#include<conio.h>
#include<stdio.h>
int fun1(char x)
{
	switch(x)
	{
		case '*':
		case '/':
			return 4;
		case '+':
		case '-':
			return 3;
	}
	return 0;
}

int fun2(char x)
{
	switch(x)
	{
		case '*':
		case '/':
			return 4;
		case '+':
		case '-':
			return 3;
		case '(':
			return 2;
		case ')':
			return 1;
	 }
	return 0;
}

void main()
{
	char exp[15], p[15], stack[15], ch;
	int i, j=0, top=-1;
clrscr();
	printf("\nInfix Expression:\t");
	gets(exp);
	top++;
	stack[top]='^';
	for(i=0; exp[i]!='\0'; i++)
	{
		ch=exp[i];
		if(ch=='*' || ch=='/' || ch=='-' || ch=='+')
		{
			while(fun1(ch)<=fun2(stack[top]))
			{
				p[j]=stack[top];
				top--;
				j++;
			}
			top++;
			stack[top]=ch;
		}

else if(ch=='(')
		{
			top++;
			stack[top]=ch;
		}
		else if(ch==')')
		{
			while(stack[top]!='(')
			{
				p[j]=stack[top];
				top--;
				j++;
			}
			top--;
		}
		else
		{
			p[j]=ch;
			j++;
		}
	}
while(stack[top]!='^')
	{
		p[j]=stack[top];
		j++;
		top--;
	}
	p[j]='\0';
	printf("\nPostfix Expression:\t");
	puts(p);
	getch();
}
