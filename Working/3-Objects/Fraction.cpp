//River Sheppard
//Description: A class for fractions that allows for easier calculations with fractions.

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
	public:
		//Constructors with numerator and denominator inputs
		Fraction (int n,int d)
		{
			numerator = n;
			denominator = d;
		}
		//default constructor
		Fraction ()
		{
			numerator = 1;
			denominator = 1;
		}
		//getter for the numerator
		int numer ()
		{
			//cout << "getting numer: " << numerator << endl;
			return numerator;
		}
		//getter for the denominator
		int denom ()
		{
			//cout << "getting denom: " << denominator << endl;
			return denominator;
		}
		//recursive function to get the greatest common denominator used in reduce function
		int gcd (int a, int b)
		{
			if (b == 0)
			{
				return a;
			}
			else
			{
				return gcd(b,a%b);
			}
		}
		//reduces a fraction to its simplified form
		Fraction reduce ()
		{
			int n = numerator;
			int d = denominator;
			int common = gcd(n,d);
			while (common > 1)
			{
				n = n / common;
				d = d / common;
				common = gcd(n,d);
			}
			return Fraction(n,d);
		}
		//overwrites the equals function 
		Fraction operator= (Fraction f)
		{
			int n = f.numer();
			int d = f.denom();
			Fraction a (n,d);
			return a;
		}
		//overwrites the equivalency function
		bool operator== (Fraction f)
		{
			Fraction a = Fraction(numerator,denominator).reduce();
			Fraction b = Fraction(f.numer(),f.denom()).reduce();
			if (a.numer() == b.numer() and a.denom() == b.denom())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//prints out the formatted function
		void print ()
		{
			cout << numerator << "/" << denominator;
		}
		//returns a fraction that equals the reciprocal of the currenct fraction
		Fraction reciprocal ()
		{
			return Fraction(denominator,numerator);
		}
		//overwrites the addition function: returns a fraction that equals the sum of the current fraction and the input fraction
		Fraction operator+ (Fraction f)
		{
			int n = numerator * f.denom() + f.numer() * denominator;
			int d = denominator * f.denom();
			return Fraction(n,d).reduce();
		}
		//overwrites the subtraction function: returns a fraction that equals the difference between the current fraction and the input fraction
		Fraction operator- (Fraction f)
		{
			int n = numerator * f.denom() - f.numer() * denominator;
			int d = denominator * f.denom();
			return Fraction(n,d).reduce();
		}
		//overwrites the multiplication function: returns a fraction that equals the product of the current fraction and the input fraction
		Fraction operator* (Fraction f)
		{
			int n = numerator * f.numer();
			int d = denominator * f.denom();
			return Fraction(n,d).reduce();
		}
		//overwrites the division function: returns a fraction that equals the quotient of the current fraction and the input fraction
		Fraction operator/ (Fraction f)
		{
			int n = numerator * f.denom();
			int d = denominator * f.numer();
			return Fraction(n,d).reduce();
		}
};
// allows for user input of a fraction
Fraction getFraction ()
{
	int n = 1;
	int d = 1;
	string mystr;
	cout << "  The numerator of the fraction is: ";
	getline (cin,mystr);
	stringstream(mystr) >> n;
	cout << "  The denominator of the fraction is: ";
	getline (cin,mystr);
	stringstream(mystr) >> d;
	return Fraction(n,d);
}
//creates a fraction calculator in the command line
int main ()
{
	bool running = true;
	
	while (running)
	{
		//same structure from the planner reformatted for a calculator
		int choice = 0;
		string mystr;
		cout << "Fraction Calculator:" << endl;
		cout << "  1. Reduce" << endl;
		cout << "  2. Reciprocal" << endl;
		cout << "  3. Add" << endl;
		cout << "  4. Subtract" << endl;
		cout << "  5. Multiply" << endl;
		cout << "  6. Divide" << endl;
		cout << "  7. Check for equivalency" << endl;
		cout << "  8. Quit" << endl;
		getline (cin,mystr);
		stringstream(mystr) >> choice;
		
		if (choice == 1)
		{
			cout << "What is the fraction you would like to reduce?" << endl;
			Fraction a = getFraction();
			Fraction b = a.reduce();
			cout << "The reduced form of ";
			a.print();
			cout << " is ";
			b.print();
			cout << "." << endl;
		}
		else if (choice == 2)
		{
			cout << "What is the fraction you would like the reciprocal of?" << endl;
			Fraction a = getFraction();
			Fraction b = a.reciprocal();
			cout << "The reciprocal of ";
			a.print();
			cout << " is ";
			b.print();
			cout << "." << endl;
		}
		else if (choice == 3)
		{
			cout << "What are the fractions you would like to add?" << endl;
			cout << "Fraction one:" << endl;
			Fraction a = getFraction();
			cout << "Fraction two:" << endl;
			Fraction b = getFraction();
			Fraction c = a + b;
			a.print();
			cout << " + ";
			b.print();
			cout << " is equal to ";
			c.print();
			cout << "." << endl;
		}
		else if (choice == 4)
		{
			cout << "What are the fractions you would like to subtract?" << endl;
			cout << "Fraction one:" << endl;
			Fraction a = getFraction();
			cout << "Fraction two:" << endl;
			Fraction b = getFraction();
			Fraction c = a - b;
			a.print();
			cout << " - ";
			b.print();
			cout << " is equal to ";
			c.print();
			cout << "." << endl;
		}
		else if (choice == 5)
		{
			cout << "What are the fractions you would like to multiply?" << endl;
			cout << "Fraction one:" << endl;
			Fraction a = getFraction();
			cout << "Fraction two:" << endl;
			Fraction b = getFraction();
			Fraction c = a * b;
			a.print();
			cout << " * ";
			b.print();
			cout << " is equal to ";
			c.print();
			cout << "." << endl;
		}
		else if (choice == 6)
		{
			cout << "What are the fractions you would like to divide?" << endl;
			cout << "Fraction one:" << endl;
			Fraction a = getFraction();
			cout << "Fraction two:" << endl;
			Fraction b = getFraction();
			Fraction c = a / b;
			a.print();
			cout << " / ";
			b.print();
			cout << " is equal to ";
			c.print();
			cout << "." << endl;
		}
		else if (choice == 7)
		{
			cout << "What are the fractions you would like to compare?" << endl;
			cout << "Fraction one:" << endl;
			Fraction a = getFraction();
			cout << "Fraction two:" << endl;
			Fraction b = getFraction();
			if (a == b)
			{
				a.print();
				cout << " is equal to ";
				b.print();
				cout << "." << endl;
			}
			else
			{
				a.print();
				cout << " is not equal to ";
				b.print();
				cout << "." << endl;
			}
		}
		else if (choice == 8)
		{
			running = false;
		}
	}
}
















