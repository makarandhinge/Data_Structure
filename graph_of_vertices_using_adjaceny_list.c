#include<stdio.h>
#include<conio.h> 
typedef struct node
{
    struct node *next;
    int vertex;
}node;
 
node *G[20];  
//struct node *G[20];
//heads of linked list
int n;
void read_graph(); 
//create adjacency list
void insert(int,int);  
//insert an edge (vi,vj) in te adjacency list
 void print_graph();
main()
{
    
    clrscr();
    read_graph();
   print_graph();
   getch();
}
 

 
void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("Enter number of vertices:");
   
    scanf("%d",&n);
 
   
    for(i=0;i<n;i++)
    {
        G[i]=NULL;
        //read edges and insert them in G[]
       
        printf("Enter number of edges:");
           scanf("%d",&no_of_edges);
 
           for(i=0;i<no_of_edges;i++)
        {
            printf("Enter an edge(u,v):");
            scanf("%d%d",&vi,&vj);
            insert(vi,vj);
        }
    }
}
 
void insert(int vi,int vj)
{
    node *p,*q;
    
    //acquire memory for the new node
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
 
    //insert the node in the linked list number vi
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        //go to end of the linked list
        p=G[vi];
       
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}
void print_graph()
{
   node *p;
   int i;
   for(i=0;i<n;i++)
   {
   		p=G[i];
   		printf("\n Adjacency list of vertex %d\n head ", i);
   		while(p!=NULL)
   			{
   				printf("->%d",p->vertex);
   				p=p->next;
   			}
   }
}
