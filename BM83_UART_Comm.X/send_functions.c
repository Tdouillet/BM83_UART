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

extern uint8_t command_sent;
extern uint8_t power_status;

void Event_Ack(uint8_t tab[]){
    
    uint8_t checksum = 1+~(0x02+0x14+tab[0]);
    
    UART1_Send(0xAA);
    UART1_Send(0x00);
    UART1_Send(0x02);
    UART1_Send(0x14);
    UART1_Send(tab[0]);
    UART1_Send(checksum);
    

}

void Module_On(void){
    
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x02);
    UART1_Write(0x00);
    UART1_Write(0x51);
    UART1_Write(0xAA);
    command_sent=1;
    
    Delay(20);
         
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x02);
    UART1_Write(0x00);
    UART1_Write(0x52);
    UART1_Write(0xA9);
    command_sent = 1;
    
    power_status = 1;
        
}

void Module_Off(void){
    
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x02);
    UART1_Write(0x00);
    UART1_Write(0x53);
    UART1_Write(0xA8);
    command_sent=1;
    
    Delay(20);
         
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x02);
    UART1_Write(0x00);
    UART1_Write(0x54);
    UART1_Write(0xA7);
    command_sent = 1;
    
    power_status = 0;
    
}

void Pair_Device(void){
    
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x02);
    UART1_Write(0x00);
    UART1_Write(0x5D);
    UART1_Write(0x9E);
    command_sent = 1;
    
}

void Exit_Pairing(void){
    
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x02);
    UART1_Write(0x00);
    UART1_Write(0x6B);
    UART1_Write(0x90);
    command_sent = 1;
    
}

void Toggle_Music(void) {
    
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x04);
    UART1_Write(0x00);
    UART1_Write(0x07);
    UART1_Write(0xF2);
    command_sent = 1;
    
}

void Voice_Prompt(uint8_t byte){
    
    uint8_t checksum = 1+~(0x03+0x13+0x02+byte);
    
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x03);
    UART1_Write(0x13);
    UART1_Write(0x02);
    UART1_Write(byte);
    UART1_Write(checksum);
    command_sent = 1;
    
}





