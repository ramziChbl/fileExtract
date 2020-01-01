%{
#include <stdio.h>
%}

%%
(ab)*c|a
[0-9]+	{printf("Nombre detecte, taille = %d", yyleng);}
.
%%
int yywrap(){}
int main(int argc, char *argv[])
{
    yylex();
    return 0;
}

