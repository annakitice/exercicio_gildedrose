#include <stdio.h>
#include "GildedRose.h"

int main()
{
    Item items[9];
    int last = 0;
    int day;
    int index;
    char buffer[128];

    init_item(items + last++, "+5 Dexterity Vest", 10, 20);
    init_item(items + last++, "Aged Brie", 2, 0);
    init_item(items + last++, "Elixir of the Mongoose", 5, 7);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", 0, 80);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", -1, 80);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 10, 49);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 5, 49);
    init_item(items + last++, "Conjured Mana Cake", 3, 6);

    puts("OMGHAI!");

    for (day = 0; day <= 30; day++)
    {
        printf("-------- day %d --------\n", day);
        printf("name, sellIn, quality\n");
        for(index = 0; index < last; index++) {
            printf("%s\n", print_item(buffer, items + index));
        }
        printf("\n");
        update_quality(items, last);
    }

    return 0;
}
