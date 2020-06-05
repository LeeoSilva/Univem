// headers
#include "../headers/actions.hpp"

int main(void){
    priorityQueue normal_queue;
    priorityQueue aged_queue;
    priorityQueue pregnant_queue;
    priorityQueue deficient_queue;

    initialize(&normal_queue);
    initialize(&aged_queue);
    initialize(&pregnant_queue);
    initialize(&deficient_queue);


    for(;;printf("==========\n")){
        int userChoise = drawMenuAndGetUserDecision();
        switch(userChoise){
            case GET_PASS_NORMAL: getPassAndRegister(NORMAL, &normal_queue); break;
            case GET_PASS_AGED: getPassAndRegister(AGED, &aged_queue); break;
            case GET_PASS_PREGNANT: getPassAndRegister(PREGNANT, &pregnant_queue); break;
            case GET_PASS_DEFICIENT: getPassAndRegister(DEFICIENT, &deficient_queue); break;
            case CALL_NEXT: 
                if(call_next_in_queue(&pregnant_queue)) break;
                if(call_next_in_queue(&deficient_queue)) break;
                if(call_next_in_queue(&aged_queue)) break;
                if(call_next_in_queue(&normal_queue)) break;
                else break;
            case SHOW_QUEUE: 
                                     printf("Normal: ");
                                     displayQueue(&normal_queue); 
                                     printf("Gestantes: ");
                                     displayQueue(&pregnant_queue); 
                                     printf("Idosos: ");
                                     displayQueue(&aged_queue); 
                                     printf("Deficientes: ");
                                     displayQueue(&deficient_queue); 
                                     break;
            case EXIT: return 0; // TODO: remove heap allocation to prevent memory leak
            default: printf("Ação inválida! Fechando Sistema.\n"); return 0;
        };
    }
}
