//Programa que soma dois numeros
#include <stdio.h> 
int num3;

int soma(int x, int y){
int v_soma;
v_soma = x + y;
return(v_soma);	
}

int main ()
{
  int num1, num2;  
  num1 = 10;
  num2 = 20;
  num3=soma(num1, num2); 
  printf("%d + %d = %d", num1, num2, num3); 
  return 0;
}
