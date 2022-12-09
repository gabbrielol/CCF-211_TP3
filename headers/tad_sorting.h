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
} sorting_informations;

// Função de ordenação por Bubble Sort
void bubble_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra);

// Função de ordenação por Selection Sort
void selection_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra);

// Função de ordenação por Insertion Sort
void insertion_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra);

// Função de ordenação por Shell Sort
void shell_sort(sorting_informations *information, new_dicionario *new_dicionario, int length, int num_letra);

// Função de ordenação por Quick Sort
void sort(int left, int right, new_dicionario *new_dicionario, int num_letra);
void partition(int left, int right, int *i, int *j, new_dicionario *new_dicionario, int num_letra);
void quick_sort(sorting_informations *information, new_dicionario *new_dicionario, int lenght, int num_letra);

// Função de ordenação por Heap Sort
void make(new_dicionario *new_dicionario, int length);
void remake(int left, int right, new_dicionario *new_dicionario);
void heap_sort(sorting_informations *information, new_dicionario *new_dicionario, int length);

// Função de SET para todas as informações
void set_new_informations(sorting_informations *information);

// Exibir informações de ordenação
void show_sorting_informations(sorting_informations *information);