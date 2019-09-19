#include<iostream>
using namespace std;
#include<vector>

// 5
// 5 1 4 1 3 1 2 1 1 1
class NodeData
{
public:
	int kuan;
	int gao;
	int mianJi;
	double kuangaobi;
};

double Min(double kuan, double gao)
{
	if ((kuan / gao) > (gao / kuan))
		return gao / kuan;
	return kuan / gao;
}
void Dispose(vector<NodeData>& v, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (v[j].mianJi > v[j+1].mianJi)
			{
				swap(v[j], v[j+1]);
			}
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		if (v[i].mianJi == v[i + 1].mianJi)
		{
			if (v[i].kuangaobi > v[i].kuangaobi)
			{
				swap(v[i], v[i + 1]);
			}
			if (v[i].kuangaobi == v[i + 1].kuangaobi)
			{
				if (v[i].kuan > v[i + 1].kuan)
				{
					swap(v[i], v[i + 1]);
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << v[i].kuan << " " << v[i].gao << " ";
	}

}

int main()
{
	vector<NodeData> v;
	int N;
	while (cin >> N)
	{
		v.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i].kuan;
			cin >> v[i].gao;
			v[i].mianJi = v[i].kuan * v[i].gao;
			v[i].kuangaobi = Min(v[i].kuan, v[i].gao);
		}
		Dispose(v, N);
	}

	return 0;
}




//#include<iostream>
//#include<vector>
//using namespace std;
//
//bool IsHuZhi(int a, int b)
//{
//	if (a == 1 || b == 1)
//		return true;
//	while (1)
//	{
//		int t = a % b;
//		if (t == 0)
//		{
//			break;
//		}
//		else
//		{
//			a = b;
//			b = t;
//		}
//	}
//	if (b > 1)
//		return false;
//	return true;
//}
//
//void Dispose(int count)
//{
//	int NCount = 0;
//	vector<float> v;
//	v.resize(count + 1);
//	v[0] = 1;
//	for (int i = 1; i <= count; i++)
//	{
//		NCount = 0;
//		for (int j = 1; j <= i; j++)
//		{
//			if (IsHuZhi(j, i))
//			{
//				NCount++;
//			}
//			if (j == i)
//			{
//				float temp = (float)NCount / (float)i;
//				if (v[i - 1] < temp)
//				{
//					v[i] = v[i - 1];
//				}
//				else
//				{
//					v[i] = temp;
//				}
//			}
//		}
//	}
//
//	cout << v[count];
//}
//
//int main()
//{
//	int count;
//	cin >> count;
//	Dispose(count);
//	return 0;
//}