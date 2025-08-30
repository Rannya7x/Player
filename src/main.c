#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "musica.h"

static void ler_linha(char* buf, size_t n) {
    if (fgets(buf, (int)n, stdin)) {
        size_t len = strlen(buf);
        if (len && buf[len - 1] == '\n')
            buf[len - 1] = 0;
    }
}

int main() {
    t_player* pl = player_criar();
    if (!pl) {
        puts("Falha ao criar player.");
        return 1;
    }

    int opt = -1;
    char nome[64], genero[32], album[64], cantor[64];
    int duracao, ano;
    t_musica* musica;

    puts("=== Tocador de Musica ===");
    puts("0. Sair");
    puts("1. Adicionar musica na biblioteca");
    puts("2. Buscar musica na biblioteca");
    puts("3. Remover musica da biblioteca");
    puts("4. Inserir musica da biblioteca na playlist");
    puts("5. Remover musica da playlist");
    puts("6. Tocar playlist");
    puts("7. Tocar musica individual");
    puts("8. Tocar ultimas K musicas");
    puts("9. Exportar biblioteca");

    while (opt != 0) {
        printf("\nOpcao: ");
        if (scanf("%d%*c", &opt) != 1)
            break;

        switch (opt) {
        case 0:
            puts("Fechando player...");
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            puts("Opcao invalida.");
        }
    }

    player_destruir(pl);
    return 0;
}
