//66070503448, Phattharapong Duangkham
#include<stdio.h>

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m],at[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&a[i][j]);
            at[j][i] = a[i][j];
        }
    }
    int cnt1=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] != at[i][j]) {
                cnt1++;
                break;
            }
        }
        if (cnt1>0) break;
    }
    if(cnt1==0) {
        printf("The matrix is symmetric\n");
        return 0;
    }
    int cnt2=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if((-a[i][j] != at[i][j]) && i!=j) {
                cnt2++;
                break;
            }
        }
        if (cnt2>0) break;
    }
    if(cnt2==0) {
        printf("The matrix is skew-symmetric\n");
        return 0;
    }
    printf("None\n");
    return 0;
}