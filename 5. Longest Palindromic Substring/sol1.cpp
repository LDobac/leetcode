#include <string>
#include <string_view>
#include <iostream>

class Solution 
{
public:
    std::string longestPalindrome(std::string s) 
    {
        if (s.size() == 1 || s.size() == 0) return s;

        int longestLength = 0;
        int start = 0;

        for (int i = 0 ; i < s.size() ; i++)
        {
            for (int j = i ; j < s.size() ; j++)
            {
                auto substr = std::string_view(&s[i], (j - i) + 1);
                if (isPalindrome(substr))
                {
                    if (longestLength < (j - i) + 1)
                    {
                        longestLength = (j - i) + 1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, longestLength);
    }

private:
    bool isPalindrome(const std::string_view& s)
    {
        auto length = s.size();

        for (std::size_t i = 0; i < length; i++)
        {
            if (s[i] != s[length - i - 1]) return false;
        }
        
        return true;
    }
};

int main(void)
{
    Solution sol;

    std::string str = "babad";

    std::cout << sol.longestPalindrome(str) << std::endl;

    return 0;
}