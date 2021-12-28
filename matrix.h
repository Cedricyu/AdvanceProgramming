#define MAX_R 200
#define MAX_C 100
//#ifndef matrix_h
//#define matrix_h
#include <stdbool.h>
#include <stdio.h>

void all_init(int m[MAX_R][MAX_C]);
void get_matrix_or_init(int r, int c, int m1[MAX_R][MAX_C], bool choose);
bool get_RC_and_detect(int *r, int *c);
bool Detect_error_RC(int R, int C);
bool Detect_error_element_range(int Mat[MAX_R][MAX_C]);
bool Addition(int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]);
bool Subtract(int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]);
bool Product(int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]);
bool Transpose(int R[MAX_C][MAX_C], int Result[MAX_R]);

void pro(int c1,int r2,int r1,int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]);
