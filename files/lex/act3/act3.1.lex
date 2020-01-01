%{
#include <stdio.h>
%}

%%
%\.[abc%]+\.%
%%
int yywrap(){}
int main(int argc, char *argv[])
{
    yylex();
    return 0;
}

