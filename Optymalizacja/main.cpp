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
		//lab1();
		lab2();
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

//void lab2(){
//
//	solution hj[100];
//	matrix x0 = matrix(2, 1, 0.75);
//	//solution wynik = HJ(f_celu2, x0, 0.5, 0.5, 0.001, 1000, 0, 0);
//	//cout << wynik << endl;
//	HJ(f_celu2, x0, 0.5, 0.5, 0.001, 1000, 0, 0);
//
//}

void lab2()
{
	ofstream zapis("Dane.txt");
	//Funkcja testowa
	double s = 3.77, alphaHJ = 0.5, alphaR = 2, beta = 0.5, epsilon = 1e-3;
	int Nmax = 1000;
	solution opt;
	matrix x0, s0;
	s0 = matrix(2, 1, s);

	cout << x0 << endl << endl;
	int i = 100;
	while (i > 0) {
		x0 = 2 * rand_mat(2, 1) - 1;
		/*opt = HJ(ff2T, x0, s, alphaHJ, epsilon, Nmax);
		zapis << x0(0) << ";" << x0(1) << ";" << opt.x(0) << ";" << opt.x(1) << ";" << opt.y << ";" << opt.f_calls << endl;
		solution::clear_calls();*/
		opt = Rosen(ff2T, x0, s0, alphaR, beta, epsilon, Nmax);
		zapis << opt.x(0) << "\t" << opt.x(1) << "\t" << opt.y << "\t" << opt.f_calls << endl;
		solution::clear_calls();
		i--;
	}

	//Ramie robota
	//s = 0.75;
	//x0 = 10 * rand_mat(2, 1);
	//cout << x0 << endl << endl;
	///*opt = HJ(ff2R, x0, s, alphaHJ, epsilon, Nmax);
	//cout << opt << endl << endl;
	//solution::clear_calls();*/
	//opt = Rosen(ff2R, x0, s0, alphaR, beta, epsilon, Nmax);
	//cout << opt << endl << endl;
	//solution::clear_calls();
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
