//66070503448 Phattharapong Duangkham
#include<stdio.h>

void hanoi(char start, char aux, char end,int n,int *cnt) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n",start,end);
        (*cnt)++;
        return;
    }
    else if(n<=0) {
        printf("PLEASE INPUT THE CORRECT n !!!\n");
        return;
    }
    else {
        hanoi(start,end,aux,n-1,cnt);
        printf("Move disk %d from %c to %c\n",n,start,end);
        hanoi(aux,start,end,n-1,cnt);
        (*cnt)++;
    }
}

int main() {
    int n; scanf("%d",&n);
    int cnt=0;
    hanoi('A','B','C',n,&cnt);
    printf("Total moves: %d\n",cnt);
}