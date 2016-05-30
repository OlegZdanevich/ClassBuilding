#include"ArrayBuilding.h"

ArrayBuilding::ArrayBuilding(int size)
{
	try
	{
		this->size = size;
		if (size <= 0) throw 1;
	}
	catch (int i)
	{
		std::cout << "Error " << i << " member must be positive" << std::endl;
		this-> size= 1;
	}
	this->Array = new Building[256];

}


int ArrayBuilding::GetSize()
{

	return size;
}

void ArrayBuilding::resize(int n)
{ 
	int prev = size;
	try 
	{
		size += n;
		if (size <= 0) throw 1;
	}
	catch (int i)
	{
		std::cout << "Error " << i << " member must be positive" << std::endl;
		size = i;

	}
}

void ArrayBuilding::Copy(ArrayBuilding v2)
{
	size = v2.size;
	for (int i = 0; i < v2.size; i++)
	{
		Array[i] = v2.Array[i];
	}
}

void ArrayBuilding::DeleteFirst()
{
	for (int i =1; i < size; i++)
	{
		Array[i - 1] = Array[i];
	}
	size--;
}


Building ArrayBuilding::TakePart(int i)
{
	if (i < size)
	{
		return Array[i];
	}
	else
	{
		std::cout << "Error" << std::endl;
		system("pause");
		system("cls");
		return Array[0];
	}
}



void ArrayBuilding::push_back(Building v)
{

	int i = 0;
	while (Array[i].GetFlag() == true)
	{
		i++;
	}   
	v.SetFlag(true);
	Array[i] = v;
	size = i + 1;
		
}

void ArrayBuilding::pop_back()
{
	Array[size - 1] = Building();
	size--;
}

void ArrayBuilding::clear()
{
	for (int i = 0; i < size; i++)
	{
		Array[i] = Building();
	}
	size = 1;
}

void ArrayBuilding::SortStagesGreater()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetStages;
	PreparingToSort(pt, true);
}

void ArrayBuilding::SortStagesLess()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetStages;
	PreparingToSort(pt, false);
}

void ArrayBuilding::SortFlatsGreater()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetFlats;
	PreparingToSort(pt, true);
}

void ArrayBuilding::SortFlatsLess()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetFlats;
	PreparingToSort(pt, false);
}

void ArrayBuilding::SortBuildTimeGreater()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetBuildTime;
	PreparingToSort(pt, true);
}

void ArrayBuilding::SortBuildTimeLess()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetBuildTime;
	PreparingToSort(pt, false);
}

void ArrayBuilding::SortRemainingTimeGreater()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetRemainingTime;
	PreparingToSort(pt, true);
}

void ArrayBuilding::SortRemainingTimeLess()
{
	typedef int (Building::* pToFunc)();
	pToFunc pt = &Building::GetRemainingTime;
	PreparingToSort(pt, false);
}

void ArrayBuilding::SortAdressGreater()
{
	typedef char* (Building::* pToFunc)();
	pToFunc pt = &Building::GetAdress;
	PreparingToSortString(pt, true);
}

void ArrayBuilding::SortAdressLess()
{
	typedef char*(Building::* pToFunc)();
	pToFunc pt = &Building::GetAdress;
	PreparingToSortString(pt, false);
}

void ArrayBuilding::SortTypeGreater()
{
	typedef char*(Building::* pToFunc)();
	pToFunc pt = &Building::GetType;
	PreparingToSortString(pt, true);
}

void ArrayBuilding::SortTypeLess()
{
	typedef char*(Building::* pToFunc)();
	pToFunc pt = &Building::GetType;
	PreparingToSortString(pt, false);
}

void ArrayBuilding::FindFlats(ArrayBuilding &v,int n)
{
	typedef int(Building::* pToFunc)();
	pToFunc pt = &Building::GetFlats;
	Search(v,n,pt);
}

void ArrayBuilding::FindStages(ArrayBuilding &v, int n)
{
	typedef int(Building::* pToFunc)();
	pToFunc pt = &Building::GetStages;
	Search(v, n, pt);
}

void ArrayBuilding::FindAdress(ArrayBuilding &v, char*num)
{

	typedef char*(Building::* pToFunc)();
	pToFunc pt = &Building::GetAdress;
	StringSearch(v, num, pt);
}

void ArrayBuilding::FindType(ArrayBuilding &v, char *num)
{
	typedef char*(Building::* pToFunc)();
	pToFunc pt = &Building::GetType;
	StringSearch(v, num, pt);
}

void ArrayBuilding::FindBuildTime(ArrayBuilding &v, int n)
{
	typedef int(Building::* pToFunc)();
	pToFunc pt = &Building::GetBuildTime;
	Search(v, n, pt);
}

void ArrayBuilding::FindRemainingTime(ArrayBuilding &v, int n)
{
	typedef int(Building::* pToFunc)();
	pToFunc pt = &Building::GetRemainingTime;
	Search(v, n, pt);
}

std::ostream& operator<<(std::ostream& out, ArrayBuilding& v)
{
	for (int i = 0; i < v.size; i++)
	{
		out << v.Array[i] << std::endl;;
	}
	return out;
}

std::istream& operator>>(std::istream& in, ArrayBuilding& v)
{
	v.clear();
	int i = 0;
	while (true)
	{
		std::cout << "Element of array (" <<  i + 1<<")"<<  std::endl;
		std::cin >> v.Array[i];
		system("pause");
		system("cls");
		std::cout << " Would you like to continue?" << std::endl;
		std::cout << " 1)Yes" << std::endl;
		std::cout << " Other Numbers)No" << std::endl;
		int r = 0;
		std::cin >> r;
		if (r != 1) break;
		v.resize(1);
		i++;
		system("cls");
	}
	return in;
}

template<class type>void Swap(type & a, type & b)
{
	type temp = a;
	a = b;
	b = temp;
}


void ArrayBuilding::QuickSort(int *a, bool (ArrayBuilding::*function1)(int, int), bool (ArrayBuilding::*function2)(int, int))
{
	QuickSort(a, 0, size - 1,function1, function2);
}

void ArrayBuilding::QuickSort(int *a, int left, int right, bool (ArrayBuilding::*function1)(int, int), bool (ArrayBuilding::*function2)(int, int))
{
	int i = left, j = right;
	int middle = a[(left + right) / 2];
	ArrayBuilding v(size);
	for (int i = 0; i < v.size; i++)
	{
		v.Array[i] = Array[i];
	}
	while (i <= j)
	{
		while ((v.*function2)(a[i],middle))
			i++;
		while ((v.*function1)(a[j], middle))
			j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			Swap(Array[i], Array[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j,function1,function2);
	if (i < right)
		QuickSort(a, i, right, function1, function2);
}




bool ArrayBuilding::StringGreater(char * a, char *b)
{
	if (strcmp(a, b)>0)return true;
	return false;
}

bool ArrayBuilding::StringLess(char *a, char *b)
{
	if (strcmp(a, b)<0)return true;
	return false;
}

bool ArrayBuilding::Greater(int a, int b)
{
	if (a > b) return true;
	return false;
}

bool ArrayBuilding::Less(int a, int b)
{
	if (a < b) return true;
	return false;
}

void ArrayBuilding::SortGreater(int * a)
{
	typedef bool (ArrayBuilding::* function)(int, int);
	function f = &ArrayBuilding::Greater;
	function s = &ArrayBuilding::Less;
	QuickSort(a, f, s);
}

void ArrayBuilding::SortLess(int * a)
{
	typedef bool (ArrayBuilding::* function)(int, int);
	function f = &ArrayBuilding::Less;
	function s = &ArrayBuilding::Greater;
	QuickSort(a, f, s);
}

void ArrayBuilding::SortGreaterString(char **a)
{
	typedef bool (ArrayBuilding::* function)(char*, char*);
	function f = &ArrayBuilding::StringGreater;
	function s = &ArrayBuilding::StringLess;
	StringQuickSort(a, f, s);
}

void ArrayBuilding::SortLessString(char **a)
{
	typedef bool (ArrayBuilding::* function)(char*, char*);
	function f = &ArrayBuilding::StringLess;
	function s = &ArrayBuilding::StringGreater;
	StringQuickSort(a, f, s);

}

void ArrayBuilding::PreparingToSort(int (Building::*function)(), bool flag)
{
	int *a = new int[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = (Array[i].*function)();
	}
	if(flag==true) SortGreater(a);
	else SortLess(a);
	delete[] a;
}

void ArrayBuilding::StringQuickSort(char **a, bool(ArrayBuilding::*function1)(char*, char*), bool(ArrayBuilding::*function2)(char*, char*))
{
	StringQuickSort(a, 0, size - 1, function1, function2);
}

void ArrayBuilding::StringQuickSort(char **a, int left, int right, bool (ArrayBuilding::*function1)(char*,char*), bool (ArrayBuilding::*function2)(char*, char*))
{
	int i = left, j = right;
	char* middle = a[(left + right) / 2];
	ArrayBuilding v(size);
	for (int i = 0; i < v.size; i++)
	{
		v.Array[i] = Array[i];
	}
	while (i <= j)
	{
		while ((v.*function2)(a[i],middle))
			i++;
		while ((v.*function1)(a[i], middle))
			j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			Swap(Array[i], Array[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		StringQuickSort(a, left, j,function1,function2);
	if (i < right)
		StringQuickSort(a, i, right,function1, function2);
}



int ArrayBuilding::StringBinarySearch(char**a, char* num)
{
	int right = size - 1;
	int left = 0;
	while (right - left > 1)
		
	{
		int mid = (left + right) / 2;
		
		if (strcmp(a[mid],num)==-1)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	for (int i = left; i <= right; i++)
		if (strcmp(a[i],num)==0)
			return i;
	return -1;

}

void ArrayBuilding::Search(ArrayBuilding &v, int n, int(Building::*function)())
{
	v.clear();
	int *a = new int[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = (Array[i].*function)();
	}
	SortGreater(a);
	int buff = InterpolSearch(a, n);
	int i = buff;
	v.size = 0;
	if (i >= 0)
	{

		while ((Array[i].*function)() == n)
		{
			v.size++;
			v.Array[v.size - 1] = Array[i];
			i--;
			if (i < 0) break;
		}
	}
	else
	{
		v.size++;
		v.Array[0] = Building("Nothing", "Nothing", 1, 1, 1990);
	}
	delete[]a;
}

void ArrayBuilding::StringSearch(ArrayBuilding &v, char *num, char*(Building::*function)())
{
	char **a = new char*[size];
	for (int i = 0; i < size; i++)
	{
		std::string buff = (Array[i].*function)();
		int k = buff.length();
		a[i] = new char[k];
		strcpy(a[i], buff.c_str());
	}
	SortGreaterString(a);
	int buff = StringBinarySearch(a, num);
	int i = buff;
	v.size = 0;
	if (i >= 0)
	{
		while (strcmp((Array[i].*function)(), num) == 0 && i<size)
		{
			v.size++;
			v.Array[v.size - 1] = Array[i];
			i++;
			if (i < 0) break;
		}
	}
	else
	{
		v.size++;
		v.Array[0] = Building("Nothing", "Nothing", 1, 1, 1990);
	}
	a = NULL;
	for (int i = 0; i < size; i++) delete[i] a;
	delete[] a;
}



void ArrayBuilding::PreparingToSortString(char* (Building::*function1)(), bool flag)
{
	char **a = new char*[size];
	for (int i = 0; i < size; i++)
	{
		std::string buff = (Array[i].*function1)();
		int k = buff.length();
		a[i] = new char[k];
		strcpy(a[i], buff.c_str());
	}
	if (flag == true) SortGreaterString(a);
	else SortLessString(a);
	a = NULL;
	for (int i = 0; i < size; i++) delete[i] a;
	delete[] a;
}

int ArrayBuilding::InterpolSearch(int* a, int num)
{
	if (size != 1)
	{
		int mid, left = 0, right = size - 1;
		while (a[left] <= num && a[right] >= num)
		{
			mid = left + ((num - a[left])*(right - left)) / (a[right] - a[left]);
			if (a[mid]<num) left = mid + 1;
			else if (a[mid]>num) right = mid - 1;
			else
			{
				return mid;
			}
		}
		if (a[left] == num) return left;
		else return -1;
	}
	else if (a[0] == num) return 0;
		else
		{
			return -1;
		}
}


