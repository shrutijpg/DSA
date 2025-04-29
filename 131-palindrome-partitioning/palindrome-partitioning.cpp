class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path; // individual list of substrings when we do the partitioning of the every recursion
        fun(0,s,res,path);
        return res;
        
    }

    void fun(int index,string s,vector<vector<string>>&res,vector<string>&path){
            //base case
            if(index == s.size()){
                res.push_back(path);
                return;
            }
            for(int i=index;i<s.size();++i){
                if(ispalindrome(s,index,i)){
                    path.push_back(s.substr(index,i-index+1));
                    fun(i+1,s,res,path);
                    path.pop_back();
                }

            }

        }

    bool ispalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;

    }
};