#pragma once
#include"Options.h"
/// <summary>
/// Структура запитань з масивом відповідей і запитанням 
/// </summary>
struct Questions
{
	int QuentityVariants = 4;
	Options* option = new Options[QuentityVariants];
	string question;

};