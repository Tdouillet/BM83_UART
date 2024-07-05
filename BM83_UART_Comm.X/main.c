/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/uart1.h"
#include "DELAY.h"
#include "send_functions.h"
/*
                         Main application
 */
uint8_t rx_buf[] = {'\0'};
uint8_t ack = 0;
uint8_t command_sent = 3;
uint8_t init_status = 1;
uint8_t init_tab[7];
uint8_t init_index = 0;
uint8_t power_status = 0;

void Manual_Send(uint8_t byte){
    
    TX_SetLow();
    Delay_us(1);
    for (uint8_t i=0; i<8; i++){
        if (byte%2 != 0){
            TX_SetHigh();
        } else {
            TX_SetLow();
        }
        Delay_us(1);
        byte=byte >> 1;
    }
    TX_SetHigh();
//    Delay_us(1);
    
}


void BP6_Turnoff_Callback(void){
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    BP6_SetInterruptHandler(BP6_Turnoff_Callback);
    
//    Delay(6000);
//    
//    UART1_Write(0xAA);
//    UART1_Write(0x00);
//    UART1_Write(0x03);
//    UART1_Write(0x02);
//    UART1_Write(0x00);
//    UART1_Write(0x51);
//    UART1_Write(0xAA);
//    command_sent=1;
//    
//    Delay(20);
//          
//    UART1_Write(0xAA);
//    UART1_Write(0x00);
//    UART1_Write(0x03);
//    UART1_Write(0x02);
//    UART1_Write(0x00);
//    UART1_Write(0x52);
//    UART1_Write(0xA9);
//    command_sent = 1;
//    
//    Delay(6000);


//    Delay(100);
//    Test_SetHigh();
//    
//    UART1_Write(0xAA);
//    UART1_Write(0x00);
//    UART1_Write(0x02);
//    UART1_Write(0x32);
//    UART1_Write(0x00);
//    UART1_Write(0xCC);
    

//    Test_SetLow();

    while (1)
    {
        
//        UART1_Write(0xFF);
//            Delay(200);
//        
//                Manual_Send(0xAA);
//                Manual_Send(0x00);
//                Manual_Send(0x03);
//                Manual_Send(0x02);
//                Manual_Send(0x00);
//                Manual_Send(0x51);
//                Manual_Send(0xAA);
//                command_sent=1;
//    
//                Delay(200);
//          
//                Manual_Send(0xAA);
//                Manual_Send(0x00);
//                Manual_Send(0x03);
//                Manual_Send(0x02);
//                Manual_Send(0x00);
//                Manual_Send(0x52);
//                Manual_Send(0xA9);
//                command_sent = 1;
        
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
            
                Delay(2000);
            
        // Add your application code
        if (!init_status){ //Initialization phase finished
            
            command_sent = 0;
            Delay(3000);
            
            if (!power_status){
//                UART1_Write(0xAA);
//                UART1_Write(0x00);
//                UART1_Write(0x03);
//                UART1_Write(0x02);
//                UART1_Write(0x00);
//                UART1_Write(0x51);
//                UART1_Write(0xAA);
//                command_sent=1;
//    
//                Delay(20);
//          
//                UART1_Write(0xAA);
//                UART1_Write(0x00);
//                UART1_Write(0x03);
//                UART1_Write(0x02);
//                UART1_Write(0x00);
//                UART1_Write(0x52);
//                UART1_Write(0xA9);
//                command_sent = 1;
                
//                power_status = 1;
            }
            
            
            
            
            
            
            
            
        }
//        
    }

    return 1;
}
/**
 End of File
*/

