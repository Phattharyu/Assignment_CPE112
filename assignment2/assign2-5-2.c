//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>

void spi(int n,int m,int **a,int h,int r,int u,int x,int y,int cnt) {
    if(cnt==0) return;
    //right
    if(h==0 && r==0) {
        for(int i=0;i<m;i++) {
            printf("%d ",a[x][y]);
            y++,cnt--;
        }
        m--,y--,x++;
        h=1;
        r=1;
        spi(n,m,a,h,r,u,x,y,cnt);
    }
    //left
    else if(h==0 && r==1) {
        for(int i=0;i<m;i++) {
            printf("%d ",a[x][y]);
            y--,cnt--;
        }
        m--,y++,x--;
        r=0;
        h=1;
        spi(n,m,a,h,r,u,x,y,cnt);
    }
    //up
    else if(h==1 && u==1) {
        for(int i=0;i<n;i++) {
            printf("%d ",a[x][y]);
            //printf("%d ",a[x][y]);
            x--,cnt--;
        }
        n--,x++,y++;
        h=0;
        u=0;
        spi(n,m,a,h,r,u,x,y,cnt);
    }
    //down
    else if(h==1 && u==0){
        for(int i=0;i<n;i++) {
            printf("%d ",a[x][y]);
            //printf("%d ",a[x][y]);
            x++,cnt--;
        }
        n--,x--,y--;
        h=0;
        u=1;
        spi(n,m,a,h,r,u,x,y,cnt);
    }
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    int cnt = n*m;
    spi(n-1,m,a,0,0,0,0,0,cnt);
    printf("\n");
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}