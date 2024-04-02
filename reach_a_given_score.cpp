//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {   
        long long int count=0;
        
    	// Your code here
    	for(long long int i=0;i<=n/3;i++){
    	    for(long long int j=0;j<=n/5;j++){
    	        for(long long int k=0;k<=n/10;k++){
    	            if(i*3+5*j+10*k==n) count++;
    	    }
    	}
    }
    return count;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends