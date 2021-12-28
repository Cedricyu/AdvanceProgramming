#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

Node *genListNode(int data,Node *next){
    Node *node = (Node *)malloc(sizeof(Node));
    node ->data = data;
    node ->next = next;
    return  node;
}
Node* list_insert(Node* node, int data)
{
    Node *n= (Node *)malloc(sizeof(Node));
    assert(n != NULL);
    n->next = node;
    n->data = data;
    return n;
}

Node* insert(Node* node, int data) {
    if(node == NULL)
        return (genListNode(data, node));

    node->next = insert(node->next, data);
    return (node);
}
Node* link_list(Node* lists[], int n)
{
    Node *revert[n];
    for (int i=0;i<n;i++){
        revert[i] = NULL;
        if (i%2==0)
            for (Node *cur = lists[i];cur != NULL ;cur= cur->next){
                revert[i] = list_insert(revert[i],cur->data);
            }
        else{
            revert[i] = lists[i];
        }
        //print(revert[i]);
    }
    int current =0;
    Node *head = revert[0];
    while (current < n){
        //printf("current = %d\n",current);
        Node *end = revert[current];
        if (end == NULL)
            return end;
        while(end->next!= NULL){
            end = end->next;
        }
        int next = current+1;
        if (next >=n){
            end->next = NULL;
            break;
        }
        //printf("next = %d\n",next);
        while(revert[next]==NULL){
            next ++;
            current ++;
        }
        end->next = revert[next];
        current++;
    }
    return head;
}
