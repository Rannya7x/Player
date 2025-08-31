#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica t_musica;

struct musica;
t_musica* musica_criar(char* nome, char* genero, int duracao, char* album, char* cantor, int ano);
void musica_imprimir(void* p);
int musica_cmp_nome(void* carga, void* chave);
void musica_destruir(void* p);

#endif // MUSICA_H
