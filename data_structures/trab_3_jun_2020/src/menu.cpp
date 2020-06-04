#include "../headers/menu.hpp"

int drawMenuAndGetUserDecition(){
    int userChoise = EXIT; 
    printf("1 - Retirar senha - atendimento normal. \n");
    printf("2 - Retirar senha - atendimento idoso. \n");
    printf("3 - Retirar senha - atendimento gestante. \n");
    printf("4 - Retirar senha - atendimento deficiente. \n");
    printf("5 - Proximo na fila. \n");
    printf("6 - Mostrar Fila. \n");
    printf("7 - Sair. \n");
    printf("Informe sua ação: \n");
    scanf("%d", &userChoise);
    fflush(stdin);
    return userChoise;
}

