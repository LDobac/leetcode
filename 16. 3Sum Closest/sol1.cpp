#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int result;
        int shortestPath = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int path = abs(target - sum);

                if (sum > target) right--;
                else if (sum < target) left++;

                if (path == 0)
                {
                    return sum;
                }
                else if (path < shortestPath)
                {
                    shortestPath = path;
                    result = sum;
                }
            }
        }

        return result;
    }
};