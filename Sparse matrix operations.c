// a) Accept conventional matrix and convert it into sparse matrix using structure andPerform addition of two sparse matrices.
// b) Implement simple and fast transpose algorithms on sparse matrix.

#include <stdio.h>
#include <stdlib.h>

void display(int mat[12][12], int m11, int m12)    //displaying original matrix
{ 
    int i;
    for( i = 0; i < m11; i++)
    {
    	int j;
        for(j = 0; j < m12; j++)
        {
            if(j == 0)
            {
                printf("\n\t%d", mat[i][j]);
            }

            else if(j == m12-1)
            {
                printf("\t%d", mat[i][j]);
            }

            else
            {
                printf("\t%d", mat[i][j]);
            }
        }
    }
}

void accept(int mat[12][12], int m11, int m12)           //accepting input matrix
{
	int i;
    for( i = 0; i < m11; i++)
    {   int j;
        for( j = 0; j < m12; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int validation(int m11, int m12)                           //checking for Invalid Inputs
{
    if(m11 <= 0 || m11 >= 12 || m12 <= 0 || m12 >= 12)
    {
        printf("\nInvalid Input....  Please re-enter the values\n");
        return 1;
    }

    return 0;
}

void disp_sparse(int sp[100][3], int m)                    //displaying Sparse Matrix
{
    int i, j;
    printf("\n\tRows\tCol\tValue");

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                if(i == 0)
                {
                    printf("\n\t%d", sp[i][j]);
                }
                else
                {
                    printf("\n\t%d", sp[i][j]+1);
                }

            }

            else if(j == 2)
            {
                printf("\t%d", sp[i][j]);
            }

            else
            {
                if(i == 0)
                {
                    printf("\t%d", sp[i][j]);
                }
                else
                {
                    printf("\t%d", sp[i][j]+1);
                }
            }
        }
    }
}

void sparse_mat(int mat1[12][12], int m11, int m12, int sp[100][3])   //converting to original to sparse
{
    int i, j, k = 1;

    for(i = 0; i < m11; i++)
    {
        for(j = 0; j < m12; j++)
        {
            if(mat1[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = mat1[i][j];
                k++;
            }
        }
    }

    sp[0][0] = m11;
    sp[0][1] = m12;
    sp[0][2] = --k;
}

void addition(int sp1[100][3], int sp2[100][3], int m11, int m21, int sp3[100][3])   //addition of two sparse Matrices
{
    if(sp1[0][0] != sp2[0][0] || sp1[0][1] != sp2[0][1])
    {
        printf("\nAddition Not Possible, No of Rows or Cols Don't Match\n");
    }

    else
    {
        int i, j, k = 1;

        for(i = 1, j = 1; i < m11 && j < m21; i *= 1, j *= 1)
        {
            if(sp1[i][0] > sp2[j][0] || (sp1[i][0] == sp2[j][0] && sp1[i][1] > sp2[j][1]))
            {//if same Rows, but Column of sp2 is less than Column of sp1
                sp3[k][0] = sp2[j][0];
                sp3[k][1] = sp2[j][1];
                sp3[k][2] = sp2[j][2];
                j++;
                k++;
            }

            else if(sp1[i][0] < sp2[j][0] || (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1]))
            {//if same Rows, but Column of sp1 is less than Column of sp2
                sp3[k][0] = sp1[i][0];
                sp3[k][1] = sp1[i][1];
                sp3[k][2] = sp1[i][2];
                i++;
                k++;
            }

            else
            {//for same cell
                if(sp1[i][2] + sp2[j][2] != 0)
                {//insert in sp3 only if addn is not 0
                    sp3[k][0] = sp1[i][0];
                    sp3[k][1] = sp1[i][1];
                    sp3[k][2] = sp1[i][2] + sp2[j][2];
                    k++;
                }

                i++;
                j++;
            }
        }

        for(;i < m11;)
        {//for remaining values of sp1
            sp3[k][0] = sp1[i][0];
            sp3[k][1] = sp1[i][1];
            sp3[k][2] = sp1[i][2];
            i++;
            k++;
        }

        for(;j < m21;)
        {//for remaining values of sp2
            sp3[k][0] = sp2[j][0];
            sp3[k][1] = sp2[j][1];
            sp3[k][2] = sp2[j][2];
            j++;
            k++;
        }

        sp3[0][0] = sp1[0][0];
        sp3[0][1] = sp2[0][1];
        sp3[0][2] = --k;
    }
}

void simp_trans(int sp[100][3])                         //Simple Transpose
{
    int i, j, k, sp1[100][3];
    sp1[0][0] = sp[0][1];
    sp1[0][1] = sp[0][0];
    sp1[0][2] = sp[0][2];

    if(sp[0][2] > 1)
    {
        k = 1;
        for(i = 0; i < sp[0][1]; i++)
        {
            for(j = 1; j <= sp[0][2]; j++)
            {
                if(sp[j][1] == i)
                {
                    sp1[k][0] = sp[j][1];
                    sp1[k][1] = sp[j][0];
                    sp1[k][2] = sp[j][2];
                    k++;
                }
            }
        }
    }

    disp_sparse(sp1, (sp1[0][2] + 1));
}

void fast_trans(int sp[100][3])                             //Fast Transpose
{
    int i, j, t[100], extra[100], sp1[100][3];
    sp1[0][0] = sp[0][1];
    sp1[0][1] = sp[0][0];
    sp1[0][2] = sp[0][2];

    if(sp[0][2] > 1)
    {
        for(i = 0; i < sp[0][1]; i++)
        {
            t[i] = 0;
        }

        for(i = 1; i <= sp[0][2]; i++)
        {
            t[sp[i][1]]++;
        }
    }

    extra[0] = 1;

    for(i = 1; i < sp[0][1]; i++)
    {
        extra[i] = extra[i - 1] + t[i - 1];
    }

    for(i = 1; i <= sp[0][2]; i++)
    {
        j = extra[sp[i][1]];
        sp1[j][0] = sp[i][1];
        sp1[j][1] = sp[i][0];
        sp1[j][2] = sp[i][2];
        extra[sp[i][1]] = j + 1;
    }

    disp_sparse(sp1, (sp1[0][2] + 1));
}

int main()
{
    int a, ch, mat1[12][12], mat2[12][12], mat3[12][12], sp1[100][3], sp2[100][3], sp3[100][3], m11, m12, m21, m22, m31, m32;
    printf("\nEnter the Matrices\n\nFor matrix 1 :-\n");

    do
    {
        printf("\nDimension(between 0 to 12) :-\n\t Rows = ");
        scanf("%d", &m11);
        printf("\t Columns = ");
        scanf("%d", &m12);
        a = validation(m11, m12);

    }while(a == 1);


    printf("\nEnter elements for 1st matrix :-\n");
    accept(mat1, m11, m12);
    sparse_mat(mat1, m11, m12, sp1);
    a = 0;

    printf("\n\nFor matrix 2 :-\n");
    do
    {
        printf("\nDimensions(between 0 to 12)\n\t Rows = ");
        scanf("%d", &m21);
        printf("\t Columns = ");
        scanf("%d", &m22);
        a = validation(m21, m22);

    }while(a == 1);

    printf("\nEnter elements for 2nd matrix :-\n");
    accept(mat2, m21, m22);
    sparse_mat(mat2, m21, m22, sp2);

    do
    {
        printf("\n\nChoose you want to perform :-\n\t 1. Accept Input\n\t 2. Display (original matrices)\n\t 3. Display (sparse matrices)\n\t 4. Addition\n\t 5. Transpose of matrix 1(Simple)\n\t 6. Transpose of matrix 2(Fast)\n\t 7. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\n\nEnter the Matrices\n");                          //accept input

                printf("\n\nFor matrix 1 :-\n");
                do
                {
                    printf("\nDimension(between 0 to 12) :-\n\t Rows = ");
                    scanf("%d", &m11);
                    printf("\t Columns = ");
                    scanf("%d", &m12);
                    a = validation(m11, m12);

                }while(a == 1);

                printf("\nEnter elements for 1st matrix :-\n");
                accept(mat1, m11, m12);
                sparse_mat(mat1, m11, m12, sp1);
                a = 0;

                printf("\n\nFor matrix 2 :-\n");
                do
                {
                    printf("\nDimensions(between 0 to 12)\n\t Rows = ");
                    scanf("%d", &m21);
                    printf("\t Columns = ");
                    scanf("%d", &m22);
                    a = validation(m21, m22);

                }while(a == 1);

                printf("\nEnter elements for 2nd matrix :-\n");
                accept(mat2, m21, m22);
                sparse_mat(mat2, m21, m22, sp2);

                break;

            case 2:
                printf("\nMatrix 1 :-\n");                            //Display Original matrix
                display(mat1, m11, m12);
                printf("\n\nMatrix 2 :-\n");
                display(mat2, m21, m22);

                break;


            case 3:
                printf("\nMatrix 1 :-\n");                            //Display Sparse matrix
                disp_sparse(sp1, (sp1[0][2] + 1));
                printf("\n\nMatrix 2 :-\n");
                disp_sparse(sp2, (sp2[0][2] + 1));

                break;

            case 4:
                addition(sp1, sp2, (sp1[0][2] + 1), (sp2[0][2] + 1), sp3);     //Addition
                printf("\nAddition is\n");
                disp_sparse(sp3, (sp3[0][2] + 1));

                break;

            case 5:
                printf("\nTranspose of Matrix 1 is\n");                   //Simple Transpose
                simp_trans(sp1);

                break;

            case 6:
                printf("\nTranspose of Matrix 2 is\n");                    //Fast Transpose
                fast_trans(sp2);
                break;

            case 7:
                printf("\n\t\tExit...\n");                                //Exit
                break;

            default:
                printf("\n\nPlease enter valid Input\n");
                break;
        }

    }while(ch != 7);

return 0;
}

