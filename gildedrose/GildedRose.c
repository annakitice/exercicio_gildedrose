#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "GildedRose.h"
#include "ItemTypes.h"

// Inicializa o item
Item* init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);
    return item;
}

// Imprime um item em buffer
char* print_item(char* buffer, Item* item)
{
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
    return buffer;
}

// Atualiza todos os itens do estoque usando Strategy Pattern
void update_quality(Item items[], int size)
{
    for (int i = 0; i < size; i++) {
        update_func func = get_update_strategy(&items[i]);
        func(&items[i]);
    }
}
