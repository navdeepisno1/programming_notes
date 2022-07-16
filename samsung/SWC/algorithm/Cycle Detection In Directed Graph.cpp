//Author: navdeepisno1
//Navdeep Sharma

/*
Algorithm

Note: As we cannot use STL ,we will create graph using Adjacency Matrix:
      A[i][j] = 0  => No Edge from Node/Vertex i to Node/Vertex j
      A[i][j] = 1  => Edge from Node/Vertex i to Node/Vertex j

In order to prevent any error during Matrix pass in function we will use global variables like
Adjacency Matrix, Visited Array,Recursion Stack Array       

Basic Approach : We will do a DFS on the graph and check for cycle from every node. If we found a cycle print it.
To detect the cycle we will use a recursion stack in the form of boolean array which will check for the element if present in the current tree generated

*/

//CODE Starts here

#include <bits/stdc++.h>

using namespace std;

//Graph size
int V;

//Global Arrays
int graph[100][100];
bool visited[100];
bool recStack[100];

//Self Defined
void initializeGraph()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
}

//Self Defined
void setVisitedState(bool state)
{
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
}

//Self Defined
void setRecStackState(bool state)
{
    for (int i = 0; i < 100; i++)
    {
        recStack[i] = false;
    }
}

//Self Defined
void printGraph()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

//Self Defined
bool dfs(int currentNode, int &parentNode)
{
    if (visited[currentNode] == true)
    {
        recStack[currentNode] = false;
        return false;
    }
    //Mark Visited array as true
    visited[currentNode] = true;

    //Mark recursion stack as true
    recStack[currentNode] = true;

    //As we are using Adjacency Matrix we will iterate from 0 to Vertex(exclusive)
    for (int node = 0; node < V; node++)
    {

        //Get if the node is present or not
        int isNodePresent = graph[currentNode][node]; //0 = Not present || 1 = Present

        //Process only if node is present else not
        if (isNodePresent == 1)
        {
            //If Node is not visited
            if (visited[node] == false)
            {
                //Recur for node and currentNode as parentNode
                if (dfs(node, currentNode) == true)
                {
                    //If Node is equal to parentNode means Self edge
                    if (node == parentNode)
                    {
                        cout << node << " ";
                        parentNode = -1;
                    }
                    else if (parentNode != -1)
                    {
                        cout << node << " ";
                    }
                    return true;
                }
            }
            //If node is present in recursion stack We found a cycle
            else if (recStack[node] == true)
            {
                //Change parentNode to node
                parentNode = node;
                return true;
            }
        }
    }

    //Remove currentNode from recursion stack/array
    recStack[currentNode] = false;
    return false;
}

bool checkCycleUtil()
{
    int parentNode = -1;
    for (int node = 0; node < V; node++)
    {
        if (visited[node] == false)
        {
            if (dfs(node, parentNode) == true)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    //Number of test cases
    int t;
    cin >> t;

    while (t--)
    {
        //Get number of vertices
        cin >> V;

        //initializeGraph,Visited array and recursion stack
        initializeGraph();
        setVisitedState(false);
        setRecStackState(false);

        //Get number of Edges
        int nEdges;
        cin >> nEdges;

        while (nEdges--)
        {
            //Get edge from starting vertex to ending vertex
            int vStart, vEnd;
            cin >> vStart >> vEnd;

            //Set edge in graph
            graph[vStart][vEnd] = 1;
        }

        cout << checkCycleUtil() << endl;
    }

    return 0;
}
