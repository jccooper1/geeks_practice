/*Given two integers m and n, try making a special sequence of numbers seq of length n such that

seqi+1 >= 2*seqi 
seqi > 0
seqi <= m
Your task is to determine total number of such special sequences possible.*/
//{ Driver Code Starts
// Initial Template for C++
    int numberSequence(int m, int n){
        // code 
        if(n==0){
            return 1;
        }
        if(m<n){
            return 0;
        }
        return numberSequence(m/2,n-1)+numberSequence(m-1,n);
        
    }
    //another way to solve this problem
int numberSequence(int m, int n){
        
        if(n==0)
        return 0;
        
        if(n==1)
        return m;
        
        int sum=0;
        
        for(int i=1;i<=m;i++){
            
            sum+=numberSequence(i/2,n-1);
        }
        
        return sum;
    }


