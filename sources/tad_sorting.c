#include "../headers/tad_sorting.h"

void bubble_sort(new_dicionario *new_dicionario, int length, int num_letra) {
    int i, j;
    char *aux;

    int com; com = 0;
    int mov; mov = 0;
    clock_t start, end;
    time_t t_start, t_end;
    double cpu_time_used;
    double time_used;

    start = clock();
    t_start = time(NULL);

    for (i = 0; i < length - 1; i++) {
        for (j = 1; j < length - i; j++) {
            com++;
            if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1]) < 0) {
                strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]);
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1]);
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - 1], aux);
                mov++;
            }
        }
    }

    end = clock();
    t_end = time(NULL);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_used = difftime(t_end, t_start);

    printf("\n");
    printf("Tempo (método clock_t): %lf\n", cpu_time_used);
    printf("Tempo (método time_t): %lf\n", time_used);
    printf("Comparações: %d\n", com);
    printf("Movimentações: %d\n", mov);
    printf("\n");
    printf("-----------------------------------------------------------------\n");
}

void selection_sort(new_dicionario *new_dicionario, int length, int num_letra) {
    int i, j;
    int min;
    char *aux;

    int com; com = 0;
    int mov; mov = 0;
    clock_t start, end;
    time_t t_start, t_end;
    double cpu_time_used;
    double time_used;

    start = clock();
    t_start = time(NULL);

    for (i = 0; i < length - 1; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            com++;
            if (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min]) < 0) {
                min = j;
            }
        }
        strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min]);
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[min],
        new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i], aux);
        mov++;
    }

    end = clock();
    t_end = time(NULL);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_used = difftime(t_end, t_start);

    printf("\n");
    printf("Tempo (método clock_t): %lf\n", cpu_time_used);
    printf("Tempo (método time_t): %lf\n", time_used);
    printf("Comparações: %d\n", com);
    printf("Movimentações: %d\n", mov);
    printf("\n");
    printf("-----------------------------------------------------------------\n");
}

void insertion_sort(new_dicionario *new_dicionario, int length, int num_letra) {
    int i, j;
    char *aux;

    int com; com = 0;
    int mov; mov = 0;
    clock_t start, end;
    time_t t_start, t_end;
    double cpu_time_used;
    double time_used;

    start = clock();
    t_start = time(NULL);

    for (i = 0; i < length; i++) {
        strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(aux, 
        new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]) < 0)) {
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1],
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j]);
            j--;
        }
        strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j + 1], aux);
    }

    end = clock();
    t_end = time(NULL);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_used = difftime(t_end, t_start);

    printf("\n");
    printf("Tempo (método clock_t): %lf\n", cpu_time_used);
    printf("Tempo (método time_t): %lf\n", time_used);
    printf("Comparações: %d\n", com);
    printf("Movimentações: %d\n", mov);
    printf("\n");
    printf("-----------------------------------------------------------------\n");
}

void shell_sort(new_dicionario *new_dicionario, int length, int num_letra) {
    int i, j;
    int h; h = 1;
    char *aux;

    int com; com = 0;
    int mov; mov = 0;
    clock_t start, end;
    time_t t_start, t_end;
    double cpu_time_used;
    double time_used;

    start = clock();
    t_start = time(NULL);

    do {
        h = h * 3 + 1;
    } while (h < length);

    do {
        h = h/3;
        for (i = h; i < length; i++) {
            strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[i]);
            j = i;
            while (strcmp(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h], aux) > 0) {
                strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j],
                new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j - h]);
                j -= h;
                if (j < h) {
                    break;
                }
            }
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[j], aux);
        }
    } while (h != 1);
    
    end = clock();
    t_end = time(NULL);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_used = difftime(t_end, t_start);

    printf("\n");
    printf("Tempo (método clock_t): %lf\n", cpu_time_used);
    printf("Tempo (método time_t): %lf\n", time_used);
    printf("Comparações: %d\n", com);
    printf("Movimentações: %d\n", mov);
    printf("\n");
    printf("-----------------------------------------------------------------\n");
}

void sort(int left, int right, new_dicionario *new_dicionario, int num_letra) {
   int i, j;
   partition(left, right, &i, &j, new_dicionario, num_letra);
   if (left < i) {
    sort(left, j, new_dicionario, num_letra);
   }
   if (i < right) {
    sort(i, right, new_dicionario, num_letra);
   }
}

void partition(int left, int right, int *i, int *j, new_dicionario *new_dicionario, int num_letra) {
    char *aux;
    char *pivot;

    strcpy(pivot, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[(*i + *j)/2]);

    *i = left;
    *j = right;

    do
    {
        while (strcmp(pivot, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[(*i + *j)/2]) > 0) {
            (*i)++;
        }
        while (strcmp(pivot, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[(*i + *j)/2]) < 0)
        {
            (*j)--;
        }
        if (*i <= *j) {
            strcpy(aux, new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*i]);
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*i], 
            new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*j]);
            strcpy(new_dicionario -> alfabeto[num_letra].lista_palavras_vetor.vetor_palavras[*j], aux);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void quick_sort(new_dicionario *new_dicionario, int lenght, int num_letra) {
    sort(0, lenght - 1, new_dicionario, num_letra);
}