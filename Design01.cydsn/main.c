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

float frequency = 440;

float toneFromFreq(float freq) {
    // m = 0.1412
    // b = -23.333

    // inverse

    return 7.25 * freq + 126;
}

void DacSet() // runs at 50 kHz
{
    Pin_1_Write(1);
    //CyDelayUs(10);
    if (EnableOutput)
    {
        // tone = tone - .01;
        // if (tone < 200)
        //     tone = 400;
        // //tone = 1000;
        // /*theta += 2 * tone * 0.00002;
        // if (theta > 6.283185307)
        //     theta -= 6.283185307;
        // //DacCode = 127 + 120 * sin((double)theta);
        // DacCode = 127 + */
        // if (UpDown)
        //     theta += tone * 0.000051;
        // else
        //     theta -= tone * 0.000051;
        // if(theta > 0.5)
        //     UpDown = 0;
        // if(theta < -0.5)
        //     UpDown = 1;

        // adjust theta based off of the theoretical run speed
        theta += 6.28 * toneFromFreq(frequency) * (1/50000.0);
        // theta += 6.28 * 8000 * (1/50000.0);
        if (theta > 6.28) theta = 0;

        // DacCode = 127 + 240 * theta;
        DacCode = 127 + 120 * sin(theta);
        
        VDAC8_1_SetValue(DacCode);
    }
    Pin_1_Write(0);
}

/* [] END OF FILE */