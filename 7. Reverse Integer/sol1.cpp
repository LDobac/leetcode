#include <cmath>
#include <iostream>
#include <climits>

class Solution 
{
public:
    int reverse(int x) 
    {
        if (x == 0) return x;

        int result = 0;

        while (x != 0)
        {   
            if (result > (INT_MAX / 10)) return 0;
            else if (result < (INT_MIN / 10)) return 0;

            result *= 10;
            result += (x % 10);

            x /= 10;
        }

        return result;
    }
};

int main(void)
{
    Solution sol;

    int x = 1534236469;

    std::cout << sol.reverse(x) << std::endl;

    return 0;
}