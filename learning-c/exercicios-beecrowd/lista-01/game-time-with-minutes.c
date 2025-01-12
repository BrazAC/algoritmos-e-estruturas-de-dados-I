#include <stdio.h>
#include <unistd.h>

int main(){
    int hI, mI, hF, mF, mT, hT, modhI;
    hT = 0;
    mT = 0;
    modhI = 0;

    //Obter dados
    scanf("%d %d %d %d", &hI, &mI, &hF, &mF);

    //Lógica caso minuto inicial seja != 0
    if(mI != 0 && mI != mF){
        mT = (60 - mI) + mF;
        modhI = hI + 2;
    }else if(mI == mF){
        mT = 0;
    }else if(mI == 0){
        mT = mF;
    }

    //Identificando se o jogo vai durar ate o proximo dia ou nao
    if(hF > hI && hF < 24){ //Mesmo dia
        hT = hF - hI;
        if(hT == 1 && modhI != 0){
            hT = 0;
        }
    }else if(hF <= hI){     //Outro dia
        hT = (24 - hI) + hF;
    }
    
    //Se mT > 60, hT += 1, mT = mT - 60
    if(mT >= 60){
        hT += 1;
        mT = mT - 60;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)", hT, mT);

    return 0;
}