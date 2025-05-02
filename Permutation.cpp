class Solution {
public:
void solve(int idx,vector<vector<int>>&ans,vector<int>nums){
    // base case
    if(idx==nums.size()){
        ans.push_back(nums);
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        solve(idx+1,ans,nums);
        swap(nums[i],nums[idx]);//backtrack
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int idx=0;
        int n=nums.size();
        vector<vector<int>>ans;
        solve(idx,ans,nums);
        return ans;
    }
};
