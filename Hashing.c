/*Name:Chinmay S. Rane
  RollNo:55
  Batch:D (SE Comps)
  Experiment no. 3
*/
  
#include<stdio.h>

void main()
{
	int n, i, temp, h;
	
	printf("\nPlease enter the tablesize:");
	scanf(" %d", &n);
	
	int a[50] = {0};
	
	for(i = 0; i<n; i++)
	{
		printf("Enter element no %d : ", i+1);
		scanf(" %d", &temp);
		
		h = (temp)%n;
		
		while(a[h]!=0)
		{
			printf("Collision occured!\n");
			h++;
			h = h%n;
		}
		
			a[h] = temp;
					
	}
	
	printf("\n\nThe array is as follows:");
	
	for(i=0; i<n; i++)
	{
		printf("\n%d : %d", i, a[i]);
	}
	
	printf("\n");
}

/*OUTPUT
students@CELAB4-13:~/Desktop$ gcc hash.c
students@CELAB4-13:~/Desktop$ ./a.out

Please enter the tablesize:10
Enter element no 1 : 4
Enter element no 2 : 75
Enter element no 3 : 715
Collision occured!
Enter element no 4 : 64 
Collision occured!
Collision occured!
Collision occured!
Enter element no 5 : 383
Enter element no 6 : 26
Collision occured!
Collision occured!
Enter element no 7 : 85
Collision occured!
Collision occured!
Collision occured!
Collision occured!
Enter element no 8 : 12
Enter element no 9 : 67
Collision occured!
Collision occured!
Collision occured!
Enter element no 10 : 23
Collision occured!
Collision occured!
Collision occured!
Collision occured!
Collision occured!
Collision occured!
Collision occured!
Collision occured!


The array is as follows:
0 : 67
1 : 23
2 : 12
3 : 383
4 : 4
5 : 75
6 : 715
7 : 64
8 : 26
9 : 85
*/
