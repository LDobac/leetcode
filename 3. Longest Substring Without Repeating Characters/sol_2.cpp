#include <string>
#include <iostream>

class Solution 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        int longestLength = 0;

        for (int i = 0 ; i < s.size() ; i++)
        {
            int length = 0;
            int sliceStart = i;

            for (int j = i ; j < s.size() ; j++)
            {
                std::string substr = s.substr(sliceStart, length);
                int pos = substr.find_first_of(s.at(j));

                if (pos == std::string::npos)
                {
                    // Not found
                    length++;

                    longestLength = (longestLength < length) ? length : longestLength;
                }
                else
                {
                    break;
                }
            }

            if (s.size() - i < longestLength) break;
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