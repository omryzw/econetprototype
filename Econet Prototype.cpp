#include <iostream>
// a menu based share airtime ussd app
using namespace std;

               void share_airtime();
               void credit();
               void share_wallet();

void share_airtime() {
	int phone,choicetime;
	cout << "enter the phone number\n";
	cin >> phone;
	cout << "Enter 1 to confirm\n";
	cin >> choicetime;
	if (choicetime == 1) {
		cout << "User" " ";
		cout << phone;
		cout << " " " has been connected successfully\n";
	}
	else {
		cout << " Process has been cancelled \n";
	}
}
	          void credit() {
		                     	int phone2,choice2;
		                        float amount;
		                     	cout << "Enter the Phone number\n";
								cin >> phone2;
								cout << "Enter the amount to share\n";
								cin >> amount;
								cout << "Enter 1 to confirm\n";
								cin >> choice2;
								if (choice2 == 1) {
									cout << "User" " ";
									cout << phone2;
									cout << " " "has been credited with" " " "$";
									cout << amount;
								}
								
								else {
									cout << " Process has been cancelled \n";
								}										
	}
	         
int main() {
	
	int pin, choice1;
	cout << "Welcome to Econet Share, Please enter your PIN below \n" << endl;
	cin >> pin;
	cout << " " << endl;

if (pin == 1968)

{
	cout << "1. Share airtime \n";
	cout << "2. Buy Credit for other\n";
	cout << "3. Exit\n \n";
	
	cin >> choice1;
	
switch (choice1) {
    
    case 1: share_airtime();
    break;

case 2: credit();
break;

case 3 : return 0;
    
   default : cout << "Incorrect Input \n\n";

}

}
    else {	
	cout << "Incorrect Pin, Please try again" " ";
	main();	
}
	
}