#ifndef T_DYNAMIC_STACK
#define T_DYNAMIC_STACK


#include <stdexcept>
#include <algorithm>




template<typename T>
class TDynamicStack
{
private:
	T* mArr;
	size_t mSizeArr;
	int mTop;

public:
	// ����������� �� ���������
	TDynamicStack() : mArr{ nullptr }, mSizeArr{ 0 }, mTop{ -1 } {}


	// ����������
	~TDynamicStack() { delete[] mArr; }


	// ��������� ���� �� �������
	bool empty() const noexcept { return mTop == -1; }
	// ���������� ������� ������ �����
	size_t size() const noexcept { return mSizeArr; }


	// ��������� ������� �� ������� �����
	void push(const T& elem)
	{
		T* tempArr = new T[mSizeArr + 1];

		std::copy(mArr, mArr + mSizeArr, tempArr);
		tempArr[mSizeArr++] = elem;
		++mTop;

		std::swap(mArr, tempArr);
		delete[] tempArr;
	}
	// ������� ������� � ������� �����
	T pop()
	{
		if (empty())
			throw std::logic_error{ "stack is empty" };

		T* tempArr = new T[mSizeArr - 1];
		T value = mArr[--mSizeArr];

		std::copy(mArr, mArr + mSizeArr, tempArr);
		--mTop;

		std::swap(mArr, tempArr);
		delete[] tempArr;

		return value;		
	}
	// ��������� �������� �������� �� ������� �����
	T top()
	{
		if (empty())
			throw std::logic_error{ "stack is empty" };

		return mArr[mTop];
	}

};



#endif // T_DYNAMIC_STACK
