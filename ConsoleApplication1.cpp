#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include <sstream> 
#include"windows.h"
#include <cstdlib>
#include<conio.h>
#define Clear system("cls");

using namespace std;
int QuentityVariants = 4;
int QuentityQuizzes = 2;
int QuentityQuestion = 10;
bool SingIn = false;
string login;
bool FirstLogin = false;
bool bigGame = false;
bool BigWin = false;
int win = 0;
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
using namespace std;

struct Options
{
	string variants;
	bool trueVariants;
};

struct Questions
{
	Options* option = new Options[QuentityVariants];
	string question;

};
struct Quizzes
{
	Questions* query = new Questions[QuentityQuestion];
	string name;
};

void BigGame(string name) {
	SetColor(0, 15);
	ifstream files;
	string s = "BigGame";
	string options;
	s += name;
	files.open(s);	
	s = "";
	getline(files, s);
	cout << s;
	getline(files, s);
	cout << "correct answer-> ";
	cin >> options;
	if (options == s) {
		BigWin = true;
		cout << "You win big game my greeting";
	}
	Sleep(2000);
	Clear;
}

void LogicGame(Quizzes quiz,string name) {
	int xp = 0;
	int achion = 0;
	int* UsedNumber = new int[QuentityQuestion];
	int* arr = new int[10];
	int  k = 0;
	while (k != 10) {
		int j = 0;

		while (true) {
			j = rand() % 10;
			bool isTrue = true;
			for (int i = 0; i < 10; i++) {
				if (j == arr[i]) {
					isTrue = false;
				}
			}
			arr[k] = j;
			if (isTrue == true) {
				k++;
				break;
			}
		}

	}
	for (int g = 0; g < QuentityQuestion; g++)
	{
		int j = arr[g];
		int a = 0;
		while (a != 13) {
			system("cls");
			cout << quiz.query[j].question << endl;
			for (int i = 0; i < QuentityVariants; i++) {
				if (i == achion) {
					SetColor(0, 14);
				}
				if (i != achion) {
					SetColor(0, 15);
				}
				cout << quiz.query[j].option[i].variants << endl;
				SetColor(0, 15);
				
			}
			SetColor(5, 15);
			cout << "True options " << win << "/10" << endl;
			SetColor(0, 15);
			a = _getch();
			if (a == 119) {
				achion--;
				if (achion < 1) {
					achion = QuentityVariants - 1;
				}
			}
			else if (a == 115) {
				achion++;
				if (achion > QuentityVariants-1) {
					achion = 0;
				}
			}
		}
		SetColor(5, 15);
		
		SetColor(0, 15);
	
		int index = 0;
		bool wins = false;
		if (quiz.query[j].option[achion].trueVariants == true) {
			win++;
			wins = true;
			index = achion;
		    xp += (100 + rand() % 100)*(j + 1);
		}
		else {
			for (int g = 0; g < QuentityVariants; g++) {
				if (quiz.query[j].option[g].trueVariants == true) {
					index = g;
				}
			}
		}
		Clear;
		SetColor(0, 15);
		cout << quiz.query[j].question << endl;
		bool IsTrue = false;					
				if (wins == false) {
					for (int i = 0; i < QuentityVariants; i++) {
						if (i == index) {
							SetColor(2, 15);
						}else if(i == achion){
							SetColor(4, 15);
						}
						else {
							SetColor(0, 15);
						}
						cout << quiz.query[j].option[i].variants << endl;
						SetColor(0, 15);
					}
				}
				else {
					for (int i = 0; i < QuentityVariants; i++)
					{
						if (i == index) {
							SetColor(2, 15);
						}
						else {
							SetColor(0, 15);
						}
					cout << quiz.query[j].option[i].variants << endl;
					SetColor(0, 15);
					}
				}
				SetColor(5, 15);

				cout << "True options " << win << "/10" << endl;
				SetColor(0, 15);
				Sleep(1500);
				Clear;
			SetColor(0, 15);	
	}
	SetColor(5, 15);
	cout<<"True options " << win<<"/10"<<endl;
	SetColor(0, 15);
	cout << endl;
	if (win > 7) {
		cout << "Do you want to play a big game, win multiply your winnings twice lose lose your winnings.1.yes 2.no " << endl;
		int  achion = 0;
		cin >> achion;
		if (achion == 1) {
			bigGame = true;
			BigGame(name);
			if (BigWin == true) {
				int index = 0;
				ifstream ReadList;
				ReadList.open("list.txt");
				int count = 0;
				string* list = new string[count];
				while (!ReadList.eof()) {
					int j = 0;
					string* temp = new string[count + 1];
					for (int i = 0; i < count; i++) {
						temp[i] = list[i];

					}
					getline(ReadList, temp[count]);
					if (temp[count] == login) {
						index = j;
					}
					count++;
					list = new string[count];
					for (int i = 0; i < count; i++) {
						list[i] = temp[i];
					}
					j++;
					temp = nullptr;
					delete[] temp;
				}
				ReadList.close();
				ofstream WriteList;
				WriteList.open("list.txt");
				
				if (FirstLogin == false) {
				for (int i = 0; i < count; i++) {
					int a = stoi(list[index + 1]);
					xp += a;
					cout << "You win " << xp << " xp" << endl;
					xp *= 2;
					cout << " But you win " << xp << " xp because you win big game" << endl;
					Sleep(1000);
					if (i == index + 1) {
						WriteList << xp << endl;
					}
					else {
						WriteList << list[i] << endl;
					}
				}
				}
				else {
					WriteList << login << endl;
					WriteList << xp << endl;
					for (int i = 0; i < count; i++) {
							WriteList << list[i] << endl;
						
					}
				}
				WriteList.close();
			}
			else {
				int index = 0;
				ifstream ReadList;
				ReadList.open("list.txt");
				int count = 0;
				string* list = new string[count];
				while (!ReadList.eof()) {
					int j = 0;
					string* temp = new string[count + 1];
					for (int i = 0; i < count; i++) {
						temp[i] = list[i];

					}
					getline(ReadList, temp[count]);
					if (temp[count] == login) {
						index = j;
					}
					count++;
					list = new string[count];
					for (int i = 0; i < count; i++) {
						list[i] = temp[i];
					}
					j++;
					temp = nullptr;
					delete[] temp;
				}
				ReadList.close();
				ofstream WriteList;
				WriteList.open("list.txt");
				xp =0;
				cout << "You win 0 xp because you lose big game" << endl;
				Sleep(1000);
				if (FirstLogin == false) {
					for (int i = 0; i < count; i++) {
						if (i == index + 1) {
							WriteList << xp << endl;
						}
						else {
							WriteList << list[i] << endl;
						}
					}
				}
				else {
					WriteList << login << endl;
					WriteList << xp << endl;
					for (int i = 0; i < count; i++) {
						WriteList << list[i] << endl;
					}
				}
				WriteList.close();
			}
		}
		else {
			int index = 0;
			ifstream ReadList;
			ReadList.open("list.txt");
			int count = 0;
			string* list = new string[count];
			while (!ReadList.eof()) {
				int j = 0;
				string* temp = new string[count + 1];
				for (int i = 0; i < count; i++) {
					temp[i] = list[i];

				}
				getline(ReadList, temp[count]);
				if (temp[count] == login) {
					index = j;
				}
				count++;
				list = new string[count]; 
				for (int i = 0; i < count; i++) {
					list[i] = temp[i];
				}
				j++;
				temp = nullptr;
				delete[] temp;
			}
			ReadList.close();
			ofstream WriteList;
			WriteList.open("list.txt");
			Sleep(1000);
			if (FirstLogin == false) {
				int a = stoi(list[index + 1]);
				xp += a;
				cout << "You win " << xp << " xp" << endl;
				for (int i = 0; i < count; i++) {
					if (i == index + 1) {
						WriteList << xp << endl;
					}
					else {
						WriteList << list[i] << endl;
					}
				}
			}
			else {
				WriteList << login << endl;
				WriteList << xp << endl;
				for (int i = 0; i < count; i++) {
					WriteList << list[i] << endl;
				}
			}
			WriteList.close();
		}
	}else {
		int index = 0;
		ifstream ReadList;
		ReadList.open("list.txt");
		int count = 0;
		string* list = new string[count];
		while (!ReadList.eof()) {
			int j = 0;
			string* temp = new string[count + 1];
			for (int i = 0; i < count; i++) {
				temp[i] = list[i];

			}
			getline(ReadList, temp[count]);
			if (temp[count] == login) {
				index = j;
			}
			count++;
			list = new string[count];
			for (int i = 0; i < count; i++) {
				list[i] = temp[i];
			}
			j++;
			temp = nullptr;
			delete[] temp;
		}
		ReadList.close();
		ofstream WriteList;
		WriteList.open("list.txt");
		
		if (FirstLogin == false) {
			int a = stoi(list[index + 1]);
			xp += a;
			for (int i = 0; i < count; i++) {
				if (i == index + 1) {
					WriteList << xp << endl;
				}
				else {
					WriteList << list[i] << endl;
				}
			}
		}
		else {
			WriteList << login << endl;
			WriteList << xp << endl;
			for (int i = 0; i < count; i++) {
				WriteList << list[i] << endl;
			}
		}
		WriteList.close();
	}
	win = 0;
	xp = 0;
	}

void rules() {
	system("mode con cols=35 lines=20");
	ifstream rul;
	rul.open("rules.txt"); 
	string r;
	while (!rul.eof()) {
		r = "";
		getline(rul, r);
		cout << r<<endl;
	}
	system("pause");
	system("mode con cols=25 lines=10");
}
void randomQuiz() {
	system("mode con cols=80 lines=10");
	ifstream files;
	string name;
	files.open("random.txt");
	int count = 0;
	string* arr1 = new string[count];
	while (!files.eof()) {
		string* temp = new string[count + 1];
		for (int i = 0; i < count; i++) {
			temp[i] = arr1[i];
		}
		getline(files, temp[count]);
		delete[] arr1;
		count++;
		arr1 = new string[count];
		arr1 = temp;
		temp = nullptr;
		delete[] temp;
	}
	int index = rand() % count + 1;
	name = arr1[index];
	string txt = ".txt";
	name += txt;
	files.close();
	ifstream file;
	file.open(name);

	Quizzes quiz;
	for (int i = 0; i < QuentityQuestion; i++) {
		getline(file, quiz.query[i].question);
		for (int j = 0; j < QuentityVariants; j++) {
			getline(file, quiz.query[i].option[j].variants);
			if (j == QuentityVariants - 1) {
				string TrueVar;
				getline(file, TrueVar);
				for (int g = 0; g < QuentityVariants; g++) {
					if (quiz.query[i].option[g].variants == TrueVar) {
						quiz.query[i].option[g].trueVariants = true;
					}
					else {
						quiz.query[i].option[g].trueVariants = false;
					}
				}
			}

		}
	}
	LogicGame(quiz,name);
}
void outputQuizzer(int a) {
	ifstream files;
	string name;
	int achion = 0;
	if (a == 1) {
		files.open("nameQuizzerProgramming.txt");
	}
	else if (a == 2) {
		files.open("nameQuizzerAdministration.txt");
	}
	else if (a == 3) {
		files.open("nameQuizzerLife.txt");
	}
	
	
	int count = 0;
	string* arr1 = new string[count];
	while (!files.eof()) {
		string* temp = new string[count + 1];
		for (int i = 0; i < count; i++) {
			temp[i] = arr1[i];
		}
		getline(files, temp[count]);
		delete[] arr1;
		count++;
		arr1 = new string[count];
		for (int i = 0; i < count; i++) {

		arr1[i] = temp[i];
		}
		temp = nullptr;
		delete[] temp;
	}
	string* temp = new string[count + 1];
	for (int i = 0; i < count; i++) {
		temp[i] = arr1[i];
	}
	count++;
	arr1 = new string[count];
	temp[count-1] = "back";
	for (int i = 0; i < count; i++) {

		arr1[i] = temp[i];
	}
	while (a != 13) {
		system("cls");
		for (int i = 0; i < count; i++) {
			if (i == achion) {
				SetColor(0, 14);
			}
			if (i != achion) {
				SetColor(0, 15);
			}
			cout << arr1[i] << endl;
			SetColor(0, 15);
		}
		
		a = _getch();
		if (a == 119) {
			achion--;
			if (achion < 0) {
				achion = count;
			}
		}
		else if (a == 115) {
			achion++;
			if (achion > count) {
				achion = 0;
			}
		}
	}
	
	

	
	if (achion != count-1) {
		Clear;
		system("mode con cols=80 lines=10");
		string txt = ".txt";
		string n = arr1[achion] + txt;
		files.close();
		files.open(n);
		name = n;
		count = 0;
		string* arr2 = new string[count];
		Quizzes quiz;
		for (int i = 0; i < QuentityQuestion; i++) {
			getline(files, quiz.query[i].question);
			for (int j = 0; j < QuentityVariants; j++) {
				getline(files, quiz.query[i].option[j].variants);
				if (j == QuentityVariants - 1) {
					string TrueVar;
					getline(files, TrueVar);
					for (int g = 0; g < QuentityVariants; g++) {
						if (quiz.query[i].option[g].variants == TrueVar) {
							quiz.query[i].option[g].trueVariants = true;
						}
						else {
							quiz.query[i].option[g].trueVariants = false;
						}
					}
				}

			}
		}

		LogicGame(quiz, name);
	}
}
void List() {
	int achion = 1;
	while (achion != 7) {
		string list[] = {
			"List group quiz",
			"1.Programming",
			"2.Administration",
			"3.Life quiz",
			"4.Random quiz",
			"5.List statik users",
			"6.Rules" ,
			"7.EXIT" 
		};
			
		int a = 0;
		while (a != 13) {
			system("cls");
			for (int i = 0; i < 8; i++) {
				if (i == achion ) {
					SetColor(0, 14);
				}
				if (i != achion ) {
					SetColor(0, 15);
				}
				cout << list[i] << endl;
				SetColor(0, 15);
			}
			a = _getch();
			if (a == 119) {
				achion--;
				if (achion < 1) {
					achion = 7;
				}
			}
			else if (a == 115) {
				achion++;
				if (achion > 8) {
					achion = 1;
				}
			}
		}
		Clear;
		if (achion > 0 && achion < 4) {
			outputQuizzer(achion);
		}
		else if (achion == 4) {
			randomQuiz();
		}
		else if (achion == 5) {
			ifstream List;
			List.open("list.txt");
			while (!List.eof()) {
				string log = "";
				string xp = "";
				getline(List, log);
				getline(List, xp);
				if (log != "") {
					cout << log << " - " << xp << endl;
				}
			}
			system("pause");
		}else if (achion == 6) {
			rules();
		}
	}	
}
void Login() {
	system("title Game Quiz");
	SetColor(0, 15);
	system("mode con cols=25 lines=10");
	string password;
	cout << endl;
	cout << "\t  LOGIN" << endl;
	cout << "\t ";
	cin >> login;
	cout << "\t PASSWORD" << endl;	
	cout << "\t ";
	cin >> password;
	ifstream singIn;
	singIn.open("D:\\Study IT STEP academy\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\users\\login.txt");
	Clear;
	bool isTrueLogin = false;
	bool isTruePassword = false;
	while (!singIn.eof()) {
		isTrueLogin = false;
		isTruePassword = false;
		string l;
		string p;
		getline(singIn,l);
		getline(singIn, p);
		if (l == login) {
			isTrueLogin = true;
			if (p == password) {
				isTruePassword = true;
			}
			break;
		}
		
		if (isTrueLogin == false) {
			FirstLogin = true;
		}
		if (isTruePassword == true && isTrueLogin == true) {
			SingIn = true;
		}		
		List();
	}
	singIn.close();
	if (SingIn == true) {
		ofstream SingAdd;
		SingAdd.open("D:\\Study IT STEP academy\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\users\\login.txt", ofstream::app);
		SingAdd << endl;
		SingAdd <<login<<endl;
		SingAdd << password << endl;
		SingAdd.close();
		string str2 = "D:\\Study IT STEP academy\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\users\\"+login+".txt";
		SingAdd.open(str2, ofstream::app);
		SingAdd.close();
		FirstLogin = true;

	}if (isTrueLogin == true && isTruePassword == false) {
		system("mode con cols=30 lines=10");
		system("cls");
		SetColor(4, 15);
		cout<<"You enter incorect password "<<endl;
		Sleep(2000);
		SetColor(0, 15);
		Login();
	}
	else {
		List();
	}
	
	Clear;
}

int main() {
	srand(time(NULL));
	Login();

	return 0;
}