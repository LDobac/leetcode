#include <string>
#include <map>

class Solution 
{
public:
    int romanToInt(std::string s) 
    {
        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            result += symbols[s[i]];

            if (i - 1 >= 0 && symbols[s[i]] > symbols[s[i - 1]])
            {
                result -= (symbols[s[i - 1]] * 2);
            }
        }
        
        return result;
    }

private:
    std::map<char, int> symbols {
        std::make_pair('I', 1), std::make_pair('V', 5), 
        std::make_pair('X', 10), std::make_pair('L', 50), 
        std::make_pair('C', 100), std::make_pair('D', 500),
        std::make_pair('M', 1000)
    };
};