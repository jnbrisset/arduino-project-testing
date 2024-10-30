
#include "functions.h"


int main(int argc, char *argv[]) {
    if (bitwise_toggle_test() != 0 ) {
        perror("setting sws");
    }

    return 0;
}