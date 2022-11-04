#pragma once

#include"ode_solver.h"

matrix f_celu(matrix x, matrix ud1 = 0, matrix ud2 = 0);
matrix df1(double t, matrix Y, matrix ud1, matrix ud2);
matrix fR(matrix x, matrix ud1, matrix ud2);

