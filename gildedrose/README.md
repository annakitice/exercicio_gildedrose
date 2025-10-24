# Gilded Rose – Inventário Refatorado em C

## Descrição

Sistema de gerenciamento de inventário que atualiza automaticamente a qualidade e o prazo de validade de itens de uma loja fictícia, seguindo regras específicas de cada tipo de item.

## Funcionalidades

- **Inicialização de itens** com nome, prazo (`sellIn`) e qualidade (`quality`).
- **Atualização diária da qualidade de todos os itens**:
  - **Itens Normais**: perdem qualidade com o tempo.
  - **Aged Brie**: qualidade aumenta com o tempo.
  - **Backstage Passes**: qualidade aumenta conforme o evento; cai para 0 após o evento.
  - **Sulfuras**: item lendário, não se altera.
  - **Conjured**: perde qualidade duas vezes mais rápido.
- **Impressão formatada de cada item** (`nome, sellIn, quality`).
- **Arquitetura modular**: cada tipo de item possui sua própria função de atualização, facilitando manutenção e expansão.

## Estrutura do Projeto

- `GildedRose.h` / `GildedRose.c` – funções gerais do sistema.  
- `ItemTypes.h` / `ItemTypes.c` – lógica de atualização específica de cada tipo de item.  
- `GildedRoseTextTests.c` – testes que simulam 30 dias de atualização.  
