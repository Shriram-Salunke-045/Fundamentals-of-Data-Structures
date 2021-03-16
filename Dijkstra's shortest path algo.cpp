/*********************************************************
a) Use the map of the area around the college as the graph. Identify the prominent land marks as
nodes and find minimum distance to various land marks from the college as the source. Represent
this graph using adjacency matrix
b) find the shortest path using Dijkstra’s algorithm.
******************************************************/

#include <iostream>
#define INFINITY 999
using namespace std;

class graph {

    int v;
    int **adj;
    char **names_of_places;

  public :
    graph(int x);
    void get_data();
    void connect(int source, int destination, int distance);
    void dijstra_Algorithm(int start);
    void display_places();
    int minDistance(int dist[], bool sptSet[]);
    void printSolution(int dist[]);
};

graph :: graph(int x) {

    v = x;
    adj = new int *[v];
    for (int i=0; i<v; i++) {
        adj[i] = new int[v];
        for (int j=0; j<v; j++) {
            adj[i][j] = 0;
        }
    }
    names_of_places = new char *[v];
    for (int i=0; i<v; i++) {
        names_of_places[i] = new char[20];
        names_of_places[i][0] = '\0';
    }
}

void graph :: get_data() {

    int x, source, destination, distance;
    names_of_places[0] = "College";
    cout<<"College will be considereed as place 0\n";
    for (int i=1; i<v; i++) {
        cout<<"Enter the name of place "<<i<<" : ";
        cin>>names_of_places[i];
    }
    cout<<"\nEnter the number of Paths(Edges) : ";
    cin>>x;
    cout<<endl;
    for (int i=0; i<x; i++) {
        cout<<"Enter the Source and Destination : ";
        cin>>source>>destination;
        cout<<"Enter the distance : ";
        cin>>distance;
        cout<<endl;
        connect(source, destination, distance);
    }
}

void graph :: connect(int x, int y, int D) {

    adj[x][y] = D;
    adj[y][x] = D;
}

void graph :: printSolution(int dist[]) 
{ 
    cout<<"\tIndex\tNameOfPlace\tminimumDistance\n";
    for (int i = 0; i < v; i++) {
        cout<<"\t"<<i<<"\t"<<names_of_places[i]<<"\t\t"<<dist[i]<<endl;
    } 
} 

int graph :: minDistance(int dist[], bool visited[]) 
{ 
    int min = INFINITY, min_index; 
    for (int i = 0; i < v; i++) 
        if (visited[i] == false && dist[i] <= min) 
            min = dist[i], min_index = i; 
    return min_index; 
} 

void graph :: dijstra_Algorithm(int src) {

    int dist[v];
    bool visited[v];
    
    for (int i = 0; i < v; i++) {
        dist[i] = INFINITY, visited[i] = false;
    }

    dist[src] = 0; 
    for (int count = 0; count < v - 1; count++) { 
        int u = minDistance(dist, visited); 
        visited[u] = true;  
        for (int i = 0; i < v; i++) 
            if (!visited[i] && adj[u][i] && dist[u] != INFINITY && dist[u] + adj[u][i] < dist[i]) 
                dist[i] = dist[u] + adj[u][i]; 
    }  
    printSolution(dist); 
} 

void graph :: display_places() {

    cout<<"\tIndex\tNames_of_Places\n";
    for (int i=0; i<v; i++) {
        cout<<"\t"<<i<<"\t"<<names_of_places[i]<<endl;
    }
}

int menu() {
    int x;
    cout<<"\n1. Enter the places.\n"
          "2. Display all the places with their index values.\n"
          "3. Display shortest path to places from college.\n"
          "4. Exit.          Enter choice : ";
    cin>>x;
    cout<<endl;
    return x;
}

int main() {

    int x, start;
    cout<<"\nEnter the number of Places or vertices(including college) : ";
    cin>>x;
    graph g(x);

    while (1) {
        switch (menu()) {
            case 1 :
                g.get_data();
                break;
            case 2 : 
                g.display_places();
                break;
            case 3 :
                cout<<"Enter the index of the place to be considered as start point : ";
                cin>>start;
                g.dijstra_Algorithm(start);
                break;
            case 4 :
                cout<<"Program exited successfully.......\n";
                exit(0);
        }
    }
}

/*

Enter the number of Places or vertices(including college) : 5

1. Enter the places.
2. Display all the places with their index values.
3. Display shortest path to places from college.
4. Exit.          Enter choice : 1

College will be considereed as place 0
Enter the name of place 1 : Gym
Enter the name of place 2 : Canteen
Enter the name of place 3 : Garden
Enter the name of place 4 : Library

Enter the number of Paths(Edges) : 7

Enter the Source and Destination : 0 1
Enter the distance : 10

Enter the Source and Destination : 0 3
Enter the distance : 30

Enter the Source and Destination : 0 4
Enter the distance : 100

Enter the Source and Destination : 2 4
Enter the distance : 10

Enter the Source and Destination : 1 2
Enter the distance : 50

Enter the Source and Destination : 2 3
Enter the distance : 20

Enter the Source and Destination : 3 4
Enter the distance : 60


1. Enter the places.
2. Display all the places with their index values.
3. Display shortest path to places from college.
4. Exit.          Enter choice : 2

        Index   Names_of_Places
        0       College
        1       Gym
        2       Canteen
        3       Garden
        4       Library

1. Enter the places.
2. Display all the places with their index values.
3. Display shortest path to places from college.
4. Exit.          Enter choice : 3

Enter the index of the place to be considered as start point : 0
        Index   NameOfPlace     minimumDistance
        0       College         0
        1       Gym             10
        2       Canteen         50
        3       Garden          30
        4       Library         60

1. Enter the places.
2. Display all the places with their index values.
3. Display shortest path to places from college.
4. Exit.          Enter choice : 4

Program exited successfully.......

*********************************/

