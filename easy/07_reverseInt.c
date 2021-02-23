#include<stdio.h>

int reverse(int x)
{

}

// use bit-wise operator
const int MAX_INT = (unsigned)(-1) >> 1;
const int MIN_INT = ~MAX_INT;
int main(int argc, char* argv[])
{
    printf("sizeof int = %ld\n", sizeof(int));
    printf("MAX_INT = %d\n", MAX_INT);
    printf("MIN_INT = %d\n", MIN_INT);

    return 0;
}