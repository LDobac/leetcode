#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

class Solution 
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        if (nums1.size() == 0 && nums2.size() == 0)
        {
            return 0.0;
        }

        int totalLength = nums1.size() + nums2.size();
        int half = totalLength / 2;
        
        std::vector<int>& A = nums1;
        std::vector<int>& B = nums2;

        if (nums1.size() < nums2.size())
        {
            auto tmp = A;
            A = nums2;
            B = tmp;
        }

        if (A.size() == 0)
        {
            int mid = B.size() / 2;
            if ((B.size() % 2) == 0)
            {
                return (B[mid - 1] + B[mid]) / 2.0;
            }
            else
            {
                return (double)B[mid];
            }
        }
        else if (B.size() == 0)
        {
            int mid = A.size() / 2;
            if ((A.size() % 2) == 0)
            {
                return (A[mid - 1] + A[mid]) / 2.0;
            }
            else
            {
                return (double)A[mid];
            }
        }

        int l = 0;
        int r = A.size() - 1;

        do 
        {
            int aLeftMidIndex = (l + r) /2;
            int bLeftMidIndex = half - aLeftMidIndex - 2;

            int aLeft = aLeftMidIndex >= 0 ? A[aLeftMidIndex] : std::numeric_limits<int>::min();
            int aRight = (aLeftMidIndex + 1) < A.size() ? A[(aLeftMidIndex + 1)] : std::numeric_limits<int>::max();
            int bLeft = bLeftMidIndex >= 0 ? B[bLeftMidIndex] : std::numeric_limits<int>::min();
            int bRight = (bLeftMidIndex + 1) < B.size() ? B[(bLeftMidIndex + 1)] : std::numeric_limits<int>::max();

            if (aLeft <= bRight && bLeft <= aRight)
            {
                if ((totalLength % 2) == 0)
                {
                    return (std::max(aLeft, bLeft) + std::min(aRight, bRight)) / 2.0;
                }
                else
                {
                    return (double)std::min(aRight, bRight);
                }
            }
            else if (aLeft > bRight)
            {
                r--;
            }
            else if (bLeft > aRight)
            {
                r++;
            }
        } while(true);
    }
};

int main(void)
{
    Solution sol;

    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};

    double result = sol.findMedianSortedArrays(nums1, nums2);

    std::cout << result << std::endl;

    return 0;
}