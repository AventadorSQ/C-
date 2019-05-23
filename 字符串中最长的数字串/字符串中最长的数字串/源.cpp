#include<iostream>
using namespace std;
#include<string>

void Dispose(string& S1)
{
	char* MaxNumPtr = NULL;
	int MaxNumLength = 0;
	char* NumPtr = NULL;
	int NumLength = 0;
	for (int i = 0; i < S1.size(); i++)
	{
		if (('9' - S1[i] >= 0 && '9' - S1[i] <= 9))
		{
			NumPtr = &S1[i];
			//要对NumLength重新进行归0
			NumLength = 0;
			while (('9' - S1[i] >= 0 && '9' - S1[i] <= 9) && (i < S1.size()))
			{
				NumLength++;
				i++;
			}

			if (NumLength > MaxNumLength)
			{
				MaxNumPtr = NumPtr;
				MaxNumLength = NumLength;
			}
		}
	}
	cout << "MaxNumPtr[i] = ";
	for (int i = 0; i < MaxNumLength; i++)
	{
		cout << MaxNumPtr[i];
	}
	cout << endl;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		Dispose(s);
	}
	return 0;
}