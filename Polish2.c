#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *instr;
char *outstr;

int init(){
    instr=calloc(100,sizeof(char));
    outstr=calloc(100,sizeof(char));
}

int input(){
    scanf("%s",instr);
    return 0;
}

int addstr(char *x, char *a){
    int i,j,k;
    for(i=0;x[i]!=0;i++);
    for(j=0;a[j]!=0;j++);
    for(k=i;k<i+j;k++) x[k]=a[k-i];
    x[k]=0;
    return 0;
}

int shiftL(char *array){
    int i=0;
    while(array[i+1]!=0){i++; array[i-1]=array[i];}
    array[i]=0;
    return 0;
}


int lv(char c){
    if(c=='*'||c=='/') return 4;
    if(c=='+'||c=='-') return 3;
    if(c=='='||c=='(') return 2;
    if(c==')'||c=='$') return 1;
    return 0;
}

char *polish(char *str){
    int i=0;
    int len=strlen(str);
    char en;
    char *out=calloc(len,sizeof(char));
    char *buf=calloc(len,sizeof(char));
    char *a=calloc(len,sizeof(char));
    char *b=calloc(len,sizeof(char));
    buf[0]=str[0]; shiftL(str);
    printf("buf:%c\n",buf[0]);
    if(isalpha(str[0])){
        a[0]=str[0]; shiftL(str);
    }else{
        en=str[0];
        if(lv(buf[0])>lv(en)&&!isalpha(en)) addstr(a,")");
        addstr(a,polish(str));
        if(lv(buf[0])>lv(en)&&!isalpha(en)) addstr(a,"(");
    }

    printf("a:%s\n",a);
    if(isalpha(str[0])){
        b[0]=str[0]; shiftL(str);
    }else{
        en=str[0];
        if(lv(buf[0])>lv(en)&&!isalpha(en)) addstr(b,")");
        addstr(b,polish(str));
        if(lv(buf[0])>lv(en)&&!isalpha(en)) addstr(b,"(");
    }
    printf("b:%s\n",b);
    addstr(out,a);
    addstr(out,buf);
    addstr(out,b);
    printf("out:%s\n",out);
    return out;
}

int reverse(char *str){
    int i,len=strlen(str);
    char *buf=calloc(len,sizeof(char));
    for(i=0;i<len;i++) buf[i]=str[len-i-1];
    for(i=0;i<len;i++) str[i]=buf[i];
    return 0;
}

int main(){
    init();
    printf("init finish\n");
    input();
    reverse(instr);
    printf("INPUT->%s\n",instr);
    addstr(outstr,polish(instr));

    reverse(outstr);
    printf("OUTPUT->%s\n",outstr);
    return 0;
}
