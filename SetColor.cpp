#include"Quizzes.h"
#include"windows.h"
/// <summary>
/// Функція для зміну кольору тексту і фону 
/// </summary>
/// <param name="text"></param>
/// <param name="bg"></param>
void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}