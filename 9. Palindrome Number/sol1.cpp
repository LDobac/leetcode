#include <iostream>

class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0) return false;
        else if (x < 10) return true;
        else if ((x % 10) == 0) return false;

        long reverse = 0;
        long tmpX = x;

        while (tmpX)
        {
            reverse = (reverse * 10) + (tmpX % 10);
            tmpX /= 10;
        }

        return reverse == x;
    }
};

int main(void)
{
    Solution sol;
    int x = -121;

    std::cout << std::boolalpha << sol.isPalindrome(x) << std::endl;

    return 0;
}