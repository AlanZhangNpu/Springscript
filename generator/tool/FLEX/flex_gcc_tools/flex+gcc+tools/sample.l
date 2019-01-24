%{
/*The codes in this file are from 
http://blog.csdn.net/opendba/article/details/5949762*/
#include "stdio.h"
#include "stdlib.h"
int num_num=0,num_id=0;
%}

INTEGER [-+]?[1-9][0-9]*
ID [a-zA-Z][a-zA-Z_0-9]*
SPACE [ /n/t]

%%

{INTEGER} { num_num++;
  printf("(num=%d)/n",atoi(yytext));/*��ӡ����ֵ*/
    /*��������һ*/
}

{ID} { num_id++;
    printf("(id=%s)/n",yytext);
    }

{SPACE} |
. {
   /*ʲôҲ����,�˵����ַ��������ַ�*/
   }

%%

int main()
{
   yylex();
   printf("num=%d,id=%d/n",num_num,num_id);
   return 0;
}

int yywrap()//�˺����������û��ṩ
{
    return 1;
}