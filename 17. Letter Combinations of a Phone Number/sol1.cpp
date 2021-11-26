#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<string> numToLetters = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    vector<string> letterCombinations(string digits) 
    {
        if (digits.size() == 0) return vector<string>();

        vector<string> result;

        com(digits, 0, "", result);

        return result;
    }

    void com(const string& digits, int digitIndex, string str, vector<string>& out)
    {
        if (digitIndex == digits.size()) 
        {
            out.push_back(str);
            return;
        }

        string& letters = numToLetters[digits[digitIndex] - '0'];

        for (int i = 0; i < letters.size(); i++)
        {
            com(digits, digitIndex + 1, str + letters[i], out);
        }
        
    }
};

int main(void)
{
    Solution sol;

    sol.letterCombinations("2");
}