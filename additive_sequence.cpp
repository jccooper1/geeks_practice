//{ Driver Code Starts
/*Given a string n, your task is to find whether it contains an additive sequence or not. A string n contains an additive sequence if its digits can make a sequence of numbers in which every number is addition of previous two numbers. You are required to complete the function which returns true if the string is a valid sequence else returns false. For better understanding check the examples.

Note: A valid string should contain at least three digit to make one additive sequence. 
Input:  
n = "1235813"
Output: 
1
Explanation: 
The given string can be splited into a series of numbers  
where each number is the sum of the previous two numbers: 
1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8, and 5 + 8 = 13. Hence, the output would be 1 (true).*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int check_digit(int n){
        int digit=0;
        int tens=0;
        while(n>10){
            digit++;
            tens=pow(10,digit)
            n=n%tens
        }
        return  digit;
    }
    
    bool isAdditiveSequence(string n) {
        // Your code here
        if(n<3) return  false;
        for(auto s:n){
            int first=s;
            int second=s+1;
            if(check_digit(first+second)>=1){
                int third=s+1+check_digit;
            }
        }
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends