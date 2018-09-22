/*NAME : Chinmay Rane
  RollNo : 55
  Batch : D
  ExpNo. : 8(Heap Tree)
*/


#include <stdio.h>

void max(int heap[50], int );
void min(int data[50], int );

void main()
{
    int data[50] = {0};
    int n, i, choice;

    printf("Enter the number of elements: ");
    scanf(" %d", &n);

    for(i = 0; i<n; i++)
    {
        printf("Value: ");
        scanf(" %d", &data[i]);
    }

    do
    {
        printf("\nMENU\n1.MIN Tree\n2.MAX Tree\n3.Exit\n:");
        scanf(" %d", &choice);

        switch(choice)
        {
            case 1:min(data, n);
                   break;

            case 2:max(data, n);
                   break;

            case 3:
                   break;

            default: printf("Please enter a valid input");
                     break;
        }
    }while(choice != 3);
}

void max(int data[50], int n)
{
    int i, m, r, temp, heap[50] = {0}, t, flag = 0;

    for(i = 0; i<n; i++)
    {
        heap[i] = data[i];

        if((heap[i] > heap[(i-1)/2]) && (i > 0))
        {
            m = i;

            while(1)
            {
                temp = heap[m];
                heap[m] = heap[(m-1)/2];
                heap[(m-1)/2] = temp;

                m = (m-1)/2;

                if((m <= 0) || (heap[m] < heap[(m-1)/2]))
                {
                    break;
                }

            }
        }
    }

    printf("The max heap structure is as follows :\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    t = n;
    heap[n] = heap[0];
    heap[0] = heap[n-1];
    t--;

    for(i = 1; i < (n-1); i++)
    {
        m = 0;

        while((heap[m] < heap[2*m + 1]) || (heap[m] < heap[2*m + 2]))
        {
            if(flag == 1)
            {
                if(heap[m] < heap[2*m +1])
                {
                    r = (2*m + 1);
                    flag = 0;
                }
                else
                {
                    break;
                }

            }
            else
            {
                r = heap[2*m + 1]>heap[2*m + 2]?(2*m + 1):(2*m + 2);
            }

            temp = heap[r];
            heap[r] = heap[m];
            heap[m] = temp;

            m = r;

            if((2*m +1) >= t)
            {
                break;
            }
            else if((2*m + 2) >= t)
            {
                flag = 1;
            }
        }

        heap[t] = heap[0];
        heap[0] = heap[t-1];
        t--;

    }

    printf("\nThe ascending order is as follows:\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }

}

void min(int data[50], int n)
{
   int i, m, r, temp, heap[50] = {0}, t, flag = 0;

    for(i = 0; i<n; i++)
    {
        heap[i] = data[i];

        if((heap[i] < heap[(i-1)/2]) && (i > 0))
        {
            m = i;

            while(1)
            {
                temp = heap[m];
                heap[m] = heap[(m-1)/2];
                heap[(m-1)/2] = temp;

                m = (m-1)/2;

                if((m <= 0) || (heap[m] > heap[(m-1)/2]))
                {
                    break;
                }

            }
        }
    }

    printf("The min heap structure is as follows :\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    t = n;
    heap[n] = heap[0];
    heap[0] = heap[n-1];
    t--;

    for(i = 1; i < (n-1); i++)
    {
        m = 0;

        while((heap[m] > heap[2*m + 1]) || (heap[m] > heap[2*m + 2]))
        {
            if(flag == 1)
            {
                if(heap[m] > heap[2*m +1])
                {
                    r = (2*m + 1);
                    flag = 0;
                }
                else
                {
                    break;
                }

            }
            else
            {
                r = heap[2*m + 1]<heap[2*m + 2]?(2*m + 1):(2*m + 2);
            }

            temp = heap[r];
            heap[r] = heap[m];
            heap[m] = temp;

            m = r;

            if((2*m +1) >= t)
            {
                break;
            }
            else if((2*m + 2) >= t)
            {
                flag = 1;
            }
        }

        heap[t] = heap[0];
        heap[0] = heap[t-1];
        t--;

    }

    printf("\nThe descending order is as follows:\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }

}

/* OUTPUT

students@CELAB4-13:~/Desktop$ gcc test1.c
students@CELAB4-13:~/Desktop$ ./a.out
Enter the number of elements: 9
Value: 4
Value: 56
Value: 2
Value: 87
Value: 18
Value: 9
Value: 34
Value: 29
Value: 57

MENU
1.MIN Tree
2.MAX Tree
3.Exit
:1
The min heap structure is as follows :
2 18 4 29 56 9 34 87 57 
The descending order is as follows:
87 57 56 34 29 18 9 4 2 
MENU
1.MIN Tree
2.MAX Tree
3.Exit
:2
The max heap structure is as follows :
87 57 34 56 18 2 9 4 29 
The ascending order is as follows:
2 4 9 18 29 34 56 57 87 
MENU
1.MIN Tree
2.MAX Tree
3.Exit
:3
*/