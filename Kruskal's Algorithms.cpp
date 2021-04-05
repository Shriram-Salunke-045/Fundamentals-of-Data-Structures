/************************************************************************
a) Represent any real world graph using adjacency list /adjacency matrix
b) Find minimum spanning tree using Kruskal’s algorithm.
*************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

class Graph
{
    int visited_arr,edgematrix,*final_matrix,vertices,edges,cost=0;
    public:
    Graph(int v,int e)              
    {
        vertices=v;                 
        edges=e;                    
     
        
        visited_arr = new int[vertices];
        for(int i=0;i<vertices;i++)
            visited_arr[i]=0;           //initialize to 0
        
        edgematrix = new int*[edges];
        for(int i = 0; i < edges; i++)
            edgematrix[i] = new int[3];             /int* matrix = new int*[rows];
                                                    for (int i = 0; i < rows; ++i)
                                                        matrix[i] = new int[cols];*/
            
        final_matrix=new int*[vertices-1];
        for(int i = 0;i < vertices-1; i++)
            final_matrix[i]=new int[3];
            
        for(int i=0;i<edges;i++)
        {
            for(int j=0;j<3;j++)
            {
                edgematrix[i][j]=0;             
            }
        }
    }
    
    void create_edges();
    void update(int s,int d,int w,int count);
    void kruskals();
    void print_edge();

};

void Graph::create_edges()
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
        edgematrix[i][0]=source;
        edgematrix[i][1]=destination;
        edgematrix[i][2]=weight;
    }
}


void Graph:: update(int s,int d,int w,int count)        
{
    int j=count-1;                  
    final_matrix[j][0]=s;
    final_matrix[j][1]=d;
    final_matrix[j][2]=w;
}

void Graph:: kruskals()
{
    int edgecount=0;
    for(int i=0;edgecount!=vertices-1;i++)
    {
      if(visited_arr[edgematrix[i][0]]==0 && visited_arr[edgematrix[i][1]]==0)
      {
            visited_arr[edgematrix[i][0]]=1;
            visited_arr[edgematrix[i][1]]=1;
            cost+=edgematrix[i][2];
            edgecount++;
            update(edgematrix[i][0],edgematrix[i][1],edgematrix[i][2],edgecount);
            
      }
      else if(visited_arr[edgematrix[i][0]]==0 && visited_arr[edgematrix[i][1]]==1)
      {
            visited_arr[edgematrix[i][0]]=1;
            cost+=edgematrix[i][2];
            edgecount++;
            update(edgematrix[i][0],edgematrix[i][1],edgematrix[i][2],edgecount);
            
      }
      else if(visited_arr[edgematrix[i][0]]==1 && visited_arr[edgematrix[i][1]]==0)
      {
            visited_arr[edgematrix[i][1]]=1;
            cost+=edgematrix[i][2];
            edgecount++;
            update(edgematrix[i][0],edgematrix[i][1],edgematrix[i][2],edgecount);
            
      }
      
     /* else(visited_arr[edgematrix[i][0]]==1 && visited_arr[edgematrix[i][1]]==1)
      {
            //deallocate the row from edgematrix
      } */
      
            
    }
}

void Graph:: print_edge()
{
       for(int i=0;i<vertices-1;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<final_matrix[i][j]<<"\t";
            }
            cout<<"\n";
        }
        
        cout<<"min cost is :"<<cost;
}


int main()
{
    int x,y;
    cout<<"give no of vertex\n";
    cin>>x;
    cout<<"enter no of edges to create in graph\n";
    cin>>y;
    Graph g(x,y);
    g.create_edges();
    g.kruskals();
    g.print_edge();
    return 0;
}




/*
OUTPUT:
give no of vertex
6
enter no of edges to create in graph
8
enter source of the edge
3
enter destination of the edge
5
enter weight of the edge
5
enter source of the edge
4
enter destination of the edge
5
enter weight of the edge
8
enter source of the edge

3
enter destination of the edge
4
enter weight of the edge
9
enter source of the edge
0
enter destination of the edge
3
enter weight of the edge
10
enter source of the edge
2
enter destination of the edge
3
enter weight of the edge
10
enter source of the edge
1
enter destination of the edge
2
enter weight of the edge
12
enter source of the edge
0
enter destination of the edge
1
enter weight of the edge
15
enter source of the edge
2
enter destination of the edge
5
enter weight of the edge
15
3	5	5	
4	5	8	
0	3	10	
2	3	10	
1	2	12	
min cost is :45

**********************************************/

