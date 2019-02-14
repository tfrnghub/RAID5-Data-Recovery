#include<stdio.h>
int main()
{
    FILE *fp1,*fp2,*fp3;
    unsigned int tmp;
    fp1=fopen("disk0","rb");
    fp2=fopen("disk2","rb");
    fp3=fopen("new_disk1","wb");
    while((tmp=fgetc(fp1))!=EOF)
    {
        tmp^=fgetc(fp2);
        fputc(tmp,fp3);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}

