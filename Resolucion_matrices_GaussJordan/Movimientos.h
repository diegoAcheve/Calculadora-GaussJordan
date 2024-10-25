#define FILCOL_MAX 100

void Proceso_GaussJordan(int& ipos_n, int& ipos_m, int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX]);

void Volver_1(int& ipos_n, int& ipos_m, int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2]);

void Volver_0(int& ipos_n, int& ipos_m, int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2]);

void Cambiar(int ipos_n1, int ipos_n2, int im_columnas, int imatriz[FILCOL_MAX][FILCOL_MAX][2]);

void Char_Int(char szValorOb[100], int& ipos_m, int& ipos_n, int imatriz[2]);

void print_matriz(int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2]);
void Evaluar(int im_columnas, int in_filas, int imatriz[FILCOL_MAX][FILCOL_MAX][2]);