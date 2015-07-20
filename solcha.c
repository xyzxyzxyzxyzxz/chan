#include<stdlib.h>
#include<stdio.h>

int main (int argc,char *argv[])
{
	char *strh,gd[130],sthle[5]={'\0'};
	
	unsigned int hle=0,nsthle=0;
	
	
	FILE *fpn,*fpo;
	
	printf("origin file name \"p_n\" ,new file name \"p_n1\"\n");
	
	if((fpn=fopen("p_n1","wb"))==NULL)
	{
		printf("open file \"p_n1\" wrong");
		exit(1);
	}
	if((fpo=fopen("p_n","rb"))==NULL)
	{	
		printf("open file \"p_n\" wrong");
		exit(1);
	}
	
	strh=(char *)malloc(1000);
	
	fread(strh,1,1,fpo);
	fread(sthle,1,4,fpo);
	
	hle=(unsigned int)strh[0];
	nsthle=(unsigned int)atoi(sthle);
		

	fread(gd,hle,1,fpo);
	fwrite(gd,hle,1,fpn);
	
	fread(strh,nsthle,1,fpo);
	
	while (!feof(fpo))
	{
		fread(gd,1,4,fpo);
		//printf("%s",gd);
		fwrite(gd,1,4,fpn);
	}
	
}
