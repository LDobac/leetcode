#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int length = strs.size();

        if (length == 0) return "";
        else if (length == 1) return strs[0];

        string& prefix = strs[0];

        for (int i = 1; i < length ; i++)
        {
            if (prefix.size() > strs[i].size())
            {
                prefix = prefix.substr(0, strs[i].size());
            }

            for (int j = 0; j < prefix.size(); j++)
            {
                if (prefix[j] != strs[i][j])
                {
                    prefix = prefix.substr(0, j);
                }
            }

            if (prefix.size() == 0) break;
        }

        return prefix;
    }
};

int main(void)
{
    Solution sol;

    vector<string> strs {
        "flower","flow","flight"
    };

    sol.longestCommonPrefix(strs);
}