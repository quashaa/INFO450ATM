//Program that determines number of bills to return with a withdrawal request
#include <iostream>
using namespace std;

//Function declaration
int getWithdraw();

int main()
{
	int withdraw = 0;
	char answer;

	cout << "**** Welcome to the ATM! ****\n" << endl;

	//This loop excutes the initial withdrawal request and allows for additional withdrawals
	do
	{
		//Function call
		withdraw = getWithdraw();

		//Resets denominations to 0 for subsequent withdrawals
		int fifty = 0, twenty = 0, ten = 0, five = 0, one = 0;
		
		/*These loops subtract the highest amount possible from the withdrawal 
		while also adding a value of 1 to the respective denomination*/
		while (withdraw >= 50)
		{
			withdraw -= 50;
			fifty += 1;
		}

		while (withdraw >= 20)
		{
			withdraw -= 20;
			twenty += 1;
		}

		while (withdraw >= 10)
		{
			withdraw -= 10;
			ten += 1;
		}

		while (withdraw >= 5)
		{
			withdraw -= 5;
			five += 1;
		}

		while (withdraw >= 1)
		{
			withdraw -= 1;
			one += 1;
		}

		cout << "\nPlease wait... Your cash is being dispersed as below:" << endl;

		//These if statments produce an output if the respective denomination has a value greater than 0
		if (fifty > 0)
			cout << fifty << " $50.00 bills" << endl;

		if (twenty > 0)
			cout << twenty << " $20.00 bills" << endl;

		if (ten > 0)
			cout << ten << " $10.00 bills" << endl;

		if (five > 0)
			cout << five << " $5.00 bills" << endl;

		if (one > 0)
			cout << one << " $1.00 bills" << endl;

		cout << "\nWould you like to make another withdrawl? (enter Y to continue)" << endl;
		cin >> answer;
		cout << endl;



	}
	while (answer == 'Y' || answer == 'y');

	cout << "**** Good Bye! ****" << endl;
	system("pause");
	return 0;
}

//Function to get withdrawal amount from user
int getWithdraw()
{
	int withdraw, min = 1, max = 300;

	//This loop ensures the user is entering a valid input
	do
	{
		cout << "Please enter a withdrawal amount" << endl;
		cin >> withdraw;

		//These if statements notify the user that the amount entered can't be less than 1 or greater than 300
		if (withdraw < min)
			cout << "Sorry, the minimum amount allowed to be withdrawn is $1.00\n" << endl;

		if (withdraw > max)
			cout << "Sorry, the maximum amount allowed to be withdrawn is $300.00\n" << endl;
	}

	while (withdraw < min || withdraw > max);

	return withdraw;
}