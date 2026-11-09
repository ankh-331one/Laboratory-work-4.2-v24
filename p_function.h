/*
 * Лабораторная 4.2 Разработка подпрограммы, применяемой к идентичным по структуре частям одного объекта.
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
#ifndef P_FUNCTION.H
#define P_FUNCTION.H

#include <stdio.h>

int input(char a, int L_diapazon, int R_diapazon);

void mass_input(FILE* in_file, double*** A, int m, int n);
void mass_print(FILE* out_file, char a, double** A, int m, int n);
void mass_free(double*** A, int m);

double cr_znach_m(double** A, int j, int m);
int find_id_max(double** A, int m, int n, int* flag);

#endif
