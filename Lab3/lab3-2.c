#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

void add(node **start,int val) {
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;
    if(*start == NULL) *start = new;
    else {
        node *last = *start;
        while(last->next != NULL) last = last->next;
        last->next = new;
    }
}

void after(node **start,int pos,int val,int *n) {
    node *ptr = *start;
    int cnt=0;
    while(ptr->data != pos) {
        ptr = ptr->next;
        cnt++;
        if(cnt>=*n) return;
    }
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    if(ptr->next == NULL) {
        temp->next = NULL;
        ptr->next = temp;
    } else {
        node *fast = ptr;
        fast = fast->next;
        ptr->next = temp;
        temp->next = fast;
    }
    (*n)++;
}

void before(node **start,int pos,int val,int *n) {
    node *pt = *start;
    node *slow = *start;
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    int cnt =0;
    while(pt->data != pos) {
        slow = pt;
        pt = pt->next;
        cnt++;
        if(cnt>=*n) return;
    }
    if(pt == *start) {
        temp->next = pt;
        *start = temp;
    }
    else {
        temp->next = pt;
        slow->next = temp;
    }
    (*n)++;
}

int main() {
    int n;
    scanf("%d",&n);
    node *start = NULL;
    for(int i=0;i<n;i++) {
        int t;
        scanf("%d",&t);
        add(&start,t);
    }
    char c;
    scanf("%c",&c);
    while(c != 'E') {
        if(c == 'A') {
            int t,pos;
            scanf("%d %d",&pos ,&t);
            after(&start,pos,t,&n);
        }
        else if(c == 'B') {
            int t,pos;
            scanf("%d %d",&pos ,&t);
            before(&start,pos,t,&n);
        }
        c='\0';
        scanf("%c",&c);
    }
    node *ptr = start;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    while(start != NULL) {
        node *temp  = start;
        start = start->next;
        free(temp);
    }
}