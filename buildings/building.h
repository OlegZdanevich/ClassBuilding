#include<iostream>
#include <string> 
#include "time.h"
class Building
{
public:
	Building(char[], char[], int, int, int);
	Building();

	friend std::istream& operator >> (std::istream&, Building&);
	friend std::ostream& operator<<(std::ostream&, Building);
	char* GetAdress();
	char* GetType();
	int GetStages();
	int GetFlats();
	int GetBuildTime();
	bool GetFlag();
	void SetFlag(bool);
	int GetRemainingTime();
private:
	
	char  adress[256];
	char type[256];
	int stages;
	int flats;
	int BuildTime;
	int RemainingTime;
	bool Flag;
};