#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int petrol;
    int dist;
    struct Node *next;
}Node;

void printData(Node *);
int condition(Node *);
void logic(Node *, int);

void main()
{
    struct Node *head = NULL;
    struct Node *temp= NULL;
    int n, i, c=0;

    printf("\nPlease enter the number of petrol pumps:");
    scanf(" %d", &n);

    temp = ( Node*)malloc(sizeof( Node));
    head = temp;
    printf("\nEnter the amount of petrol in petrol pump no. 1 : ");
    scanf(" %d", &(temp->petrol));
    printf("\nEnter the distance between petrol pump no. 1 and 2 : ");
    scanf(" %d", &(temp->dist));



    for(i=1; i<n; i++)//Input logic
    {
        (temp->next) = ( Node*)malloc(sizeof( Node));
        temp = (temp->next);
        printf("\nEnter the amount of petrol in petrol pump no. %d : ", i+1);
        scanf(" %d", &(temp->petrol));
        if(i+1==n)
        {
            printf("\nEnter the distance between petrol pump no. %d and 1 : ", i+1);
            scanf(" %d", &(temp->dist));
        }
        else
        {
            printf("\nEnter the distance between petrol pump no. %d and %d : ", i+1, i+2);
            scanf(" %d", &(temp->dist));
        }

    }

    temp->next = NULL;

    printf("\n\n\n");

    printData(head);

    c = condition(head);

    if(c == 2)
    {
        printf("\nThe journey is not possible as the petrol is insufficient\n");
    }

    else
    {
        temp->next = head;
        printf("\nThe journey is possible!\n\n\n");
        logic(head, n);
    }

}

void printData(Node *Temp)//print current data
{
    printf("\nCurrent scenario is as follows:\n");
    printf("HEAD--->");
    while((Temp)!=NULL)
    {
        printf("(%d,%d)--->", (Temp->petrol), (Temp->dist) );
        Temp = (Temp->next);
    }

    printf("HEAD\n");
}

int condition(Node *Temp)//check condition for journey
{
   int p=0, d=0;
   while(Temp!=NULL)
   {
        p+=(Temp->petrol);
        d+=(Temp->dist);
        Temp = (Temp->next);
   }
   printf("\n\npetrol = %d, dist = %d", p, d);
   if(p>=d)
   {
        printf("\nPetrol left : %d units\n", p-d);
        return (3);
   }
   else
   {
       return (2);
   }
}

void logic(Node *Temp, int m)//start point and petrol left
{
    int p=0, d=0, count=1, pl=0;

    while(count!=m)
    {
        d = Temp->dist;
        p += ((Temp->petrol)-d);

        if(p<0)
        {
            p = 0;
            d = 0;
            count = 0;
        }

        Temp = Temp->next;
        count = count + 1;
    }

    Temp = Temp->next;

    printf("\nThe first possible route is as follows:\n");
    printf("HEAD--->");

    for(count = 1; count<=m; count++)
    {
        printf("(%d,%d)--->", (Temp->petrol), (Temp->dist) );
        Temp = (Temp->next);
    }

    printf("HEAD\n\n\n");
}
