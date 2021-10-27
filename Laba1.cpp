

#include <stdio.h>
#include<stdlib.h>


int main()
{
	long int n, i, x;
	long double max, min, sum= 0.0, supsum = 0.0;

	printf("Enter n: ");
	scanf_s("%d", &n);
	printf("Enter max: ");
	scanf_s("%lf", &max);
	printf("Enter min: ");
	scanf_s("%lf", &min);

	double* numsDec = (double*)malloc(n * sizeof(double));
	int* numsOst = (int*)malloc(n * sizeof(int));

	if (n <= 0) {
		printf("ERROR: n cannot be <= 0 \n");
		return 0;
	}

	if (max < min) {
		printf("ERROR: max cannot be < min! \n");
		return 0;
	}
	if (numsDec == 0) {
		printf("ERROR: massic equals 0!\n");
		return 0;
	}


	for (i = 0; i < n; i++) {
		numsDec[i] = ((double)rand() / RAND_MAX * (max - min) + min);
		x = (numsDec[i] - int(numsDec[i])) * 100000;


		if (x == 0) {
			numsOst[i] = int(x);
		}
		else {
			while (x % 10 == 0)
				x = x / 10;
			numsOst[i] = int(x);
		}
	}
	printf("\n");
	
	for (i = 0; i < n; i++) {
		supsum = supsum + numsDec[i];
		if (numsOst[i] < n) {
			sum = sum - numsDec[numsOst[i]];
			numsDec[numsOst[i]] = 0.0;
		}
	}
	for (i = 0; i < n; i++) {
		sum = sum + numsDec[i];
	}

	printf("Total sum of numbers: %lf \n", supsum);
	printf("Sum of numbers: %lf", sum);

	free(numsDec);
	free(numsOst);
	return 0;
}



	

