#pragma once

typedef struct s_node {
    int data;
    struct s_node *next;
} Node;

///////////////////////////
// Must implement function
//
Node* list_insert(Node* node, int data);
Node* link_list(Node* lists[], int n);
//void print(Node *head);
///////////////////////////
