#ifndef ITEM_TYPES_H
#define ITEM_TYPES_H

#include "GildedRose.h"  // garante que Item está definido

typedef void (*update_func)(Item *item);

void update_normal_item(Item *item);
void update_aged_brie(Item *item);
void update_backstage(Item *item);
void update_sulfuras(Item *item);
void update_conjured(Item *item);

update_func get_update_strategy(Item *item);

#endif
