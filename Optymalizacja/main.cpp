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
		lab6();
	}
	catch (string EX_INFO)
	{
		cerr << "ERROR:\n";
		cerr << EX_INFO << endl << endl;
	}
	system("pause");
	return 0;
}

//void lab1()
//{
//
//	double x0 = -17.2134, d = 1.1, epsilon = 0.00001, gamma = 1e-200, Nmax = 1000;
//
//	double* p = new double[2];
//	solution fibbobibo[100];
//	solution laga[100];
//	solution opt;
//	matrix min1 = 1000;
//	matrix min2 = 1000;
//	srand(time(NULL));
//
//	//for (int i = 0; i < 100; i++){
//	//	p = expansion(&f_celu, x0, 1, 1.25, 1000, 0, 0);
//	//	//cout << x0 << "," << p[0] << "," << p[1];
//	//	/*solution::clear_calls();
//	//	fibbobibo[i] =  fib(f_celu, p[0], p[1], epsilon, 0, 0);
//	//	cout << fibbobibo[i].f_calls << endl;*/
//	//	solution::clear_calls();
//	//	laga[i] = lag(f_celu, p[0], p[1], epsilon, gamma, Nmax, 0, 0);
//	//	cout << fibbobibo[i].f_calls << endl;
//	//	x0 += d;
//	//}
//
//	//cout << "\n\nFIBONACCI\n\n" << endl;
//	//for (int i = 0; i < 100; i++){
//	//	cout << fibbobibo[i].x << "," << fibbobibo[i].y << "," << fibbobibo[i].f_calls << ",";
//	//	if (min1 > fibbobibo[i].y) min1 = fibbobibo[i].y;
//	//	cout << min1 << endl;
//	//}
//	////solution::clear_calls();
//	//cout << "\n\nLAGRANGE'A\n\n" << endl;
//	//for (int i = 0; i < 100; i++){
//	//	cout << laga[i].x << "," << laga[i].y << "," << laga[i].f_calls << ",";
//	//	if (min2 > laga[i].y) min2 = laga[i].y;
//	//	cout << min2 << endl;
//	//}
//	//
//	epsilon = 1e-10;
//	opt = fib(fR, 1e-4, 1e-2, epsilon);
//	cout << opt << endl;
//	opt = lag(fR, 1e-4, 1e-2, epsilon, gamma, Nmax);
//	cout << opt << endl << endl;
//}

//void lab2(){
//
//	solution hj[100];
//	matrix x0 = matrix(2, 1, 0.75);
//	//solution wynik = HJ(f_celu2, x0, 0.5, 0.5, 0.001, 1000, 0, 0);
//	//cout << wynik << endl;
//	HJ(f_celu2, x0, 0.5, 0.5, 0.001, 1000, 0, 0);
//
//}

//void lab2()
//{
//	ofstream zapis("Dane.txt");
//	//Funkcja testowa
//	double s = 3.77, alphaHJ = 0.5, alphaR = 2, beta = 0.5, epsilon = 1e-3;
//	int Nmax = 1000;
//	solution opt;
//	matrix x0, s0;
//	s0 = matrix(2, 1, s);
//
//	cout << x0 << endl << endl;
//	int i = 100;
//	while (i > 0) {
//		x0 = 2 * rand_mat(2, 1) - 1;
//		/*opt = HJ(ff2T, x0, s, alphaHJ, epsilon, Nmax);
//		zapis << x0(0) << ";" << x0(1) << ";" << opt.x(0) << ";" << opt.x(1) << ";" << opt.y << ";" << opt.f_calls << endl;
//		solution::clear_calls();*/
//		opt = Rosen(ff2T, x0, s0, alphaR, beta, epsilon, Nmax);
//		zapis << opt.x(0) << "\t" << opt.x(1) << "\t" << opt.y << "\t" << opt.f_calls << endl;
//		solution::clear_calls();
//		i--;
//	}
//
//	//Ramie robota
//	//s = 0.75;
//	//x0 = 10 * rand_mat(2, 1);
//	//cout << x0 << endl << endl;
//	///*opt = HJ(ff2R, x0, s, alphaHJ, epsilon, Nmax);
//	//cout << opt << endl << endl;
//	//solution::clear_calls();*/
//	//opt = Rosen(ff2R, x0, s0, alphaR, beta, epsilon, Nmax);
//	//cout << opt << endl << endl;
//	//solution::clear_calls();
//}
//
//void lab3()
//{
//	ofstream zapis("Dane.txt");
//	//zapis << "\n\nProblem testowy\n\n";
//	matrix x0, a(4.4934);
//	double c_ex = 1, c_in = 10, dc_ex = 2, dc_in = 0.5, epsilon = 1e-4;
//	int Nmax = 10000;
//	solution opt;
//	int i = 100;
//	while (i > 0) {
//		do
//			x0 = 5 * rand_mat(2, 1) + 1;
//		while (norm(x0) > a);
//		opt = pen(ff3T, x0, c_ex, dc_ex, epsilon, Nmax, a);
//		zapis << x0(0) << "\t" << x0(1) << "\t" << opt.x(0) << "\t" << opt.x(1) << "\t" << norm(opt.x) << "\t" << opt.y << "\t" << opt.f_calls;
//		solution::clear_calls();
//		opt = pen(ff3T, x0, c_in, dc_in, epsilon, Nmax, a);
//		zapis << "\t" << opt.x(0) << "\t" << opt.x(1) << "\t" << norm(opt.x) << "\t" << opt.y << "\t" << opt.f_calls << endl;
//		solution::clear_calls();
//		i--;
//	}
//	//zapis << "//////////////\tProblem rzeczywisty\t///////////////\n";
//
//
//	x0 = matrix(2, 1);
//	x0(0) = 0;// 20 * m2d(rand_mat()) - 10;
//	x0(1) = 0;// 40 * m2d(rand_mat()) - 20;
//	cout << "x0:\n" << x0 << endl << endl;
//	opt = pen(ff3R, x0, c_ex, dc_ex, epsilon, Nmax);
//	opt.y = -opt.y;
//	cout << opt << endl;
//	solution::clear_calls();
//}
//
//void lab4()
//{
//	//Funkcja testowa
//	ofstream S;
//	S.open("wyniki.txt");
//	double epsilon = 1e-3, h = -1;
//	cout << h << endl << endl;
//	int Nmax = 5000;
//	matrix x0;
//	solution opt;
//	//x0 = 20 * rand_mat(2, 1) - 10;
//	//x0(0) = -6.95284;
//	//x0(1) = 9.72172;
//	//cout << x0(0)<< " " <<x0(1) << endl << endl;
//	///*opt = SD(ff4T, gf4T, x0, h, epsilon, Nmax);
//	//cout << opt << endl << endl;*/
//	///*solution::clear_calls();
//	//opt = CG(ff4T, gf4T, x0, h, epsilon, Nmax);
//	//cout << opt << endl << endl;
//	//solution::clear_calls();*/
//	//opt = Newton(ff4T, gf4T, Hf4T, x0, h, epsilon, Nmax);
//	//cout << opt << endl << endl;
//	//solution::clear_calls();
//
//	for (int i = 0; i < 100; i++) {
//		x0 = 20 * rand_mat(2, 1) - 10;
//		cout << x0 << endl << endl;
//		opt = SD(ff4T, gf4T, x0, h, epsilon, Nmax);
//		S << x0(0) << " " << x0(1) << " " << opt.x(0) << " " << opt.x(1) << " " << opt.y << " " << opt.f_calls << " " << opt.g_calls << " ";
//		solution::clear_calls();
//		opt = CG(ff4T, gf4T, x0, h, epsilon, Nmax);
//		S << opt.x(0) << " " << opt.x(1) << " " << opt.y << " " << opt.f_calls << " " << opt.g_calls << " ";
//		solution::clear_calls();
//		opt = Newton(ff4T, gf4T, Hf4T, x0, h, epsilon, Nmax);
//		S << opt.x(0) << " " << opt.x(1) << " " << opt.y << " " << opt.f_calls << " " << opt.g_calls << " " << opt.H_calls << "\n";
//		solution::clear_calls();
//	}
//
//	////Regresja liniowa
//	/*epsilon = 1e-5, h = 0.00001;
//	Nmax = 20000;
//	x0 = matrix(3, 1);
//	opt = CG(ff4R, gf4R, x0, h, epsilon, Nmax);
//	cout << opt << endl << endl;
//
//	int n = 3, m = 100, P = 0;
//	matrix X(n, m), Y(1, m);
//	ifstream Sin("XData.txt");
//	Sin >> X;
//	Sin.close();
//	Sin.open("YData.txt");
//	Sin >> Y;
//	Sin.close();
//	for (int i = 0; i < m; ++i)
//	{
//		h = (trans(opt.x) * X[i])();
//		h = 1.0 / (1.0 + exp(-h));
//		if (round(h) == Y(0, i))
//			++P;
//	}
//	cout << P << endl << endl;*/
//}

void lab5()
{
	//Funkcja testowa
	ofstream a1("1.txt");
	ofstream a10("10.txt");
	ofstream a100("100.txt");
	ofstream belka("belka.txt");

	double pom = 0;
	matrix x0(2, 1), ud(2, 1);
	double epsilon = 1e-3 , w=0;
	int Nmax = 5000, a;
	solution opt;
	a = 100;
	//w = 0.5;
	ud(0) = 0;
	ud(1) = a;
	
	for (size_t i = 0; i < 101; i++)
	{
		ud(1) = 1;
		ud(0) = pom;
		x0 = 20 * rand_mat(2, 1) - 10;
		a1 << x0(0) << "\t" << x0(1);
		opt = Powell(ff5T, x0, epsilon, Nmax, ud);
		a1 << "\t" << opt.x(0) << "\t" << opt.x(1) << "\t" << opt.y(0) << "\t" << opt.y(1) << "\t" << opt.f_calls << endl;
		solution::clear_calls();

		ud(1) = 10;
		opt = Powell(ff5T, x0, epsilon, Nmax, ud);
		a10 << opt.x(0) << "\t" << opt.x(1) << "\t" << opt.y(0) << "\t" << opt.y(1) << "\t" << opt.f_calls << endl;
		solution::clear_calls();

		ud(1) = 100;
		opt = Powell(ff5T, x0, epsilon, Nmax, ud);
		a100 << opt.x(0) << "\t" << opt.x(1) << "\t" << opt.y(0) << "\t" << opt.y(1) << "\t" << opt.f_calls << endl;
		solution::clear_calls();


		pom += .01;
	}
	/*x0 = 20 * rand_mat(2, 1) - 10;
	cout << x0 << endl << endl;
	opt = Powell(ff5T, x0, epsilon, Nmax, ud);
	cout << opt << endl << endl;
	solution::clear_calls();*/

	//cout << "------------------------\n";
	////Belka
	//x0(0) = 0.8 * m2d(rand_mat()) + 0.2; // 100 - 1000
	//x0(1) = 0.04 * m2d(rand_mat()) + 0.01; // 10 - 50
	//cout << x0 << endl << endl;
	//w = 0;
	//ud = matrix(1, 1, w); // w a coœ
	//opt = Powell(ff5R, x0, epsilon, Nmax, ud);
	//cout << opt << endl << endl;
	//solution::clear_calls();

	for (size_t i = 0; i < 101; i++)
	{
		x0(0) = 800 * m2d(rand_mat()) + 200; // 100 - 1000
		x0(1) = 40 * m2d(rand_mat()) + 10; // 10 - 50
		belka << x0(0) << "\t" << x0(1);// << endl;
		ud = matrix(1, 1, w); // w, a
		opt = Powell(ff5R, x0, epsilon, Nmax, ud);
		belka << "\t" << opt.x(0)*1000 << "\t" << opt.x(1)*1000 << "\t" << opt.y(0) << "\t" << opt.y(1)*1000 << "\t" << opt.f_calls << endl;
		solution::clear_calls();
		w += .01;

	}
}

void lab6()
{
	//Funkcja testowa
	double epsilon = 1e-2;
	int Nmax = 10000;
	matrix limits(2, 2), sigma0(2, 1, 0.01);
	solution opt;
	//limits(0, 0) = limits(1, 0) = -5;
	//limits(0, 1) = limits(1, 1) = 5;
	
	/*for(int i=0;i<100;i++){
		opt = EA(ff6T, 2, limits, 20, 40, sigma0, epsilon, Nmax);
		cout << opt.x(0) << " " << opt.x(1) << " " << opt.y() << " " << solution::f_calls << " " << ((sqrt(pow(opt.x(0),2)+ pow(opt.x(1), 2)) < epsilon) ? "TAK" : "NIE") << endl;
		solution::clear_calls();
	}*/

	//Identyfikacja


	Nmax = 5000;
	epsilon = 1e-3;
	limits = matrix(2, 2);
	limits(0, 0) = limits(1, 0) = 0.1;
	limits(0, 1) = limits(1, 1) = 3;
	opt = EA(ff6R, 2, limits, 20, 40, matrix(2, 1, 1), epsilon, Nmax);
	cout << opt << endl << endl;

	//Symulacja
	ff6R(opt.x, matrix());
}
