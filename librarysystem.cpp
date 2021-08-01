///By OMRI MAREBERA (H160490V)
///omrimarebera85@gmail.com +263778922305
///Harare Institue of Technology @2017
///Zimbabwe first year student
#include <iostream>

#include <cstring>

using namespace std;
//char book_title[100];
///////////////////Declared the following as Global Varibles since i couldn't use them outside their classess//////////////////////////////
int book_id;
char name[100];
char std_id[100];
int days;
string borrowed_book[100]; //stores the names of borrowed books
string compare[100]; /// left empty so as to compare with the bookrec to check if empty.
/// to compare since its empty and can't use character string functions apa
///also used string and not char because Char was overloading with the Titles.
string bookrec[100] = {
	"HTML5_Basics_by_Duckket",
	"Visual_Basic_for_Beginners",
	"Popular_Mechanics_Magazine",
	"Crawshaw_Discrete_Mathematics",
	"Tambaoga_by_Willard_Motsipiri"
};
//function declaration
void Login();
void Print_Details();

class Library {
	public:
		char choice;
	void getDetails() {
		cout << "Enter the Student Name\n";
		cin >> name;
		cout << "Enter the Student School ID\n";
		cin >> std_id;
		Book_List(); /// shows the user a list of books and their IDs
		cout << endl;
		cout << "Enter the Book ID\n";
		cin >> book_id;
		cout << "Enter the Days\n";
		cin >> days;
		Book_Records();
		Print_Details();
	}

	void Book_Records() {
		//cout << "Enter The Book ID\n";
		//cin >> book_id;
		//int 
		//if borrowed is not null then print book has been borrowed
		//below code to be changed to add  more books
		switch (book_id) {

			case 1:
				if (borrowed_book[0] == compare[0]) { //check if index 0 is empty

					borrowed_book[0] = bookrec[0]; //if empty means book has not been borrowed therefore we assign the book to that borrowed array

				} else {
					Warning();
				}
				break;

			case 2:
				if (borrowed_book[1] == compare[0]) {
					borrowed_book[1] = bookrec[1];
				} else {
					Warning();
				}
				break;

			case 3:
				if (borrowed_book[2] == compare[0]) {
					borrowed_book[2] = bookrec[2];
				} else {
					Warning();
				}
				break;

			case 4:
				if (borrowed_book[3] == compare[0]) {
					borrowed_book[3] = bookrec[3];
				} else {
					Warning();
				}
				break;

			case 5:
				if (borrowed_book[4] == compare[0]) {
					borrowed_book[4] = bookrec[4];
				} else {
					Warning();
				}
				break;
			default:
				cout << "Invalid Book ID\n";
				cout << " Enter Another Valid Book ID\n";
				cin >> book_id;
				Book_Records(); ///starts again
		}

	}
	int Warning() {
		// TO BE CALLED IF BOOK IS NOT AVAILABLE
		int i;
		cout << " Book is Nolonger Available\n\n";
		cout << "Do you want to continue : Y/N? \n\n";
		cin >> choice;
		cout << endl;
		cout << "-------------------------------------------------------------------------------------";
		cout << endl;
		if (choice == 'Y') {
			cout << "The Book status are :\n\n";
			for (i = 0; i < 5; i++) {
				if (borrowed_book[i] != compare[i]) {
					//IF BORROWED BOOK RECORD IS NOT EMPTY MEANS BOOK HAS BEEN BORROWED ALREADY		
					cout << borrowed_book[i] << " with Book ID = " << i + 1 << " has been borrowed.";
					cout << endl;
				} else

					cout << bookrec[i] << " with Book id = " << i + 1 << " is available.";
				cout << endl;
			}
			cout << endl;
			cout << "Enter another Book Id\n";
			cin >> book_id;
			Book_Records(); ///could not jump back to specific line of code
		} else {
			return 0;
		}

	}

	void Book_List() {
		cout << "List of Books\n\n";
		cout << "Title of Book" << "\t\t\t\t" << "Book ID number" << endl;
		cout << "HTML5 Basics by Duckket" << "\t\t\t\t" << "1" << endl;
		cout << "Visual Basic for Beginners" << "\t\t\t" << "2" << endl;
		cout << "Popular Mechanics Magazine" << "\t\t\t" << "3" << endl;
		cout << "Crawshaw Discrete Mathematics" << "\t\t\t" << "4" << endl;
		cout << "Tambaoga by Willard Motsipiri" << "\t\t\t" << "5" << endl;
		cout << endl << endl;
	}

};

class Welcome_Screen {
	public:
		void Login() ///login function
	{
		int log_id, log_pin;
		cout << "Welcome to the Libary System\n\n";
		cout << "Enter User ID followed by User PIN to Login\n\n";
		///pin number to have an input mask like ***///
		cin >> log_id >> log_pin;
		if (log_id == 1234 & log_pin == 1234) {
			cout << " Login Successful \n\n";

		} else {
			cout << "Login Failed .Try again\n\n";
			Login();
		}
	}
	int Main_Menu() {
		Library issue;
		int choice;
		cout << " This is the main menu, choose options below\n";
		cout << "1. Borrow Book\n" << "2. View Book List\n" << "3.Exit\n";
		cin >> choice;
		switch (choice) {
			case 1:
				issue.getDetails();
				break;
			case 2:
				issue.Book_List();
				break;
			case 3:
				cout << "Thank you for using the Omri Library System ver 1.0";
				return 0;
				break;
			default:
				cout << "Invalid input \n";
				Main_Menu();

		}
	}
};
///Put this function outchea cuz you can't call a class function within another class
///to be used on iteration that's why it is a function.
void Print_Details() {

	char answer; ///choice to continue or add another student
	cout << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << endl;
	cout << "The Details of Last Transaction\n\n";
	cout << "Name" << "\t" << "STD ID" << "\t" << "Book ID" << "\t" << "Book Title" << endl;
	cout << name << "\t" << std_id << "\t" << book_id << "\t" << bookrec[book_id - 1]; ////points to the exact book
	cout << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	// current date/time based on current system function
	time_t tommorrow = time(0);

	// convert now to string form
	char * dt = ctime( & tommorrow);

	cout << "The Time and Date of transaction is : " << dt << endl;
	cout << endl;

	cout << "The Book Should be Returned in " << days << " Days";
	cout << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------------------------";
	cout << endl;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	cout << "Perform another transaction? Y/N \n";
	cin >> answer;
	if (answer == 'Y') {
		Welcome_Screen account;
		account.Main_Menu();
	} else {
		cout << "Thanks for using Omri Library System ver 1.0\n";
	}
}
int main() {
	Welcome_Screen account;
	account.Login();
	account.Main_Menu();
}
///By OMRI MAREBERA (H160490V)