//66070503448, Phattharapong Duangkham
#include<stdio.h>

int min(int a,int b) {
    if(a<b) return a;
    else return b;
}

int minj(int st,int end, int a[]) {
    int mina;
    if(st>=end) return 0;
    for (int k = st+1;k <= st + a[st] && k <= end; k++) {
        int jumps = 1 + minj(k, end, a);
        mina = min(mina, jumps);
    }
    return mina;
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d\n",minj(0,n-1,a));
}