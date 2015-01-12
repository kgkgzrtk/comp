#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *instr;
char *outstr;
char *prstr;
char *st;
char *en[4]={"AD","SB","ML","DV"};
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
    fflush(stdin);
    while(instr[i-1]!='.'){
        if((instr[i]=fgetc(stdin))!='\n') i++;
    }
    i--;
    instr[i]=0;
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
int popup(){
    outstr[o]=st[s];
    o++;
    s--;
    return 0;
}

int id(char c){
    if(c=='+') return 0;
    if(c=='-') return 1;
    if(c=='*') return 2;
    if(c=='/') return 3;
    return -1;
}

int main(){
    init();
    printf("init finish\n");
    input();
    printf("INPUT->%s\n",instr);
    int n,flag=0;
    char pre_w1,pre_w2,pre_w3;
    char w1,w2,w3,ew;
    char token,pre_token;
    
    printf("<OUTPUT>\n");
    for(n=0;n<i;n++){
        token=instr[n];
        pre_token=instr[n-1];
        w1=instr[n+2];
        w2=instr[n+4];
        w3=instr[n+6];
        if(isalnum(token)){
            pushdown(token);
        }else if(token=='='){
            printf("LD $%c\n",w1);
            ew=w2;
            s=s-2;
        }else if(((id(token)<3&&id(pre_token)<3)||(id(token)>2&&id(pre_token)>2))&&w1==ew){
            printf("%s $%c\n",en[id(token)],w2);
            ew++;
        }else if(id(token)>=0){
            if(flag) printf("ST $%c\n",ew);
            printf("LD $%c\n",w1);
            printf("%s $%c\n",en[id(token)],w2);
            ew=w3;
            s=s-3;
            pre_w1=w1;
            pre_w2=w2;
            pre_w3=w3;
            flag=1;
        }
    }
    printf("ST $%c\n",ew);
    return 0;
}
