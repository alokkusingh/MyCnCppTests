#include <stdio.h>

union myUnion {
    unsigned char ch[2];
    unsigned int x;
};

int main() {

    union myUnion abc;
    abc.x = 265;
//    printf ("%d\n",abc.ch[0]);
//    printf ("%d\n",abc.ch[1]);
//    printf ("%d\n",abc.x);
    if (abc.ch[0] == 0) {
        printf ("Its little endian processor");
    } else {
        printf ("Its big endian processor");
    }
return(0);
}
