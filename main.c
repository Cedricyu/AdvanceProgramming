
#include <stdint.h>
//#pragma once
#include <stdio.h>
#include <stdbool.h>
//#include "matrix.c"
int main(){
    int r = 0 , c = 0;
    if (get_RC_and_detect(&r, &c)) return 0;

    int m1[MAX_R][MAX_C];
    get_matrix_or_init(r, c, m1, 1);
    if (Detect_error_element_range(m1)) return 0;

    
    return 0;
    
}
