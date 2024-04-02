//{ Driver Code Starts
//Initial Template for C++
/*You are given two four digit prime numbers num1 and num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.*/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int prime[10000];
    void all_prime(){
        memset(prime,1,sizeof(prime));
        prime[0]=prime[1]=0;
        for(int i=2;i<=9999;i++){
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    prime[i]=0;
                }
                else{
                    prime[i]=1;
            }
        }
    }
    }
    int solve(int num1,int num2)
    {   
      //code here
    all_prime();
    queue<pair<int,int>> q;
    q.push({num1,0});
    while(!q.empty()){
        auto curr=q.front();
        int dist=curr.second;
        q.pop();
        if(n=num2){
            return dist;
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<=9;j++){
                int nxt = int(n/ pow(10,i+1)) *pow(10,i+1) + (j * pow(10,i)) + (n % int pow(10,i));
                if(prime[nxt]==1){
                    q.push({nxt,dist+1});
                }
            
        }
    }
    }
    return -1;
    }
    
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends