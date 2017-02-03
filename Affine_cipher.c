#include<stdio.h>
#include<stdio.h>
int MI(int r1,int r2)
{
    int q,r,s1=1,s2=0,s,t1=0,t2=1,t;
    while(r2!=0)
    {
        q=r1/r2;
        r=r1%r2;
        s=s1-s2*q;
        t=t1-t2*q;
        r1=r2;r2=r;
        s1=s2;s2=s;
        t1=t2;t2=t;
    }
    if(r1!=1)
        return -1;
    else
    {
        if(t1>=0)
        {
             return t1;
        }
        else
        {
            return (26+t1);
        }
    }
}
int main()
{
    printf("\t\tEncryption\n\n");
    int k1;
    int k2;
    printf("\nEnter Key1: ");
    scanf("%d",&k1);
    printf("\nEnter Key2: ");
    scanf("%d",&k2);
    char pt[1000000];
    printf("\nEnter Plain Text: ");
    scanf("%s",&pt);
    int i;
    char ct[1000000];
    for(i=0;i<strlen(pt);i++)
    {
        char c;
        if(pt[i]>=65&&pt[i]<=90)
        {
            c=pt[i]-65;
            ct[i]=(c * k1 + k2)%26 + 65;
        }
        else if(pt[i]>=97&&pt[i]<=122)
        {
            c=pt[i]-97;
            ct[i]=(c * k1 + k2)%26 + 97;
        }
        else
        {
            ct[i]=pt[i];
        }
    }
    printf("\nCipher Text: ");
    printf("%s",ct);
    printf("\n\n\t\tDecryption\n\n");
    printf("\nEnter Key1: ");
    scanf("%d",&k1);
    printf("\nEnter Key2: ");
    scanf("%d",&k2);
    printf("\nEnter Cipher Text: ");
    scanf("%s",&ct);
    k1=MI(26,k1);
    if(k1==-1)
        printf("\n**Invalid Key**");
    else
    {
        for(i=0;i<strlen(ct);i++)
        {
            if(ct[i]>=65&&ct[i]<=90)
            {
                ct[i]=ct[i]-65;
                if(ct[i] - k2<0)
                    pt[i]=((ct[i] - k2 + 26) * k1 )%26 + 65;
                else
                    pt[i]=((ct[i] - k2) * k1 )%26 + 65;
            }
            else if(ct[i]>=97&&ct[i]<=122)
            {
                ct[i]=ct[i]-97;
                if(ct[i] - k2<0)
                    pt[i]=((ct[i] - k2 + 26) * k1 )%26 + 97;
                else
                    pt[i]=((ct[i] - k2) * k1 )%26 + 97;
            }
            else
            {
                pt[i]=ct[i];
            }
        }
    }
    printf("\nPlain Text: ");
    printf("%s",pt);
    return 0;
}
