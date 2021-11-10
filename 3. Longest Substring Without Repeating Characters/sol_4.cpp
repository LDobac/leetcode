#include <string>
#include <string_view>
#include <iostream>

class Solution 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        if (s.size() == 0) return 0;
        else if (s.size() == 1) return 1;

        int longestLength = 0;

        int left = 0;
        int right = 0;
        int length = 0;

        while(right < s.size())
        {
            std::string_view substr(&s[left], length);
            auto pos = substr.find_first_of(s.at(right));

            if (pos != std::string::npos)
            {
                left += (pos + 1);
            }
            
            right++;
            length = right - left;

            longestLength = (longestLength < length) ? length : longestLength;
        }

        return longestLength;
    }
};

int main(void)
{
    Solution sol;

    std::string s = "dvdf";

    std::cout << sol.lengthOfLongestSubstring(s) << std::endl;
}