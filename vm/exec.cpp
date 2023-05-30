#include "registers.h"
#include "instructions.cpp"
void Execute(int source[], int lenght){
    for(int i =0; i < lenght;i++){
        switch(source[i]){
            case 1: 
                mov(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 2:
                cpy(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 3:
                exit(Sreg[0]);
                break;
            case 4:
                print(Sreg);
                break;
            case 5:
                Sreg[0] = get();
                break;
            case 6:
                add(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 7:
                sub(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 8:
                mul(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 9:
                div(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 10:
                i = source[++i] -1;
                break;
            case 11:
                cmp(Sreg,&Sreg[0],source[++i]);
                break;
            case 12:
                if(je(Sreg[0]))
                    i = source[++i] -1;
                break;
            case 13:
                if(jne(Sreg[0]))
                    i = source[++i] -1;
                break;
            case 14:
                if(jnz(Sreg[0]))
                    i = source[++i] -1;
                break;
            
        }
    }
} 