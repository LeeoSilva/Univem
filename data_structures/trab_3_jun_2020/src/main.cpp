// headers
#include "../headers/actions.hpp"

int main(void){
    priorityQueue queues;
    
    for(;;printf("==========\n")){
        int userChoise = drawMenuAndGetUserDecision();
        switch(userChoise){
            case GET_PASS_NORMAL: getPassAndRegister(NORMAL, &queues); break;
            case GET_PASS_AGED: getPassAndRegister(AGED, &queues); break;
            case GET_PASS_PREGNANT: getPassAndRegister(PREGNANT, &queues); break;
            case GET_PASS_DEFICIENT: getPassAndRegister(DEFICIENT, &queues); break;
            case CALL_NEXT: printf("call_next\n"); break;
            case SHOW_QUEUE: printf("show_queue\n"); break;
            case EXIT: return 0; // TODO: remove heap allocation to prevent memory leak
            default: printf("Ação inválida! Fechando Sistema.\n"); return 0;
        };
    }
}
