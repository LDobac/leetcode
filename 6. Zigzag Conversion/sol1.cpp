#include <string>
#include <iostream>

class Solution 
{
public:
    std::string convert(std::string s, int numRows) 
    {
        if (numRows <= 1) return s;
        
        bool middle = false;
        int curRow = 0;
        int i = 0;
        std::string result = "";

        while (result.size() != s.size())
        {
            int index = curRow + (i * ((numRows - 1) * 2));

            if (curRow % (numRows - 1) != 0)
            {
                if (middle)
                {
                    index -= (curRow * 2);
                    i--;
                    middle = false;
                }
                else
                {
                    middle = true;
                }
            }

            if (index >= s.size())
            {
                curRow++;
                middle = false;
                i = 0;

                continue;
            }

            result += s[index];

            i++;
        }

        return result;
    }
};

int main(void)
{
    Solution sol;

    std::string str = "PAYPALISHIRING";
    int rows = 4;

    std::cout << sol.convert(str, rows) << std::endl;

    return 0;
}