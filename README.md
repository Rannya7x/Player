# 🎵 Atividade Prática – Tocador de Música (com TAD e Reaproveitamento de Código)

## Objetivo
Implementar um **tocador de música** em C que manipula **playlists** e **músicas individuais**, utilizando **estruturas de dados genéricas** e aplicando os conceitos de **TAD (Tipo Abstrato de Dado)** e **encapsulamento**.

---

## O que você vai praticar
- Uso de **Lista Simplesmente Encadeada genérica** (`listase.c/.h`);
- Criação de **TADs especializados** (`musica`, `playlist`, `player`);
- Operações **posicionais** (inserir/remover início/final);
- Operações **por conteúdo** (buscar/remover por nome);
- Uso de **callbacks (funções de impressão, comparação e destruição)**;
- Organização modular do código em `.h/.c`.

---

## Estruturas fornecidas
- `listase.h / listase.c`: implementação de uma **lista simplesmente encadeada genérica** (com `void*` e callbacks).
- Você **não pode alterar** esse código.
- Deve **reaproveitá-lo** para implementar `playlist` e `player`.

---

## Estruturas a implementar

### 🎶 TAD Música (`musica.h/.c`)
Representa uma música com os atributos:
- nome (string até 60 chars),
- gênero (string até 30 chars),
- duração (int, em segundos),
- álbum (string até 60 chars),
- cantor(a) (string até 60 chars),
- ano (int).

Deve fornecer:
- Função construtora (`musica_criar`),
- Função destrutora (`musica_destruir`),
- Callback de impressão (`musica_imprimir`),
- Callback de comparação por nome (`musica_cmp_nome`).

---

### 📑 TAD Playlist (`playlist.h/.c`)
Encapsula uma **lista genérica** (`t_lse`) e fornece operações para gerenciar músicas:

- `playlist_criar()` e `playlist_destruir()`
- `playlist_inserir_final()`
- `playlist_remover_inicio()`
- `playlist_buscar_por_nome()`
- `playlist_remover_por_nome()`
- `playlist_tocar()` (percorrer e imprimir músicas na ordem)

> A playlist **não manipula nós diretamente** — delega tudo para o TAD lista.

---

### ▶️ TAD Player (`player.h/.c`)
Gerencia:
- A **biblioteca de músicas** (lista genérica),
- A **playlist atual** (instância de `t_playlist`).

Operações mínimas:
- Adicionar música na biblioteca,
- Buscar música na biblioteca por nome,
- Inserir músicas da biblioteca na playlist,
- Reproduzir playlist atual,
- Reproduzir música individual.

---

## Exemplo de uso (saída esperada)
```
=== Tocador de Musica ===
0. Sair
1. Adicionar musica na biblioteca
2. Buscar musica na biblioteca
3. Remover musica da biblioteca
4. Inserir musica da biblioteca na playlist
5. Remover musica da playlist
6. Tocar playlist
7. Tocar musica individual
8. Tocar ultimas K musicas
9. Exportar biblioteca

Opcao: 1
Nome: Yesterday
Genero: Rock
Duracao: 125
Album: Help!
Cantor: Beatles
Ano: 1965
Musica adicionada à biblioteca!

Opcao: 2
Nome para buscar: Yesterday
Musica encontrada: Yesterday (Beatles, 1965) [125s]

Opcao: 4
Nome: Yesterday
Musica inserida na playlist!

Opcao: 6
Tocando playlist...
Yesterday (Beatles, 1965) [125s]

Opcao: 7
Nome: Yesterday
Tocando: Yesterday (Beatles, 1965) [125s]

Opcao: 8
Quantidade: 1
Yesterday (Beatles, 1965) [125s]

Opcao: 9
Salvo em musicas.txt

Opcao: 4
Nome: Yesterday
Musica inserida na playlist!

Opcao: 5
Nome: Yesterday
Musica removida da playlist!

Opcao: 3
Nome: Yesterday
Musica removida da bibliteca!

Opcao: 0
Fechando player...
```

---

## Entrega
1. Código-fonte completo (`.h/.c`) + `Makefile`;
2. `README.md` explicando:
   - Como compilar e executar;
   - Política de memória adotada (quem destrói músicas? playlist ou biblioteca?);
   - Funcionalidades implementadas;
3. Exemplos de execução.

---

## Critérios de avaliação
- **40%** – Uso correto do TAD lista (`lse`) sem alterar sua implementação;
- **30%** – Funcionalidade correta das operações (playlist + player);
- **20%** – Organização modular e política de memória;
- **10%** – Funcionalidades extras (ex.: playlist ordenada, últimas K músicas, exportação).

---

Boa implementação! 🚀
