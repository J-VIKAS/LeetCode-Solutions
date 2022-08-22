class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && (log2(n)/2 == (int)log2(n)/2);
    }
};