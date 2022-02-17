#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int * decToBin(int);
void help();
main()
{
    char c;
    int label=0, countWord=0, i=0;
    FILE *f1, *f2;
    int *p;
    f1=fopen("Code.txt","r");
    f2=fopen("Symbol.txt","w");
    char a[20];
    fscanf(f1,"%s",a);
    while(!feof(f1))
    {
        countWord++;
        fscanf(f1,"%s",a);
    }
    fclose(f1);
    char arr[countWord][6];
    char labelarr[countWord][10];
    int b=0, o=0;
    f1=fopen("Code.txt","r");
    fscanf(f1,"%s",a);
    while(!feof(f1))
    {
        if(strchr(a,':')!=NULL)
        {
            label=strlen(a);
            a[label-1]='\0';
            strcpy(labelarr[b++],a);
            p=decToBin(((rand()%100)+1));
            int counter = 0;
            fprintf(f2,"%s ",a);
            while(counter<7)
            {
                fprintf(f2,"%d",*(p+counter));
                counter++;
            }
            fprintf(f2,"\n");
        }
        fscanf(f1,"%s",a);
    }
    fclose(f1);
    int flag1=0;
    f1=fopen("Code.txt","r");
    fscanf(f1,"%s",a);
    while(!feof(f1))
    {

        if(strchr(a,':')!=NULL);
        else if(strlen(a)==2 || strlen(a)==1);
        else if(strchr(a,'0')!=NULL || strchr(a,'1')!=NULL || strchr(a,'2')!=NULL || strchr(a,'3')!=NULL || strchr(a,'4')!=NULL || strchr(a,'5')!=NULL || strchr(a,'6')!=NULL || strchr(a,'7')!=NULL || strchr(a,'8')!=NULL || strchr(a,'9')!=NULL);
        else
        {
            int m=0;
            for(m=0;m<b;m++)
            {
                if(strcmp(a,labelarr[m])==0)
                {
                    flag1=1;
                }
            }
            if(flag1==0)
            {
                strcpy(arr[i++],a);
            }
            flag1=0;
        }
        fscanf(f1,"%s",a);
    }
    fclose(f1);
    int j=0;
    char codes[50][5];
    FILE *f3=fopen("Opcode.txt","r");
    fscanf(f3,"%s",a);
    while(!feof(f3))
    {
        if(strchr(a,'1')==NULL || strchr(a,'0')==NULL)
        {
                strcpy(codes[j++],a);
        }
        fscanf(f3,"%s",a);
    }
    int k=0, l=0;
    printf("Total instructions in the code : \n");
    for(k=0;k<i;k++)
    {
        printf("%s\t",arr[k]);
    }
    int flag=0;
    int y=0;
    for(k=0;k<i;k++)
    {
        for(l=0;l<j;l++)
        {
            if(strcmp(arr[k],codes[l])==0)
            {
                printf("\n%s instruction found in the OPCODE File", arr[k]);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
           printf("\n%s is not a valid instruction", arr[k]);
           printf("\n");
           printf("Select an option:\n1. Help\n2. Continue\n");
           scanf("%d", &y);
           if(y==1)
           {
                help();
           }
        }
        flag=0;
    }
    printf("\n");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    f1=fopen("Code.txt", "r");
    f2=fopen("Symbol.txt", "r");
    f3=fopen("Opcode.txt", "r");
    FILE *f4=fopen("Register.txt", "r");
    FILE *f5=fopen("Binary.txt", "w");
    int q, value, flag2=0;
    char d[20];
    int *x;
    int counter1;
    fscanf(f1,"%s",a);
    while(!feof(f1))
    {
        if(strchr(a,':')!=NULL)
        {
            label=strlen(a);
            a[label-1]='\0';
        }
        f2=fopen("Symbol.txt", "r");
        fscanf(f2,"%s",d);
        while(!feof(f2))
        {
            if(strcmp(a,d)==0)
            {
                fscanf(f2,"%s",d);
                fprintf(f5,"\n%s",d);
                flag2=1;
                break;
            }
            fscanf(f2,"%s",d);
        }
        f3=fopen("Opcode.txt", "r");
        fscanf(f3,"%s",d);
        while(!feof(f3))
        {
            if(strcmp(a,d)==0)
            {
                fscanf(f3,"%s",d);
                fprintf(f5,"\n%s",d);
                flag2=1;
                break;
            }
            fscanf(f3,"%s",d);
        }
        f4=fopen("Register.txt", "r");
        fscanf(f4,"%s",d);
        while(!feof(f4))
        {
            if(strcmp(a,d)==0)
            {
                fscanf(f4,"%s",d);
                fprintf(f5,"\t%s",d);
                flag2=1;
                break;
            }
            fscanf(f4,"%s",d);
        }
        if(flag2==0)
        {
            if(strchr(a,'0')!=NULL || strchr(a,'1')!=NULL || strchr(a,'2')!=NULL || strchr(a,'3')!=NULL || strchr(a,'4')!=NULL || strchr(a,'5')!=NULL || strchr(a,'6')!=NULL || strchr(a,'7')!=NULL || strchr(a,'8')!=NULL || strchr(a,'9')!=NULL)
            {
                value=atoi(a);
                x=decToBin(value);
                counter1 = 0;
                fprintf(f5,"\t");
                while(counter1<7)
                {
                    fprintf(f5,"%d",*(x+counter1));
                    counter1++;
                }
            }
        }
        flag2=0;
        fscanf(f1,"%s",a);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
}
int* decToBin(int decNumber)
{
    int quo;
    int i, j;
    int* binNumber;
    binNumber=(int*)malloc(7*sizeof(int));
    for(i=0; i<7; i++)
    {
        binNumber[i]=0;
    }
    i=6;
    quo = decNumber;
    while(quo!=0)
    {
         binNumber[i--]= quo % 2;
         quo = quo / 2;
    }
    return binNumber;
}
void help()
{
    FILE *f6=fopen("Help.txt", "r");
    char a[20];
    while(!feof(f6))
    {
        fscanf(f6,"%s",a);
        if(strchr(a,'.')!=NULL)
        {
            printf("%s\n", a);
        }
        else
        {
            printf("%s ", a);
        }
    }
    return;
}
