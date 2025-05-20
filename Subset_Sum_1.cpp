class Solution {
  public:
  void solve(int idx,int sum,int N,vector<int>&arr,vector<int>&subsetsum){
    //   base case
    if(idx==N){
        subsetsum.push_back(sum);
        return;
    }
    // picked wala case
    solve(idx+1,sum+arr[idx],N,arr,subsetsum);
    // notpicked wala case
    solve(idx+1,sum,N,arr,subsetsum);
  }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>subsetsum;
        int N=arr.size();
        solve(0,0,N,arr,subsetsum);
        sort(subsetsum.begin(),subsetsum.end());
        return subsetsum;
    }
};


// TC:- 2^n:(for generating all subset sum)+2^nlog(2^n):(for sorting)
// SC:- 2^n(for output)
