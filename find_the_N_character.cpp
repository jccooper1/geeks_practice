//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//I tried using the recursion but it will take too much time to execute 
// } Driver Code Ends
//User function template for C++
/*
class Solution{
public:
    std::string find(std::string s, int r, std::string &res){
        if(r==0) return s;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') res+="10";
            else if(s[i]=='0') res+="01";
        }
        s=res;
        res="";
        return find(s,r-1,res);
    }

    char nthCharacter(std::string s, int r, int n) {
        std::string hh="";
        std::string res="";
        res=find(s,r,hh);
        return res[n];
    }
};*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends