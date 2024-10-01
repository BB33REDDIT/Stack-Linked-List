#include <stdio.h>
#include <stdlib.h>
int c = 0;
struct node 
{
    int val;
    struct node *next;
};
struct node *head = NULL;

void push(int val) 
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) 
    {
        printf("Unable to push element.\n");
        return;
    }
    new_node->val = val;
    new_node->next = head;
    head = new_node;
    printf("Item pushed successfully.\n");
}

void pop() 
{
    if (head == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Item popped successfully.\n");
}

void display() 
{
    if (head == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    struct node *current = head;
    printf("Stack elements:\n");
    while (current != NULL) 
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main() 
{
    while (c != 4) 
    {
        printf("\nChoose Operation:\n");
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) 
        {
            case 1:
                int val;
                printf("Enter the value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);  
                break; 
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
