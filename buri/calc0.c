#include <stdio.h>

#define CALC_OP  1
#define CALC_NUM 2
#define CALC_MEM 3

int main(int argc, char *argv[]){

    char last_op = '+', *p = argv[1];
    long num, acc = 0, mem = 0, sign = 1, flag = CALC_OP;

    for( ; *p != '\0'; p++ ){
        switch( *p ){
            case 0+'0':
            case 1+'0':
            case 2+'0':
            case 3+'0':
            case 4+'0':
            case 5+'0':
            case 6+'0':
            case 7+'0':
            case 8+'0':
            case 9+'0':
                switch( flag ){
                    case CALC_OP:
                        num = *p-'0';
                        break;
                    case CALC_NUM:
                        num = num * 10 + (*p-'0');
                        break;
                    case CALC_MEM:
                        num = *p-'0';
                        acc = 0;
                        last_op = '+';
                        break;
                }
                flag = CALC_NUM;
                break;
            case 'S':
                sign *= -1;
                break;
            case 'C':
                mem = 0;
                break;
            case 'R':
                acc = mem;
                break;
            case 'P':
                if( flag == CALC_NUM ){
                    switch( last_op ){
                        case '+':
                            acc = acc + (num*sign);
                            break;
                        case '-':
                            acc = acc - (num*sign);
                            break;
                        case '*':
                            acc = acc * (num*sign);
                            break;
                        case '/':
                            acc = acc / (num*sign);
                            break;
                    }
                }
                sign = 1;
                mem += acc;
                flag = CALC_MEM;
                break;
            case 'M':
                if( flag == CALC_MEM ){
                    switch( last_op ){
                        case '+':
                            acc = acc + (num*sign);
                            break;
                        case '-':
                            acc = acc - (num*sign);
                            break;
                        case '*':
                            acc = acc * (num*sign);
                            break;
                        case '/':
                            acc = acc / (num*sign);
                            break;
                    }
                }
                sign = 1;
                mem -= acc;
                flag = CALC_MEM;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
                if( flag == CALC_NUM ){
                    switch( last_op ){
                        case '+':
                            acc = acc + (num*sign);
                            break;
                        case '-':
                            acc = acc - (num*sign);
                            break;
                        case '*':
                            acc = acc * (num*sign);
                            break;
                        case '/':
                            acc = acc / (num*sign);
                            break;
                    }
                }
                sign = 1;
                last_op = *p;
                flag = CALC_OP;
                break;
        }
    }
    printf("%ld\n", acc);

    return 0;

}


