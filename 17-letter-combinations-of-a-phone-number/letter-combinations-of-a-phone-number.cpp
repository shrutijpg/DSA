#include<bits/stdc++.h>
class Solution {
public:
    void help(int i,string& s,string& temp,vector<string>& ans,unordered_map<char,string> &m){
        
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }

        string str = m[s[i]];
        for(int j =0;j<str.size();j++){
            temp.push_back(str[j]);
            help(i+1,s,temp,ans,m);
            temp.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        vector<string> ans;
        string temp;
        help(0,digits,temp,ans,m);
        return ans;

    }
};