#include <iostream>
#include <vector>
#include <string>
#include <tuple>

class Solution
{
public:
    std::vector<int> Answer(std::vector<int>& nums, int target)
    {
        for (int x = 0 ; x < nums.size() ; x++)
        {
            for (int y = x + 1 ; y < nums.size() ; y++)
            {
                int sumResult = nums[x] + nums[y];

                if (target == sumResult)
                {
                    return std::vector<int>{x, y};
                }
            }
        }

        return std::vector<int>();
    }
};


int main(void)
{
    Solution sol;

    std::vector<std::tuple<std::vector<int>, int>> problems {
        std::make_tuple(std::vector<int>{2, 7, 11, 15}, 9),
        std::make_tuple(std::vector<int>{3, 2 ,4}, 6),
        std::make_tuple(std::vector<int>{3, 3}, 6)
    };

    for (auto problem : problems)
    {
        auto answer = sol.Answer(std::get<0>(problem), std::get<1>(problem));

        for (int num : answer)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}