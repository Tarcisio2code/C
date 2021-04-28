#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    int x = 100;
    int *ptr;
    ptr = &x;
    
    
    int **mem_ptr;	// pointer to int pointer type
    mem_ptr = &ptr;	// get memory address from int pointer variable

    printf("Using pointers\n\n");
    printf("Content of variable v_num: %d\n", x);
    printf("Address of variable v_num: %x \n", &x);
    printf("Content of pointer variable ptr: %d\n", ptr);
    printf("Address of pointer variable ptr: %x", mem_ptr);

    getch();
    return(0);
}