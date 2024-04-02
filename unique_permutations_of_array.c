/*Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. 
A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi
*/

//this part contains the useage of vector and set
//explain vector::insert()  =>https://cplusplus.com/reference/vector/vector/insert/
class Solution {
  public:
  set<vector<int>>st;
  void perm(vector<int>temp,int l,int h){
      if(l==h){
          st.insert(temp);
      }
      else{
          for(int i=l;i<=h;i++){
              swap(temp[l],temp[i]);
              perm(temp,l+1,h);
          }
      }
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
    perm(arr,0,n-1);
        vector<vector<int>>ans;
       ans.insert(ans.begin(),st.begin(),st.end());
       return ans;
    }
};
