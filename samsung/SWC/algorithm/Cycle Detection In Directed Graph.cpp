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
To detect the cycle we will use a recursion stack in the form of boolean array which will check for the element if present in

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

void setVisitedState(bool state)
{
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
}

void setRecStackState(bool state)
{
    for (int i = 0; i < 100; i++)
    {
        recStack[i] = false;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> V;
    }
}
