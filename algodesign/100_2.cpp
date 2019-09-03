/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 * Problem: UVA 100 ( 3n + 1 )
 */
#include<stdio.h>
 
#define SIZE 1000002
 
/* Lookup table for storing previously calculated values */
static unsigned table[SIZE];
 
/* Returns cycle length for given number */
unsigned cycleLength(register unsigned n){
    /* If the value already exists in the lookup table then return its cycle length */
    if (n < SIZE && table[n])
        return table[n];
 
    /* Check if number is odd */
    if (n&1){
        if (n < SIZE){
            /* Since 3n+1 becomes an even number, we perform the next step which is divided by two since its even, also +2 since we perform two operations */
            table[n] = 2 + cycleLength((3 * n + 1) >> 1);
            return table[n];
        }else
            /* The value is bigger than table so we calculate and return */
            return 2 + cycleLength((3 * n + 1) >> 1);
    }else{
        if (n < SIZE){
            /* The number is even so we perform number divided two, or bit shift left once */
            table[n] = 1 + cycleLength(n >> 1);
            return table[n];
        }else
            return 1 + cycleLength(n >> 1);
    }
}
 
int main(){
    unsigned a, b, count;
    register unsigned n;
    /* This is necessary since i don't check for 1 in cycleLength, Also 1st index is always 1 */
    table[1] = 1;
 
    while (scanf("%u%u", &a, &b) == 2){
        unsigned maxCycle = 0;
        /* The input may contain bigger number first then smaller number */
        if (a < b){
            for (n = a; n <= b; ++n){
                /* Cycle every value between a to b */
                count = cycleLength(n);
                /* We need to find max cycle, so if a cycle count is greater than maxCycle then replace maxCycle */
                if (maxCycle < count)
                    maxCycle = count;
            }
        }else{
            for (n = b; n <= a; ++n){
                count = cycleLength(n);
                if (maxCycle < count)
                    maxCycle = count;
            }
        }
        printf("%u %u %u\n", a, b, maxCycle);
    }
    return 0;
}
