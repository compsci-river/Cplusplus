//River Sheppard
//Description: Creates a planner for homework. Has nodes which include the name, due date and expected time for the assignment. The planner gives four options,
//add an assignment, delete an assignment, print out the assigment list, and quit the program. The assignments are stored in a linked list.

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//node component of the linked list
struct node
{
	node * next;
	string name;
	int month;
	int day;
	int hours;
	int dateVal;
};

//creates a new assignment node 
node * newNode()
{
	string mystr;
	string n;
	int m = 0;
	int d = 0;
	double h;
	int mVal[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	
	cout << "What is the name of this assignment? ";
	getline (cin,mystr);
	stringstream(mystr) >> n;
	cout << "  Due date information:" << endl;
	//makes sure the entered month is valid
	while (m < 1 or m > 12)
	{
		cout << "    What month is it due? ";
		getline (cin,mystr);
		stringstream(mystr) >> m;
		if (m < 1 or m > 12)
		{
			cout << "    That is not a valid month please try again?" << endl;
		}
	}
	//makes sure the entered day is valid
	while (d < 1 or d > mVal[m-1])
	{
		cout << "    What day is it due? ";
		getline (cin,mystr);
		stringstream(mystr) >> d;
		if (d < 1 or d > mVal[m-1])
		{
			cout << "    That is not a valid day please try again?" << endl;
		}
	}
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

//converts the month and day to a combined string
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

//converts the hours component to a string
string hoursToStr(int hours)
{
	string s;
	if (hours == 1) s = to_string(hours) + "  hour ";
	else if (hours < 10) s = to_string(hours) + "  hours";
	else s = to_string(hours) + " hours";
	s = " " + s;
	return s;
}

//add an assigment
node * addNode(node * first)
{
	node * nodeA = newNode();
	if (first == NULL) 
	{
		first = nodeA;
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
	return first;
}

//delete an assigment
node * delNode(node * first)
{
	string n;
	string mystr;
			
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
	if (check)
	{
		cout << "No assignment of name " << n << " to delete." << endl;
	}
	else
	{
		cout << "Deleted assignment " << n << "." << endl;
	}
	return first;
}

//print assignments
void printOut(node * first)
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

node * quit(node * first)
{
	node * current = first;
	node * hold;
	while (current != NULL)
	{
		hold = current;
		current = current->next;
		delete hold;
	}
	return first;
}

//main function - controls the planner
int main()
{
	bool running = true;
	
	node * first = NULL;
	
	while (running)
	{
		int choice = 0;
		string mystr;
		//gets the main choice of what the planner should do
		cout << "Enter the number for your choice:" << endl;
		cout << "  1. Enter a new assignment" << endl;
		cout << "  2. Delete an assignment" << endl;
		cout << "  3. Print out a list of assignments" << endl;
		cout << "  4. Quit" << endl;
		getline (cin,mystr);
		stringstream(mystr) >> choice;
		
		if (choice == 1)
		{
			first = addNode(first);
		}
		else if (choice == 2)
		{
			first = delNode(first);
		}
		else if (choice == 3)
		{
			printOut(first);
		}
		//quit program
		else if (choice == 4)
		{
			first = quit(first);
			running = false;
		}
	}
}














