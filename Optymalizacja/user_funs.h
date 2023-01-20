#pragma once

#include"ode_solver.h"

matrix f_celu(matrix x, matrix ud1 = 0, matrix ud2 = 0);
matrix f_celu2(matrix x, matrix ud1 = 0, matrix ud2 = 0);
matrix f_celu3(matrix x, matrix ud1 = 0, matrix ud2 = 0);
matrix f_celu3_test(matrix x, matrix ud1 = 0, matrix ud2 = 0);
matrix df1(double t, matrix Y, matrix ud1, matrix ud2);
matrix fR(matrix x, matrix ud1, matrix ud2);

matrix ff2T(matrix x, matrix ud1, matrix ud2);
matrix ff2R(matrix x, matrix ud1, matrix ud2);
matrix df2(double t, matrix Y, matrix ud1, matrix ud2);

matrix ff3T(matrix x, matrix ud1, matrix ud2);
matrix df3(double t, matrix Y, matrix ud1, matrix ud2);
matrix ff3R(matrix x, matrix ud1, matrix ud2);

matrix ff4T(matrix x, matrix ud1, matrix ud2);
matrix gf4T(matrix x, matrix ud1, matrix ud2);
matrix Hf4T(matrix x, matrix ud1, matrix ud2);
matrix ff4R(matrix x, matrix ud1, matrix ud2);
matrix gf4R(matrix x, matrix ud1, matrix ud2);

matrix ff5T(matrix x, matrix ud1, matrix ud2);
matrix ff5R(matrix x, matrix ud1, matrix ud2);

matrix ff6T(matrix x, matrix ud1 = NAN, matrix ud2 = NAN);
matrix ff6R(matrix x, matrix ud1 = NAN, matrix ud2 = NAN);
matrix df6(double t, matrix Y, matrix ud1 = NAN, matrix ud2 = NAN);