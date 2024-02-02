#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

void addbegin(node **start,int val) {
    node *new = (node *)malloc(sizeof(node));
    new->next = *start;
    new->data = val;
    *start = new;
}

void addlast(node **start,int val) {
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;

    if(*start == NULL) {
        *start = new;
    } else {
        node *last = *start;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    node *start = NULL;
    int option;
    scanf("%d",&option);
    if(n<1) {
        printf("Invalid\n");
        return 0;
    }
    if(option == 2){
        for(int i=0;i<n;i++) {
            int t;
            scanf("%d",&t);
            addlast(&start,t);
        }
    }
    else if(option == 1) {
        for(int i=0;i<n;i++) {
            int t;
            scanf("%d",&t);
            addbegin(&start,t);
        }
    }
    else {
        printf("Invalid\n");
        return 0;
    }
    node *ptr = start;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");


    while (start != NULL) {
        node *temp = start;
        start = start->next;
        free(temp);
    }
    return 0;
}