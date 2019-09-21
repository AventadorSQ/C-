#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//void DisposeOne(vector<int>& v)
//{
//	int len = v.size();
//	int sum = 0;
//	for (int k = 0; k < len; k++)
//	{
//		sum += v[k];
//	}
//
//	//vector<vector<int>> DisposeTable(len + 1, vector<int>(sum/2 + 1, 0));
//	//for (int i = 1; i <= len; i++)
//	//{
//	//	for (int j = 1; j <= sum / 2; j++)
//	//	{
//	//		if (v[i - 1] > j)
//	//		{
//	//			DisposeTable[i][j] = DisposeTable[i][j - 1];
//	//		}
//	//		else
//	//		{
//	//			int NewData = DisposeTable[i - 1][j - v[i - 1]] + v[i - 1];
//	//			DisposeTable[i][j] = max(NewData, DisposeTable[i - 1][j]);
//	//		}
//	//	}
//	//}
//
//	cout << DisposeTable[len][sum / 2] << " " << sum - DisposeTable[len][sum / 2] << endl;
//}
void DisposeOne(vector<int>& vec)
{
	int len = vec.size();
	int Sum = 0;
	for (int k = 0; k < len; k++)
	{
		Sum = Sum + vec[k];
	}

	int sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += vec[i];
	}

	vector<vector<int>> dp;
	for (int i = 0; i <= len; i++) {
		vector<int>tmp;
		for (int j = 0; j <= sum / 2; ++j) {
			tmp.push_back(0);
		}
		dp.push_back(tmp);
	}

	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= sum / 2; ++j) {
			if (j >= vec[i - 1])dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i - 1]] + vec[i - 1]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	int cha = sum - 2 * dp[len][sum / 2];
	int Num = (Sum - cha) / 2;
	cout << Num << " " << Sum - Num << endl;
}


void Dispose(vector<vector<int>>& v)
{
	int count = v.size();
	for (int i = 0; i < count; i++)
	{
		DisposeOne(v[i]);
	}
}

int main()
{
	vector<vector<int>> v;
	int count;
	cin >> count;
	v.resize(count);
	for (int i = 0; i < count; i++)
	{
		int DataCount;
		cin >> DataCount;
		for (int j = 0; j < DataCount; j++)
		{
			int Data;
			cin >> Data;
			v[i].push_back(Data);
		}
	}

	Dispose(v);
	return 0;
}