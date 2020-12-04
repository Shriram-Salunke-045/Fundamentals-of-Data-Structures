
//Merge and Quick

// a)  Implement Quick Sort & Merge Sort with recursion to sort the given list of numbers. Display corresponding list in each pass. 
// b)  Implement Merge Sort to sort the given list of numbers without recursion. Display corresponding list in each pass. 

# include <stdio.h>
#define MAX 10

void accept(int A[30],int n);
void display(int A[30],int n);
void merge(int A[30],int l1,int u1,int l2,int u2);
void merge_sort(int Ar[30],int low,int high);
void merge_sort_itr(int Ar[30],int n);
void quick_sort(int A[MAX],int,int,int);
void quicksort(int A[MAX],int);
int partition(int A[MAX],int,int,int);
void swap(int A[MAX],int *i,int *j);
int main()
{

   int choice,no;
   int arr[30];
   do{
    printf("\n1:add elements\n2:display elements\n3:Recursive merge sort\n4:Iterative merge sort\n5:quick sort\n6:EXIT\n Enter your choice:\n");
    scanf("%d",&choice);


    switch(choice)

    {

      case 1:
          printf(" Enter the number of elements  you want add:\n");
          scanf("%d",&no);
          accept(arr,no);
          break;

      case 2:
            printf("the enterd elements are:\n");
            display(arr,no);
            break;

      case 3:

             merge_sort(arr,0,no-1);
             printf("the final sorted array is:");
            display(arr,no);
             break;

      case 4:

            merge_sort_itr(arr ,no);
            break;
      case 5:
              quick_sort(arr,no,0,no-1);
              printf("the final sorted array is:\n");
              display(arr,no);
              break;


   default:
      printf("please enter valid input!\n");

      }
    }while(choice!=6);

    return 0;
   }
void accept(int A[30],int n)
{
     int i;
     printf("enter the elements:\n");
     for(i=0;i<n;i++)
     {
         scanf("%d",&A[i]);
     }

}

void display(int A[30],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
      printf("%d\t",A[i]);
  }
}


void merge(int A[30],int l1,int u1,int l2,int u2)
{
    int temp[50],i,j,k=0;

    i=l1;
    j=l2;

    while(i<=u1 &&  j<=u2)
    {
     if(A[i]<A[j])
     {
         temp[k]=A[i];
         k++;
         i++;

     }
    else
    {
        temp[k]=A[j];
        k++;
        j++;
    }

    }

    while(i<=u1)
{
   temp[k]=A[i];
   k++;
   i++;

}

while(j<=u2)

{
    temp[k]=A[j];
    k++;
    j++;
}

for(i=0,j=l1;j<=u2;i++,j++)
{
    A[j]=temp[i];
}

printf("\n sorted subarray:");
for(i=l1;i<=l2;i++)
    printf("%d ",A[i]);
}


void merge_sort(int Ar[30],int low,int high)
{
  int mid;

  if(low<high)
  {
      mid=(low+high)/2;

      merge_sort(Ar,low,mid);
      merge_sort(Ar,mid+1,high);

      merge(Ar,low,mid,mid+1,high);

  }

}


void merge_sort_itr(int Ar[30],int n)

{
   int size,i,j,k,u1,u2,l1,l2,temp[50];
   for(size=1;size<n;size=2*size)
   {

      l1=0;k=0;
      while(l1+size<n)
      {
        u1=l1+size-1;
        l2=u1+1;
        u2=l2+size-1;

        if(u2>=n)
            u2=n-1;

        merge(Ar,l1,u1,l2,u2);
        l1=u2+1;

      }
   }

}


void quick_sort(int A[MAX],int n,int l,int u)
{
    int pivot,i;
    if(l<u)
    {
       pivot=partition(A,n,l,u);
       printf("After partitioning:\t");
       for(i=0;i<n;i++)
            printf("%d",A[i]);
       quick_sort(A,0,l,pivot-1);


    }

}


int partition(int A[MAX],int n,int l,int u)

{

   int pivot,i,j,temp;
   pivot=A[i];
   i=l;
   j=u;


   while(i<=j)
   {
       while(A[i]<=pivot && i<u)
        i++;

       while(A[j]>=pivot)
        j--;

      if(i<j)
        swap(A,&i,&j);
   }
      printf("\npivot %d:",A[j]);

      return j;
   }


   void swap(int A[MAX],int *i,int *j)
   {
      int temp;
      temp=A[*i];
      A[*i]=A[*j];
      A[*j]=temp;

   }
