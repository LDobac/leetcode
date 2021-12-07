#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        generate(n, 0, 0, "", result);

        return result;
    }

    void generate(int n, int open, int close, string s, vector<string>& out)
    {
        if (s.length() == n * 2)
        {
            out.push_back(s);
        }

        if (open < n)
        {
            generate(n, open + 1, close, s + '(', out);
        }

        if (close < open)
        {
            generate(n, open, close + 1, s + ')', out);
        }
    }
};

int main(void)
{
    Solution s;

    for (int i = 0; i < 8; i++)
    {
        auto v = s.generateParenthesis(i);

        cout << i << " : ";
        for (auto s : v)
        {
            cout << s << ", ";
        }
        cout << endl;
    }
}