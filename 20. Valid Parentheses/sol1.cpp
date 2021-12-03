#include <string>
#include <stack>

using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        if (s.size() % 2 != 0) return false;

        stack<char> openBrackets;

        for (char ch : s)
        {
            if ('(' == ch || '{' == ch || '[' == ch)
            {
                openBrackets.push(ch);
            }
            else if (')' == ch || '}' == ch || ']' == ch)
            {
                if (openBrackets.size() == 0) return false;

                char openBracket = openBrackets.top();

                if (
                    !(
                        ('(' == openBracket && ')' == ch) || 
                        ('{' == openBracket && '}' == ch) || 
                        ('[' == openBracket && ']' == ch)
                    )
                )
                {
                    return false;
                }

                openBrackets.pop();
            }
        }

        return openBrackets.size() == 0;
    }
};

int main(void)
{
    Solution sol;

    sol.isValid("()");

    return 0;
}