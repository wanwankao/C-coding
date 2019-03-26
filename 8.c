#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word{
 char ptr[30];
 struct word *next;
};
  int main(){
  char input[30];
  struct word *head=NULL,*pre=NULL,*cur=NULL;
 int flag=0;
 while(fgets(input,30,stdin)!=NULL){
  if(input[strlen(input)-1]=='\n'){
   input[strlen(input)-1]='\0';
  }
  if(head==NULL){
   head=(struct word*)malloc(sizeof(struct word));
   strcpy(head->ptr,input);
   head->next=NULL;
  }
  else if(head!=NULL){
   pre=NULL;
   cur=head;
   while(cur!=NULL&&strcmp(cur->ptr,input)<0){
    pre=cur;
    cur=cur->next;
   }
   if(cur==NULL){
    cur=(struct word*)malloc(sizeof(struct word));
    cur->next=NULL;
    pre->next=cur;
    strcpy(cur->ptr,input);
   }
   else if(cur!=NULL){
    if(strcmp(cur->ptr,input)==0){
     continue;
    }
    if(cur==head){
     head=NULL;
     head=(struct word*)malloc(sizeof(struct word));
     head->next=cur;
     strcpy(head->ptr,input);
    }
    else if(cur!=head){
     pre->next=(struct word*)malloc(sizeof(struct word));
     pre->next->next=cur;
     strcpy(pre->next->ptr,input);
    }
   }
  }
 }
 pre=NULL;
 cur=head;
 while(cur!=NULL){
  printf("%s\n",cur->ptr);
  pre=cur;
  cur=cur->next;
 }
}