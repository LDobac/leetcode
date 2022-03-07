#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1) return 0;

        int prevNum = nums[0];
        int nextInsertIdx = -1;
        int count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prevNum)
            {
                if (nextInsertIdx < 0) nextInsertIdx = i;
            }
            else
            {
                prevNum = nums[i];
                count++;

                if (nextInsertIdx > 0) 
                {
                    nums[nextInsertIdx] = nums[i];
                    nextInsertIdx++;
                }
            }
        }

        return count;
    }
};

int main(void)
{
    Solution s;

    vector<int> v{0,0,1,1,1,2,2,3,3,4};

    int result = s.removeDuplicates(v);

    for (int num : v)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "count : " << result << std::endl;
    

    return 0;
}