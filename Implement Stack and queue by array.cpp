//Practice assign1 : Implement stack ADT and queue ADT using array.

//Create 2 different classes for stack and queue ADT. Use array data structure to store the elements.  

#include<iostream>
#define SIZE 5
using namespace std;
class STACK
{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();    //defualt constructor
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void displayItems();
};
STACK::STACK(){
    top=-1;
}
class queue
{
private:
int queue[100], n = 100, front = - 1, rear = - 1;
public:
    void Enqueue();
    void Dequeue();
    void Display();

};
int STACK::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int STACK::isFull(){
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}

int STACK::push(int n){
    //check stack is full or not
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}

int STACK::pop(){
    //to store and print which number
    //is deleted
    int temp;
    //check for empty
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;

}

void STACK::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}
void queue::Enqueue() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}


void queue::Dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}
void queue::Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}


int main(){
    //declare object
    STACK stk;
    queue q;
    int ch, n,temp;

    do
    {
        cout<<endl;

        cout<<"1) - Push Item."<<endl;
        cout<<"2) - Pop Item."<<endl;
        cout<<"3) - Display Items (Print STACK)."<<endl;
         cout<<"4) Insert element to queue"<<endl;
   cout<<"5) Delete element from queue"<<endl;
   cout<<"6) Display all the elements of queue"<<endl;
    cout<<"7) - Exit."<<endl;

      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {




        case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk.push(n);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<temp<<" inserted."<<endl;
            break;

            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                else
                    cout<<temp<<" is removed (popped)."<<endl;
            break;

            case 3:
                stk.displayItems();
                break;
        case 4: q.Enqueue();
         break;
         case 5: q.Dequeue();
         break;
         case 6: q.Display();
         break;
         case 7: cout<<"Exit"<<endl;

            default:
                cout<<"An Invalid choice."<<endl;



}
    }while(ch!=7);
return 0;
}
/******************************* OUTPUT ***********************************
. /main

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
1
Enter item to insert: 7
7 inserted.

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
2
7 is removed (popped).

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
1
Enter item to insert: 5
5 inserted.

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
3
STACK is: 5 

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
4
Insert the element in queue : 
4

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
5
Element deleted from queue is : 4

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
6
Queue elements are : 

1) - Push Item.
2) - Pop Item.
3) - Display Items (Print STACK).
4) Insert element to queue
5) Delete element from queue
6) Display all the elements of queue
7) - Exit.
Enter your choice : 
7
Exit
*******************************************/




