//66070503448 Phattharapong Duangkham
#include <stdio.h>
#include <stdlib.h>
//Version 1
void removen(char str[]) {
    int i=0;
    while(str[i] != '\n') i++;
    str[i] = '\0';
}

int vowels(char str) {
    if(str=='a' || str=='e' || str=='i' || str=='o' || str=='u') {
        return 1;
    }
    else if(str=='A' || str=='E' || str=='I' || str=='O' || str=='U') {
        return 1;
    }
    else return 0;
}

int conso(char string) {
    if((string>=65 && string<=90) || (string>=97 && string<=122)) {
        return 1;
    }
    else return 0;
}

int main() {
    char word[1000];
    fgets(word,1000,stdin);
    removen(word);
    int prio[1000];
    int i=0;
    while(word[i] != '\0') {
        if(vowels(word[i]) == 1) prio[i] = 3;
        else if((conso(word[i]) == 1)) prio[i]=1;
        else prio[i] = 2;
        i++;
    }
    i=0;
    while(word[i] != '\0') {
        if(prio[i] == 3) printf("%c",word[i]);
        i++;
    }
    i=0;
    while(word[i] != '\0') {
        if(prio[i] == 2) printf("%c",word[i]);
        i++;
    }
    i=0;
    while(word[i] != '\0') {
        if(prio[i] == 1) printf("%c",word[i]);
        i++;
    }
    printf("\n");
}