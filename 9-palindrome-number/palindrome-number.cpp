class Solution {
public:
    bool isPalindrome(int x) {
        long revNum=0;
        int dup=x;

        while(dup>0){
            int ld = dup % 10;

            revNum = (revNum * 10) + ld;
            dup=dup/10;
        }
        if(revNum==x) return true;
        else return false;
    }
};