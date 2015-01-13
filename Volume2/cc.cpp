#include <stdio.h>
#include <stdlib.h>

int main(){
    const char   firstname[] = "bobby";
    const char*  lastname = "eraserhead";
    printf("%lu\n", sizeof(firstname) + 
                    sizeof(lastname));
                    system("PAUSE");
    return 0;
}

