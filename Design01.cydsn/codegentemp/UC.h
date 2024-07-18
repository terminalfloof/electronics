/*******************************************************************************
* File Name: UC.h  
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

#if !defined(CY_PINS_UC_H) /* Pins UC_H */
#define CY_PINS_UC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UC__PORT == 15 && ((UC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    UC_Write(uint8 value);
void    UC_SetDriveMode(uint8 mode);
uint8   UC_ReadDataReg(void);
uint8   UC_Read(void);
void    UC_SetInterruptMode(uint16 position, uint16 mode);
uint8   UC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the UC_SetDriveMode() function.
     *  @{
     */
        #define UC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define UC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define UC_DM_RES_UP          PIN_DM_RES_UP
        #define UC_DM_RES_DWN         PIN_DM_RES_DWN
        #define UC_DM_OD_LO           PIN_DM_OD_LO
        #define UC_DM_OD_HI           PIN_DM_OD_HI
        #define UC_DM_STRONG          PIN_DM_STRONG
        #define UC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define UC_MASK               UC__MASK
#define UC_SHIFT              UC__SHIFT
#define UC_WIDTH              1u

/* Interrupt constants */
#if defined(UC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UC_SetInterruptMode() function.
     *  @{
     */
        #define UC_INTR_NONE      (uint16)(0x0000u)
        #define UC_INTR_RISING    (uint16)(0x0001u)
        #define UC_INTR_FALLING   (uint16)(0x0002u)
        #define UC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define UC_INTR_MASK      (0x01u) 
#endif /* (UC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UC_PS                     (* (reg8 *) UC__PS)
/* Data Register */
#define UC_DR                     (* (reg8 *) UC__DR)
/* Port Number */
#define UC_PRT_NUM                (* (reg8 *) UC__PRT) 
/* Connect to Analog Globals */                                                  
#define UC_AG                     (* (reg8 *) UC__AG)                       
/* Analog MUX bux enable */
#define UC_AMUX                   (* (reg8 *) UC__AMUX) 
/* Bidirectional Enable */                                                        
#define UC_BIE                    (* (reg8 *) UC__BIE)
/* Bit-mask for Aliased Register Access */
#define UC_BIT_MASK               (* (reg8 *) UC__BIT_MASK)
/* Bypass Enable */
#define UC_BYP                    (* (reg8 *) UC__BYP)
/* Port wide control signals */                                                   
#define UC_CTL                    (* (reg8 *) UC__CTL)
/* Drive Modes */
#define UC_DM0                    (* (reg8 *) UC__DM0) 
#define UC_DM1                    (* (reg8 *) UC__DM1)
#define UC_DM2                    (* (reg8 *) UC__DM2) 
/* Input Buffer Disable Override */
#define UC_INP_DIS                (* (reg8 *) UC__INP_DIS)
/* LCD Common or Segment Drive */
#define UC_LCD_COM_SEG            (* (reg8 *) UC__LCD_COM_SEG)
/* Enable Segment LCD */
#define UC_LCD_EN                 (* (reg8 *) UC__LCD_EN)
/* Slew Rate Control */
#define UC_SLW                    (* (reg8 *) UC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UC_PRTDSI__CAPS_SEL       (* (reg8 *) UC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UC_PRTDSI__OE_SEL0        (* (reg8 *) UC__PRTDSI__OE_SEL0) 
#define UC_PRTDSI__OE_SEL1        (* (reg8 *) UC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UC_PRTDSI__OUT_SEL0       (* (reg8 *) UC__PRTDSI__OUT_SEL0) 
#define UC_PRTDSI__OUT_SEL1       (* (reg8 *) UC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UC_PRTDSI__SYNC_OUT       (* (reg8 *) UC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(UC__SIO_CFG)
    #define UC_SIO_HYST_EN        (* (reg8 *) UC__SIO_HYST_EN)
    #define UC_SIO_REG_HIFREQ     (* (reg8 *) UC__SIO_REG_HIFREQ)
    #define UC_SIO_CFG            (* (reg8 *) UC__SIO_CFG)
    #define UC_SIO_DIFF           (* (reg8 *) UC__SIO_DIFF)
#endif /* (UC__SIO_CFG) */

/* Interrupt Registers */
#if defined(UC__INTSTAT)
    #define UC_INTSTAT            (* (reg8 *) UC__INTSTAT)
    #define UC_SNAP               (* (reg8 *) UC__SNAP)
    
	#define UC_0_INTTYPE_REG 		(* (reg8 *) UC__0__INTTYPE)
#endif /* (UC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UC_H */


/* [] END OF FILE */
