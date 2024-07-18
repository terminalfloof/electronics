/*******************************************************************************
* File Name: DS.h  
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

#if !defined(CY_PINS_DS_H) /* Pins DS_H */
#define CY_PINS_DS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DS__PORT == 15 && ((DS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DS_Write(uint8 value);
void    DS_SetDriveMode(uint8 mode);
uint8   DS_ReadDataReg(void);
uint8   DS_Read(void);
void    DS_SetInterruptMode(uint16 position, uint16 mode);
uint8   DS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DS_SetDriveMode() function.
     *  @{
     */
        #define DS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DS_DM_RES_UP          PIN_DM_RES_UP
        #define DS_DM_RES_DWN         PIN_DM_RES_DWN
        #define DS_DM_OD_LO           PIN_DM_OD_LO
        #define DS_DM_OD_HI           PIN_DM_OD_HI
        #define DS_DM_STRONG          PIN_DM_STRONG
        #define DS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DS_MASK               DS__MASK
#define DS_SHIFT              DS__SHIFT
#define DS_WIDTH              1u

/* Interrupt constants */
#if defined(DS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DS_SetInterruptMode() function.
     *  @{
     */
        #define DS_INTR_NONE      (uint16)(0x0000u)
        #define DS_INTR_RISING    (uint16)(0x0001u)
        #define DS_INTR_FALLING   (uint16)(0x0002u)
        #define DS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DS_INTR_MASK      (0x01u) 
#endif /* (DS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DS_PS                     (* (reg8 *) DS__PS)
/* Data Register */
#define DS_DR                     (* (reg8 *) DS__DR)
/* Port Number */
#define DS_PRT_NUM                (* (reg8 *) DS__PRT) 
/* Connect to Analog Globals */                                                  
#define DS_AG                     (* (reg8 *) DS__AG)                       
/* Analog MUX bux enable */
#define DS_AMUX                   (* (reg8 *) DS__AMUX) 
/* Bidirectional Enable */                                                        
#define DS_BIE                    (* (reg8 *) DS__BIE)
/* Bit-mask for Aliased Register Access */
#define DS_BIT_MASK               (* (reg8 *) DS__BIT_MASK)
/* Bypass Enable */
#define DS_BYP                    (* (reg8 *) DS__BYP)
/* Port wide control signals */                                                   
#define DS_CTL                    (* (reg8 *) DS__CTL)
/* Drive Modes */
#define DS_DM0                    (* (reg8 *) DS__DM0) 
#define DS_DM1                    (* (reg8 *) DS__DM1)
#define DS_DM2                    (* (reg8 *) DS__DM2) 
/* Input Buffer Disable Override */
#define DS_INP_DIS                (* (reg8 *) DS__INP_DIS)
/* LCD Common or Segment Drive */
#define DS_LCD_COM_SEG            (* (reg8 *) DS__LCD_COM_SEG)
/* Enable Segment LCD */
#define DS_LCD_EN                 (* (reg8 *) DS__LCD_EN)
/* Slew Rate Control */
#define DS_SLW                    (* (reg8 *) DS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DS_PRTDSI__CAPS_SEL       (* (reg8 *) DS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DS_PRTDSI__OE_SEL0        (* (reg8 *) DS__PRTDSI__OE_SEL0) 
#define DS_PRTDSI__OE_SEL1        (* (reg8 *) DS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DS_PRTDSI__OUT_SEL0       (* (reg8 *) DS__PRTDSI__OUT_SEL0) 
#define DS_PRTDSI__OUT_SEL1       (* (reg8 *) DS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DS_PRTDSI__SYNC_OUT       (* (reg8 *) DS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DS__SIO_CFG)
    #define DS_SIO_HYST_EN        (* (reg8 *) DS__SIO_HYST_EN)
    #define DS_SIO_REG_HIFREQ     (* (reg8 *) DS__SIO_REG_HIFREQ)
    #define DS_SIO_CFG            (* (reg8 *) DS__SIO_CFG)
    #define DS_SIO_DIFF           (* (reg8 *) DS__SIO_DIFF)
#endif /* (DS__SIO_CFG) */

/* Interrupt Registers */
#if defined(DS__INTSTAT)
    #define DS_INTSTAT            (* (reg8 *) DS__INTSTAT)
    #define DS_SNAP               (* (reg8 *) DS__SNAP)
    
	#define DS_0_INTTYPE_REG 		(* (reg8 *) DS__0__INTTYPE)
#endif /* (DS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DS_H */


/* [] END OF FILE */
