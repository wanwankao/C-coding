#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
struct stack{
	int weight;
	int full;
	struct stack *next;
};
struct stack *top=NULL,*cur=NULL,*top2=NULL,*newadd=NULL;
int weightsum=0;
int fullsum=0;
int weight,full;
//堆線滿 
int isfull(){
	if(weightsum+weight>MAXSIZE){
		return 1;
	}
	else{
		return 0;
	}
}
//出線並入第二條線 
int pop(){
	cur=top;
	weightsum=weightsum-cur->weight;
	fullsum=fullsum-cur->full;
	top=top->next;
	cur->next=top2;
	top2=cur;
}
//第二條彈回第一條線 
int popback(){
	weight=top2->weight;
	full=top2->full;
	if(isfull()==1){
		cur=top2;
		top2=top2->next;
		free(cur);
	}
	else if(isfull()==0){
		cur=top2;
		weightsum=weightsum+cur->weight;
		fullsum=fullsum+cur->full;
		cur=top2->next;
		top2->next=top;
		top=top2;
		top2=cur;
	}
}
//入線 
int push(){
	newadd=(struct stack*)malloc(sizeof(struct stack));
	newadd->weight=weight;
	newadd->full=full;
	weightsum=weightsum+newadd->weight;
	fullsum=fullsum+newadd->full;
	newadd->next=top;
	top=newadd;
}
int main(){
	while(scanf("%d%d",&weight,&full)!=EOF){
		if(isfull()==1){
			while(top!=NULL&&top->full>=full){
				pop();
			}
			if(top!=NULL){
				cur=top;
				top=top->next;
				weightsum=weightsum-cur->weight;
				fullsum=fullsum-cur->full;
				free(cur);
			}
			if(isfull()==0){
				push();
			}
			while(top2!=NULL){
				popback();
			}
		}
		else{
			push();
		}
	}
	printf("%d %d",weightsum,fullsum);
}