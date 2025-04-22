class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solve(n,n,"",v);
        return v;

    }
    void solve(int open,int close,string op,vector<string>&v){
        if(open == 0 && close ==0){
            v.push_back(op);
            return;
        }
        if(open>0){

            solve(open-1,close,op + '(',v);
        }
        if(close>open){
            
            solve(open,close-1,op + ')',v);
        }

    }
};