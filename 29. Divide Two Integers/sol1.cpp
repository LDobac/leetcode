#include <cmath>
#include <climits>

class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long a = labs(dividend);
        long b = labs(divisor);
        long result = 0;
        bool isNeg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        
        while (a >= b) {
            long temp = b;
            long m = 1;
            while (temp << 1 <= b) {
                temp <<= 1;
                m <<= 1;
            }
            a -= temp;
            result += m;
        }
        return isNeg ? -result : result;
    }
};

int main(void)
{
    Solution s;

    s.divide(-2147483648, 1);
}