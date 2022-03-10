#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        int n = 0;

        if (!needle.size()) return 0;
        if (!haystack.size()) return -1;

        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[n])
            {
                if ((n + 1) == needle.size()) return i - n;
                
                n++;
            }
            else
            {
                i -= n;
                n = 0;
            }
        }

        return -1;
    }
};

int main(void)
{
    Solution s;

    // int result = s.strStr("hello", "ll");
    // int result = s.strStr("aaaaa", "ba");
    // int result = s.strStr("", "");
    int result = s.strStr("mississippi", "issip");

    cout << result << endl;

    return 0;
}