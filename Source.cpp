//source code file
#include<iostream>
using namespace std;
class Distance
{
private:
	float feet, inch;
public:
	//this function will ask user for distance
	void getDistance()
	{
		cout <<"\n\tPlease enter feet: ";
		cin >> feet;
		cout << "\tPlease enter inch: ";
		cin >> inch;
	}
	//this will print output
	void showDistance()
	{
		cout << "Feet: " << feet << endl;
		cout << "Inch: " << inch << endl;
		//if inches enterd are greater than 12 then incrementing feet
		if (inch > 12)
		{
			feet++;
			inch -= 12;
		}
	}
	//adding distance
	Distance addDistance(Distance D2)
	{
		Distance sum;
		sum.feet = feet + D2.feet;
		sum.inch = inch + D2.inch;
		//if sum of inches is greater than 12 then converting them into feet according to situation and displaying remaining inches
		if (sum.inch > 12)
		{
			//
			int extraInches = sum.inch / 12;
			sum.feet += extraInches;
			sum.inch -= (extraInches * 12);
		}
		return sum;
	}
	//subtracting distance
	Distance subDistance(Distance D2)
	{
		Distance subtraction;
		//if 1st distance is greater than second distance then this block will execute
		if (feet > D2.feet)
		{
			//if 1st distance inch is greater than or equal to second then performing 1st minus second
			if (inch > D2.inch || inch == D2.inch)
			{
				subtraction.feet = feet - D2.feet;
				subtraction.inch = inch - D2.inch;
			}
			//else if 1st distance inch is less than second then performing second minus 1st
			else if (inch < D2.inch)
			{
				subtraction.feet = feet - D2.feet;
				subtraction.inch = D2.inch - inch;
			}
		}
		//this is vice versa of above block
		else
		{
			if (inch > D2.inch || inch == D2.inch)
			{
				subtraction.feet = D2.feet - feet;
				subtraction.inch = inch - D2.inch;
			}
			else if (inch < D2.inch)
			{
				subtraction.feet = feet - D2.feet;
				subtraction.inch = D2.inch - inch;
			}
		}
		return subtraction;
	}
};
int main()
{
	Distance D1, D2, D3, D4;
	cout << "Please enter Distance 1: \n";
	D1.getDistance();
	cout << "\nPlease enter Distance 2: \n";
	D2.getDistance();
	D3 = D1.addDistance(D2);
	D4 = D1.subDistance(D2);
	cout << endl << "Distance 1 entered by user is : \n";
	D1.showDistance();
	cout << endl << "Distance 2 entered by user is: \n";
	D2.showDistance();
	cout << endl << "After adding both distances sum becomes : \n";
	D3.showDistance();
	cout << endl << "After subtracting both distances difference becomes: \n";
	D4.showDistance();
	cout << endl;
	system("pause");
	return 0;
}
