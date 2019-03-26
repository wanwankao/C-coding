#include <stdio.h>
char b[1000];
int cnt = 0;
int l(char in[])
{
	int len = 0;
	while(in[len]!='\0')
	len++;
	return len;
}
void cat(char a[])
{
	int len  = l(a);
	for(int i = 0 ; i <len;i++)
		b[cnt++] = a[i];
}
int main(int argc, char *argv[])
{
	char in[1024];
	printf("%s",argv[1]);
	while(fgets(in,1024,stdin)!=NULL)
	{
		//cat(" ");
		int len = l(in);
		if(in[len-1]=='\n') in[len-1] = '\0';
		len = l(in);
		cat(in);
	}
	printf("%s\n",b);
	return 0;
}