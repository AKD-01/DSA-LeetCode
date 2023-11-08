class Solution {
public:
   bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int need = max(abs(sx - fx), abs(sy - fy));
        return need > 0 ? t >= need : t != 1;
    }
};