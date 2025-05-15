class Solution {
public:
    int firstUniqChar(string s) {
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    
    // Step 2: Find the first unique character
    for (int i = 0; i < s.size(); ++i) {
        if (charCount[s[i]] == 1) {
            return i; // Return the index of the first unique character
        }
    }
    
    // Step 3: If no unique character is found, return -1
    return -1;
        
    }
};