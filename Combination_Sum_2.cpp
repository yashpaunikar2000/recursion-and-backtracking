class Solution {
public:
void solve(vector<int>& candidates,int idx,int target,vector<vector<int>>&ans,vector<int>output){
    //base case
    if(target<0){
        return ;
    }
        if(target==0){
            ans.push_back(output);
            return;
        }
        // include
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            output.push_back(candidates[i]);
            solve(candidates,i+1,target-candidates[i],ans,output);
            output.pop_back();
        }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int idx=0;
        vector<vector<int>>ans;
        vector<int>output;
        sort(candidates.begin(),candidates.end());
        solve(candidates,idx,target,ans,output);
        return ans;
    }
};
