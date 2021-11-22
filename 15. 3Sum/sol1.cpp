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

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j) continue;

                for (int k = 0; k < nums.size(); k++)
                {
                    if (i == k || j == k) continue;

                    if ((nums[i] + nums[j] + nums[k]) == 0)
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
        13,-11,-14,4,-9,-10,-11,7,-14,-9,14,0,-5,-7,6,-9,11,6,-14,-12,-10,9,-8,-7,5,6,8,-12,-1,-4,14,-3,0,7,9,7,12,13,-9,13,11,-10,-10,-9,-10,12,-10,8,-5,13,11,-8,7,-12,0,-11,2,-14,-8,8,-3,13,-9,5,5,7,-11,-6,5,-13,-7,1,14,-10,-1,-11,-13,4,12,-11,2,0,-4,-14,4,4,-10,13,-3,-10,6,1,-12,4,-9,1,-4,-13,10,8,-11,10,-14,-12,-14,1,-8,10,-10,11,-15,0,-3,-12,1,-14,-1,-1,6,11,-4,-3,-2,-1,-13
    };

    auto result = sol.threeSum(nums);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "[ " << result[i][0] << ", "<< result[i][1] << ", " << result[i][2] << " ]" << endl;
    }
}