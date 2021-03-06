// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <windows.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int N = 1, wait = 0;
	char *arg[] = { NULL };
	char *run[] = { NULL };
	char *maxInst = getenv("MAX_INSTANCES"); 

	if (argc < 2) {
		return -1;
	}
	*run = argv[argc - 1];
	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "-w") || !strcmp(argv[i], "--wait")) wait = 1;
		else if (!strcmp(argv[i], "-i") || !strcmp(argv[i], "--instances"))
			N = atoi(argv[++i]);
		else if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--arguments"))
			*arg = argv[++i];
	}

	HANDLE *handles = new HANDLE[N];

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));

	for (int i = 0; i < N; i++) {
		CreateProcess(run[0], arg[0], NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
		handles[i] = pi.hProcess;
	}
	if (wait == 1) WaitForMultipleObjects(N, handles, TRUE, INFINITE);
	return 1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
