#include "SimpleSolution.h"

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> nums_map;
    vector<int> res;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (nums_map.count(nums[i])) {
            res.push_back(i);
            res.push_back(nums_map[nums[i]]);
            break;
        }
        else {
            nums_map[target - nums[i]] = i;
        }
    }
    return res;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> res;

    int rowNum = matrix.size();
    int colNum = matrix[0].size();


    int up_edge = 0;
    int down_edge = rowNum - 1;
    int right_edge = colNum - 1;
    int left_edge = 0;
    while (left_edge <= right_edge && up_edge <= down_edge)
    {
        for (int col = left_edge; col <= right_edge; col++)
        {
            res.push_back(matrix[up_edge][col]);
        }


        for (int row = up_edge + 1; row <= down_edge; row++)
        {
            res.push_back(matrix[row][right_edge]);
        }

        if (up_edge < down_edge && left_edge < right_edge)
        {
            for (int i = right_edge - 1; i >= left_edge; i--)
            {
                res.push_back(matrix[down_edge][i]);
            }

            for (int i = down_edge - 1; i > up_edge; i--)
            {
                res.push_back(matrix[i][left_edge]);
            };
        }
        
        right_edge--;
        down_edge--;
        left_edge++;
        up_edge++;
    }
    return res;
}