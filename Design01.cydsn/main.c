/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>

CY_ISR_PROTO(DacSet);

float theta = 0;
float tone = 4000;
uint8_t DacCode = 0;
uint8_t EnableOutput = 0;

int main()
{
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    VDAC8_1_Start();
    isr_1_StartEx(DacSet);
    
    /*isr_1_SetPriority(DEFAULT_PRIORITY);
    CyIntSetVector(NESTED_ISR,NestedIsrHandler);
    CyIntSetPriority(NESTED_ISR,HIGHER_PRIORITY);
    CyIntEnable(NESTED_ISR);*/
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    for(;;)
    {
        /* Place your application code here. */
        if (Pin_2_Read() == 1)
        {
            EnableOutput = 1;
            tone = 5000;
        } else if (Pin_3_Read() == 1)
        {
          //blah   
        } else
        {
            EnableOutput = 0;   
        }
    }
}

void DacSet() // runs at 50 kHz
{
    if (EnableOutput)
    {
        tone = tone - 1;
        if (tone < 1000)
            tone = 4000;
        theta += 6.283185307 * tone * 0.00002;
        if (theta > 6.283185307)
            theta -= 6.283185307;
        DacCode = 127 + 120 * sin((double)theta);
        VDAC8_1_SetValue(DacCode);
    }
}

/* [] END OF FILE */
