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
    printf("INPUT->%s\n",instr);
    
    int n;
    char token;
    
    printf("<OUTPUT>\n");
    for(n=0;n<i;n++){
        token=instr[n];
        if(isalpha(token)){
            pushdown(token);
        }else if(token=='='){
            printf("%c(%c,%c)\n",token,st[s-1],st[s-2]);
            s--;
            pushdown(w+'a');
            w++;
        }else{
            printf("%c(%c,%c,%c)\n",token,st[s-2],st[s-1],w+'a');
            s=s-2;
            pushdown(w+'a');
            w++;
        }
    }
    return 0;
}
