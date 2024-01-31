//66070503448 Phattharapong Duangkham
#include<stdio.h>

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    int x,y;
    scanf("%d %d",&x,&y);
    int b[x][y];
    for(int i=0;i<x;i++) for(int j=0;j<y;j++) scanf("%d",&b[i][j]);
    if(m!=x) {
        printf("Not Compatible\n");
        return 0;
    }
    int s[n][y];
    for(int i=0;i<n;i++) for(int j=0;j<y;j++) s[i][j]=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<y;j++) {
            for(int k=0;k<m;k++) {
                s[j][i] += (a[j][k] * b[k][i]);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<y;j++) printf("%d ",s[i][j]);
        printf("\n");
    }
}
