/*NAME : Chinmay Rane
  batch : D
  Rollno : 55
  Experiment : POSTFIX TO INFIX (expression tree)
*/

// postfix to infix (tree)
#include <stdio.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node * left;
    struct node * right;
}node;

struct node * stack[50];
int top = -1;

struct node * pop();
struct node * tree(char in[50]);
void inorder(struct node * );

void main()
{
    struct node * root;
    char input[50];
    int i;

    printf("Please enter the postfix expression:\n");
    gets(input);

    root = tree(input);

    printf("The infix expression is as follows\n");
    inorder(root);

}

struct node * tree(char in[50])
{
    int i;
    struct node * temp;
    char a;

    for(i = 0; i< strlen(in); i++)
    {
        a = in[i];
        if(a == '*' || a=='/' || a == '+' || a == '-')
        {
            temp = (node *)malloc(sizeof(node));
            temp->data = a;

            temp->right = pop();
            temp->left = pop();

            stack[++top] = temp;

        }
        else
        {
            temp = (node *)malloc(sizeof(node));
            temp->data = a;

            temp->right = NULL;
            temp->left = NULL;

            stack[++top] = temp;

        }
    }//end of for loop

    if(top != 0)
    {
        printf("\nPlease enter a valid postfix expression\n");
        return NULL;
    }
    else
    {
        return stack[top];
    }

}

struct node * pop()
{
    if(top == -1)
    {
        printf("The stack is empty!");
        return NULL;
    }
    else
    {
        printf("pop : %c\n",(stack[top]->data));
        return (stack[top--]);
    }
}

void inorder(struct node* temp)
{
     if (temp == NULL)
     {
         return;
     }

     inorder(temp->left);

     printf("%c ", temp->data);

     inorder(temp->right);

}

/*OUTPUT:
celab4-2@CELAB4-2:~/Desktop$ ./a.out
Please enter the postfix expression:
ab*cd+pq/*-
pop : b
pop : a
pop : d
pop : c
pop : q
pop : p
pop : /
pop : +
pop : *
pop : *
The infix expression is as follows
a * b - c + d * p / q 
*/