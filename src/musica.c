#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/musica.h"

struct musica {
    char nome[60];
    char genero[30];
    int duracao;
    char album[60];
    char cantor[60];
    int ano;
};

t_musica* musica_criar(const char* nome, const char* genero, int duracao, const char* album, const char* cantor, int ano) {
    t_musica* msc = malloc(sizeof(t_musica));
    if(msc == NULL) {
        return NULL;
    }
    if (nome == NULL || genero == NULL || album == NULL || cantor == NULL || duracao <= 0 || ano <= 0) {
        free(msc);
        return NULL;
    }
    strcpy(msc->nome, nome);
    strcpy(msc->genero, genero);
    msc->duracao = duracao;
    strcpy(msc->album, album);
    strcpy(msc->cantor, cantor);
    msc->ano = ano;
    return msc;
}

void musica_imprimir(void* p) {
    t_musica* msc = (t_musica*)p;
    if(msc == NULL) {
        return;
    }
    printf( "%s (%s, %d) [%ds]\n", msc->nome, msc->cantor, msc->ano, msc->duracao);
}

int musica_cmp_nome(void* carga, void* chave) {
    t_musica* msc = (t_musica*)carga;
    char* nome_chave = (char*)chave;
    if(msc == NULL || nome_chave == NULL) {
        return -1; 
    }
    return strcmp(msc->nome, nome_chave);
}

void musica_destruir(void* p) {
    t_musica* msc = (t_musica*)p;
    if(msc == NULL) {
        return;
    }
    free(msc);
}
