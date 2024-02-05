//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void add(node **start , int val,int *cnt) {
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    if(*start == NULL) {
        *start = new;
    }
    else {
        node *last = *start;
        for(int i=0;i<(*cnt-1);i++) {
            last = last->next;
        }
        last->next = new;
    }
    new->next = *start;
}

void cutout(node **start, int step, int *cnt,int n,node **curr) {
    if(*cnt == 1) return;
    else {
        node *slow = *curr;
        for(int i=0;i<(step-1); i++) {
            //if(*cnt == n) i++;
            slow = (*curr);
            *curr = (*curr)->next;
        }
        slow->next = (*curr)->next;
        node *clear = *curr;
        *curr = (*curr)->next;
        //printf("slow : %d curr : %d ",slow->data,(*curr)->data);
        if(clear == *start) {
            *start = clear->next;
        }
        //printf("cut : %d\n",clear->data);
        free(clear);
        (*cnt)--;
        cutout(start,step,cnt,n,curr);
    }
}

int main() {
    int n,step; scanf("%d %d",&n,&step);
    node *start = NULL;
    int cnt=0;
    for(int i=0;i<n;i++) {
        int t; scanf("%d",&t);
        add(&start,t,&cnt);
        cnt++;
    }
    node *curr = start;
    cutout(&start,step,&cnt,n,&curr);
    node *pt = start;
    pt = pt->next;
    printf("%d\n",pt->data);
}