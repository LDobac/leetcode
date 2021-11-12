#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int maxArea(std::vector<int>& height) 
    {
        if (height.size() == 2)
        {
            return  std::min(height[0], height[1]);
        }

        int count = height.size();

        int maxArea = 0;

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i; j < count; j++)
            {
                int barHeight = std::min(height[i], height[j]);
                int barWidth = j - i;

                int area = barWidth * barHeight;

                if (area > maxArea)
                {
                    maxArea = area;
                }
            }
        }
        
        return maxArea;
    }
};