#pragma once
#include"Questions.h"

/// <summary>
/// Header struct with array question
/// </summary>
struct Quizzes
{
	int QuentityQuestion = 10;
	string name;
	bool SingIn = false;
	string login;
	bool FirstLogin = false;
	bool bigGame = false;
	bool BigWin = false;
	Questions* query = new Questions[QuentityQuestion];
};