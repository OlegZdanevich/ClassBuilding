#include <io.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include"ArrayBuilding.h"
using namespace std;
int N = 256;
void FrontEnd();
void DownloadFromFile(ArrayBuilding&);
void Functional(ArrayBuilding);
void WriteToFile(ArrayBuilding);
void InitNameFile(char* file);
int main()
{
	FrontEnd ();
	return 0;
}



void FrontEnd()
{
	cout.width(30);
	cout << "Welcome to the programm  !!!" << endl;
	cout << "********************************************************************************" << endl;
	system("pause");
	while (true)
	{
		system("cls");
		cout << "How do you want to take date?" << endl;
		cout << "1) Enter information" << endl;
		cout << "2)Download from file" << endl;
		int choice;
		cin >> choice;
		system("cls");
		ArrayBuilding buff(1);
		if (choice == 1) cin >> buff;
		if (choice == 2) DownloadFromFile(buff);
		Functional(buff);
		char s;
		cout << "Would you like to countinie? " << endl;
		cout << "Yes- y or Y " << endl;
		cout << "No- other symbols" << endl;
		cout << "Waiting for Enter: " << endl;
		cin >> s;
		system("cls");
		if (s == 'y' || s == 'Y') continue;
		break;
	}
}



void DownloadFromFile(ArrayBuilding& buff)
{
	char filename[256];
	InitNameFile(filename);
	ifstream streamIn(filename, ios::in | ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		return;
	}
	Building build;
	while (streamIn.read((char*)&build, sizeof(Building)))
	{
		buff.push_back(build);
	}
	streamIn.close();
}

void Functional(ArrayBuilding buff)
{
	system("cls");
	cout << "Do you want to find something or sort?" << endl;
	cout << "1)Sort" << endl;
	cout << "2)Find" << endl;
	int i;
	cin >> i;
	system("cls");
	if (i == 1)
	{
		cout << "1)Sort Stages Greater" << endl;
		cout << "2)Sort Stages Less" << endl;
		cout << "3)Sort Flats Greater" << endl;
		cout << "4)Sort Flats Less" << endl;
		cout << "5)Sort Build Time Greater" << endl;
		cout << "6)Sort Build Time Less" << endl;
		cout << "7)Sort Remaining Time Greater" << endl;
		cout << "8)Sort Remaining Time Less" << endl;
		cout << "9)Sort Adress Greater" << endl;
		cout << "10)Sort Adress Less" << endl;
		cout << "11)Sort Type Greater" << endl;
		cout << "12)Sort Type Less" << endl;
		cin >> i;
		system("cls");
		switch (i)
		{
		case 1:
			buff.SortStagesGreater();
			break;
		case 2:
			buff.SortStagesLess();
			break;
		case 3:
			buff.SortFlatsGreater();
			break;
		case 4:
			buff.SortFlatsLess();
			break;
		case 5:
			buff.SortBuildTimeGreater();
			break;
		case 6:
			buff.SortBuildTimeLess();
			break;
		case 7:
			buff.SortRemainingTimeGreater();
			break;
		case 8:
			buff.SortRemainingTimeLess();
			break;
		case 9:
			buff.SortAdressGreater();
			break;
		case 10:
			buff.SortAdressLess();
			break;
		case 11:
			buff.SortTypeGreater();
			break;
		case 12:
			buff.SortTypeLess();
			break;
		}
		i = 1;
		cout << buff;
		cout << endl;
		WriteToFile(buff);
	}
	if (i == 2)
	{
		cout << "1)Find Flats" << endl;
		cout << "2)Find Stages" << endl;
		cout << "3)Find Adress" << endl;
		cout << "4)Find Type" << endl;
		cout << "5)Find Build Time" << endl;
		cout << "6) Find Remaining Time" << endl;
		cin >> i;
		system("cls");
		int KeyInt;
		char KeyChar[256];
		ArrayBuilding result;
		switch (i)
		{
			
		case 1:
			cout << "By what key Do you want to find?" << endl;
			cin >> KeyInt;
			buff.FindFlats(result, KeyInt);
			break;
		case 2:
			cout << "By what key Do you want to find?" << endl;
			cin >> KeyInt;
			buff.FindStages(result, KeyInt);
			break;
		case 3:
			cout << "By what key Do you want to find?" << endl;
			cin.ignore();
			cin.getline(KeyChar, 256, '\n');
			buff.FindAdress(result, KeyChar);
			break;
		case 4:
			cout << "By what key Do you want to find?" << endl;
			cin.ignore();
			cin.getline(KeyChar, 256, '\n');
			buff.FindType(result, KeyChar);
			break;
		case 5:
			cout << "By what key Do you want to find?" << endl;
			cin >> KeyInt;
			buff.FindBuildTime(result, KeyInt);
			break;
		case 6:
			cout << "By what key Do you want to find?" << endl;
			cin >> KeyInt;
			buff.FindRemainingTime(result, KeyInt);
			break;

		}
		i = 2;
		cout << result;
		cout << endl;
		WriteToFile(result);
	}
}

void WriteToFile(ArrayBuilding buff)
{
	cout << "Do you want to save result?" << endl;
	int i;
	cout << "1)Yes" << endl;
	cout << "2)No" << endl;
	cin >> i;
	system("cls");

	if (i == 1)
	{
		char filename[256];
		InitNameFile(filename);
		ofstream StreamOut(filename, ios::out | ios::binary);
		if (!(StreamOut.is_open()))
		{
			cout << "Cannot open file to write!" << endl;
			system("pause");
			exit(1);
		}
		else
		{
			for (int k = 0; k < buff.GetSize(); k++)
			{
				StreamOut.write((char*)&buff.TakePart(k), sizeof(Building));
			}
		}
		StreamOut.close();
	}
	
}

void InitNameFile(char* file)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(file, 256, '\n');
}

