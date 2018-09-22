/*Name: Chinmay Rane
  Rollno: 55
  batch: D(SE Comps)
  Experiment no. 2
*/

//BFS and DFS in Graphs

#include <stdio.h>
#include <stdlib.h>

void shortestPath(int m[10][10], char c[20][20], int , int , int );
void bfs(int m[10][10], char c[20][20], int, int);
void dfs(int m[10][10], char c[20][20], int, int);

void main()
{
	int n, i, j, mat[10][10] = {0}, source, dest;
	char city[20][20];

	printf("\nPlease enter the number of cities (vertices) :");
	scanf(" %d", &n);

	for(i=0; i<n; i++)
	{
		printf("\nEnter city %d :", i+1);
		scanf(" %s", city[i]);
	}

	for(i=0; i<n; i++)
	{
		printf("\nEnter the indices of the cities which can be reached from %s", city[i]);
		printf("\nEnter 0 to quit\n");

		do
		{
			printf(":");
			scanf(" %d", &j);
			if(j!=0)
			{
				mat[i][j-1] = 1;
			}

		} while(j!=0);

		printf("\n");
	}


	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d\t", mat[i][j]);
		}

		printf("\n");
	}

	printf("\nPlease enter the source index:");
	scanf("%d", &source);
	printf("\nPlease enter the destination index:");
	scanf(" %d", &dest);

	printf("\nThe bfs result is as follows:");
	bfs(mat, city, (source - 1), n);

	printf("\nThe dfs result is as follows:");
	dfs(mat, city, (source - 1), n);

	shortestPath(mat, city, (source - 1), (dest - 1), n);
}

void bfs(int m[10][10], char c[20][20], int s, int n)
{
    int queue[10], visited[10] = {0};
    int front = 0, rear = -1, i;

    visited[s] = 1;
    queue[++rear] = s;
    printf("\n%s ", c[queue[front]]);

    while(front<=rear)
    {
        for(i=0; i<n; i++)
        {
            if(m[queue[front]][i]==1 && visited[i]==0)
            {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%s ", c[queue[rear]]);
            }
        }
        front=front + 1;
    }
}

void dfs(int m[10][10], char c[20][20], int s, int n)
{
    int stack[10] = {0}, visited[10] = {0};
    int top = -1, i;
    stack[++top] = s;
    visited[s] = 1;
    printf("\n%s ", c[stack[top]]);

    while(top != -1)
    {
        s = stack[top];
        for(i = 0; i<n; i++)
        {
            if(m[stack[top]][i] == 1 && visited[i] == 0 )
            {
                stack[++top] = i;
                printf("%s ", c[stack[top]]);
                visited[i] = 1;
            }
        }
        top--;
    }
}
void shortestPath(int m[10][10], char c[20][20], int s, int d, int n )
{
    int queue[10], origin[10] = {0}, visited[10] = {0};
    int front = 0, rear = -1, i, flag = 0, r = 0;

    visited[s] = 1;
    queue[++rear] = s;
    origin[0] = s;

    while(front<=rear)
    {
        for(i=0; i<n; i++)
        {
            if(m[queue[front]][i]==1 && visited[i]==0)
            {
                queue[++rear] = i;
                visited[i] = 1;
                origin[++r] = queue[front];

                if(queue[rear] == d)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 1)
        {
           break;
        }
        front=front + 1;
    }

    if(front>=rear)
    {
        printf("\nNo possible routes!");
    }
    else
    {
        printf("\n\n");
        i = rear;
        printf("\nThe shortest possible route is as follows:\n");
        printf("%s<---", c[queue[i]]);
        while(origin[i]!=s)
        {
            printf("%s<---", c[origin[i]] );
            r = i;
            while(queue[i] != origin[r])
            {
                i--;
            }
        }

        printf("%s\n", c[origin[i]]);

    }
}

/*OUTPUT
students@CELAB4-13:~/Desktop$ gcc city.c
students@CELAB4-13:~/Desktop$ ./a.out

Please enter the number of cities (vertices) :7

Enter city 1 :Delhi

Enter city 2 :Mumbai

Enter city 3 :Jaipur

Enter city 4 :Pune

Enter city 5 :Bangalore

Enter city 6 :Ahmedabad

Enter city 7 :Goa

Enter the indices of the cities which can be reached from Delhi
Enter 0 to quit
:3
:2
:0


Enter the indices of the cities which can be reached from Mumbai
Enter 0 to quit
:4
:0


Enter the indices of the cities which can be reached from Jaipur
Enter 0 to quit
:6
:1
:7
:0


Enter the indices of the cities which can be reached from Pune
Enter 0 to quit
:5
:2
:0


Enter the indices of the cities which can be reached from Bangalore
Enter 0 to quit
:3
:4
:0


Enter the indices of the cities which can be reached from Ahmedabad
Enter 0 to quit
:7
:4
:0


Enter the indices of the cities which can be reached from Goa
Enter 0 to quit
:6
:0

0	1	1	0	0	0	0	
0	0	0	1	0	0	0	
1	0	0	0	0	1	1	
0	1	0	0	1	0	0	
0	0	1	1	0	0	0	
0	0	0	1	0	0	1	
0	0	0	0	0	1	0	

Please enter the source index:1

Please enter the destination index:7

The bfs result is as follows:
Delhi Mumbai Jaipur Pune Ahmedabad Goa Bangalore 
The dfs result is as follows:
Delhi Mumbai Pune Bangalore Jaipur Ahmedabad Goa 


The shortest possible route is as follows:
Goa<---Jaipur<---Delhi
*/