#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
int indexholder = 0;
class Book {
	string title;
	string shelfnumber;
	string authors;
	string edition;
	string publisher;
	string publishedyear;
	string ISBN;
	string length;
	string subjects;
	//string isgot;
	//string available;
	ifstream bookdataholder;
	ofstream bookdataholder2;
	ofstream borrowreturnfile;
	ifstream borrowreturnfile2;
	//vector<vector<string>>bookfeatures;
	//vector<vector<string>>bookauthors;
public:
	void bookmenu(int bookoption = 0) {
		/*string linebook;
		string searching = "available";
		bookdataholder.open("bookdataholder.txt", ios::app);
		while (!bookdataholder.eof()) {
			getline(bookdataholder,linebook,'\n');
			size_t v=linebook.find(searching);
			int startindex = static_cast<int>(v);
			linebook.substr(startindex, 9) = "not free ";
			bookdataholder.close();
		}*/
		if (bookoption == 0) {
			cout << "choose one of the following options:" << endl << "1.search" << endl << "2.borrowing a book" << endl << "3.returning a book" << endl << "4.exit" << endl;
			cin >> bookoption;
		}
		/*if (bookoption == 1) {
			cout << "choose which feature do you want to search the book with" << endl << "1.title" << "2.authors" << "3.publisher" << "4.publishedyear" << endl;
			int bookfeature;
		}*/
		if (bookoption == 1) {
			search();
		}
		else if (bookoption == 2) {
			borrowing();
		}
		else if (bookoption == 3) {
			returning();
		}
		else if (bookoption == 4) {
			exit(1);
		}
	}
	void search() {
		cout << "choose features you want to search based on them (enter * if you dont want that filter and use \"_\" instead of \"space\"):" << endl << "title : ";
		cin >> title;
		cout << "authors: ";
		cin >> authors;
		cout << "publisher: ";
		cin >> publisher;
		cout << "published year: ";
		cin >> publishedyear;
		string linesearch;
		//if (title != "*" && authors != "*" && publisher != "*" && publishedyear != "*") {
		int p = 0;
		bookdataholder.open("bookdataholder.txt", ios::app);
		cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		cout << "here is your search result(s) based on filters you applied: ";
		while (!bookdataholder.eof()) {
			getline(bookdataholder, linesearch, '\n');
			size_t v = 1000, w = 1000, x = 1000, y = 1000;
			if (title != "*") {
				v = linesearch.find(title);
			}
			if (authors != "*") {
				w = linesearch.find(authors);
			}
			if (publisher != "*") {
				x = linesearch.find(publisher);
			}
			if (publishedyear != "*") {
				y = linesearch.find(publishedyear);
			}
			int v1 = static_cast<int>(v);
			int w1 = static_cast<int>(w);
			int x1 = static_cast<int>(x);
			int y1 = static_cast<int>(y);

			if (v1 != -1 && v1 != 1000 && w1 != -1 && w1 != 1000 && x1 != -1 && x1 != 1000 && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if (v1 != -1 && v1 != 1000 && (w1 == 1000) && (x1 == 1000) && (y1 == 1000)) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if ((v1 == 1000) && w1 != -1 && w1 != 1000 && (x1 == 1000) && (y1 == 1000)) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if ((v1 == 1000) && (w1 == 1000) && x1 != -1 && x1 != 1000 && (y1 == 1000)) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if ((v1 == 1000) && (w1 == 1000) && (x1 == 1000) && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if (v1 != -1 && v1 != 1000 && w1 != -1 && w1 != 1000 && (x1 == 1000) && (y1 == 1000)) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if (v1 != -1 && v1 != 1000 && (w1 == 1000) && x1 != -1 && x1 != 1000 && (y1 == 1000)) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if (v1 != -1 && v1 != 1000 && (w1 == 1000) && (x1 == 1000) && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if ((v1 == 1000) && w1 != -1 && w1 != 1000 && x1 != -1 && x1 != 1000 && (y1 == 1000)) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if ((v1 == 1000) && w1 != -1 && w1 != 1000 && (x1 == 1000) && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if ((v1 == 1000) && (w1 == 1000) && x1 != -1 && x1 != 1000 && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if (v1 != -1 && v1 != 1000 && w1 != -1 && w1 != 1000 && x1 != -1 && x1 != 1000 && (y1 == 1000)) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if (v1 != -1 && v1 != 1000 && (w1 == 1000) && x1 != -1 && x1 != 1000 && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if (v1 != -1 && v1 != 1000 && w1 != -1 && w1 != 1000 && (x1 == 1000) && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
			if ((v1 == 1000) && w1 != -1 && w1 != 1000 && x1 != -1 && x1 != 1000 && y1 != -1 && y1 != 1000) {
				cout << endl;
				cout << linesearch;
				p = 1;
			}
		}
		if (p == 0) {
			cout << "no result matches your search data" << endl;
			bookmenu(0);
		}
		else {
			cout << endl << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
			cout << "what do you want to do now?" << endl;
			bookmenu(0);
		}
		bookdataholder.close();
	}
	void borrowing() {
		string book_title2;
		string book_authors2;
		cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		cout << "enter title and author(s) of the book you want to borrow , ((completely)):(if you can't remember, search the book for details first!)" << endl << "use \"_\" instead of \"space\"" << endl;
		cout << "title: ";
		cin >> book_title2;
		cout << "author(s): ";
		cin >> book_authors2;
		size_t finder = 0;
		size_t finder2 = 0;
		int findint = 0;
		int find2int = 0;
		size_t indexfree = 0;
		int fl = 2;
		string blineholder;
		string alinestring;
		bookdataholder.open("bookdataholder.txt", ios::in);
		while (getline(bookdataholder, blineholder)) {
			int	finder = blineholder.find(book_title2);
			int finder2 = blineholder.find(book_authors2);
			//cout << finder << "   " << finder2 << endl;
			findint = static_cast<int>(finder);
			find2int = static_cast<int>(finder2);
			//cout << findint << "   " << finder2;
			if ((findint != -1) && (find2int != -1)) {
				fl = 1;
				indexfree = blineholder.find("free_status");
				int indexfreeint = static_cast<int>(indexfree);
				if (indexfreeint != -1) {
					alinestring = blineholder.substr(0, indexfreeint) + "not_available" + blineholder.substr(indexfreeint + 11, blineholder.length() - indexfreeint - 11);
					borrowreturnfile.open("borrowreturnfile.txt", ios::app);
					borrowreturnfile << alinestring << endl;
					borrowreturnfile.close();
					//cout << alinestring;
					//blineholder.substr(indexfree, 13) = "not_available";
					//elementassemble(alinestring, counterline);
				}
			}
			else {
				borrowreturnfile.open("borrowreturnfile.txt", ios::app);
				borrowreturnfile << blineholder << endl;
				borrowreturnfile.close();
			}
		}
		if (fl != 1) {
			cout << "this book is not available in the library right now!" << endl;
			bookdataholder.close();
			bookmenu(0);
		}
		else {
			bookdataholder.close();
			cout << "you borrowed the book successfully!" << endl;
			cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
			cout << "if you want to exit enter 1 and to continue enter 2" << endl;
			int optionn = 0;
			cin >> optionn;
			if (optionn == 1) {
				exit(1);
			}
			else if (optionn == 2) {
				bookmenu(0);
			}
		}
		remove("bookdataholder.txt");
		string backtomainf;
		borrowreturnfile2.open("borrowreturnfile.txt", ios::in);
		while (getline(borrowreturnfile2, backtomainf)) {
			bookdataholder2.open("bookdataholder.txt", ios::app);
			bookdataholder2 << backtomainf << endl;
			bookdataholder2.close();
		}
		borrowreturnfile2.close();
		remove("borrowreturnfile.txt");
	}
	void returning() {
		string return_title;
		string return_authors;
		cout << "enter title and author(s) of the book you want to return , ((completely)):(if you can't remember, search the book for details first!)" << endl << "use \"_\" instead of \"space\"" << endl;
		cout << "title: ";
		cin >> return_title;
		cout << "author(s): ";
		cin >> return_authors;
		size_t findret = 0;
		size_t findret2 = 0;
		int findretint = 0;
		int findret2int = 0;
		size_t indexnotfree = 0;
		int fla = 2;
		string seclineholder;
		string firstlineholder;
		bookdataholder.open("bookdataholder.txt", ios::in);
		while (getline(bookdataholder, seclineholder)) {
			int	findret = seclineholder.find(return_title);
			int findret2 = seclineholder.find(return_authors);
			//cout << finder << "   " << finder2 << endl;
			findretint = static_cast<int>(findret);
			findret2int = static_cast<int>(findret2);
			//cout << findint << "   " << finder2;
			if ((findretint != -1) && (findret2int != -1)) {
				fla = 1;
				indexnotfree = seclineholder.find("not_available");
				int indexnotfreeint = static_cast<int>(indexnotfree);
				if (indexnotfreeint != -1) {
					firstlineholder = seclineholder.substr(0, indexnotfreeint) + "free_status" + seclineholder.substr(indexnotfreeint + 13, seclineholder.length() - indexnotfreeint - 13);
					borrowreturnfile.open("borrowreturnfile.txt", ios::app);
					borrowreturnfile << firstlineholder << endl;
					borrowreturnfile.close();
				}
			}
			else {
				borrowreturnfile.open("borrowreturnfile.txt", ios::app);
				borrowreturnfile << seclineholder << endl;
				borrowreturnfile.close();
			}
		}
		if (fla != 1) {
			cout << "this book doesn't available in the library!" << endl;
			bookdataholder.close();
			bookmenu(0);
		}
		else {
			bookdataholder.close();
			cout << "you returned the book successfully!" << endl;
			cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
			cout << "if you want to exit enter 1 and to continue enter 2" << endl;
			int optionnn = 0;
			cin >> optionnn;
			if (optionnn == 1) {
				exit(1);
			}
			else if (optionnn == 2) {
				bookmenu(0);
			}
		}
		remove("bookdataholder.txt");
		string backtomainfile;
		borrowreturnfile2.open("borrowreturnfile.txt", ios::in);
		while (getline(borrowreturnfile2, backtomainfile)) {
			bookdataholder2.open("bookdataholder.txt", ios::app);
			bookdataholder2 << backtomainfile << endl;
			bookdataholder2.close();
		}
		borrowreturnfile2.close();
		remove("borrowreturnfile.txt");
	}
	//void elementassemble(string holderrr, int counterline2) {
	//	string newlinestring;
	//	int newcounterline = 0;
	//	//cout << holderrr;
	//	cout << counterline2;
	//	bookdataholder.open("bookdataholder.txt", ios::in);
	//	while (getline(bookdataholder, newlinestring)) {
	//		borrowreturnfile.open("borrowreturnfile.txt", ios::app);
	//		if (counterline2 == newcounterline) {
	//			borrowreturnfile << holderrr << endl;
	//			newcounterline++;
	//		}
	//		else {
	//			borrowreturnfile << newlinestring << endl;
	//			newcounterline++;
	//		}
	//		borrowreturnfile.close();
	//		//cout << newlinestring;
	//	}
	//	bookdataholder.close();
	//}
private:
};
class User :public Book {
	string username;
	string password;
	string firstname;
	string lastname;
	string birthdate;
	vector<vector<string>> dataholder;
	fstream dataholderfile;
public:
	void Sign_Up(string username, string password, string firstname = NULL, string lastname = NULL, string birthdate = NULL) {
		cout << "enter your firstname: ";
		cin >> firstname;
		cout << "enter your lastname: ";
		cin >> lastname;
		cout << "enter your birthdate: ";
		cin >> birthdate;
		dataholder.push_back({ username,password,firstname,lastname,birthdate,"0"});
		dataholderfile.open("dataholder.txt", ios::app);
		dataholderfile << username << "," << password << "," << firstname << "," << lastname << "," << birthdate << "," << endl;
		dataholderfile.close();
		cout << "you have successfully signed up!" << endl;
		cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
		workmenu(0);
	}
	void Sign_In(string username, string password) {
		string holderstring;
		int p = 1;
		dataholderfile.open("dataholder.txt", ios::in);
		while (getline(dataholderfile, holderstring)) {
			int starti = 0;
			p = 1;
			int endi;
			string userstr, userstr2;
			for (int i = 0; i < holderstring.length(); i++) {
				if (p < 3) {
					if ((holderstring[i] == ',') && (p == 2)) {
						userstr2 = holderstring.substr(starti + 1, i-starti-1);
						p += 1;
					}
					if ((holderstring[i] == ',') && (p == 1)) {
						endi = i;
						userstr = holderstring.substr(starti, endi);
						starti = i;
						p += 1;
					}
				}
			}
			//cout << userstr <<endl<< userstr2;
			if ((userstr == username) && (userstr2 == password)) {
				cout << "you have successfully signed in!" << endl;
				cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
				cout << "here is the book menu:" << endl;
				p = 4;
				bookmenu(0);
			}
		}
		if (p != 4) {
			cout << "incorrect username or password! please try again" << endl;
			cout << "enter your username" << endl << "username: ";
			cin >> username;
			cout << "enter your password" << endl << "password: ";
			cin >> password;
			Sign_In(username, password);
		}
	}
	void workmenu(int option) {
		if (option == 0) {
			cout << "welcome to the library!" << endl << "choose if you want to sign up or sign in" << endl << "1.sign in" << endl << "2.sign up" << endl << "3.exit" << endl;;
			cin >> option;
		}
		if (option == 1) {
			cout << "enter your username" << endl << "username: ";
			cin >> username;
			cout << "enter your password" << endl << "password: ";
			cin >> password;
			Sign_In(username, password);
		}
		else {
			if (option == 2) {
				cout << "enter your username" << endl << "username: ";
				cin >> username;
				while (checkusername(username) == false) {
					cout << "username is used sometime before! try another username!";
					cin >> username;
				}
				cout << "enter your password" << endl << "password: ";
				cin >> password;
				Sign_Up(username, password, firstname, lastname, birthdate);
			}
			/*else {
				cout << "please choose a valid number" << endl;
				cin	>> option;
				workmenu(option);
			}*/
		}
		if (option == 3) {
			exit(1);
		}	
	}
private:
	bool checkusername(string username) {
		for (int i = 0; i < dataholder.size(); ++i) {
			if (dataholder[i][0] == username) {
				indexholder = i;
				return false;
			}
		}
		return true;
	}
};
int main() {
	User user;
	user.workmenu(0);
	//Book x;
	//x.bookmenu(0);
	return 0;
}
//cout << "choose features you want to search based on them (print * if you dont want it):" << endl << "title : ";
//cin >> title;
//cout << "authors: ";
//cin >> authors;
//cout << "publisher: ";
//cin >> publisher;
//cout << "published year: ";
//cin >> publishedyear;
//string linesearch;
//if (title != "*" && authors != "*" && publisher != "*" && publishedyear != "*") {
//	int p = 0;
//	bookdataholder.open("bookdataholder.txt", ios::app);
//	while (!bookdataholder.eof()) {
//		getline(bookdataholder, linesearch, '\n');
//		size_t v = linesearch.find(title);
//		size_t w = linesearch.find(authors);
//		size_t x = linesearch.find(publisher);
//		size_t y = linesearch.find(publishedyear);
//		int v1 = static_cast<int>(v);
//		int w1 = static_cast<int>(w);
//		int x1 = static_cast<int>(x);
//		int y1 = static_cast<int>(y);
//		if (v1 != -1 && w1 != -1 && x1 != -1 && y1 != -1) {
//			cout << "here is your wanted books based on your filters: " << endl;
//			cout << linesearch;
//			p = 1;
//		}
//	}
//	if (p == 0) {
//		cout << "no result matches your search data";
//		bookmenu(0);
//	}
//	else {
//		cout << "do you want to borrow it now?" << endl << "if yes, enter 1 and for returning to the main menu, enter 2";
//		int opt;
//		cin >> opt;
//	}
//	bookdataholder.close();
//}
//	}