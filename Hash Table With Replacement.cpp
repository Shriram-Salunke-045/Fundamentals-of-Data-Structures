/**************************************************************************************
 Store data of students using hashing function for telephone number and implement linear
probing using chaining with replacement algorithm.
****************************************************************************************/
#include <iostream>
#include <cstring>
#define SIZE 10
using namespace std;

int hash_function(int x) {
	return x % SIZE;
}

void Insert(int data[], int flag[], int chain[], int x) {
	int i=0;
	int j;
	int position = hash_function(x);
	if (flag[position] == 0) {
		data[position] = x;
		flag[position] = 1;
		return;
	}
	if (hash_function(data[position]) != hash_function(x)) {
		j = position;
		while (flag[j] && i<SIZE) {
			j = hash_function(j+1);
			i++;
		}
		if (i == SIZE) {
			cout << "\n Error!!!"
			        "\n Hash Table is full\n";
			return;
		}
		i = hash_function(data[position]);   //delete the element by modifying the chain
		//this is beginning of the chain
		while (chain[i] != position) {
			i = chain[i];
		}
		chain[i] = chain[position];   //we add deleted element at the end of the chain
		while (chain[i] != -1) {
			i = chain[i];
		}
		chain[i] = j;
		data[j] = data[position];
		chain[position] = -1;
		flag[j] = 1;
		chain[j] = -1;
		data[position] = x;   //insertion of the current key
		chain[position] = -1;
		return;
	}
	//condition for if the hash location contains the synonyns
	// first we locate the empty location
	i=0;
	j = position;
	while (flag[j] && i<SIZE) {
		j = hash_function(j+1);
		i++;
	}
	if (i == SIZE) {
		cout << "\n Error!!!"
		        "\n The table is full\n";
		return;
	}
	data[j] = x;
	flag[j] = 1;
	chain[j] = -1;
	// we go to the end of chain
	i = position;  //this is beginning of the chain
	while (chain[i] != -1) {
		i = chain[i];
	}
	chain[i] = j;
}

int Search(int data[], int flag[], int chain[], int x) {
	int i=0;
	int j = hash_function(x);
	while (i<SIZE && flag[j] && (hash_function(data[j]) != hash_function(x))) {
		i++;
		j = hash_function(j+1);
	}
	if (!flag[j] || i==SIZE) {
		return -1;
	}   // locate the element in the chain
	while (j != -1) {
		if (data[j] == x) {
			return j;
		}
		j = chain[j];
	}
	return -1;
}

void Display(int data[], int flag[], int chain[]) {
	cout << "\n\tIndex\tdata\tflag\tchain\n";
	for (int i=0; i<SIZE; i++) {
		cout << "\t" << i << "\t" << data[i] << "\t" << flag[i] << "\t";
		if (chain[i] < 0) {
			cout << chain[i] << endl;
		}
		else {
			cout << " " << chain[i] << endl;
		}
	}
}

int menu() {
	int x;
	cout << "\n________MENU________";
	cout << "\n1. Insert the Element."
	        "\n2. Display the Element."
	        "\n3. Search the Element."
	        "\n4. Exit.                     Enter choice : ";
	cin >> x;
	return x;
}

int main() {
	int x;
	int data[SIZE] = {0};
	int flag[SIZE];
	int chain[SIZE];
	memset(flag, 0, sizeof(flag));
	memset(chain, -1, sizeof(chain));
	while (1) {
		switch (menu()) {
			case 1 :
				cout << "\nEnter the Element : ";
				cin >> x;
				Insert(data, flag, chain, x);
				break;
			case 2 :
				Display(data, flag, chain);
				break;
			case 3 :
				cout << "\nEnter the Element to Search : ";
				cin >> x;
				x = Search(data, flag, chain, x);
				if (x != -1) {
					cout << "\n Element found!!!\n"
					        " Availability location : " << x << endl;
				}
				else {
					cout << "\n Alert!!!\n"
					        " Element not found\n";
				}
				break;
			case 4 :
				exit(0);
		}
	}
	return 0;
}

/**************************OUTPUT****************************
./main

________MENU________
1. Insert the Element.
2. Display the Element.
3. Search the Element.
4. Exit.                     Enter choice : 1

Enter the Element : 1

________MENU________
1. Insert the Element.
2. Display the Element.
3. Search the Element.
4. Exit.                     Enter choice : 1

Enter the Element : 2

________MENU________
1. Insert the Element.
2. Display the Element.
3. Search the Element.
4. Exit.                     Enter choice : 1

Enter the Element : 3

________MENU________
1. Insert the Element.
2. Display the Element.
3. Search the Element.
4. Exit.                     Enter choice : 2

    Index   data    flag    chain
    0   0   0   -1
    1   1   1   -1
    2   2   1   -1
    3   3   1   -1
    4   0   0   -1
    5   0   0   -1
    6   0   0   -1
    7   0   0   -1
    8   0   0   -1
    9   0   0   -1

________MENU________
1. Insert the Element.
2. Display the Element.
3. Search the Element.
4. Exit.                     Enter choice : 3

Enter the Element to Search : 2

 Element found!!!
 Availability location : 2

________MENU________
1. Insert the Element.
2. Display the Element.
3. Search the Element.
4. Exit.                     Enter choice : 4
**************************************************/

