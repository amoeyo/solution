#include "SimpleSolution.h"

int main()
{
	vector<int> nums = { 3,2,4 };
	int target = 6;
	vector<int> res;

	//两数之和
	res = twoSum(nums, target);
	print<int>(res);

	return 0;
}