#include<stdio.h>;

int soma(int x, int y);						// function prototype

int main(void) {
	int num1, num2, num3;
	printf("Digite primeiro numero:");
	scanf("%d", &num1);
	printf("Digite segundo numero:");
	scanf("%d", &num2);

	num3 = soma(num1, num2); 				// function call

	printf("A soma de: %d + %d = %d\n", num1, num2, num3);
	return(0);
	}

	int soma(int x, int y)					// fuction definition
	{
		return (x+y);
	}