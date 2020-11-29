// Perform matrix operations without pointers.

#include <stdio.h>

void accept(int A[5][5], int, int);
void display(int A[5][5], int, int);
void multiplication(int A[5][5], int B[5][5], int, int, int, int D[5][5]);
void addition(int A[5][5], int B[5][5], int, int,int C[5][5]);
void transpose(int A[5][5], int, int);

int main() {
	int A[5][5], B[5][5], C[5][5], D[5][5], r1, c1, r2, c2, choice;
	printf("Enter the No.of Rows and Column of first matrix :");
	scanf("%d%d", &r1, &c1);
	printf("Enter the elements in first matrix : \n");
	accept(A, r1, c1);
	printf("\n");
	printf("Elements you  entered in 1st matrix  are : \n");
	display(A, r1, c1);
	printf("\n");
	printf("Enter the No.of Rows and Column of second matrix : ");
	scanf("%d%d", &r2, &c2);
	printf("Enter the elements in second matrix : \n");
	accept(B, r2, c2);
	printf("\n");
	printf("Elements ypu entered in 2nd array are : \n");
	display(B, r2, c2);
	printf("\n");

	do {
		printf("Press :\n1 for addition\n2 for multiplication\n3 for transpose\n4 for exit\n");
		printf("Enter choice : ");
		scanf("%d", &choice);

		switch (choice) {

			case 1 :
				if (r1==r2 && c1==c2) {
					addition(A, B, r1, c1, C);
					display(C, r1, c1);
				}
				else {
					printf("The sum cannot be calculated\n");
				}
				break;
			case 2 :
				if (c1==r2) {
					multiplication(A, B, r1, r2, c2, D);
					display(D, c1, r2);
				}
				else {
					printf("Multiplication cannot be performed\n");
				}
				break;
			case 3 :
				transpose(A, r1, c1);
				display(A, r1, c1);
		}
	}while(choice!=4);
	printf("Program Exited\n");
}

void addition(int A[5][5], int B[5][5], int r1, int c1, int C[5][5]) {
	int i, j;
	for (i=0; i<r1; i++) {
		for (j=0; j<c1; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void multiplication(int A[5][5], int B[5][5], int r1, int r2, int c2, int D[5][5]) {
	int i, j, k;
	for (i=0; i<r1; i++) {
		for(j=0; j<c2; j++) {
			D[i][j] = 0;
			for (k=0; k<r2; k++) {
				D[i][j] = D[i][j] + A[i][k] * B[k][i];
			}
		}
	}
}

void transpose(int A[5][5], int r1, int c2) {
	int i, j, temp;
	for (i=0; i<r1; i++) {
		for (j=0; j<c2; j++) {
			temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
	}
}

void accept(int A[5][5], int r1, int c1) {
	int i, j;
	for (i=0; i<r1; i++) {
		for (j=0; j<c1; j++) {
			scanf("%d",&A[i][j]);
		}
	}
}

void display(int A[5][5], int r1, int c1) {
	int i, j;
	for (i=0; i<r1; i++) {
		for (j=0; j<c1; j++) {
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
}

