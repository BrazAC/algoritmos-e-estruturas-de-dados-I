#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c, delta, r1, r2;
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = pow(b, 2) - (4 * a * c);
    if (a == 0 || delta < 0){
        printf("Impossivel calcular\n");
    }else{
        printf("Teste: %lf\n", pow(4, (1/2)));
        r1 = (((-1) * b) + pow(delta, 1/2)) / (2*a);
        r2 = (((-1) * b) - pow(delta, 1/2)) / (2*a);
        
        printf("R1 = %.5f\n", r1);
        printf("R2 = %.5f\n", r2);
    }

    return 0;
}