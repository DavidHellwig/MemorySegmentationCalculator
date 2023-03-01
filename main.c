#include <stdio.h>
#include <stdlib.h>
void translate(int VA) {
    const int code = 0x0001;

    const int heap = 0x0002;

    const int stack = 0x0003;

    int BASE;

    int BOUND;

    int SEG_SHIFT = 14;

    int SEG_MASK = 0xc000;

    int OFFSET_MASK = 0x3fff;

    int SEG_NUM = (VA & SEG_MASK) >> SEG_SHIFT;

    printf("%d\n",SEG_NUM);

    if(SEG_NUM == code){
        BASE = 0x2000;
        BOUND = 0x1000;
    }

    else if(SEG_NUM == heap){
        BASE = 0x4000;
        BOUND = 0x3000;
    }

    else if(SEG_NUM == stack){
        BASE = 0xc000;
        BOUND = 0x2000;
    }


    if (SEG_NUM < code || SEG_NUM > stack ) {
        printf("FAULT\n");
        exit(0);
    }
    int offset;

    offset = VA & OFFSET_MASK;

    if(offset > BOUND) {
        printf("%x, FAULT\n",offset);
        exit(0);

    }

    int PA = BASE + offset;
    printf("%x\n",PA);

    }



int main() {
    translate(0xc000);
    return 0;
}
