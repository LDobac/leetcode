#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.size() < 1) return 0;

        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[count] = nums[i];
                count++;
            }
        }

        return count;
    }
};

int main(void)
{
    Solution s;

    vector<int> v{3,2,2,3};

    int result = s.removeElement(v, 3);

    for (int i = 0; i < result; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "count : " << result << std::endl;
    

    return 0;
}