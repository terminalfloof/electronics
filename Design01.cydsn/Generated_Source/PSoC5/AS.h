/*******************************************************************************
* File Name: AS.h  
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

#if !defined(CY_PINS_AS_H) /* Pins AS_H */
#define CY_PINS_AS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AS__PORT == 15 && ((AS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AS_Write(uint8 value);
void    AS_SetDriveMode(uint8 mode);
uint8   AS_ReadDataReg(void);
uint8   AS_Read(void);
void    AS_SetInterruptMode(uint16 position, uint16 mode);
uint8   AS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AS_SetDriveMode() function.
     *  @{
     */
        #define AS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AS_DM_RES_UP          PIN_DM_RES_UP
        #define AS_DM_RES_DWN         PIN_DM_RES_DWN
        #define AS_DM_OD_LO           PIN_DM_OD_LO
        #define AS_DM_OD_HI           PIN_DM_OD_HI
        #define AS_DM_STRONG          PIN_DM_STRONG
        #define AS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AS_MASK               AS__MASK
#define AS_SHIFT              AS__SHIFT
#define AS_WIDTH              1u

/* Interrupt constants */
#if defined(AS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AS_SetInterruptMode() function.
     *  @{
     */
        #define AS_INTR_NONE      (uint16)(0x0000u)
        #define AS_INTR_RISING    (uint16)(0x0001u)
        #define AS_INTR_FALLING   (uint16)(0x0002u)
        #define AS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AS_INTR_MASK      (0x01u) 
#endif /* (AS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AS_PS                     (* (reg8 *) AS__PS)
/* Data Register */
#define AS_DR                     (* (reg8 *) AS__DR)
/* Port Number */
#define AS_PRT_NUM                (* (reg8 *) AS__PRT) 
/* Connect to Analog Globals */                                                  
#define AS_AG                     (* (reg8 *) AS__AG)                       
/* Analog MUX bux enable */
#define AS_AMUX                   (* (reg8 *) AS__AMUX) 
/* Bidirectional Enable */                                                        
#define AS_BIE                    (* (reg8 *) AS__BIE)
/* Bit-mask for Aliased Register Access */
#define AS_BIT_MASK               (* (reg8 *) AS__BIT_MASK)
/* Bypass Enable */
#define AS_BYP                    (* (reg8 *) AS__BYP)
/* Port wide control signals */                                                   
#define AS_CTL                    (* (reg8 *) AS__CTL)
/* Drive Modes */
#define AS_DM0                    (* (reg8 *) AS__DM0) 
#define AS_DM1                    (* (reg8 *) AS__DM1)
#define AS_DM2                    (* (reg8 *) AS__DM2) 
/* Input Buffer Disable Override */
#define AS_INP_DIS                (* (reg8 *) AS__INP_DIS)
/* LCD Common or Segment Drive */
#define AS_LCD_COM_SEG            (* (reg8 *) AS__LCD_COM_SEG)
/* Enable Segment LCD */
#define AS_LCD_EN                 (* (reg8 *) AS__LCD_EN)
/* Slew Rate Control */
#define AS_SLW                    (* (reg8 *) AS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AS_PRTDSI__CAPS_SEL       (* (reg8 *) AS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AS_PRTDSI__OE_SEL0        (* (reg8 *) AS__PRTDSI__OE_SEL0) 
#define AS_PRTDSI__OE_SEL1        (* (reg8 *) AS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AS_PRTDSI__OUT_SEL0       (* (reg8 *) AS__PRTDSI__OUT_SEL0) 
#define AS_PRTDSI__OUT_SEL1       (* (reg8 *) AS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AS_PRTDSI__SYNC_OUT       (* (reg8 *) AS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AS__SIO_CFG)
    #define AS_SIO_HYST_EN        (* (reg8 *) AS__SIO_HYST_EN)
    #define AS_SIO_REG_HIFREQ     (* (reg8 *) AS__SIO_REG_HIFREQ)
    #define AS_SIO_CFG            (* (reg8 *) AS__SIO_CFG)
    #define AS_SIO_DIFF           (* (reg8 *) AS__SIO_DIFF)
#endif /* (AS__SIO_CFG) */

/* Interrupt Registers */
#if defined(AS__INTSTAT)
    #define AS_INTSTAT            (* (reg8 *) AS__INTSTAT)
    #define AS_SNAP               (* (reg8 *) AS__SNAP)
    
	#define AS_0_INTTYPE_REG 		(* (reg8 *) AS__0__INTTYPE)
#endif /* (AS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AS_H */


/* [] END OF FILE */
