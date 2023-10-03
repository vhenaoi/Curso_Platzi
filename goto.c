#include <stdio.h>

int n = 30;
int i = 0;
int count =0;
int panic = 0;

int main(){
    for(size_t i = 0; i < count; i++){
       for(size_t i = 0; i < count; i++){
            for(size_t i = 0; i < count; i++){
                if (panic)
                goto errorHandler;
            }
        }
    }
    errorHandler: // Todo el codigo para componenr tu desastre
    return 0;
}