//River Sheppard
//C++ Basics Lab
//Description: reads in a file with a list of points and starting at the first point tries
//to find the shortest path through the points by going the closest point that has not been
//visited before it prints the range that the points are in, then the number of points, and
//then the points in the order that the path takes.

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

double getDist(double xOne,double yOne,double xTwo,double yTwo)
{
	double xDist = xTwo - xOne;
	double yDist = yTwo - yOne;
	return sqrt(xDist * xDist + yDist * yDist);
}

int getShortestDistance(int dex,double xList[],double yList[],bool visited[],int leng)
{
	double minDist = -1;
	int index = 0;
	
	double pX = xList[dex];
	double pY = yList[dex];
	
	for(int n = 0; n < leng; n++)
	{
		if (!visited[n])
		{
			double dist = getDist(pX,pY,xList[n],yList[n]);
			if (minDist == -1) 
			{
				minDist = dist;
				index = n;
			}
			else if (minDist > dist) 
			{
				minDist = dist;
				index = n;
			}
		}
	}
	return index;
}

int strToInt(string s)
{
	int val = 0;
	stringstream num(s);
	num >> val;
	return val;
}

double strToDou(string s)
{
	double val = 0;
	stringstream num(s);
	num >> val;
	return val;
}

bool finished(bool visited[],int leng)
{
	for (int n = 0; n < leng; n++)
	{
		if (!visited[n])
		{
			return false;
		}
	}
	return true;
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
	
	double x [numLines];
	double y [numLines];
	bool visited [numLines];
	
	double minX;
	double minY;
	double maxX;
	double maxY;
	
	int val = 0;
	
	while (myFile >> word)
	{
		double temp = strToDou(word);
		
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
			visited[val/2] = false;
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
	
	int index = 0;
	double pathDist = 0;
	visited[index] = true;
	cout << x[index] << " " << y[index] << endl;
	
	bool done = false;
	
	while(!done)
	{
		int dex = getShortestDistance(index, x, y, visited, numLines);
		pathDist += getDist(x[index],y[index],x[dex],y[dex]);
		index = dex;
		visited[index] = true;
		cout << x[index] << " " << y[index] << endl;
		done = finished(visited,numLines);
	}
	cout << "" << endl;
	cout << pathDist << endl;
}

