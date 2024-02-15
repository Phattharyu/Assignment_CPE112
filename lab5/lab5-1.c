//66070503448 Phattharapong Duangkham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char song[50];
    char artist[50];
    int sec;
    struct node *next;
}node;

void add(node **start,char s[],char art[],int t) {
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->song,s);
    strcpy(new->artist,art);
    new->sec = t;
    new->next = NULL;
    if(*start == NULL) {
        *start = new;
    }
    else {
        node *last = *start;
        while(last->next != NULL) last = last->next;
        last->next = new;
    }
}

void cut(char *str) {
    for(int i=0;i<strlen(str);i++) {
        if(str[i] == '\n') {
            str[i] = '\0';
            return;
        }
    }
}

void pop(node **start) {
    if(*start == NULL) {
        printf("No songs in the playlist\n");
        return;
    }
    node *nex = *start;
    nex = nex->next; 
    printf("Now playing: %s by %s\n",(*start)->song,(*start)->artist);
    free(*start);
    *start = nex;
}

void sum(node **start) {
    if(*start == NULL) {
        printf("No songs in the playlist\n");
        return;
    }
    else {
        node *ptr = *start;
        int sum=0;
        printf("Songs in the playlist:\n");
        while(ptr != NULL) {
            printf("%s by %s %d\n",ptr->song,ptr->artist,ptr->sec);
            sum += ptr->sec;
            ptr = ptr->next;
        }
        printf("Remaining Time: %d\n",sum);
    }
}

int main() {
    char op[10];
    fgets(op,10,stdin);
    char s[50];
    char art[50];
    int t;
    node *start = NULL;
    while(1) {
        if(strcmp(op,"add\n") == 0) {
            fgets(s,50,stdin);
            cut(s);
            fgets(art,50,stdin);
            cut(art);
            scanf("%d",&t);
            add(&start,s,art,t);
        }
        else if(strcmp(op,"play\n")==0) {
            pop(&start);
        }
        else if(strcmp(op,"sum\n")==0) {
            sum(&start);
            break;
        }
        fgets(op,10,stdin);
    }
}