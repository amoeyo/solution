#include "SimpleSolution.h"
#include "GraphSolution.h"
#include "DPSolution.h"

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
	//vector<int> favorite = { 2,-1,3,1 };
	////int len = maximumInvitations(favorite);
	//int len = longestCycle(favorite);
	//cout << len << endl;

	//��ϸ����������
	/*vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
	int len = lengthOfLIS(nums);
	cout << len;*/

	//�༭����
	/*string word1 = "horse";
	string word2 = "ros";
	int dis = minDistance(word1, word2);
	cout << dis;*/

	//��С��������
	vector<vector<int>> heights = {
		{1,2,2},
		{3,8,2},
		{5,3,5}
	};

	int minEffort = minimumEffortPath(heights);

	cout << minEffort;

	return 0;
}