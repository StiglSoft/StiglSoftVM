#include "registers.h"
#include "instructions.cpp"
int ExecutionDisabled = 0;

void Execute(int sources[], int lenght){
    int source[lenght];
    for(int i =0; i < lenght;i++){
        source[i] = sources[i];
    }
    for(int i =0; i < lenght;i++){
        if(ExecutionDisabled){
            if(source[i] == 16)
                ExecutionDisabled = 0;
            continue;
        }
        switch(source[i]){
            //Skipping zero... 0 == EMPTY
            case 1: 
                mov(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 2:
                cpy(&Sreg,&Areg,source[++i],source[++i]);
                break;
            case 3:
                return;
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
                //If cmpeq != 0 then jump
            case 14:
                if(jnz(Sreg[0]))
                    i = source[++i] -1;
                break;
                //Enables on the NOCODE mode
                //16 Disables!
            case 15:
                ExecutionDisabled = 1;
                break;
            case 17:
                i = Sreg[0] -1;
                break;
            case 18:
                switch (source[++i]){
                    case 1:
                        Sreg[0] = Stack1.top();
                        break;
                    case 2:
                        Stack1.pop();
                        break;
                    case 3:
                        Stack1.push(Sreg[0]);
                        break;
                    case 4:
                        Sreg[0] = Stack1.top();
                        Stack1.pop();
                        break;
                    case 5:
                        Stack1.push(i-1);
                        break;
                }break;
            case 19:    
                if(jb(Sreg[0]))
                    i = source[++i] -1;
                break;
            case 20:
                if(js(Sreg[0])) 
                    i = source[++i] -1;
                break;
            case 21:
                interpret(&Sreg, &source, i);
                break;
            case 22:
                int j = 0;
                std::string hexDigits = "0123456789ABCDEF";
                std::cout <<  "\033[36m" <<"Hex dump of registers:" << "\033[37m" << std::endl;
                for(int i =0; i < 128;i++){
                    std::string hexString;
                    hexString += hexDigits[Sreg[i] / 16];
                    hexString += hexDigits[Sreg[i] % 16];
                    if(hexString != "00"){
                        std::cout << "\033[33m";
                    }std::cout << hexString << " " << "\033[37m";
                    j++;
                    if(j % 8 == 0)
                        std::cout << std::endl;
                }std::cout << std::endl << "\033[36m" << "Hex dump of code:" << "\033[37m" << std::endl;
                for(int i =0; i < lenght;i++){
                    std::string hexString;
                    hexString += hexDigits[source[i] / 16];
                    hexString += hexDigits[source[i] % 16];
                    if(hexString != "00"){
                        std::cout << "\033[33m";
                    }std::cout << hexString << " " << "\033[37m";
                    j++;
                    if(j % 8 == 0 && j > 0)
                        std::cout << std::endl;
                }std::cout << std::endl;
                break;
        }
    }
} 