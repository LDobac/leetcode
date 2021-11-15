#include <string>

class Solution 
{
public:
    std::string intToRoman(int num) 
    {
        std::string result = "";

        int multiple = 0;
        while (num > 0)
        {
            int digit = num % 10;

            std::string one = "I";
            std::string four = "IV";
            std::string five = "V";
            std::string nine = "IX";

            if (multiple == 1)
            {
                one = "X";
                four = "XL";
                five = "L";
                nine = "XC";
            }
            else if (multiple == 2)
            {
                one = "C";
                four = "CD";
                five = "D";
                nine = "CM";
            }
            else if (multiple == 3)
            {   
                one = "M";
            }

            if (digit == 4) result.insert(0, four);
            else if (digit == 9) result.insert(0, nine);
            else
            {
                std::string tmp = "";

                if (digit >= 5)
                {
                    tmp += five;
                    digit -= 5;
                }

                for (int i = 0; i < digit; i++)
                {
                    tmp += one;
                }
                
                result.insert(0, tmp);
            }

            multiple++;
            num /= 10;
        }

        return result;
    }
};

int main(void)
{
    Solution sol;

    int num = 58;

    sol.intToRoman(num);

    return 0;
}