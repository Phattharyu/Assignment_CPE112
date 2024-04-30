//66070503448 Phattharapong Duangkham
#include<stdio.h>

int min(int a,int b) {
    return a < b ? a : b;
}

int main() {
    int n,t; scanf("%d",&n);
    int a0[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&t);
            if(t==-1) {
                a0[i][j]=999;
                continue;
            }
            a0[i][j] = t;
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                a0[i][j] = min(a0[i][j],(a0[i][k]+a0[k][j]));
            }
        }  
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",(a0[i][j]==999 ? -1 : a0[i][j]));
        }
        printf("\n");
    }
}
