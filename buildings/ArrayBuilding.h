#include"building.h"

class ArrayBuilding
{
public:
	ArrayBuilding(int = 1);
	int GetSize();
	void resize(int);
	void Copy(ArrayBuilding);
	void DeleteFirst();
	Building TakePart(int);
	void push_back(Building);
	void pop_back();
	void clear();
	void SortStagesGreater();
	void SortStagesLess();
	void SortFlatsGreater();
	void SortFlatsLess();
	void SortBuildTimeGreater();
	void SortBuildTimeLess();
	void SortRemainingTimeGreater();
	void SortRemainingTimeLess();
	void SortAdressGreater();
	void SortAdressLess();
	void SortTypeGreater();//
	void SortTypeLess();//
	void FindFlats(ArrayBuilding &,int);
	void FindStages(ArrayBuilding &, int);
	void FindAdress(ArrayBuilding &, char*);
	void FindType(ArrayBuilding &, char*);
	void FindBuildTime(ArrayBuilding &, int);
	void FindRemainingTime(ArrayBuilding&,int);
	friend std::ostream& operator<<(std::ostream&, ArrayBuilding&);
	friend std::istream& operator>>(std::istream&, ArrayBuilding&);
private:
	void PreparingToSort(int (Building::*)(), bool);
	void PreparingToSortString(char* (Building::*)(), bool);
	int InterpolSearch(int* , int );
	int StringBinarySearch(char**, char*);
	void Search(ArrayBuilding &, int, int(Building::*)());
	void StringSearch(ArrayBuilding &, char*, char*(Building::*)());
	void StringQuickSort(char**, bool  (ArrayBuilding::*)(char*, char*), bool  (ArrayBuilding::*)(char*, char*));
	void StringQuickSort(char**, int, int, bool  (ArrayBuilding::*)(char*, char*), bool  (ArrayBuilding::*)(char*, char*));
	void QuickSort(int*,  bool (ArrayBuilding::*)(int, int), bool (ArrayBuilding::*)(int, int));
	void QuickSort(int*, int, int, bool (ArrayBuilding::*)(int, int), bool (ArrayBuilding::*)(int, int));
	bool StringGreater(char*, char*);
	bool StringLess(char*, char*);
	bool Greater(int, int);
	bool Less(int, int);
	void SortGreater(int*);
	void SortLess(int*);
	void SortGreaterString(char**);
	void SortLessString(char**);
	Building *Array;
	int size;
};

template<class type>void Swap(type & a, type & b);

