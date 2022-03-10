#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        if (!needle.size()) return 0;
        if (!haystack.size()) return -1;

        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                if (i + needle.size() > haystack.size()) break;

                int left = 1;
                int right = needle.size() - 1;

                while(left <= right)
                {
                    if ((haystack[i + left] == needle[left]) && (haystack[i + right] == needle[right]))
                    {
                        left++;
                        right--;
                    }
                    else
                    {
                        break;
                    }
                }

                if (left > right) return i;
            }
        }

        return -1;
    }
};

int main(void)
{
    Solution s;

    int result = s.strStr("hello", "ll");
    // int result = s.strStr("aaaaa", "ba");
    // int result = s.strStr("", "");
    // int result = s.strStr("mississippi", "issip");
    // int result = s.strStr("mississippi", "pi");

    cout << result << endl;

    return 0;
}