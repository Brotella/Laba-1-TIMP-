#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <string> 

using namespace std;

int main()
{
	char m1[100];
	ifstream file1("text1.txt");
	char m2[100];
	ifstream file2("text2.txt");

	cout << "Differens of first file: ";

	string first, second;
	while (getline(file1, first))
	{
		bool is_different = true;
		file2.seekg(0); 
		while (getline(file2, second))
		{
			if (first == second)
			{
				is_different = false;
				break;
			}
		}
		if (is_different)
			cout << first << endl;
		if (file2.eof())
		{
			file2.close();
			file2.open("text2.txt");
		}
	}

	if (file1.eof())
	{
		file1.close();
		file1.open("text1.txt");
	}
	if (file2.eof())
	{
		file2.close();
		file2.open("text2.txt");
	}

	cout << "Differens of second file: ";

	while (getline(file2, first))
	{
		bool is_different = true;
		file1.seekg(0);
		while (getline(file1, second))
		{
			if (first == second)
			{
				is_different = false;
				break;
			}
		}
		if (is_different)
			cout << first << endl;
		if (file1.eof())
		{
			file1.close();
			file1.open("text1.txt");
		}
	}

	file1.close();
	file2.close();
	system("pause");
	return 0;
}
