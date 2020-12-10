/*  a)Implement any database using doubly linked list with following options 
i. Insert a record 
ii. Display list forward  
iii. Display list backward 
b) iii. Modify a record  
iv. Delete a record     */

#include<stdio.h>
#include<malloc.h>
typedef struct emp
{
	int empid;
	int sal;
	char name[20];
	char dpt[20];
	struct emp *next;
	struct emp *prev;
}*node;

node accept()  //accept node
{
	node a;
	a=(node)malloc(sizeof(struct emp)); //dynamic memory allocation
	printf("\nEnter Employee Name : ");
	scanf("%s",a->name);
	printf("\nEnter department of Employee : ");
	scanf("%s",a->dpt);
	printf("\nEnter Employee ID : ");
	scanf("%d",&a->empid);
	printf("\nEnter Employee salary : ");
	scanf("%d",&a->sal);
	a->next=NULL;
	a->prev=NULL;
	return(a);
}

node create(node first) //create link list
{
	node a,newnode;
	int ch;
	do
	{
		newnode=accept();
		if(first==NULL)
			first=a=newnode;
		else
		{
			a->next=newnode;
			newnode->prev=a;
			a=a->next;
		}
		printf("\n Do you want to add more nodes(0 for no / 1 for yes)\n");
		scanf("%d",&ch);
	}while(ch==1);
	return first;
}

void display(node first)
{
	node a;
	if (first==NULL)
	printf("\nEMPTY list");
	else 
	{
		printf("\n");
		printf("\n-----------------------------------------------------------------------\n");
		printf("\n\t NAME \t     DEPARTMENT \tEMP_ID  \tSALLERY \n");
		printf("\n-----------------------------------------------------------------------\n");
		while(first!=NULL)
		{
			printf("\t %s ",first->name);
			printf("\t\t %s ",first->dpt);
		    printf("\t\t %d ",first->empid);
		    printf("\t\t %d ",first->sal);
		    printf("\n");
			first=first->next;	
		}
	}
		printf("\n-----------------------------------------------------------------------\n");
}

void search(node first)
{
	node a;
	int key,pos=0,flag=0;
	printf("Enter Employee ID to SEARCH : ");
	scanf("%d",&key);
	a=first;
	while(a!=NULL && a->empid!=key)
	a=a->next;
	if (a==NULL)
	  printf("\nRECORD NOT FOUND..........");
	else
	{
	    	printf("\t %s\n",a->name);
			printf("\t %s\n",a->dpt);
		    printf("%d\n",a->empid);
		    printf("%d\n",a->sal);
	 } 
	
}
node insert_begin(node first) //insertion at begginning
{
	node a;
	a=accept();
	if(first==NULL)
		first=a;
	else
	{
		a->next=first;
		first->prev=a;
		first=a;
	}
	return first;
}

node insert_end(node first) //insertion at end 
{
	node a,newnode;
	newnode=accept();
	if(first==NULL)
		first=newnode;
	else
	{
		a=first;
		while(a->next!=NULL)
		a=a->next;
		a->next=newnode;
		newnode->prev=a;
	}
	return first;
}

node insert_position(node first) //insertion at location
{
	node a,newnode;
	int loc,i=1;
	if (first==NULL)
	  printf("\nEMPTY list...........");
	else 
	{
	printf("\nEnter the location :");
	scanf("%d",&loc);
	a=accept();
	newnode=first;
	while(i<loc-1)
	{
		if(newnode->next==NULL)
		{
			printf("\nUnderflow!!");
	     	return(first);	
		}
		newnode=newnode->next;
		i++;
	}

	a->next=newnode->next;
	newnode->next->prev=a;
	newnode->next=a;
	a->prev=newnode;
	return first;	
	}
	
}

node delete_begin(node first) //delete node at beggining
{
	node a;
	if (first==NULL)
	  printf("\nEMPTY list...........");
	else
	{
		a=first;
		first=first->next;
		printf("Deleted Record is : \n");
		printf("\t %s\n",a->name);
		printf("\t %s\n",a->dpt);
		printf("%d\n",a->empid);
		printf("%d\n",a->sal);
		free(a);
	}
	return first;
}

node delete_end(node first) //delete node at end
{
	node a,b;
	if (first==NULL)
	  printf("\nEMPTY list...........");
	else
	{
		a=first;
		while(a->next!=NULL)
		{
			a=a->next;
		}
		b=a->prev;
		b->next=NULL;
		a->prev=NULL;
		printf("Deleted Record is : \n");
		printf("\t %s\n",a->name);
		printf("\t %s\n",a->dpt);
		printf("%d\n",a->empid);
		printf("%d\n",a->sal);
		free(a);
		
	}
return first;
}

node delete_position(node first) //delete node from any position
{
	node a,b;
	int loc;
	if (first==NULL)
	  printf("\nEMPTY list...........");
	else
	{
		printf("\nEnter Employee ID to delete record : ");
	    scanf("%d",&loc);
		a=first;
		while(a->empid!=loc)
		{
			a=a->next;
		}
		printf("Deleted Record is : \n");
		printf("\t %s\n",a->name);
		printf("\t %s\n",a->dpt);
		printf("%d\n",a->empid);
		printf("%d\n",a->sal);
		a->prev->next=a->next;
		a->next->prev=a->prev;
		a->next=NULL;
		a->prev=NULL;
		free(a);
		
	}
return first;
}

node modify(node first) //modify node
{
	node a;
	int key,pos=0,flag=0;
	if (first==NULL)
	  printf("\nEMPTY list");
	else 
	{
		printf("Enter EMP_ID to modify :\n");
		scanf("%d",&key);
		a=first;
		while(a->empid!=key)
		{
			a=a->next;
		}
		
	printf("\nEnter Employee Name : ");
	scanf("%s",a->name);
	printf("\nEnter department of Employee : ");
	scanf("%s",a->dpt);
	printf("\nEnter Employee ID : ");
	scanf("%d",&a->empid);
	printf("\nEnter Employee salary : ");
	scanf("%d",&a->sal);
	}
	return first;
}

void display_reverse(node first) //displaying linked list in reverse order
{
	node p;
	if(first!=NULL)
	{
		for(p=first;p->next!=NULL;p=p->next)
		for(p=first;p!=NULL;p=p->prev)
			{
				printf("\t %s\n",p->name);
				printf("\t %s\n",p->dpt);
				printf("%d\n",p->empid);
				printf("%d\n",p->sal);
				printf("\n");
			}
		}
		
}


int main()
{
	int i,choice;
	node a,first=NULL;
	do
	{
	printf("\n****************\n");
	printf("Enter KEY :\n");
	printf(" Enter 1.CREATE\n");
	printf(" Enter 2.DISPLAY\n");
	printf(" Enter 3.SEARCH\n");
	printf(" Enter 4.INSERT BEGINING NODE\n");
	printf(" Enter 5.INSERT END NODE\n");
	printf(" Enter 6.INSERT POSITION NODE\n");
	printf(" Enter 7.DELETE BEGINING NODE\n");
	printf(" Enter 8.DELETE END NODE\n");
	printf(" Enter 9.DELETE Position NODE\n");
	printf(" Enter 10.MODIFY \n");
	printf(" Enter 11.DISPLAY REVERSE\n");
	printf("\n****************\n");
	printf(" Enter your choice : ");
	scanf("%d",&i); 
	switch(i)
	{
		case 1:{
			first=create(first);
			break;
		}
		case 2:{
		    display(first);
			break;
		}case 3:{
			search(first);
			break;
		}case 4:{
			first=insert_begin(first);
			break;
		}case 5:{
			first=insert_end(first);
			break;
		}case 6:{
			first=insert_position(first);
			break;
		}case 7:{
			first=delete_begin(first);
			break;
		}case 8:{
			first=delete_end(first);
			break;
		}case 9:{
			first=delete_position(first);
			break;
		}case 10:{
			first=modify(first);
			break;
		}case 11:{
			display_reverse(first);
			break;
		}
}
	}while(i<=11);
}



