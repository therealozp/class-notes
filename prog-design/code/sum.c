#include <stdio.h>

int sum (int (*f) (int), int start, int end);
int fact(int n);
int square(int n);
int cube(int n);

int main()
{
	int start, end;
	printf("Enter start value: ");	
	scanf("%d", &start);
	printf("Enter end value: ");
	scanf("%d", &end);
	
	//display the sum of factorials, the sum of squares, 
	//and the sum of cubes from start to end
    int totalfact = sum(fact, start, end);
    int totalsquare = sum(square, start, end);
    int totalcube = sum(cube, start, end);

    printf("Total of factorials: %d\n", totalfact);
    printf("Total of squares: %d\n", totalsquare);
    printf("Total of cubes: %d\n", totalcube);
    return 0;
}

int sum (int (*f) (int), int start, int end) {
    int total = 0;  
    for (int i = start; i < end + 1; i++) {
        total += f(i);
    }
    return total; 
}

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    int factarray[n + 1]; 
    factarray[0] = 1;
    for (int i = 1; i < n + 1; i++) {
        factarray[i] = i * factarray[i-1];
    }
    return factarray[n];
}

int square(int n)
{
  return n*n;
}

int cube(int n)
{
  return n*n*n;
}
