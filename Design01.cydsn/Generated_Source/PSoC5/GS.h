/*******************************************************************************
* File Name: GS.h  
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

#if !defined(CY_PINS_GS_H) /* Pins GS_H */
#define CY_PINS_GS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 GS__PORT == 15 && ((GS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    GS_Write(uint8 value);
void    GS_SetDriveMode(uint8 mode);
uint8   GS_ReadDataReg(void);
uint8   GS_Read(void);
void    GS_SetInterruptMode(uint16 position, uint16 mode);
uint8   GS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the GS_SetDriveMode() function.
     *  @{
     */
        #define GS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define GS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define GS_DM_RES_UP          PIN_DM_RES_UP
        #define GS_DM_RES_DWN         PIN_DM_RES_DWN
        #define GS_DM_OD_LO           PIN_DM_OD_LO
        #define GS_DM_OD_HI           PIN_DM_OD_HI
        #define GS_DM_STRONG          PIN_DM_STRONG
        #define GS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define GS_MASK               GS__MASK
#define GS_SHIFT              GS__SHIFT
#define GS_WIDTH              1u

/* Interrupt constants */
#if defined(GS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in GS_SetInterruptMode() function.
     *  @{
     */
        #define GS_INTR_NONE      (uint16)(0x0000u)
        #define GS_INTR_RISING    (uint16)(0x0001u)
        #define GS_INTR_FALLING   (uint16)(0x0002u)
        #define GS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define GS_INTR_MASK      (0x01u) 
#endif /* (GS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GS_PS                     (* (reg8 *) GS__PS)
/* Data Register */
#define GS_DR                     (* (reg8 *) GS__DR)
/* Port Number */
#define GS_PRT_NUM                (* (reg8 *) GS__PRT) 
/* Connect to Analog Globals */                                                  
#define GS_AG                     (* (reg8 *) GS__AG)                       
/* Analog MUX bux enable */
#define GS_AMUX                   (* (reg8 *) GS__AMUX) 
/* Bidirectional Enable */                                                        
#define GS_BIE                    (* (reg8 *) GS__BIE)
/* Bit-mask for Aliased Register Access */
#define GS_BIT_MASK               (* (reg8 *) GS__BIT_MASK)
/* Bypass Enable */
#define GS_BYP                    (* (reg8 *) GS__BYP)
/* Port wide control signals */                                                   
#define GS_CTL                    (* (reg8 *) GS__CTL)
/* Drive Modes */
#define GS_DM0                    (* (reg8 *) GS__DM0) 
#define GS_DM1                    (* (reg8 *) GS__DM1)
#define GS_DM2                    (* (reg8 *) GS__DM2) 
/* Input Buffer Disable Override */
#define GS_INP_DIS                (* (reg8 *) GS__INP_DIS)
/* LCD Common or Segment Drive */
#define GS_LCD_COM_SEG            (* (reg8 *) GS__LCD_COM_SEG)
/* Enable Segment LCD */
#define GS_LCD_EN                 (* (reg8 *) GS__LCD_EN)
/* Slew Rate Control */
#define GS_SLW                    (* (reg8 *) GS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GS_PRTDSI__CAPS_SEL       (* (reg8 *) GS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GS_PRTDSI__OE_SEL0        (* (reg8 *) GS__PRTDSI__OE_SEL0) 
#define GS_PRTDSI__OE_SEL1        (* (reg8 *) GS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GS_PRTDSI__OUT_SEL0       (* (reg8 *) GS__PRTDSI__OUT_SEL0) 
#define GS_PRTDSI__OUT_SEL1       (* (reg8 *) GS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GS_PRTDSI__SYNC_OUT       (* (reg8 *) GS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(GS__SIO_CFG)
    #define GS_SIO_HYST_EN        (* (reg8 *) GS__SIO_HYST_EN)
    #define GS_SIO_REG_HIFREQ     (* (reg8 *) GS__SIO_REG_HIFREQ)
    #define GS_SIO_CFG            (* (reg8 *) GS__SIO_CFG)
    #define GS_SIO_DIFF           (* (reg8 *) GS__SIO_DIFF)
#endif /* (GS__SIO_CFG) */

/* Interrupt Registers */
#if defined(GS__INTSTAT)
    #define GS_INTSTAT            (* (reg8 *) GS__INTSTAT)
    #define GS_SNAP               (* (reg8 *) GS__SNAP)
    
	#define GS_0_INTTYPE_REG 		(* (reg8 *) GS__0__INTTYPE)
#endif /* (GS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_GS_H */


/* [] END OF FILE */
