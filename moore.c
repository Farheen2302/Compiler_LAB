#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *p;
	char moore[10][10];
	char final[10];
	char ch, *inputstr;
	int state,begin,i=0,j=0,k=0,l=0,f=0,flag =0,flag2=0,val=0;

	p = fopen("moorefile.txt","r");
	inputstr = (char *)malloc(sizeof(char)*100);

	//starting state
	fscanf(p,"%ch",&ch);
	begin = ch-48;
	fscanf(p,"%ch",&ch);//for '\n'
	fscanf(p,"%ch",&ch);//for next character

	while(ch!='\n')
	{
		if(ch!=' ')
			final[f++] = ch-48;//final states
		fscanf(p,"%ch",&ch);

	}

	fscanf(p,"%ch",&ch);//for next character

	while(!feof(p))
	{
		if(ch == '\n')
		{
			i++;
			j=0;
		}
		else if(ch!=' ')
		{
			moore[i][j]=ch;//matrix of the automata
			j++;
		}

		fscanf(p,"%ch",&ch);
		
	}


	k=0;

	//checking if file properly read or not
	for(k=0;k<=i;k++)
	{
		for(l=0;l<j;l++)
		{
			printf("%d  ",moore[k][l]-48);
		}
		printf("\n");
	}
	k=0;
	//now implementing moore machine
	printf("Enter the \"STOP\" to stop\n");	

	while(1)
	{
		k=0;
		printf("Enter the input string::\n");
		scanf("%s",inputstr);
		printf("OUTP\n");
		if(strcmp(inputstr,"STOP")==0)
			break;
		state = begin;
		
		while(*(inputstr+k)!='\0')
		{
			if(*(inputstr+k)-97>=0 && *(inputstr+k)-97<=(j-2))
			{
				printf("%d\n",moore[state][2]-48);
				val = inputstr[k]-97;
				if(moore[state][val] == '-')
				{
					flag=1;
					break;
				}
				state = moore[state][val] - 48;
				k++;
			}
			else
			{
				flag=1;
				break;
			}
		}
		l=0;
		
		while(l<f)
		{
			if(final[l++]==state)
			{
				flag2 = 1;
				break;
			}
		}

		if(flag==1 || flag2==0)
			printf("STRING NOT ACCEPTED\n");
		else
			printf("STRING ACCEPTED\n");
		flag =0;
		flag2 =0;
		strcpy(inputstr,"\0");

	}
}