/*A gallery with plants is divided into n parts, numbered 0, 1, 2, 3, ..., n-1. 
There are provisions for attaching water sprinklers in every division. 
A sprinkler with range x at division i can water all divisions from i-x to i+x.
Given an array gallery[] consisting of n integers, where gallery[i] is the range of the sprinkler at partition i (a power of -1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the entire gallery. 
If there is no possible way to water the full length using the given sprinklers, print -1.*/

//my idea is below,s but the fault is that my code cant correctly handle the zero case, so it can't return -1
//then the following is my own code about this problem

/*class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        int covered_max=0;
        int covered_min=0;
        int range;
        int num=1;
        for(int i=0;i<n;i++){
            gallery[i]=range;
            if(range==-1){
                continue;
            }
            if(range+i>covered_max&&range-i>covered_min&&covered_max<n-1){
                num+=1;
                covered_max=range+i;
            }
            if(range-i<covered_min&&covered_min>0&&range+i<covered_max){
                num+=1;
                covered_min=range-i;
            }
            if(range+i>=covered_max&&range-i<=covered_min&&covered_max<n-1&&covered_min>0){  //the fault is here
                covered_max=range+i;
                covered_min=range-i;
            }
        }
        if(covered_min>0||covered_max<n-1){
            return -1;
        }
        return num;
        
    }
};
*/


class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
       const int INF = INT_MAX;
        
        // Create an array to represent the coverage of each position
        int coverage[n];
        for (int i = 0; i < n; ++i) {
            coverage[i] = -1;  // Initialize coverage to -1 (not covered)
        }

        // Populate the coverage array based on the sprinkler ranges
        for (int i = 0; i < n; ++i) {
            if (gallery[i] != -1) {
                int left = std::max(0, i - gallery[i]);
                int right = std::min(n - 1, i + gallery[i]);
                for (int j = left; j <= right; ++j) {
                    coverage[j] = std::max(coverage[j], right);
                }
            }
        }

        // Count the number of sprinklers needed
        int count = 0;
        int curr_end = -1;

        for (int i = 0; i < n; ++i) {
            if (coverage[i] == -1) {
                return -1;  // It's not possible to cover the entire gallery
            }

            if (i > curr_end) {
                ++count;
                curr_end = coverage[i];
            }
        }

        return count; // code here
    }
};