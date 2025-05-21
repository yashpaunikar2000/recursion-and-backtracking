// 🔷 1. Problem Statement Understanding
// "Given an array of integers, we need to find the sum of all possible subsets (including the empty subset)."
// This is a powerset problem, but instead of printing all subsets, we’re only interested in their sums.

// 🔷 2. Approach Summary (How you’d explain it)
// "I solved this using recursive backtracking. At every index, I have two choices:
// Pick the current element and add it to the current sum.
// Don't pick the current element and leave the sum as is.
// I recursively explore both options for each index, and once I reach the end of the array, I store the current sum in a result list."

// ************************************************************CODE************************************************************
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
