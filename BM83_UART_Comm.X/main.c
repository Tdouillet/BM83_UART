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
uint8_t command_sent = 0;
uint8_t init_tab[7];
uint8_t init_index = 0;
uint8_t init_status = 1;
uint8_t power_status = 0;
uint8_t pairing = 0;



//Turn on button
void BP6_Press_Callback(void){
 
    Voice_Prompt(0xC0);
    
}

void BP5_Press_Callback(void){
    
    
    
}

void BP4_Press_Callback(void){
    
    Voice_Prompt(0xC1);
}

//Turn off button
void BP3_Press_Callback(void){
    
    if (power_status){
        Module_Off();
        power_status = 0;
    } else {
        Module_On();
        power_status = 1;
    }
    
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    BP6_SetInterruptHandler(BP6_Press_Callback);
    BP5_SetInterruptHandler(BP5_Press_Callback);
    BP4_SetInterruptHandler(BP4_Press_Callback);
    BP3_SetInterruptHandler(BP3_Press_Callback);
    
    LED_SetHigh();
    Delay(6000);
    LED_SetLow();
    
    Module_On();
    
    Delay(1000);
            
    UART1_Write(0xAA);
    UART1_Write(0x00);
    UART1_Write(0x09);
    UART1_Write(0x05);
    UART1_Write(0x53);
    UART1_Write(0x6B);
    UART1_Write(0x79);
    UART1_Write(0x47);
    UART1_Write(0x75);
    UART1_Write(0x61);
    UART1_Write(0x72);
    UART1_Write(0x64);
    UART1_Write(0xC8);
        
    
    while (1)
    {          
        // Add your application code
        
    
        
    }

    return 1;
}
/**
 End of File
*/

