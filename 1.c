#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *cmd, **data;
    int i,cnt, length;
        scanf("%d",&cnt);
        cmd = (char *)malloc(sizeof(char *) * 8); 
        data = (char **)malloc(sizeof(void *) * cnt);
        for(i = 0; i < cnt; i++){
            *cmd = '\0';
            length = 0;
                          //printf("i = %d\n",i);
            scanf("%s",cmd);
              //printf("cmd = %s\n",cmd);
            scanf("%d",&length);
             // printf("len = %d\n",length);
            length++;
            if(strcmp(cmd, "INSERT")==0){
                *(data+i) = (char *)malloc(sizeof(char)*length);
                scanf("%s",*(data+i));
            }
        }
        *cmd = '\0';
        scanf("%s",cmd);
        if(strcmp(cmd, "OUTPUT") == 0){ 
            for(i = cnt-1; i >= 0; i--){
                printf("%s\n",*(data+i));
            }
        }
        for(i = 0; i < cnt; i++){
            free(*(data+i));
        }
        free(data);
        free(cmd);

        return 0;
}
