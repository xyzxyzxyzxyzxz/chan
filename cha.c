#include<stdlib.h>
#include<stdio.h>

int main (int argc,char *argv[])
{
	char *strh,gd[130],sthle[5]={'\0'};
	int i=0;
	unsigned int hle=0;
	
	FILE *fpn,*fpo;
	
	printf("origin file name \"p\" ,new file name \"p_n\"\n");
	
	if((fpn=fopen("p_n","wb"))==NULL)
	{
		printf("open file \"p_n\" wrong");
		exit(1);
	}
	if((fpo=fopen("p","rb"))==NULL)
	{	
		printf("open file \"p\" wrong");
		exit(1);
	}
	
	strh=(char *)malloc(1000);
		
	printf("input string ,first letter must be ascii\n");
	scanf("%s",strh);
	
	while (strh[i++]!='\0');
	i--;
	
	hle=(unsigned int)strh[0];
	
	sprintf(sthle,"%04d",i);
	
	
	fprintf(fpn,"%c",strh[0]);
	fwrite(sthle,1,4,fpn);
	
	fread(gd,hle,1,fpo);
	fwrite(gd,hle,1,fpn);
	
	fprintf(fpn,"%s",strh);
	
	while (!feof(fpo))
	{
		fread(gd,1,4,fpo);
		//printf("%s",gd);
		fwrite(gd,1,4,fpn);
	}
	
	free(strh);
	return 0;
}
