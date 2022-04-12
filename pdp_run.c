#include <stdio.h>
#include "main.c"

word reg[8];
#define pc reg[7]
void run() {
    pc = 01000;
    while(1)  {
        word w = w_read(pc);


    }






}



