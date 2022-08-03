class Solution {
public:
    double myPow(double x, int n) {
        if ( x < 0 )
        {
            x *= -1;
            if ( n%2 == 0 ){
                return pow(10,n*log10(x));
            } else {
                return (-1)*pow(10,n*log10(x));
            }
        } else {
            return pow(10,n*log10(x));
        }
    }
};