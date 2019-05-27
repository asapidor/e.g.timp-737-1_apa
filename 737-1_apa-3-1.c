#include <stdio.h>
#include <stdlib.h> 
struct node {
    int value;
    struct node *next;
} node;
 
struct list {
    struct node *head;
    struct node *tail;
} list;
 
void init(struct list* l, int value) {
    struct node* ln;
    ln = (struct node*)malloc(sizeof(struct node));
    ln -> value = value;
    ln -> next = NULL;
    l -> head = ln;
}
 
void clear(struct list* l) {
    struct node *ln = l -> head;
    struct node *lf = NULL;
    while (ln != NULL) {
        lf = ln ->next;
        free(ln);
        ln = lf;
    }
    l -> head = NULL;
}
 
int isEmpty(struct list* l) {
    return l -> head == NULL;
}
 
struct node* find(struct list* l, int value) {
    struct node *ln = l -> head;
    while (ln -> value != value) {
        if (ln -> next != NULL) {
            ln = ln -> next;
        }
        else {
            return 0;
        }
    }
    return ln;
}
 
int push_back(struct list* l, int value) {
    if(isEmpty(l) == 1) {
        init(l, value);
    }
    else {
        struct node* ln = (struct node*) malloc(sizeof(struct node));
        ln -> value = value;
        ln -> next = NULL;
        struct node* pre = l -> head;
        while (pre -> next != NULL) {
            pre = pre -> next;
        }
        pre -> next = ln;
    }
    return 0;
}
 
int push_front(struct list* l, int value) {
    if (isEmpty(l) == 1) {
        init(l, value);
    }
    else {
        struct node* ln = (struct node*) malloc(sizeof(struct node));
        ln->value = value;
        ln->next = l->head;
        l->head = ln;
    }
    return 0;
}
 
int insertAfter(struct list* l, int next, int value) {
    struct node* ln = malloc(sizeof(node));
    ln -> value = value;
    struct node* prs = l -> head;
    struct  node* pre = l -> head;
    for (int i = 0; i <  next; i++) {
        pre = prs;
        prs = prs -> next;
        if (prs == NULL) {
            return 1;
        }
    }
    pre -> next = ln;
    ln -> next = prs;
    return 0;
}
 
void remvsp(struct list* l, struct node *ln) {
    if(ln != NULL){
        if (ln == l -> head) {
            l->head = ln->next;
        }
        else
        {
            struct node *ad = (struct node*)malloc(sizeof(struct node));
            ad = l -> head;
            while(ad -> next != ln)
                ad = ad -> next;
            ad -> next = ln -> next;
        }
        free(ln);
    }
}
 
int rem(struct list* l, int value) {
    struct node* ln = find(l, value);
    if (ln != NULL){
        remvsp(l, ln);
        return 0;
    }
    return 1;
}
 
void print(struct list* l) {
    struct node* ln = l -> head;
    while (ln -> next != NULL) {
        printf("%d ", ln -> value);
        ln = ln -> next;
    }
    printf("%d\n", ln -> value);
}
 
int main() {
    int n, value, k[3], m, t, x, j, z;
    struct list* list = (struct list*)malloc(sizeof(struct list));
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push_back(list, value);
    }
    print(list);
    scanf("%d%d%d", &k[0], &k[1], &k[2]);
    for (int i = 0; i < 3; i++) {
        if (find(list, k[i]) == NULL) {
            printf("0");
        }
        else {
            printf("1");
        }
    }
    printf("\n");
    scanf("%d", &m);
    push_back(list, m);
    print(list);
    scanf("%d", &t);
    push_front(list, t);
    print(list);
    scanf("%d", &x);
    scanf("%d", &j);
    insertAfter(list, x, j);
    print(list);
    scanf("%d", &z);
    rem(list, z);
    print(list);
    clear(list);
    return 0;
}
