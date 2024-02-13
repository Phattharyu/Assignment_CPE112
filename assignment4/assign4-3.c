//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>

int main() {
    char word[1000]; scanf("%s",word);
    int last=0;
    while(word[last] != '\0') last++;
    last--;
    int tr = 1;
    while(last >= 0) {
        int first=last;
        first--;
        if(word[last]=='}') {
            tr = 0;
            while (first>=0) {
                if(word[first] == '{') {
                    word[first] = '\0';
                    word[last] = '\0';
                    tr =1;
                    break;
                }
                first--;
            }
            if(tr == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } else if(word[last] == ')') {
            tr = 0;
            while (first>=0) {
                if(word[first] == '(') {
                    word[first] = '\0';
                    word[last] = '\0';
                    tr = 1;
                    break;
                }
                first--;
            }
            if(tr == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } else if(word[last] == ']') {
            tr = 0;
            while (first>=0) {
                if(word[first] == '[') {
                    word[first] = '\0';
                    word[last] = '\0';
                    tr =1;
                    break;
                }
                first--;
            }
            if(tr == 0) {
                printf("The string is not balanced\n");
                return 0;
            }
        } else if(word[last] == '(') {
            printf("The string is not balanced\n");
            return 0;
        }
        else if(word[last] == '{') {
            printf("The string is not balanced\n");
            return 0;
        }
        else if(word[last] == '[') {
            printf("The string is not balanced\n");
            return 0;
        }
        last--;
    }
    if(tr!=0) printf("The string is balanced\n");
    else printf("The string is not balanced\n");
    return 0;
}