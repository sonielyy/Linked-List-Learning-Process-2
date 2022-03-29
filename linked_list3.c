#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

typedef struct node node;

void print_nodes(node *r)
{
    while (r != NULL) 
    {
        printf("Integer Value: %d\n", r-> number);
        r = r-> next;
    }
}
node * add_order(node *r, int new_num) 
{
    if (r == NULL)  // Linked List is Empty
    {
        r = (node *) malloc (sizeof(node));
        r -> next = NULL;
        r -> number = new_num;
        return r;
    }
    if (r -> number > new_num) // Linked List isn't empty and new_num < number
    {
        //root is changing!
        struct node *temp;
        temp = (node *) malloc (sizeof(node));
        temp -> number = new_num;
        temp -> next = r;
        return temp;
    }
    struct node *iter;
    iter = r;

    while (iter-> next != NULL && iter-> next -> number < new_num) // Detecting the NULL or Bigger Node Value than new_num
    {
        iter = iter->next;

    }
    
    struct node *temp;
    temp = (node*) malloc (sizeof(node)); // Create new node when NULL or biggest value.
    temp -> number = new_num;
    temp -> next = iter -> next;
    iter -> next = temp;
    return r;

}
int main() 
{
    struct node *root;
    root = NULL;
    root = add_order(root, 50);
    root = add_order(root, 450);
    root = add_order(root, 70);
    root = add_order(root, 80);
    print_nodes(root);

    return 0;
}