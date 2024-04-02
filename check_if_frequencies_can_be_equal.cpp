//{ Driver Code Starts
/*Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

Note: The driver code print 1 if the value returned is true, otherwise 0.
Input:
s = "xyyz"
Output: 
1 
Explanation: 
Removing one 'y' will make frequency of each character to be 1.*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:    
    bool sameFreq(std::string s)
    {
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        std::map<int, int> freqCount;
        for (int f : freq) {
            if (f > 0) {
                freqCount[f]++;
            }
        }

        if (freqCount.size() == 1) {
            return true;
        } else if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            it++;
            int f2 = it->first, c2 = it->second;
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) {
                return true;
            }
            if ((f1 == f2 + 1 && c1 == 1) || (f2 == f1 + 1 && c2 == 1)) {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends