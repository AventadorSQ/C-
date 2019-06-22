#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	static bool Find(int target, vector<vector<int>> array) {
		size_t size = array.size();
		int i = 0;
		int t = (int)size - 1;
		while (i < size && t >= 0)
		{
			if (array[i][t] == target)
			{
				return true;
			}
			else if (array[i][t] > target)
			{
				t--;
			}
			else
			{
				i++;
			}
		}
		return false;
	}
};

int main()
{
	vector <vector<int>> array = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	Solution::Find(1, array);
	return 0;
}