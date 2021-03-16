/************************************************************************************************
a) Consider a friends’ network on face book social web site. Model it as a graph to represent each
node as a user and a link to represent the fried relationship between them. Store data such as date
of birth, number of comments for each user.
i) Find who is having maximum friends
Hint: Use adjacency list representation
b) For a friends’ network,
ii) Find who has post maximum and minimum comments (using BFS)
iii) Find users having birthday in this month (using DFS)
******************************************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

class node {

  public :
    char name[20];
    int index, year, month, day, no_of_likes, no_of_friends, no_of_Comments;
    node *next;
    node();
    node(char name[20], int, int, int, int, int, int);
};

class graph {

    node *G[20];
    int no_of_users, month, friends[20], visited[20];

  public :
    graph();
    void read_Graph();
    int insert(node *G[], int x, int y);
    void connect();
    void display();
    void max_Friendz();
    void birthday_this_month(int x);
    void max_min_comments();
};

node :: node() {

    next = NULL;
    name[0] = '\0';
    index = year = month = day = no_of_likes = no_of_friends = 0;
}

node :: node (char shriramname[20], int shriramindex, int shriramyear, int shrirammonth, int shriramday, int shriramno_of_likes, int shriramno_of_Comments) {

    strcpy(name, shriramname);
    index = shriramindex;
    year = shriramyear;
    month = shrirammonth;
    day = shriramday;
    no_of_likes = shriramno_of_likes;
    no_of_Comments = shriramno_of_Comments;
}

graph :: graph() {

    cout<<"\nEnter the number of users : ";
    cin>>no_of_users;

    for (int i=0; i<no_of_users; i++) {
        G[i] = NULL;
        friends[i] = 0;
        visited[i] = 0;
    }
}

void graph :: read_Graph() {

    char name[20];
    int index, year, month, day, no_of_likes, no_of_Comments;

    for (int i=0; i<no_of_users; i++) {
        index = i;
        cout<<"\nFor User "<<i<<" :\n";
        cout<<"Enter the name : ";
        cin>>name;
        cout<<"Enter the date of birth\n\tyear : ";
        cin>>year;
        cout<<"\tmonth : ";
        cin>>month;
        cout<<"\tday : ";
        cin>>day;
        cout<<"Enter no_of_likes : ";
        cin>>no_of_likes;
        cout<<"Enter no_of_comments : ";
        cin>>no_of_Comments;

        node *new_Node = new node(name, index, day, month, year, no_of_likes, no_of_Comments);
        G[i] = new_Node;
    }
    connect();
}

void graph :: connect() {

    int no_of_edges, re, i, source, destination;
    cout<<"Enter the no. of Edges : ";
    cin>>no_of_edges;

    for (i=0; i<no_of_edges; i++) {
        cout<<"Enter the source and destination : ";
        cin>>source>>destination;
        re=insert(G,source,destination);
        re=insert(G,destination,source);
        if(re==1)
        {
            cout<<"\nEnter appropriate user id\n";
            i--;
        }
    }
}

int graph :: insert(node *graph[], int src, int des) {

    node *start,*p;
	start=graph[des];
    start->next=NULL;
    if(graph[src]->next==NULL) {
        graph[src]->next=start;
    }
    else {	
        p=graph[src]->next;
        while(p->next!=NULL) {
            p=p->next;
        }
        p->next=start;
    }
    friends[src]++;
    return 0;
}

void graph :: display() {

    cout<<"\n";
    cout<<"Index\tName\tBirthday\tLikes\tFriend\tComment\n";

    for (int i=0; i<no_of_users; i++) {
        node *temp = G[i];
        cout<<temp->index<<"\t"<<temp->name<<"\t"<<temp->day<<"-"<<temp->month<<"-"<<temp->year<<"\t"<<temp->no_of_likes<<"\t"<<friends[i]<<"\t"<<temp->no_of_Comments<<endl;
    }
}

void graph :: max_Friendz() {

    int max=0, index;
    for (int i=0; i<no_of_users; i++) {
        if (max < friends[i]) {
            max = friends[i];
            index = i;
        }
    }
    cout<<"\n\tPerson with max friendz : "<<G[index]->name;
    cout<<"\n\tNo. of friendz : "<<friends[index]<<endl;
}

void graph :: birthday_this_month(int x) {

    for (int i=0; i<no_of_users; i++) {
        if (G[i]->month == x) {
            cout<<"\nBirthday this month is of "<<G[i]->name<<endl;
        }
    }
}

void graph :: max_min_comments() {

    int max=0, min=9999;
    char min_name[20], max_name[20];
    min_name[0] = '\0';
    max_name[0] = '\0';
    for (int i=0; i<no_of_users; i++) {
        if (G[i]->no_of_Comments < min) {
            min = G[i]->no_of_Comments;
            strcpy(min_name, G[i]->name);
        }
        if (G[i]->no_of_Comments > max) {
            max = G[i]->no_of_Comments;
            strcpy(max_name, G[i]->name);
        }
    }
    cout<<"\n\tMax comments : \n\t"<<max_name<<endl<<"\t"<<max<<" comments\n"<<endl<<"\tMin comments : \n\t"<<min_name<<"\n\t"<<min<<" comments"<<endl;
}

int menu() {

    int x;
    cout<<"\n1. Enter the data\n"
          "2. Display the data\n"
          "3. Find max Friendz\n"
          "4. Birthday this month\n"
          "5. Max, Min comments\n"
          "6. Exit\nEnter : ";
    cin>>x;
    return x;
}

int main() {

    int x;
    graph g;
    while (1) {
        switch (menu()) {
            case 1 : 
                g.read_Graph();
                break;
            case 2 : 
                g.display();
                break;
            case 3 : 
                g.max_Friendz();
                break;
            case 4 :
                cout<<"Enter month : ";
                cin>>x;
                g.birthday_this_month(x);
                break;
            case 5 :
                g.max_min_comments();
                break;
            case 6 :
                cout<<"\nProgram exited sucessfully\n";
                exit(0);
        }
    }
    return 0;
}

/*

OUTPUT :

Enter the number of users : 4

1. Enter the data
2. Display the data
3. Find max Friendz
4. Birthday this month
5. Max, Min comments
6. Exit
Enter : 1

For User 0 :
Enter the name : User_0
Enter the date of birth
        year : 2000
        month : 1
        day : 1
Enter no_of_likes : 12
Enter no_of_comments : 23

For User 1 :
Enter the name : User_1
Enter the date of birth
        year : 2001
        month : 2
        day : 2
Enter no_of_likes : 34
Enter no_of_comments : 2

For User 2 :
Enter the name : User_2
Enter the date of birth
        year : 2002
        month : 3
        day : 3
Enter no_of_likes : 23
Enter no_of_comments : 23

For User 3 :
Enter the name : User_3
Enter the date of birth
        year : 2003
        month : 4
        day : 4
Enter no_of_likes : 43
Enter no_of_comments : 37
Enter the no. of Edges : 4
Enter the source and destination : 0 1
Enter the source and destination : 0 2
Enter the source and destination : 0 3
Enter the source and destination : 2 3

1. Enter the data
2. Display the data
3. Find max Friendz
4. Birthday this month
5. Max, Min comments
6. Exit
Enter : 2

Index   Name    Birthday        Likes   Friend  Comment
0       User_0  2000-1-1        12      3       23
1       User_1  2001-2-2        34      1       2
2       User_2  2002-3-3        23      2       23
3       User_3  2003-4-4        43      2       37

1. Enter the data
2. Display the data
3. Find max Friendz
4. Birthday this month
5. Max, Min comments
6. Exit
Enter : 3

        Person with max friendz : User_0
        No. of friendz : 3

1. Enter the data
2. Display the data
3. Find max Friendz
4. Birthday this month
5. Max, Min comments
6. Exit
Enter : 4
Enter month : 3

Birthday this month is of User_2

1. Enter the data
2. Display the data
3. Find max Friendz
4. Birthday this month
5. Max, Min comments
6. Exit
Enter : 5

        Max comments :
        User_3
        37 comments

        Min comments :
        User_1
        2 comments

1. Enter the data
2. Display the data
3. Find max Friendz
4. Birthday this month
5. Max, Min comments
6. Exit
Enter : 6

Program exited sucessfully

***************************************/

