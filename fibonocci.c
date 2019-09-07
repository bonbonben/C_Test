#include <stdio.h>
#include <stdlib.h>

int n;
//node資料結構
struct node{
    int n;
    int value;
    struct node* prev;  //上一個node
} node={.n=1, .value=1, .prev=NULL};
struct node *node_pointer=&node;    //堆疊指標先指向第一個位置


void push(int n, int value){
    //配置一塊記憶體空間給node
    struct node *new_node=malloc(sizeof(node));
    //設定他的值
    new_node->value=value;
    new_node->n=n;
    //新node要指向舊node
    new_node->prev=node_pointer;
    //pointer更新到最頂端
    node_pointer=new_node;

    //因為費波納契再也不會用到兩個之前的node 可以把偷偷她釋放掉
    free(node_pointer->prev->prev);
}

int fibonocci(void){
    //PUSH f[n-1]+f[n]
    push(node_pointer->n+1,node_pointer->value+node_pointer->prev->value);
    //如果算到解答了
    if(node_pointer->n==n) return node_pointer->value;
    //繼續算
    return fibonocci();
}

int main(int argc, char *argv[]){
    //前兩個比較不規則 所以要寫
    push(2, 1);

    n=20;
    printf("%d", fibonocci());

    return EXIT_SUCCESS;
}
