/*Given N numbers in an array, your task is to keep at most the top K numbers with respect to their frequency.
In other words, you have to iterate over the array, and after each index, determine the top K most frequent numbers until that iteration and store them in an array in decreasing order of frequency. 
An array will be formed for each iteration and stored in an array of arrays. If the total number of distinct elements is less than K, then keep all the distinct numbers in the array. 
If two numbers have equal frequency, place the smaller number first in the array.
*/


class Solution {
  public:
  vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
        vector<int> top(K+2);
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < N; i++) {
            vector<int>temp;
            m[arr[i]]++;
            top[K] = arr[i];
            auto it = find(top.begin(), top.end() - 1, arr[i]);//the vector::end() is the next position of the last element,which can't be dereferenced
            for (int j = distance(top.begin(), it) - 1; j >= 0; --j) {
                if (m[top[j]] < m[top[j + 1]])
                    swap(top[j], top[j + 1]);
                else if ((m[top[j]] == m[top[j + 1]]) && (top[j] > top[j+1]))
                    swap(top[j], top[j + 1]);
            }
            for (int b = 0; b < K&&top[b]!=0; ++b)
                temp.push_back(top[b]);
                ans.push_back(temp);
        }
        return ans;
    }
};


