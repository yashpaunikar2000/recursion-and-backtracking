class Solution {
public:
void solve(set<vector<int>>&st,vector<int>temp,int idx,vector<int>nums){
        //base case
        if(idx>=nums.size()){
            st.insert(temp);
            return;
        }
        // include
        temp.push_back(nums[idx]);
        solve(st,temp,idx+1,nums);
        // exclude
        temp.pop_back();
        solve(st,temp,idx+1,nums);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int idx=0;
        int n=nums.size();
        vector<int>temp;
        set<vector<int>>st;
        solve(st,temp,idx,nums);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
