#include"user_funs.h"
#include<cmath>

#define M_PI 3.1415

matrix f_celu(matrix x, matrix ud1, matrix ud2) {
	return -cos(0.1 * x()) * exp(-pow(0.1 * x() - 2 * M_PI, 2)) + 0.002 * pow(0.1 * x(), 2);
}

matrix df1(double t, matrix Y, matrix ud1, matrix ud2) {
	double a = 0.98, b = 0.63, g = 9.81;
	double Fin = .01, Faout, Fbaut;
	double Pa = 1, Pb = 1, Db = 0.00365665; 
	double Tin = 10, Ta = 90;
	matrix dY(3, 1);

	Faout = a * b * m2d(ud2) * sqrt(2 * g * Y(0) / Pa);
	Fbaut = a * b * Db * sqrt(2 * g * Y(1) / Pb);

	dY(0) = -Faout;
	dY(1) = Faout + Fin - Fbaut;
	dY(2) = (Fin / Y(1)) * (Tin - Y(2)) + (Faout / Y(1)) * (Ta - Y(2));

	return dY;
}

matrix fR(matrix x, matrix ud1, matrix ud2) {
	matrix y;
	matrix Y0 = matrix(3, new double [3] {5, 1, 10}); // Va0 Vb0 Tb0
	matrix* Y = solve_ode(df1, 0, 1, 1000, Y0, ud1, x);

	double max = Y[1](0,2);

	for (int i = 0; i < get_size(Y[1])[0]; i++) {
		if (Y[1](i,2) > max) max = Y[1](i,2);
	}

	y = abs(max - 40);

	return y;
}