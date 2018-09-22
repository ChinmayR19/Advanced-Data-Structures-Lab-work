/*NAME : Chinmay Rane
  Batch : D
  RollNo : 55
  Exp no. : 5(avl tree)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
    int bf;

}node;

struct node* newnode();
struct node* insertion(struct node*, struct node *);
void traversal(struct node*);
struct node* deletion(struct node * , int );
struct node* minvalue(struct node * );
int maxheight(int , int );
int height(struct node *);
struct Node *rightRotate(struct node *);
struct Node *leftRotate(struct node *);
int Balancefactor(struct node *);

void main()
{
    struct node* root = NULL;
    struct node * temp;
    char c;
    int choice, d;

    do
    {
    printf("\nSelect your choice:");
    printf("\n1.Insertion\n2.Deletion");
    printf("\n3.Traversal\n4.exit\n:");
    scanf(" %d", &choice);

    switch(choice)
        {
             case 1: do
                     {
                        temp = newnode();
                        root = insertion(root, temp);

                        printf("Do you want to continue?[y/n]");
                        scanf(" %c", &c);

                     }while(c != 'n');
                     break;

             case 2: printf("\nEnter the node you want to delete : ");
                     scanf(" %d", &d);
                     root = deletion(root, d);
                     printf("Node deleted successfuly!\n");
                     break;

             case 3: printf("\n");
                     printf("Inorder Traversal : ");
                     traversal(root);
                     printf("\n");
                     break;

             case 4:
                     break;

             default: printf("Please input a valid choice\n");
                      break;
        }


    }while(choice != 4);
}

struct node* insertion(struct node * root, struct node * temp)
{
    if(root == NULL)
    {
        return temp;
    }
    else if(temp->data < root->data)
    {
        root->left = insertion(root->left, temp);
    }
    else if(temp->data > root->data)
    {
        root->right = insertion(root->right, temp);
    }


    (root->height) = 1 + maxheight(height(root->left), height(root->right));

    int balance = Balancefactor(root);
    
    //LL
    if (balance > 1 && temp->data < root->left->data)
        {
            printf("\ncritical node:(%d)LL rotation", node->data);
            return rightRotate(root);
            
        }
            
    //RR
    if (balance < -1 && temp->data > root->right->data)
        {
            printf("\ncritical node:(%d)RR rotation", node->data);
            return leftRotate(root);
        }

    //LR
    if (balance > 1 && temp->data > root->left->data)
    {
        printf("\ncritical node:(%d)LR rotation", node->data);
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    //RL
    if (balance < -1 && temp->data < root->right->data)
    {
        printf("\ncritical node:(%d)RL rotation", node->data);
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    root->bf = balance;
    
    return root;
}

void traversal(struct node *temp)
{

     if (temp == NULL)
          return;

     traversal(temp->left);

     printf("%d(%d) ", (temp->data), (temp->bf));

     traversal(temp->right);
}

struct node * deletion(struct node * root, int d)
{
    if(root == NULL)
    {
        printf("The tree is empty!");
        return NULL;
    }

    if(d < root->data)
    {
        root->left = deletion(root->left, d);
    }
    else if(d > root->data)
    {
        root->right = deletion(root->right, d);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node * temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node * temp = minvalue(root->right);
            root->data = temp->data;
            deletion(root->right, temp->data);
            return root;
        }
    }

    return root;
}

struct node* minvalue(struct node * temp)
{
    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

struct node* newnode()
{
        struct node * temp = (node *)malloc(sizeof(node));
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        printf("Value: ");
        scanf(" %d", &temp->data);

        return temp;
};

int maxheight(int a, int b)
{
    return (a > b)? a : b ;
}

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct Node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxheight(height(y->left), height(y->right))+1;
    x->height = maxheight(height(x->left), height(x->right))+1;

    return x;
}

struct Node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxheight(height(x->left), height(x->right))+1;
    y->height = maxheight(height(y->left), height(y->right))+1;

    return y;
}

int Balancefactor(struct node *N)
{
    if (N == NULL)
        {
            return 0;
        }
    else
    {
        return height(N->left) - height(N->right);
    }
}

/*OUTPUT:

students@students-Veriton-M200-H81:~/Desktop$ ./a.out

Select your choice:
1.Insertion
2.Deletion
3.Traversal
4.exit
:1
Value: 2
Do you want to continue?[y/n]y
Value: 1
Do you want to continue?[y/n]y
Value: 4
Do you want to continue?[y/n]y
Value: 5
Do you want to continue?[y/n]y
Value: 9
critical node:(4)RR rotation
Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Deletion
3.Traversal
4.exit
:3

Inorder Traversal : 1(0) 2(-1) 4(-1) 5(-1) 9(0) 

Select your choice:
1.Insertion
2.Deletion
3.Traversal
4.exit
:1
Value: 3
critical node:(2)RL rotation
Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Deletion
3.Traversal
4.exit
:3

Inorder Traversal : 1(0) 2(-1) 3(0) 4(1) 5(1) 9(0) 

Select your choice:
1.Insertion
2.Deletion
3.Traversal
4.exit
:1
Value: 6
critical node:(6)RL rotation
Do you want to continue?[y/n]y
Value: 7
critical node:(4)RR rotationss
Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Deletion
3.Traversal
4.exit
:3

Inorder Traversal : 1(0) 2(-1) 3(0) 4(-1) 5(1) 6(-1) 7(0) 9(1) 

Select your choice:
1.Insertion
2.Deletion
3.Traversal
4.exit
:4
students@students-Veriton-M200-H81:~/Desktop$ 
*/