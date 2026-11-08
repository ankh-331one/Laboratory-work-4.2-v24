#include "p_function.h"
#include <locale.h>
#include <malloc.h>

int input(char a, int L_diapazon, int R_diapazon){
    setlocale(0,"");
    setlocale(LC_NUMERIC, "C");
    int x;
    do{
        printf("\nВведите %c: ", a);
        scanf("%d", &x);
        if (x < L_diapazon || x > R_diapazon){
            printf("\n==========================================================================\n");
            printf("Ошибка: Нарушен диапазон: %c должно быть от %d до %d", a, L_diapazon, R_diapazon);
            printf("\n==========================================================================\n");
        }
    }while (x < L_diapazon || x > R_diapazon);
    return x;
}

void mass_input(FILE* in_file, double** *A, int m, int n){
    setlocale(0,"");
    setlocale(LC_NUMERIC, "C");
    int i, j;
    (*A) = (double**)malloc(m*sizeof(double*));
    for (i = 0; i < m; i++){
        (*A)[i] = (double*)malloc(n*sizeof(double));
        for (j = 0; j < n; j++){
            fscanf(in_file, "%lf", &(*A)[i][j]);
        }
    }
    return ;
}

void mass_print(FILE* out_file, char a, double** A, int m, int n){
    setlocale(0,"");
    setlocale(LC_NUMERIC, "C");
    int i, j;
    fprintf(out_file, "\nВведён массив %c(%d*%d):\n", a, m, n);
    fprintf(out_file, " ___"); for (j = 0; j < m; j++) fprintf(out_file, " __________");
    fprintf(out_file, "\n|m\\n|"); for (j = 0; j < n; j++) fprintf(out_file, "%6d    |", j);
    fprintf(out_file, "\n ---"); for (j = 0; j < n; j++) fprintf(out_file, "+----------");
    for (i = 0; i < m; i++){
        fprintf(out_file, "\n|%2d |", i);
        for (j = 0; j < n; j++){
            fprintf(out_file, "%9.3lf |", A[i][j]);
        }
    }
    fprintf(out_file, "\n ==="); for (j = 0; j < n; j++) fprintf(out_file, " ==========");
    return;
}

void mass_free(double*** A, int m){
    for (int i = 0; i < m; i++) free((*A)[i]);
    free(*A);
    return;
}

double cr_znach_m(double** A, int j, int m){
    double sum = 0, k = 0;
    for (int i = 0; i < m; i++){
        if (A[i][j] < 0){
            sum += A[i][j];
            k += 1;
        }
    }
    if (k == 0){
        k += 1;
    }
    return sum/k;
}


int find_id_max(double** A, int m, int n, int* flag){
    int id_max = 0;
    double cr_znach, max;
    int j = 0;
    while (j < n && !(*flag)){
        cr_znach = cr_znach_m(A, j, m);
        if (cr_znach != 0){
            max = cr_znach;
            id_max = j;
            (*flag) = 1;
        }else j++;
    }
    j += 1;
    while (j < n && flag){
        cr_znach = cr_znach_m(A, j, m);
        if (cr_znach > max && cr_znach != 0){
            max = cr_znach;
            id_max = j;
        }
        j++;
    }
    return id_max;
}

