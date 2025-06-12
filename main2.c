//Write a program to find the solution to the following problem:
//One hundred of buffaloes, one hundred of grasses
//The standing buffaloes eat five grasses
//The lying buffaloes eat three grasses
//Three old buffaloes eat one grass.
//How many standing buffaloes, lying buffaloes, and old buffaloes are there?

//Here's my program:
#include<stdio.h>
int main()
{
	int i, k, j;         // i: standing buffaloes; k: lying buffaloes; j: old buffaloes.
	for (i=1; i<20; i++) {
		for (k=1; k<32; k++) {
			for (j=1; j<=276; j++) {
				if (i+k+j==100 && 15*i+9*k+1*j==300) {
					printf("After computing the problem, there are %d standing buffaloes, %d lying buffaloes, %d old buffaloes",i,k,j);
					return(0);
				}
			}
		}
	}printf("No valid combination found.\n");
	return(0);
}
