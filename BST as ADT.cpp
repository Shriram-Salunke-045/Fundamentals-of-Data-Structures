/* a) Create a binary search tree (BST) of and perform following operations:
i) Insert (Rec and non-rec) ii) Display inorder (rec) iii) Search a node (rec and non-rec)
iv) Find height of the tree(rec)  v) level wise display (using queue)
vi) Delete (rec) vii) Find mirror image (rec) */

#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *left,*right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

class tree
{
    node *root;
    void inorder1(node *t);
    void search(node *t);
    int search_node(node *t,int temp);
    int height_tree(node *t);
    void level_wise(node *t);
    void postorder1(node *t);
    node* create1(node *t);
    node* insert(node *t,node *temp);
    node* create_tree(int);
    void create_tree_iter(int);
    node* create2(node *t);
    int search_ele_iter(int);
    node* mirror_tree(node *t);
public:
    tree()
    {
        root=NULL;
    }
    void create()
    {
        root=create1(root);
    }
    void create_iter()
    {
        root=create2(root);
    }
    void inorder()
    {
        inorder1(root);
    }
    void search_element()
    {
        search(root);
    }
    void height()
    {
        int temp=height_tree(root);
        cout<<"\n Height of Tree = "<<temp;
    }
    void level()
    {
        level_wise(root);
    }
    void search_iter()
    {
        int temp;
        cout<<"\n Enter Number to be searched : ";
        cin>>temp;
        int res = search_ele_iter(temp);
        if(res==1)
            cout<<"\nElement "<<temp<<" Found ";
        else
            cout<<"\nElement "<<temp<<" Not found";
    }
    void mirror()
    {
        root=mirror_tree(root);
    }
};

class stack
{
    int top;
    node *stk[1000];
public:
    stack()
    {
        top=-1;
    }
    void push(node *t)
    {
        stk[++top]=t;
    }
    node* pop()
    {
        return stk[top--];
    }
    int empty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    int full()
    {
        if(top==1000)
            return 0;
        else
            return 1;
    }

};
class que
{
    int front,rear;
    node *arr[1000];
public:
    que()
    {
        front=-1;
        rear=-1;
    }
    int isEmpty()
    {
        if(front>rear)
        {
            front = -1;
            rear = -1;
            return 1;
        }
        else
            return 0;
    }
    int isFull()
    {
        if(rear==1000)
            return 1;
        else
            return 0;
    }
    void enqueue(node *t)
    {

        if(rear==-1)
        {
            ++front;
        }
        ++rear;
        arr[rear]=t;
    }
    node* dequeue()
    {
        node* temp = arr[front];
        ++front;
        return temp;
    }

};

node* tree::create_tree(int x)
{
    node *temp = new node(x);
    root = insert(root,temp);
    return root;
}

node* tree::insert(node *t,node *temp)
{
    if(t==NULL)
        return temp;
    else if(temp->data < t->data)
        t->left=insert(t->left,temp);
    else
        t->right=insert(t->right,temp);
}

node* tree::create1(node *t)
{
    int cho;
    do
    {
        int temp;
        cout<<"\nEnter Element : ";
        cin>>temp;
        root=create_tree(temp);

        cout<<"\n Do you wish to continue (0 for Yes /1 for No) : ";
        cin>>cho;
    }while(cho==0);
    return root;
}

node* tree::create2(node *t)
{
    int cho;
    do
    {
        int temp;
        cout<<"\nEnter Element : ";
        cin>>temp;
        create_tree_iter(temp);

        cout<<"\n Do you wish to continue (0 for Yes /1 for No) : ";
        cin>>cho;
    }while(cho==0);
    return root;
}
void tree::create_tree_iter(int x)
{
    node *parent,*current=root;
    node *temp = new node(x);
    if(root==NULL)
        root=temp;
    else
    {
        while(current!=NULL)
        {
            parent=current;
            if(temp->data < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if(temp->data < parent->data)
            parent->left=temp;
        else
            parent->right=temp;
    }

}
void tree::inorder1(node *t)
{
    if(t!=NULL)
    {
        inorder1(t->left);
        cout<<t->data<<" ";
        inorder1(t->right);
    }
}

int tree::search_node(node *t,int temp)
{
    if(t==NULL)
        return 0;
    else if(t->data==temp)
        return 1;
    else if(temp < t->data)
        return search_node(t->left,temp);
    else
        return search_node(t->right,temp);
}

void tree::search(node *t)
{
    int temp;
    cout<<"\nEnter Element To be searched : ";
    cin>>temp;
    int flag = search_node(t,temp);

    if(flag==1)
        cout<<"\n Element "<<temp<<" Found";
    else
        cout<<"\n Element "<<temp<<" Not Found ";
}

int tree::height_tree(node *t)
{
    if(t==NULL)
        return 0;
    else
    {
        int lh = height_tree(t->left);
        int rh = height_tree(t->right);

        if(lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }

}
void tree::level_wise(node *t)
{
    que q1;
    node* temp=t;
    q1.enqueue(t);
    while(temp!=NULL)
    {
        if(q1.isEmpty()==1)
            break;
        temp = q1.dequeue();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q1.enqueue(temp->left);
        if(temp->right!=NULL)
            q1.enqueue(temp->right);
    }
}

int tree::search_ele_iter(int x)
{
    node *current = root;
    while(current!=NULL)
    {
        if(current->data == x)
            return 1;
        else if(x < current->data)
            current = current->left;
        else if(x > current->data)
            current = current->right;
    }
    return 0;
}

node* tree::mirror_tree(node *t)
{
    if(t==NULL)
        return 0;
    else
    {
        mirror_tree(t->left);
        mirror_tree(t->right);

        node *temp = t->left;
        t->left = t->right;
        t->right = temp;
    }
    return t;
}

int main()
{
    tree obj;
    int cho;
    do
    {
        cout<<"\n1. Create (Recursion) "<<endl;
        cout<<"2. Inorder "<<endl;
        cout<<"3. Search a node  "<<endl;
        cout<<"4. Height of Tree "<<endl;
        cout<<"5. Level wise display "<<endl;
        cout<<"6. Create (Iterative) "<<endl;
        cout<<"7. Search a node (Iterative) "<<endl;
        cout<<"8. Mirror of a Tree "<<endl;
        cout<<"9. Exit "<<endl;
        cout<<"Enter Choice  : "<<endl;
        cin>>cho;
        if(cho==1)
            obj.create();
        else if(cho==2)
        {
            cout<<"\nInorder  ==> ";
            obj.inorder();
            cout<<endl;
        }
        else if(cho==3)
        {
            obj.search_element();
            cout<<endl;
        }
        else if(cho==4)
        {
            obj.height();
            cout<<endl;
        }
        else if (cho==5)
        {
            obj.level();
            cout<<endl;
        }
        else if (cho==6)
        {
            obj.create_iter();
            cout<<endl;
        }
        else if (cho==7)
        {
            obj.search_iter();
            cout<<endl;
        }
        else if (cho==8)
        {
            obj.mirror();
            cout<<"\n Inverted Tree Successfully "<<endl;
            cout<<endl;
        }
    }while(cho!=9);
}
/******
OUTPUT
1. Create (Recursion)
2. Inorder
3. Search a node
4. Height of Tree
5. Level wise display
6. Create (Iterative)
7. Search a node (Iterative)
8. Mirror of a Tree
9. Exit
Enter Choice  :
1

Enter Element : 2

 Do you wish to continue (0/1) : 0

Enter Element : 4

 Do you wish to continue (0/1) : 0

Enter Element : 6

 Do you wish to continue (0/1) : 0

Enter Element : 8

 Do you wish to continue (0/1) : 0

Enter Element : 9

 Do you wish to continue (0/1) : 1

1. Create (Recursion)
2. Inorder
3. Search a node
4. Height of Tree
5. Level wise display
6. Create (Iterative)
7. Search a node (Iterative)
8. Mirror of a Tree
9. Exit
Enter Choice  :
2

Inorder  ==> 2 4 6 8 9

1. Create (Recursion)
2. Inorder
3. Search a node
4. Height of Tree
5. Level wise display
6. Create (Iterative)
7. Search a node (Iterative)
8. Mirror of a Tree
9. Exit
Enter Choice  :
3

Enter Element To be searched : 8

 Element 8 Found

1. Create (Recursion)
2. Inorder
3. Search a node
4. Height of Tree
5. Level wise display
6. Create (Iterative)
7. Search a node (Iterative)
8. Mirror of a Tree
9. Exit
Enter Choice  :
4

 Height of Tree = 5

1. Create (Recursion)
2. Inorder
3. Search a node
4. Height of Tree
5. Level wise display
6. Create (Iterative)
7. Search a node (Iterative)
8. Mirror of a Tree
9. Exit
Enter Choice  :
5
2 4 6 8 9

1. Create (Recursion)
2. Inorder
3. Search a node
4. Height of Tree
5. Level wise display
6. Create (Iterative)
7. Search a node (Iterative)
8. Mirror of a Tree
9. Exit
Enter Choice  :
8

 Inverted Tree Successfully


1. Create (Recursion)
2. Inorder
3. Search a node
4. Height of Tree
5. Level wise display
6. Create (Iterative)
7. Search a node (Iterative)
8. Mirror of a Tree
9. Exit
Enter Choice  :9
Process returned 0 (0x0)   execution time : 205.624 s
Press any key to continue.
***************/

