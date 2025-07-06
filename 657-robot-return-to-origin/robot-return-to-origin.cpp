class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        int h = 0, v = 0;
        for (char move : moves) {
            if (move == 'R') h++;
            else if (move == 'L') h--;
            else if (move == 'U') v++;
            else if (move == 'D') v--;
        }
        return h == 0 && v == 0;
    }
};