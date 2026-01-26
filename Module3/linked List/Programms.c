1.*Code to Create a Node (Using malloc)*

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *newNode;

    // Allocate memory for one node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation is successful
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign data and initialize next pointer
    newNode->data = 10;
    newNode->next = NULL;

    printf("Node created successfully\n");
    printf("Data = %d\n", newNode->data);

    return 0;
}

OUTPUT:
Node created successfully
Data = 10

🔹 Creating a Singly Linked List in C

✅ What this program does:
Creates multiple nodes
Links them using next
Displays the list

#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        // Create a new node
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        // Linking nodes
        if (head == NULL) {
            head = newNode;   // first node
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Display the linked list
    printf("\nSingly Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

OUTPUT:
Enter number of nodes: 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30

Singly Linked List: 10 -> 20 -> 30 -> NULL

**Program of creating a Simply linked list.**
Complete Simple Program
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *second;

    // First node
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    // Second node
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 20;
    second->next = NULL;

    // Linking
    head->next = second;

    // Display list
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}

🔹 Output
10 -> 20 -> NULL

Traversing a Singly Linked List in C

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, count = 0, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Creating the linked list
    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;   // first node
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traversing and counting
    temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        count++;
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Total number of nodes = %d\n", count);

    return 0;
}

OUTPUT:
Enter number of nodes: 3
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30

Linked List: 10 -> 20 -> 30 -> NULL
Total number of nodes = 3

Insertion at the end of a Singly Linked List in C

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int value, choice = 1;

    while (choice) {
        // Create new node
        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        // Insert at end
        if (head == NULL) {
            head = newNode;   // empty list
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        printf("Do you want to insert another node? (1/0): ");
        scanf("%d", &choice);
    }

    // Display the list
    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

OUTPUT:
Enter data: 10
Do you want to insert another node? (1/0): 1
Enter data: 20
Do you want to insert another node? (1/0): 1
Enter data: 30
Do you want to insert another node? (1/0): 0

Linked List: 10 -> 20 -> 30 -> NULL
