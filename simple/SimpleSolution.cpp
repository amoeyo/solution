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