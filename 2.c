#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stk{
	double n;
	struct stk *next;
};
typedef struct stk* stack;
stack top = NULL;
void push(double in){
	stack newstk = (stack)malloc(sizeof(stack));
	newstk -> n = in;
	newstk -> next = top;
	top = newstk;
}
double pop(){
	stack ptr = top;
	if(ptr==NULL) return 0;
	double tmp;
	tmp = ptr -> n;
	top = top -> next;
	free(ptr);
	return tmp;
}
int main(){
	char a[1000];
	while(fgets(a,1000,stdin)!=NULL){
		int l = strlen(a);
		if(a[l-1]=='\n') a[l-1]='\0';
		char *pch;
  		pch = strtok (a," ");
  		while (pch != NULL){	
			if(!strcmp(pch,"+")||!strcmp(pch,"-")||!strcmp(pch,"*")||!strcmp(pch,"/")){
				double a2 = pop();
				double b = pop();
				if(!strcmp(pch,"+")) b+=a2;
				else if(!strcmp(pch,"-")) b-=a2;
				else if(!strcmp(pch,"*")) b*=a2;
				else b/=a2;
				push(b);
			}
			else{
				double num = atof(pch);
				push(num);
			}
    		pch = strtok (NULL, " ");
  		}
	}
		double ans = pop();
		printf("%.1f\n",ans);
	return 0;
}
