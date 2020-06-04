// headers
#include "../headers/priorityQueue.hpp"
#include "../headers/client.hpp"
#include "../headers/menu.hpp"

int main(void){
    int userChoise = drawMenuAndGetUserDecition();
    switch(userChoise){
        case GET_PASS_NORMAL: printf("Normal\n");break;
        case GET_PASS_AGED: printf("Aged\n"); break;
        case GET_PASS_PREGNANT: printf("Pregnant\n"); break;
        case GET_PASS_DEFICIENT: printf("Deficient\n"); break;
        case CALL_NEXT: printf("call_next\n"); break;
        case SHOW_QUEUE: printf("show_queue\n"); break;
        case EXIT: return 0;
        default: printf("Ação inválida! Fechando Sistema.\n"); return 0;
    };
}
