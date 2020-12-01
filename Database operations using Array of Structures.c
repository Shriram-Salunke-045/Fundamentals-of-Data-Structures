#include<stdio.h>
 
typedef struct Product
{
    char name[20];
    int code;
    int price;
    int flag;
}pro;
 
int createDB(pro pr[]);
pro addRecord();
void display(pro p);
void displayDB(pro pr[],int);
int search(pro p[],int,int);
void modify(pro p[],int,int);
void tempDel(pro p[],int,int);
int del(pro p[],int,int);
void sort(pro p[],int);
void displayDel(pro pr[],int);
 
int main()
{
    int choice,n=0,num,i;
    pro p[10];
    
    do
    {
        printf("\n 1.Create Database\n 2.Display\n 3.Search \n 4.Modify \n 5.Permanent delete \n 6. Temporary delete \n 7.Sort \n 8. Insert product \n 9.Display deleted products \n 10.Exit \n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                n=createDB(p);
                break;
            case 2:
                displayDB(p,n);
                break;
            case 3:
                printf("Enter code of the product you want to search\n");
                scanf("%d",&num);
                i=search(p,n,num);
                if(i==-1)
                    printf("\nRecord not found\n");
                else
                {
                    printf("\n Details of product found\n");
                    display(p[i]);
                }
                break;
            case 4:
                printf("\nEnter the code of the product which you want to modify\n");
                scanf("%d",&num);
                modify(p,n,num);
                break;
            case 5:
                printf("Enter code of the product which you want to delete permanently\n");
                scanf("%d",&num);
                n=del(p,n,num);
                break;
            case 6:
                printf("Enter code of the product which you want to delete temporarily\n");
                scanf("%d",&num);
                tempDel(p,n,num);
                break;
            case 7:
                printf("\tSorted Database(ACCORDING TO PRICE):\n");
                sort(p,n);
                displayDB(p,n);
                break;
            case 8:
                p[n]=addRecord();
                n++;
                break;
            case 9:
                displayDel(p,n);
                break;
            case 10:
                break;
            default:
                printf("Enter a number from 1-9\n");
                break;
        }
    }while(choice!=10);
return 0;
}
                
pro addRecord()
{
    pro temp;
    printf("Enter name,code and price of the product\n");
    scanf("%s%d%d",&temp.name,&temp.code,&temp.price);
    temp.flag=0;
    return temp;
}
        
int createDB(pro pr[])
{
     int n=0,i,ch;
    do
    {
        pr[n]=addRecord();
        n++;
        printf("Do you want to insert another record? Type 1 for yes, 0 for no\n");
        scanf("%d",&ch);
    }while(ch==1);
return n;
}
 
void display(pro p)
{
    if(p.flag==0)
    {
        printf("%s\t%d\t%d\t\n",p.name,p.code,p.price);
    }
}
                
void displayDB(pro pr[],int n)
{
    int i;
    printf("\tLIST OF PRODUCTS\n");
    printf("Name\tCode\tPrice\n");
    for(i=0;i<n;i++)
     display(pr[i]);
}                
                
void displayDel(pro pr[],int n)
{
    int i;
    printf("\tDeleted products:\n");
    printf("Name\tCode\tPrice\n");
    for(i=0;i<n;i++)
    {
        if(pr[i].flag==1)
        {
            printf("%s\t%d\t%d\n",pr[i].name,pr[i].code,pr[i].price);
        }
    }    
}
 
int search(pro pr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(pr[i].flag==0 && pr[i].code==num)
         return i;
    }
     return -1;    
}                
 
void modify(pro pr[],int n,int num)
{
    int ch,i;
    i=search(pr,n,num);
    if(i==-1)
        printf("No such product found\n");
    else
    {
        printf("Do you want to change name.Type 0 for yes, 1 for no.\n");
        scanf("%d",&ch);
        if(ch==0)
        {
            printf("Enter new name\n");
            scanf("%s",&pr[i].name);
        }
        printf("Do you want to change the price.Type 0 for yes, 1 for no.\n");
        scanf("%d",&ch);
        if(ch==0)
        {
            printf("Enter new price\n");
            scanf("%d",&pr[i].price);
        }        
    }
    
}                
                
void tempDel(pro pr[],int n,int num)
{
    int ch,i;
    i=search(pr,n,num);
    if(i==-1)
        printf("No such product found\n");
    else
        pr[i].flag=1;
}                
                
int del(pro pr[],int n,int num)
{
    int i;
    i=search(pr,n,num);
    if(i==-1)
        printf("\n No such product found\n");
    else
    {
        printf("Deleted product is\n");
        display(pr[i]);
        while(i<n)
        {
            pr[i]=pr[i+1];
            i++;
        }
    }
    n--;
    return n;
}                
        
void sort(pro pr[],int n)
{
    int i,j;
    pro temp;
    for(i=0;i<n-1;i++)
    {
           for(j=0;j<n-1;j++)
            {
                if(pr[j].price>pr[j+1].price)
                {
                    temp=pr[j];
                    pr[j]=pr[j+1];
                    pr[j+1]=temp;
                }
 
           }
    }
}
