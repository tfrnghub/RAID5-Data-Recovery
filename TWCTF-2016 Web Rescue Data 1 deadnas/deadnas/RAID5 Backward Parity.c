//RAID5 Backward Parity[Adaptec]
#include<stdio.h>
int stripe=0x200;//stripe size
int main()
{
    FILE *fp;
    int n;
    unsigned char tmp0[0x90000];
    unsigned char tmp1[0x90000];
    unsigned char tmp2[0x90000];
    
    fp=fopen("disk0","rb");
    n=fread(tmp0,1,0x90000,fp);
    printf("%x\n",n);
    fclose(fp);
    
    fp=fopen("new_disk1","rb");
    n=fread(tmp1,1,0x90000,fp);
    printf("%x\n",n);
    fclose(fp);
    
    fp=fopen("disk2","rb");
    n=fread(tmp2,1,0x90000,fp);
    printf("%x\n",n);
    fclose(fp);
    
    int i,j;
    fp=fopen("disk","wb");
    for(i=0;i<0x400;i++)
    {
        j=i*stripe;
        if(i%3!=2)
            fwrite(tmp0+j,1,stripe,fp);
        if(i%3!=1)
            fwrite(tmp1+j,1,stripe,fp);
        if(i%3!=0)
            fwrite(tmp2+j,1,stripe,fp);
    }
    fclose(fp);
    
 

    return 0;
}

