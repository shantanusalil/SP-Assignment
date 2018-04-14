
#include<stdio.h>
#include<string.h>

int litcnt=1,symcnt=1,i,j,k,l,flag,wordcnt;
char Buffer[90],word1[20],word2[20],word3[20],word4[20];
struct symtab{
char name[20];
int value;

}symtab[10];

struct littab{
char name;
int value;
int flag;
}littab[10];
void print()
{
    printf("symtable\n");
    for (i=1;i<symcnt;i++)
    {
        printf("%s   %d\n",symtab[i].name,symtab[i].value);
    }
    printf("littable\n");
    for (i=1;i<litcnt;i++)
    {
        printf("%c   %d   %d\n",littab[i].name,littab[i].value,littab[i].flag);
    }


}
int main()
{ int flag=0;
    FILE *fp1=fopen("input_table.txt","r");
    if(fp1==NULL)printf("file not opened\n");
    //printf("*");
    while(fgets(Buffer,80,fp1)){
        wordcnt=sscanf(Buffer,"%s%s%s",word1,word2,word3);
        //printf("%d\n",wordcnt);
        if(wordcnt==2)
        { strcpy(symtab[symcnt].name,word1);
            int temp=atoi(word2);
            symtab[symcnt].value=temp; symcnt++;

        }
        else if(wordcnt==3)
        {
            littab[litcnt].name=word1[0];
            littab[litcnt].value=atoi(word2);
            littab[litcnt].flag=atoi(word3); litcnt++;

        }
        else continue;

    }
//print();

fclose(fp1);
fp1=fopen("output.txt","r");
FILE *fp2=fopen("pass2out.txt","w");

        fgets(Buffer,50,fp1);
        while(fgets(Buffer,50,fp1))
        {
        wordcnt=sscanf(Buffer,"%s%s%s%s",word1,word2,word3,word4);
        if(wordcnt==2)
        {printf("\n");
            i=1;
            while(word1[i]!=')'){printf("%c",word1[i]); i++;} printf(" ");
            if(word2[1]=='I')
               {
                   i=4;
                   while(word2[i]!=')'){printf("%c",word2[i]); i++;} printf("  ");
               }
        }
        if(wordcnt==4)
        {printf("\n");
            i=1;
            while(word1[i]!=')'){printf("%c",word1[i]); i++;} printf(" ");

            if(word2[1]=='I')
            {
                i=4; while(word2[i]!=')'){printf("%c",word2[i]); i++;} printf("  ");
                i=1;

                while(word3[i]!=')'){printf("%c",word3[i]); i++;} printf(" ");

                            if(word4[1]=='L')
                            {
                                int x=(int)word4[3];
                                x=x-'0';
                                printf("%d ",littab[x].value); printf(" ");

                            }

                                if(word4[1]=='S')
                            {
                                int x=(int)word4[3];
                                x=x-'0';
                                printf("%d",symtab[x].value); printf(" ");

                            }
            }
            /*
            else if(word2[1]=='S')
            {
                int x=(int)word2[4];
                x=x-'0';
                printf("%d",symtab[x].value); printf(" ");
                i=4;

                while(word3[i]!=')'){printf("%c",word3[i]); i++;} printf(" ");
                printf("%c",word4[3]); printf(" ");
            }
            */
        }

        }





}
