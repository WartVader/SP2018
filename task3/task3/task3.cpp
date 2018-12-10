// task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
	int i = 0;

	time_t Time = 0;// для sub и add
	time_t Time1 = 0, Time2 = 0; // для diff

	int operation = 0, aTime = 0;
	//cout << argv[0] << ' ' << argv[1] << ' ' << argv[2] << ' ';
	if (!strcmp(argv[1], "add") || !strcmp(argv[1], "sub")) {
		Time = atoi(argv[3]);
		if (!strcmp(argv[2], "day"))
			Time *= 60 * 60 * 24;
		else if (!strcmp(argv[2], "hour"))
			Time *= 60 * 60;
		else if (!strcmp(argv[2], "min"))
			Time *= 60;
		else cout << "Wrong time (use only day, hour, min, sec)";
	}
		
	time_t timer = 0;
	struct tm *today = 0;
	
	if (!strcmp(argv[1], "add")) {
		time(&timer);
		timer += Time;
		today = localtime(&timer); 
		cout << asctime(today); 
	}
	else if (!strcmp(argv[1], "sub")) {
		time(&timer);
		timer -= Time;
		today = localtime(&timer); 
		cout << asctime(today); 
	}
	else if (!strcmp(argv[1], "diff")) {
		for (i = 2; i < argc; i++) {
			int hour = 0, min = 0, sec = 0; 
			//Далее идет запись в вышеперечисленные переменные и проверка шаблона
			if (sscanf(argv[i], "%2d:%2d:%2d", &hour, &min, &sec) != 3 || strlen(argv[i]) != 8 
				|| hour > 23 || min && sec > 59 || hour && min && sec < 0) {
				cout << "Wrong time format (23:59:59 - max, 00:00:00 - min)";
				return -1;
			}
			int diffsec = hour * 60 * 60 + min * 60 + sec;
			if (i == 2) Time1 = diffsec;
			else Time2 = diffsec;
		}
		timer = abs(Time1 - Time2);
		cout << timer << endl;
	}
	if (timer < 0) { //Если меньше, чем 00 1 января 1970 года - выход
		cout << "Can't get result" << endl;
		return -1;
	}
	



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
