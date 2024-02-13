//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>

int main() {
    char inp[100];
    scanf("%s",inp);
    int last_index = 0;
    int first = 0;
    while(inp[last_index] != '\0') last_index++;
    last_index--;
    while (first<last_index) {
        if(inp[first] != inp[last_index]) {
            printf("no\n");
            return 0;
        }
        first++;
        last_index--;
    }
    printf("yes\n");
    return 0;
}