

#include "matrix.h"


void all_init(int m[MAX_R][MAX_C]){
    for (int i = 0 ; i < MAX_R; i++){
        for (int j = 0 ; j < MAX_C; j++){
            m[i][j] = -2147483648;
        }
    }
}

void get_matrix_or_init(int r, int c, int m1[MAX_R][MAX_C], bool choose){
//依據r c數值，讀入矩陣到 m1 內
//choose=1: 使用scnaf
//choose=0: 初始化
    printf("input the matrix\n");
    for (int i = 0 ; i < MAX_R; i++){
        for (int j = 0 ; j < MAX_C; j++){
            if (choose && ((i < r) && (j < c)))
                scanf("%d", &m1[i][j]);
            else
                m1[i][j] = -2147483648;
        }
    }
}

bool get_RC_and_detect(int *r, int *c){
//讀入r c數值，「真實」更動到外面的r c的數值
//如果rc數值有問題，回傳1，沒問題回傳0
    printf("input the row and col:\n");
    scanf("%d %d", r, c);

    if (Detect_error_RC(*r, *c))
        return 1;

    return 0;
}
int Get_rangeR(int M[MAX_R][MAX_C]){
    int max_r;
    for (int i=0;i<MAX_R;i++){
        if (M[0][i]>1000||M[0][i]<-1000){
            return max_r=i;
        }
    }
    return -1;
}
int Get_rangeC(int M[MAX_R][MAX_C]){
    int max_c;
    for (int i=0;i<MAX_R;i++){
        if (M[i][0]>1000||M[i][0]<-1000){
            return max_c=i;
        }
    }
    return -1;
}

bool Detect_error_RC(int R, int C){
    if (R>200||R<0){
        printf(" RC: The R or C Value range exceeds");
        return 1;
    }
    if (C>100||C<0){
        printf(" RC: The R or C Value range exceeds");
        return 1;
    }
    return 0;
}

bool Detect_error_element_range(int Mat[MAX_R][MAX_C]){

    for (int i=0;i<Get_rangeR(Mat);i++){
        for (int j=0;j<Get_rangeC(Mat);j++){
            if (Mat[i][j]>1000||Mat[i][j]<-1000){
                printf("Range: The element of the matrix is outside the range of -1000 to 1000\n");
                return 1;
            }
        }
    }
    return 0;
}

//0: OK, 1: Error
bool Addition(int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]){
    int r1=Get_rangeR(M_1);
    int c1=Get_rangeC(M_1);
    int c2=Get_rangeC(M_2);
    int r2=Get_rangeR(M_2);
    printf("%d%d%d%d",r1,r2,c1,c2);
    if (r1==r2&&c1==c2){
        for(int i=0;i<c1;++i){
            for(int j=0;j<r2;++j){
                R[i][j]=M_1[i][j]+M_2[i][j];
            }
        }
        return 0;
    }
    printf("Addition: The number of rows and columns does not match\n");
    return 1;
}

bool Subtract(int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]){
    int r1=Get_rangeR(M_1);
    int c1=Get_rangeC(M_1);
    int c2=Get_rangeC(M_2);
    int r2=Get_rangeR(M_2);
    if (r1==r2&&c1==c2){
        for(int i=0;i<c1;++i){
            for(int j=0;j<r2;++j){
                R[i][j]=M_1[i][j]-M_2[i][j];
            }
        }
        return 0;
    }
    printf("Subtract: The number of rows and columns does not match\n");
    return 1;
}

bool Product(int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]){
    int r1=Get_rangeR(M_1);
    int c1=Get_rangeC(M_1);
    int c2=Get_rangeC(M_2);
    int r2=Get_rangeR(M_2);
    int r3=r1;
    int c3=c2;
    printf("%d%d%d%d%d%d\n",r1,r2,r3,c1,c2,c3);
    if (r1==c2){
        //pro(c1,r2,r1,M_1,M_2,&R);
        return 0;
    }
    printf("Product: The number of rows and columns does not match\n");
    return 1;
}

bool Transpose(int R[MAX_R][MAX_C], int Result[MAX_R]){
    int r1=Get_rangeR(R);
    int c1=Get_rangeC(R);
    for(int i=0;i<c1;i++){
        int sum=0;
        for (int j=0;j<r1;j++){
            sum+=R[j][i];
            if (R[j][i]>1000||R[j][i]<-1000){
                break;
            }
        }
        Result[i]=sum;
    }
    return 0;
}

void pro(int c1,int r2,int r1,int M_1[MAX_R][MAX_C], int M_2[MAX_R][MAX_C], int R[MAX_R][MAX_C]){
    for (int i=0; i<c1; i++) {
            for (int j=0; j<r2; j++) {
                for(int k = 0; k <r1; k++) {
                    R[i][j] = R[i][j] +M_1[i][k] * M_2[k][j];
                }
            }
    }
    return ;
}
