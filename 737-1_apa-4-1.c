#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *parent;
    struct node *left;
    struct node *right;
}node;
typedef struct tree{
    struct node *root;
    int amount;
}tree;
typedef struct listnode{
    node *ptr_node_tree;
    struct listnode *next;
} listnode;
void init(tree *tree1){
    tree1 -> root = NULL;
}
typedef struct list{
    listnode *head;
    listnode *tail;
}list;
void createlist(list *list){
    list -> head = NULL;
    list -> tail = NULL;
}
int push(list *list, node *node){
    listnode *new = (listnode*)malloc(sizeof(listnode));
    new -> ptr_node_tree = node;
    new -> next = NULL;
    if (list -> head)
        list -> tail -> next = new;
    else
        list -> head = new;
    list -> tail = new;
    return 0;
}
void clearlist(list *list){
    listnode *vsp, *vsp2;
    vsp = list -> head;
    do{
        vsp2 = vsp;
        vsp = vsp -> next;
        free(vsp2);
    }while (vsp);
    list -> head = NULL;
    list -> tail = NULL;
}
int RemoveMin(tree *tree, node *node){
    tree -> amount--;
    if (tree -> amount != 1){
        while (node -> left != NULL){
            node = node -> left;
        }
        if (node -> right != NULL){
            node -> right -> parent = node -> parent;
            if (node == tree -> root){
                tree -> root = node -> right;
            }
            else{
                node -> parent -> left = node -> right;
            }
        }
        else{
            node -> parent -> left = NULL;
            int value = node -> value;
            free(node);
            return value;
        }
    }
    else{
        tree -> root = NULL;
        tree -> amount = 0;
        free(tree -> root);
        return 0;
    }
}
void clear(tree *tree){
    while (tree -> root != NULL){
        RemoveMin(tree, tree -> root);
    }
}
node *findvsp(node *node, int value) {
    if ((node == NULL) || (node -> value == value)){
        return node;
    }
    if (value < node -> value){
        return findvsp(node -> left, value);
    }
    else{
        return findvsp(node -> right, value);
    }
}
int find(tree *tree, int value, node **node){
    if (findvsp(tree -> root, value) == NULL){
        return 1;
    }
    *node = findvsp(tree -> root, value);
    return 0;
}
int insert(tree *tree, int value){
    node *vsp = (node*)malloc(sizeof(node));
    vsp -> value = value;
    if (tree -> root == NULL){
        vsp -> left = vsp -> right = NULL;
        vsp -> parent = NULL;
        tree -> root = vsp;
        tree -> amount = 1;
        return 0;
    }
    if (vsp -> value == tree -> root -> value)
        return -1;
    node *vsp2 = (node*)malloc(sizeof(node)), *vsp3 = NULL;
    vsp2 = tree -> root;
    while (vsp2 != NULL)
    {
        vsp3 = vsp2;
        if (value < vsp2 -> value)
            vsp2 = vsp2 -> left;
        else
            vsp2 = vsp2 -> right;
    }
    if (vsp -> value == vsp3 -> value){
        return -1;
    }
    vsp -> parent = vsp3;
    vsp -> left = NULL;
    vsp -> right = NULL;
    if (value < vsp3 -> value)
        vsp3 -> left = vsp;
    else
        vsp3 -> right = vsp;
    tree -> amount++;
    return 0;
}
node* removevsp(node* tree, int value){
    node* vsp;
    if (!tree){
        return tree;
    }
    else if (value < tree -> value){
        tree -> left = removevsp(tree -> left, value);
    }
    else if (value > tree -> value){
        tree -> right = removevsp(tree -> right, value);
    }
    else{
        if (tree -> left && tree -> right){
            vsp = tree -> right;
            while (vsp -> left != NULL){
                vsp = vsp -> left;
            }
            vsp -> left = tree -> left;
            vsp = tree -> right;
            free(tree);
            return vsp;
        }
        else if (tree -> left == tree -> right){
            free(tree);
            return NULL;
        }
        else{
            if (!tree -> left) vsp = tree -> right;
            else vsp = tree -> left;
            free(tree);
            return vsp;
        }
    }
    return tree;
}
int Remove(tree *tree, int value){
    node *vsp = removevsp(tree->root, value);
    if(!vsp)
        return 1;
    else{
        tree->amount--;
        tree->root = vsp;
        return 0;
    }
}
int rotateRight(tree *tree){
    node *vsp = tree->root->left;
    if (vsp == NULL){
        return 1;
    }
    tree -> root -> left = vsp -> right;
    vsp -> right = tree -> root;
    vsp -> parent = tree -> root -> parent;
    tree -> root -> parent = vsp;
    tree -> root = vsp;
    return 0;
}
int rotationLeft(tree *tree){
    node *vsp = tree->root->right;
    if (vsp == NULL){
        return 1;
    }
    tree -> root -> right = vsp -> left;
    vsp -> left = tree -> root;
    vsp -> parent = tree -> root -> parent;
    tree -> root -> parent = vsp;
    tree -> root = vsp;
    return 0;
}
void print(node *node1){
    if (node1){
        list list1, list2;
        list *ptrlist1 = &list1;
        list *ptrlist2 = &list2;
        createlist(ptrlist1);
        createlist(ptrlist2);
        node *vsp = NULL;
        listnode *list = NULL;
        int c = 0, val = node1->value, j = 0;
        node *l = node1->left;
        node *r = node1->right;
        push(ptrlist1, node1);
        while(1){
            while (ptrlist1->head){
                if (ptrlist1->head){
                    node *nodelist_pop;
                    vsp = ptrlist1->head->ptr_node_tree;
                    nodelist_pop = ptrlist1->head;
                    ptrlist1->head = ptrlist1->head->next;
                    if (ptrlist1->head == NULL)
                        ptrlist1->tail = NULL;
                    free(nodelist_pop);
                }else
                    vsp = NULL;
                if (ptrlist1->head == NULL){
                    if (vsp->value == val && c == 1)
                        printf("_\n");
                    else
                        printf("%d\n", vsp->value);
                }
                else if (vsp->value == val && c == 1)
                    printf("_ ");
                else
                    printf("%d ", vsp->value);
                if (vsp->left)
                    push(ptrlist2, vsp->left);
                else
                    push(ptrlist2, node1);
                if (vsp->right)
                    push(ptrlist2, vsp->right);
                else
                    push(ptrlist2, node1);
            }
            node1->left = node1->right = NULL;
            c = 1;
            list = ptrlist2->head;
            while (ptrlist2->head->ptr_node_tree->value == val){
                ptrlist2->head = ptrlist2->head->next;
                if (ptrlist2->head->next == NULL)
                    if (ptrlist2->head->ptr_node_tree->value == val){
                        j = 1;
                        node1->left = l;
                        node1->right = r;
                        clearlist(ptrlist2);
                        break;
                    }
            }
            ptrlist2->head = list;
            if (j == 1)
                break;
            ptrlist1->head = ptrlist2->head;
            ptrlist1->tail = ptrlist2->tail;
            ptrlist2->head = NULL;
            ptrlist2->tail = NULL;
        }
    }
    else
        printf("-\n");
}
void printTree(tree *tree){
    print(tree->root);
}
int main() {
    tree *tree1 = (tree*)malloc(sizeof(node));
    init(tree1);
    int a[4];
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
    for (int i = 0; i < 4; i++) {
        insert(tree1, a[i]);
    }
    print(tree1->root);
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    for (int i = 0; i < 3; i++)
        insert(tree1, a[i]);
    print(tree1 -> root);
    int m;
    scanf("%d", &m);
    node *node1 = (node*)malloc(sizeof(node));
    if (find(tree1, m, &node1) == 1)
        printf("-\n");
    else {
        if (node1->parent == NULL)
            printf("_ ");
        else
            printf("%d ", node1->parent->value);
        if (node1->left == NULL)
            printf("_ ");
        else
            printf("%d ", node1->left->value);
        if (node1->right == NULL)
            printf("_ ");
        else
            printf("%d", node1->right->value);
    }
    printf("\n");
    scanf("%d", &m);
    if (find(tree1, m, node1) == 1)
        printf("-\n");
    else {
        if (node1->parent == NULL)
            printf("_ ");
        else
            printf("%d ", node1->parent->value);
        if (node1->left == NULL)
            printf("_ ");
        else
            printf("%d ", node1->left->value);
        if (node1->right == NULL)
            printf("_ ");
        else
            printf("%d ", node1->right->value);
    }
    scanf("%d", &m);
    Remove(tree1, m);
    print(tree1->root);
    while (rotationLeft(tree1) == 0);
        print(tree1->root);
    while (rotateRight(tree1) == 0);
        print(tree1->root);
    printf("%d\n", tree1->amount);
    clear(tree1);
    print(tree1->root);
    return 0;
}
