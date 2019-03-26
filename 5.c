#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char line[1024],tmp[1024];
  int len;
  int i,j;
  while(fgets(line,1024,stdin)!=NULL){
    memset(tmp,0,sizeof(tmp));
    j=0;
    len=strlen(line);
    if(line[len-1]=='\n') line[len-1]='\0';
    len=strlen(line);
    for(i=0;i<len;i++){
      if(line[i]==' '&&line[i-1]==' ') continue;
      else{
        tmp[j]=line[i];
        j++;
      }
    }
    len=strlen(tmp);
    if(tmp[len-1]==' ') tmp[len-1]='\0';
    if(tmp[0]==' '){
      len=strlen(tmp);
      for(int i=1;i<len;i++){
        printf("%c",tmp[i]);
      }
      printf("\n");
    }
    else printf("%s\n",tmp);
  }
  return 0;
}