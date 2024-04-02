/*In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy->sell->buy->sell). The stock prices throughout the day are represented in the form of an array of prices. 

Given an array price of size n, find out the maximum profit that a share trader could have made.*/
/*Input:
n = 6
prices[] = {10,22,5,75,65,80}
Output:
87
Explanation:
Trader earns 87 as sum of 12, 75 Buy at 10, sell at 22, Buy at 5 and sell at 80.*/
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n=price.size();
            int  profit1[n]={0};
            int  profit2[n]={0};
            int min_price=price[0];
            for(int i=1;i<=n;i++){
                min_price=min(min_price,price[i]);
                profit1[i]=max(profit1[i-1],price[i]-min_price);
            }
            int max_price=price[n-1];
            for(int i=n-2;i>=0;i--){
                max_price=max(max_price,price[i]);
                profit2[i]=max(profit2[i+1],profit1[i]+max_price-price[i]);
            }
            return profit2[0];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends