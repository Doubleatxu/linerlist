#ifndef CLinearList_
#define CLinearList_
#include<iostream>
using namespace std;
template<class T>
class CLinearList
{
public:
	CLinearList(int MaxListSize = 10); //构造函数
	virtual ~CLinearList();
	bool IsEmpty() const { return length == 0; }
	int Length() const { return length; } //返回当前元素个数
	bool Find(int k, T& x) const; //返回第k个元素保存至x中
	int Search(const T& x) const; // 返回x所在位置
	CLinearList<T>& Insert(int k, const T& x); // 在第k个位置插入x，从零开始算
	CLinearList<T>& Delete(int k, T& x);
	void Output(ostream& out) const;
private:
	int length;
	int MaxSize;
	T *element; // 一维动态数组

};

template<class T>
CLinearList<T>::CLinearList(int MaxListSize)// 基于公式的线性表的构造函数
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}
template<class T>
bool CLinearList<T>::Find(int k, T& x) const
{ //把第k个元素取至x中
  //如果不存在第k个元素则返回false，否则返回true
	if (k<0 || k>length - 1)  // 不存在第k个元素
		return false;
	x = element[k];
	return true;
}

template<class T>
int CLinearList<T>::Search(const T& x) const  // 查找x，如果找到，则返回x所在的位置
{
	// 如果x不在表中，则返回0
	for (int i = 0; i < length; i++)
		if (element[i] == x) return i;
	return 0;
}
template<class T>
CLinearList<T>& CLinearList<T>::Delete(int k, T& x)
{// 把第k个元素放入x中，然后删除第k个元素
	if (Find(k, x))
	{
		for (int i = k; i <length; i++)
			element[i] = element[i + 1];    // 把元素k+l, ...向前移动一个位置
		length--;
		return *this;
	}
}

template<class T>
CLinearList<T>& CLinearList<T>::Insert(int k, const T& x)
{// 在第k个位置插入x

	if (k < 0 || k >MaxSize - 1)
		cout << "位置不对！" << endl;
	else if (length == MaxSize)
		cout << "超出数组最大长度！" << endl;
	else
	{
		if (length != 0)
		{
			for (int i = length - 1; i >= k; i--)
				element[i] = element[i - 1];
		}
		element[k] = x;
		length++;

	}
	return *this;
}

template<class T>
void CLinearList<T>::Output(ostream& out) const   //把表输送至输出流 辅助函数，只要是为了重载<<，也可以用友元函数重载
{
	for (int i = 0; i <length; i++)
		out << element[i] << " ";
}
// 重载<<
template <class T>
ostream& operator<<(ostream& out, const CLinearList<T>& x)
{
	x.Output(out);
	return out;
}
template<class T>
CLinearList<T>::~CLinearList()
{
	delete[] element;
}
#endif 

