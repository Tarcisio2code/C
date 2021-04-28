#include <stdio.h>
void troca(int *x, int *y) {
int aux;
if(x != NULL && y != NULL){ //se endereços forem válidos
aux = *x;                    //faz a troca
*x = *y;
*y = aux;
printf("aux: %d\n", aux);
printf("aux: %d\n", &aux);
printf("x: %d\n", x);
printf("y: %d\n", y);
}
}

int main(){
int v1=5, v2=10;
printf("end v1: %d - end v2: %d\n", &v1, &v2);
troca(&v1, &v2);
printf("end v1: %d - end v2: %d\n", &v1, &v2);
printf("v1 = %d  e v2 = %d\n", v1, v2);
}

