#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define true 1
#define false 0
typedef int bool;


typedef struct Node {
    int val;
    struct Node *prev, *next;
}Node;

typedef struct DList{
    Node *head;
    Node *tail;
    int size;
}DList;

DList* createDList(){
    DList *D = (DList*)malloc(sizeof(DList));
    D->head = D->tail = NULL;
    D->size = 0;
    return D;
}

void insert(DList* D, int val){
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->prev = node->next = NULL;

    if (D->size == 0) 
        D->head = D->tail = node;
    else{
        if (D->tail->next == NULL){
            D->tail->next = node;   //'''next 不一定是下一個'''
            node->prev = D->tail;
            D->tail = node;
        }
        else if ( D->tail->prev == NULL){
            D->tail->prev = node;
            node->next = D->tail;
            D->tail = node;
        }
    }
    ++D->size;
}


void message(char* message){
    printf("%s\n", message);
}


void pop_back(DList* D){
    if (D->size == 0)
        return;
    else if (D->size == 1)  //only one node
    {
        free(D->tail);
        D->tail = D->head = NULL;
        D->size = 0;
    }
    else
    {
        Node *ptr = D->tail;
        if (D->tail->next == NULL){
            ptr = ptr->prev;
            ptr->next = NULL;
            free(D->tail);
            D->tail = ptr;
        }
        else if (D->tail->prev == NULL){
            ptr = ptr->next;
            ptr->prev = NULL;
            free(D->tail);
            D->tail = ptr;
        }
        --D->size;
    }
}



void reverse(DList* D){
    Node *temp = D->head;
    D->head = D->tail;
    D->tail = temp;
}


void migrate(DList* a, DList* b) // ra-th rail is shut down, and all its cabins is migrated into the rb-th
{
    if (a->size == 0)  //a has no node
        return ;
    
    else if (b->size == 0)   // b has no node
    {
        b->head = a->tail;
        b->tail = a->head;
        a->tail = a->head = NULL;
        b->size = a->size;
        a->size = 0;
        // assert(2 == 3);
    }
    else  //  b has at least one node
    {
        reverse(a);
        if (b->tail->next == NULL){
            b->tail->next = a->head;
            if (a->head->prev == NULL){
                a->head->prev = b->tail;
            }
            else if (a->head->next == NULL){
                a->head->next = b->tail;
            }
        }
        else if (b->tail->prev == NULL){
            b->tail->prev = a->head;
            if (a->head->next == NULL){
                a->head->next = b->tail;
            }
            else if (a->head->prev == NULL){
                a->head->prev = b->tail;
            }
        }
        b->tail = a->tail;
        a->head = a->tail = NULL;
        b->size += a->size;
        a->size = 0;
    }
    // assert(b->tail != NULL);
}


void print(DList* D){
    if (D->size == 0)
    {
        printf("\n");
        return;
    }
    Node *curNode = D->head;
    Node *prevNode = D->head;
    while (true)
    {   

        if (curNode == D->tail){
            printf("%d\n", curNode->val);
            break;
        }
        // printf("sdf ");
        Node *nextNode = NULL;   //你確定 next 真的是next?
        if (curNode->prev == NULL){  //如果curnode的prev是NULL，next就是下一個
            nextNode = curNode->next;
        }
        else if (curNode->next == NULL){  //不然如果curnode的next是NULL，prev就是下一個
            nextNode = curNode->prev;
        }
        else if (curNode->next == prevNode){   //不然如果curnode的next是上一個node,prev就是下一個
            nextNode = curNode->prev;
        }
        else if (curNode->prev == prevNode){  //不然如果curnode的prev是上一個node,next就是下一個
            nextNode = curNode->next;
        }

        // now nextNode is the True nextNode

        printf("%d ", curNode->val);
        prevNode = curNode;
        curNode = nextNode;

    }

}

char cmd[10];
int r, l, ra, rb;
int main()
{
    int numOfRail_k, numOfRec_n;
    scanf("%d %d", &numOfRail_k, &numOfRec_n);
    // printf("%d %d", numOfRail_k, numOfRec_n);
    DList **dl = malloc(sizeof(DList*) * numOfRail_k);
    for(int i = 0; i < numOfRail_k; ++i){    
        int temp;
        dl[i] = createDList();
    }
    while(numOfRec_n > 0){
        --numOfRec_n;
        scanf("%s", cmd);
        // message(cmd);
        if (strcmp(cmd, "enter") == 0){
            scanf("%d %d", &r, &l);
            if (r >= numOfRail_k)
                continue;
            insert(dl[r], l);
        }
        else if (strcmp(cmd, "leave") == 0){
            scanf("%d", &r);
            if (r >= numOfRail_k)
                continue;
            pop_back(dl[r]);
        }
        else if (strcmp(cmd, "migrate") == 0){
            scanf("%d %d", &ra, &rb);
            if (ra >= numOfRec_n || rb >= numOfRec_n)
                continue;
            migrate(dl[ra], dl[rb]);
            // message("test");
        }
        for(int i = 0; i < numOfRail_k; ++i)
        {    
            printf("rail %d , size = %d: ", i, dl[i]->size);
            print(dl[i]);
        // message("tes");
            if (dl[i]->size > 1 ){
            assert((dl[i]->head->next != NULL) || (dl[i]->head->prev != NULL));
            assert((dl[i]->tail->next != NULL) || (dl[i]->tail->prev != NULL));
            }
        }
            printf("\n");
    }
    for(int i = 0; i < numOfRail_k; ++i)
    {    
        // reverse(dl[i]);
        print(dl[i]);
        free(dl[i]);
    }
    free(dl);
    return 0;
}

