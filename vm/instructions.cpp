#include <iostream>
void print(int reg[]){
    for(int i = 1; i < reg[0];i++){
        std::cout << (char)reg[i];
    }
}
void exit(int ec){
    exit(ec);
}
int get(){
   return getchar();
}
void cmp(int (reg)[], int* reg0, int src){
    if(reg[1] == reg[src])
        *reg0 = 0;
    else if(reg[1] == 0)
        *reg0 = 2;
    else if(reg[1] < reg[src])
        *reg0 = -1;
    else if(reg[1] > reg[src])
        *reg0 = 1;
}
void mov(int(*reg)[], int(* Areg)[], int src, int dest){
    int cr;
    if(src < 128)
        cr = (*reg)[src];
    else cr = (*Areg)[src-128];
    if(dest < 128)
        (*reg)[dest] = cr;
    else (*Areg)[dest-128] = cr;
}
void cpy(int(*reg)[], int(*Areg)[], int dest, int src){
    //std::cout << src;
    if(dest < 128)
        (*reg)[dest] = src;
    else (*Areg)[dest-128] = src;
}
void add(int (*reg)[], int(*Areg)[], int us, int src){
    int cr;
    if(us < 128)
        cr = (*reg)[us];
    else cr = (*Areg)[us-128];
    if(src < 128)
        (*reg)[src] = (*reg)[src] + cr;
    else (*Areg)[src] = (*Areg)[src] + cr;
}
void sub(int (*reg)[], int(*Areg)[], int us, int src){
    int cr;
    if(us < 128)
        cr = (*reg)[us];
    else cr = (*Areg)[us-128];
    if(src < 128)
        (*reg)[src] = (*reg)[src] - cr;
    else (*Areg)[src] = (*Areg)[src] - cr;
}
void mul(int (*reg)[], int(*Areg)[], int src, int us){
    int cr;
    if(us < 128)
        cr = (*reg)[us];
    else cr = (*Areg)[us-128];
    if(src < 128)
        (*reg)[src] = (*reg)[src] * cr;
    else (*Areg)[src] = (*Areg)[src] * cr;
}
void div(int (*reg)[], int(*Areg)[], int src, int us){
    int cr;
    if(us < 128)
        cr = (*reg)[us];
    else cr = (*Areg)[us-128];
    if(src < 128)
        (*reg)[src] = (*reg)[src] / cr;
    else (*Areg)[src] = (*Areg)[src] / cr;
}
int je(int reg0){
    if(reg0 == 0){
        return 1;
    }return 0;
}
int jne(int reg0){
    if(reg0 == 0){
        return 0;
    }return 1;
}
int jnz(int reg0){
    if(reg0 == 2){
        return 1;
    }return 0;
}
int jb(int reg0){
    if(reg0 == 1){
        return 1;
    }return 0;
}
int js(int reg0){
    if(reg0 == -1){
        return 1;
    }return 0;
}
void interpret(int (*reg)[], int (*sources)[], int current){
    switch((*reg)[0]){
        case 0:
            for(int i =1; i < 127 && (*reg)[i] != 0; i++){
                std::cout << (char)((*reg)[i]);
            }break;
        case 1:
            (*reg)[0] = getchar();
            break;
        case 2: 
            //std::cout << "Overwriting reg[" << (*reg)[1] << "] to reg[" << (*reg)[2] << "]\n";
            (*sources)[(*reg)[1]] = (*reg)[2];
            break;
        case 3:
            (*reg)[1] = (*reg)[(*reg)[2]];
            break;
    }
}