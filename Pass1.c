#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  LCount=1,PoolCount ,WCount,LC,symcount=1,lctemp;
char Word1[15],Word2[15],Word3[15],Word4[15],Word5[15],Size[50],temp[15];

int  i,j,k,f1=1;
struct mot
{
    char name[20];
    int opcode;
}mot[11];


struct pot
{
    char name[20];
    int opcode;
}pot[5];

struct reg
{
    char name[20];
    int opcode;
}reg[4];

struct ds
{
    char  name[10];
    int opcode;
}ds[5];

struct compare
{
    char name[20];
    int opcode;
}compare[6];

struct lt
{
    char name[20];
    int opcode;
    int flag;
}lt[10];

struct symbol
{
    char name[20];
    int opcode;
}symbol[10];

int searchmot(char *s,struct mot mot[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(mot[i].name,s)==0)
            return i;
    }

    return -1;
}

int searchpot(char *s,struct pot pot[])
{
    int i;
    for(i=0;i<5;i++)
    {
        if(strcmp(pot[i].name,s)==0)
            return i+1;
    }

    return -1;
}

int searchcompare(char *s,struct compare compare[])
{
    int i;
    for(i=0;i<6;i++)
    {
        if(strcmp(compare[i].name,s)==0)
            return i+1;
    }

    return -1;
}
int searchreg(char *s,struct reg reg[])
{
    int i;
    for(i=0;i<4;i++)
    {
        if(strcmp(reg[i].name,s)==0)
            return i+1;
    }

    return -1;
}
int searchds(char *s,struct ds ds[])
{
    int i;
    for(i=0;i<2;i++)
    {
        if(strcmp(ds[i].name,s)==0)
            return i+1;
    }

    return -1;
}
int searchsym(char *s,struct symbol symbol[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(symbol[i].name,s)==0)
            return i;
    }

    return -1;
}

int searchlt(char *s,struct lt lt[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(lt[i].name,s)==0&&lt[i].flag==f1)
            return i;
    }

    return -1;
}

int main()
{
	int NewLCount=1;


    strcpy(mot[0].name,"STOP");
	mot[0].opcode=0;
    strcpy(mot[1].name,"ADD");
	mot[1].opcode=1;
    strcpy(mot[2].name,"SUB");
	mot[2].opcode=2;
    strcpy(mot[3].name,"MULT");
	mot[3].opcode=3;
    strcpy(mot[4].name,"MOVER")
	;mot[4].opcode=4;
    strcpy(mot[5].name,"MOVEM");
	mot[5].opcode=5;
    strcpy(mot[6].name,"COMP");
	mot[6].opcode=6;
    strcpy(mot[7].name,"BC");
	mot[7].opcode=7;
    strcpy(mot[8].name,"DIV");
	mot[8].opcode=8;
    strcpy(mot[9].name,"READ");
	mot[9].opcode=9;
    strcpy(mot[10].name,"PRINT");
	mot[10].opcode=10;

    strcpy(ds[0].name,"DC");
	ds[0].opcode=1;
    strcpy(ds[1].name,"DS");
	ds[1].opcode=2;

    strcpy(pot[0].name,"START");
	pot[0].opcode=1;
    strcpy(pot[1].name,"END");
	pot[1].opcode=2;
    strcpy(pot[2].name,"EQU");
	pot[2].opcode=3;
    strcpy(pot[3].name,"ORIGIN");
	pot[3].opcode=4;
    strcpy(pot[4].name,"LTORG");
	pot[4].opcode=5;

    strcpy(reg[0].name,"AREG");
	reg[0].opcode=1;
    strcpy(reg[1].name,"BREG");
	reg[1].opcode=2;
    strcpy(reg[2].name,"CREG");
	reg[2].opcode=3;
    strcpy(reg[3].name,"DREG");
	reg[3].opcode=4;

    strcpy(compare[0].name,"LT");
	compare[0].opcode=1;
    strcpy(compare[1].name,"LE");
	compare[1].opcode=2;
    strcpy(compare[2].name,"GT");
	compare[2].opcode=3;
    strcpy(compare[3].name,"GE");
	compare[3].opcode=4;
    strcpy(compare[4].name,"EQ");
	compare[4].opcode=5;
    strcpy(compare[5].name,"ANY");
	compare[5].opcode=6;

       FILE *fp1=fopen("input.txt","r");

        if(fp1==NULL)
        {
            printf("\nInput File doesnt exists\n");
            return 0;
        }

        FILE *fp2=fopen("output.txt","w");

        if(fp2==NULL)
        {
            printf("\nOutputFile doesnt exists\n");
            return 0;
        }

        while(fgets(Size,50,fp1))
        {
            WCount=sscanf(Size,"%s%s%s%s",Word1,Word2,Word3,Word4);

            switch(WCount)
            {
                case 1: i=searchmot(Word1,mot);
                        if(i==0)
                        {
                        	if(lctemp!=0)
                        	{
                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
                        		lctemp=0;
                        		break;
							}
                            fprintf(fp2,"(%03d) (IS %02d)\n",LC++,i);
                            break;
                        }

                       i=searchpot(Word1,pot);
                       if(i==5)
                       {
                            int k;
                            for(k=1;k<LCount;k++)
                            {
                                lt[k].opcode=LC;
                                fprintf(fp2,"(%03d) (%s)\n ",LC++,lt[k].name);

                            }
                            NewLCount=LCount;
                            f1++;
                       }

                       else if(i==2)
                       {
                            int k;
                            for(k=NewLCount;k<LCount;k++)
                            {
                                lt[k].opcode=LC;
                                fprintf(fp2,"(%03d) (%s)\n ",LC++,lt[k].name);
							}
                       }
                       break;
                case 2: i=searchpot(Word1,pot);
                        if(Word1[strlen(Word1)-1]==':')
                        {
                            char temp[10];
                            int l;
                            for(l=0;Word1[l]!=':';l++)
                            {
                                temp[l]=Word1[l];
                            }
                            temp[l]='\0';
                            i=searchsym(temp,symbol);
                            if(i==-1)
                            {
                                strcpy(symbol[symcount].name,temp);
                                symbol[symcount++].opcode=LC;
                            }
                            symbol[i].opcode=LC;
                            int s=searchmot(Word2,mot);
                            if(lctemp!=0)
                        	{
                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
                        		lctemp=0;
                        		break;
							}
                            fprintf(fp2,"(%03d) (IS %d)\n ",LC++,s);
                            break;
                        }
                        if(i==1)
                        {
                            LC=atoi(Word2);
                            fprintf(fp2,"(AD, %02d) (C, %03d)\n",i,LC);
                            break;
                        }

                        if(i==4)
                        {
                            char temp1[10],temp2[10];
                            int j,k;
                            for(j=0;Word2[j]!='+';j++)
                            {
                                temp1[j]=Word2[j];
                            }
                            temp1[j]='\0';
                            int t=0;
                            for(k=j+1;Word2[k]!='\0';k++)
                            {
                                temp2[t++]=Word2[k];
                            }
                            temp2[t]='\0';
                            int inc=atoi(temp2);
                            int lc=searchsym(temp1,symbol);
                            if(lc!=-1)
                            {
                                lctemp=symbol[lc].opcode+inc;
                            }
                            else
                            {
                                printf("Symbol not Present!!!\n");
                            }
                            break;
						}
						break;
                case 3: i=searchmot(Word1,mot);
                        if(i>=1&&i<=8)
                        {
                            int j=searchcompare(Word2,compare);
                            if(j!=-1)
                            {
                                strcpy(symbol[symcount].name,Word3);
                                symbol[symcount++].opcode=0;
                                if(lctemp!=0)
	                        	{
	                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
	                        		lctemp=0;
	                        		break;
								}
                                fprintf(fp2,"(%03d) (IS, %02d) (%d) (S,%d)\n",LC++,i,j,symcount-1);
                                break;
                            }

                            char temp[10];
                            for(j=0;Word2[j]!=',';j++)
                            {
                                temp[j]=Word2[j];
                            }
                            temp[j]='\0';
                            int k=searchreg(temp,reg);
                            if(k!=-1)
                            {
                                    if(Word3[0]=='=')
                                    {
                                    	char temp[10];
                                    	int p;
                                    	for(p=2;p<strlen(Word3)-1;p++)
                                    	{
                                    		temp[p-2]=Word3[p];
										}
										temp[p-2]='\0';
										int t=searchlt(temp,lt);
										if(t==-1)
										{
											strcpy(lt[LCount].name,temp);
											lt[LCount].opcode=-1;
											lt[LCount].flag=f1;
											if(lctemp!=0)
				                        	{
				                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
				                        		lctemp=0;
				                        		break;
											}
											fprintf(fp2,"(%03d) (IS, %02d) (%d) (L,%d)\n",LC++,i,k,LCount++);
                                            break;
										}
										else
										{
											if(lctemp!=0)
				                        	{
				                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
				                        		lctemp=0;
				                        		break;
											}
											fprintf(fp2,"(%03d) (IS, %02d) (%d) (L,%d)\n",LC++,i,k,t);
                                            break;
										}

                                    }
                                    else
                                    {
                                    	int t=searchsym(Word3,symbol);
										if(t==-1)
										{
											strcpy(symbol[symcount].name,Word3);
	                                        symbol[symcount].opcode=-1;
	                                        if(lctemp!=0)
				                        	{
				                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
				                        		lctemp=0;
				                        		break;
											}
	                                        fprintf(fp2,"(%03d) (IS, %02d) (%d) (S,%d)\n",LC++,i,k,symcount++);
	                                        break;
										}
										else
										{
											if(lctemp!=0)
				                        	{
				                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
				                        		lctemp=0;
				                        		break;
											}
											fprintf(fp2,"(%03d) (IS, %02d) (%d) (S,%d)\n",LC++,i,k,t);
                                            break;
										}

                                    }
                            }
                            break;
                        }
				        int k=searchds(Word2,ds);
                        if(k==1)
                        {
                            int t;
                            char temp[10];
                            for(t=1;t<strlen(Word3)-1;t++)
                            {
                                temp[t-1]=Word3[t];
                            }
                            temp[t-1]='/0';
                            t=atoi(temp);
                            i=searchsym(Word1,symbol);
                            if(i==-1)
                            {
                                strcpy(symbol[symcount].name,Word1);
                                symbol[symcount].opcode=LC;
                                if(lctemp!=0)
	                        	{
	                        		fprintf(fp2,"(%03d) (IS %02d)\n",lctemp,i);
	                        		lctemp=0;
	                        		break;
								}
                                fprintf(fp2,"(%03d) (S, %02d) (DL %d) (C %d)\n",LC++,symcount++,k,t);
                                break;
                            }
                            symbol[i].opcode=LC;
                            if(lctemp!=0)
                        	{
                        		fprintf(fp2,"(%03d) (S, %02d) (DL %d) (C %d)\n",lctemp,i,k,t);
                        		lctemp=0;
                        		break;
							}
                            fprintf(fp2,"(%03d) (S, %02d) (DL %d) (C %d)\n",LC++,i,k,t);
                            break;
				        }
                        if(k==2)
                        {
                            i=searchsym(Word1,symbol);
                            if(i==-1)
                            {
                                strcpy(symbol[symcount].name,Word1);
                                if(lctemp!=0)
	                        	{
	                        		symbol[symcount].opcode=lctemp;
	                        		fprintf(fp2,"(%03d) (S, %02d) (DL %d) (C %d)\n",lctemp,symcount++,k,atoi(Word3));
	                        		lctemp=0;
	                        		LC=LC+atoi(Word3);
	                        		break;
								}
								symbol[symcount].opcode=LC;
                                fprintf(fp2,"(%03d) (S, %02d) (DL %03d) (C %d)\n",LC,symcount++,k,atoi(Word3));
                                LC=LC+atoi(Word3);
                                break;
                            }
                            if(lctemp!=0)
	                        	{
	                        		symbol[i].opcode=lctemp;
	                        		fprintf(fp2,"(%03d) (S, %02d) (DL %d) (C %d)\n",lctemp,i,k,atoi(Word3));
	                        		lctemp=0;
	                        		LC=LC+atoi(Word3);
	                        		break;
								}
                            symbol[i].opcode=LC;
                            fprintf(fp2,"(%03d) (S, %02d) (DL %d) (C %d)\n",LC,i,k,atoi(Word3));
                            LC=LC+atoi(Word3);
                            break;
                        }
                        
                        if(strcmp(Word2,"EQU")==0)
                        {
                             i=searchsym(Word3,symbol);
                             int j=searchsym(Word1,symbol);
                             symbol[j].opcode=symbol[i].opcode;
                             break;
						}
                        break;
                case 4: printf(" ");
						char temp[10];
                        int l;
                        for(l=0;Word1[l]!=':';l++)
                        {
                            temp[l]=Word1[l];
                        }
                        temp[l]='\0';
                        i=searchsym(temp,symbol);
                        if(i==-1)
                        {
                        	strcpy(symbol[symcount].name,temp);
                            symbol[symcount++].opcode=LC;
						}
						else
						{
							symbol[i].opcode=LC;
						}
						i=searchmot(Word2,mot);
                        if(i>=1&&i<=8)
                        {
                             char temp[10];
                            for(j=0;Word3[j]!=',';j++)
                            {
                                temp[j]=Word3[j];
                            }
                            temp[j]='\0';
                            int k=searchreg(temp,reg);
                            if(k!=-1)
                            {
                                    if(Word4[0]=='=')
                                    {
                                    	char temp[10];
                                    	int p;
                                    	for(p=2;p<strlen(Word4)-1;p++)
                                    	{
                                    		temp[p-2]=Word4[p];
										}
										temp[p-2]='\0';
										int t=searchlt(temp,lt);
										if(t==-1)
										{
											strcpy(lt[LCount].name,temp);
											lt[LCount].opcode=-1;
											lt[LCount].flag=f1;
											if(lctemp!=0)
				                        	{
				                        		fprintf(fp2,"(%03d) (IS, %02d) (%d) (L,%d)\n",lctemp,i,k,LCount++);
				                        		lctemp=0;
				                        		break;
											}
											fprintf(fp2,"(%03d) (IS, %02d) (%d) (L,%d)\n",LC++,i,k,LCount++);
                                            break;
										}
										else
										{
											fprintf(fp2,"(%03d) (IS, %02d) (%d) (L,%d)\n",LC++,i,k,t);
                                            break;
										}

                                    }
                                    else
                                    {
                                    	int t=searchsym(Word4,symbol);
										if(t==-1)
										{
											strcpy(symbol[symcount].name,Word3);
	                                        symbol[symcount].opcode=-1;
	                                        if(lctemp!=0)
				                        	{
				                        		fprintf(fp2,"(%03d) (IS, %02d) (%d) (S,%d)\n",lctemp,i,k,symcount++);
				                        		lctemp=0;
				                        		break;
											}
	                                        fprintf(fp2,"(%03d) (IS, %02d) (%d) (S,%d)\n",LC++,i,k,symcount++);
	                                        break;
										}
										else
										{
											 if(lctemp!=0)
				                        	{
				                        		fprintf(fp2,"(%03d) (IS, %02d) (%d) (S,%d)\n",lctemp,i,k,t);
				                        		lctemp=0;
				                        		break;
											}
											fprintf(fp2,"(%03d) (IS, %02d) (%d) (S,%d)\n",LC++,i,k,t);
                                            break;
										}

                                    }
                            }
                            else
                            {
                            	printf("Register not present!!!");
                            	return 0;
							}
                            break;
                        }
                        else
						{
                        	printf("IS not present!!!!");
                        	return 0;
						}
                        break;
			}
        }

    printf("Literal Table \n");
    for(i=1;i<LCount;i++)
    {
    	printf("%s %d \n",lt[i].name,lt[i].opcode);
	}
	printf("\n");
	printf("Symbol Table \n");
	for(i=1;i<symcount;i++)
    {
    	printf("%s %d\n",symbol[i].name,symbol[i].opcode);
	}
	printf("\n");
	printf("PoolTab \n");
	{
		printf("1\n");
		for(i=2;i<LCount;i++)
		{
			if(lt[i].flag!=lt[i-1].flag)
			 	printf("%d\n",i);
		}
	}
	
    return 0;
}


