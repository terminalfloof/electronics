/*******************************************************************************
* File Name: DacOutput.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DacOutput_H) /* Pins DacOutput_H */
#define CY_PINS_DacOutput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DacOutput_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DacOutput__PORT == 15 && ((DacOutput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DacOutput_Write(uint8 value);
void    DacOutput_SetDriveMode(uint8 mode);
uint8   DacOutput_ReadDataReg(void);
uint8   DacOutput_Read(void);
void    DacOutput_SetInterruptMode(uint16 position, uint16 mode);
uint8   DacOutput_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DacOutput_SetDriveMode() function.
     *  @{
     */
        #define DacOutput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DacOutput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DacOutput_DM_RES_UP          PIN_DM_RES_UP
        #define DacOutput_DM_RES_DWN         PIN_DM_RES_DWN
        #define DacOutput_DM_OD_LO           PIN_DM_OD_LO
        #define DacOutput_DM_OD_HI           PIN_DM_OD_HI
        #define DacOutput_DM_STRONG          PIN_DM_STRONG
        #define DacOutput_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DacOutput_MASK               DacOutput__MASK
#define DacOutput_SHIFT              DacOutput__SHIFT
#define DacOutput_WIDTH              1u

/* Interrupt constants */
#if defined(DacOutput__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DacOutput_SetInterruptMode() function.
     *  @{
     */
        #define DacOutput_INTR_NONE      (uint16)(0x0000u)
        #define DacOutput_INTR_RISING    (uint16)(0x0001u)
        #define DacOutput_INTR_FALLING   (uint16)(0x0002u)
        #define DacOutput_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DacOutput_INTR_MASK      (0x01u) 
#endif /* (DacOutput__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DacOutput_PS                     (* (reg8 *) DacOutput__PS)
/* Data Register */
#define DacOutput_DR                     (* (reg8 *) DacOutput__DR)
/* Port Number */
#define DacOutput_PRT_NUM                (* (reg8 *) DacOutput__PRT) 
/* Connect to Analog Globals */                                                  
#define DacOutput_AG                     (* (reg8 *) DacOutput__AG)                       
/* Analog MUX bux enable */
#define DacOutput_AMUX                   (* (reg8 *) DacOutput__AMUX) 
/* Bidirectional Enable */                                                        
#define DacOutput_BIE                    (* (reg8 *) DacOutput__BIE)
/* Bit-mask for Aliased Register Access */
#define DacOutput_BIT_MASK               (* (reg8 *) DacOutput__BIT_MASK)
/* Bypass Enable */
#define DacOutput_BYP                    (* (reg8 *) DacOutput__BYP)
/* Port wide control signals */                                                   
#define DacOutput_CTL                    (* (reg8 *) DacOutput__CTL)
/* Drive Modes */
#define DacOutput_DM0                    (* (reg8 *) DacOutput__DM0) 
#define DacOutput_DM1                    (* (reg8 *) DacOutput__DM1)
#define DacOutput_DM2                    (* (reg8 *) DacOutput__DM2) 
/* Input Buffer Disable Override */
#define DacOutput_INP_DIS                (* (reg8 *) DacOutput__INP_DIS)
/* LCD Common or Segment Drive */
#define DacOutput_LCD_COM_SEG            (* (reg8 *) DacOutput__LCD_COM_SEG)
/* Enable Segment LCD */
#define DacOutput_LCD_EN                 (* (reg8 *) DacOutput__LCD_EN)
/* Slew Rate Control */
#define DacOutput_SLW                    (* (reg8 *) DacOutput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DacOutput_PRTDSI__CAPS_SEL       (* (reg8 *) DacOutput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DacOutput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DacOutput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DacOutput_PRTDSI__OE_SEL0        (* (reg8 *) DacOutput__PRTDSI__OE_SEL0) 
#define DacOutput_PRTDSI__OE_SEL1        (* (reg8 *) DacOutput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DacOutput_PRTDSI__OUT_SEL0       (* (reg8 *) DacOutput__PRTDSI__OUT_SEL0) 
#define DacOutput_PRTDSI__OUT_SEL1       (* (reg8 *) DacOutput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DacOutput_PRTDSI__SYNC_OUT       (* (reg8 *) DacOutput__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DacOutput__SIO_CFG)
    #define DacOutput_SIO_HYST_EN        (* (reg8 *) DacOutput__SIO_HYST_EN)
    #define DacOutput_SIO_REG_HIFREQ     (* (reg8 *) DacOutput__SIO_REG_HIFREQ)
    #define DacOutput_SIO_CFG            (* (reg8 *) DacOutput__SIO_CFG)
    #define DacOutput_SIO_DIFF           (* (reg8 *) DacOutput__SIO_DIFF)
#endif /* (DacOutput__SIO_CFG) */

/* Interrupt Registers */
#if defined(DacOutput__INTSTAT)
    #define DacOutput_INTSTAT            (* (reg8 *) DacOutput__INTSTAT)
    #define DacOutput_SNAP               (* (reg8 *) DacOutput__SNAP)
    
	#define DacOutput_0_INTTYPE_REG 		(* (reg8 *) DacOutput__0__INTTYPE)
#endif /* (DacOutput__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DacOutput_H */


/* [] END OF FILE */
