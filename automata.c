//
//  automata.c
//  AUTOMATA
//
//  Created by student_account on 11/08/15.
//  Copyright 2015 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int arr[10][10];
    FILE *p;
    int i=0,len=0,st = 0,state = 0,init,final[100],k=0,m=0,n=0,j=0,flag =0;
    char ch;
    char str[100];
    int chr;
    
    p = fopen("myfile.txt","r");
    	
    
    i = 0;
    
    fscanf(p,"%c",&ch);                                                                                                                                                                                                                                                                                                                                                                                                                                            
    init = ch - 48;
 
    fscanf(p,"%c",&ch);
    
    while(1)
    {
        fscanf(p,"%c",&ch);
        
        if(ch != '\n')
            {
                final[k++] = ch-48;
                }
        else
            {
                break;
            }
            
    }
 
    
    while(!feof(p))
        {
            while(1)
            {
                fscanf(p,"%c",&ch);
               
                if(ch != '\n')
                {
                    if(ch != ' ')
                        
                    {
                        if(ch == '-')
                            arr[m][n++] = -1;
                        else
                        {
                        arr[m][n++] = (int)(ch - 48);
                        }
   
                    }
                     
                    st = n;}
                else
                {
                    
                    break;
                    
                }
            }
            n=0;
            m++;
        }
        
    printf("\nEnter \"STOP\" to stop\n");
    
   while(1)
   { 
    printf("\nEnter the input string\n");
    scanf("%s",str);
    
    if(strcmp(str,"STOP")==0)
    	break;
    	
    len = strlen(str);
    i =0;
   
    while(*(str + i)!='\0')
    {
        chr = ((str[i])-97) ;
        if(chr<st)   
        {
            state = arr[state][chr];
            if(state == -1)
            {
		       flag = 1;
		   }
            
        }
        else
        {
            flag = 1;
        }
        i++;
    }
    i = 0;
    if(flag!=1)
    {
    	flag =1;
		for(i = 0;i<k;i++)
		{
		    if(state == final[i])
		    {
		        printf("STRING ACCEPTED\n");
		        flag = 0;
		     	break;
		    }
		}
	}
    if(flag == 1)
    {
        printf("NOT ACCEPTED!!\n");
    }
   }
}
