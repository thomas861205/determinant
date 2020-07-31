#include <stdio.h>
#include <stdlib.h> //malloc
// #define MAX 3

void print(int **ptr, int n){
	int i,j;
	for (i = 0; i< n; i++){
		for (j = 0; j< n; j++){
			printf("%d", ptr[i][j]);
			if (j != n -1) printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}

int det(int **ptr, int n){
	if (n == 1) return **ptr;
	else {
		int i,j,k,m;
		int sign = 1;
		int ans = 0;
		int **sub;
		for (i = 0; i < n; i++){
			sub = malloc(sizeof(int *)*(n-1));
			for (j = 0; j < n-1; j++) sub[j] = malloc(sizeof(int)*(n-1));
			
			m = 0;
			for (j = 0; j < n; j++){
				if (j != i){
					for (k = 0; k < n-1; k++) sub[m][k] = ptr[j][k+1];
					m++;
				}
			}
			// print(sub, n-1);
			ans += ptr[i][0]*det(sub, n-1)*sign;
			sign = -sign;
			free(sub);
		}
		return ans;
	}
}

int main(void){
	int i, j;
	int size;

	scanf("%d", &size);
	int **row = malloc(sizeof(int *) * size);
	for (i = 0; i < size; i++) {
		row[i] = malloc(sizeof(int)*size);
	}
	for (i = 0; i< size; i++) {
		for (j = 0; j< size; j++) {
			scanf("%d", &row[i][j]);
		}
	}
	printf("%d\n", det(row, size));
	return 0;
}
