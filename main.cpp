
#define EXTERNC
#include "CoolPropLib.h"
#undef EXTERNC
#include <cstdio>
#include <cstdlib>

int main(){
    long errcode;
    const int buffer_length = 300;
    char message_buffer[buffer_length];
    long handle = AbstractState_factory("HEOS", "Methane&Ethane", &errcode, message_buffer, buffer_length);
    if (errcode != 0L){
        printf("Error: %s", message_buffer); return EXIT_FAILURE;
    }
    
    double fractions[] = {0.5, 0.5};
    long N = 2;
    AbstractState_set_fractions(handle, fractions, N, &errcode, message_buffer, buffer_length);
    if (errcode != 0L){
        printf("Error: %s", message_buffer); return EXIT_FAILURE;
    }
    
    AbstractState_build_phase_envelope(handle, "none", &errcode, message_buffer, buffer_length);
    if (errcode != 0L){
        printf("Error: %s", message_buffer); return EXIT_FAILURE;
    }
    
    const int length = 200;
    double T[length], p[length], rhomolar_liq[length], rhomolar_vap[length], x[length*2], y[length*2];
    AbstractState_get_phase_envelope_data(handle, length, T, p, rhomolar_liq, rhomolar_vap, x, y, &errcode, message_buffer, buffer_length);
    if (errcode != 0L){
        printf("Error: %s", message_buffer); return EXIT_FAILURE;
    }
}