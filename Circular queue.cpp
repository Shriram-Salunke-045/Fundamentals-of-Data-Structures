// Implement a circular queue.

#include<Stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 5

using namespace std;

class cQue
{
	int q[SIZE];
	int f,r;

	public:
		cQue();
		int isfull();
		int isempty();
		void enque(int ele);
		int deque1();


};

cQue::cQue()
{
	f=r=-1;

}

int cQue::isfull()
{
	if(f==(r+1)%SIZE)
		return 1;
	else
		return 0;
}

int cQue::isempty()
{
	if(f==-1 )
		return 1;
	else
		return 0;

}

void cQue::enque(int ele)
{
    if(isempty()==1)
    {
        r=f=0;
    }
    else{
		r=(r+1)%SIZE;

		q[r]=ele;
    }
}

int cQue::deque1()
{
	int ele;
if(r==f)
{
    ele=q[f];
    r=f=-1;
}
else
        {
          ele=q[f];
		f=(f+1)%SIZE;
        }



	return ele;
}



main()
{
int ele, opt;
cQue objcQue;

do
{
//cout<< "\n\n***cQue USING ARRAY*\n";
cout<<"1.enque"<<"2.deque"<<"3.EXIT";
cout<<" \n Enter ur choice : ";
cin>>opt;
switch(opt)
	{
	case 1: if(objcQue.isfull()!=1)
		{
		cout<<"\n Enter the item to be enqueed";
		cin>>ele;

		objcQue.enque(ele);
		}
		else
		cout<<endl<<"cQue FULL! cQue OVERFLOW!";

		break;

	case 2: if(objcQue.isempty()!=1)
		{
		ele=objcQue.deque1();
		cout<<"\n The element dequeped="<<ele;
		}
		else
		cout<<endl<<"cQue EMPTY! cQue UNDERFLOW!";
		break;

	}
}while(opt!=3);
//getch();
return 0;
}
[20/11, 9:03 PM] Pratiksha New: 13
[20/11, 9:04 PM] Pratiksha New: /*************************
Avnish Oswal
17U040
231040
A2-IT
**************************/

#include<iostream>
using namespace std;
struct info{            //data for the patient
    char name[20];
    int age,id;
};
class queue{                //class for the queue
    struct patient{
        info data;
        struct patient *next;           //pointer to the next node
    };
    typedef patient *node;
    node front,rear;                    //declaring pointers of the nodes
public:
    void inqueue(info );                    //function to add a person in the queue
    info dequeue();
    int isEmpty()
    {
        if (front==NULL)
            return 1;
        else return 0;
    }                   //function to serve a person waiting in the queue
    void display_q();                   //function to display th list of the patients in the queue
    queue()             //constructor
    {
        front=NULL;
        rear=NULL;
    }
    void display(info data)                 //displaying information of the patient
{
    cout<<data.name;
    cout<<"\t"<<data.id;
    cout<<"\t"<<data.age;
}

};
int priority(int );             //for assigning priority to the patients

void queue::inqueue(info temp)              //function to add patients in the queue
{
    node add=new patient;
    add->next=NULL;
    add->data=temp;

    if(front == NULL)
    {
        front=add;
        rear=add;
    }
    else
    {
        rear->next=add;
        rear=add;
    }
}
info queue::dequeue()               //function for serving a person from the queue
{
    node temp;
    info pat;
    temp=front;
    if(front==NULL)
    {
        pat.id=-1;
        return pat;
    }
    else if(front == rear)
    {
        pat=front->data;
        front=NULL;
        rear=NULL;
    }
    else
    {
        pat=front->data;
        front=front->next;
        temp->next=NULL;
    }
    delete temp;
    return pat;
}
void queue::display_q()                 //function to display the patients in the queue priority wise
{
    cout<<"NAME\tAGE\tID"<<endl;
    info data;
    node temp=front;
    data.id=0;
    while(temp!=NULL)
    {
        data=temp->data;;
        display(data);
        cout<<endl;
        temp=temp->next;

    }

}


int priority(int d)         //function for assigning priority based on the disease
{
    switch(d)
    {
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
    }
}
int main()              //main function
{
    info data;          //data for the patient
    queue q[3];         //queues arranged priority wise
    int s,c,p,i=0;
    int d;
    do{                     //menu driven loops
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Enter the choice\n1.Add patient \n2.Serve patient \n3.Display Queue\n4.Exit\n";
        cin>>s;
        switch(s)
        {
            case 1://for accepting patients in the queue
                do{
                    cout<<"Enter the patient id: ";
                    cin>>data.id;
                    cout<<"Enter the name: ";
                    cin>>data.name;
                    cout<<"Enter the age: ";
                    cin>>data.age;
                    cout<<"Enter the disease\n1.Cancer\n2.Malaria\n3.TB\n4.Jaundice\n5.Fever\n";
                    cin>>d;
                    p=priority(d);
                    q[p].inqueue(data);         //call to inqueue
                    cout<<"---------------------------------------"<<endl;
                    cout<<"Want to add more patients\n1.Yes\n2.No\n";
                    cin>>c;
                }while(c==1);
                break;
            case 2://for serving the patient and displaying his/her details
                //cout<<"First queue:\n";


                if(q[0].isEmpty()==0)
                {
                    data=q[0].dequeue();
                    cout<<"Patient served:\n";
                    cout<<"NAME\tAGE\tID"<<endl;
                    q[0].display(data);
                    cout<<endl;
                }

                else  if(q[1].isEmpty()==0)
                {
                    data=q[1].dequeue();
                    cout<<"Patient served:\n";
                    cout<<"NAME\tAGE\tID"<<endl;
                    q[1].display(data);
                    cout<<endl;
                }
                else if(q[2].isEmpty()==0)
                {
                 data=q[2].dequeue();
                    cout<<"Patient served:\n";
                    cout<<"NAME\tAGE\tID"<<endl;
                    q[2].display(data);
                    cout<<endl;
                }
                else
                    cout<<"\n all patients served";
                break;
            case 3://for displaying the patients queues acc. to priority
                cout<<"Serious patients:\n";
                q[0].display_q();
                cout<<"Average patients n";
                q[1].display_q();
                cout<<"General check-up patients \n";
                q[2].display_q();
                break;
            case 4:
                break;
            default:
                cout<<"Error input\n";
        }

    }while(s!=4);
}
