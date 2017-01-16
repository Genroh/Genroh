#include <stdio.h>

#define CALC_OP  1
#define CALC_NUM 2
#define CALC_MEM 3

int main(int argc, char *argv[]){

    char last_op = '+', *p = argv[1];
    long sign = 1, flag = CALC_OP;
    //num:-8(%ebp) acc:-12(%ebp) mem:-4(%ebp)

    printf( "\t.data\n"
            "L_fmt:\n"
            "\t.ascii \"%%d\\n\\0\"\n"
            "\t.text\n"
            "\t.global main\n"
            "main:\n"
            "\tpushl %%ebp\n"
            "\tmovl  %%esp, %%ebp\n" );
    printf( "\tsubl  $16, %%esp\n");
    printf( "\tmovl  $0, -12(%%ebp)\n"
            "\tmovl  $0, -4(%%ebp)\n"
            "\tmovl  $0, %%edx\n" );

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
                        printf( "\tmovl  $%c, -8(%%ebp)\n", *p );
                        break;
                    case CALC_NUM:
                        printf( "\tmovl  -8(%%ebp), %%eax\n" );
                        printf( "\timull $10, %%eax\n" );
                        printf( "\taddl  $%c, %%eax\n", *p );
                        printf( "\tmovl  %%eax, -8(%%ebp)\n" );
                        break;
                    case CALC_MEM:
                        last_op = '+';
                        printf( "\tmovl  $%c, -8(%%ebp)\n", *p );
                        printf( "\tmovl  $0, -12(%%ebp)\n" );
                        break;
                }
                flag = CALC_NUM;
                break;
            case 'S':
                sign *= -1;
                break;
            case 'C':
                printf( "\tmovl  $0, -4(%%ebp)\n" );
                break;
            case 'R':
                printf( "\tmovl  -4(%%ebp), %%eax\n"
                        "\tmovl  %%eax, -12(%%ebp)\n" );
                break;
            case 'P':
                if( flag == CALC_NUM ){
                    if( sign == -1 ){
                        printf( "\tmovl  -8(%%ebp), %%eax\n"
                                "\tnegl  %%eax\n"
                                "\tmovl  %%eax, 8(%%ebp)\n" );
                    }
                    switch( last_op ){
                        case '+':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\taddl  -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '-':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\tsubl  -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '*':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\timull -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '/':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\tcltd\n" );
                            printf( "\tidivl -8(%%ebp)\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                    }
                }
                sign = 1;
                printf( "\tmovl  -4(%%ebp), %%eax\n" );
                printf( "\taddl  -12(%%ebp), %%eax\n" );
                printf( "\tmovl  %%eax, -4(%%ebp)\n" );
                flag = CALC_MEM;
                break;
            case 'M':
                if( flag == CALC_NUM ){
                    if( sign == -1 ){
                        printf( "\tmovl  -8(%%ebp), %%eax\n"
                                "\tnegl  %%eax\n" 
                                "\tmovl  %%eax, -8(%%ebp)\n" );
                    }
                    switch( last_op ){
                        case '+':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\taddl  -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '-':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\tsubl  -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '*':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\timull -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '/':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\tcltd\n" );
                            printf( "\tidivl -8(%%ebp)\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                    }
                }
                sign = 1;
                printf( "\tmovl  -4(%%ebp), %%eax\n" );
                printf( "\tsubl  -12(%%ebp), %%eax\n" );
                printf( "\tmovl  %%eax, -4(%%ebp)\n" );
                flag = CALC_MEM;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
                if( flag == CALC_NUM ){
                    if( sign == -1 ){
                        printf( "\tmovl  -8(%%ebp), %%eax\n"
                                "\tnegl  %%eax\n"
                                "\tmovl  %%eax, -8(%%ebp)\n" );
                    }
                    switch( last_op ){
                        case '+':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\taddl  -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '-':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\tsubl  -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '*':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\timull -8(%%ebp), %%eax\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                        case '/':
                            printf( "\tmovl  -12(%%ebp), %%eax\n" );
                            printf( "\tcltd\n" );
                            printf( "\tidivl -8(%%ebp)\n" );
                            printf( "\tmovl  %%eax, -12(%%ebp)\n" );
                            break;
                    }
                }
                sign = 1;
                last_op = *p;
                flag = CALC_OP;
                break;
        }
    }
    printf( "\tpushl -12(%%ebp)\n"
            "\tpushl $L_fmt\n"
            "\tcall  printf\n"
            "\taddl  $8, %%esp\n"
            "\tleave\n"
            "\tret\n" );

    return 0;

}


