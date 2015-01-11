#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *instr;
char *outstr;
char *prstr;
char *st;
int i,o,s,w;

int init(){
    instr=malloc(sizeof(char)*100);
    outstr=malloc(sizeof(char)*100);
    prstr=malloc(sizeof(char)*100);
    st=malloc(sizeof(char)*100);
    i=0;
    o=0;
    s=0;
    w=0;
}

int input(){
    scanf("%s",instr);
    i=strlen(instr);
    return 0;
}

int output(int a, char *c){
    int i;
    for(i=0;i<a;i++) printf("%c",c[i]);
    printf("\n");
    return 0;
}

int pushdown(char c){
    st[s]=c;
    s++;
    return 0;
}


int main(){
    init();
    printf("init finish\n");
    input();
    output(i,instr);
    int n;
    char token;

    for(n=0;n<i;n++){
        token=instr[n];
        if(isalpha(token)){
            pushdown(token);
        }else if(token=='='){
            printf("%c(%c,%d)\n",token,st[s-1],w);
            s--;
            pushdown(w+48);
            w++;
        }else{
            printf("%c(%c,%c,%d)\n",token,st[s-2],st[s-1],w);
            s=s-2;
            pushdown(w+48);
            w++;
        }
    }
    return 0;
}
