class Solution {
public:
void solve(vector<int>& candidates,int idx,int target,vector<vector<int>>&ans,vector<int>output){
    //base case
    if(idx==candidates.size()){
        if(target==0){
            ans.push_back(output);
        }
        return ;
    }
        // include
        if(candidates[idx]<=target){
            output.push_back(candidates[idx]);
            solve(candidates,idx,target-candidates[idx],ans,output);
            output.pop_back();
        }
        // exclude;
        solve(candidates,idx+1,target,ans,output);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int idx=0;
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates,idx,target,ans,output);
        return ans;
    }
};
