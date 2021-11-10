#include <string>
#include <iostream>

class Solution 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        int longestLength = 0;

        int length = 0;
        int sliceStart = 0;

        for (int i = 0; i < s.size(); i++)
        {
            std::string substr = s.substr(sliceStart, length);
            int pos = substr.find_first_of(s.at(i));

            if (pos == std::string::npos)
            {
                // Not found
                length++;

                longestLength = (longestLength < length) ? length : longestLength;
            }
            else
            {
                // Found
                length = 1;
                sliceStart = i;
            }
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