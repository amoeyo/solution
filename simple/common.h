#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_UNIT 0x7fffffff
#define MIN_UNIT 0x80000000

using namespace std;

template<typename T>
void print(vector<T> nums)
{
	auto it = nums.begin();
	while (it != nums.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

#endif // !__COMMON_H__