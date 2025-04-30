class Solution {
public:
void solve(vector<int>& nums,vector<int>output,vector<vector<int>>&ans,int idx){
    // base case
    if(idx>=nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums,output,ans,idx+1);
    // include
    int elem=nums[idx];
    output.push_back(elem);
    solve(nums,output,ans,idx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int n=nums.size();
        int idx=0;
        solve(nums,output,ans,idx);
        return ans;
    }
};
