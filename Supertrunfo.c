#include <stdio.h>
#include <string.h>

// infos
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[100];
    unsigned long int populacao;
    float pib; // em bilhões
    float area; // em km²
    int pontosTuristicos;

    // Propriedades
    float densidadePopulacional;
    float pibPerCapita;
} Carta;


// Função para calcular as propriedades
void calcularPropriedades(Carta *c) {
    c->densidadePopulacional = (float)c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000.0) / (float)c->populacao;
}


// Função para cadastrar a carta
void cadastrarCarta(Carta *c) {

    printf("\n=== Cadastro da Carta ===\n");

    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Código: ");
    scanf("%s", c->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c->nomeCidade);

    printf("População: ");
    scanf("%lu", &c->populacao);

    printf("PIB (em bilhões): ");
    scanf("%f", &c->pib);

    printf("Área (km²): ");
    scanf("%f", &c->area);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    calcularPropriedades(c);
}


// Função para exibir a carta
void exibirCarta(Carta c) {

    printf("\n===== Carta Cadastrada =====\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %lu habitantes\n", c.populacao);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Área: %.2f km²\n", c.area);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
}


// Função para comparar (Super Trunfo)
void compararCartas(Carta c1, Carta c2) {

    printf("\n===== Comparação de Cartas =====\n");

    // Operadores relacionais
    if (c1.populacao > c2.populacao)
        printf("Carta 1 vence em População!\n");
    else if (c1.populacao < c2.populacao)
        printf("Carta 2 vence em População!\n");
    else
        printf("Empate em População!\n");

    if (c1.pibPerCapita > c2.pibPerCapita)
        printf("Carta 1 vence em PIB per capita!\n");
    else if (c1.pibPerCapita < c2.pibPerCapita)
        printf("Carta 2 vence em PIB per capita!\n");
    else
        printf("Empate em PIB por capita!\n");

    if (c1.densidadePopulacional < c2.densidadePopulacional)
        printf("Carta 1 vence em Densidade (menor é melhor)!\n");
    else if (c1.densidadePopulacional > c2.densidadePopulacional)
        printf("Carta 2 vence em Densidade (menor é melhor)!\n");
    else
        printf("Empate em Densidade!\n");
}


int main() {

    Carta carta1, carta2;

    cadastrarCarta(&carta1);
    cadastrarCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}