#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tad_lista_palavra.h"

typedef struct {
    tipo_palavra *vetor_palavras;
} tipo_vetor_palavras;

// Função que inicializa um vetor, dinamicamente alocado, para uma lista de palavras
void incializa_vetor_palavras(tipo_vetor_palavras *vetor, int tamanho);

// Função que copia os itens da lista encadeada de palavras para o vetor
void copia_lista_palavras(tipo_lista_palavras *lista_palavras, tipo_vetor_palavras *vetor, int tamanho);