/*Q.  a) In a class of n students, some students like Math, some like science and some like both the subjects.
Find the students who like ( i) Either Math or Science (ii) Both Math and Science */

#include <stdio.h>

void accept(int[], int);
void display(int[], int);
int inter(int[], int[], int, int, int[]);
int uni(int[], int[], int, int, int[]);
int diff(int[], int[], int, int, int[]);
int validate(int[], int);

int main()
{
    int n1,n2,n3,c1,c2;
    int s1[100], s2[100], s3[100];
    int ch;

    do
    {
       printf("\nMenu:\n");
       printf(" 1.Accept the given sets of students\n 2.Display the given sets of students \n 3.Union of student who like math or science\n 4. student who like both subject\n 5.Students who like only math or science\n");
       printf(" 6.Exit\n");
       scanf("%d", &ch);
       switch(ch)
       {
       case 1:
            printf("Enter no.of student who like math\n");
            scanf("%d", &n1);
            printf("Enter roll.no.of student who like math\n");
            accept(s1, n1);
            printf("Enter no.of student who like science\n");
            scanf("%d", &n2);
            printf("Enter roll.no.of student who like science\n");
            accept(s2, n2);
            printf("Validating the sets.......\n");
            c1=validate(s1, n1);
            c2=validate(s2, n2);
            if(c1==1 ||  c2==1)
            {
                printf("The set is invalid, it is a multiset, please re-enter the set\n");
            }
            else if(c1 !=1 && c2 !=1)
            {
                printf("The sets have been validated\n");
            }
            break;
       case 2:
           printf("Displaying the given sets of students\n");
           printf("Maths=");
           display(s1,n1);
           printf("\nScience=");
           display(s2,n2);
           break;
       case 3:
           printf("Union of student who like math or science:\n");
           n3=uni(s1, s2, n1, n2, s3);
           display(s3, n3);
           break;
       case 4:
           printf("Student who like both subject\n");

           n3=inter(s1, s2, n1, n2, s3);
           if(n3==0)
           {
               printf("Student who like both subject\n");
           }
           else
           {
               printf("Student who like both subject\n");
               display(s3,n3);
           }
           break;
       case 5:
           printf("Student who like only math or science\n");
           n3=diff(s1, s2, n1, n2, s3);
           display(s3, n3);
           break;
       case 6:
           printf("Exiting...");
           exit(0);
           break;
       default:
           printf("Please enter an integer between one and six\n");
       }

    }while (ch<=6);

return 0;
}
    void accept(int set[], int n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d", &set[i]);
        }
    }

    void display(int set[], int n)
    {
        printf("{");
        for(int i=0;i<n;i++)
        {
            printf("%d, ", set[i]);
        }
        printf("}");
    }

    int inter(int s1[], int s2[], int n1, int n2, int s3[])
    {
        int n3=0;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(s1[i]==s2[j])
                {
                    s3[n3]=s1[i];
                    n3++;
                }
            }
        }
    return n3;
    }

    int uni(int s1[], int s2[], int n1, int n2, int s3[])
    {
        int n3=0,i,j;

        for(i=0;i<n1;i++)
        {
            s3[i]=s1[i];
        }
        n3=i;
        for(i=0;i<n2;i++)
        {
            for(j=0;j<n3;j++)
            {
                if(s2[i]==s3[j])
                {
                    break;
                }
                if(j==n3-1)
                {
                    s3[n3]=s2[i];
                    n3++;
                }
			}
        }
        return n3;
    }

   int validate(int set[], int s)
    {
    int check=0;
    for(int i=0;i<s; i++)
        {
        for(int j = 0;j<s; j++)
        {
            if(i != j && set[i]==set[j])
            {
                check=1;
                break;
            }

        }
        }
    return check;
    }


 int diff(int s1[], int s2[], int n1, int n2, int s3[])
    {
        int i,j,n3=0;
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n2;j++)
            {
                if(s1[i]==s2[j])
                {
                    break;
                }
                if(j==n2-1)
                {
                    s3[n3]=s1[i];
                    n3++;
                }
            }
        }
        for(i=0;i<n2;i++)
        {
            for(j=0;j<n1;j++)
            {
                if(s2[i]==s1[j])
                {
                    break;
                }
                if(j==n1-1)
                {
                    s3[n3]=s2[i];
                    n3++;
                }
            }
        }
    return n3;
    }


