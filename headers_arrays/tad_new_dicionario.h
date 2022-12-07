#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tad_dicionario.h"

// Declarando um tipo para a lista de palavras
typedef struct {
    tipo_palavra *vetor_palavras;
} tipo_vetor_palavras;

// Declarando um tipo para o dicionário
typedef struct {    
    char identificador_upper;
    char identificador_lower;
    tipo_vetor_palavras lista_palavras_vetor;
} tipo_new_dicionario;

// Declarando o dicionário
typedef struct {
    tipo_new_dicionario alfabeto[26];
} new_dicionario;


// Função que inicializa um vetor, dinamicamente alocado, para uma lista de palavras
void incializa_vetor_palavras(tipo_vetor_palavras *vetor, int tamanho);