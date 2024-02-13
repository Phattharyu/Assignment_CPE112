//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>

int main() {
    int num,base; scanf("%d %d",&num,&base);
    if(num<0 || base>36 || base < 2) {
        printf("invalid\n");
        return 0;
    }
    int cnt=0;
    char ans[100];
    if(num == 1) {
        printf("1\n");
        return 0;
    }
    else if(num == 0) {
        printf("0\n");
        return 0;
    }
    else {
        while(num!=0) {
            int t = num%base;
            num = num/base;
            if(t<=9) ans[cnt] = t + '0';
            else {
                ans[cnt] = t+55;
            }
            cnt++;
        }
    }
    for(int i=(cnt-1);i>=0;i--) {
        printf("%c",ans[i]);
        ans[i] = '\0';//pop it out
        cnt--;
    }
    printf("\n");
    return 0;
}