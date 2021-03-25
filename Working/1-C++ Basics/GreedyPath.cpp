//River Sheppard
//C++ Lab

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

void printVars(int x[],int y[],int c)
{
	for (int n = 0; n < c; n++)
	{
		cout << x[n];
		cout << ",";
		cout << y[n] << endl;
	}
}

int strToInt(string s)
{
	int val = 0;
	stringstream num(s);
	num >> val;
	return val;
}

int main(int argc, char *argv[])
{
	string line;
	int numLines = 0;
	ifstream myFile (argv[1]);
	//if (!myFile.is_open()) return;
	
	string word;
	myFile >> word;
	numLines = strToInt(word);
	
	int x [numLines];
	int y [numLines];
	bool visited [numLines];
	
	int minX;
	int minY;
	int maxX;
	int maxY;
	
	int val = 0;
	
	while (myFile >> word)
	{
		int temp = strToInt(word);
		
		if (val%2 == 0)
		{
			if (val == 0)
			{
				minX = temp;
				maxX = temp;
			}
			else if (temp < minX) minX = temp;
			else if (temp > maxX) maxX = temp;
			x[val/2] = temp;
		}
		else
		{
			if (val == 1)
			{
				minY = temp;
				maxY = temp;
			}
			else if (temp < minY) minY = temp;
			else if (temp > maxY) maxY = temp;
			y[(val-1)/2] = temp;
		}
		
		val++;
	}
	cout << minX << "," << minY << endl;
	cout << maxX << "," << maxY << endl;
	cout << "" << endl;
	cout << numLines << endl;
	printVars(x,y,numLines);
}

