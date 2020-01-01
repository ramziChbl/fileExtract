%{
#include <stdio.h>
%}

%%
2CSSI(Q|L)  {printf("1CS");}
                 
%%
int yywrap(){}
int main(int argc, char *argv[])
{
    FILE *f;
    if(argc == 2)
    {
        f = fopen(argv[1], "r");
    }
    yyset_in(f);

    yylex();
    fclose(f);
    return 0;
}

