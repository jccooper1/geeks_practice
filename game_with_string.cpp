/*Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. */
/*Input: 
s = abccc, k = 1
Output: 
6
Explaination:
We remove c to get the value as 1^2 + 1^2 + 2^2
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        int freq[26]={0};
        for(char c:s){
            freq[c-'a']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            pq.push(freq[i]);
        }
        while(k>0){
            int top=pq.top();
            pq.pop();
            pq.push(top-1);
            k--;
        }
        int res=0;
        while(!pq.empty()){
            int top1=pq.top();
            res+=pow(top1,2);
            pq.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends