#if 01
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char c;
    int freq;
    struct node* left;
    struct node* right;
}NODE;

NODE* PQUE[101];
int idx=0;

char code[30]={0,};
int codeIdx=-1;

NODE* createNODE(char _c, int _freq){
    NODE* _new=(NODE*)malloc(sizeof(NODE));
    _new->c=_c;
    _new->freq=_freq;
    _new->left=0;
    _new->right=0;
    return _new;
}

void enqueue(NODE* _new){
    if(idx==100)return;

    idx++;
    PQUE[idx]=_new;

    int cur=idx;
    int p=cur/2;
    while(cur>1){
        if(PQUE[cur]->freq < PQUE[p]->freq){
            NODE* temp=PQUE[cur];
            PQUE[cur]=PQUE[p];
            PQUE[p]=temp;
            cur=p;
            p=cur/2;
        }
        else break;
    }
}

NODE* dequeue(void){
    if(idx==0)return 0;
    NODE* res=PQUE[1];

    PQUE[1]=PQUE[idx];
    idx--;

    int cur=1;
    int child=cur*2;

    while(1){
        if(child>idx)break;
        if((child+1<=idx) && (PQUE[child]->freq > PQUE[child+1]->freq)){
            child++;
        }
        if(PQUE[cur]->freq>PQUE[child]->freq){
            NODE* temp=PQUE[cur];
            PQUE[cur]=PQUE[child];
            PQUE[child]=temp;
            cur=child;
            child=cur*2;
        }
        else break;
    }

    return res;
}

NODE* buildHuffmanTree(void){
    while(1){
        NODE* first=dequeue();
        NODE* second=dequeue();
        if(second==0)return first;

        NODE* combine=createNODE(0,(first->freq)+(second->freq));
        combine->left=first;
        combine->right=second;

        enqueue(combine);
    }
}

void genHuffmanCode(NODE* _node){
    if(_node==0)return;

    codeIdx++;
    code[codeIdx]='0';
    genHuffmanCode(_node->left);
    code[codeIdx]=0;
    codeIdx--;

    if(_node->c !=0)printf("%c --> %s\n",_node->c,code);

    codeIdx++;
    code[codeIdx]='1';
    genHuffmanCode(_node->right);
    code[codeIdx]=0;
    codeIdx--;
}

int main(){
    enqueue(createNODE('a',3));
    enqueue(createNODE('b',4));
    enqueue(createNODE('c',6));
    enqueue(createNODE('b',4));

    NODE* temp=buildHuffmanTree();

    genHuffmanCode(temp);
    return 0;
}
#endif