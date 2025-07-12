class Solution {
public:
    int countKeyChanges(string s) {
        int changes = 0;
    char prevKey = tolower(s[0]);  // First key (in lowercase)

    for (int i = 1; i < s.length(); i++) {
        char currentKey = tolower(s[i]);
        if (currentKey != prevKey) {
            changes++;
            prevKey = currentKey;
        }
    }

    return changes;
    }
};