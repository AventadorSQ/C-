//2. ����n��������������ִ������ڵ������鳤��һ�������
//����������
//ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n / 2��
//���������
//������ִ������ڵ���n / 2������
//ʾ��1 :
//����
//3 9 3 2 5 6 7 3 2 3 3 3
//���
//3

#include<iostream>
#include<vector>
using namespace std;


//��ӡ����������
void PrintArray(vector<int>& array)
{
	int size = array.size();
	for (int y = 0; y < size; y++)
	{
		cout << array[y] << " ";
	}
	cout << endl;
}

//2.����������
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// { 12,63,156,982,20,478,639,32,2315,123 };
//3.������������
int MaxNum(vector<int>& array)
{
	int size = array.size();
	int temp = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > temp)
		{
			temp = array[i];
		}
	}
	return temp;
}

//4.�������ж���λ����¼��λ��
int MaxWeiShu(int num)
{
	int counts = 0;
	while (1)
	{
		if (num / 10 != 0)
		{
			num = num / 10;
			counts++;
		}
		else
		{
			break;
		}
	}
	return counts + 1;
}

//5.����������һ������
void OneSort(vector<int>& array, int i)
{
	int size = array.size();
	//��¼ÿ��Ͱ�д�ŵĸ���
	int arrk[10] = { 0 };
	//����10��Ͱ
	int arr[10][10000] = { 0 };

	//�����������д�Ž�Ͱ��
	for (int j = 0; j < size; j++)
	{
		//�ж�ÿһ������ͬλ�ϵ���
		int temp = (int)(array[j] / pow(10, i)) % 10;
		//cout << temp << endl;
		//�жϹ���������ĸ�Ͱ�У����Ž�ȥ
		for (int OneNum = 0; OneNum < 10; OneNum++)
		{
			if (temp == OneNum)
			{
				arr[OneNum][arrk[OneNum]] = array[j];
				arrk[OneNum] += 1;
				break;
			}
		}
	}
	int as = 0;
	//��ÿһ�������������·Ż�ԭ����
	for (int OneNum = 0; OneNum < 10; OneNum++)
	{
		//��ÿ��Ͱ�е��������ڷŻ�ԭ����
		for (int x = 0; x < arrk[OneNum]; x++)
		{
			array[as] = arr[OneNum][x];
			as++;
		}
	}

}

//6.��������
void RadixSort(vector<int>& array)
{
	int size = array.size();
	if (size <= 1)
	{
		return;
	}
	//������������
	int Max = MaxNum(array);
	//cout << "vector_size = " << array.size() << endl;
	//cout << "Max = " << Max << endl;
	//�������ж���λ����¼��λ��
	int count = MaxWeiShu(Max);
	//cout << "count = " << count << endl;
	//ȡ��ÿ������ÿ��λ�������С��������
	for (int i = 0; i < count; i++)
	{
		//һ������֮���˳��
		OneSort(array, i);
	}
	//PrintArray(array);
}
void Dispose(vector<int>& V)
{
	//��¼���ֳ��ֵ�������
	size_t MaxCount = 0;
	//��¼������
	int data = 0;
	//cout << "vector_size = " << V.size() << endl;
	RadixSort(V);
	//PrintArray(V);
	//2 2 3 3 3 3 3 3 5 6 7 9
	size_t size = V.size();
	for (size_t i = 0; i < size - 1; i++)
	{
		int dataS = V[i];
		size_t count = 1;
		while (V[i] == V[i + 1])
		{
			count++;
			i++;
		}
		if (count > MaxCount)
		{
			MaxCount = count;
			data = dataS;
		}
	}
	if (MaxCount >= size / 2)
	{
		cout << "���ִ���������vector��Ч���ȵ�һ��������ǣ�";
		cout << data << endl;
	}
	else
	{
		cout << "û�г��ִ���������vector��Ч���ȵ�һ�������" << endl;
	}
}
//3 9 3 2 5 6 7 3 2 3 3 3
int main()
{
	cout << "��Ѱһ���������ظ�������С������һ�볤�ȵ�����" << endl;
	cout << "������N������:";
	vector<int> l;

	int data;
	while (cin >> data)
	{
		l.push_back(data);
		if (cin.get() == '\n')
		{
			;
			break;
		}
		//l.push_back(data);
	}
	int count = l.size();
	cout << "vector_size = " << l.size() << endl;
	vector<int> L(l);

	Dispose(L);
	system("pause");
	return 0;
}