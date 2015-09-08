//
//  newfile.c
//  FAr_LP
//
//  Created by admin on 01/09/15.
//  Copyright 2015 __MyCompanyName__. All rights reserved.
///
//  Created by admin on 01/09/15.
//  Copyright 2015 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *p;
    char ch;
    int i=0,k=0,j=0,n=3,m=2,z=0,s=0,t=0,v=0,nrow=0,r=0,hai=0,ektohai=0,val=0;
    char arr[10][10][10],newarr[10][10][10];
    int check[10][10],fill = 0;
    p=fopen("mynewfile.txt","r");
    for(i=0;i<10;i++)
    	for(j=0;j<10;j++)
    		check[i][j]=0;
    i=0;
    j=0;
    while(!feof(p))
    {
        j=0;
        while(1)
        {   
            k=0;
            while(1)
            {
                fscanf(p,"%c",&ch);
               // printf("%d =>%d=>%c\n",i,j,ch);
                if(ch == '-')
                    break;
                if(ch==' ')
                    break;
                if(ch=='\n')
                    break;
                if(ch!=',')
                    arr[i][j][k++]=ch;
            }
            arr[i][j][k]='\0';
            if(ch == ' ')
            {
                j++;
                m=j;
              }
                
            if(ch=='\n')
                break;
        }
        if(ch == '\n')
            i++;
    }
    printf("Read the file **hopefully no errors**\n");
    k=0;
    n=i-1;
  //  printf("Nrow=%d  Ncol = %d\n",n,m);	
    
   // m=j;
   m++;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%s  ",arr[i][j]);
        }
        printf("\n");
    }
    
    //!!!!!!!!!!!CONVERTTING NFA TO DFA!!!!!!!!!!!!!!!
    nrow = n;//saved the initial states
    z = nrow;
    k=0;	
    r=0;
    fill=0;
    for(i=0;i<z;i++)
    {
        for(j=0;j<m;j++)
        {
            k=0;
            if(strlen(arr[i][j])>1)//means more than one state here
            {
               //Now cheking that if we have already assign the state or not
					for(s=0;s<r;s++)
					{	
					//here we need to check if the check matrix contains the state or not
					val=0;
					for(t=0;t<m;t++)
					{
						k=0;
						while(arr[i][j][k]!='\0')
						{
							if(t==(arr[i][j][k]-48))
							{
								ektohai = 1;
								if(check[s][t]==0)
								{
									val = 1;
									break;
								}
							}
							k++;
						}
						//agar ek b value false aati hai to
						if(ektohai==0)
						{
							if(check[s][t]==1)
								val=1;
						}
						else
							ektohai = 0;
							
						if(val==1)//means nhi hai
						{
							break;
						}
					}
					if(val == 0)
					{
						
						hai=1;
						printf("i=%d j=%d hai=%d",i,j,hai);
						break;
					}
					else
					{
						val=0;
					}	
				}
				k=0;
				if(hai == 0 || r==0)//it didn't get it
				{
						//adding a new state to the original matrix
						for(v=0;v<m;v++)
					  	{
							strcpy(arr[z][v],"\0");
						}
					  while(arr[i][j][k]!='\0')
					  {
					  	check[r][arr[i][j][k]-48]= 1;//updating check list of new states
					  	//need to update original matirx
					  	for(v=0;v<m;v++)
					  	{
					  		strcat(arr[z][v],arr[arr[i][j][k]-48][v]);
					  		//printf("str=%s\n",arr[z][v]);
					  	}
					  	k++;
					 }
					  r++;//new row to be added in the check matrix
						newarr[i][j][0]=z+48;
						newarr[i][j][1]='\0';
					  z++;
				}
				else if(hai == 1)
				{
					
					newarr[i][j][0]=nrow+s+48;
					newarr[i][j][1]='\0';
					//printf("i=%d j=%d val = %d\n",i,j,s);
				}	
				            
            }
            else
            {
            	newarr[i][j][0]=arr[i][j][0];
            	newarr[i][j][1]='\0';
            	//printf("i=%d j=%d val = %d\n",i,j,s);
            } 
            fill=0;
            val =0;
            hai=0;
			k=0; 
        }
        
    }
    
    printf("The output:\n");
    for(i=0;i<z;i++)
    {
    	for(j=0;j<m;j++)
    	{
    		printf("%s ",arr[i][j]);
    	}
    	printf("\n");
    }
  /* printf("Check\n");
     for(i=0;i<=r;i++)
    {
    	for(j=0;j<=m;j++)
    	{
    		printf("%d ",check[i][j]);
    	}
    	printf("\n");
    }
    */
    return 0;
}


