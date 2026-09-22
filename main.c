#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int item;
    struct Node * next;
} Node, LinkedList;

LinkedList * CreateList () {
    Node * head = malloc(sizeof(Node));
    
    if (head == NULL)
        exit(1);

    head->next = NULL;
    return head;
}

void addItem(LinkedList * list, int item) {
    Node * new = malloc(sizeof(Node));
    
    if (new == NULL)
        exit(1);

    new->item = item;
    new->next = NULL;

    LinkedList * current = list;

    while (current->next != NULL)
        current = current->next; 

    current->next = new;
    printf("Success!\n");
    
}

int RemoveItem(LinkedList * list, int item) {
    LinkedList * current = list;

    while (current->next != NULL && (current->next)->item != item)
        current = current->next;

    if (current->next == NULL) {
        printf("item not found\n");
        return -1;
    }

    Node * target_node = (current->next);
    int target = target_node->item;

    current->next = target_node->next;

    target_node->next = NULL;
    free(target_node);
        
    printf("Success!\n");
    return target;
}


void printList(LinkedList * list) {
   if (list->next == NULL) {
        printf("it is an empty-list\n");
        return;    
   }
    LinkedList * current = list->next; 
    while (current->next != NULL) {
        printf("( %d ) --->  ", (current)->item);
        current = (current)->next;
    }
    printf("( %d ) ---> NULL\n\n", (current)->item);
    
}


void RemoveList (LinkedList ** list) {
    if (list == NULL || *list == NULL) return;
    
    LinkedList * current = *list;

    while (current->next != NULL) {
        Node * temp = current;
        current = current->next;
        free(temp);
    }

    *list = NULL;
    printf("Success!");
}


int main() {
    LinkedList * list = CreateList();
    
    printf("\nEND\n");
    return 0;
}
