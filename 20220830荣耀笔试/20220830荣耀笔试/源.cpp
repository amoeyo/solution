#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "math.h"

using namespace std;

//int main()
//{
//	float num;
//
//	cin >> num;
//
//	int pw = 0; //0 = B,1 = KB, 2 = MB, 3 = GB
//
//	while (num >= 1024 && pw < 3)
//	{
//		num = num / 1024;
//		pw++;
//	}
//
//	switch (pw)
//	{
//	case 0:
//		printf("%.2fB", num);
//		break;
//	case 1:
//		printf("%.2fKB", num);
//		break;
//	case 2:
//		printf("%.2fMB", num);
//		break;
//	default:
//		printf("%.2fGB", num);
//		break;
//	}
//	
//	return 0;
//
//
//}


//int distance(int x0, int y0, int x1, int y1)
//{
//	return sqrt((y0 - y1) * (y0 - y1) + (x0 - x1) * (x0 - x1));
//}
//
//vector<int> res;
//
//int calSum(vector<vector<int>>& graph)
//{
//	int sum = 0;
//	for (int i = 0; i < res.size() - 1; i++)
//	{
//		sum += graph[res[i]][res[i + 1]];
//	}
//	sum += graph[0][res[0]] + graph[0][res[res.size() - 1]];
//	return sum;
//}
//
//
//int minD = 100000000;
//
////全排列
//void dfs(vector<vector<int>>& graph, vector<bool>& visit)
//{
//	if (res.size() == graph.size() - 1)
//	{
//		int dis = calSum(graph);
//		if (dis < minD)
//		{
//			minD = dis;
//		}
//		return;
//	}
//
//	for (int i = 1; i < graph.size(); i++)
//	{
//		if (visit[i] == false)
//		{
//			visit[i] = true;
//			res.push_back(i);
//			dfs(graph, visit);
//			res.pop_back();
//			visit[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	vector<vector<int>> pos = {
//		{0, 0},
//		{1, 0},
//		{2, 0},
//		{3, 0},
//		{4, 0},
//		{5, 0}
//	};
//
//	int beeNum = pos.size();
//	vector<vector<int>> graph;
//	graph.resize(pos.size());
//	for (int i = 0; i < beeNum; i++)
//	{
//		graph[i].resize(beeNum);
//	}
//
//	//邻接图
//	for (int i = 0; i < beeNum; i++)
//	{
//		for (int j = i; j < beeNum; j++)
//		{
//			graph[i][j] = distance(pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
//			graph[j][i] = graph[i][j];
//		}
//	}
//
//	vector<bool> visit;
//	visit.assign(beeNum, false);
//	visit[0] = true;
//
//	dfs(graph, visit);
//
//	cout << minD;
//
//}

bool isReplace(string ans, string stu)
{
	int total = ans.size();
	int fit = 0;
	unordered_map<char, int> ans_map;
	for (int i = 0; i < ans.length(); i++)
	{
		ans_map[ans[i]]++;
	}
	for (int i = 0; i < stu.length(); i++)
	{
		if (ans_map[stu[i]])
		{
			ans_map[stu[i]]--;
			fit++;
		}
	}
	if (fit > total / 2) return true;
	return false;
}


int main()
{
	vector<string> answer = { "today", "is", "a", "good", "day" };
	vector<string> stu = { "is", "a", "dog", "day", "too" };

	int totalPoint = answer.size();

	int res = totalPoint;

	vector<bool> visitStu;
	visitStu.assign(stu.size(), false);
	vector<bool> visitAns;
	visitAns.assign(totalPoint, false);




	//先找正确的单词
	for (int i = 0; i < stu.size(); i++)
	{
		//stu[i]
		for(int j = 0; j < totalPoint; j++)
		{
			if (stu[i] == answer[j] && !visitAns[j])
			{
				visitAns[j] = true;
				visitStu[i] = true;
			}
		}
	}

	//对于未查找过的ans和未查找过的stu，判断替换
	for (int i = 0; i < stu.size(); i++)
	{
		if (visitStu[i]) continue;
		//stu[i]
		for (int j = 0; j < totalPoint; j++)
		{
			if (visitAns[j]) continue;
			//对stu[i]和answer[j]进行判断
			if (isReplace(answer[j], stu[i]))
			{
				visitAns[j] = true;
				visitStu[i] = true;
				res--;
			}
		}
	}

	//判断

}
