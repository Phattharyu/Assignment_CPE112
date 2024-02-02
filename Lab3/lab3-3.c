#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void add(node **start,int val) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if(*start == NULL) {
        *start = temp;
    } else {
        node *last = *start;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

void firstdel(node **start) {
    if(*start == NULL) return;
    node *pt = *start;
    *start = pt->next;
    free(pt);
}

void lastdel(node **start) {
    if(*start == NULL) return;
    node *pt = *start;
    node *slow = *start;

    while(pt->next != NULL) {
        slow = pt;
        pt = pt->next;
    }
    if(slow == pt) *start = NULL;
    else slow->next = NULL;
    free(pt);
}

void Ndel(node **start , int val) {
    node *ptr = *start;
    node *slow = *start;
    int cnt=0;
    while(ptr->data != val) {
        slow = ptr;
        ptr = ptr->next;
        cnt++;
        if(ptr == NULL) return;
    }
    if(cnt == 0) {
        ptr = ptr->next;
        *start = ptr;
        free(slow);
    } else {
        if(ptr->next == NULL) {
            slow->next = NULL;
            free(ptr);
        } else {
            node *fast = ptr->next;
            slow->next = fast;
            free(ptr);
        }
    }
}

void clearmem(node **start) {
    node *clear = *start;
    node *ptr = clear->next;
    while(ptr != NULL) {
        clear = ptr;
        ptr = ptr->next;
        free(clear);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    node *start = NULL;
    //Input numbers to list
    for(int i=0;i<n;i++) {
        int t; scanf("%d",&t);
        add(&start,t);
    }
    char c;
    scanf("%c",&c);
    while(c != 'E') {
        if(c == 'F') {
            firstdel(&start);
        }
        else if(c == 'L') {
            lastdel(&start);
        }
        else if(c == 'N') {
            int te; scanf("%d",&te);
            Ndel(&start,te);
        }
        node *p = start;
        int cnt=0;
        while(p != NULL) {
            p = p->next;
            cnt++;
        }
        if(cnt == 0) {
            printf("none\n");
            return 0;
        }
        scanf("%c",&c);
    }
    node *p = start;
    int cnt=0;
    while(p != NULL) {
        p = p->next;
        cnt++;
    }
    if(cnt == 0) {
        printf("none\n");
        return 0;
    } else {
        node *ptr = start;
        while(ptr != NULL) {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return 0;
}
