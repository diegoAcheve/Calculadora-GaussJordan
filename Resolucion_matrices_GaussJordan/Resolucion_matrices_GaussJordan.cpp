#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "Movimientos.h"

int main()
{
    int imatriz[FILCOL_MAX][FILCOL_MAX][2];
    int in_filas, im_columnas, ipos_n, ipos_m;
    char szValorOb[FILCOL_MAX];
    char szSINO[3];
    bool fin = false;

    while (!fin)
    {
    
        //Pedimos el numero de filas y columnas de la matriz
        printf_s("\nNumero de filas(n) de la matriz : ");
        scanf_s("%i", &in_filas);

        printf_s("\nNumero de columnas(m) de la matriz : ");
        scanf_s("%i", &im_columnas);

        //Comenzamos un ciclo de 0 a in_filas y que pueda detenerse con una bandera true||false

        //pedimos los valores
        for (ipos_n = 0; ipos_n < in_filas; ipos_n++)
        {
            for (ipos_m = 0; ipos_m < im_columnas; ipos_m++)
            {
                printf("\nEl valor de la matriz en (%i,%i) para (n,m): ", ipos_n + 1, ipos_m + 1);
                scanf_s("%s", szValorOb, 100);
                Char_Int(szValorOb, ipos_m, ipos_n, imatriz[ipos_n][ipos_m]);
            }
        }

        system("cls");

        printf("\n");
        print_matriz(im_columnas, in_filas, imatriz);

        //Empezamos el proceso Gauss-Jordan
        ipos_m = 0;
        for (ipos_n = 0; ipos_n < in_filas; ipos_n++, ipos_m++)
        {
            printf("\n");
            printf("Volvemos 1 el termino en (%i,%i):\n", ipos_n + 1, ipos_m + 1);
            Volver_1(ipos_n, ipos_m, im_columnas, in_filas, imatriz);
            print_matriz(im_columnas, in_filas, imatriz);
            if (ipos_n < in_filas)
            {
                printf("\n");
                printf("Volvemos O los otros terminos:\n");
                Volver_0(ipos_n, ipos_m, im_columnas, in_filas, imatriz);
                print_matriz(im_columnas, in_filas, imatriz);
            }
        }

        Evaluar(im_columnas, in_filas, imatriz);

        printf("\n\n\n\t %cQuieres resolver otra matriz?(si/no)",168);
        scanf_s("%s", szSINO, 3);
        szSINO[2] = '\0';
        char no[3] = { 'n','o','\0' };
        
        if (strcmp(szSINO, no) == 0)
            fin = true;
        system("cls");
    }




}
