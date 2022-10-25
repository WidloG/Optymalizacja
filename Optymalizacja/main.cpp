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
	p = expansion(&f_celu, -10, 1, 1.5, 1000, 0, 0);
	cout << p[0] << endl << p[1] << endl;
	//p = exception(&f_celu, -100, 1, 1.5, 1000, 0, 0);
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
