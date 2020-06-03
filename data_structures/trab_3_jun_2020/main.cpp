#include <stdio.h>

enum menu {
    NORMAL = 1,
    AGED,
    PREGNANT,
    DEFICIENT,
    CALL_NEXT,
    SHOW_QUEUE,
    EXIT
};

int displayMenuAndGetUserDecisition(){
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

int main(void){
    int userChoise = displayMenuAndGetUserDecisition();
    switch(userChoise){
        case NORMAL: printf("Normal\n");break;
        case AGED: printf("Aged\n"); break;
        case PREGNANT: printf("Pregnant\n"); break;
        case DEFICIENT: printf("Deficient\n"); break;
        case CALL_NEXT: printf("call_next\n"); break;
        case SHOW_QUEUE: printf("show_queue\n"); break;
        case EXIT: return 0;
        default: printf("Ação inválida! Fechando Sistema.");
    };
}
