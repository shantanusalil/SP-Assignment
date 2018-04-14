/*
E -> E*T | T
T -> T+F | F
F -> (E) | id

->removing left recursion
E -> TE'
E' -> *TE' | ε
T -> FT'
T' -> +FT' | ε
F -> (E) | id

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[100];
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F();
          main()
          {
i=0;
error=0;
                printf("Enter an arithmetic expression   :  "); // Eg: a+a*a
                gets(input);
                E();
                if(strlen(input)==i&&error==0)
                        printf("\nAccepted..!!!\n");
                else printf("\nRejected..!!!\n");
                          }



void E()
{printf("E -> TE'\n");
     T();
     Eprime();
}
void Eprime()
{
     if(input[i]=='*')
     { printf("E' -> *TE'\n");
     i++;
     T();
     Eprime();

     }
    else printf("E'-> epsilon\n");
     }
void T()
{printf("T -> FT'\n");
     F();
     Tprime();
}
void Tprime()
{
     if(input[i]=='+')
     {printf("T' -> +FT'\n");
                      i++;
                      F();
                      Tprime();
                      }
                      else printf("T'->epsilon\n");
}
     void F()
     {
          if(isalnum(input[i]))
                { printf("F -> id \n");
                  i++;
                }
          else if(input[i]=='(')
          {
		  i++;

		  E();
		  if(input[i]==')')
		 {

			  i++;
			printf("F -> E \n");
		}
		  else error=1;
            }

          else error=1;
          }
