/**************************************************************************
 a) Construct an inorder threaded binary search tree.
b) Traverse threaded binary tree it in inorder and preorder.
************************************************************************/
#include<iostream>
using namespace std;
struct Node
{
    struct Node *left, *right;

    int info;
    // True if left pointer points to predecessor
    // in Inorder Traversal

    bool lthread;
    // True if right pointer points to successor

    // in Inorder Traversal

    bool rthread;
};
 
// Insert a Node in Binary Threaded Tree

struct Node *insert(struct Node *root, int key)
{

    // Searching for a Node with given value

    Node *ptr = root;

    Node *par = NULL; // Parent of key to be inserted

    while (ptr != NULL)

    {

        // If key already exists, return

        if (key == (ptr->info))

        {

            cout<<"Duplicate Key !\n";

            return root;

        }
 

        par = ptr; // Update parent pointer
 

        // Moving on left subtree.

        if (key < ptr->info)

        {

            if (ptr -> lthread == false)

                ptr = ptr -> left;

            else

                break;

        }
 

        // Moving on right subtree.

        else

        {

            if (ptr->rthread == false)

                ptr = ptr -> right;

            else

                break;

        }

    }
 

    // Create a new node

    Node *tmp = new Node;

    tmp -> info = key;

    tmp -> lthread = true;
    tmp -> rthread = true;

    if (par == NULL)

    {

        root = tmp;

        tmp -> left = NULL;

        tmp -> right = NULL;

    }

    else if (key < (par -> info))

    {

        tmp -> left = par -> left;

        tmp -> right = par;

        par -> lthread = false;

        par -> left = tmp;

    }

    else

    {

        tmp -> left = par;

        tmp -> right = par -> right;

        par -> rthread = false;

        par -> right = tmp;

    }
 

    return root;
}
 
// Returns inorder successor using rthread

struct Node *inorderSuccessor(struct Node *ptr)
{

    // If rthread is set, we can quickly find

    if (ptr -> rthread == true)

        return ptr->right;
 

    // Else return leftmost child of right subtree

    ptr = ptr -> right;

    while (ptr -> lthread == false)

        ptr = ptr -> left;

    return ptr;
}
 
// Printing the threaded tree

void inorder(struct Node *root)
{

    if (root == NULL)

        cout<<"Tree is empty";
 

    // Reach leftmost node

    struct Node *ptr = root;

    while (ptr -> lthread == false)

        ptr = ptr -> left;
 

    // One by one print successors

    while (ptr != NULL)

    {

        cout<<ptr -> info<<" ";

        ptr = inorderSuccessor(ptr);

    }
}
 
 
 

 
 void preorder(Node *head)
{Node *p;
p=head->left;

cout<<head->info<<" ";
//start traverse from root node of TBT
while ( p!=head)
{
cout<< p->info<<" ";
if (p->lthread==false)//if left child 'Y'
p=p->left;
else if (p->rthread==false)//Rchild 'Y
p=p->right;
else //reach to node which has right chi
{ while ( p!=head && p->rthread==true)
p=p->right;
if(p!=head)
p=p->right;
}//inner while
}
}
 
 
 
 
// Driver Program

int main()
{

    struct Node *root = NULL;
 int n,x;
  while(1)
  {cout<<"\n1-Insert data\n";
  cout<<"2-Inorder display\n";
  cout<<"3-Preorder display\n";
    cin>>n;
    switch(n)
  {case 1:
    cout<<"\nEnter element:";
    cin>>x;
    root = insert(root, x);
    
   
 
break;
case 2:
    cout<<"Inorder Traversal :\n";
    inorder(root);
    cout<<endl;
 break;
 case 3:
cout<<"Preorder Traversal :\n";
preorder(root);
break;
case 4:
  exit(1);
  break;
  default:
    cout<<"Invalid option\n";
  
}
}
    return 0;
}
 /************************ OUTPUT  *********************************
./a.out

1-Insert data
2-Inorder display
3-Preorder display
1

Enter element7

1-Insert data
2-Inorder display
3-Preorder display
1

Enter element2

1-Insert data
2-Inorder display
3-Preorder display
1

Enter element10

1-Insert data
2-Inorder display
3-Preorder display
1

Enter element5

1-Insert data
2-Inorder display
3-Preorder display
1

Enter element1

1-Insert data
2-Inorder display
3-Preorder display
2
Inorder Traversal 
1 2 5 7 10 

1-Insert data
2-Inorder display
3-Preorder display
3
Preorder Traversal 
7 2 1 5 
1-Insert data
2-Inorder display
3-Preorder display  ***********************************************/

