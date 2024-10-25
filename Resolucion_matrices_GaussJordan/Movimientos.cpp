#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Fracciones.h"
#define FILCOL_MAX 100

void Cambiar(int ipos_n1, int ipos_n2, int im_columnas, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	int aux_num, aux_den, contador;
	for (int contador = 0; contador < im_columnas; contador++)
	{
		aux_num = imatriz[ipos_n1][contador][0];
		aux_den = imatriz[ipos_n1][contador][1];
		imatriz[ipos_n1][contador][0] = imatriz[ipos_n2][contador][0];
		imatriz[ipos_n1][contador][1] = imatriz[ipos_n2][contador][1];
		imatriz[ipos_n2][contador][0] = aux_num;
		imatriz[ipos_n2][contador][1] = aux_den;
	}
}

void Volver_1(int& ipos_n, int& ipos_m, int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	bool fin = false;
	if (imatriz[ipos_n][ipos_m][0] == 0)
	{
		//Evaluar, cambiar renglon y volver el nuevo renglon 1
		bool columna_0 = true;
		while (columna_0)
		{
			if (ipos_m < im_columnas - 1)
			{
				int contador;
				for (contador = ipos_n + 1; contador < in_filas; contador++)
				{
					if (imatriz[contador][ipos_m][0] != 0)
					{
						Cambiar(ipos_n, contador, im_columnas, imatriz);
						columna_0 = false;
						contador = in_filas;
					}
					else
						columna_0 = true;
				}
				if (columna_0)
					ipos_m = ipos_m + 1;
			}
			else
			{
				columna_0 = false;
				fin = true;
				ipos_n = in_filas;
			}
		}
	}

	if (((imatriz[ipos_n][ipos_m][0] != 1) || (imatriz[ipos_n][ipos_m][1] != 1)) && (!fin))
	{
		int num, den;
		for (int m = 0; m < im_columnas; m++)
		{
			if (m != ipos_m)
			{
				num = inv_multi_num(imatriz[ipos_n][ipos_m][0], imatriz[ipos_n][ipos_m][1], imatriz[ipos_n][m][0], imatriz[ipos_n][m][1]);
				den = inv_multi_den(imatriz[ipos_n][ipos_m][0], imatriz[ipos_n][ipos_m][1], imatriz[ipos_n][m][0], imatriz[ipos_n][m][1]);
				reduccion(num, den, imatriz[ipos_n][m]);
			}
		}
		num = inv_multi_doble_num(imatriz[ipos_n][ipos_m][0], imatriz[ipos_n][ipos_m][1]);
		den = inv_multi_doble_den(imatriz[ipos_n][ipos_m][0], imatriz[ipos_n][ipos_m][1]);
		reduccion(num, den, imatriz[ipos_n][ipos_m]);
	}
}

void Volver_0(int& ipos_n, int& ipos_m, int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	for (int n = 0; n < in_filas; n++)
	{
		int escalar_inv[2];
		if (n != ipos_n)
		{
			escalar_inv[0] = -1 * imatriz[n][ipos_m][0];
			escalar_inv[1] = imatriz[n][ipos_m][1];
			if (imatriz[n][ipos_m][0] != 0)
			{
				for (int m = 0; m < im_columnas; m++)
				{
					int respuesta[2], inverso[2];
					inverso[0] = mult_frac_num(escalar_inv[0], escalar_inv[1], imatriz[ipos_n][m][0], imatriz[ipos_m][m][1]);
					inverso[1] = mult_frac_den(escalar_inv[0], escalar_inv[1], imatriz[ipos_n][m][0], imatriz[ipos_m][m][1]);
					reduccion(inverso[0], inverso[1], inverso);
					respuesta[0] = sum_frac_num(inverso[0], inverso[1], imatriz[n][m][0], imatriz[n][m][1]);
					respuesta[1] = sum_frac_den(inverso[0], inverso[1], imatriz[n][m][0], imatriz[n][m][1]);
					reduccion(respuesta[0], respuesta[1], imatriz[n][m]);
				}
			}
		}
	}
}

void Char_Int(char szValorOb[100], int& ipos_m, int& ipos_n, int imatriz[2])
{
	int largo, i, j, num_largo, aux, numerador, denominador;
	bool fraccion = false;
	bool valor_crct = false;
	bool num_neg = false; bool den_neg = false;
	char szValoresValidos[] = { '0','1','2','3','4','5','6','7','8','9','/','\0' };
	largo = strlen(szValorOb);

	numerador = 0; denominador = 0;

	for (i = 0; (i < largo) && (!valor_crct); i++)
	{
		valor_crct = true;
		for (j = 0; (j < 10) && (valor_crct); j++)
		{
			if (szValorOb[i] == '-')
			{
				if (fraccion)
					den_neg = true;
				else
					num_neg = true;
				valor_crct = false;
			}
			else if (szValorOb[i] == '/')
			{
				fraccion = true;
				num_largo = i;
				valor_crct = false;
			}
			else if (szValorOb[i] == szValoresValidos[j])
				valor_crct = false;
		}
	}

	if (valor_crct)
	{
		ipos_m = ipos_m - 1;
		printf("valor invalido para la posicion (%i, %i), por favor vuelva a ingresarlo", ipos_n + 1, ipos_m + 2);
	}
	else
	{
		if (fraccion)
		{
			int p = 0;
			if (num_neg)
			{
				for (i = num_largo - 1; i > 0; i--)
				{
					char c;
					c = szValorOb[i];
					aux = c - '0';
					numerador = numerador + (aux * pow(10, p++));
				}
				numerador = numerador * -1;
			}
			else
			{
				for (i = num_largo - 1; i >= 0; i--)
				{
					char c;
					c = szValorOb[i];
					aux = c - '0';
					numerador = numerador + (aux * pow(10, p++));
				}
			}
			imatriz[0] = numerador;
			p = 0;
			if (den_neg)
			{
				for (i = largo - 1; i > num_largo + 1; i--)
				{
					char c;
					c = szValorOb[i];
					aux = c - '0';
					denominador = denominador + (aux * pow(10, p++));
				}
				denominador = denominador * -1;
			}
			else
			{
				for (i = largo - 1; i > num_largo; i--)
				{
					char c;
					c = szValorOb[i];
					aux = c - '0';
					denominador = denominador + (aux * pow(10, p++));
				}
			}
			imatriz[1] = denominador;
			if (imatriz[1] == 0)
				imatriz[1] = 1;
		}
		else
		{
			int p = 0;
			if (num_neg)
			{
				for (i = largo - 1; i > 0; i--)
				{
					char c;
					c = szValorOb[i];
					aux = c - '0';
					numerador = numerador + (aux * pow(10, p++));
					imatriz[0] = numerador * -1;
				}
			}
			else
			{
				for (i = largo - 1; i >= 0; i--)
				{
					char c;
					c = szValorOb[i];
					aux = c - '0';
					numerador = numerador + (aux * pow(10, p++));
					imatriz[0] = numerador;
				}
			}
				imatriz[1] = 1;
		}
	}

}
	
void print_matriz(int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	for (int n = 0; n < in_filas; n++)
	{
		printf("| ");
		for (int m = 0; m < im_columnas; m++)
		{
			if (m + 1 == im_columnas)
				printf("|\t");
			if (imatriz[n][m][1] == 1)
			{
				printf("%i \t", imatriz[n][m][0]);
			}
			else
				printf("%i/%i \t", imatriz[n][m][0], imatriz[n][m][1]);
		}
		printf(" |\n");
	}
}

void printresult(int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	int impresion = 0;
	for (int n = 0; n < in_filas; n++)
	{
		for (int m = 0; m < im_columnas; m++)
		{
			if ((imatriz[n][m][0] != 0) && (m != im_columnas - 1))
			{
				if (imatriz[n][m][1] == 1)
				{
					if ((imatriz[n][m][0] == 1))
					{
						if (impresion == 0)
						{
							printf("\nx_%i ", m + 1);
							impresion = impresion + 1;
						}
						else
							printf("+ x_%i  ", m + 1);
					}
					else
					{
						if (impresion == 0)
						{
							printf("\n%i(x_%i) ", imatriz[n][m][0], m + 1);
							impresion = impresion + 1;
						}
						else
							printf("+ %i(x_%i)  ", imatriz[n][m][0], m + 1);
					}
				}
				else
				{
					if (impresion == 0)
					{
						printf("\n%i/%i(x_%i) ", imatriz[n][m][0], imatriz[n][m][1], m + 1);
						impresion = impresion + 1;
					}
					else
						printf("+ %i/%i(x_%i)  ", imatriz[n][m][0], imatriz[n][m][1], m + 1);
				}
			}
			else if ((m == im_columnas - 1) && (impresion != 0))
			{
				if (imatriz[n][m][1] == 1)
				{
					printf("= %i", imatriz[n][m][0]);
					impresion = 0;
				}
				else
				{
					printf("= %i/%i", imatriz[n][m][0], imatriz[n][m][1]);
					impresion = 0;
				}
			}
		}
	}
}

void Evaluar(int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	int m, n;
	bool incompatible = false;
	bool determinada = true;
	for (n = 0; (n < in_filas) && (!incompatible); n++)
	{
		incompatible = true;
		for (m = 0; (m < im_columnas) && (incompatible); m++)
		{
			if (m != im_columnas - 1)
			{
				if (imatriz[n][m][0] == 0)
					incompatible = true;
				else
					incompatible = false;
			}
			else if (m == im_columnas - 1)
			{
				if (imatriz[n][m][0] != 0)
					incompatible = true;
				else
					incompatible = false;
			}
		}
	}

	if (incompatible)
		printf("\nLa matriz es incompatible");
	else
	{
		int ipos_n, ipos_m;
		ipos_n = 0;
		ipos_m = 0;


		for (n = 0; (n < in_filas) && (determinada); n++)
		{
			determinada = true;
			for (m = 0; (m < im_columnas - 1) && (determinada); m++)
			{
				if ((ipos_n == n) && (ipos_m == m))
					determinada = true;
				else
				{
					if (imatriz[n][m][0] == 0)
						determinada = true;
					else
						determinada = false;
				}
			}
			ipos_n = ipos_n + 1;
			ipos_m = ipos_m + 1;
		}

		if (determinada)
		{
			printf("\nEs una matriz compatible determinada:");
			printresult(im_columnas, in_filas, imatriz);
		}
		else
		{
			printf("\nEs una matriz compatible indeterminada:");
			printresult(im_columnas, in_filas, imatriz);
		}
	}
}

/*
//En proceso
void Buscar_1(int& ipos_n, int& ipos_m, int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	if ((imatriz[ipos_n][ipos_m][0] == 1) && (imatriz[ipos_n][ipos_m][1] == 1))
	{
		Volver_0(ipos_n,ipos_m,im_columnas,in_filas,imatriz);
	}
	else if (imatriz[ipos_n][ipos_m][0] != 0)
	{
		Volver_1(ipos_n, ipos_m, im_columnas, in_filas, imatriz);
	}
	else if ((imatriz[ipos_n][ipos_m][0] == 0) && (ipos_n != in_filas - 1))
	{
		float valor_fila[FILCOL_MAX];
		int posicion_fila[FILCOL_MAX];
		int contador = 0;
		for (int n = 0; n < in_filas; n++)
		{
			if (n != ipos_n)
			{
				valor_fila[contador] = imatriz[n][ipos_m][0] / imatriz[n][ipos_m][1];
				posicion_fila[contador] = n;
				contador++;
			}
		}
		for (int x_1 = 0; x_1 < contador - 1; x_1++)
		{
			for (int x_2 = 0; x_2 < contador - 1; x_2++)
			{
				if (valor_fila[x_2 + 1] < valor_fila[x_2])
				{
					float faux; int iaux;
					faux = valor_fila[x_2 + 1];
					iaux = posicion_fila[x_2 + 1];
					valor_fila[x_2 + 1] = valor_fila[x_2];
					posicion_fila[x_2 + 1] = posicion_fila[x_2];
					valor_fila[x_2] = faux;
					posicion_fila[x_2] = iaux;
				}

			}
		}
	}
}


int Evaluar_r(int im_columnas, int ipos_n, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	int estado_lec, resultado;
	estado_lec = Leer_r(im_columnas, ipos_n, imatriz);

	if (estado_lec == 0)
		resultado = 0;
	else
	{
		for (int m = 0; m < im_columnas; m++)
		{
			if (imatriz[ipos_n][m][0] != 0)
			{
				m = im_columnas;
				resultado = 1;
			}
			if (m == im_columnas - 1)
			{
				if ((imatriz[ipos_n][m][0] == 1) && (imatriz[ipos_n][m][1] == 1))
					resultado = 0;
			}
		}
	}

}

int Leer_r(int im_columnas, int ipos_n, int imatriz[FILCOL_MAX][FILCOL_MAX][2])
{
	int resultado;
	for (int m = 0; m < im_columnas; m++)
	{
		if (imatriz[ipos_n][m][0] != 0)
		{
			m = im_columnas;
			resultado = 1;
		}
		if (m == im_columnas - 1)
		{
			if ((imatriz[ipos_n][m][0] == 1) && (imatriz[ipos_n][m][1] == 1))
				resultado = 0;
		}
	}
	return resultado;
}



void Proceso_GaussJordan(int& ipos_n, int& ipos_m, int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX])
{
	//covertimos el pimer termino en 1
	if (imatriz[ipos_n][ipos_m] != 1)
	{
		if (imatriz[ipos_n][ipos_m] == 0)
		{
			int ircambio;
			ircambio=Evaluar_r(ipos_m);
			Cambiar_r(ipos_n,ircambio);
		}
		else
		{
			for (int i=(ipos_m-1);i < im_columnas;i++)
			{
				inv_multi(imatriz[ipos_n][ipos_m], imatriz[ipos_n][i]);
			}
		}
	}

	//reducimos los terminos adyacentes en la misma columna a 0
	
	for (int i = 0; i < in_filas; i++)
	{
		if (i != ipos_n)
		{
			int iInv_ad = inv_ad(imatriz[i][ipos_m]);

			for (int j = 0; j < im_columnas; j++)
			{
				mult_sum(iInv_ad, imatriz[ipos_n][j], imatriz[i][j]);
			}
		}
	}
}
*/