#include "SimpleSolution.h"
#include "GraphSolution.h"

int main()
{
	/*
	 *	simple solution
	 */
	//vector<int> nums = { 3,2,4 };
	
	

	////����֮��
	//int target = 6;
	//vector<int> res;
	//res = twoSum(nums, target);
	//print<int>(res);

	/*
	 *  graph solution 
	 */
	//��������
	/*vector<vector<int>> graph = {
		{1, 0},
		{2, 0},
		{3, 1},
		{3, 2}
	};
	int numCourses = 4;
	vector<int> course = findOrder(numCourses, graph);
	print<int>(course);*/

	//���λ�����
	vector<int> favorite = { 2,-1,3,1 };
	//int len = maximumInvitations(favorite);
	int len = longestCycle(favorite);
	cout << len << endl;

	return 0;
}