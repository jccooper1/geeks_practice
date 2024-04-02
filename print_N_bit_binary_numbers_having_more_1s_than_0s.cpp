//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
std::string decimalToBinary(int decimal, int numBits) {
    std::string binary = std::bitset<32>(decimal).to_string();
    // Keep the last numBits digits
    return binary.substr(32 - numBits);
}
	vector<string> NBitBinary(int n)
	{
	    vector<string>dp;
	  if(!n%2){
	      int max=0;
	      for(int i=0;i<n;i++){
	          max+=pow(2,i);
	      }
	      int min=0;
	      for(int i=0;i<n/2-1;i++){
	          min+=pow(2,i);
	      }
	      min=min+pow(2,n-1);
	      for(int i=min;i<=max;i++){
	          string str1=decimalToBinary(i);
	          dp.push_back(str1);
	      }
	  }
	  else{
	      int max=0;
	      for(int i=0;i<n;i++){
	          max+=pow(2,i);
	      }
	      int min=0;
	      for(int i=0;i<n/2;i++){
	          min+=pow(2,i);
	      }
	      min+=pow(2,n-1);
	      for(int i=min;i<=max;i++){
	          string str1=decimalToBinary(i);
	          dp.push_back(str1);
	      }
	      
	  }
	  
	  return dp;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends