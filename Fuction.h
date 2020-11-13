#pragma once
#include"Quizzes.h"
#include<string>
#include<fstream>
#include"windows.h"
#include<cstdlib>
#define Clear system("cls");




void SetColor(int text, int bg);
void BigGame( Quizzes quiz, string name);
void LogicGame(Quizzes quiz, string name);
void outputQuizzer(int a);
void List();
void Login(Quizzes quiz);
void rules();
void randomQuiz(Quizzes quiz);
void InvisibleСursor(bool $CCI);