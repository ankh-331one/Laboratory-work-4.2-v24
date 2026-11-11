/*
 * Лабораторная 4.2 Разработка подпрограммы, применяемой к идентичным по структуре частям одного объекта.
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
#include "p_function.h"
#include <malloc.h>

int input(char name, int L_diapazon, int R_diapazon){
    int x;
    do{
        printf("\nВведите %c: ", name);
        scanf("%d", &x);
        if (x < L_diapazon || x > R_diapazon){
            printf("\n==========================================================================\n");
            printf("Ошибка: Нарушен диапазон: %c должно быть от %d до %d", name, L_diapazon, R_diapazon);
            printf("\n==========================================================================\n");
        }
    }while (x < L_diapazon || x > R_diapazon);
    return x;
}

void mass_input(FILE* f_in, double** *X, int nx, int mx){
    (*X) = (double**)malloc(nx*sizeof(double*));
    for (int i = 0; i < nx; i++){
        (*X)[i] = (double*)malloc(mx*sizeof(double));
        for (int j = 0; j < mx; j++){
            fscanf(f_in, "%lf", &(*X)[i][j]);
        }
    }
    return ;
}

void mass_print(FILE* f_out, char name, double** X, int nx, int mx){
    int i, j;
    fprintf(f_out, "\nВведён массив %c(%d*%d):\n", name, nx, mx);
    fprintf(f_out, " ___"); for (j = 0; j < mx; j++) fprintf(f_out, " __________");
    fprintf(f_out, "\n|m\\n|"); for (j = 0; j < mx; j++) fprintf(f_out, "%6d    |", j);
    fprintf(f_out, "\n ---"); for (j = 0; j < mx; j++) fprintf(f_out, "+----------");
    for (i = 0; i < nx; i++){
        fprintf(f_out, "\n|%2d |", i);
        for (j = 0; j < mx; j++){
            fprintf(f_out, "%9.3lf |", X[i][j]);
        }
    }
    fprintf(f_out, "\n ==="); for (j = 0; j < mx; j++) fprintf(f_out, " ==========");
    return;
}

void mass_free(double** *X, int nx){
    for (int i = 0; i < nx; i++) free((*X)[i]);
    free(*X);
    (*X) = NULL;
    return;
}


double cr_znach_m(double** X, int j, int nx){
    double sum = 0;
    int k = 0;
    for (int i = 0; i < nx; i++){
        if (X[i][j] < 0){
            sum += X[i][j];
            k += 1;
        }
    }
    if (k == 0){
        sum = 0;
    }else{
        sum /= k;
    }
    return sum;
}

int find_id_max(double** X, int nx, int mx, int *flag_find){
    int id_max = 0;
    double cr_znach, max = 0;
    for (int j = 0; j < mx; j++){
        cr_znach = cr_znach_m(X, j, nx);
        if (cr_znach != 0){
            if (!(*flag_find) || cr_znach > max){
                max = cr_znach;
                id_max = j;
                (*flag_find) = 1;
            }
        }
    }
    return id_max;
}
