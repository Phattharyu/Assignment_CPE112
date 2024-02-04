//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

void insert(node **start, int val , int *cnt) {
    node *new = (node *)malloc(sizeof(node));
    new->data=val;
    new->next = NULL;
    if(*start == NULL) {
        *start = new;
        (*cnt)++;
    }
    else {
        node *last = *start;
        for(int i=0;i<(*cnt-1);i++) {
            last = last->next;
        }
        last->next = new;
        (*cnt)++;
    }
    new->next = *start;
}

void del(node **start , int val, int *cnt) {
    node *ptr = *start;
    node *slow = *start;
    for(int i=0;i<(*cnt);i++) {
        if(val == ptr->data) {
            if(ptr == *start) {
                node *fast = ptr->next;
                *start = fast;
                free(ptr);
            }
            else if(i == *cnt) {
                free(ptr);
                slow->next = *start;
            } else {
                node *fast = ptr->next;
                free(ptr);
                slow->next = fast;
            }
            (*cnt)--;
            break;
        }
        slow = ptr;
        ptr = ptr->next;
    }
}

int main() {
    node *start = NULL;
    char c;
    scanf("%c",&c);
    int cnt =0;
    while (c != 'E'){
        if(c == 'I') {
            int t; scanf("%d",&t);
            insert(&start,t,&cnt);
        }
        else if(c == 'D') {
            int t; scanf("%d",&t);
            del(&start,t,&cnt);
        }
        scanf("%c",&c);
    }
    if(cnt == 0) printf("Empty");
    else {
        node *ptr = start;
        for(int i=0;i<cnt;i++) {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
    node *clear = start;
    for(int i=0;i<cnt;i++) {
        node *temp = clear->next;
        free(clear);
        clear = temp;
    }
    start = NULL;
}