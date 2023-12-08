// C++ program to illustrate bookshop
// management system using File Handling
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Bookshop Class
class bookshop {	
public:
	void control_panel();
	void add_book();
	void show_book();
	void check_book();
	void update_book();
	void del_book();
      void bookShopRecord();
	void membership();
};

// Function to display the menus
void bookshop::control_panel()
{
	cout << "\n\n\t\t\t\tCONTROL PANEL";
	cout << "\n\n1. ADD BOOK";
	cout << "\n2. DISPLAY BOOKS";
	cout << "\n3. CHECK PARTICULAR BOOK";
	cout << "\n4. UPDATE BOOK";
	cout << "\n5. DELETE BOOK";
	cout << "\n6. CHECK MEMEBERSHIP/ADD MEMBERSHIP";
	cout << "\n7. EXIT";
}

// Function to add book
void bookshop::add_book()
{
	fstream file;
	int no_copy;
	float b_price;
	string b_name, a_name, b_id;
	cout << "\n\n\t\t\t\tADD BOOKS";
	cout << "\n\nBook ID : ";
	cin >> b_id;
	cout << "\nBook Name : ";
	cin >> b_name;
	cout << "\nAuthor Name : ";
	cin >> a_name;
	cout << "\nNo. of Books : ";
	cin >> no_copy;
	cout << "\nEnter price : ";
	cin >> b_price;

	// Open file in append or
	// output mode
	file.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt",ios::out | ios::app);
	file << " " << b_id << " " << b_name << " " << a_name << " " << no_copy << " " << b_price << "\n";
	file.close();
}

// Function to display book
void bookshop::show_book()
{
	fstream file;
	int no_copy;
	float b_price;
	string b_name, b_id, a_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt", ios::in);
	if (!file) {

		cout << "\n\nFile Opening Error!";
      }

	else {

		cout << "\n\n\nBook ID\t\tBookname" << "\tAuthor\t\tNo.of Books\tprice\n\n"; 
            file >> b_id >> b_name;
            file >> a_name >> no_copy >> b_price;

		// Till end of file is reached
		while (!file.eof()) {

			cout << " " << b_id << "\t\t" << b_name << "\t\t" << a_name << "\t\t" << no_copy <<  "\t\t" << b_price << "\n\n";
			file >> b_id >> b_name;
			file >> a_name >> no_copy >> b_price;
		}

            

            // Close the file
		file.close();
	}
}

// Function to check the book
void bookshop::check_book()
{
	fstream file;
	int no_copy, count = 0;
	float b_price;
	string b_id, b_name, a_name, b_id1;

	cout << "\n\n\t\t\t\tCheck " << "Particular Book";

	// Open the file in input mode
	file.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt", ios::in);
	if (!file) {

		cout << "\n\nFile Opening Error!";
      }

	else {

		cout << "\n\nBook ID : ";
		cin >> b_id1;
		file >> b_id >> b_name;
		file >> a_name >> no_copy >> b_price;

		while (!file.eof()) {

			if (b_id1 == b_id) {

		
				cout << "\n\n\t\t\t\t" << "Check Particular Book";
				cout << "\n\nBook ID : " << b_id;
				cout << "\nName : " << b_name;
				cout << "\nAuthor : " << a_name;
				cout << "\nNo. of Books : " << no_copy;
				cout << "\nPrice : " << b_price;
				cout << endl << endl;
				count++;
				break;
			}

			file >> b_id >> b_name;
			file >> a_name >> no_copy >> b_price;
		}

		
		file.close();
		if (count == 0){
                  cout << "\n\nBook ID Not" << " Found...";
            }
	}
}

// Function to update the book
void bookshop::update_book()
{
	fstream file, file1;
	int no_copy, no_co, count = 0;
	float b_price,b_p;
	string b_name, b_na, a_name;
	string a_na, b_idd, b_id;

	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo1.txt", ios::app | ios::out);
	file.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt", ios::in);

	if (!file) {

		cout << "\n\nFile Opening Error!";
      }

	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy >> b_price;

		// Till end of file is reached
		while (!file.eof()) {
			if (b_id == b_idd) {
		
				cout << "\t\t\t\t" << "Update Book Record";
				cout << "\n\nNew Book Name : ";
				cin >> b_na;
				cout << "\nAuthor Name : ";
				cin >> a_na;
				cout << "\nNo. of Books : ";
				cin >> no_co;
				cout << "\nNew Price: ";
				cin >> b_p;
				file1 << " " << b_id << " " << b_na << " " << a_na << " " << no_co <<  " " << b_p << "\n\n";
				count++;
			}

			else {
				file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << "\n\n";
                  }

			file >> b_idd >> b_name;
			file >> a_name >> no_copy >> b_price;
                  
		}
		if (count == 0) {
			cout << "\n\nBook ID" << " Not Found...";
            }
	}
	cout << endl;
	

	// Close the files
	file.close();
	file1.close();
	remove("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt");
	rename("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo1.txt", "/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt");
}

// Function to delete book
void bookshop::del_book()
{
	fstream file, file1;
	int no_copy, count = 0;
	float b_price;
	string b_id, b_idd, b_name, a_name;
	cout << "\n\n\t\t\t\tDelete a Book";

	// Append file in output mode
	file1.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo1.txt", ios::app | ios::out);
	file.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt", ios::in);

	if (!file) {
		cout << "\n\nFile Opening Error...";
      }

	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy >> b_price;
		while (!file.eof()) {

			if (b_id == b_idd) {

		
				cout << "\n\n\t\t\t\t" << "Delete a Book";
				cout << "\n\nBook is Deleted "" Successfully...\n\n";
				count++;
			}

			else {
				file1 << " " << b_idd << " " << b_name << " " << a_name<< " " << no_copy << " " << b_price << "\n\n";
                        }
			file >> b_idd >> b_name;
			file >> a_name >> no_copy >> b_price;
		}
		if (count == 0)
			cout << "\n\nBook ID " << "Not Found...";
	}
	

	// Close the file
	file.close();
	file1.close();
	remove("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt");
	rename("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo1.txt", "/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt");
}



//added 1st::
void bookshop::membership()
{

	cout << "\n\nIF U DECIDE TO BUY OUR MEMBERSHIP THEN YOU CAN HAVE CERTAIN BENIFITS, LIKE ------->> \n" << endl;
	cout << "Direct discount upto 10%% or more on any and every book we have...!!! \n" << endl;

	fstream file;
	int coustomer , coustomer1 , coustomer2;
	bool key = false;
	char x;

	file.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/membership.txt", ios::in);

	if (!file) 
	{
		cout << "\n\nFile Opening Error...";

		return;
      }

	file >> coustomer;


	cout << "\n\nEnter ur coustomer I.D :: " << endl;
	cin >> coustomer1;

	while (!file.eof())
	{
		if (coustomer1 == coustomer)
		{
			cout << "\n\nyou already have a membership";
			cout << "\ncheck for today's discounts..!!\n\n";
			system("cowsay Loading...Discounts...!");
			key = true;
			break;
		}

		else
		{
			break;
		}
	}

	file.close();

	if (key == false)
	{
		cout << "do you want to add membership..?\nthe price is: RS 1,000.00 \n(y/n)\n";
		cin >> x;

		if (x == 'y'|| x == 'Y')
		{
			key = true;

			fstream file;

			file.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/membership.txt", ios::out | ios::app);

			file << coustomer1 << "\n" ;

			cout << "\n\ncongrats...! now you have joined our membership..!!\n\n";
			system("cowsay Loading...Discounts...!");

			file.close();
		}

		else
		{
			return;
		}
 	}



	if (key == true)
	{
		// main block::::
		fstream file11;
		int no_copy;
		float b_price;
		string b_name, b_id, a_name;
		cout << "\n\n\t\t\t\nDISCOUNTED PRICES FOR OUR MEMBERS ONLY..!";

		// Open the file in input mode
		file11.open("/home/tanmay/Documents/CODES/Cpp1/bookinfo/bookinfo.txt", ios::in);

		if (!file11) 
		{

			cout << "\n\nFile Opening Error!";
		}

		else {

			cout << "\n\n\nBook ID\t\tBookname\tprice\n\n"; 
			file11 >> b_id >> b_name;
			file11 >> a_name >> no_copy >> b_price;

			// Till end of file is reached
			while (!file11.eof()) {

				cout << " " << b_id << "\t\t" << b_name << "\t\t" <<  b_price - ((b_price) * 0.1) << "\n\n";
				file11 >> b_id >> b_name;
				file11 >> a_name >> no_copy >> b_price;
			}

			

			// Close the file
			file11.close();
		}
		
		}
}
// Function for book shop record::
void bookshop::bookShopRecord()
{
	int choice;
	char x;
	bookshop b;

	while (1) {

		b.control_panel();
		cout << "\n\nEnter your choice : ";
		cin >> choice;

            //here we go..!!!
		switch (choice) {

		case 1:
			do {

				b.add_book();
				cout << "\n\nWant to add"
					<< " another book? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y' || x == 'Y');
			break;

		case 2:
			b.show_book();
			break;

		case 3:
			b.check_book();
			break;
		case 4:
			b.update_book();
			break;

		case 5:
			b.del_book();
			break;

		case 6:
			b.membership();
			break;
		
		case 7:
			exit(0);
			break;

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}

// Driver Code
int main()
{
      // Created an object of bookshop class
      bookshop miniproject;

	// Function Call
	miniproject.bookShopRecord();

	return 0;
}
