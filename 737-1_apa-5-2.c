#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;
 
typedef struct tree
{
    struct Node *root;
    int count;
} Tree;
void init(Tree *tree) {
 
    tree->root = NULL;
}
int insert(Tree *tree, int value) {
    Node *temp = (Node*)malloc(sizeof(Node));
 
    temp->value = value;
 
 
    if (tree->root == NULL) {
        temp->left = temp->right = NULL;
        temp->parent = NULL;
        tree->root = temp;
        tree->count = 1;
        return 0;
    }
 
    if (temp->value == tree->root->value)
        return -1;
 
    Node *root2 = (Node*)malloc(sizeof(Node)), *root3 = NULL;
 
    root2 = tree->root;
 
    while (root2 != NULL)
    {
        root3 = root2;
        if (value < root2->value)
            root2 = root2->left;
        else
            root2 = root2->right;
    }
 
    if (temp->value == root3->value) {
        return 1;
    }
 
    temp->parent = root3;
    temp->left = NULL;
    temp->right = NULL;
 
    if (value < root3->value)
        root3->left = temp;
    else
        root3->right = temp;
    tree->count++;
    return 0;
}
void print(Tree *rot)
{
    Node *f[15];
    int tmp = 0;
    Node *temp[15];
    int tmp_2 = 0;
    Node * node = rot -> root;
    while(tmp_2 <rot ->count)
    {
        while (node!= NULL)
        {
            tmp_2++;
            if(node -> right != NULL)
            {tmp++;
                f[tmp] = node->right;
            }
            temp[tmp_2] = node;
            node = node->left;
 
        }
        node = f[tmp];
        tmp = tmp -1 ;
    }
    for (int i = 1; i <= tmp_2; i++)
    {
        if (i == tmp_2) {
            printf("%d",temp[i]->value);
        }
        else {
            printf("%d ", temp[i]->value);
        }
    }
    printf("\n");
}
int main()
{
    Tree *tree =malloc(sizeof tree);
    init(tree);
 
    int arr[7];
    scanf("%d%d%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3],&arr[4],&arr[5],&arr[6]);
    for (int i = 0; i < 7; i++){
        insert(tree, arr[i]);}
    print(tree);
 
    return 0;
}
