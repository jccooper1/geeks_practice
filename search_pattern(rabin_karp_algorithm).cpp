//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            vector<int> ans;
            int patternLength = pattern.size();
            int textLength = text.size();

            for (int i = 0; i <= textLength - patternLength; i++) {
                int j;
                for (j = 0; j < patternLength; j++) {
                    if (text[i + j] != pattern[j]) {
                        break;
                    }
                }
                if (j == patternLength) {
                    ans.push_back(i + 1);
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends