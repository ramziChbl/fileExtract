%{
#include <stdio.h>
%}

%%
[a-zA-Z0-9]+    {if(yyleng == 8)   printf("Mot de passe\n");
                 else   printf("Identificateur\n");} 
%%
int yywrap(){}
int main(int argc, char *argv[])
{
    yylex();
    return 0;
}

