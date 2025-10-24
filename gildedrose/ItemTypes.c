#include <string.h>
#include "GildedRose.h"
#include "ItemTypes.h"

// Constantes com os nomes dos itens
static const char *ITEM_AGED_BRIE   = "Aged Brie";
static const char *ITEM_SULFURAS    = "Sulfuras, Hand of Ragnaros";
static const char *ITEM_BACKSTAGE   = "Backstage passes to a TAFKAL80ETC concert";

// Helpers
static void increase_quality(Item *item) {
    if (item->quality < 50) item->quality++;
}

static void decrease_quality(Item *item) {
    if (item->quality > 0) item->quality--;
}

static void decrease_sellin(Item *item) {
    item->sellIn--;
}

static void reset_quality(Item *item) {
    item->quality = 0;
}

// Estratégia: item normal
void update_normal_item(Item *item) {
    decrease_sellin(item);
    decrease_quality(item);
    if (item->sellIn < 0) decrease_quality(item);
}

// Estratégia: aged brie
void update_aged_brie(Item *item) {
    decrease_sellin(item);
    increase_quality(item);
    if (item->sellIn < 0) increase_quality(item);
}

// Estratégia: backstage pass
void update_backstage(Item *item) {
    decrease_sellin(item);

    if (item->sellIn < 0) {
        reset_quality(item);
        return;
    }

    increase_quality(item);
    if (item->sellIn < 10) increase_quality(item);
    if (item->sellIn < 5) increase_quality(item);
}

// Estratégia: sulfuras (não altera nada)
void update_sulfuras(Item *item) { }

// Estratégia: conjured
void update_conjured(Item *item) {
    decrease_sellin(item);
    decrease_quality(item);
    decrease_quality(item);
    if (item->sellIn < 0) {
        decrease_quality(item);
        decrease_quality(item);
    }
}

// Seleciona a estratégia certa baseado no tipo do item
update_func get_update_strategy(Item *item) {
    if (strcmp(item->name, ITEM_SULFURAS) == 0) return update_sulfuras;
    if (strcmp(item->name, ITEM_AGED_BRIE) == 0) return update_aged_brie;
    if (strcmp(item->name, ITEM_BACKSTAGE) == 0) return update_backstage;
    if (strstr(item->name, "Conjured") != NULL) return update_conjured;
    return update_normal_item;
}
