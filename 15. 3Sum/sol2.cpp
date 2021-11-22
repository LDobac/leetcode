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

        int num1, num2, num3;

        for (int i = 0; i < nums.size(); i++)
        {
            num1 = nums[i];

            for (int j = 0; j < nums.size(); j++)
            {
                if (j == i) continue;
                else if (num1 > 0 && nums[j] > 0) continue;
                else if (num1 < 0 && nums[j] < 0) continue; 

                num2 = num1 + nums[j];

                for (int k = 0; k < nums.size(); k++)
                {
                    if (j == k || i == k) continue;
                    else if (num2 > 0 && nums[k] > 0) continue;
                    else if (num2 < 0 && nums[k] < 0) continue; 

                    num3 = num2 + nums[k];

                    if (num3 == 0)
                    {
                        auto v = vector<int>{nums[i], nums[j], nums[k]};
                        sort(v.begin(), v.end()); 

                        bool push = true;

                        for (size_t w = 0; w < result.size(); w++)
                        {
                            if (result[w] == v)
                            {
                                push = false;
                                break;
                            }
                        }

                        if (push)
                        {
                            result.push_back(v);
                        }
                    }
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
        0,-6,0,-14,2,0,-9,5,-9,-8,-7,12,-4,14,-6,6,0,5,-2,6,-7,1,10,-10,-5,3,-2,-3,-13,-6,1,-6,3,9,-5,12,-6,-7,2,0,1,11,-11,4,2,-2,-5,-13,11,0,9,11,-13,-4,-13,-11,14,-8,1,8,1,9,-13,-11,3,-11,9,12,-2,-4,-11,6,14,-7,-5,1,-1,-3,-4,-5,12,12,13,6,-7,-15,10,14,14,-12,8,0,13,2,-3,1,-1,-9,-9,12,-6,-5,-5,-6,4,5,2,10,-13,13,12,6
    };

    auto result = sol.threeSum(nums);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "[ " << result[i][0] << ", "<< result[i][1] << ", " << result[i][2] << " ]" << endl;
    }
}