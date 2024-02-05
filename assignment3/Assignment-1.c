//66070503448 Phattharapong Duangkham
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int score;
    int ID;
    struct node *next;
}node;

void add(node **start) {
    int id,temp; scanf("%d %d",&id,&temp);
    node *new = (node *)malloc(sizeof(node));
    new->ID = id;
    new->score = temp;
    if(*start == NULL) *start = new;
    else {
        new->next = (*start);
        *start = new;
    }
}

void sortid(node **start,int n) {
    if(n == 1) {
        printf("%d\n",(*start)->score);
        return;
    }
    for(int i=0;i<n;i++) {
        node *curr = *start;
        node *bef = *start;
        for(int j=0;j<(n-1);j++) {
            if((curr->ID > curr->next->ID) && (curr->next != NULL)) {
                int tid = curr->ID;
                curr->ID = curr->next->ID;
                curr->next->ID = tid;
                int tscore = curr->score;
                curr->score = curr->next->score;
                curr->next->score = tscore;
            }
            bef = curr;
            curr = curr->next;
        }
    }
}

void sortscore(node **start,int n) {
    if(n == 1) {
        return;
    }
    for(int i=0;i<n;i++) {
        node *curr = *start;
        node *bef = *start;
        for(int j=0;j<(n-1);j++) {
            if((curr->score > curr->next->score) && (curr->next != NULL)) {
                int tscore = curr->score;
                curr->score = curr->next->score;
                curr->next->score = tscore;
            }
            bef = curr;
            curr = curr->next;
        }
    }
}

int main() {
    int n; scanf("%d",&n);
    node *start = NULL;
    for(int i=0;i<n;i++) {
        add(&start);
    }
    
    int choice; scanf("%d",&choice);
    if(choice == 0) {
        sortid(&start,n);
    }
    else if(choice ==1) {
        sortscore(&start,n);
    }
    node *ptr = start;
    for(int i=0;i<n;i++) {
        printf("%d ",ptr->score);
        ptr = ptr->next;
    }
    printf("\n");
}
//this method is kinda เหลี่ยมนะคัย
