/*
 * File:   sendFunc.c
 * Author: t.douillet
 *
 * Created on 1 juillet 2024, 15:43
 */


#include "xc.h"
#include "mcc_generated_files\uart1.h"
#include "send_functions.h"
#include "DELAY.h"
#include "mcc_generated_files/pin_manager.h"

//void Manual_Send(uint8_t byte){
//    
//    TX_SetLow();
//    Delay_us(9);
//    for (uint8_t i=0; i<8; i++){
//        if (byte%2 == 0){
//            TX_SetHigh();
//        } else {
//            TX_SetLow();
//        }
//        Delay_us(9);
//        byte=byte >> 1;
//    }
//    TX_SetHigh();
//    Delay_us(9);
//    
//}

void Event_Ack(uint8_t tab[]){
    
    uint8_t checksum = 1+~(0x02+0x14+tab[0]);
    
//    Manual_Send(0xAA);
//    Manual_Send(0x00);
//    Manual_Send(0x02);
//    Manual_Send(0x14);
//    Manual_Send(tab[0]);
//    Manual_Send(checksum);
    
    UART1_Send(0xAA);
    UART1_Send(0x00);
    UART1_Send(0x02);
    UART1_Send(0x14);
    UART1_Send(tab[0]);
    UART1_Send(checksum);
    

}





