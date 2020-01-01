%{
#include <stdio.h>
%}

%%
2CSSI(Q|L)   {printf("1CS");}
                 
%%
int yywrap(){}
int main(int argc, char *argv[])
{
    yylex();
    return 0;
}

