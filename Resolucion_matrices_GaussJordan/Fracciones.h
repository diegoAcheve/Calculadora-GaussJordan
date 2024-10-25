#pragma once
#define FILCOL_MAX 1000

int inv_multi_num(int numerador, int denominador);
int inv_multi_den(int numerador, int denominador);
int inv_multi_num(int nume_inv, int den_inv, int num, int den);
int inv_multi_den(int nume_inv, int den_inv, int num, int den);

int mult_frac_num(int num_1, int den_1, int num_2, int den_2);
int mult_frac_den(int num_1, int den_1, int num_2, int den_2);
int mult_frac_num(int num, int num_2, int den_2);
int mult_frac_den(int num, int num_2, int den_2);

int inv_adi_num(int num_1, int den_1, int num_2, int den_2);
int inv_adi_den(int num_1, int den_1, int num_2, int den_2);

int sum_frac_num(int num_1, int den_1, int num_2, int den_2);
int sum_frac_den(int num_1, int den_1, int num_2, int den_2);

int inv_multi_doble_num(int num, int den);
int inv_multi_doble_den(int num, int den);

int reduccion_num(int num, int den);
int reduccion_den(int num, int den);
void reduccion(int num, int den, int imatriz[2]);

int max_cd(int num_1, int num_2);