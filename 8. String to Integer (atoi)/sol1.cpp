#include <string>
#include <iostream>
#include <climits>

class Solution 
{
public:
    int myAtoi(std::string s) 
    {
        if (!s.size()) return 0;

        int result = 0;
        bool neg = false;
        bool findSign = false;

        for (int index = 0; index < s.size() ; index++)
        {
            char chr = s[index];

            if ((chr < '0' || chr > '9') && !((result == 0) && (chr == '+' || chr == '-')))
            {
                if (result == 0 && !(chr == '+' || chr == '-' || chr == ' ')) break;
                if (chr == '.') break;

                if (findSign) break;
                else continue;
            }

            if (chr == '+') 
            {
                if (findSign) break;
                neg = false;
                findSign = true;
            }
            else if (chr == '-') 
            {
                if (findSign) break;
                neg = true;
                findSign = true;
            }
            else 
            {
                int num = (neg ? -(chr - '0') : (chr - '0'));
                if (result > INT_MAX/10 || (result == INT_MAX / 10 && num > 7)) return INT_MAX;
                if (result < INT_MIN/10 || (result == INT_MIN / 10 && num < -8)) return INT_MIN;

                findSign = true;
                result *= 10;
                result = result + num;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution sol;

    std::string str = " b11228552307";

    std::cout << sol.myAtoi(str) << std::endl;

    return 0;
}