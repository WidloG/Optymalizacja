#include"user_funs.h"
#include<cmath>

#define M_PI 3.1415

matrix f_celu(matrix x, matrix ud1, matrix ud2) {
	return -cos(0.1 * x()) * exp(-pow(0.1 * x() - 2 * M_PI, 2)) + 0.002 * pow(0.1 * x(), 2);
}

matrix f_celu2(matrix x, matrix ud1, matrix ud2) {
	return pow(x(0), 2) + pow(x(1), 2) - cos(2.5 * M_PI * x(0)) - cos(2.5 * M_PI * x(1)) + 2;
}

matrix f_celu3_test(matrix x, matrix ud1, matrix ud2) {
	return pow((x(0)-2),2) + pow((x(1) - 3), 2);
}

matrix f_celu3(matrix x, matrix ud1, matrix ud2) {
	return (sin(M_PI * sqrt(pow(x(0) / M_PI, 2) + pow(x(1) / M_PI, 2))) / (M_PI * sqrt(pow(x(0) / M_PI, 2) + pow(x(1) / M_PI, 2))));
}

matrix df1(double t, matrix Y, matrix ud1, matrix ud2) {
	double a = 0.98, b = 0.63, g = 9.81;
	double Fin = .01, Faout, Fbout;
	double Pa = 0.75, Pb = 1, Db = 0.00365665; 
	double Tin = 10, Ta = 90;
	matrix dY(3, 1);

	Faout = Y(0) > 0 ? a * b * m2d(ud2) * sqrt(2 * g * Y(0) / Pa) : 0;
	Fbout = Y(1) > 1 ? a * b * Db * sqrt(2 * g * Y(1) / Pb) : 0;

	dY(0) = -Faout;
	dY(1) = Faout + Fin - Fbout;
	dY(2) = (Fin / Y(1)) * (Tin - Y(2)) + (Faout / Y(1)) * (Ta - Y(2));

	return dY;
}

matrix fR(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	matrix Y0 = matrix(3, new double [3] {5, 1, 10}); // Va0 Vb0 Tb0
	matrix* Y = solve_ode(df1, 0, 1, 1000, Y0, ud1, x);

	double max = Y[1](0, 2);
	int n = get_len(Y[0]);
	for (int i = 1; i < n; ++i) {
		if (max < Y[1](i, 2))
			max = Y[1](i, 2);
	}

	y = abs(max - 50);

	return y;
}

matrix ff2T(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	y = pow(x(0), 2) + pow(x(1), 2) - cos(2.5 * 3.14 * x(0)) - cos(2.5 * 3.14 * x(1)) + 2;
	return y;
}

matrix ff2R(matrix x, matrix ud1, matrix ud2)
{
	ofstream zapis2("daneRamie.txt");
	matrix y;
	matrix Y0(2, 1), Y_ref(2, new double[2] { 3.14, 0 });
	matrix* Y = solve_ode(df2, 0, 0.1, 100, Y0, Y_ref, x);
	int n = get_len(Y[0]);
	y = 0;
	for (int i = 0; i < n; ++i)
	{
		y = y + 10 * pow(Y_ref(0) - Y[1](i, 0), 2) + pow(Y_ref(1) - Y[1](i, 1), 2) + pow(x(0) * (Y_ref(0) - Y[1](i, 0)) + x(1) * (Y_ref(1) - Y[1](i, 1)), 2);
		zapis2 << Y[1](i, 0) << "\t" << Y[1](i, 1) << endl;
	}
	zapis2 << "\n\n\n\n\n\n\n\n\n";
	y = y * 0.1;
	return y;
}

matrix df2(double t, matrix Y, matrix ud1, matrix ud2)
{
	double mr = 1, mc = 5, l = 0.5, b = 0.5;
	double I = mr * l * l / 3 + mc * l * l;
	matrix dY(2, 1);
	dY(0) = Y(1);
	dY(1) = (ud2(0) * (ud1(0) - Y(0)) + ud2(1) * (ud1(1) - Y(1)) - b * Y(1)) / I;

	return dY;
}

matrix ff3T(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	y = (sin(3.14 * sqrt(pow((x(0) / 3.14), 2) + pow((x(1) / 3.14), 2)))) / (3.14 * sqrt(pow((x(0) / 3.14), 2) + pow((x(1) / 3.14), 2)));
	return y;
}

matrix ff3R(matrix x, matrix ud1, matrix ud2) {
	/*matrix y;
	matrix Y0(4, new double[4] { 0, x(0), 100, 0 });
	matrix* Y = solve_ode(df3, 0, 0.01, 7, Y0, ud1, x(1));
	int n = get_len(Y[0]);
	int i50 = 0, i0 = 0;
	for (int i = 0; i < n; ++i) {
		if (abs(Y[1](i, 2) - 50) < abs(Y[1](i50, 2) - 50)) i50 = i;
		if (abs(Y[1](i, 2)) < abs(Y[1](i0, 2)))  i0 = i;
	}
	y = -Y[1](i0, 0);
	if (abs(x(0)) - 10 > 0) y = y + ud2 * pow(abs(x(0)) - 10, 2);
	if (abs(x(1)) - 30 > 0) y = y + ud2 * pow(abs(x(1)) - 30, 2);
	if (abs(Y[1](i50, 0) - 5) - 1 > 0) y = y + ud2 * pow(abs(Y[1](i50, 0) - 5) - 1, 2);
	cout << Y[1](i50, 0) << "\t" << Y[1](i50, 1) << endl;
	return y;*/

	matrix y;
	matrix y0(4, new double[4] { 0, x(0), 100, 0 });
	matrix* Y = solve_ode(df3, 0, 0.01, 7, y0, ud1, x(1));
	int n = get_len(Y[0]);
	int i50 = 0, i0 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (abs(Y[1](i, 2) - 50) < abs(Y[1](i50, 2) - 50))
			i50 = i;
		if (abs(Y[1](i, 2)) < abs(Y[1](i0, 2)))
			i0 = i;
	}
	y = -Y[1](i0, 0);
	if (abs(x(0)) - 10 > 0)
		y = y + ud2 * pow(abs(x(0)) - 10, 2);
	if (abs(x(1)) - 25 > 0)
		y = y + ud2 * pow(abs(x(1)) - 25, 2);
	if (abs(Y[1](i50, 0) - 5) - 1 > 0)
		y = y + ud2 * pow(abs(Y[1](i50, 0) - 5) - 1, 2);
	return y;
}

matrix df3(double t, matrix Y, matrix ud1, matrix ud2) {
	/*double C = 0.47, r = 0.12, m = 0.6, ro = 1.2, g = 9.81;
	double S = 3.14 * r * r,
		Dx = 0.5 * C * ro * S * Y(1) * abs(Y(1)),
		Dy = 0.5 * C * ro * S * Y(3) * abs(Y(3)),
		FMx = 3.14 * ro * Y(3) * m2d(ud2) * pow(r, 3),
		FMy = 3.14 * ro * Y(1) * m2d(ud2) * pow(r, 3);
	matrix dY(4, 1);
	dY(0) = Y(1);
	dY(1) = (-Dx - FMx) / m;
	dY(2) = Y(3);
	dY(3) = (-m * g - Dy - FMy) / m;
	return dY;*/
	double c = 0.47, r = 0.12, m = 0.6, r0 = 1.2, g = 9.81;
	double s = M_PI * r * r;
	double Dx = 0.5 * c * r0 * s * abs(Y(1)) * (Y(1));
	double Dy = 0.5 * c * r0 * s * abs(Y(3)) * (Y(3));
	double Fmx = M_PI * r0 * Y(3) * m2d(ud2) * pow(r, 3);
	double Fmy = M_PI * r0 * Y(1) * m2d(ud2) * pow(r, 3);

	matrix dy(4, 1);
	dy(0) = Y(1);
	dy(1) = (-Dy - Fmx) / m;
	dy(2) = Y(3);
	dy(3) = (-m * g - Dy - Fmy) / m;

	return dy;
}
