/*********************************************************************************************************
Q. 	a) A business house has several offices in different countries; they want to lease phone lines to
		connect them with each other and the phone company charges different rent to connect different
		pairs of cities. Business house want to connect all its offices with a minimum total cost.
		Bansilal Ramnath Agarwal Charitable Trust’s
		Vishwakarma Institute of Information Technology, Pune-48
		(An Autonomous Institute affiliated to Savitribai Phule Pune University)
		Department of Information Technology
		CURRICULUM BOOK
		i) Represent using appropriate data structure.
	b) Apply suitable algorithm to find minimum total cost. (Prim’s algorithm)
	***************************************************************************************/
	
#include <stdio.h>
#include <iostream>
using namespace std;

class Graph
{
    int *visited_arr,*parent_arr,*key,**edgematrix,vertices,cost=0;
    public:
    Graph(int no)                   //constructor
    {
        vertices=no;
        
        key = new int[no];
        for(int i=0;i<no;i++)
            key[i]=9999;            //default
        
        
        visited_arr = new int[no];
        for(int i=0;i<no;i++)
            visited_arr[i]=0;       //Initialize to 0
            
        parent_arr = new int[no];
        for(int i=0;i<no;i++)
            parent_arr[i]=0;        //Initialize to 0
        
        edgematrix = new int*[no];
        for(int i = 0; i < no; i++)
            edgematrix[i] = new int[no];
            
        for(int i=0;i<no;i++)
        {
            for(int j=0;j<no;j++)
            {
                edgematrix[i][j]=0;
            }
            
        }
    }
    
    void create_edges(int edges);
    int minKey(/*int key,int visited_arr*/);
    void printMST(/*int parent, int edgematrix*/);  
    void prims();
    void min_total_cost();
    
};


void Graph:: prims()
{
    key[0]=0;
    parent_arr[0]=-1;
    int u;
    for(int count = 0; count < vertices - 1; count++)
    {
        u=minKey();                             //find edge with lowest weight
        visited_arr[u]=1;                       //mark visited
        for(int i = 0; i<vertices; i++)
        {
            if(edgematrix[u][i] != 0 && visited_arr[i] == 0 && edgematrix[u][i] < key[i])
            {
                parent_arr[i] = u;
                key[i] = edgematrix[u][i];
            }
        }
    }
    
    printMST();
}

int Graph :: minKey(/*key,visited_arr*/)  
{  
    // Initialize min value  
    int min = 9999; 
    int min_index;  
    for (int i = 0; i < vertices; i++)  
        if (visited_arr[i] == 0 && key[i] < min)  
            min = key[i], min_index = i;  
  
    return min_index;  
}  

void Graph:: printMST(/*int parent, int edgematrix*/)  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < vertices; i++)  
    {
        cout<<parent_arr[i]<<" - "<<i<<" \t"<<edgematrix[i][parent_arr[i]]<<" \n";  
        cost=cost+edgematrix[i][parent_arr[i]];
    } 
}

void Graph::create_edges(int edges)
{
    int destination,source,weight;
    for(int i=0;i<edges;i++)
    {
        cout<<"enter source of the edge\n";
        cin>>source;
        cout<<"enter destination of the edge\n";
        cin>>destination;
        cout<<"enter weight of the edge\n";
        cin>>weight;
        edgematrix[source][destination]=weight;
        edgematrix[destination][source]=weight;
    }
}

void Graph:: min_total_cost(){
    cout<<"min cost required is :"<<cost;
}

int main()
{
    int x;
    cout<<"give no of vertex\n";
    cin>>x;
    Graph g(x);
    cout<<"enter no of edges to create in graph\n";
    cin>>x;
    g.create_edges(x);
    g.prims();
    g.min_total_cost();

    return 0;
}




/************************************************
OUTPUT:
give no of vertex
7
enter no of edges to create in graph
9
enter source of the edge
0
enter destination of the edge
4
enter weight of the edge
3
enter source of the edge
4
enter destination of the edge
6
enter weight of the edge
5
enter source of the edge
6
enter destination of the edge
5
enter weight of the edge
7
enter source of the edge
5
enter destination of the edge
3
enter weight of the edge
2
enter source of the edge
3
enter destination of the edge
2
enter weight of the edge
3
enter source of the edge
2
enter destination of the edge
0
enter weight of the edge
2
enter source of the edge
0
enter destination of the edge
1
enter weight of the edge
1
enter source of the edge
1
enter destination of the edge
4
enter weight of the edge
2
enter source of the edge
1
enter destination of the edge
5
enter weight of the edge
4
Edge 	Weight
0 - 1 	1 
0 - 2 	2 
2 - 3 	3 
1 - 4 	2 
3 - 5 	2 
4 - 6 	5 
min cost required is :15
**********************/

		
