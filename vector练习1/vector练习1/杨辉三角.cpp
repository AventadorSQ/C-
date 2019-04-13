#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> 杨辉三角;
		//设置vector有效元素个数
		杨辉三角.resize(numRows);
		//第一步将两边都赋值为1
		for (int i = 0; i < numRows; i++)
		{
			杨辉三角[i].resize(i + 1, 1);
			//杨辉三角[i][0] = 杨辉三角[i][i] = 1;
		}
		//第二部计算里面对应位置的值
		for (int i = 2; i < numRows; i++)
		{
			for (int j = 1; j < i; j++)
			{
				杨辉三角[i][j] = 杨辉三角[i - 1][j - 1] + 杨辉三角[i - 1][j];
			}
		}

		return 杨辉三角;
	}
};

int main()
{
	Solution s;
	s.generate(5);
	return 0;
}