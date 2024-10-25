#include <stdio.h>
#include <string.h>
#include <math.h>
#define FILCOL_MAX 1000

int inv_multi_num(int numerador, int denominador)
{
	return denominador;
}
int inv_multi_den(int numerador, int denominador) 
{
	return numerador;
}
int inv_multi_num(int nume_inv, int den_inv, int num, int den)
{
	int resutado_num;
	resutado_num = den_inv * num;
	
	return resutado_num;
}
int inv_multi_den(int nume_inv, int den_inv, int num, int den)
{
	int resutado_num;
	resutado_num = nume_inv * den;

	return resutado_num;
}

int mult_frac_num(int num_1, int den_1, int num_2, int den_2)
{
	int resultado_num;
	resultado_num = num_1 * num_2;

	return resultado_num;
}
int mult_frac_den(int num_1, int den_1, int num_2, int den_2)
{
	int resultado_den;
	resultado_den = den_1 * den_2;

	return resultado_den;
}
int mult_frac_num(int num, int num_2, int den_2)
{
	int resultado_num;
	resultado_num = num * num_2;

	return resultado_num;
}
int mult_frac_den(int num, int num_2, int den_2)
{
	int resultado_den;
	resultado_den = 1 * den_2;

	return resultado_den;
}

int sum_frac_num(int num_1, int den_1, int num_2, int den_2)
{
	int resultado_num;
	resultado_num = (num_1 * den_2) + (num_2 * den_1);
	return resultado_num;
}
int sum_frac_den(int num_1, int den_1, int num_2, int den_2)
{
	int resultado_den;
	resultado_den = den_1 * den_2;
	return resultado_den;
}

int inv_adi_num(int num_1, int den_1, int num_2, int den_2)
{
	int resultado_num;
	resultado_num = sum_frac_num(-num_1, den_1, num_2, den_2);
	return resultado_num;
}
int inv_adi_den(int num_1, int den_1, int num_2, int den_2)
{
	int resultado_den;
	resultado_den = sum_frac_den(-num_1, den_1, num_2, den_2);
	return resultado_den;
}



int inv_multi_doble_num(int num, int den)
{
	return 1;
}
int inv_multi_doble_den(int num, int den)
{
	return 1;
}

int max_cd(int num_1, int num_2)
{
	int resultado, aux;
	if ((num_1 == 0) || (num_2 == 0))
		return 1;
	else
	{
		
		if (num_1 < num_2)
		{
			aux = num_1;
			num_1 = num_2;
			num_2 = aux;
		}
		do {
			resultado = num_2;
			num_2 = num_1 % num_2;
			num_1 = resultado;
		} while (num_2 != 0);
	}
	return resultado;
}

int reduccion_num(int num, int den)
{
	int mcd, resultado;
	mcd = max_cd(num, den);
	resultado = num / mcd;
	return resultado;
}
int reduccion_den(int num, int den)
{
	int mcd, resultado;
	mcd = max_cd(num, den);
	resultado = den / mcd;
	return resultado;
}
void reduccion(int num, int den, int imatriz[2])
{
	int mcd, resultado_num, resultado_den;
	mcd = max_cd(num, den);
	if (num != 0)
	{
		if ((num < 0) && (den < 0))
		{
			if (mcd > 0)
				mcd = mcd * -1;
		}
		else if ((num < 0) && (mcd < 0))
		{
			mcd = mcd * -1;
		}
		else if ((den < 0) && (mcd > 0))
		{
			mcd = mcd * -1;
		}

		imatriz[0] = num / mcd;
		imatriz[1] = den / mcd;
	}
	else
	{
		imatriz[0] = num;
		imatriz[1] = 1;
	}
	
	
}

