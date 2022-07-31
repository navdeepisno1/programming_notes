//Author NAVDEEPISNO1
//Navdeep Sharma

//Question : Wormholes

/*
Algorithm

Basic Approach: We will enumerate every possible path using backtracking and return the minimum cost from them.

Steps:
1 -> Start with Initial Source and Destination ,Now as specified in question we can use wormholes any number of time.
2 -> At every step we will iterate over every wormhole and calculate the cost with code + distance 
3 -> Now the near end to destination could be either start or destination of wormholes. We have to consider that both could source.
4 -> Update answer at every step and at last print the answer

*/

//Code

//Main header files
#include <iostream>

//Namespace to avoid variable name confusion
using namespace std;

//Structure to store location/position
struct Position
{
    int x;
    int y;
};

//Structure to store Wormhole details
struct WormHole
{
    struct Position start;
    struct Position end;
    int cost;
};

//Global Variables
int nWormholes;
int minCost;
int answer = 100000;
struct Position source, destination;

//Global arrays
struct WormHole wormholes[100];
int visited[100];

//Utility Functions

//Self Defined
int getMin(int a, int b)
{
    return a > b ? b : a;
}

//Self Defined
int getAbsoluteDifference(int a, int b)
{
    return a > b ? a - b : b - a;
}

//Self Defined
int getDistance(struct Position p1, struct Position p2)
{
    return getAbsoluteDifference(p1.x - p2.x) + getAbsoluteDifference(p1.y - p2.y);
}

//Main Utility function to solve problem
void solve(struct Position src, struct Position dest, int cost)
{
    //Add cost to the distance and compare to the current answer and update with minium value
    int tempCost = cost + getDistance(src, dest);
    answer = getMin(answer, tempCost);

    //Iterate over every wormhole
    for (int i = 0; i < nWormholes; i++)
    {
        //Consider only if unvisited
        if (visited[i] == 0)
        {
            //Mark as visited
            visited[i] = 1;

            int val;

            //Consider start of wormhole as next src
            val = wormholes[i].cost + getDistance(src, wormholes[i].start);
            solve(wormholes[i].start, dest, cost + val);

            //Consider end of wormhole as next src
            val = wormholes[i].cost + getDistance(src, wormholes[i].end);
            solve(wormholes[i].end, dest, cost + val);

            //Mark as unvisited
            visited[i] = 0;
        }
    }
}

//Main Function
int main()
{

    //Get number of testcases
    int t;
    cin >> t;

    //Loop till t!=0 i.e 0 = false
    while (t--)
    {
        //Get the source and destinations
        cin >> source.x >> source.y;
        cin >> destination.x >> destination.y;

        //Get the number of wormholes
        cin >> nWormholes;

        //Get wormholes details
        for (int i = 0; i < nWormholes; i++)
        {
            struct WormHole w;
            cin >> w.start.x >> w.start.y >> w.end.x >> w.end.y >> w.cost;

            wormholes[i] = w;
        }

        //Solve with start point as source and final point as destination
        solve(source, destination, 0);

        //Output the answer
        cout << answer << endl;
    }

    //Yeah program executed successfully
    return 0;
}