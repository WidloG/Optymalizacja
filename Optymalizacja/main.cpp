/*********************************************
Kod stanowi uzupe³nienie materia³ów do æwiczeñ
w ramach przedmiotu metody optymalizacji.
Kod udostêpniony na licencji CC BY-SA 3.0
Autor: dr in¿. £ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia Górniczo-Hutnicza
*********************************************/
//checking

#include"opt_alg.h"
#include"user_funs.h"

void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
void lab6();

int main()
{
	try
	{
		lab1();
	}
	catch (string EX_INFO)
	{
		cerr << "ERROR:\n";
		cerr << EX_INFO << endl << endl;
	}
	system("pause");
	return 0;
}

void lab1()
{
	double* p = new double[2];
	solution fibbobibo[100];
	solution laga[100];
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		double x0 = rand() % 1001 + 1;
		p = expansion(&f_celu, x0, 1, 2.5, 1000, 0, 0);
		cout << x0 << "," << p[0] << "," << p[1] << endl;
		fibbobibo[i] =  fib(f_celu, p[0], p[1], 0.00001, 0, 0);
		laga[i] = lag(f_celu, p[0], p[1], 0.00001, 1e-7, 0, 0);
	}
	cout << "FIBBOBIBO" << endl;
	for (int i = 0; i < 100; i++)
	{
		//cout << fibbobibo[i] << endl;
		cout << fibbobibo[i].x << "," << fibbobibo[i].y << "," << fibbobibo[i].f_calls << "," << endl;
	}

	//p = expansion(&f_celu, 100.0, 1.0, 2.0, 1000, 0, 0);
	//cout << p[0] << endl << p[1] << endl;

	/*for (int i = 0; i < 100; i++)
	{
		cout << fib(f_celu, p[0], p[1], 0.00001, 0, 0);
	}*/
}

void lab2()
{

}

void lab3()
{

}

void lab4()
{

}

void lab5()
{

}

void lab6()
{

}
