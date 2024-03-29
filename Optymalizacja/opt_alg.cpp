#include"opt_alg.h"
double* expansion(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		int i = 0;
		solution X0(x0), X1(x0 + d);
		solution pom;
		X0.clear_calls();
		double* p = new double[2];
		X1.fit_fun(ff, ud1, ud2);
		X0.fit_fun(ff, ud1, ud2);
		if (X1.y == X0.y) {
			p[0] = m2d(X0.x);
			p[1] = m2d(X1.x);
			//cout << endl << X1.f_calls << ",";
			//X1.clear_calls();
			return p;
		}

		if (X1.y > X0.y) {
			d = -d;
			X1.x = x0 + d;
			X1.fit_fun(ff, ud1, ud2);
			if (X1.y >= X0.y) {
				p[1] = m2d(X0.x - d);
				p[0] = m2d(X1.x);
				//cout << endl << X1.f_calls << ",";
				//X1.clear_calls();
				return p;
			}
		}

		for (;;) {

			i++;
			pom.x = x0 + pow(alpha, i) * d;
			pom.fit_fun(ff, ud1, ud2);
			if (X1.y <= pom.y) break;
			X0 = X1;
			X1 = pom;

		}

		if (d > 0) {
			p[0] = m2d(X0.x);
			p[1] = m2d(pom.x);
			//cout << endl << X1.f_calls << ",";
			//X1.clear_calls();
			return p;
		}

		p[0] = m2d(pom.x);
		p[1] = m2d(X0.x);
		//cout << endl << X1.f_calls << ",";
		//X1.clear_calls();
		return p;
	}
	catch (string ex_info){
		throw ("double* expansion(...):\n" + ex_info);
	}
}

solution fib(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		Xopt.ud = b - a;
		int n = static_cast<int>(ceil(log2(sqrt(5) * (b - a) / epsilon) / log2((1 + sqrt(5)) / 2)));
		double* F = new double[n] {1, 1};
		for (int i = 2; i < n; ++i)
			F[i] = F[i - 2] + F[i - 1];
		solution A(a), B(b), C, D;
		C.x = B.x - 1.0 * F[n - 2] / F[n - 1] * (B.x - A.x);
		D.x = A.x + B.x - C.x;
		C.fit_fun(ff, ud1, ud2);
		D.fit_fun(ff, ud1, ud2);
		for (int i = 0; i <= n - 3; ++i){
			if (C.y < D.y) B = D;
			else A = C;
			C.x = B.x - (F[n - i - 2] / F[n - i - 1]) * (B.x - A.x);
			D.x = A.x + B.x - C.x;
			C.fit_fun(ff, ud1, ud2);
			D.fit_fun(ff, ud1, ud2);
		}
		Xopt = C;
		Xopt.flag = 0;
		return Xopt;
	}
	catch (string ex_info){
		throw ("solution fib(...):\n" + ex_info);
	}
}

solution lag(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, double gamma, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		Xopt.ud = b - a;
		solution A(a), B(b), C, D, D_old(a);
		C.x = (a + b) / 2;
		A.fit_fun(ff, ud1, ud2);
		B.fit_fun(ff, ud1, ud2);
		C.fit_fun(ff, ud1, ud2);
		double l, m;
		while (true){
			l = m2d(A.y * (pow(B.x) - pow(C.x)) + B.y * (pow(C.x) - pow(A.x)) + C.y * (pow(A.x) - pow(B.x)));
			m = m2d(A.y * (B.x - C.x) + B.y * (C.x - A.x) + C.y * (A.x - B.x));
			if (m <= 0){
				Xopt = D_old;
				Xopt.flag = 2;
				return Xopt;
			}
			D.x = 0.5 * l / m;
			D.fit_fun(ff, ud1, ud2);
			if (A.x <= D.x && D.x <= C.x){
				if (D.y < C.y) {
					B = C;
					C = D;					
				}
				else {
					A = D;
				}
			}
			else if (C.x <= D.x && D.x <= B.x)
			{
				if (D.y < C.y) {
					A = C;
					C = D;
				}
				else {
					B = D;
				}
			}
			else
			{
				Xopt = D_old;
				Xopt.flag = 2;
				return Xopt;
			}
			Xopt.ud.add_row((B.x - A.x)());
			if (B.x - A.x < epsilon || abs(D.x() - D_old.x()) < gamma){
				Xopt = D;
				Xopt.flag = 0;
				break;
			}
			if (solution::f_calls > Nmax){
				Xopt = D;
				Xopt.flag = 1;
				break;
			}
			D_old = D;
		}
		return Xopt;
	}
	catch (string ex_info){
		throw ("solution lag(...):\n" + ex_info);
	}
}

solution HJ(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double  alpha, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try{
		solution XB;
		solution XB2;
		solution X;

		XB.x = x0;
		XB.fit_fun(ff, ud1, ud2);
		while (true){
			X = HJ_trial(ff, XB, s, ud1, ud2);
			//cout << X.x(0) << " " << X.x(1) << endl;
			if (X.y < XB.y){
				while (true){
					XB2 = XB;
					XB = X;
					X.x = XB.x + XB.x - XB2.x;

					X.fit_fun(ff, ud1, ud2);
					X = HJ_trial(ff, X, s, ud1, ud2);
					if (X.y >= XB.y) break;
					if (XB.f_calls > Nmax) return XB;
				}
			}
			else s *= alpha;
			if (XB.f_calls > Nmax || s < epsilon) return XB;
		}
	}
	catch (string ex_info){
		throw ("solution HJ(...):\n" + ex_info);
	}
}

solution HJ_trial(matrix(*ff)(matrix, matrix, matrix), solution XB, double s, matrix ud1, matrix ud2)
{
	try{
		solution X;

		int* n = get_size(XB.x);
		matrix D(n[0], n[0]);
		for (int i = 0; i < n[0]; i++) D(i, i) = 1; 
		for (int i = 0; i < n[0]; ++i){
			X.x = XB.x + s * D[i];
			X.fit_fun(ff, ud1, ud2);
			if (X.y < XB.y) XB = X;
			else{
				X.x = XB.x - s * D[i];
				X.fit_fun(ff, ud1, ud2);
				if (X.y < XB.y) XB = X;
			}
		}
		return XB;
	}
	catch (string ex_info)
	{
		throw ("solution HJ_trial(...):\n" + ex_info);
	}
}

solution Rosen(matrix(*ff)(matrix, matrix, matrix), matrix x0, matrix s0, double alpha, double beta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution X(x0), Xt;
		int n = get_dim(X);//liczba wymiar�w
		matrix l(n, 1),//odleg�o� od orginalnego punktu 
			p(n, 1),//pora�ki w kierunu
			s(s0),//d�ugo�ci kroku
			D = ident_mat(n);
		X.fit_fun(ff, ud1, ud2);
		while (true)
		{
			for (int i = 0; i < n; ++i)
			{
				Xt.x = X.x + s(i) * D[i];
				Xt.fit_fun(ff, ud1, ud2);
				if (Xt.y < X.y)
				{
					X = Xt;
					l(i) += s(i);
					s(i) *= alpha;
				}
				else
				{
					++p(i);
					s(i) *= -beta;
				}
			}
			bool change = true;
			for (int i = 0; i < n; ++i)
				if (p(i) == 0 || l(i) == 0)
				{
					change = false;
					break;
				}
			if (change)
			{
				matrix Q(n, n), v(n, 1);
				for (int i = 0; i < n; ++i)
					for (int j = 0; j <= i; ++j)
						Q(i, j) = l(i);
				Q = D * Q;
				v = Q[0] / norm(Q[0]);
				D.set_col(v, 0);
				for (int i = 1; i < n; ++i)
				{
					matrix temp(n, 1);
					for (int j = 0; j < i; ++j)
						temp = temp + trans(Q[i]) * D[j] * D[j];
					v = (Q[i] - temp) / norm(Q[i] - temp);
					D.set_col(v, i);
				}
				s = s0;
				l = matrix(n, 1);
				p = matrix(n, 1);
			}
			double max_s = abs(s(0));
			for (int i = 1; i < n; ++i)
				if (max_s < abs(s(i)))
					max_s = abs(s(i));
			if (max_s<epsilon || solution::f_calls>Nmax)
				return X;
		}
	}
	catch (string ex_info)
	{
		throw ("solution Rosen(...):\n" + ex_info);
	}
}
solution pen(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution Xopt;
		double alpha = 1;
		double beta = 0.5;
		double gamma = 2;
		double delta = 0.5;
		double s = 0.5;

		solution X(x0), X1;
		while (true)
		{
			X1 = sym_NM(ff, X.x, s, alpha, beta, gamma, delta, epsilon, Nmax, ud1, c);
			if (norm(X.x - X1.x) < epsilon)
			{
				Xopt = X1;
				Xopt.flag = 0;
				break;
			}
			if (solution::f_calls > Nmax)
			{
				Xopt = X1;
				Xopt.flag = 1;
				break;
			}
			c *= dc;
			X = X1;
		}

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution pen(...):\n" + ex_info);
	}
}
//solution pen(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c0, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
//{
//	try {
//		solution Xopt(x0);
//		double alpha = 1, beta = 0.5, gamma = 2, delta = 0.5, s = 0.5;
//		solution X(x0), X1;
//		matrix c(2, new double[2] { c0, dc });
//		X = sym_NM(ff, X.x, s, alpha, beta, gamma, delta, epsilon, Nmax, ud1, c);
//		while (true)
//		{
//			X1 = sym_NM(ff, X.x, s, alpha, beta, gamma, delta, epsilon, Nmax, ud1, c);
//			cout << "";
//			matrix tmp = X1.y - X.y;
//			//cout << "\n\ntmp\t" << tmp << endl;
//			if ((tmp) < epsilon)
//			{
//				Xopt = X1;
//				return X1;
//			}
//			//? ? ?
//			X = X1;
//		}
//		return Xopt;
//	}
//	catch (string ex_info)
//	{
//		throw ("solution pen(...):\n" + ex_info);
//	}
//}

//solution sym_NM(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2)
//{
//	try
//	{
//		solution Xopt;
//		//Tu wpisz kod funkcji
//
//		return Xopt;
//	}
//	catch (string ex_info)
//	{
//		throw ("solution sym_NM(...):\n" + ex_info);
//	}
//}

solution sym_NM(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	solution Xopt;
	int n = get_len(x0);
	int N = n;//+1;
	matrix D = ident_mat(n);
	int ii = 0;
	solution* S = new solution[N];
	S[0].x = x0;
	S[0].fit_fun(ff, ud1, ud2);
	for (int i = 1; i < N; ++i)
	{
		S[i].x = x0 + s * D[i];
		S[i].fit_fun(ff, ud1, ud2);
	}
	solution PR, PE, PN;
	matrix pc;
	int i_min, i_max;
	while (true)
	{
		ii++;
		i_min = 0;
		i_max = 0;
		for (int i = 1; i < N; i++)
		{
			if (S[i].y < S[i - 1].y)
				i_min = i;
			if (S[i].y > S[i - 1].y)
				i_max = i;
		}
		if (S[i_min].y == S[i_max].y)return -1;
		pc = matrix(n, 1);
		for (int i = 0; i < N; i++)
			if (i != i_max)
				//? ? ?
				pc = pc + S[i].x / n;
		PR.x = pc + alpha * (pc = S[i_max].x);
		PR.fit_fun(ff, ud1, ud2);
		if (PR.y >= S[i_min].y)
			S[i_max] = PR;

		else if (PR.y < S[i_min].y)
		{
			PE.x = pc + gamma * (PR.x - pc);
			PE.fit_fun(ff, ud1, ud2);
			if (PE.y < PR.y)

				S[i_max] = PE;
			else
				S[i_max] = PR;
		}
		else
		{
			if (S[i_min].y <= PR.y && PR.y < S[i_max].y)
				S[i_max] = PR;
			else {
				PN.x = pc + beta * (S[i_max].x - pc);
				PN.fit_fun(ff, ud1, ud2);
				if (PN.y < S[i_max].y)
					S[i_max] = PN;
				else
				{
					for (int i = 0; i < N; ++i)
						if (i != i_min)
						{
							S[i].x = delta * (S[i].x + S[i_min].x);
							S[i].fit_fun(ff, ud1, ud2);
						}
				}
			}
		}
		solution max_s = S[0];
		Xopt = max_s;
		for (int i = 1; i < N; ++i) {
			if (max_s.y < S[i].y) max_s = S[i];
			if (max_s.y > S[i].y) Xopt = S[i];
			double tmp;

			tmp = m2d(S[i_min].y) - m2d(S[i].y);
			if (abs(tmp) < epsilon) break;
		}
		if (ii >= n)break;
	}
	return Xopt;

}

solution SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution SD(...):\n" + ex_info);
	}
}

solution CG(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution CG(...):\n" + ex_info);
	}
}

solution Newton(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix),
	matrix(*Hf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Newton(...):\n" + ex_info);
	}
}

solution golden(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution golden(...):\n" + ex_info);
	}
}

solution Powell(matrix(*ff)(matrix, matrix, matrix), matrix x0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Powell(...):\n" + ex_info);
	}
}

solution EA(matrix(*ff)(matrix, matrix, matrix), int N, matrix limits, int mi, int lambda, matrix sigma0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution EA(...):\n" + ex_info);
	}
}
