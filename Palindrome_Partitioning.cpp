*******************RECURSION TREE*******************

partition("aab") → backtrack(0, [])
    ↳ ispalin(0,0): "a" ✅ → ["a"]
        ↳ ispalin(1,1): "a" ✅ → ["a", "a"]
            ↳ ispalin(2,2): "b" ✅ → ["a", "a", "b"] ✅
        ↳ backtrack to ["a"]
    ↳ ispalin(1,2): "ab" ❌
↳ ispalin(0,1): "aa" ✅ → ["aa"]
    ↳ ispalin(2,2): "b" ✅ → ["aa", "b"] ✅

class Solution {
public:
bool ispalin(string &s, int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void backtrack(string s, int idx, vector<string>curr, vector<vector<string>>&result){
    // base case
    if(idx==s.size()){
        result.push_back(curr);
        return;
    }
    for(int i=idx;i<s.size();i++){
        if(ispalin(s,idx,i)){
            curr.push_back(s.substr(idx,i-idx+1));
            backtrack(s,i+1,curr,result);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>curr;
        backtrack(s,0,curr,result);
        return result;
    }
};
