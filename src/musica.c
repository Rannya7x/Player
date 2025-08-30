#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica {
    char nome[60];
    char genero[30];
    int duracao;
    char album[60];
    char cantor[60];
    int ano;
};

t_musica* musica_criar(void* nome, void* genero, int duracao, void* album, void* cantor, int ano) {
    t_musica* msc = malloc(sizeof(t_musica));
    strcpy(msc->nome, nome);
    strcpy(msc->genero, genero);
    msc->duracao = duracao;
    strcpy(msc->album, album);
    strcpy(msc->cantor, cantor);
    msc->ano = ano;
    return msc;
}

void musica_imprimir(void* p) {
    t_musica msc = *(t_musica*)p;
    printf("Nome: %s\n", msc.nome);
}

int musica_cmp_nome(void* carga, void* chave) {
    // Implemente o seu código aqui
}

void musica_destruir(void* p) {
    // Implemente o seu código aqui
}
