#ifndef ROSE_INCLUDED
#define ROSE_INCLUDED

#include "ItemTypes.h"

typedef struct
{
    char *name;
    int sellIn;
    int quality;
} Item;

// Inicializa um item
Item* init_item(Item* item, const char *name, int sellIn, int quality);

// Atualiza todos os itens do estoque chamando a estratégia correta
void update_quality(Item items[], int size);

// Imprime um item em formato "nome, sellIn, quality"
char* print_item(char* buffer, Item* item);

#endif
