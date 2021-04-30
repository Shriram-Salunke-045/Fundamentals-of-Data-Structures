/************************************************************************************
a) Implement an index sequential file for any Database and perform following operations on it i)
Create Database ii) Display Database iii) Add a record
b) On index sequential file, perform
iv) Delete a record v)Modify a record vi)Search record
**********************************************************************************************/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
//#include<stblib>
using namespace std;
   
typedef struct INDEX{
		int emp_id;
		int position;
	}Ind_Rec;
typedef struct EMPLOYEE{
		char name[10];
		int emp_id;
		int salary;
	}Rec;
class EMP_CLASS{
	
	
	int n;
	Rec Records;
	Ind_Rec Ind_Records;
	public :
EMP_CLASS(){
	strcpy(Records.name,"");
}
void insert(){
	int i ,j;
	fstream seqfile;
	fstream indexfile;
	
	seqfile.open("EMP.txt", ios::in|  ios::out|  ios::app);
	indexfile.open("IND.txt",ios::in| ios::out|  ios::app);
	if(!seqfile || !indexfile){
		cout<<"\n error opening file";
		return;
	}
	cout<<"\n Enter Emp_ID : ";
	cin>>Records.emp_id;
	cout<<"\n Enter Salary : ";
	cin>>Records.salary;
	cout<<"\n Enter Name :";
	cin>>Records.name;
	
	indexfile.seekp(0,ios::end);
	seqfile.seekp(0,ios::end);
	n=seqfile.tellp()/sizeof(Records);
	seqfile.write((char*)&Records,sizeof(Records))<<flush;
	Ind_Records.emp_id=Records.emp_id;
	Ind_Records.position=n;
	indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
	n++;
	
	indexfile.close();
	seqfile.close();
}
void Display(){
	 fstream seqfile;
	 fstream indexfile;
	 int n,i,j;
	 cout<<"\nIndex File ";
	 indexfile.open("IND.txt",ios::in|ios::out|ios::app);
	 if(!indexfile){
	 	cout<<"\n Error Opening file";
	 	return ;
	 }
	 indexfile.seekg(0,ios::beg);
	 while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records))){
	 	cout<<"\n Emp_ID : "<<Ind_Records.emp_id;
	 	cout<<"\t Position : "<<Ind_Records.position;
	 }
	 indexfile.close();
	  indexfile.open("IND.txt",ios::in|ios::out|ios::app);
	  seqfile.open("EMP.txt",ios::in|ios::out|ios::app);
	 if(!seqfile || !indexfile){
	 	cout<<"\n Error Opening file";
	 	return ;
	 }
	 indexfile.seekg(0,ios::beg);
	 seqfile.seekg(0,ios::beg);
	 cout<<"\n The contents of file are :"<<endl;
	 i=0;
	 while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records))){
	 	i=Ind_Records.position*sizeof(Rec);
	 	seqfile.seekg(i,ios::beg);
	 	seqfile.read((char *)&Records,sizeof(Records));
	 	if(Records.emp_id=-1){
	 		cout<<"\nName :"<<Records.name<<flush;
	 		cout<<"\nEmp_ID :"<<Records.emp_id;
	 		cout<<"\nSalary :"<<Records.salary;
		 }
	 }
	 seqfile.close();
	 indexfile.close();	
}
		void Upadate(){
			int pos,id;
			char New_name[10];
			int New_emp_id;
			int New_salary;
			cout<<"\n For updation :\nEnter the Emp_Id for searching :";
			cin>>id;
			fstream seqfile;
			fstream indexfile;
			seqfile.open("EMP.txt",ios::in|ios::out|ios::app);
			indexfile.open("IND.txt",ios::in|ios::out|ios::app);
			indexfile.seekg(0,ios::beg);
			
			pos=-1;
			while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records))){
				if(id==Ind_Records.emp_id){
					pos=Ind_Records.position;
					break;
				}
			}
			if(pos==-1){
				cout<<"\n The record is not present in the file";
				return ;
			}
			else{
				cout<<"\n Enter the value for updation :";
				cout<<"\n Name :";
				cin>>New_name;
				cout<<"\n Salary :";
				cin>>New_salary;
				
				int offset=pos*sizeof(Rec);
				seqfile.seekp(offset);
				strcpy(Records.name,New_name);
				Records.emp_id=id;
				Records.salary=New_salary;
				seqfile.write((char *)&Records,sizeof(Records))<<flush;
				cout<<"\n the record is updated !!";
			}
			seqfile.close();
			indexfile.close();
		}
		void Delete(){
			int id,pos;
			cout<<"\n For deletion,";
			cout<<"\n Enter the Emp_Id for searching : ";
			cin>>id;
			fstream seqfile;
			fstream indexfile;
			seqfile.open("EMP.txt",ios::in|ios::out|ios::app);
			indexfile.open("IND.txt",ios::in|ios::out|ios::app);
		    seqfile.seekg(0,ios::beg);
			indexfile.seekg(0,ios::beg);
			
			pos=-1;
			while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records))){
				if(id==Ind_Records.emp_id){
					pos=Ind_Records.position;
					break;
				}
			}
			if(pos==-1){
				cout<<"\n The record is not present in the file";
				return ;
			}
			int offset = pos*sizeof(Rec);
			seqfile.seekp(offset);
			strcpy(Records.name,"");
			Records.emp_id=-1;
			seqfile.write((char*)&Records,sizeof(Records))<<flush;
			offset=pos*sizeof(Ind_Rec);
			indexfile.seekp(offset);
			Ind_Records.emp_id=-1;
			Ind_Records.position=pos;
			indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
			seqfile.seekg(0);
			indexfile.close();
			seqfile.close();
			cout<<"\n the record is deleted !!!";
		}
		void Append();
		void Search(){
			fstream seqfile;
			fstream indexfile;
			int id,pos,offset;
			cout<<"\n Enter the Emp-Id for searching the record :";
			cin>>id;
			indexfile.open("IND.txt",ios::in|ios::app);
			pos=-1;
			while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records))){
				if(id==Ind_Records.emp_id){
					pos=Ind_Records.position;
					break;
				}
			}
			if(pos==-1){
				cout<<"\n Record is not present in the file";
				return ;
			}
			offset = pos*sizeof(Records);
			seqfile.open("EMP.txt",ios::in|ios::app);
			seqfile.seekg(offset,ios::beg);
			seqfile.read((char *)&Records,sizeof(Records));
			if(Records.emp_id==-1){
				cout<<"\n Record is not present in the file";
				return;
			}
			else{
			   cout<<"\n The Record is present in the filr and it is :";
			   cout<<"\n Name : "<<Records.name;
			   cout<<"\n Emp_ID :"<<Records.emp_id;
			   cout<<"\n Salary :"<<Records.salary;	
			}
			seqfile.close();
			indexfile.close();
		}				
};


int main(){
	EMP_CLASS List;
	int choice,key;
	do{
		cout<<"\nMenu\n1.Insert\n2.Display\n3.Update\n4.Delete\n5.Search\n6.Exit";
		cout<<"\nEnter your choice :";
		cin>>choice;
		switch(choice){
			case 1 :
				List.insert();
				break;
			case 2: 
			    List.Display();
			    break;
			case 3:
				List.Upadate();
				break;
			case 4:
				List.Delete();
				break;
			case 5:
				List.Search();
				break;
		}
		
	}while(choice!=6);
	return 0;
}

/******************** OUTPUT *********************************
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :1

 Enter Emp_ID : 1

 Enter Salary : 2000

 Enter Name :aaa

Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :1

 Enter Emp_ID : 2

 Enter Salary : 3000

 Enter Name :bbbb

Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :1   

 Enter Emp_ID : 3

 Enter Salary : 4000

 Enter Name :ccc

Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :2

Index File 
 Emp_ID : 1  Position : 0
 Emp_ID : 2  Position : 1
 Emp_ID : 3  Position : 2
 The contents of file are :

Name :aaa
Emp_ID :-1
Salary :2000
Name :bbbb
Emp_ID :-1
Salary :3000
Name :ccc
Emp_ID :-1
Salary :4000
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :3

 For updation :
Enter the Emp_Id for searching :2

 Enter the value for updation :
 Name :ffff

 Salary :9000

 the record is updated !!
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :2

Index File 
 Emp_ID : 1  Position : 0
 Emp_ID : 2  Position : 1
 Emp_ID : 3  Position : 2
 The contents of file are :

Name :aaa
Emp_ID :-1
Salary :2000
Name :bbbb
Emp_ID :-1
Salary :3000
Name :ccc
Emp_ID :-1
Salary :4000
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :4

 For deletion,
 Enter the Emp_Id for searching : 33

 The record is not present in the file
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :4

 For deletion,
 Enter the Emp_Id for searching : 3

 the record is deleted !!!
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :5

 Enter the Emp-Id for searching the record :1

 The Record is present in the filr and it is :
 Name : aaa
 Emp_ID :1
 Salary :2000
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
Enter your choice :2

Index File 
 Emp_ID : 1  Position : 0
 Emp_ID : 2  Position : 1
 Emp_ID : 3  Position : 2
 Emp_ID : -1     Position : 2
 The contents of file are :

Name :aaa
Emp_ID :-1
Salary :2000
Name :bbbb
Emp_ID :-1
Salary :3000
Name :ccc
Emp_ID :-1
Salary :4000
Name :ccc
Emp_ID :-1
Salary :4000
Menu
1.Insert
2.Display
3.Update
4.Delete
5.Search
6.Exit
*******************************************************************************/

