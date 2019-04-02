#include<iostream>
using namespace std;


//Ä£ÄâÊµÏÖvector
namespace bit
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{}
		vector(size_t n, const T& data = T())
		{
			_start = new T[n];
			_finish = _start;
			_endOfStorage = _start + n * sizeof(T);
		}
		vector()
	private:
		T* _start;
		T* _finish;
		T* _endOfStorage;
	};
}
int main()
{

	system("pause");
	return 0;
}