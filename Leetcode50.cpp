class Solution {
public:
   double myPow(double x, int n) {
        if (n==0) return 1;
        if (n%2) {
            return n > 0 ? x*myPow(x*x,n/2) : myPow(1/x/x,n/2);
        } else {
            double t = (n > 0 ?myPow(x*x, n / 2): myPow(1/x/x,n/2));
            return t*t;
        }
};