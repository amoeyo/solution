#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <map>

#define MAX_UNIT 0x7fffffff
#define INF 0x7fffffff
#define MIN_UNIT 0x80000000

//#define SOLUTION_0
#define SOLUTION_1

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