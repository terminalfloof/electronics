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

void DacSet() // runs at 50 kHz
{
    //CyDelayUs(10);
    if (EnableOutput)
    {
        int tone;

        int active[] = {
            C_Read() > 0 ? 1 : 0,
            CS_Read() > 0 ? 1 : 0,
            D_Read() > 0 ? 1 : 0,
            DS_Read() > 0 ? 1 : 0,
            E_Read() > 0 ? 1 : 0,
            F_Read() > 0 ? 1 : 0,
            FS_Read() > 0 ? 1 : 0,
            G_Read() > 0 ? 1 : 0,
            GS_Read() > 0 ? 1 : 0,
            A_Read() > 0 ? 1 : 0,
            AS_Read() > 0 ? 1 : 0,
            B_Read() > 0 ? 1 : 0,
            UC_Read() > 0 ? 1 : 0
        };

        float previousTheta = theta;
        DacCode = 127;
        // adjust theta based off of the theoretical run speed
        int i = 0;
        for (i = 0; i < 13; i++) {
            if (active[i]) {
                theta = previousTheta;
                theta += 2 * 3.14159 * frequencies[i] * (1/16000.0);
                if (theta > 2 * 3.14159) theta -= 2 * 3.14159;
                DacCode += 120 * sin(theta);
            }
        }

        // DacCode += 120 * sin(theta * frequencies[4]);

        // int count = 1;
        // int i = 0;
        // for (i = 0; i < 13; i++) if (active[i]) count++;
        // if (count == 0) return;

        // int i = 0;
        // for (i = 0; i < 13; i++) {
        //     if (active[i]) {
        //         theta *= frequencies[i];
        //         if 
        //     }
        // }

        // theta += 6.28 * 8000 * (1/50000.0);
        
        VDAC8_1_SetValue(DacCode);
    }
}

/* [] END OF FILE */