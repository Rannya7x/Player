#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist t_playlist;

t_playlist* playlist_criar();
void playlist_destruir(t_playlist* pl);
void playlist_inserir_final(t_playlist* pl, void* m);
void* playlist_remover_inicio(t_playlist* pl);
void* playlist_buscar_por_nome(t_playlist* pl, const char* nome);
void* playlist_remover_por_nome(t_playlist* pl, const char* nome);
void playlist_tocar(t_playlist* pl);
int playlist_tamanho(t_playlist* pl);

#endif // PLAYLIST_H
