#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool visited[10];
Point pointCustomers[10];

//State can be true or false
void setVisitedState(bool state)
{
    for(int i=0;i<10;i++)
    {
        visited[i] = state;
    }
}

//All Helper Functions at one place above the main Helper function i.e solveUtility()

int getAbsValueUtil(int v1,int v2)
{
    return v1>v2 ? v1-v2 : v2-v1;
}

int getDistanceUtil(Point pSource,Point pDestination)
{
    return getAbsValueUtil(pSource.x,pDestination.x) + getAbsValueUtil(pSource.y,pDestination.y);
}


int solveUtility(int parcelDelivered,int nCustomers,Point pHome,Point pCurrent)
{
    //Base condition we delivered all parcels so return the distance with home otherwise office
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
	    
	    cin>>nCustomers;
	    
	    Point pHome;
	    cin>>x>>y;
	    pHome.x = x;
	    pHome.y = y;
	    
	    Point pOffice;
	    cin>>x>>y;
	    pOffice.x = x;
	    pOffice.y = y;
	    
	    for(int i=0;i<nCustomers;i++)
	    {
	        Point p;
	        cin>>x>>y;
	        p.x = x;
	        p.y = y;
	        
	        pointCustomers[i] = p;
	    }
	    
	    setVisitedState(false);
	    int parcelDelivered = 0;
	    cout<<solveUtility(parcelDelivered,nCustomers,pHome,pOffice)<<endl;
	    
	}
	
	return 0;
}
