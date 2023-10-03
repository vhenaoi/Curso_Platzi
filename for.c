#include <stdio.h>

int n = 30;
int i =0;

int main(){
    for(i=0; i < n; i++){
        continue;
        printf("El valor actual de i es %d \n", i);
    }
    printf("El valor actual de i es %d \n", i);
    return 0;
}