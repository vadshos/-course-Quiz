#pragma once
#include"Options.h"
struct Questions
{
	int QuentityVariants = 4;
	Options* option = new Options[QuentityVariants];
	string question;

};