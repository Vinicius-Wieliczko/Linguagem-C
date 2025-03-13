#include<stdio.h>
#include<stdlib.h>

int L[20][20];
char LCSPD(char X[20],char Y[20], int m, int n){
    for(int i = 0; i<m; i++){
        for(int j = 0; i<n; i++){
            if (i == 0 || j==0){
                L[i][j] = 0;
                }
            else if (X[i-1] == Y[j-1]){
               L[i][j] = L[i-1][j-1] + 1;
            }else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int max(int x, int y){
    if (x > y)
        return x;
    else
        return y;
}

int main(){
    LCSPD("analise", "algoritmos", 20, 20);
    for(int i = 0; i<20; i++){
        for(int j = 0; i<20; i++){
                printf("%d", L[i][j]);
        }
    }
return 0;
}



