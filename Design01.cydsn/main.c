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
uint8_t DacCode = 0;
uint8_t EnableOutput = 0;
uint8_t UpDown = 0;

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
        EnableOutput = 1;
        /*if (Pin_2_Read() == 1)
        {
            EnableOutput = 1;
            tone = 5000;
        } else if (Pin_3_Read() == 1)
        {
          //blah   
        } else
        {
            EnableOutput = 1;//fixme;   
        }*/
    }
}

float frequencies[] = {262.0, 278.1, 292.8, 314.13, 333.5, 352.3, 376.3, 397.0, 421.4, 444.7, 472.4, 508.2, 532.0};
int active[13];

void DacSet() // runs at 50 kHz
{
    //CyDelayUs(10);
    if (EnableOutput)
    {
        int tone;

        // adjust theta based off of the theoretical run speed
        theta += 2 * 3.14159 * frequencies[(int) (tone / 1000)] * (1/15790.0);
        // theta += 6.28 * 8000 * (1/50000.0);
        if (theta > (2 * 3.14159)) theta = 0;

        // DacCode = 127 + 240 * theta;
        DacCode = 127 + 120 * sinf(theta);
        
        VDAC8_1_SetValue(DacCode);
    }
}

/* [] END OF FILE */