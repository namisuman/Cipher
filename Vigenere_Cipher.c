#include<stdio.h>
#include<string.h>
int main()
{
    char msg[1000000];
    printf("enter Plain Text: \n");
    scanf("%s",&msg);
    char key[20];
    printf("enter the key: ");
    scanf("%s",&key);
    int i,j=0,c;
    for(i=0;i<strlen(msg);i++)
    {
        c=msg[i];
        if(c>=65&&c<=90)
        {
            c=msg[i]-65;
            c=(c+ key[j] -65)%26;
            msg[i]=c+65;
        }
        else if(c>=97&&c<=122)
        {
            c=msg[i]-97;
            c=(c+ key[j] -97)%26;
            msg[i]=c+97;
        }
        else
            msg[i]=c;
        j=(j+1) % (strlen(key));
    }
    printf("Cipher Text: \n");
    printf("%s",msg);
    printf("\n\nenter Cipher Text: \n");
    scanf("%s",&msg);
    printf("enter the key: ");
    scanf("%s",&key);
    j=0;
    for(i=0;i<strlen(msg);i++)
    {
        c=msg[i];
        if(c>=65&&c<=90)
        {
            c=(c - key[j]);
            if(c<0)
                c=c+26;
            msg[i]=c+65;
        }
        else if(c>=97&&c<=122)
        {
            c=msg[i];
            c=(c- key[j]);
            if(c<0)
                c=c+26;
            msg[i]=c+97;
        }
        else
            {msg[i]=c;}
        j=(j+1) % (strlen(key));
    }
    printf("Plain Text: \n");
    printf("%s",msg);
    return 0;
}
