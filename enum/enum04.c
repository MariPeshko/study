#include <stdio.h>  

enum directions{North=1, East, West, South};  

int main(){

    enum directions d;

    d=0;

    switch(d){  

        case North:

        printf("We are headed towards North.\n");

        break;

        case East:

        printf("We are headed towards East.\n");

        break;

        case West:

        printf("We are headed towards West.\n");

        break;

        case South:

        printf("We are headed towards South\n");

        break;

    }

    return 0;

}
