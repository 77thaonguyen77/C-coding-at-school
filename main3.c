//Write a C program using the following simple menu:
//1-Processing date data
//2-Character data
//3-Quit
//Choose an operation:
//-When user chooses 1: User will enter values of date, month, year then the program will announce wether this date is valid or not.
//-When user chooses 2: User will enter two characters, then the program will print out ASCII codes of characters between them using descending order. Example:
//Input:ca
//Output:
//c:99, 63h
//b:98, 62h
//a:97, 61h

//And here's my program in C:
#include<stdio.h>
void menu() {
	printf("\n-------------Choose a problem to solve (1-3):--------------\n");
	printf("1-Processing date data.\n");
	printf("2-Charater data.\n");
	printf("3-Quit.\n\n");
}
int main() 
{
	menu();
	char n;
	n=getchar();
	fflush(stdin);
	do{
		switch (n) {
			case '1':	{
				int date, month, year;
				printf("Enter value of date:");
				scanf("%d",&date);
				printf("\nEnter value of month:");
				scanf("%d",&month);
				while(month<1 || month>12) {
					printf("\nThe value of month is invalid. Please try again:");
					scanf("%d",&month);
				}printf("\nEnter value of year:");
				scanf("%d",&year);
				while(year<1) {
					printf("\nThe value of year is invalid. Please try again:");
					scanf("%d",&month);
				}
				switch (month) {
					case 1: case 3: case 5: case 7: case 8: case 10: case 12:
						if (date>=1 && date<=31) {
							printf("\nThe date is valid.");
						}else {
							printf("\nInvalid date.");
						}break;
					case 4: case 6: case 9: case 11:
						if (date>=1 && date <=30) {
							printf("\nThe date is valid.");
						}else {
							printf("\nInvalid date.");
						}break;
					case 2:
						if((year%4==0 && year%100!=0) || (year%400==0)) {
							if (date>=1 && date<=29) {
								printf("\nThe date is valid.");
							}else {
								printf("\nInvalid date.");
							}
						}else if(year%4!=0) {
							if (date>=1 && date<=28) {
								printf("\nThe date is valid.");
							}else {
								printf("\nInvalid date.");
							}
						}else {
							printf("Invalid date.");
						}break;
					default:
						printf("\nInvalid month.");
						break;
					break;
				}break;
			}
			case '2': {
				char c1, c2;
				int m, i;
				printf("\nEnter the first character:");
				c1=getchar();
				fflush(stdin);
				printf("\nEnter the second character:");
				c2=getchar();
				fflush(stdin);
				if(c1<c2) {
					m=c1;
					c1=c2;
					c2=m;
				}for(i=c1; i>=c2; i--) {
					printf("\n%c: %d, %x",i,i,i);
				}break;
			}
			case '3': {
				return(0);
			}
			default: {
				printf("\nInvalid choice.\n");
				break;
		    }
		}fflush(stdin);
		menu();
		n=getchar();
		fflush(stdin);
	}while(n!='!');
	return(0);
}

//I run this program on Dev C++. When I asked chatGPT to check the code, it said using fflush(stdin) is a non-official way and suggestted using clearInputBuffer().
//I still wondered about that. If you could help me, please send me a feedback. I will be very appreciate that.
