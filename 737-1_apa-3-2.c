#include<stdio.h>
#include<stdlib.h>
 
typedef struct node{
      int value;
      struct node *next;
      struct node *prev;
}node;
 
typedef struct list{
       struct node *head;
       struct node *tail;
}list;
 
void init(list* t){
      t->head = NULL;
      t->tail = NULL;
 }
 
void deletelist(list* t){
    node* tmp = t->head;
    node* lt;
 
    while(tmp != NULL){
          lt = tmp->next;
          free(tmp);
          tmp = lt;
    }
      t->head = NULL;
      t->tail = NULL;
}
 
int isEmpty(list* t){
     
     if(t->head == NULL && t->tail == NULL){
             return 0;}
     return 1;
}
 
int findplace(list* t, int value){
       node* tmp;
       tmp = t->head;
       while(tmp != NULL){
             if(tmp->value == value)
                      return 1;
             tmp = tmp->next;
       }
       return 0;
}
 
int pushback(list* t, int value){
     node* tmp = malloc(sizeof(node));    
           tmp->value = value;
           tmp->next = NULL;
           tmp->prev = NULL;
 
     if(!isEmpty(t)){
        t->head = tmp;
        t->tail = tmp;
        return 0;
     }
     else {
          tmp->prev = t->tail;
          t->tail->next = tmp;
          t->tail = tmp;
          return 0;
     }
     return 1;
}
 
int pushfront(list* t, int value){
     node* tmp = malloc(sizeof(node));
     tmp->value = value;
     tmp->next = NULL;
     tmp->prev = NULL;
   
     if(!isEmpty(t)){
        t->head = tmp;
        t->tail = tmp;
        return 0;
     }
     else {
          tmp->next = t->head;
          t->head->prev = tmp;
          t->head = tmp;
             return 0;
     }
     return 1;
}
     
int insertAfter(list* t,int num, int value){
     node* tmp = t->head;
     
     for(int i=0; i<num; i++){
         tmp = tmp->next;
            if(tmp == NULL)
                 return 1;
     }
     node* tmp1 = malloc(sizeof(node));
     tmp1->value = value;
 
          if(tmp == t->tail){
             tmp->next = tmp1;
             tmp1->prev = tmp;
             tmp1->next = NULL;
          }
          else {
             tmp1->next = tmp->next;
             tmp1->prev = tmp;
 
             tmp->next = tmp1;
             tmp = tmp->next;
             tmp = tmp->next;
             tmp->prev = tmp1;
                  return 0;
          }
}
 
int insertBefore(list* t, int num, int value){
     node* tmp = t->head;
 
     for(int i=0; i<num; ++i){
         tmp = tmp->next;
         if(tmp == NULL)
            return 1;
     }
     node* tmp1 = malloc(sizeof(node));
     tmp1->value = value;
        if(tmp == t->head){
           tmp->prev = tmp1;
           tmp1->next = tmp;
           tmp1->prev = NULL;
           t->head = tmp1;
        }
        else {
           tmp1->prev = tmp->prev;
           tmp1->next = tmp;
 
           tmp->prev = tmp1;
           tmp = tmp->prev;
           tmp = tmp->prev;
           tmp->next = tmp1;
                return 0;
        }
}
   
int delPer(list* t, int value){
     node* tmp = t->head;
     node* lt;
 
     while(tmp != NULL){
           lt = tmp;
            if(tmp->value == value){
               if(tmp == t->head){
                  tmp = tmp->next;
                  tmp->prev = NULL;
                  free(lt);
               }
               else if(tmp == t->tail){
                    tmp = tmp->prev;
                    tmp->next = NULL;
                    free(lt);
                    t->tail = tmp;
               }
               else {
                    tmp = lt->next;
                    tmp->prev = lt->prev;
                    tmp = lt->prev;
                    tmp->next = lt->next;
                    free(lt);
               }
               return 0;
             }
             tmp = tmp->next;
       }
       return 1;    
}
 
int delLast(list* t, int value){
     node* tmp = t->tail;
     node* lt;
 
     while(tmp != NULL){
           lt = tmp;
           if(tmp->value == value){
 
              if(tmp == t->tail){
                 tmp = tmp->prev;
                 tmp->next = NULL;
                 free(lt);
              }
              else if(tmp == t->head){
                      tmp = tmp->next;
                      tmp-> prev = NULL;
                      free(lt);
                      t->head = tmp;
              }
              else {
                    tmp = lt->next;
                    tmp->prev = lt->prev;
                    tmp = lt->prev;
                    tmp->next = lt->next;
                    free(lt);
               }
               return 0;
             }
             tmp = tmp->prev;
        }
        return 1;
}
                     
void printlist(list* t){
     node* tmp;
     tmp = t->head;
 
     while(tmp != NULL){
           printf("%d", tmp->value);
           tmp = tmp->next;
     if(tmp != NULL)
        printf(" ");
     }
     printf("\n");
}
 
void printinv(list* t){
     node* tmp;
     tmp = t->tail;
 
     while(tmp != NULL){
           printf("%d", tmp->value);
           tmp = tmp->prev;
       if(tmp != NULL)
              printf(" ");
     }
     printf("\n");
}
 
int main(){
     int n, x, y;
     list* ls;
 
     init(ls);
     scanf("%d", &n);
     for(int i=0; i<n; i++){
         scanf("%d", &x);
         pushback(ls, x);
     }
     printlist(ls);
 
     for(int i=1; i<=3; i++){
         scanf("%d", &y);
         printf("%d", findplace(ls, y));
     }
     printf("\n");
 
     scanf("%d", &x);
     pushback(ls, x);
 
     printinv(ls);
 
     scanf("%d", &x);
     pushfront(ls, x);
     printlist(ls);
 
     scanf("%d %d", &x, &y);
     insertAfter(ls, x-1, y);
 
     printinv(ls);
 
     scanf("%d %d", &x, &y);
     insertBefore(ls, x-1, y);
 
     printlist(ls);
 
     scanf("%d", &x);
     delPer(ls, x);
 
     printinv(ls);
 
     scanf("%d", &x);
     delLast(ls, x);
 
     printlist(ls);
     deletelist(ls);
     return 0;
}
