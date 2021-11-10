#include <string>
#include <string_view>
#include <iostream>
#include <vector>

class Solution 
{
public:
    std::string longestPalindrome(std::string s) 
    {
        if (s.size() == 1 || s.size() == 0) return s;

        int longestLen = 0;
        int start = 0;

        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

        // 열 기반으로 탐색
        for (int j = 0 ; j < s.size() ; j++)
        {
            for (int i = 0 ; i <= j ; i++)
            {
                bool same = s[i] == s[j];

                // 문자열 길이가 2이상일때는 dp[i + 1][j - 1]즉, substr이 회문이여야 함
                // 문자열 길이가 2일경우(i, i+1) 두 문자가 같아야 회문
                // 문자열 길이가 1일경우 무조건 회문
                dp[i][j] = j - i > 2 ? (dp[i + 1][j - 1] && same) : same;
                
                if ((longestLen < (j - i + 1)) && dp[i][j])
                {
                    longestLen = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, longestLen);
    }
};

int main(void)
{
    Solution sol;

    std::string str = "babad";

    std::cout << sol.longestPalindrome(str) << std::endl;

    return 0;
}