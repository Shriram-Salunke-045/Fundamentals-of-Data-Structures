/*******************************************************
Implement the following operations on Sequential file:
insert record
read records
search
modify
delete
*********************************************************/

#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

class student
{
    private:
        int roll;
        char name[20],city[30],divi[5];
        
    public:
        void get();
        void put();
        int getRoll();
        void setRoll(int);
        char *getName();
        void setName(char *);
        char *getDivi();
        void setDivi(char *);
        char *getCity();
        void setCity(char *);
};

class seq_file
{
    private:
        char file_name[30];
    public:
        seq_file();  //Constructor-default
        seq_file(char file_name[]); //Constructor-parameterized
        void create();
        void display();
        void insertStudent();
        void searchStudent();
        void deleteStudent();
        void modifyStudent();
        
};

seq_file::seq_file()   //Constructor-default
{
    ofstream file("student.txt"); //File creation
    strcpy(file_name,"student.txt");
    
    if (file)
    {
        cout<<"\tFile is Opened Successfully";
    }
    
    else
        cout<<"File Error!!";
    file.close();
}


seq_file::seq_file(char file_name[])
{
    ofstream file(file_name);
    
    if (file)
    {
        cout<<"\tFile is Opened Successfully";
    }
    
    else
        cout<<"File Error!!";
    file.close();
}

void student::get()
{
    cout<<"\n\tEnter Roll No.:";
    cin>>roll;
    
    cout<<"\n\tEnter Name:";
    cin>>name;
    
    cout<<"\n\tEnter Division:";
    cin>>divi;
    
    cout<<"\n\tEnter city";
    cin>>city;
}

void student::put()
{
    cout<<"\t\t"<<roll<<"\t\t";
    cout<<name<<"\t\t";
    cout<<divi<<"\t\t";
    cout<<city;
    cout<<"\n";
}

int student::getRoll()
{
    return roll;
}

void student::setRoll(int newRoll)
{
    roll=newRoll;
}

char *student::getName()
{
    return name;
}

void student::setName(char *newName)
{
    strcpy(name,newName);
}

char *student::getDivi()
{
    return divi;
}

void student::setDivi(char *newDivi)
{
    strcpy(divi,newDivi);
}

char *student::getCity()
{
    return city;
}

void student::setCity(char *newCity)
{
    strcpy(city,newCity);
}

void seq_file::create()
{
    int i,totalrecords;
    ofstream file;
    file.open(file_name,ios::app); //Open File in append mode
    cout<<"\n\tEnte Number of Students :";
    cin>>totalrecords;
    
    for(i=0;i<totalrecords;i++)
    {
        cout<<"\tSTUDENT"<<(i+1);
        student s;
        s.get();
        file.write((char *)&s,sizeof(s)); //Writing data to file
    }
    file.close();
}


void seq_file::display() //Reading file
{
    ifstream file; //create in stream
    student s;
    file.open(file_name,ios::in);
    cout<<"\t\tRoll No.\t\tName\t\tDiv.\t\tCity\n";
    
    while(file.read((char *)&s,sizeof(s)))
    {
        s.put();
    }
    file.close();
}

void seq_file::insertStudent()
{
    ofstream file;
    file.open(file_name,ios::app);
    student s;
    s.get();
    file.write((char *)&s,sizeof(s));
    file.close();
}

void seq_file::searchStudent()  //Using linear search
{
    int key,found=0;
    ifstream file;
    student s;
    file.open(file_name,ios::in);
    cout<<"\tEnter Roll number to search :";//using roll number as key to search
    cin>>key;
    
    while(file.read((char *)&s,sizeof(s)))
    {
        if(s.getRoll()==key)
        {
            cout<<"\n\t\tRoll no\t\tName\t\tDiv.\t\tCity\t\n";
            s.put();
            found =1;
        }
    }
    
    if(found==0)
    {
        cout<<"\n\tNo Such Student Found !!";
    }
    else
        cout<<"\n\tStudent Found!!";
    file.close();
}


void seq_file::deleteStudent() //Deletion -search is require
{
    int key,found=0;
    ifstream file;
    student s;
    file.open(file_name,ios::in);
    ofstream tempfile;
    tempfile.open("temp.txt",ios::app); //creating temporary file 
    cout<<"\tEnter Roll number to delete :";
    cin>>key;
    
    while(file.read((char *)&s,sizeof(s)))
    {
        if(s.getRoll()==key)
        {
           found=1;
        }
        else
        {
            
            tempfile.write((char *)&s,sizeof(s)); //write in temporary file
        }
    }
    
    if(found==1)
    {
        cout<<"\n\tEntry Deleted Successfully";
    }
    else
    {
        cout<<"\n\tStudent Not Found!!";
        
    }
    
    file.close();
    remove(file_name);
    tempfile.close();
    rename("temp.txt",file_name);
}


void seq_file::modifyStudent()
{
    int key,pos,found=0;
    fstream file;
    student s;
    file.open(file_name,ios::in|ios::out);
    cout<<"\tEnter Roll number to Modify:";
    cin>>key;
    
   while(!file.eof())
   {
       pos=file.tellg();
       file.read((char *)&s,sizeof(s));
       
       if(file)
       {
           if(s.getRoll()==key)
           {
             found=1;    
             s.get();
             file.seekg(pos);
             file.write((char *)&s,sizeof(s));
             s.put();
           }
       }
       
   }
    
    if(found==0)
    {
        cout<<"\n\tNo Such Student Found !!";
    }
    else
        cout<<"\n\tEntry Modified Successfully!!";
    file.close();
}


int main()
{
    int choice;
    seq_file studentFile;
    do
    {
        cout<<"\t\t------------Sequential File For Student Database-----------------\n";
        cout<<"\t\t\t1.Build Table\n\t\t\t2.Display Table\n\t\t\t3.Insert New Entry\n\t\t\t4.Search Entry\n\t\t\t5.Delete Entry\n\t\t\t6.Modify Entry\n\t\t\t7.Exit\n";
        cout<<"\tEnter Your Choice";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                studentFile.create();
            break;
            case 2:
                studentFile.display();
            break;
            case 3:
                studentFile.insertStudent();
            break;
            case 4:
                studentFile.searchStudent();
            break;
            case 5:
                studentFile.deleteStudent();
            break;
            case 6:
                studentFile.modifyStudent();
            break;
            case 7:
                cout<<"Thank You!";
            break;
            default:
                cout<<"Enter Valid Choice";
            
            
        }
    }while(choice!=7);
    
    return 0;
}

