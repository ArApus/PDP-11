#include <stdio.h>
#include <assert.h>
typedef unsigned char byte;
typedef unsigned short int word;
typedef word adr;
#define MEMSIZE (64*1024)

byte mem[MEMSIZE];

byte b_read  (adr a);            // читает из "старой памяти" mem байт с "адресом" a.
void b_write (adr a, byte val);  // пишет значение val в "старую память" mem в байт с "адресом" a.
word w_read  (adr a);            // читает из "старой памяти" mem слово с "адресом" a.
void w_write (adr a, word val);  // пишет значение val в "старую память" mem в слово с "адресом" a.
void load_file();
void mem_dump(adr start, word n);
void b_write (adr a, byte val){
    mem[a] = val;
}
byte b_read  (adr a){
    byte b;
    if(a % 2 == 0)
        b = mem[a];
    else{
        word w = mem[a-1];
        b = w >> 8 & 0xFF;
    }
    return b;
}
word w_read(adr a){
    word w = ((word)mem[a+1]) << 8;
    w = w | mem[a];
    return w;
}
void w_write (adr a, word val){
    mem[a] = val;
    mem[a+1] = val >> 8;
}

void load_file(){
    adr n, adress;
    byte val;
    while(scanf("%hx%hx", &adress, &n) == 2) {
        adr i;

        for (i = 0; i < n; i++) {
            scanf("%hhx", &val);
            b_write(adress + i, val);
        }
    }
}
void mem_dump(adr start, word n){
    adr i;
    for(i = 0; i < n; i=i+2) {
        word w = w_read(start + i);
        printf("%06ho : %06ho\n", start + i, w);
    }
}

debug

int main() {


    return 0;
}
