#include <bits/stdc++.h>

using namespace std;

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For creating graph
vector<vector<int>> createGraph(int V)
{
    vector<vector<int>> res(V);
    cout << "Graph with " << V << " vertices created" << endl;
    return res;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For adding edge
void addEdge(vector<vector<int>> &graph, int src, int dest)
{
    graph[src].push_back(dest);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For Finding OutDegree of nodes
int getOutDegreeOfNode(int n, vector<vector<int>> &graph)
{
    return graph[n].size();
}

void printOutDegree(vector<vector<int>> &graph)
{
    cout << "-----------------------------------------------" << endl;
    cout << "Printing the OutDegree of graph" << endl;

    vector<int> outDegree(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++)
    {
        outDegree[i] = getOutDegreeOfNode(i, graph);
    }

    for (int i = 0; i < outDegree.size(); i++)
    {
        cout << i << "->" << outDegree[i] << endl;
    }

    cout << "-----------------------------------------------" << endl;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For Finding OutDegree of nodes
void printInDegree(vector<vector<int>> &graph)
{
    cout << "-----------------------------------------------" << endl;
    cout << "Printing the InDegree of graph" << endl;

    vector<int> inDegree(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            inDegree[graph[i][j]]++;
        }
    }

    for (int i = 0; i < inDegree.size(); i++)
    {
        cout << i << "->" << inDegree[i] << endl;
    }

    cout << "-----------------------------------------------" << endl;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For printing Topological Sort of graph
// Using BFS
void topologicalSortBFS(vector<vector<int>> &graph)
{
    cout << "-----------------------------------------------" << endl;
    cout << "Printing the Topological sort of graph using Kahn's Algorithm" << endl;
    vector<int> inDegree(graph.size(), 0);

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            inDegree[graph[i][j]]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop();

        for (int i = 0; i < graph[temp]; i++)
        {
            if (--inDegree[graph[temp][i]] == 0)
            {
                q.push(graph[temp][i]);
            }
        }
    }
    cout << endl;
    cout << "-----------------------------------------------" << endl;
}

// Using DFS
void utilityTopologicalSortDFS(int i, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &res)
{
    if (visited[i] == false)
    {
        visited[i] = true;

        for (auto v : graph[i])
        {
            if (visited[v] == false)
            {
                utilityTopologicalSortDFS(v, graph, visited, res);
            }
        }

        res.push_back(i);
    }
}

void topologicalSortDFS(vector<vector<int>> &graph)
{
    vector<int> res;

    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            utilityTopologicalSortDFS(i, graph, visited, res);
        }
    }

    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " ";
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For DFS
void utilityDFS(int n, vector<vector<int>> &graph, vector<bool> &visited)
{
    if (visited[n] == false)
    {
        cout << n << " ";
        visited[n] = true;

        for (auto i : graph[n])
        {
            if (visited[i] == false)
            {
                utilityDFS(i, graph, visited);
            }
        }
    }
}

void DFS(vector<vector<int>> &graph)
{
    cout << "-----------------------------------------------" << endl;
    cout << "Printing the DFS of graph" << endl;

    vector<bool> visited[graph.size(), false];

    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i] == false)
        {
            utilityDFS(i, graph, visited);
        }
    }

    cout << "-----------------------------------------------" << endl;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For BFS
void utilityBFS(int n, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";

        for (auto i : graph[temp])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void BFS(vector<vector<int>> &graph)
{
    cout << "-----------------------------------------------" << endl;
    cout << "Printing the DFS graph" << endl;

    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i] == false)
        {
            utilityBFS(i, graph, visited);
        }
    }

    cout << "-----------------------------------------------" << endl;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// For Printing entire graph adjacency list
void printGraph(vector<vector<int>> &graph)
{
    cout << "-----------------------------------------------" << endl;
    cout << "Printing the graph" << endl;

    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> [ ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << "-----------------------------------------------" << endl;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Detect Cycle for Directed Graph
bool utilityCyclicDirected(int n, vector<bool> &visited, vector<bool> &recStack, vector<vector<int>> &graph)
{
    visited[n] = true;
    recStack[n] = true;

    for (auto i : graph[n])
    {
        if (visited[i] == false)
        {
            if (utilityCyclicDirected(i, visited, recStack, graph))
            {
                return true;
            }
            else if (recStack[i] == true)
            {
                return true;
            }
        }
    }

    recStack[n] = false;

    return false;
}

bool isCyclicDirected(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    vector<bool> recStack(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i] == false)
        {
            if (utilityCyclicDirected(i, visited, recStack, graph))
            {
                return true;
            }
        }
    }

    return false;
}

// Detect Cycle for Undirected Graph
bool utilityCyclicUndirected(int v, int parent, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[v] = true;

    for (auto i : graph[v])
    {
        if (visited[i] == false)
        {
            if (utilityCyclicUndirected(i, v, graph, visited))
            {
                return true;
            }
        }
        else if (i != parent)
        {
            return true;
        }
    }

    return false;
}

bool isCyclicUndirected(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if (visited[i] == false)
        {
            if (utilityCyclicUndirected(i, -1, graph, visited) == true)
            {
                return true;
            }
        }
    }

    return false;
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int main()
{

    int V = 6;

    vector<vector<int>> graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printGraph(graph);
}
