//Author NAVDEEPISNO1
//Navdeep Sharma



/*
ALgorithm

The basic idea used here is we will enumerate every possible combination

Steps:
1 As we know that we have two coordinates everywhere and we need them at same time to perform calculation given in the question (Here Distance).
2 Create struct to hold both x & y .Here we call it as Point
3 Always create Functions in bottom up manner. i.e main should be bottommost , helper function must be above main, any other utility function in the same way as previous one.
4 Inorder to track Visited Customer create an boolean 1D array of Size MAX_CLIENTS .i.e 10 here

*/


//Include basic header files
#include <bits/stdc++.h>

//Add namespace to remove confusion among variables
using namespace std;

//Create stucture to hold the coordinate or point .Its best practice to create it above all the variables to avoid compiler error
struct Point
{
    int x;
    int y;
};

//Create a global visited array & Customers array
bool visited[10];
Point pointCustomers[10];

//Utility function to set State of Visited Array.(State can be true or false)
void setVisitedState(bool state)
{
    for(int i=0;i<10;i++)
    {
        visited[i] = state;
    }
}

//All Helper Functions at one place above the main Helper function i.e solveUtility()
//Self Defined
int getAbsValueUtil(int v1,int v2)
{
    return v1>v2 ? v1-v2 : v2-v1;
}

//Self Defined
int getDistanceUtil(Point pSource,Point pDestination)
{
    return getAbsValueUtil(pSource.x,pDestination.x) + getAbsValueUtil(pSource.y,pDestination.y);
}

//Self Defined
int solveUtility(int parcelDelivered,int nCustomers,Point pHome,Point pCurrent)
{
    //Base condition we delivered all parcels so return the distance with home.
    if(parcelDelivered==nCustomers)
    {
        return getDistanceUtil(pCurrent,pHome);
    }
    
    //Initialize answer with INT_MAX because we have to get minimum distance
    int ans = INT_MAX;
    
    for(int i=0;i<nCustomers;i++)
    {
        Point pDestination = pointCustomers[i];
        
        //Check if we have visited the current customer 
        if(!visited[i])
        {
            //Mark this location as visited
            visited[i] = true;
            
            //Get the distance between current location and destination
            int val = getDistanceUtil(pCurrent,pDestination);
            
            //Update answer with the minimum value that we get after considering this location in solution 
            //And pass current pDestination as pCurrent
            ans = min(ans,val + solveUtility(parcelDelivered+1,nCustomers,pHome,pDestination));
            
            //Use backtracking and unmark the location
            visited[i] = false;
        }
    }
    
    //return the answer
    return ans;
    
}


//Main function from where CPU start reading the program
int main() {	
	//Get number of testcases
	int t;
	cin>>t;
	
	//Run loop till t!=0 because 0 = false
	while(t--)
	{
	    //Store number of customers in nCustomers
	    int nCustomers;
	    
	    //Store x and y in variables
            int x,y;
	    
		//Get the number of customers
	    cin>>nCustomers;
	    
		//Get Home coordinates or points
	    Point pHome;
	    cin>>x>>y;
	    pHome.x = x;
	    pHome.y = y;
	    
		//Get Office coordinates or points
	    Point pOffice;
	    cin>>x>>y;
	    pOffice.x = x;
	    pOffice.y = y;
	    
		//Get Customer coordinates or points and fill in the array
	    for(int i=0;i<nCustomers;i++)
	    {
	        Point p;
	        cin>>x>>y;
	        p.x = x;
	        p.y = y;
	        
	        pointCustomers[i] = p;
	    }
	    
		//Set Visited Array to false
	    setVisitedState(false);
		
		//Set number of parcel delivered or number of customers reached
	    int parcelDelivered = 0;
		
		//Output the result
	    cout<<solveUtility(parcelDelivered,nCustomers,pHome,pOffice)<<endl;	    
	}
	
	return 0;
}
