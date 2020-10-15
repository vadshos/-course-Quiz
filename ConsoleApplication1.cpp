#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include <sstream> 
#include"windows.h"
#include <cstdlib>
#define Clear system("cls");

using namespace std;
int QuentityVariants = 4;
int QuentityQuizzes = 2;
int QuentityQuestion = 10;
bool SingIn = false;
string login;
bool bigGame = true;
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
		cout << "You win big game my 	greeting";
	}
	Sleep(2000);
	Clear;
}

void LogicGame(Quizzes quiz,string name) {
	int xp = 0;
	for (int j = 0; j < QuentityQuestion; j++)
	{
		cout << quiz.query[j].question << endl;
		for (int i = 0; i < QuentityVariants; i++)
		{
			cout << quiz.query[j].option[i].variants << endl;			
		}
		SetColor(5, 15);
		cout << "True options " << win << "/10" << endl;
		SetColor(15, 0);
		int achion;
		cout << "Enter option-> ";
		cin >> achion;
		int index = 0;
		bool wins = false;
		if (quiz.query[j].option[achion - 1].trueVariants == true) {
			win++;
			wins = true;
			index = achion-1;
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
		cout << quiz.query[j].question << endl;
		bool IsTrue = false;					
				if (wins == false) {
					for (int i = 0; i < QuentityVariants; i++) {
						if (i == index) {
							SetColor(2, 0);
						}else if(i == achion-1){
							SetColor(4, 0);
						}
						else {
							SetColor(15, 0);
						}
						cout << quiz.query[j].option[i].variants << endl;
						SetColor(15, 0);
					}
				}
				else {
					for (int i = 0; i < QuentityVariants; i++)
					{
						if (i == index) {
							SetColor(2, 0);
						}
						else {
							SetColor(15, 0);
						}
					cout << quiz.query[j].option[i].variants << endl;
					SetColor(15, 0);
					}
				}
				Sleep(1500);
				Clear;
			SetColor(15, 0);	
	}
	ifstream ListAdd;
	int count = 0;
	string* arr1 = new string[count+1];
	ListAdd.open("list.txt", ofstream::app);
	while (!ListAdd.eof()) {
		string* temp = new string[count + 1];
		for (int i = 0; i < count; i++) {
			temp[i] = arr1[i];
		}
		getline(ListAdd, temp[count]);
		delete[] arr1;
		count++;
		arr1 = new string[count];
		for (int i = 0; i < count; i++) {
		arr1[i] = temp[i];
		}
		temp = nullptr;
		delete[] temp;
	}
	ListAdd.close();
	SetColor(5, 15);
	cout<<"True options " << win<<"/10"<<endl;
	SetColor(15, 0);
	cout << endl;
	if (win > 7) {
		cout << "Do you want to play a big game, win multiply your winnings twice lose lose your winnings.1.yes 2.no " << endl;
		int  achion = 0;
		cin >> achion;
		if (achion == 1) {
			BigGame(name);
		}
	}
	if (bigGame == true&&BigWin == true) {
		int index = -1;
		for (int i = 0; i < (count * 2) + 1; i++) {
			if (arr1[i] == login) {
				index = i;
			}
		}
		stringstream geek(arr1[index + 2]);
		int a = 0;
		geek << a;
		xp += a;
		cout << "You win " << xp << "xp"<<endl;
		xp*=2;
		cout << "And with x2 bonus you win " << xp << "xp";

		ofstream List;
		List.open("list.txt");
		for (int i = 0; i < count; i++) {
			if (i == index) {
				List << arr1[i] << endl;
				List << xp << endl;
				i++;
			}
			else {
				List << arr1[i] << endl;
			}
		}
		if (index == -1) {
			for (int i = 0; i < count; i++) {
				if (i == count - 1) {
					List << login << endl;
					List << xp << endl;
					i++;
				}
				else {
					List << arr1[i] << endl;
				}
			}
		}
		List.close();
	}else if (bigGame == false ) {
		int index = -1;
		for (int i = 0; i < (count * 2) + 1; i++) {
			if (arr1[i] == login) {
				index = i;
			}
		}
		stringstream geek(arr1[index + 2]);
		int a = 0;
		geek << a;
		xp += a;
		ofstream List;
		List.open("list.txt");
		for (int i = 0; i < count; i++) {
			if (i == index) {
				List << arr1[i] << endl;
				List << xp << endl;
				i++;
			}
			else {
				List << arr1[i] << endl;
			}
		}
		if (index == -1) {
			for (int i = 0; i < count; i++) {
				if (i == count - 1) {
					List << login << endl;
					List << xp << endl;
					i++;
				}
				else {
					List << arr1[i] << endl;
				}
			}
		}
		List.close();
	}
	else if(bigGame == true && BigWin != true){
		int index = -1;
		for (int i = 0; i < (count * 2) + 1; i++) {
			if (arr1[i] == login) {
				index = i;
			}
		}

		
		xp = 0;
		cout << "You win " << xp << "xp because you lose in big game";


		ofstream List;
		List.open("list.txt");
		for (int i = 0; i < count; i++) {
			if (i == index) {
				List << arr1[i] << endl;
				List << xp << endl;
				i++;
			}

			else {
				List << arr1[i] << endl;
			}
		}
		if (index == -1) {
			for (int i = 0; i < count; i++) {
				if (i == count - 1) {
					List << login << endl;
					List << xp << endl;
					i++;
				}

				else {
					List << arr1[i] << endl;
				}
			}
		}
		List.close();
	}
}
void randomQuiz() {
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
		arr1 = temp;
		temp = nullptr;
		delete[] temp;
	}
	for (int i = 0; i < count; i++) {
		cout<<"" << i + 1 << ". " << arr1[i] << endl;
	}
	cout << "Enter number quizeer-> ";
	cin >> achion;
	Clear;
	system("mode con cols=80 lines=10");
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
	LogicGame(quiz,name);
}
void List() {
	int achion = 0;
	while (achion != 6) {
		cout << "List group quiz" << endl;
		cout << "1.Programming" << endl;
		cout << "2.Administration" << endl;
		cout << "3.Life quiz" << endl;
		cout << "4.Random quiz" << endl;
		cout << "5.List statik users" << endl;
		cout << "6.EXIT" << endl;
		cout << "Enter achion-> ";		
		cin >> achion;
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
				if (log != "" && xp != "") {
				cout << log << " - " << xp << endl;
				}
			}
		}
	}	
}
void Login() {
	system("mode con cols=25 lines=10");
	string password;
	cout << "\tLOGIN" << endl;
	cout << "\t ";
	cin >> login;
	cout << "\tPASSWORD" << endl;	
	cout << "\t";
	cin >> password;
	ifstream singIn;
	singIn.open("D:\\Study IT STEP academy\\Новая папка\\ConsoleApplication1\\ConsoleApplication1\\users\\login.txt");
	Clear;
	
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
	
	Clear;
}

int main() {
	srand(time(NULL));
	Login();

	return 0;
}