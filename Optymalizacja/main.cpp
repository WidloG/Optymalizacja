/*********************************************
Kod stanowi uzupe�nienie materia��w do �wicze�
w ramach przedmiotu metody optymalizacji.
Kod udost�pniony na licencji CC BY-SA 3.0
Autor: dr in�. �ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia G�rniczo-Hutnicza
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

	double x0 = -17.2134, d = 1.1, epsilon = 0.00001, gamma = 1e-200, Nmax = 1000;

	double* p = new double[2];
	solution fibbobibo[100];
	solution laga[100];
	solution opt;
	matrix min1 = 1000;
	matrix min2 = 1000;
	srand(time(NULL));

	//for (int i = 0; i < 100; i++){
	//	p = expansion(&f_celu, x0, 1, 1.25, 1000, 0, 0);
	//	//cout << x0 << "," << p[0] << "," << p[1];
	//	/*solution::clear_calls();
	//	fibbobibo[i] =  fib(f_celu, p[0], p[1], epsilon, 0, 0);
	//	cout << fibbobibo[i].f_calls << endl;*/
	//	solution::clear_calls();
	//	laga[i] = lag(f_celu, p[0], p[1], epsilon, gamma, Nmax, 0, 0);
	//	cout << fibbobibo[i].f_calls << endl;
	//	x0 += d;
	//}

	//cout << "\n\nFIBONACCI\n\n" << endl;
	//for (int i = 0; i < 100; i++){
	//	cout << fibbobibo[i].x << "," << fibbobibo[i].y << "," << fibbobibo[i].f_calls << ",";
	//	if (min1 > fibbobibo[i].y) min1 = fibbobibo[i].y;
	//	cout << min1 << endl;
	//}
	////solution::clear_calls();
	//cout << "\n\nLAGRANGE'A\n\n" << endl;
	//for (int i = 0; i < 100; i++){
	//	cout << laga[i].x << "," << laga[i].y << "," << laga[i].f_calls << ",";
	//	if (min2 > laga[i].y) min2 = laga[i].y;
	//	cout << min2 << endl;
	//}
	//
	epsilon = 1e-10;
	opt = fib(fR, 1e-4, 1e-2, epsilon);
	cout << opt << endl;
	opt = lag(fR, 1e-4, 1e-2, epsilon, gamma, Nmax);
	cout << opt << endl << endl;
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
