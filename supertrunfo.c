#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[20];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

// Função para cadastrar os dados da carta
void cadastrarCarta(struct Carta *carta) {
    printf("Informe o Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Informe o Código da carta: ");
    scanf(" %[^\n]", carta->codigo);

    printf("Informe o Nome da cidade: ");
    scanf(" %[^\n]", carta->nome_cidade);

    printf("Informe a População: ");
    scanf("%d", &carta->populacao);

    printf("Informe a Área (km²): ");
    scanf("%f", &carta->area);

    printf("Informe o PIB (em milhões): ");
    scanf("%f", &carta->pib);

    printf("Informe o Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculos adicionais
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    // Escolha do atributo de comparação
    // Opções: populacao, area, pib, densidade_populacional, pib_per_capita
    char atributo[] = "populacao";  // <-- Altere aqui se quiser comparar outro atributo

    float valor1 = 0, valor2 = 0;
    int vencedor = 0;  // 0 = empate, 1 = carta1, 2 = carta2

    if (strcmp(atributo, "populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } else if (strcmp(atributo, "densidade_populacional") == 0) {
        valor1 = carta1.densidade_populacional;
        valor2 = carta2.densidade_populacional;
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
    }

    // Determinação do vencedor
    if (strcmp(atributo, "densidade_populacional") == 0) {
        if (valor1 < valor2) {
            vencedor = 1;
        } else if (valor2 < valor1) {
            vencedor = 2;
        }
    } else {
        if (valor1 > valor2) {
            vencedor = 1;
        } else if (valor2 > valor1) {
            vencedor = 2;
        }
    }

    // Exibir resultado
    printf("\nComparação de cartas (Atributo: %s):\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, valor2);

    if (vencedor == 1) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (vencedor == 2) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
