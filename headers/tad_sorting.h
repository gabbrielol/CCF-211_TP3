#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/tad_alt_dicio.h"

// Estrutura que armazena as informações de ordenação da lista e método atual
typedef struct {
    int sort_com;
    int sort_mov;
    double sort_time;
    int t_sort_com;
    int t_sort_mov;
    double t_sort_time;
} sorting_informations;

// Função de ordenação por Bubble Sort
void bubble_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length);

// Função de ordenação por Selection Sort
void selection_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length);

// Função de ordenação por Insertion Sort
void insertion_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length);

// Função de ordenação por Shell Sort
void shell_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length);

// Função de ordenação por Quick Sort
void quick_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int length);
void sort(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right);
void partition(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right, int *i, int *j);

// Função de ordenação por Heap Sort
void heap_sort(sorting_informations *information, new_dicionario *new_dicionario, int num_letra, int *length);
void make(sorting_informations *information, tipo_vetor_palavras *vetor, int *length);
void remake(sorting_informations *information, tipo_vetor_palavras *vetor, int left, int right);

// Função de SET para todas as informações
void set_new_informations(sorting_informations *information);

// Função de SET para uma nova iteração em um mesmo método
void set_next_informations(sorting_informations *information);

// Exibir informações de ordenação
void show_sorting_informations(sorting_informations *information);