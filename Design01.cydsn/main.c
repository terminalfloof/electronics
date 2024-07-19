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

float frequencies[] = {262.0, 278.1, 292.8, 314.13, 327.5, 344.3, 372.3, 392.0, 416.4, 437.7, 467.4, 502.2, 524.0};

void DacSet() // runs at 50 kHz
{
    //CyDelayUs(10);
    if (EnableOutput)
    {
        if (C_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[0] * (1/16000.0);
        }
        else if (CS_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[1] * (1/16000.0);
        }
        else if (D_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[2] * (1/16000.0);
        }
        else if (DS_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[3] * (1/16000.0);
        }
        else if (E_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[4] * (1/16000.0);
        }
        else if (F_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[5] * (1/16000.0);
        }
        else if (FS_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[6] * (1/16000.0);
        }
        else if (G_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[7] * (1/16000.0);
        }
        else if (GS_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[8] * (1/16000.0);
        }
        else if (A_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[9] * (1/16000.0);
        }
        else if (AS_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[10] * (1/16000.0);
        }
        else if (B_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[11] * (1/16000.0);
        }
        else if (UC_Read() > 0) {
            theta += 2 * 3.14159 * frequencies[12] * (1/16000.0);
        }

        if (theta > 2 * 3.14159) {
            theta -= 2 * 3.14159;
        }

        DacCode = 127 + 120 * sinf(theta);

        VDAC8_1_SetValue(DacCode);
    }
}

/* [] END OF FILE */