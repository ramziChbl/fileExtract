%{
#include <stdio.h>
%}

%%
main    {printf("(mot-cle,main)");}
if      {printf("(mot-cle,if)");}
else    {printf("(mot-cle,else)");}
while    {printf("(mot-cle,while)");}
do    {printf("(mot-cle,do)");}
switch    {printf("(mot-cle,switch)");}
of    {printf("(mot-cle,of)");}
break    {printf("(mot-cle,break)");}
[a-zA-Z][a-zA-Z0-9]*    {printf("(id,%s)", yytext);}
[0-9]+  {printf("(con,%s)", yytext);}

(<|<=|=|<>|>|>=|\+|-)    {printf("(operateur,%s)",yytext);}
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

