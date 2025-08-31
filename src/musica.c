#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../include/musica.h"

struct musica {
    char nome[60];
    char genero[30];
    int duracao;
    char album[60];
    char cantor[60];
    int ano;
};

t_musica* musica_criar(char* nome, char* genero, int duracao, char* album, char* cantor, int ano) {
    t_musica* msc = malloc(sizeof(t_musica));
    assert(msc != NULL);
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
    assert(msc != NULL);
    printf( "Nome: %s\n", msc->nome);
}

int musica_cmp_nome(void* carga, void* chave) {
    t_musica* msc = (t_musica*)carga;
    char* nome_chave = (char*)chave;
    assert(msc != NULL);
    assert(chave != NULL);
    return strcmp(msc->nome, nome_chave);
}

void musica_destruir(void* p) {
    t_musica* msc = (t_musica*)p;
    assert(msc != NULL);
    free(msc);
    return NULL;
}
