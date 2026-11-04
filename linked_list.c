#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning() {
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;
}

void insertAtEnd() {
    struct Node *newNode, *temp;

    newNode = malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted\n");
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void search() {
    int key, position = 1;
    struct Node *temp = head;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n",
                   position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element not found\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- LINKED LIST OPERATIONS ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtBeginning();
                break;

            case 2:
                insertAtEnd();
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                display();
                break;

            case 5:
                search();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
