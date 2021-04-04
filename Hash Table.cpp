/******************************************************************************************

a) Store data of students using hashing function for roll number and implement linear probing
using chaining without replacement algorithm.

b) Store data of students using hashing function for telephone number and implement linear
probing using chaining with replacement algorithm.

********************************************************************************************/

#include <iostream>
#include <cstring>  //imporyed for memset function
#define SIZE 10      //hashing works efficiently if prime no. is used
using namespace std;

int hash_function(int x) {
	return x % SIZE;
} // returns the hash value

void Insert(int data[], int flag[], int chain[], int x) {
	int i=0, position = hash_function(x);
	while (flag[position] && i<SIZE) {
		if (data[position]%SIZE == x%SIZE) {
			break;
		}
		i++;
		position = hash_function(position + 1);
	}
	if (i == SIZE) {
		cout << "\n Error!!!\n The hash table is full\n";
		return;
	}  // returns if hash table is full
	while (chain[position] != -1) {
		position = chain[position];
	}
	int temp = position;
	while (flag[temp] && i<SIZE) {
		temp = hash_function(temp + 1);
		i++;
	}
	if (i == SIZE) {
		cout << "\n Error!!!\n The hash table is full\n";
		return;
	}   // returns if the hash table is full
	data[temp] = x;
	flag[temp] = 1;
	if (temp != position) {
		chain[position] = temp;
	}
}

int Search(int data[], int flag[], int chain[], int x) {
	int position = hash_function(x), i=0;
	while (i<SIZE && flag[position] && data[position]%SIZE != x%SIZE) {
		i++;
		position = hash_function(position + 1);
	}
	if ( !flag[position] || i == SIZE) {
		return -1;
	}
	while (position != -1) {
		if (data[position] == x) {
			return position;
		}
		position = chain[position];
	}
	return -1;
}

void Display(int data[], int flag[], int chain[]) {
	cout << "\n\tOrder\tData\tflag\tchain\n\t";
	for (int i=0; i<SIZE; i++) {
		cout << i << "\t" << data[i] << "\t" << flag[i] << "\t";
		if (chain[i] > -1) {
			cout << " " << chain[i] << "\n\t";
		}
		else {
			cout << chain[i] << "\n\t";
		}
	}
}

int menu() {
	int x;
	cout << "\n_______MENU_______";
	cout << "\n1. Insert Elements.\n"
	        "2. Search Elements.\n"
	        "3. Display Elements.\n"
	        "4. Exit                  Enter choice : ";
	cin >> x;
	return x;
}

int main() {
	int x;
	int data[SIZE] = {0};
	int flag[SIZE];
	int chain[SIZE];
	memset(flag, 0, sizeof(flag));    //memset function assigns the value to all the chunk of memory occupied by the variable
	memset(chain, -1, sizeof(chain));  //-1 value occupied in chain array everywhere
	while (1) {
		switch (menu()) {
			case 1 :
				cout << "\nEnter the Element : ";
				cin >> x;
				Insert(data, flag, chain, x);
				break;
			case 2 :
				cout << "ENter the number to be searched : ";
				cin >> x;
				x = Search(data, flag, chain, x);
				if(x == -1) {
					cout << "\n Alert!!!\n Element not found\n";
				}
				else {
					cout << "\n Element found!!!\n Availability location : " << x << endl;
				}
				break;
			case 3 :
				Display(data, flag, chain);
				break;
			case 4 :
				exit(0);
		}
	}
	return 0;
}
/************************ OUTPUT ********************************
./main

_______MENU_______
1. Insert Elements.
2. Search Elements.
3. Display Elements.
4. Exit                  Enter choice : 1

Enter the Element : 1

_______MENU_______
1. Insert Elements.
2. Search Elements.
3. Display Elements.
4. Exit                  Enter choice : 1

Enter the Element : 2

_______MENU_______
1. Insert Elements.
2. Search Elements.
3. Display Elements.
4. Exit                  Enter choice : 1

Enter the Element : 3

_______MENU_______
1. Insert Elements.
2. Search Elements.
3. Display Elements.
4. Exit                  Enter choice : 1

Enter the Element : 4

_______MENU_______
1. Insert Elements.
2. Search Elements.
3. Display Elements.
4. Exit                  Enter choice : 2
ENter the number to be searched : 3

 Element found!!!
 Availability location : 3

_______MENU_______
1. Insert Elements.
2. Search Elements.
3. Display Elements.
4. Exit                  Enter choice : 3

    Order   Data    flag    chain
    0   0   0   -1
    1   1   1   -1
    2   2   1   -1
    3   3   1   -1
    4   4   1   -1
    5   0   0   -1
    6   0   0   -1
    7   0   0   -1
    8   0   0   -1
    9   0   0   -1

_______MENU_______
1. Insert Elements.
2. Search Elements.
3. Display Elements.
4. Exit                  Enter choice : 4
**************************************************/

