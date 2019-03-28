#include<vector>
#include<string>
#include<iostream>
using namespace std;


string letterMap[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
class Solution
{
public:
	void _letterCombinations(string& digits, string strRet, vector<string>& vRet, size_t index)
	{
		if (index >= digits.size())
		{
			vRet.push_back(strRet);
			return;
		}
		string& strLetter = letterMap[digits[index] - '0'];
		for (size_t i = 0; i < strLetter.size(); i++)
		{
			_letterCombinations(digits, strRet + strLetter[i], vRet, index+1);
		}
	}
	vector<string> letterCombinations(string digits)//digitsÊý×Ö¼ü
	{
		vector<string> vRet;
		if (digits.empty())
		{
			return vRet;
		}
		string strRet;
		size_t index = 0;
		_letterCombinations(digits, strRet, vRet, index);
		return vRet;
	}
	//friend ostream& operator<<(ostream& _cout,vector<string>& vRet);
};
//ostream& operator<<(ostream& _cout, vector<string>& vRet)
//{
//	for (auto& e:vRet)
//	{
//		_cout << vRet[e] << " ";
//	}
//}
int main()
{
	Solution s;
	vector<string> vRet = s.letterCombinations("23");
	//for (size_t i : vRet.size)
	//{
	//	cout << vRet[i] << " ";
	//}

	system("pause");
	return 0;
}