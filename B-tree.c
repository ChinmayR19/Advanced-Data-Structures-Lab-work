/*NAME : Chinmay Rane
  RollNo. : 55
  Batch : D (SE comps)
  Exp no. : 6(B tree)
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

}node;

struct node * insertion(struct node * , int );
struct node * newnode();
int sort_check(struct node * , int );//used only for traversing
struct node * sort_insert(struct node * , int, struct node * );
void traversal(struct node * );
struct node * split(struct node * );
struct node * check_root(struct node * );
void search(struct node * , int );

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
                        printf("Enter the data : ");
                        scanf(" %d", &key);

                        root = insertion(root, key);

                        printf("Do you want to continue?[y/n]");
                        scanf(" %c", &c);

                     }while(c != 'n');
                      break;

             case 2: printf("Enter the key you want to search : ");
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
    //printf(" %d", root->l);
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

    if(flag == 1)//to take care of non root node
    {
        root->link[a] = root->link[a]->link[1];
        root = sort_insert(root, (root->link[a])->data[0], root->link[a]);
    }

    if(root->l == (m-1))
    {
        root = check_root(root);
        if(root->r == 0)
        {
            flag = 1;//to take care of non root node
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

    return temp;
}

int sort_check(struct node * root, int k)//returns the index of the link to be traversed to
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

    if(p != NULL)//used during splitting when keys exceed order-1
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

void traversal(struct node * root)
{
    int i;

    if(root == NULL)
    {
        return;
    }

    for(i = 0; i <= (root->l); i++)
    {
        traversal(root->link[i]);

        printf("%d ", root->data[i]);

    }

    traversal(root->link[i]);
}

struct node * split(struct node * root)//returns the node with the middle element which points to the 2 splitted node
{
    int i;

        struct node * temp = newnode();
        struct node * temp1 = newnode();

        temp->data[++(temp->l)] = root->data[(m-1)/2];

        for(i = (m/2)-1; i >= 0; i--)
        {
            temp1->data[i] = root->data[root->l];
            (temp1->l)++;
            (root->l)--;
        }
        (root->l)--;

        temp->link[0] = root;
        temp->link[1] = temp1;

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

void search(struct node * root, int k)
{
	int i;

    if(root == NULL)
    {
        return;
    }

    for(i = 0; i <= (root->l); i++)
    {
        search(root->link[i], k);
        
        if(root->data[i] == k)
        {
        	skey = 1;
        	break;
        }
    }

    search(root->link[i], k);
	
}

/*OUTPUT
students@CELAB4-13:~/Desktop$ gcc btree.c
students@CELAB4-13:~/Desktop$ ./a.out

Enter the order of the tree: 3

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1 
Enter the data : 3
 0Do you want to continue?[y/n]y
Enter the data : 9
 1Do you want to continue?[y/n]y
Enter the data : 7
 2Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 3 7 9 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1
Enter the data : 23
 1Do you want to continue?[y/n]y
Enter the data : 45
 2Do you want to continue?[y/n]y
Enter the data : 1
 1Do you want to continue?[y/n]y
Enter the data : 5
 2Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 1 3 5 7 9 23 45 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:1
Enter the data : 14
 1Do you want to continue?[y/n]y
Enter the data : 25
 1Do you want to continue?[y/n]y
Enter the data : 24
 2Do you want to continue?[y/n]y
Enter the data : 13
 2Do you want to continue?[y/n]y
Enter the data : 11
 1Do you want to continue?[y/n]n

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:3

Inorder : 1 3 5 7 9 11 13 14 23 24 25 45 

Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:2
Enter the key you want to search : 14
14 found in the tree!
Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:2
Enter the key you want to search : 21
21 NOT found in the tree!
Select your choice:
1.Insertion
2.Search
3.Traversal
4.exit
:4
students@CELAB4-13:~/Desktop$ 
*/