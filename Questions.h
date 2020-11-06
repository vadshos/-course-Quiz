#pragma once
#include"Options.h"
/// <summary>
/// Struct with question and array options
/// </summary>
struct Questions
{
	int QuentityVariants = 4;
	Options* option = new Options[QuentityVariants];
	string question;

};