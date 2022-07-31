//Author NAVDEEPISNO1
//Navdeep Sharma

//Question :

/*
Algorithm

Basic: We will run a BFS and color the adjacent vertices with different color than parent vertex, If we found that any of two adjacent vertex have same color we will return false/-1 other wise we will print the answer

*/

//Code

//Include important header files
#include <iostream>

//Namespace to avoid variable name confusion
using namespace std;

//Our graph
int graph[100][100];

//Helper FUnction to Initialise graph or reset graph to 0
//A[i][j] = 0 => No edge from i to j
//A[i][j] = 1 => Edge from i to j
void initializeGraph()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            graph[i][j] = 0;
        }
    }
}

//Utility Function to perform BFS and Color the graph
bool bfs(int vertex, int nodeColors[], int nVertices)
{
    //Assume that our graph is bipartite
    bool res = true;

    //Iterate over every adjacent neighbour of vertex
    for (int i = 0; i < nVertices; i++)
    {
        //Only consider if there is edge i.e graph[i][j]==1
        if (graph[vertex][i] == 1)
        {
            //Now if Vertex is not colored we will color it with different color than parent vertex
            if (nodeColors[i] != -1)
            {
                //Color the vertex
                nodeColors[i] = 1 - nodeColors[vertex];
                res = res & bfs(i, nodeColors, nVertices);
            }
            //If adjacent vertices have same color It means that the graph is not bipartite
            else if (nodeColors[i] == nodeColors[vertex])
            {
                return false;
            }
        }
    }

    //Return result
    return res;
}

//Utility Function to check if graph is BiPartite or not
bool checkBipartiteGraph(int nVertices, int nodeColors[])
{
    //Run BFS from every vertex which is uncolored
    for (int i = 0; i < nVertices; i++)
    {
        //Only consider unvisited or uncolored Vertex
        if (nodeColors[i] != -1)
        {
            //Color it with 0
            nodeColors[i] = 0;
            //And check for the condition of bipartite
            if (bfs(i, nodeColors, nVertices) == false)
            {
                return false;
            }
        }
    }

    return true;
}

//Main Function
int main()
{
    //Get the testcases
    int t;
    cin >> t;

    //Iterate while t!=0 (0=false)
    while (t--)
    {
        //Reset the graph edges
        initializeGraph();

        //Get the number of vertices
        int nVertices;
        cin >> nVertices;

        //Create a tracking array to track which vertex is given which color
        int nodeColors[nVertices];
        for (int i = 0; i < nVertices; i++)
        {
            nodeColors[i] = -1;
        }

        //Input the Adjacency Matrix
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                cin >> graph[i][j];
            }
        }

        //Call the helper function
        bool isBartite = checkBipartiteGraph(nVertices, nodeColors);

        //Print the vertices if graph is BiPartite
        if (isBartite == true)
        {
            for (int i = 0; i < nVertices; i++)
            {
                if (nodeColors[i] == 0)
                {
                    cout << i << " ";
                }
            }
        }
        //Else print -1
        else
        {
            cout << "-1";
        }

        cout << endl;
    }

    //Yeah Our Program executed successfully
    return 0;
}