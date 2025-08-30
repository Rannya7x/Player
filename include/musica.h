#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica t_musica;

struct musica;
t_musica* musica_criar();
void musica_imprimir(void* p);
int musica_cmp_nome(void* carga, void* chave);
void musica_destruir(void* p);

#endif // MUSICA_H
