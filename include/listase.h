#ifndef LISTA_SE_H
#define LISTA_SE_H

typedef int (*cmp_func)(void* a, void* b);
typedef void (*destruir_func)(void* p); 
typedef void (*print_func)(void* p); 

typedef struct lse t_lse;

t_lse* lse_criar(cmp_func* comparar, destruir_func* destruir, print_func* imprimir);
void lse_destruir(t_lse* l, destruir_func destruir);
void lse_inserir_inicio(t_lse* l, void* carga);
void lse_inserir_final(t_lse* l, void* carga);
void lse_inserir_ordenado(t_lse* l, void* carga, cmp_func cmp);
void* lse_buscar(t_lse* l, void* chave, cmp_func cmp);
void* lse_remover_inicio(t_lse* l);
void* lse_remover_por_nome(t_lse* l, void* chave, cmp_func cmp);
void lse_imprimir(t_lse* l, print_func print);
int lse_tamanho(t_lse* l);

#endif // LISTA_SE_H
