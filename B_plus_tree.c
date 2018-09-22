/*NAME : Chinmay Rane
  RollNo. : 55
  Batch : D (SE comps)
  Exp no. : 7 (B + tree)
*/  


#include <stdio.h>
#include <stdlib.h>

int m, skey = 0;

typedef struct node
{
    int data[10];
    struct node * link[10];
    int l;
    int r;
    struct node * sibling;

}node;

struct node * insertion(struct node * , int );
struct node * newnode();
int sort_check(struct node * , int );
struct node * sort_insert(struct node * , int, struct node * );
void traversal (struct node * );
struct node * split(struct node * );
struct node * check_root(struct node * );
void search (struct node * , int );


void main()
{
    struct node * root = NULL;
    char c;
    int key, choice;

    printf("\nEnter the order of the tree: ");
    scanf(" %d", &m);

    do
    {
    printf("\nSelect your choice:");
    printf("\n1.Insertion\n2.Search");
    printf("\n3.Traversal\n4.exit\n:");
    scanf(" %d", &choice);

    switch(choice)
        {
             case 1: do
                     {
                        printf("\nEnter the data : ");
                        scanf(" %d", &key);

                        root = insertion(root, key);

                        printf("Do you want to continue?[y/n]");
                        scanf(" %c", &c);

                     }while(c != 'n');
                      break;

             case 2:printf("Enter the key you want to search : ");
                     scanf(" %d", &key);

                     search(root, key);

                     if(skey == 1)
                     {
                     	printf("%d found in the tree!", key);
                     	skey = 0;
                     }
                     else
                     {
                     	printf("%d NOT found in the tree!", key);
                     }

                     break;

             case 3: printf("\nInorder : ");
                     traversal(root);
                     printf("\n");
                     break;

             case 4:
                     break;

             default: printf("Please input a valid choice\n");
                      break;
        }


    }while(choice != 4);
    printf(" %d", root->l);
}

struct node * insertion(struct node * root, int k)
{
    int flag = 0, a;

    if(root == NULL)
    {
        root  = newnode();
        root->r = 1;
        root->data[++(root->l)] = k;
        printf(" %d", root->l);
        return root;
    }
    else if(root->link[0] == NULL)
    {
        root = sort_insert(root, k, NULL);
        printf(" %d", root->l);
    }
    else
    {
        a = sort_check(root, k);

        root->link[a] = insertion(root->link[a], k);
    }

    if(flag == 1)
    {
        root->link[a] = root->link[a]->link[1];
        root = sort_insert(root, (root->link[a])->data[0], root->link[a]);
    }

    if(root->l == (m-1))
    {
        root = check_root(root);
        if(root->r == 0)
        {
            flag = 1;
        }
    }

    return root;
}

struct node * newnode()
{
    int i;

    struct node * temp = (node *)malloc(sizeof(node));

    for(i = 0; i < 10; i++)
    {
        temp->data[i] = 0;
        temp->link[i] = NULL;
    }

    temp->l = -1;
    temp->r = 0;
    temp->sibling = NULL;

    return temp;
}

int sort_check(struct node * root, int k)
{
    int i = 0;

    while(k > root->data[i])
    {
        i++;
        if(i == (root->l)+1)
        {
            break;
        }
    }

    return i;
}

struct node * sort_insert(struct node * root, int k, struct node * p)
{
    int i, n, c = 0;

    root->data[++(root->l)] = k;

    for(i = (root->l); i > 0; i--)
    {
        if(root->data[i] < root->data[i-1])
        {
            n = root->data[i];
            root->data[i] = root->data[i-1];
            root->data[i-1] = n;
            c++;
        }
    }

    c = (root->l) - c;

    if(p != NULL)
    {
        for(i = (root->l); i >= c; i--)
        {
            root->link[i+1] = root->link[i];
        }

        root->link[c] = p->link[0];

        free(p);
    }

    return root;
}

void search (struct node * root, int k)
{
    int i;

    while(root->link[0] != NULL)
    {
        root = root->link[0];
    }

    while(root != NULL)
    {
        for(i = 0; i<=(root->l); i++)
        {
            if(root->data[i] == k)
            {
                skey = 1;
                break;
            }
        }
        root =  root->sibling;
        if(skey == 1)
        {
            break;
        }
    }
}

struct node * split(struct node * root)
{
    int i, v;

        if(root->link[0] == NULL)
            {v = ((m-1)/2);}
        else
            {v = ((m/2)-1);}

        struct node * temp = newnode();
        struct node * temp1 = newnode();

        temp->data[++(temp->l)] = root->data[m/2];

        for(i = v; i >= 0; i--)
        {
            temp1->data[i] = root->data[root->l];
            temp1->link[i+1] = root->link[(root->l) + 1];
            root->link[(root->l) + 1] = NULL;
            (temp1->l)++;
            (root->l)--;
        }
        if(root->link[0] != NULL)
            {
                temp1->link[i] = root->link[root->l];
                (root->l)--;
            }

        temp->link[0] = root;
        temp->link[1] = temp1;

        temp1->sibling = root->sibling;//sibling linking
        root->sibling = temp1;//sibling linking

        return temp;
}

struct node * check_root(struct node * root)
{
    if(root->r == 1)
    {
        root = split(root);
        root->r = 1;
        root->link[0]->r = 0;
    }
    else
    {
        root = split(root);
        root->link[0]->r = 0;
    }

    return root;
}

void traversal(struct node * root)
{
    int i;

    while(root->link[0] != NULL)
    {
        root = root->link[0];
    }

    while(root != NULL)
    {
        for(i = 0; i<=(root->l); i++)
        {
            printf("%d ", root->data[i]);
        }
        root =  root->sibling;
    }
}

/* OUTPUT

students@celab6-17:~$ gcc bplus.c
students@celab6-17:~$ ./a.out

Enter the order of the tree: 5

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1

Enter the data : 9
 0Do you want to continue?[y/n]y

Enter the data : 3
 1Do you want to continue?[y/n]y

Enter the data : 15
 2Do you want to continue?[y/n]y

Enter the data : 7
 3Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 3 7 9 15 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1

Enter the data : 43
 4Do you want to continue?[y/n]y

Enter the data : 25
 3Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 3 7 9 15 25 43 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1

Enter the data : 6
 2Do you want to continue?[y/n]y

Enter the data : 13
 4Do you want to continue?[y/n]y

Enter the data : 23
 3Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 3 6 7 9 13 15 23 25 43 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1

Enter the data : 18
 4Do you want to continue?[y/n]y

Enter the data : 52
 3Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 3 6 7 9 13 15 18 23 25 43 52 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1

Enter the data : 39
 4Do you want to continue?[y/n]y

Enter the data : 29
 2Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 3 6 7 9 13 15 18 23 25 29 39 43 52 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:2
Enter the key you want to search : 23
23 found in the tree!
Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 3 6 7 9 13 15 18 23 25 29 39 43 52 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:17
Please input a valid choice

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:2
Enter the key you want to search : 17
17 NOT found in the tree!
Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:4
 0students@celab6-17:~$ 
 */