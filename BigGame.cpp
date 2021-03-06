#include"Quizzes.h"
#include "Fuction.h"
#include<conio.h>

/// <summary>
/// Outputs additional game,   if user answered true 7 and hight 
/// </summary>
/// <param name="quiz">struct quiz</param>
/// <param name="name">name quiz</param>
void BigGame(Quizzes quiz, string name) {
	SetColor(0, 15);
	ifstream files;
	string TemoVariable = "BigGame\\BigGame";
	string options;
	TemoVariable += name;
	files.open(TemoVariable);
	TemoVariable = "";
	getline(files, TemoVariable);
	cout << TemoVariable;
	getline(files, TemoVariable);
	cout << "correct answer-> ";
	cin >> options;
	if (options == TemoVariable) {
		quiz.BigWin = true;
		cout << "You win big game my greeting";
	}
	Sleep(2000);
	Clear;
}

/// <summary>
/// Logic game
/// </summary>
/// <param name="quiz">struct quiz</param>
/// <param name="name">name quiz</param>
void LogicGame(Quizzes quiz, string name)
{
	int win = 0;
	int xp = 0;
	int achion = 0;
	int* UsedNumber = new int[quiz.QuentityQuestion];
	int* ArrayforWriteData = new int[10];
	int  k = 0;
	while (k != 10) {
		int j = 0;

		while (true) {
			j = rand() % 10;
			bool isTrue = true;
			for (int i = 0; i < 10; i++) {
				if (j == ArrayforWriteData[i]) {
					isTrue = false;
				}
			}
			ArrayforWriteData[k] = j;
			if (isTrue == true) {
				k++;
				break;
			}
		}

	}
	for (int g = 0; g < quiz.QuentityQuestion; g++)
	{
		int j = ArrayforWriteData[g];
		int a = 0;
		while (a != 13) {
			system("cls");
			cout << quiz.query[j].question << endl;
			for (int i = 0; i < quiz.query[g].QuentityVariants; i++) {
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
					achion = quiz.query[g].QuentityVariants - 1;
				}
			}
			else if (a == 115) {
				achion++;
				if (achion > quiz.query[g].QuentityVariants - 1) {
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
			xp += (100 + rand() % 100) * (j + 1);
		}
		else {
			for (int k = 0; k < quiz.query[k].QuentityVariants; k++) {
				if (quiz.query[j].option[k].trueVariants == true) {
					index = k;
				}
			}
		}
		Clear;
		SetColor(0, 15);
		cout << quiz.query[j].question << endl;
		bool IsTrue = false;
		if (wins == false) {
			for (int i = 0; i < quiz.query[g].QuentityVariants; i++) {
				if (i == index) {
					SetColor(2, 15);
				}
				else if (i == achion) {
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
			for (int i = 0; i < quiz.query[g].QuentityVariants; i++)
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
	cout << "True options " << win << "/10" << endl;
	SetColor(0, 15);
	cout << endl;
	if (win > 0) {
		cout << "Do you want to play a big game, win multiply your winnings twice lose lose your winnings.1.yes 2.no " << endl;
		int  achion = 0;
		cin >> achion;
		if (achion == 1) {
			quiz.bigGame = true;
			BigGame(quiz, name);
			if (quiz.BigWin == true) {
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
					if (temp[count] == quiz.login) {
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

				if (quiz.BigWin == true) {
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
					WriteList << quiz.login << endl;
					WriteList << xp << endl;
					for (int i = 0; i < count; i++) {
						WriteList << list[i] << endl;

					}
				}
				WriteList.close();
			}
			else if(quiz.BigWin == false&& quiz.bigGame == true){
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
					if (temp[count] == quiz.login) {
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
				xp = 0;
				cout << "You win 0 xp because you lose big game" << endl;
				Sleep(1000);
				if (quiz.FirstLogin == false) {
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
					WriteList << quiz.login << endl;
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
				if (temp[count] == quiz.login) {
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
			if (quiz.FirstLogin == false) {
				int previosXp = stoi(list[index + 1]);
				xp += previosXp;
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
				WriteList << quiz.login << endl;
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
			if (temp[count] == quiz.login) {
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

		if (quiz.FirstLogin == false) {
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
			WriteList << quiz.login << endl;
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

/// <summary>
/// Function for check rand quiz
/// </summary>
/// <param name="quiz">struct quiz</param>
void randomQuiz(Quizzes quiz) {
	system("mode con cols=80 lines=10");
	ifstream files;
	string name;
	files.open("random.txt");
	int count = 0;
	string* ArrayForQuiz = new string[count];
	while (!files.eof()) {
		string* temp = new string[count + 1];
		for (int i = 0; i < count; i++) {
			temp[i] = ArrayForQuiz[i];
		}
		getline(files, temp[count]);
		delete[] ArrayForQuiz;
		count++;
		ArrayForQuiz = new string[count];
		ArrayForQuiz = temp;
		temp = nullptr;
		delete[] temp;
	}
	int index = rand() % count + 1;
	name = ArrayForQuiz[index];
	string txt = ".txt";
	name += txt;
	files.close();
	ifstream file;
	file.open(name);


	for (int i = 0; i < quiz.QuentityQuestion; i++) {
		getline(file, quiz.query[i].question);
		for (int j = 0; j < quiz.query[i].QuentityVariants; j++) {
			getline(file, quiz.query[i].option[j].variants);
			if (j == quiz.query[i].QuentityVariants - 1) {
				string TrueVar;
				getline(file, TrueVar);
				for (int g = 0; g < quiz.query[i].QuentityVariants; g++) {
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

/// <summary>
/// Function for output rules quiz 
/// </summary>
void rules() {
	system("mode con cols=35 lines=20");
	ifstream rul;
	rul.open("rules.txt");
	string stringRul;
	while (!rul.eof()) {
		stringRul = "";
		getline(rul, stringRul);
		cout << stringRul << endl;
	}
	system("pause");
	system("mode con cols=25 lines=10");
}

/// <summary>
/// Function for output name quiz by category
/// </summary>
/// <param name="a">name category</param>
void outputQuizzer(int a) {
	ifstream files;
	string name;
	int achion = 0;
	if (a == 1) {
		files.open("NameQuiz\\nameQuizzerProgramming.txt");
	}
	else if (a == 2) {
		files.open("NameQuiz\\nameQuizzerAdministration.txt");
	}
	else if (a == 3) {
		files.open("NameQuiz\\nameQuizzerLife.txt");
	}


	int count = 0;
	string* arryForWriteData = new string[count];
	while (!files.eof()) {
		string* temp = new string[count + 1];
		for (int i = 0; i < count; i++) {
			temp[i] = arryForWriteData[i];
		}
		getline(files, temp[count]);
		delete[] arryForWriteData;
		count++;
		arryForWriteData = new string[count];
		for (int i = 0; i < count; i++) {

			arryForWriteData[i] = temp[i];
		}
		temp = nullptr;
		delete[] temp;
	}
	string* temp = new string[count + 1];
	for (int i = 0; i < count; i++) {
		temp[i] = arryForWriteData[i];
	}
	count++;
	arryForWriteData = new string[count];
	temp[count - 1] = "back";
	for (int i = 0; i < count; i++) {

		arryForWriteData[i] = temp[i];
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
			cout << arryForWriteData[i] << endl;
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




	if (achion != count - 1) {
		Clear;
		system("mode con cols=80 lines=10");
		string txt = ".txt";
		string SecondName = arryForWriteData[achion] + txt;
		files.close();
		files.open("Quiz\\"+SecondName);
		name = SecondName;
		count = 0;
		string* arr2 = new string[count];
		Quizzes quiz;
		for (int i = 0; i < quiz.QuentityQuestion; i++) {
			getline(files, quiz.query[i].question);
			for (int j = 0; j < quiz.query[i].QuentityVariants; j++) {
				getline(files, quiz.query[i].option[j].variants);
				if (j == quiz.query[i].QuentityVariants - 1) {
					string TrueVar;
					getline(files, TrueVar);
					for (int g = 0; g < quiz.query[i].QuentityVariants; g++) {
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

/// <summary>
/// Function for output list category quiz
/// </summary>
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
				if (i == achion) {
					SetColor(0, 14);
				}
				if (i != achion) {
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
			Quizzes quiz;
			randomQuiz(quiz);
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
		}
		else if (achion == 6) {
			rules();
		}
	}
}

/// <summary>
/// Fuction login/registration user
/// </summary>
/// <param name="quiz">struct quiz</param>
void Login(Quizzes quiz) {
	system("title Game Quiz");
	SetColor(0, 15);
	system("mode con cols=25 lines=10");
	string password;
	cout << endl;
	cout << "\t  LOGIN" << endl;
	cout << "\t ";
	cin >> quiz.login;
	cout << "\t PASSWORD" << endl;
	cout << "\t ";
	cin >> password;
	ifstream singIn;
	singIn.open("C:\\Users\\VS\\source\\repos\\My cours c++\\My cours c++\\users\\login.txt");
	Clear;
	bool isTrueLogin = false;
	bool isTruePassword = false;
	while (!singIn.eof()) {
		isTrueLogin = false;
		isTruePassword = false;
		string l;
		string p;
		getline(singIn, l);
		getline(singIn, p);
		if (l == quiz.login) {
			isTrueLogin = true;
			if (p == password) {
				isTruePassword = true;
			}
			break;
		}

		if (isTrueLogin == false) {
			quiz.FirstLogin = true;
		}
		if (isTruePassword == true && isTrueLogin == true) {
			quiz.SingIn = true;
		}
		List();
	}
	singIn.close();
	if (quiz.SingIn == true) {
		ofstream SingAdd;
		SingAdd.open("users\\login.txt", ofstream::app);
		SingAdd << endl;
		SingAdd << quiz.login << endl;
		SingAdd << password << endl;
		SingAdd.close();
		string str2 = "users" + quiz.login + ".txt";
		SingAdd.open(str2, ofstream::app);
		SingAdd.close();
		quiz.FirstLogin = true;

	}if (isTrueLogin == true && isTruePassword == false) {
		system("mode con cols=30 lines=10");
		system("cls");
		SetColor(4, 15);
		cout << "You enter incorect password " << endl;
		Sleep(2000);
		SetColor(0, 15);
		Login(quiz);
	}
	else {
		List();
	}

	Clear;
}