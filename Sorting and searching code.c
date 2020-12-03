//a) Sort the set of strings in ascending order using Insertion sort and descending order by using Selection sort. (Display pass by pass output)
//b) Search a particular string using binary search with and without recursion.

#include<stdio.h>
#include<string.h>
void accept(char[10][10],int);
void display(char[10][10],int);
void insert_sort(char[10][10],int);
void selection_sort(char[10][10],int);
void swap(char[10],char[10]);
int binary_search(char[10][10],int);
int binary_search_recur(char[10][10],int,int,char[10]);
int main(){

   int i,j,count,inx = 0,sw = 0,end = 1,inx1 = 0;
   char s[10],str[10][10],temp[10];
   while(end != 0){
   printf("\nEnter your preference\n1.Accept\n2.Display\n3.Insertion Sort\n4.Selection Sort\n5.Binary Search(without recursion)\n6.Binary Search(with recursion)\n7.Exit\n");
   scanf("%d",&sw);
   switch(sw){
   case 1:
       printf("\nHow many strings you are going to enter?:\n");
       scanf("%d",&count);
       accept(str,count);
       break;
   case 2:
       display(str,count);
       break;
   case 3:
       insert_sort(str,count);
       break;
   case 4:
       selection_sort(str,count);
       break;
   case 5:
        inx = binary_search(str,count);
        if(inx != -1){
            printf("\nYes, The string is present at index %d\n",inx);
           }
        else{printf("\nString is missing\n");}
        break;
   case 6:

        printf("Enter string:\n");
        scanf("%s",&s);
        inx1 = binary_search_recur(str,0,count - 1,s);
        if(inx1 != -1){
            printf("\nYes, The string is present at index %d\n",inx1);
           }
        else{printf("\nString is missing\n");}
        inx1 = 0;
        break;
   case 7:
    end = 0;
   default:
    printf("Enter valid option");
   }
 }
 return 0;
}
void accept(char str[10][10],int n){
   printf("Enter your strings\n");
   int i;
   for( i = 0;i < n;i++)
   {
      scanf("%s",&str[i]);
   }
}
void display(char str[10][10],int n){
    printf("\nYour strings are:\n");
    int i;
    for( i = 0;i < n;i++){
      printf("%s\t\t",str[i]);
   }
}
void insert_sort(char str[10][10],int n){
     char key[10];
     int j = 0;
     int s;
    for ( s = 1; s < n; s++) {
       strcpy(key,str[s]);
       j = s - 1;
       while (strcmp(key,str[j]) < 0 && j >= 0) {
         strcpy(str[j + 1],str[j]);
         j--;
       }
       strcpy(str[j + 1],key);
       display(str,n);
    }
}
void selection_sort(char str[10][10],int n){
    int  max_idx;
    int i;
    for ( i = 0; i < n-1; i++){
        max_idx = i;
        int j;
        for ( j = i+1; j < n; j++){
        if (strcmp(str[j],str[max_idx]) > 0){
            max_idx = j;
          }
        }

        display(str,n);
        swap(str[max_idx],str[i]);

    }
    display(str,n);
}
void swap(char str1[10],char str2[10]){
    char temp[10];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);

}
//without recursion
int binary_search(char str[10][10], int n){
   int l = 0,r = n - 1,mid = 0;
   char s[10];
   printf("Enter string:\n");
   scanf("%s",&s);
 while(l<r){

    mid = (l + r)/2;
   if(strcmp(s,str[l]) == 0){
    return l;

   }
   else if(strcmp(s,str[r]) == 0){
    return r;

   }
   else if(strcmp(s,str[mid]) == 0){
    return mid;

   }
   else if(strcmp(s,str[mid]) > 0){
    l =mid;
   }
   else{
    r = mid;
   }
 }
 return -1;

}
//with recursion
int binary_search_recur(char str[10][10],int l,int r,char s[10]){
   int mid = 0;

 if(r >= 1){

  mid = (l + r)/2;
  if(strcmp(s,str[mid]) == 0){
    return mid;
   }
  else if(strcmp(s,str[mid]) < 0){
    return binary_search_recur(str,l,mid -1,s);
  }
  else{
    return binary_search_recur(str,mid + 1,r,s);
   }
}

 return -1;
}
