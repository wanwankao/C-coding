#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char source[1024],target[1024];
char line[1024];
char tmp[40][1024];

void front(int len,int cnt)
{
 // printf("line %s\n",line);
  int i,j,count=0;
  for(i=0 ; i<len ; i++){
    if(strncmp(line+i,source,strlen(source))!=0) count++;
    else break;
  }
  //printf("count %d\n",count);
  for(i=0 ; i<count ; i++){
    tmp[cnt][i]=line[count-i-1];
  }
  //printf("tmp %s",tmp[cnt]);
  strcat(tmp[cnt],target);
  char *pch;
  pch=line;
  strcat(tmp[cnt],pch+count+strlen(source));
  //printf("tmp %s",tmp[cnt]);
  
}

void back(int len,int cnt){
  int i,j,count=0;
  char Tmp[100];
  memset(Tmp,'\0',sizeof(char));
  for(i=0 ; i<len ; i++){
    if(strncmp(line+i,source,strlen(source))!=0) count++;
    else break;
  }
  //printf("count %d\n",count);
  for(i=0 ; i<count ; i++){
    tmp[cnt][i]=line[i];
  }
  //strncpy(tmp[cnt],line,count);
  strcat(tmp[cnt],target);
  //printf("tmp %s",tmp[cnt]);
  /*for(i=0,j=len ; j>count+strlen(source) ; j--,i++){
    Tmp[i]=line[j-1];
  }*/
  for(i = len; i >=0;i--)
  {
    Tmp[i]=line[len-i-1];
  }
  //printf("Tmp %s %d\n",Tmp,strlen(Tmp));
  strncat(tmp[cnt],Tmp,len - count - strlen(source));
  //printf("tmp %s",tmp[cnt]);
}

int main(int argc,char *argv[]){
  for(int i = 0;i < 40;i++ )
    memset(tmp[i],'\0',sizeof(char));
  strcpy(source,argv[argc-2]);
  strcpy(target,argv[argc-1]);
  int len,cnt=0,i;
  while(fgets(line,1024,stdin)!=NULL){
    len=strlen(line);
    if(line[len-1]=='\n') line[len-1]='\0';
    len=strlen(line);
    if(strcmp(source,target)>0) front(len,cnt);
    else back(len,cnt);
    cnt++;
     // printf("%s\n",tmp[cnt-1]);
  }
  for(i=cnt-1 ; i>=0 ; i--){
    printf("%s\n",tmp[i]);
  }
  return 0;
}