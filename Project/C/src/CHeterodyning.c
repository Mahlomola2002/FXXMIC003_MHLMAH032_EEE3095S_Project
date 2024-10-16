#include "CHeterodyning.h"

extern float data [SAMPLE_COUNT];
extern float carrier[SAMPLE_COUNT];

float result [SAMPLE_COUNT];

int main(int argc, char**argv){
    printf("Running Unthreaded Test\n");
    printf("Precision sizeof %ld\n", sizeof(float));
    

    printf("Total amount of samples: %ld\n", sizeof(data) / sizeof(data[0]));
    double avg_time=0;

    for(int i=0;i<10000;i++){
        avg_time=avg_time+calculate_time();
    }
    double t=avg_time/10000;

   
    printf("Time: %lf ms\n",t/1e-3);
    printf("End Unthreaded Test\n");
    printf("sizeof float: %lu\n", sizeof(float) * 8);
    return 0;
}

double calculate_time(){
     tic(); // start the timer
    for (int i = 0;i<SAMPLE_COUNT;i++ ){
        result[i] = data[i] * carrier[i];
    }
    return toc();

}
