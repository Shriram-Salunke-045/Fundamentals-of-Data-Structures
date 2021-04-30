/*****************************************************************
a) Implement direct access file for any Database and perform following operations on it i) Create
Database ii) Display Database
b) For direct access file perform iii) Search a record
****************************************************/

#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
#define TableSize 5
class File{
	private:
	struct rec
	{
		int rno;
		char name[TableSize];
		int chain;
	};
	public:
	File();
	int hash(int);
	void display();
	void create();
	void addrecord();
	int search(int);
	void modify();
};
File:: File() {}
void File:: create()
{
	rec r;
	int i;
	ofstream fs;
	r.rno=-1;
	r.name[0]='\0';
	r.chain=-1;
	fs.open("MYFILE.dat",ios::binary|ios::out);
	if(fs)
	{
		for(i=0;i<TableSize;i++)
		{
			fs.seekp((i)*sizeof(r),ios::beg);
			fs.write((char*)&r, sizeof(r));
		}
	}
	else	cout<<"\nUnable to Open File for writing";
}
void File:: display()
{
	ifstream fs;
	rec r;
	fs.open("MYFILE.dat",ios::binary|ios::in);
	if(fs)
	{
		cout<<"\nRollno\tName\tChain\n";
		while(fs.read((char*)&r, sizeof(r)))
		{
			cout<<"\n"<<r.rno<<"\t"<<r.name<<"\t"<<r.chain;
		}
	}
	else
		cout<<"\nUnable to Open File for reading";
	fs.close();
}
int File:: hash(int rollno)
{
	return(rollno%TableSize);
}
void File::addrecord()
{
	fstream fs;
	rec r,m;
	int index,index1;
	char ch;
	fs.open("MYFILE.dat",ios::binary|ios::in|ios::out);
	do
	{
		cout<<"\nEnterrollno and name of a student : ";
		cin>>r.rno;
		cin>>r.name;
		r.chain=-1;
		index=hash(r.rno);

		fs.seekg((index)*sizeof(r),ios::beg);
		fs.read((char*)&m, sizeof(m));
		if(m.rno==-1)
		{
			fs.seekp((index)*sizeof(r),ios::beg);
			fs.write((char*)&r, sizeof(r));
		}
		else
		{
			while(m.chain!=-1)
			{
				index=m.chain;
				fs.seekg((index)*sizeof(r),ios::beg);
				fs.read((char*)&m, sizeof(m));
			}
			index1=index;
			do
			{
				index=(index+1)%TableSize;
				fs.seekg((index)*sizeof(r),ios::beg);
				fs.read((char*)&m, sizeof(m));
			}
			while((index!=index1)&&(m.rno!=-1));
			if(index==index1)
			{
				cout<<"\nOverflow";
			}
			else
			{
				fs.seekp((index)*sizeof(r),ios::beg);
				fs.write((char*)&r, sizeof(r));
				fs.seekg((index1)*sizeof(r),ios::beg);
				fs.read((char*)&m, sizeof(m));
				if(hash(m.rno)==hash(r.rno))
					m.chain=index;
				else
					m.chain=-1;
				fs.seekp((index1)*sizeof(r),ios::beg);
				fs.write((char*)&m, sizeof(m));
			}
		}
		cout<<"Would u like to add any more record y/n : ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	fs.close();
	display();
}
int File:: search(int rno)
{
	ifstream fs;
	rec r,m;
	int i,index,index1,flag=0;
	char ch;
	fs.open("MYFILE.dat",ios::binary|ios::in);
	if(fs)
	{
		index=hash(rno);
		fs.seekg((index)*sizeof(m),ios::beg);
		fs.read((char*)&m, sizeof(m));
		if(m.rno==rno)
		{
			flag=1;
		}
		else
		{
			if(hash(rno)==hash(m.rno))
			{
				while((m.chain!=-1)&&(hash(rno)==hash(m.rno)))
				{
					index=m.chain;
					fs.seekg((index)*sizeof(m),ios::beg);
					fs.read((char*)&m, sizeof(m));
					if(m.rno==rno)
					{
						flag=1;
						break;
					}
				}
			}
			else
			{
				index1=index;
				do
				{
					index=(index+1)%TableSize;
					fs.seekg((index)*sizeof(m),ios::beg);
					fs.read((char*)&m, sizeof(m));
				}while((index!=index1)&&(m.rno!=rno));
			}

	}
		if((index!=index1)&&(m.rno==rno))
			flag=1;
		if(flag==0)
		{
			cout<<"\nRecord Not found";
			index=-1;
		}
		else
		{
			cout<<"\nRecord Found at "<<index<<" location";
			fs.seekg((index)*sizeof(r),ios::beg);
			fs.read((char*)&r, sizeof(r));
			cout<<"\n"<<r.rno<<"\t"<<r.name;
		}
	}
	else
		cout<<"\nUnable to open the file for reading...";
	fs.close();
	return (index);
}
void File:: modify()
{
	fstream fs;
	rec r,m;
	int i,rno,index,index1;
	char ch;
	cout<<"\nEnter roll no of a student to be modified : ";
	cin>>rno;
	index=search(rno);
	if(index==-1)
		cout<<"\nCan't modify";
	else
	{
		fs.open("MYFILE.dat",ios::binary|ios::in|ios::out);
		if(fs)
		{
			fs.seekg((index)*sizeof(m),ios::beg);
			fs.read((char*)&m, sizeof(m));
			cout<<"\nEnter modified name of a student : ";
			cin>>m.name;
			fs.seekp((index)*sizeof(m),ios::beg);
			fs.write((char*)&m, sizeof(m));
		}
		else
			cout<<"\nUnable to open the file for modification";
	}
	fs.close();
}
int main()
{
	int choice,rno;
	char ch;
	File file;
	while(1)
	{
		cout<<"\n\n***MENU*\n\n1.Create\n2.Add record\n3.Modify\n4.Search";
		cout<<"\n5.Display Records\n6.Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			file.create();
cout<<"\nMYFILE.dat file is created...";
			break;
		case 2:
			file.addrecord();
			break;
		case 3:
			file.modify();
			break;
		case 4:
			cout<<"Enter a roll no of a record to be searched : ";
			cin>>rno;
			file.search(rno);
			break;
		case 5:
			file.display();
			break;
		case 6:
				exit(0);
		default:cout<<"\nPlease Enter valid choice";
		}
	}
}
/*************************** OUTPUT ***********************************************
./main


***MENU*

1.Create
2.Add record
3.Modify
4.Search
5.Display Records
6.Exit

Enter your choice : 1

MYFILE.dat file is created...

***MENU*

1.Create
2.Add record
3.Modify
4.Search
5.Display Records
6.Exit

Enter your choice : 2

Enterrollno and name of a student : 2
shriram
Would u like to add any more record y/n : y

Enterrollno and name of a student : 3
atharva
Would u like to add any more record y/n : y

Enterrollno and name of a student : 4
kshitija
Would u like to add any more record y/n : n

Rollno  Name    Chain

-1      -1
-1      -1
2   shriram -1
3   atharva -1
4   kshitija?T)>    -1

***MENU*

1.Create
2.Add record
3.Modify
4.Search
5.Display Records
6.Exit

Enter your choice : 3

Enter roll no of a student to be modified : 3

Record Found at 3 location
3   atharva
Enter modified name of a student : sairaj


***MENU*

1.Create
2.Add record
3.Modify
4.Search
5.Display Records
6.Exit

Enter your choice : 4
Enter a roll no of a record to be searched : 4

Record Found at 4 location
4   kshitija?T)>

***MENU*

1.Create
2.Add record
3.Modify
4.Search
5.Display Records
6.Exit

Enter your choice : 5

Rollno  Name    Chain

-1      -1
-1      -1
2   shriram -1
3   sairaj  -1
4   kshitija?T)>    -1

***MENU*

1.Create
2.Add record
3.Modify
4.Search
5.Display Records
6.Exit
********************************************************************************/

