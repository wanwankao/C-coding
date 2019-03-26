#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
 int num[5];
 int sum;
};
struct student grade[100];
int sort(int people){
 int a,b,c,d;
 int temp[5];
 int tmp;
 for(a=people;a>0;a--){
  for(b=0;b<a;b++){
   if(grade[b].sum<grade[b+1].sum){
    for(c=0;c<5;c++){
     temp[c]=grade[b].num[c];
     grade[b].num[c]=grade[b+1].num[c];
     grade[b+1].num[c]=temp[c];
    }
    tmp=grade[b].sum;
    grade[b].sum=grade[b+1].sum;
    grade[b+1].sum=tmp;
   }
  }
 }
}
int main(){
 char input[1000];
 char *pch;
 int i=0,j,count=0;
 while(fgets(input,1000,stdin)!=NULL){
  for(j=0;j<5;j++){
   grade[i].num[j]=0;
  }       //struct規0
  j=0;
  grade[i].sum=0;
  pch=input;
  while(*pch!='\n'&&*pch!='\0'){
   grade[i].num[j]=atoi(pch);
   grade[i].sum=grade[i].sum+grade[i].num[j];
   while(*pch!=' '&&*pch!='\n'){
    pch++;
   }
   pch++;
   j++;
  }
  count++;
  i++;
 }
 sort(count);
 for(i=0;i<count;i++){
  printf("%d %d %d %d %d\n",grade[i].num[0],grade[i].num[1],grade[i].num[2],grade[i].num[3],grade[i].num[4]);  
 }
}