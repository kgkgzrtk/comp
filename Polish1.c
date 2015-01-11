#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *instr;
char *outstr;
char *st;
int i,o,s;

int init(){
    instr=calloc(100,sizeof(char));
    outstr=calloc(100,sizeof(char));
    st=calloc(100,sizeof(char));
    i=0;
    o=0;
    s=0;
}

int input(){
    scanf("%s",instr);
    i=strlen(instr);
    return 0;
}

int pushdown(char c){
    st[s]=c;
    s++;
    return 0;
}

int popup(){
    outstr[o]=st[s-1];
    st[s-1]=0;
    o++;
    s--;
    return 0;
}

int del(){
    st[s-1]=0;
    s--;
    return 0;
}

int lv(char c){
    if(c=='*'||c=='/') return 4;
    if(c=='+'||c=='-') return 3;
    if(c=='='||c=='(') return 2;
    if(c==')'||c=='$') return 1;
    return 0;
}

int main(){
    init();
    printf("init finish\n");
    input();
    printf("INPUT->%s\n",instr);
    int n;
    char token;

    for(n=0;n<i;n++){
        token=instr[n];
        printf("[%c]\n",token);
        if(isalpha(token)){
            outstr[o]=token;
            o++;
        }else if(token=='('){
            pushdown(token);
        }else if(token==')'){
            while(st[s-1]!='(') popup();
            del();
        }else{
            if(lv(token)>lv(st[s-1])){
                pushdown(token);
            }
            else{
                while(lv(token)<=lv(st[s-1])) popup();
                pushdown(token);
            }
        }
        printf("stock:%s outstr:%s\n",st,outstr);
    }

    while(s!=0) popup();
    printf("OUTPUT->%s\n",outstr);
    return 0;
}
