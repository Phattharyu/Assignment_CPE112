//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void push(node **start,int val,int *cnt) {
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    if(*start == NULL) {
        *start = new;
    }
    else {
        new->next = (*start);
        *start = new;
    }
    (*cnt)++;
}

bool ismt(int *cnt) {
    if(*cnt == 0) return true;
    else return false;
}

void pop(node **start,int *cnt) {
    if(ismt(cnt)) {
        printf("empty\n");
        return;
    }
    node *clear = *start;
    node *nex = *start;
    nex = nex->next;
    printf("%d\n",clear->data);
    free(clear);
    *start = nex;
    (*cnt)--;
}

bool top(node **start) {
    if(*start == NULL) return true;
    else {
        printf("%d\n",(*start)->data);
        return false;
    }
}



int main() {
    char choice; scanf("%c",&choice);
    node *start = NULL;
    int cnt = 0;
    while(1) {
        if(choice == 'p') {
            int t; scanf("%d",&t);
            push(&start,t,&cnt);
        }
        else if(choice == 'o') {
            pop(&start,&cnt);
        }
        else if(choice == 't') {
            if(top(&start)) printf("empty\n");
        }
        else if(choice == 'e') {
            if(ismt(&cnt)) printf("1\n");
            else printf("0\n");
        }
        else if(choice == 'q') {
            break;
        }
        scanf("%c",&choice);
    }
}