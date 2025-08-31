#include <stdlib.h>
#include "../include/listase.h"

typedef struct no {
    void* carga;
    struct no* prox;
} t_no;

struct lse {
    t_no* inicio;
    t_no* final;
    int tamanho;
    cmp_func comparar;
    destruir_func destruir;
    print_func imprimir;
};

t_no* no_criar(void* carga, t_no* prox) {
    t_no* no = (t_no*) malloc(sizeof(t_no));
    if (!no) return NULL;
    no->carga = carga;
    no->prox = prox;
    return no;
}

t_lse* lse_criar(cmp_func comparar, destruir_func destruir, print_func imprimir) {
    t_lse* l = (t_lse*) malloc(sizeof(t_lse));
    if (!l) return NULL;
    l->inicio = NULL;
    l->final = NULL;
    l->tamanho = 0;
    l->comparar = comparar;
    l->destruir = destruir;
    l->imprimir = imprimir;
    return l;
}

void lse_destruir(t_lse* l, destruir_func destruir) {
    if (!l) return;

    t_no* atual = l->inicio;
    while (atual) {
        t_no* proximo = atual->prox;
        if (destruir) destruir(atual->carga);
        free(atual);
        atual = proximo;
    }
    free(l);
}

void lse_inserir_inicio(t_lse* l, void* carga) {
    if (!l || !carga) return;

    t_no* no = no_criar(carga, l->inicio);
    if (!no) return;

    l->inicio = no;
    if (!l->final) {
        l->final = no;
    }
    l->tamanho++;
}

void lse_inserir_final(t_lse* l, void* carga) {
    if (!l || !carga) return;

    t_no* no = no_criar(carga, NULL);
    if (!no) return;

    if (l->final) {
        l->final->prox = no;
    } else {
        l->inicio = no;
    }
    l->final = no;
    l->tamanho++;
}

void lse_inserir_ordenado(t_lse* l, void* carga, cmp_func cmp) {
    if (!l || !carga || !cmp) return;

    t_no* no = no_criar(carga, NULL);
    if (!no) return;

    t_no* atual = l->inicio;
    t_no* anterior = NULL;

    while (atual && cmp(carga, atual->carga) > 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior) {
        anterior->prox = no;
    } else {
        l->inicio = no;
    }

    if (atual) {
        no->prox = atual;
    } else {
        l->final = no;
    }

    l->tamanho++;
}

void* lse_buscar(t_lse* l, void* chave, cmp_func cmp) {
    if (!l || !chave || !cmp) return NULL;

    t_no* atual = l->inicio;
    while (atual && cmp(atual->carga, chave) != 0) {
        atual = atual->prox;
    }
    return atual ? atual->carga : NULL;
}

void* lse_remover_inicio(t_lse* l) {
    if (!l || !l->inicio) return NULL;

    t_no* removido = l->inicio;
    void* carga = removido->carga;
    l->inicio = removido->prox;
    if (!l->inicio) {
        l->final = NULL;
    }
    l->tamanho--;
    free(removido);
    return carga;
}

void* lse_remover_por_nome(t_lse* l, void* chave, cmp_func cmp) {
    if (!l || !chave || !cmp) return NULL;

    t_no* atual = l->inicio;
    t_no* anterior = NULL;

    while (atual && cmp(atual->carga, chave) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual) return NULL;

    if (anterior) {
        anterior->prox = atual->prox;
    } else {
        l->inicio = atual->prox;
    }

    if (!atual->prox) {
        l->final = anterior;
    }

    l->tamanho--;
    void* carga = atual->carga;
    free(atual);
    return carga;
}

void lse_imprimir(t_lse* l, print_func print) {
    if (!l || !print) return;

    t_no* atual = l->inicio;
    while (atual) {
        print(atual->carga);
        atual = atual->prox;
    }
}

int lse_tamanho(t_lse* l) {
    if (!l) return 0;
    return l->tamanho;
}
