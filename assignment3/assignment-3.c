//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode
{
int val;
struct ListNode *next;
} ListNode;

void add(ListNode **start,int t) {
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->val = t;
    new->next = NULL;
    if(*start == NULL) {
        *start = new;
    }
    else {
        ListNode *last = *start;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

void begin(ListNode **temp,int t) {
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->val = t;
    new->next = *temp;
    *temp = new;
}

int main() {
    char inp[5];
    ListNode *start = NULL;
    while(1) {
        scanf("%s",inp);
        if(strcmp("END",inp) == 0) break;
        else {
            int t = atoi(&inp[0]);
            add(&start,t);
        }
    }
    int st,en; scanf("%d %d",&st,&en);
    ListNode *ptr = start;
    for(int i=1;i<st;i++) {
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }
    ListNode *temp = NULL;
    for(int i=st;i<=en;i++) {
        begin(&temp,ptr->val);
        ptr = ptr->next;
    }
    ListNode *print = temp;
    while(print != NULL) {
        printf("%d ",print->val);
        print = print->next;
    }
    while(ptr != NULL) {
        printf("%d ",ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}