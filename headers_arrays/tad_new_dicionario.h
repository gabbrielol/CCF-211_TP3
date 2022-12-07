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

// Função que copia os itens da lista encadeada de palavras para o vetor
void copia_lista_palavras(tipo_lista_palavras *lista_palavras, tipo_vetor_palavras *vetor);

// Função para inicializar o novo dicionário vazio
void inicializa_new_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario);

// Função para construir o novo dicionário a partir do um já existente
void constroi_new_dicionario(new_dicionario *new_dicionario, tipo_dicionario *dicionario);

// Função para imprimir determinada letra do novo dicionário
void imprime_new_dicionario_letra();

// Fução para imprimir o novo dicionário completo com a a lista de palavras de cada letra do alfabeto
void imprime_new_dicionario_completo();