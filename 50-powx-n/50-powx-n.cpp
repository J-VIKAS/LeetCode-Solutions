class Solution {
public:
    double myPow(double x, int n) {
        if ( x < 0 ){
            return pow(-1,n)*pow(10,n*log10((x*-1)));
        } else {
            return pow(10,n*log10(x));
        }
    }
};