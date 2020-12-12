// a) Implement polynomial using CLL and perform  
// i. Addition of Polynomials 
// b) Implement polynomial using CLL and perform
// ii. Multiplication of polynomials and    
// iii. Evaluation of polynomial

#include <stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct  node
 {
  int power;
  float coeff;
  struct node *next;
 }node;

  node *  insert(node *head,int power1,float coeff1);
  node *  create();
  node *  padd(node *p1,node *p2);
  node *  pmul(node *p1,node *p2);
  float eval(node *p1,float x);
  void print(node *head);

node *insert(node *head,int power1,float coeff1)
      {
  node *p,*q;
  
  p=(node*) malloc(sizeof(node));
  p->power=power1;
  p->coeff=coeff1;
  p->next=NULL;

  if(head==NULL) //Empty linked list
     {
    head=p;
    head->next=head;//CLL
    return(head);
     }
  if(power1<head->power)//lowest power,inserted at the end
     {
    p->next=head->next;
    head->next=p;
    head=p;
    return(head);
     }
  if(power1==head->power) //add coefficients
     {
    head->coeff=head->coeff+coeff1;
    return(head);
     }

   q=head;
   while(q->next!=head && power1<=q->next->power) //locate the position for insertion
    q=q->next;

   if(p->power==q->power)
    q->coeff=q->coeff+coeff1;
   else
     {
    p->next=q->next;//insert node p between q and q->next node
    q->next=p;
     }
  return(head);
  }


 node *create(node *head)
   {
  int n,i,power1;
  float coeff1;

  printf("\nEnter No. of Terms:");
  scanf("%d",&n);
  printf("\nenter a term as a tuple of (power,coefficient) : ");
  for(i=1;i<=n;i++)
     {
    scanf("%d%f",&power1,&coeff1);
    head=insert(head,power1,coeff1);
     }
       return(head);
  }

 node * padd(node *p1,node *p2)
 {
  node *p;
  node *head=NULL;
  int power;float coeff;
  p=p1->next;
  do     //insert the first polynomial
     {
    head=insert(head,p->power,p->coeff);
    p=p->next;
     } while(p!=p1->next);
  p=p2->next;
  do  //insert the second polynomial
     {
    head=insert(head,p->power,p->coeff);
    p=p->next;
   } while(p!=p2->next);
  return(head);
  }

 node *pmul(node *p1,node *p2)
 {
  node *head1,*head2;
  node *head=NULL;
  head2=p2->next;
  do   //for every term of the second polynomial
     {
    head1=p1->next;
    do  //multiply with every term of the first polynomial
       {
 //  for(p=head1;p!=NULL;p=p->next)
      head=insert(head,head1->power+head2->power,head1->coeff * head2->coeff);
      head1=head1->next;
        }while(head1!=p1->next);
    head2=head2->next;
     }while(head2!=p2->next);
  return(head);
 }

 float eval(node *head,float x)
 {
  float value=0.00;
  node *p;
  p=head->next;
  do
    {
    value=value+p->coeff * pow(x,p->power);
    p=p->next;
    }while(p!=head->next);
  return(value);
 }

 void print( node *head)
 {
  node *p;
  p=head->next;
  printf("\n");
  do
     {
    printf("%6.2f x^%d   ",p->coeff,p->power);
    p=p->next;
     }while(p!=head->next);
 }


main()
 {
  node *p1,*p2,*p3;
  int op;
  float value,x;
  p1=p2=p3=NULL;
//  clrscr();
  do
    {
    printf("\n1)Create first polynomial");
    printf("\n2)Create second polynomial");
    printf("\n3)Print first polynomial");
    printf("\n4)Print second polynomial");
    printf("\n5)Add\n6)Multiply\n7)Evaluate First Polynomial\n8)Quit");
    printf("\nEnter Your Choice: ");
    scanf("%d",&op);
    switch(op)
       {
      case 1: p1=create(p1);break;
      case 2: p2=create(p2);break;
      case 3: print(p1);break;
      case 4: print(p2);break;
      case 5: p3=padd(p1,p2);
        print(p3);break;
      case 6: p3=pmul(p1,p2);
        print(p3);break;
      case 7: printf("\nEnter the value of X:");
        scanf("%f",&x);
        value=eval(p1,x);
        printf("\nEvaluated value = %6.2f",value);
        break;
        }
   }while(op!=8);
 }

