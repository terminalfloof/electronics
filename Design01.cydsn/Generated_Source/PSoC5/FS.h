/*******************************************************************************
* File Name: FS.h  
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

#if !defined(CY_PINS_FS_H) /* Pins FS_H */
#define CY_PINS_FS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FS__PORT == 15 && ((FS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    FS_Write(uint8 value);
void    FS_SetDriveMode(uint8 mode);
uint8   FS_ReadDataReg(void);
uint8   FS_Read(void);
void    FS_SetInterruptMode(uint16 position, uint16 mode);
uint8   FS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the FS_SetDriveMode() function.
     *  @{
     */
        #define FS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define FS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define FS_DM_RES_UP          PIN_DM_RES_UP
        #define FS_DM_RES_DWN         PIN_DM_RES_DWN
        #define FS_DM_OD_LO           PIN_DM_OD_LO
        #define FS_DM_OD_HI           PIN_DM_OD_HI
        #define FS_DM_STRONG          PIN_DM_STRONG
        #define FS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define FS_MASK               FS__MASK
#define FS_SHIFT              FS__SHIFT
#define FS_WIDTH              1u

/* Interrupt constants */
#if defined(FS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FS_SetInterruptMode() function.
     *  @{
     */
        #define FS_INTR_NONE      (uint16)(0x0000u)
        #define FS_INTR_RISING    (uint16)(0x0001u)
        #define FS_INTR_FALLING   (uint16)(0x0002u)
        #define FS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define FS_INTR_MASK      (0x01u) 
#endif /* (FS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FS_PS                     (* (reg8 *) FS__PS)
/* Data Register */
#define FS_DR                     (* (reg8 *) FS__DR)
/* Port Number */
#define FS_PRT_NUM                (* (reg8 *) FS__PRT) 
/* Connect to Analog Globals */                                                  
#define FS_AG                     (* (reg8 *) FS__AG)                       
/* Analog MUX bux enable */
#define FS_AMUX                   (* (reg8 *) FS__AMUX) 
/* Bidirectional Enable */                                                        
#define FS_BIE                    (* (reg8 *) FS__BIE)
/* Bit-mask for Aliased Register Access */
#define FS_BIT_MASK               (* (reg8 *) FS__BIT_MASK)
/* Bypass Enable */
#define FS_BYP                    (* (reg8 *) FS__BYP)
/* Port wide control signals */                                                   
#define FS_CTL                    (* (reg8 *) FS__CTL)
/* Drive Modes */
#define FS_DM0                    (* (reg8 *) FS__DM0) 
#define FS_DM1                    (* (reg8 *) FS__DM1)
#define FS_DM2                    (* (reg8 *) FS__DM2) 
/* Input Buffer Disable Override */
#define FS_INP_DIS                (* (reg8 *) FS__INP_DIS)
/* LCD Common or Segment Drive */
#define FS_LCD_COM_SEG            (* (reg8 *) FS__LCD_COM_SEG)
/* Enable Segment LCD */
#define FS_LCD_EN                 (* (reg8 *) FS__LCD_EN)
/* Slew Rate Control */
#define FS_SLW                    (* (reg8 *) FS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FS_PRTDSI__CAPS_SEL       (* (reg8 *) FS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FS_PRTDSI__OE_SEL0        (* (reg8 *) FS__PRTDSI__OE_SEL0) 
#define FS_PRTDSI__OE_SEL1        (* (reg8 *) FS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FS_PRTDSI__OUT_SEL0       (* (reg8 *) FS__PRTDSI__OUT_SEL0) 
#define FS_PRTDSI__OUT_SEL1       (* (reg8 *) FS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FS_PRTDSI__SYNC_OUT       (* (reg8 *) FS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(FS__SIO_CFG)
    #define FS_SIO_HYST_EN        (* (reg8 *) FS__SIO_HYST_EN)
    #define FS_SIO_REG_HIFREQ     (* (reg8 *) FS__SIO_REG_HIFREQ)
    #define FS_SIO_CFG            (* (reg8 *) FS__SIO_CFG)
    #define FS_SIO_DIFF           (* (reg8 *) FS__SIO_DIFF)
#endif /* (FS__SIO_CFG) */

/* Interrupt Registers */
#if defined(FS__INTSTAT)
    #define FS_INTSTAT            (* (reg8 *) FS__INTSTAT)
    #define FS_SNAP               (* (reg8 *) FS__SNAP)
    
	#define FS_0_INTTYPE_REG 		(* (reg8 *) FS__0__INTTYPE)
#endif /* (FS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FS_H */


/* [] END OF FILE */
