﻿#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include <sstream> 
#include"windows.h"


using namespace std;
int QuentityVariants = 4;
int QuentityQuizzes = 2;
int QuentityQuestion = 10;
bool SingIn = false;
int win = 0;
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}
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

void LogicGame(Quizzes quiz) {
	for (int j = 0; j < 10; j++)
	{

		cout << quiz.query[j].question << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << quiz.query[j].option[i].variants << endl;
			
		}
		int achion;
		cout << "Enter option-> ";
		cin >> achion;
		if (quiz.query[j].option[achion - 1].trueVariants == true) {
			win++;
		}

	}
	cout << win;
}
void randomQuiz() {
	ifstream files;
	string name;
	files.open("nameQuizzer.txt");
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
	files.open(name);

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
	LogicGame(quiz);
}
void addingNewQuizzer(string* name) {
	ofstream file;
	string txt = ".txt";
	file << name << endl;
	file.open("nameQuizzer.txt");//typing name in list quizzer
	file << *name << endl;
	*name += txt;
	file.close();
	file.open(*name);
	int math = QuentityQuestion * QuentityVariants + QuentityVariants + 1;
	string* str = new string[math];
	int var = 0;
	int counts = 0;
	for (int i = 0; i < QuentityQuestion; i++) {
		cout << "Enter qustion  -> ";
		cin.ignore();
		getline(cin, str[counts]);
		counts++;
		bool isTrue = false;
		string IsTrue = "";
		int VarForRetype = counts;
		for (int j = 0; j < QuentityVariants; j++) {
			cout << "Enter options  -> ";
			cin.ignore();
			getline(cin, str[counts]);
			counts++;
			if (isTrue == false) {
				int achion = 0;
				cout << "This is true options (1. yes 2. no) -> ";
				cin >> achion;
				if (achion == 1) {
					counts--;
					var = counts;
					IsTrue = str[counts];
					counts++;
					isTrue = true;
				}
			}
		}
		if (IsTrue == "") {
			cout << "You didn't choise true options\n 1. retype \n 2. choise true options  ";
			int achion;
			cin >> achion;
			if (achion == 1) {
				for (int j = 0; j < QuentityVariants; j++) {
					cout << str[i] << endl;
					cin.ignore();
					string str2;
					getline(cin, str[i]);
					if (isTrue == false) {
						int achion = 0;
						cout << "This is true options (1. yes 2. no) -> ";
						cin >> achion;
						if (achion == 1) {
							counts--;
							str[var] = str[i];
							counts++;
							isTrue = true;
						}
					}
				}
			}
			else {
				for (int k = VarForRetype; k < (VarForRetype + QuentityVariants); k++) {
					cout << str[k] << endl;
					cin.ignore();
					string str2;
					getline(cin, str[i]);
					if (isTrue == false) {
						int achion = 0;
						cout << "This is true options (1. yes 2. no) -> ";
						cin >> achion;
						if (achion == 1) {

							str[var] = str[i];
							isTrue = true;
						}
					}
				}
			}
		}
		else {
			str[counts] = IsTrue;
		}
	}


	file << QuentityQuestion << endl;
	file << QuentityVariants << endl;
	QuentityQuizzes++;
	for (int i = 0; i < math; i++) {

		file << str[i] << endl;
	}
	file.close();
	delete[] str;

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
		arr1 = temp;
		temp = nullptr;
		delete[] temp;
	}
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << arr1[i] << endl;
	}
	cout << "Enter number quizeer-> ";
	cin >> achion;
	string txt = ".txt";
	name = arr1[achion - 1];
	name += txt;
	files.close();
	files.open(name);
	count = 0;
	string* arr2 = new string[count];
	

	Quizzes quiz;
	for (int i = 0; i < QuentityQuestion; i++) {
		getline(files, quiz.query[i].question);
		for (int j = 0; j < QuentityVariants;j++) {
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
	LogicGame(quiz);
}
void List() {
	cout << "List group quiz" << endl;
	cout << "1.Programming" << endl;
	cout << "2.Administration" << endl;
	cout << "3.Life quiz" << endl;
	cout << "4.Random quiz" << endl;
	if (SingIn == true) {
		cout << "5.Your quiz" << endl;
		cout << "6.List statik users" << endl;
	}
	else {
	cout << "5.List statik users" << endl;
	}
	int achion = 0;
	cout << "Enter achion-> ";
	cin >> achion;
	if (achion > 0 && achion < 4) {
		outputQuizzer(achion);
	}
	else if (achion == 4) {

	}
	else if (achion == 5) {

	}
	else if (achion == 6) {

	}
}

void Login() {
	string login;
	string password;
	cout << "LOGIN" << endl;
	cin >> login;
	cout << "PASSWORD" << endl;
	cin >> password;
	ifstream singIn;
	singIn.open("D:\\Study IT STEP academy\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\users\\login.txt");
	
	while (!singIn.eof()) {
		bool isTrueLogin = false;
		bool isTruePassword = false;
		string l;
		string p;
		getline(singIn,l);
		getline(singIn, p);
		if (l == login) {
			isTrueLogin = true;
		}
		if (p == password) {
			isTruePassword = true;
		}
		if (isTruePassword == true && isTrueLogin == true) {
			SingIn = true;
		}
		List();


	}
	singIn.close();
	if (SingIn == false) {
		ofstream SingAdd;
		SingAdd.open("D:\\Study IT STEP academy\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\users\\login.txt", ofstream::app);
		SingAdd << endl;
		SingAdd <<login<<endl;
		SingAdd << password;
		SingAdd.close();
		string str2 = "D:\\Study IT STEP academy\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\users\\"+login+".txt";
		SingAdd.open(str2, ofstream::app);
		SingAdd.close();
	}
	
	system("cls");
	

}

int main() {
	
	Login();


	return 0;
}