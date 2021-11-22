#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0) right--;
                else if (sum < 0) left++;
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    left++;
                    while (nums[left] == nums[left - 1] && left < right) left++;
                }
            }
        }

        return result;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums {
        0, 0, 0, 0
    };

    auto result = sol.threeSum(nums);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "[ " << result[i][0] << ", "<< result[i][1] << ", " << result[i][2] << " ]" << endl;
    }
}