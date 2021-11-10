#include <iostream>
#include <string>
#include <vector>

class Solution 
{
public:
    bool isMatch(std::string s, std::string p) 
    {
        std::vector<std::vector<char>> tmp(s.size() + 1, std::vector<char>(p.size() + 1, -1));
        dp.swap(tmp);

        return isMatch(0, 0, s, p);
    }

private:
    std::vector<std::vector<char>> dp;

    bool isMatch(int i, int j, const std::string& s ,const std::string& p)
    {
        if (dp[i][j] != -1) return dp[i][j];

        char match = -1;

        // If no more patterns
        if (j == p.length())
        {
            // True when no more string, If string does not empty, False
            match = (i == s.length());
        }
        else 
        {
            bool firstMatch = (i < s.length()) && (p[j] == s[i] || p[j] == '.');

            // if Kleene star, character matches zero or more
            if (j + 1 < p.length() && p[j + 1] == '*')
            {
                        // If zero match, skip Kleene star
                match = isMatch(i, j + 2, s, p) || 
                        // If non-zero matches, keep finding more matches character
                        (firstMatch && isMatch(i + 1, j, s, p));
            }
            else
            {
                // Finding next matches character
                match = firstMatch && isMatch(i + 1, j + 1, s, p);
            }
        }

        dp[i][j] = match;

        return match;
    }
};

int main(void)
{
    Solution sol;

    std::string str = "abc";
    std::string pattern = "a*";

    std::cout << std::boolalpha << sol.isMatch(str, pattern) << std::endl; 

    return 0;
}