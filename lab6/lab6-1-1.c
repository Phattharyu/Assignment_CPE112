//66070503448 Phattharapong Duangkham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {
    int n; scanf("%d",&n);
    int c=0;
    int arr[MAX];
    for (int i=0;i<MAX;i++)  arr[i] = -999;
    while(1) {
        char ch[10]; scanf("%s",ch);
        if(strcmp(ch,"ROOT")==0) {
            if(c==1) {
                printf("cannot create duplicated root\n");
                continue;
            }
            int t; scanf("%d",&t);
            arr[1] = t;
            c=1;
        }
        else if(strcmp(ch,"INSL")==0) {
            int boo=0;
            int par; scanf("%d",&par);
            int t; scanf("%d",&t);
            for(int i=1;i<=n;i++) {
                if(par == arr[i]) {
                    if(arr[i*2] != -999) {
                        printf("node already presented\n");
                        boo=1;
                        break;
                    } 
                    else if(i*2 > n) {
                        printf("overflow\n");
                        boo=1;
                        break;
                    }
                    else {
                        arr[i*2] = t;
                        boo=1;
                        break;
                    }
                }
            }
            if(boo==0) {
                printf("not found\n");
                continue;
            }

        }
        else if(strcmp(ch,"INSR")==0) {
            int boo=0;
            int par; scanf("%d",&par);
            int t; scanf("%d",&t);
            for(int i=1;i<=n;i++) {
                if(par == arr[i]) {
                    if(arr[(i*2)+1] != -999) {
                        printf("node already presented\n");
                        boo=1;
                        break;
                    } 
                    else if((i*2)+1 > n) {
                        printf("overflow\n");
                        boo=1;
                        break;
                    }
                    else {
                        arr[(i*2)+1] = t;
                        boo=1;
                        break;
                    }
                }
            }
            if(boo==0) {
                printf("not found\n");
                continue;
            }
        }
        else if(strcmp(ch,"END")==0) break;
    }
    for(int i=1;i<=n;i++) {
        if(arr[i] == -999) {
            printf("null ");
        }
        else printf("%d ",arr[i]);
    }
    printf("\n");
}