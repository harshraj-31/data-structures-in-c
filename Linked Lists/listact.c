#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Global pointers */
struct node *list1 = NULL;
struct node *list2 = NULL;
struct node *startList1 = NULL;
struct node *startList2 = NULL;
struct node *unionList = NULL;
struct node *intersection = NULL;

/* Create List 1 */
void createL1(int value) {
    struct node *newNode, *ptr;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (list1 == NULL) {
        list1 = newNode;
        startList1 = list1;
    } else {
        ptr = list1;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}

/* Create List 2 */
void createL2(int value) {
    struct node *newNode, *ptr;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (list2 == NULL) {
        list2 = newNode;
        startList2 = list2;
    } else {
        ptr = list2;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}

/* Check if value exists */
int exists(struct node *ptr, int value) {
    while (ptr != NULL) {
        if (ptr->data == value)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

/* Find Union */
void findUnion() {
    struct node *ptr, *newNode;

    unionList = NULL;

    /* Copy list1 */
    ptr = startList1;
    while (ptr != NULL) {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = ptr->data;
        newNode->next = unionList;
        unionList = newNode;
        ptr = ptr->next;
    }

    /* Add unique elements from list2 */
    ptr = startList2;
    while (ptr != NULL) {
        if (!exists(unionList, ptr->data)) {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = ptr->data;
            newNode->next = unionList;
            unionList = newNode;
        }
        ptr = ptr->next;
    }
}

/* Find Intersection */
void findIntersection() {
    struct node *ptr, *newNode;

    intersection = NULL;

    ptr = startList1;
    while (ptr != NULL) {
        if (exists(startList2, ptr->data) &&
            !exists(intersection, ptr->data)) {

            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = ptr->data;
            newNode->next = intersection;
            intersection = newNode;
        }
        ptr = ptr->next;
    }
}

/* Display list */
void display(struct node *ptr) {
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* Main with menu */
int main() {
    int choice, value;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Find Union\n");
        printf("6. Find Intersection\n");
        printf("7. Display Union\n");
        printf("8. Display Intersection\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            createL1(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            createL2(value);
            break;

        case 3:
            printf("List 1: ");
            display(startList1);
            break;

        case 4:
            printf("List 2: ");
            display(startList2);
            break;

        case 5:
            findUnion();
            printf("Union created\n");
            break;

        case 6:
            findIntersection();
            printf("Intersection created\n");
            break;

        case 7:
            printf("Union: ");
            display(unionList);
            break;

        case 8:
            printf("Intersection: ");
            display(intersection);
            break;

        case 9:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}
