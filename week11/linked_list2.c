/* Some linked list examples. See textbook 17.5 for more code.
 *
 * Sam Scott, McMaster University, 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 100

/* The node type contains a next pointer */
struct node {
    char name[N+1];
    int grade;
    struct node *next;
};

/* returns TRUE if head is null (list is empty) */
bool is_empty(struct node *head) {
    return head == NULL;
}

/* prepends a node containing the given name and grade at the head of a list 
 * returns the new head 
 */
struct node *prepend(struct node *head, char *name, int grade) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) 
        exit(EXIT_FAILURE);

    strcpy(newnode->name, name);
    newnode->grade = grade;
    newnode->next = head;

    return newnode;
}

struct node *append(struct node *head, char *name, int grade) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL)
        exit(EXIT_FAILURE);

    strcpy(newnode->name, name);
    newnode->grade = grade;
    newnode->next = NULL;

    // Special case: empty list
    if (head == NULL) {
        return newnode;
    }

    // Traverse to the end of the list
    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    // Attach the new node
    p->next = newnode;

    return head;
}

struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;  // Save next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev forward
        current = next;        // Move current forward
    }

    return prev;  // New head is the previous last node
}

/* deletes the head of a list. Returns the new head. */
struct node *delete_first(struct node *head) {
    if (head == NULL) 
        return head;
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

/* destroys a list from head onwards. Returns NULL. */
struct node *destroy_list(struct node *head) {
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}

/* prints the contents of a list given the head. */
void print_list(struct node *head) {
    if (head == NULL) {
        puts("*** empty list ***");
        return;
    }
    while (head != NULL) {
        printf("%s: %d\n", head->name, head->grade);
        head = head->next;
    }
}

/* find a student grade */
int find_grade(struct node *head, char *name) {
    struct node *p = head;
    while (p != NULL) {
        if (strcmp(p->name, name) == 0)
            return p->grade;
        p = p->next;
    }
    return -1;
}

/* delete a student by name */
struct node *delete_by_name(struct node *head, char *name) {
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = head->next;
                free(current);
            } else {
                previous->next = current->next;
                free(current);
            }
            return head;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

int count(struct node *head, int value) {
    int count = 0;
    struct node *p = head;
    while (p != NULL) {
        if (p->grade > value) {
            count++;
        }
        p = p->next;
    }
    return count;
}

/* main function - some simple tests of above functions */
void main() {
    struct node *list = NULL;

    puts("\nLIST CREATED");
    print_list(list);

    puts("\nADDING NODES");
    list = prepend(list, "Sam Scott", 99);
    list = prepend(list, "Anne St-Amand", 85);
    list = prepend(list, "Rosa St-Amand", 78);
    list = prepend(list, "Maxime St-Amand", 65);
    print_list(list);

    puts("\nREVERSING LIST");
    list = reverse(list);
    print_list(list);

    puts("\nFINDING GRADES");
    int grade = find_grade(list, "Rosa St-Amand");
    printf("Rosa St-Amand: %d\n", grade);
    grade = find_grade(list, "Louise St-Amand");
    printf("Louise St-Amand: %d\n", grade);

    puts("\nAPPENDING NODES");
    list = append(list, "Alex St-Amand", 88);
    list = append(list, "Louise St-Amand", 91);
    print_list(list);

    puts("\nCOUNTING GRADES ABOVE 80");
    int count_above_80 = count(list, 80);
    printf("Number of grades above 80: %d\n", count_above_80);

    puts("\nCOUNTING GRADES ABOVE 50");
    int count_above_50 = count(list, 50);
    printf("Number of grades above 50: %d\n", count_above_50);

    puts("\nREMOVE TWO NODES BY NAME");
    list = delete_by_name(list, "Sam Scott");
    list = delete_by_name(list, "Rosa St-Amand");
    print_list(list);

    puts("\nDESTROYING LIST");
    list = destroy_list(list);
    print_list(list);
}
