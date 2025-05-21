class Solution {
public:
void solve(int idx,string &temp,vector<string>&ans,string &digits,unordered_map<char, string> &mp){
    // base case
    if(idx>=digits.size()){
        ans.push_back(temp);
        return ;
    }
    char ch=digits[idx];
    string str=mp[ch];
    for(int i=0;i<str.size();i++){
        // Do
        temp.push_back(str[i]);
        // explore
        solve(idx+1,temp,ans,digits,mp);
        // revert back
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        string temp="";
        vector<string>ans;
        int n=digits.size();
        // 1st case:- if there is no digits
        if(n==0){
            return {};
        }
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        // sending my solve function
        solve(0,temp,ans,digits,mp);
        return ans;
    }
};
