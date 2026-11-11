/*
 * Лабораторная 4.2 Разработка подпрограммы, применяемой к идентичным по структуре частям одного объекта.
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
#ifndef P_FUNCTION.H
#define P_FUNCTION.H

#include <stdio.h>

int input(char name, int L_diapazon, int R_diapazon);

void mass_input(FILE* f_in, double** *X, int nx, int mx);
void mass_print(FILE* f_out, char name, double** X, int nx, int mx);
void mass_free(double** *X, int nx);

double cr_znach_m(double** X, int j, int nx);
int find_id_max(double** X, int nx, int mx, int *flag_find);

#endif

