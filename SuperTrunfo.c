#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

// Estrutura para armazenar os dados das cartas (cidades)
struct Cidade {
    unsigned long populacao;  // População agora é unsigned long para números maiores
    float area, pib, densidade, pib2, superpoder; // Declara variáveis do tipo float para área, PIB, densidade, PIB per capita e superpoder
    int pontos_turisticos; // Declara variável do tipo inteiro para pontos turísticos
};

// Função para capturar os dados de uma carta
void capturar_dados(struct Cidade *c) {
    printf("População: "); // Imprime "População: " na tela
    scanf("%lu", &c->populacao); // Lê um valor unsigned long do teclado e armazena em c->populacao

    printf("Área: "); // Imprime "Área: " na tela
    scanf("%f", &c->area); // Lê um valor float do teclado e armazena em c->area

    printf("PIB: "); // Imprime "PIB: " na tela
    scanf("%f", &c->pib); // Lê um valor float do teclado e armazena em c->pib

    printf("Pontos Turísticos: "); // Imprime "Pontos Turísticos: " na tela
    scanf("%d", &c->pontos_turisticos); // Lê um valor inteiro do teclado e armazena em c->pontos_turisticos
}

// Função para calcular a densidade, PIB per capita e o superpoder
void calcular_valores(struct Cidade *c) {
    c->densidade = c->populacao / c->area; // Calcula a densidade populacional
    c->pib2 = c->pib / c->populacao; // Calcula o PIB per capita
    c->superpoder = c->populacao + c->area + c->pib + c->pib2 + c->pontos_turisticos + (1 / c->densidade); // Calcula o "superpoder"
}

// Função para exibir as informações de uma carta
void exibir_carta(struct Cidade *c, int numero) {
    printf("\n--- CARTA %d ---\n", numero); // Imprime o número da carta
    printf("População: %lu\n", c->populacao); // Imprime a população
    printf("Área: %.2f km²\n", c->area); // Imprime a área com 2 casas decimais
    printf("PIB: %.2f bilhões\n", c->pib); // Imprime o PIB com 2 casas decimais
    printf("Pontos Turísticos: %d\n", c->pontos_turisticos); // Imprime o número de pontos turísticos
    printf("Densidade Populacional: %.2f hab/km²\n", c->densidade); // Imprime a densidade populacional com 2 casas decimais
    printf("PIB per Capita: %.2f\n", c->pib2); // Imprime o PIB per capita com 2 casas decimais
    printf("Super Poder: %.2f\n", c->superpoder); // Imprime o "superpoder" com 2 casas decimais
}

// Função para comparar dois valores e retornar o número da carta vencedora
int comparar_valores(float val1, float val2, int tipo) {
    switch (tipo) {
        case 1: return val1 > val2 ? 1 : 2; // População (retorna 1 se val1 > val2, senão retorna 2)
        case 2: return val1 > val2 ? 1 : 2; // Área (retorna 1 se val1 > val2, senão retorna 2)
        case 3: return val1 > val2 ? 1 : 2; // PIB (retorna 1 se val1 > val2, senão retorna 2)
        case 4: return val1 > val2 ? 1 : 2; // Pontos Turísticos (retorna 1 se val1 > val2, senão retorna 2)
        case 5: return val1 < val2 ? 1 : 2; // Densidade (menor vence) (retorna 1 se val1 < val2, senão retorna 2)
        case 6: return val1 > val2 ? 1 : 2; // PIB per Capita (retorna 1 se val1 > val2, senão retorna 2)
        case 7: return val1 > val2 ? 1 : 2; // Super Poder (retorna 1 se val1 > val2, senão retorna 2)
        default: return 0; // Retorna 0 em caso de tipo inválido
    }
}

int main() {
    struct Cidade c1, c2; // Declara duas variáveis do tipo struct Cidade

    // Captura de dados para as duas cartas
    printf("== Captura de Dados da Carta 1 ==\n"); // Imprime mensagem na tela
    capturar_dados(&c1); // Chama a função para capturar dados da carta 1

    printf("\nPressione ENTER para continuar...\n"); // Imprime mensagem na tela
    getchar(); getchar(); // Limpa buffer e espera ENTER

    printf("== Captura de Dados da Carta 2 ==\n"); // Imprime mensagem na tela
    capturar_dados(&c2); // Chama a função para capturar dados da carta 2

    // Cálculos das variáveis
    calcular_valores(&c1); // Calcula os valores para a carta 1
    calcular_valores(&c2); // Calcula os valores para a carta 2

    // Exibição das Cartas
    exibir_carta(&c1, 1); // Exibe os dados da carta 1
    exibir_carta(&c2, 2); // Exibe os dados da carta 2

    // Comparação das cartas
    printf("\n--- COMPARAÇÃO DAS CARTAS ---\n"); // Imprime mensagem na tela

    printf("População: Carta %d venceu\n", comparar_valores(c1.populacao, c2.populacao, 1)); // Compara população e imprime o resultado
    printf("Área: Carta %d venceu\n", comparar_valores(c1.area, c2.area, 2)); // Compara área e imprime o resultado
    printf("PIB: Carta %d venceu\n", comparar_valores(c1.pib, c2.pib, 3)); // Compara PIB e imprime o resultado
    printf("Pontos Turísticos: Carta %d venceu\n", comparar_valores(c1.pontos_turisticos, c2.pontos_turisticos, 4)); // Compara pontos turísticos e imprime o resultado
    printf("Densidade Populacional: Carta %d venceu\n", comparar_valores(c1.densidade, c2.densidade, 5)); // Compara densidade e imprime o resultado
    printf("PIB per Capita: Carta %d venceu\n", comparar_valores(c1.pib2, c2.pib2, 6)); // Compara PIB per capita e imprime o resultado
    printf("Super Poder: Carta %d venceu\n", comparar_valores(c1.superpoder, c2.superpoder, 7)); // Compara superpoder e imprime o resultado

    return 0; // Retorna 0 para indicar execução bem-sucedida
}