#pragma once
#include"Questions.h"

/// <summary>
/// Головна структура з масивом запитань
/// </summary>
struct Quizzes
{
	int QuentityQuestion = 10;
	Questions* query = new Questions[QuentityQuestion];
	string name;
	bool SingIn = false;
	string login;
	bool FirstLogin = false;
	bool bigGame = false;
	bool BigWin = false;
};