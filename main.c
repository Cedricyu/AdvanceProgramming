#include <stdio.h>
#include "list.h"
void print(Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    puts("");
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    Node *lists[n];
    for (int i = 0; i < n; i += 1)
    {
        lists[i] = NULL;
        int m = 0; // list size
        scanf("%d", &m);
        for (int j = 0; j < m; j += 1)
        {
            int data = 0;
            scanf("%d", &data);
            lists[i] = list_insert(lists[i], data);
        }
    }
    Node *result = link_list(lists, n);
    print(result);
    return 0;
}
