//The company needs a program to calculate employee salaries based on the following rules:
//•	Each employee has a basic salary. Based on this, allowances and total income are calculated.
//•	The program must also:
//o	Validate inputs.
//o	Provide aggregated statistics about the company.
//o	Demonstrate modular programming through user-defined functions.
//Situation Description:
//The company has employees with varying levels of salaries, and a new HR system is required to:
//1.	Input Details:
//•	The number of employees.
//•	The basic salary of each employee.
//2.	Perform the following calculations:
//•	Allowance Calculation:
//o	If the basic salary is below 6,000,000, the allowance is 25% of the basic salary.
//o	If the basic salary is between 6,000,000 and 15,000,000 (inclusive), the allowance is 15%.
//o	If the basic salary exceeds 15,000,000, the allowance is 10%.
//•	Income Tax Deduction:
//o	Income tax is applied to the total income after adding the allowance:
//	If total income <= 8,000,000, no tax is applied.
//	If total income > 8,000,000, a 10% tax is applied on the amount exceeding 8,000,000.
//•	Total Net Income:
//o	Net income is calculated as:
//Net Income = Basic Salary + Allowance − Tax Deduction
//3.	Generate Statistics:
//•	The total salary cost (sum of all employees' net incomes).
//•	The number of employees in each allowance category.

//Here's my program in C:
#include<stdio.h>
void compute_allowance(float basic, int *high, int *medium, int *low, float *allowance ) {
	if (basic<6000000) {
		*allowance=0.25*basic;
		(*high)++;
	}else if (basic<=15000000) {
		*allowance=0.15*basic;
		(*medium)++;
	}else {
		*allowance=0.1*basic;
		(*low)++;
	}
}
float compute_incometaxdeduction(float basic, float allowance) {
	float tax, total_income;
	total_income=basic+allowance;
	if (total_income<=8000000) {
		tax=0;
	}else {
		tax=0.1*(total_income-8000000);
	}return tax;
}
float compute_netincome(float basic, float allowance, float tax) {
	float netincome;
	netincome=basic+allowance-tax;
	return netincome;
}
int main() {
	int number, i, high=0, medium=0, low=0;
	float allowance=0, basic, totalsalary=0, tax, netincome;
	do{
		printf("Enter number of staffs:");
		scanf("%d",&number);
	}while(number<0);
	for(i=1; i<=number; i++) {
		do{
			printf("Enter the basic salary of staff %d:\n",i);
			scanf("%f",&basic);
		}while(basic<0);
		compute_allowance(basic, &high, &medium, &low, &allowance);
		printf("Allowance of this staff is:%.2f\n",allowance);
		tax=compute_incometaxdeduction(basic, allowance);
		printf("Tax of this staff is:%.2f\n",tax); 
		netincome=compute_netincome(basic, allowance, tax);
		printf("Net income of this staff is:%.2f\n\n",netincome);
		totalsalary+=netincome;
	}printf("Total salary: %.2f\n",totalsalary);
	printf("Number of staffs receive 25%% of basic salary:%d\n",high);
	printf("Number of staffs receive 15%% of basic salary:%d\n",medium);
	printf("Number of staffs receive 10%% of basic salary:%d\n",low);
  return(0);
}
// In this code I used: loop do-while, for; functions.
// I have just learned C for 1 month. That explained why my code is pretty simple.
// If you are reading this and have a more optimized way to solve this, feel free to send me some feedback, eagle to read them.
