#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int pai(int n){
    return (n-1)/2;
}

int filho_esq(int n){
    return (n*2)+1;
}

int filho_dir(int n){
    return (n*2)+2;
}

void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heap(int v[], int n, int size){

    int esq = filho_esq(n);
    int dir = filho_dir(n);
    int maior = n;

    if(esq < size && v[esq] > v[maior]){
        maior = esq;
    }

    if(dir < size && v[dir] > v[maior]){
        maior = dir;
    }

    if(maior != n){
        troca(&v[maior], &v[n]);
        heap(v, maior, size);
    }

}

void constroi_heap(int v[], int size){
    for(int n=size-2; n>=0; n--){
        heap(v, n, size);
    }
}

//TESTES
void teste_pai(){
    int n, r;

    n = 3;
    r = pai(n);
    assert(r == 1); 

    n = 4;
    r = pai(n);
    assert(r == 1);
}

void teste_filho_esq(){
    int n, r;

    n = 1;
    r = filho_esq(n);
    assert(r == 3);

    n = 2;
    r = filho_esq(n);
    assert(r == 5);
}

void teste_filho_dir(){
    int n, r;

    n = 1;
    r = filho_dir(n);
    assert(r == 4);

    r = 2;
    r = filho_dir(n);
    assert(r = 6);
}

void teste_troca(){
    int r;
    int a=0, b=1;
    int v[2] = {0, 1};

    troca(&v[a], &v[b]);
    r = v[a];
    assert(r == 1);
}

void teste_heap(){

    int v[3] = {10, 15, 9};
    int r[3] = {15, 10, 9};

    heap(v, 0, 3);

    for(int i=0; i<3; i++){
        assert(v[i] == r[i]);
    }

}

void teste_constroi_heap(){

    int v[7] = {10, 15, 9, 17, 12, 8, 25};
    int r[7] = {25, 17, 10, 15, 12, 8, 9};

    constroi_heap(v, 7);

    for(int i=0; i<7; i++){
        assert(v[i] == r[i]);
    }
}

int main(void){
    teste_pai();
    teste_filho_esq();
    teste_filho_dir();
    teste_troca();
    teste_heap();
    teste_constroi_heap();
    return EXIT_SUCCESS;
}

