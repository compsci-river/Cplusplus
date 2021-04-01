//River Sheppard
//Description:

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node
{
	node * next;
	string name;
	int month;
	int day;
	int hours;
	int dateVal;
};

node * newNode()
{
	string mystr;
	string n;
	int m;
	int d;
	double h;
	
	cout << "What is the name of this assignment? ";
	getline (cin,mystr);
	stringstream(mystr) >> n;
	cout << "  Due date information:" << endl;
	cout << "    What month is it due? ";
	getline (cin,mystr);
	stringstream(mystr) >> m;
	cout << "    What day is it due? ";
	getline (cin,mystr);
	stringstream(mystr) >> d;
	cout << "How many hours will it take you to complete? ";
	getline (cin,mystr);
	stringstream(mystr) >> h;
	
	node * nodeA = new node;
	nodeA->name = n;
	nodeA->month = m;
	nodeA->day = d;
	nodeA->hours = h;
	nodeA->dateVal = m * 100 + d;
	
	return nodeA;
}

string dateToStr(int month,int day)
{
	string m;
	if (month >= 10) m = to_string(month);
	else m = " " + to_string(month);
	string d;
	if (day >= 10) d = to_string(day);
	else d = to_string(day) + " ";
	string s = m + "/" + d;
	return s;
}

string hoursToStr(int hours)
{
	string s;
	if (hours == 1) s = to_string(hours) + "  hour ";
	else if (hours < 10) s = to_string(hours) + "  hours";
	else s = to_string(hours) + " hours";
	s = " " + s;
	return s;
}



int main()
{
	bool running = true;
	
	node * first = NULL;
	bool start = true;
	
	while (running)
	{
		if (first == NULL)
		{
			start = true;
		}
		int choice = 0;
		string mystr;
		
		cout << "Enter the number for your choice:" << endl;
		cout << "  1. Enter a new assignment" << endl;
		cout << "  2. Delete an assignment" << endl;
		cout << "  3. Print out a list of assignments" << endl;
		cout << "  4. Quit" << endl;
		getline (cin,mystr);
		stringstream(mystr) >> choice;
		
		if (choice == 1)
		{
			node * nodeA = newNode();
			if (start) 
			{
				first = nodeA;
				start = false;
			}
			else if (first->dateVal >= nodeA->dateVal)
			{
				nodeA->next = first;
				first = nodeA;
			}
			else
			{
				bool check = true;
				
				node * current = first;
				node * pre;
				while (current != NULL)
				{
					if (check and current->dateVal >= nodeA->dateVal)
					{
						nodeA->next = current;
						pre->next = nodeA;
						check = false;
					}
					pre = current;
					current = current->next;
				}
				
				if (check)
				{
					pre->next = nodeA;
				}
			}
		}
		else if (choice == 2)
		{
			string n;
			
			cout << "What is the name of the assignment you would like to delete? ";
			getline (cin,mystr);
			stringstream(mystr) >> n;
			
			bool check = true;
			bool started = false;
			
			node * current = first;
			node * pre;
			while (current != NULL)
			{
				if (check and current->name == n)
				{
					if (started)
					{
						pre->next = current->next;
					}
					else
					{
						first = current->next;
					}
					delete current;
					check = false;
				}
				if(!started) started = true;
				pre = current;
				if (current != NULL) current = current->next;
			}
			cout << "Deleted assignment " << n << "." << endl;
		}
		else if (choice == 3)
		{
			node * current = first;
			while (current != NULL)
			{
				int i;
				string da = dateToStr(current->month,current->day);
				string na = current->name;
				string ho = hoursToStr(current->hours);
				string st = "Due:                                                             ";
				for (i = 0; i < 5; i++)
				{
					st[4+i] = da[i];
				}
				for (i = 0; i < na.length(); i++)
				{
					st[11+i] = na[i];
				}
				for (i = 0; i < 9; i++)
				{
					st[31+i] = ho[i];
				}
				cout << st << endl;
				current = current->next;
			}
		}
		else if (choice == 4)
		{
			running = false;
		}
	}
}














