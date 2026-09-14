/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Group31_ProjectWork_EmbeddedSystem.h
 *
 * Code generated for Simulink model 'Group31_ProjectWork_EmbeddedSystem'.
 *
 * Model version                  : 1.830
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Aug 14 18:43:05 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Group31_ProjectWork_EmbeddedSystem_h_
#define Group31_ProjectWork_EmbeddedSystem_h_
#ifndef Group31_ProjectWork_EmbeddedSystem_COMMON_INCLUDES_
#define Group31_ProjectWork_EmbeddedSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "main.h"
#include "stm_lpuart.h"
#endif                 /* Group31_ProjectWork_EmbeddedSystem_COMMON_INCLUDES_ */

#include "Group31_ProjectWork_EmbeddedSystem_types.h"
#include "rt_zcfcn.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define Group31_ProjectWork_EmbeddedSystem_M (Group31_ProjectWork_Embedded_M)

/* Block signals (default storage) */
typedef struct {
  char_T printVen[256];
  char_T ASCIItoString[256];           /* '<Root>/ASCII to String' */
  char_T msgOut[256];                  /* '<Root>/Chart' */
  real_T ledR;                         /* '<Root>/Chart' */
  real_T ledG;                         /* '<Root>/Chart' */
  real_T ledB;                         /* '<Root>/Chart' */
  real_T led_utente;                   /* '<Root>/Chart' */
  real_T duty_cycle;                   /* '<Root>/Chart' */
  real_T rele_luci;                    /* '<Root>/Chart' */
} B_Group31_ProjectWork_Embedde_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTRead_Gro_T obj; /* '<Root>/UART//USART Read' */
  stm32cube_blocks_UARTWrite_Gr_T obj_n;/* '<Root>/UART//USART Write' */
  stm32cube_blocks_PWMOutput_Gr_T obj_b;/* '<S25>/PWM Output' */
  stm32cube_blocks_PWMOutput_Gr_T obj_i;/* '<S23>/PWM Output' */
  real_T temperatura;                  /* '<Root>/Chart' */
  real_T durata_luci;                  /* '<Root>/Chart' */
  real_T angolo;                       /* '<Root>/Chart' */
  real_T prima_attivazione;            /* '<Root>/Chart' */
  real_T mod_luci;                     /* '<Root>/Chart' */
  real_T config_comp_mod_luci;         /* '<Root>/Chart' */
  real_T config_comp_durata_luci;      /* '<Root>/Chart' */
  real_T config_comp_temp;             /* '<Root>/Chart' */
  real_T config_comp_ven;              /* '<Root>/Chart' */
  real_T i;                            /* '<Root>/Chart' */
  real_T config_comp_init;             /* '<Root>/Chart' */
  char_T uartMsg[256];                 /* '<Root>/Chart' */
  char_T strTemperatura[256];          /* '<Root>/Chart' */
  char_T strAngolo[256];               /* '<Root>/Chart' */
  uint32_T temporalCounter_i2;         /* '<Root>/Chart' */
  uint8_T is_active_c3_Group31_ProjectWor;/* '<Root>/Chart' */
  uint8_T is_Group31_ProjectWork_Embedded;/* '<Root>/Chart' */
  uint8_T is_MAIN;                     /* '<Root>/Chart' */
  uint8_T is_CONFIGURAZIONE;           /* '<Root>/Chart' */
  uint8_T tp_MENU;                     /* '<Root>/Chart' */
  uint8_T is_LUCI;                     /* '<Root>/Chart' */
  uint8_T is_LED_UTENTE;               /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  uint8_T temporalCounter_i3;          /* '<Root>/Chart' */
  uint8_T previousZC;                  /* '<Root>/Chart' */
  uint8_T previousZC_d;                /* '<Root>/Chart' */
  uint8_T previousZC_i;                /* '<Root>/Chart' */
  uint8_T previousZC_m;                /* '<Root>/Chart' */
  uint8_T previousZC_l;                /* '<Root>/Chart' */
  uint8_T previousZC_h;                /* '<Root>/Chart' */
  uint8_T previousZC_f;                /* '<Root>/Chart' */
  uint8_T previousZC_n;                /* '<Root>/Chart' */
  uint8_T previousZC_fx;               /* '<Root>/Chart' */
  uint8_T previousZC_a;                /* '<Root>/Chart' */
  uint8_T previousZC_aw;               /* '<Root>/Chart' */
} DW_Group31_ProjectWork_Embedd_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SFunction_edgeDetectionSignal_Z;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetectionSignal_h;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetectionSigna_ha;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetectionSign_ha5;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetectionSig_ha50;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetectionSi_ha50t;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetectionS_ha50ta;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetection_ha50tat;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetectio_ha50tato;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetecti_ha50tatof;/* '<Root>/Chart' */
  ZCSigState SFunction_edgeDetect_ha50tatof1;/* '<Root>/Chart' */
} PrevZCX_Group31_ProjectWork_E_T;

/* Real-time Model Data Structure */
struct tag_RTM_Group31_ProjectWork_E_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Group31_ProjectWork_Embedde_T Group31_ProjectWork_EmbeddedS_B;

/* Block states (default storage) */
extern DW_Group31_ProjectWork_Embedd_T Group31_ProjectWork_Embedded_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Group31_ProjectWork_E_T Group31_ProjectWork_Emb_PrevZCX;

/* Model entry point functions */
extern void Group31_ProjectWork_EmbeddedSystem_initialize(void);
extern void Group31_ProjectWork_EmbeddedSystem_step(void);
extern void Group31_ProjectWork_EmbeddedSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Group31_ProjectWork__T *const Group31_ProjectWork_Embedded_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Group31_ProjectWork_EmbeddedSystem'
 * '<S1>'   : 'Group31_ProjectWork_EmbeddedSystem/Chart'
 * '<S2>'   : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read'
 * '<S3>'   : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read1'
 * '<S4>'   : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read2'
 * '<S5>'   : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read3'
 * '<S6>'   : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Write'
 * '<S7>'   : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Write1'
 * '<S8>'   : 'Group31_ProjectWork_EmbeddedSystem/PWM Output'
 * '<S9>'   : 'Group31_ProjectWork_EmbeddedSystem/PWM Output3'
 * '<S10>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read/ECSoC'
 * '<S11>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S12>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read1/ECSoC'
 * '<S13>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S14>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read2/ECSoC'
 * '<S15>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S16>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read3/ECSoC'
 * '<S17>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Read3/ECSoC/ECSimCodegen'
 * '<S18>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Write/ECSoC'
 * '<S19>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S20>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Write1/ECSoC'
 * '<S21>'  : 'Group31_ProjectWork_EmbeddedSystem/Digital Port Write1/ECSoC/ECSimCodegen'
 * '<S22>'  : 'Group31_ProjectWork_EmbeddedSystem/PWM Output/ECSoC'
 * '<S23>'  : 'Group31_ProjectWork_EmbeddedSystem/PWM Output/ECSoC/ECSimCodegen'
 * '<S24>'  : 'Group31_ProjectWork_EmbeddedSystem/PWM Output3/ECSoC'
 * '<S25>'  : 'Group31_ProjectWork_EmbeddedSystem/PWM Output3/ECSoC/ECSimCodegen'
 */
#endif                               /* Group31_ProjectWork_EmbeddedSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
