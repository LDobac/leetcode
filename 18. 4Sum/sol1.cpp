#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k)
    {
        vector<vector<int>> result;

        if (start >= nums.size())
        {
            return result;
        }

        int average = target / k;

        if  (nums[start] > average || average > nums.back()) 
        {
            return result;
        }

        if (k == 2)
        {
            return twoSum(nums, target, start);
        }

        for (int i = start; i < nums.size(); i++)
        {
            if (i != start && nums[i - 1] == nums[i]) continue;

            auto subsets = kSum(nums, target - nums[i], i + 1, k -1);

            for (auto subset : subsets)
            {
                subset.push_back(nums[i]);

                result.push_back(subset);
            }
        }
        
        return result;
    }

    vector<vector<int>> twoSum(vector<int>& nums, int target, int start)
    {
        vector<vector<int>> result;

        int left = start;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];

            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                 result.push_back({nums[left], nums[right]});

                left++;
                while (nums[left] == nums[left - 1] && left < right) left++;
            }
        }

        return result;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums = {2,2,2,2,2};
    sol.fourSum(nums, 8);

    return 0;
}