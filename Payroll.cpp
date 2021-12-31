#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int highestPay(double PayArray[], int NumberOfNamesFilled)
{
	/*
		Takes the gross pay array and the number of employees entered to compute the
		index of the array at which stores the highest pay.
	*/
	double highestPaySoFar=PayArray[0];
	double highestIndexSoFar;
	for(int index=0;index<NumberOfNamesFilled;index++)
	{
		if (highestPaySoFar<PayArray[index])
		{
			highestPaySoFar=PayArray[index];
			highestIndexSoFar=index;
		}
	}
	return(highestIndexSoFar);
}
int lowestPay(double PayArray[],int NumberOfNamesFilled)
{
	/*
		Takes the gross pay array and the number of employees entered to compute the
		index of the array at which stores the lowest pay.
	*/
	double lowestPaySoFar=PayArray[0];
	double lowestIndexSoFar;
	for(int index=0;index<NumberOfNamesFilled;index++)
	{
		if (PayArray[index]<lowestPaySoFar)
		{
			lowestPaySoFar=PayArray[index];
			lowestIndexSoFar=index;
		}
	}
	return(lowestIndexSoFar);
}

int getEmployeeNames(string NameArray[],int MaxSize)
{
	/*
		Takes the user's keyboard inputs and store each string inputs into the an array
		designated for containing employees' name until the user enters "quit". The function
		also returns the number of the employees entered into the array.
	*/
	int index=0;
	do {
		cout << "Enter an employee name: ";
		getline(cin,NameArray[index]);
		index++;
	}
	while (((index-1)<MaxSize)&&(NameArray[index-1]!="quit"));
	return(index-1);
}

void getHourlyPay(string NameArray[],double hourlyPayArray[], int NumberOfNamesFilled)
{
	/*
		Takes the user's keyboard inputs and store each double inputs into an array designated
		for containing employees' hourly rates until the hourly rates of all employees are entered.
	*/
	for (int employeeIndex=0;employeeIndex<NumberOfNamesFilled;employeeIndex++)
	{
		cout << "Enter " << NameArray[employeeIndex] << "'s hourly pay rate: ";
		cin >> hourlyPayArray[employeeIndex];
	}
}


int main()
{
	//Sets the decimals outputted to be of two decimal points
	std::cout << std::setprecision(2) << std::fixed;

	/*
		Declares and initializes two constant variables for the number of days in the week and
		the maximum size of employees the user can enter
	*/
	const int NUMDAYS = 7;
	const int SIZE=999;
	
	//Declares necessary variables

	string employeeNames[SIZE];
	double hourlyPay[SIZE];
	double grossPay[SIZE];
    double workHours[SIZE][NUMDAYS];
    int numberOfEmployees=getEmployeeNames(employeeNames,SIZE);
    getHourlyPay(employeeNames,hourlyPay,numberOfEmployees);
    double totalHours[numberOfEmployees];

 	for (int employeeIndex=0;employeeIndex<numberOfEmployees;employeeIndex++)
	{	
		/*
			If the loop hasn't completed entering the work hours of all employees, the program
			will prompt the user to enter number of hours the remaining employees worked
			every day in a week
		*/
		totalHours[employeeIndex]=0;
		cout << "Enter "<<employeeNames[employeeIndex]<<"'s hours for 7 days (0 if day off): ";
		for (int daysIndex=0;daysIndex<NUMDAYS;daysIndex++)
			/*
				If the loop hasn't completed going through entering the hours each employees works 
				in all seven days, the program takes in the user's keyboard input and store it as
				the employee's hours worked at a prticular day. Then, this value is added to the total
				hours that employee worked.

			*/
		{
				cin >> workHours[employeeIndex][daysIndex];
				totalHours[employeeIndex] += workHours[employeeIndex][daysIndex];
		}
		//Computes the gross pay each employee earns
		grossPay[employeeIndex]=totalHours[employeeIndex]*hourlyPay[employeeIndex];
	}

	//Prints out the table, listing the gross pay all employees entered receive
    cout << setw(20) << "Employee Name" << setw(12) << "Total Hours" << setw(10) << "Gross Pay" << endl;
	for (int employeeIndex=0;employeeIndex<numberOfEmployees;employeeIndex++)
	{
		cout << setw(20) << employeeNames[employeeIndex] << setw(12) << totalHours[employeeIndex] << setw(10) << grossPay[employeeIndex] << endl;
	}
	//Prints out the highest pay and lowest pay value
 	cout << "Highest Pay: $" << grossPay[highestPay(grossPay,numberOfEmployees)] << " " << employeeNames[highestPay(grossPay,numberOfEmployees)] << endl;
 	cout << "Lowest Pay: $" << grossPay[lowestPay(grossPay,numberOfEmployees)] << " " << employeeNames[lowestPay(grossPay,numberOfEmployees)]<<endl;
    return 0;
}
