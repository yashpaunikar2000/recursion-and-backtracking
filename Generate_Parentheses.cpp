✅ Thought Process & Approach..
Each valid sequence must:
Contain exactly n opening '(' brackets and n closing ')' brackets.
Never have more ')' than '(' at any point (to stay balanced).

✅ Why Backtracking is Used?
We explore all possibilities recursively.
When a path doesn’t lead to a valid answer or we’ve finished one path, we backtrack by removing the last added character (pop_back()).
This lets us try the next valid combination.

****RECURSION TREE****
solve("")                  // length 0
 ├── push('(') → "("
 │   ├── push('(') → "(("
 │   │   ├── push('(') → "(((" ❌ too many, rejected
 │   │   └── push(')') → "(()"
 │   │        ├── push('(') → "(()(" ❌ invalid later
 │   │        └── push(')') → "(())" ✅ ✅ added to result
 │   │             → pop → "(()"
 │   │             → pop → "(("
 │   │        → pop → "(("
 │   → pop → "("
 │
 └── push(')') → "()" ✅
     ├── push('(') → "()("
     │   ├── push('(') → "()((" ❌ too many
     │   └── push(')') → "()()" ✅ ✅ added to result
     │        → pop → "()("
     │        → pop → "()"
     └── pop → "()"
 → pop → ""


class Solution {
public:
vector<string>result;
bool isvalid(string curr){
    int cnt=0;
    for(auto it:curr){
        if(it=='('){
            cnt++;
        }else{
            cnt--;
            if(cnt<0)
            return false;
        }
    }
    if(cnt<0){
        return false;
    }
    return cnt==0;
}
void solve(string &curr,int n){
    // base case
    if(curr.size()==2*n){
        if(isvalid(curr)){
            result.push_back(curr);
        }
        return;
    }
    
    curr.push_back('(');
    solve(curr,n);// Trust of recursion
    curr.pop_back();
    
    curr.push_back(')');
    solve(curr,n);// Trust of recursion
    curr.pop_back();
}
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return result;
    }
};
