/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Group31_ProjectWork_EmbeddedSystem_types.h
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

#ifndef Group31_ProjectWork_EmbeddedSystem_types_h_
#define Group31_ProjectWork_EmbeddedSystem_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_GSKovyH6bCN42HwFzVB4DE
#define struct_tag_GSKovyH6bCN42HwFzVB4DE

struct tag_GSKovyH6bCN42HwFzVB4DE
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_GSKovyH6bCN42HwFzVB4DE */

#ifndef typedef_stm32cube_blocks_DigitalPortR_T
#define typedef_stm32cube_blocks_DigitalPortR_T

typedef struct tag_GSKovyH6bCN42HwFzVB4DE stm32cube_blocks_DigitalPortR_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortR_T */

#ifndef struct_tag_tsKyPuhWUdS8zBSeRGR2aC
#define struct_tag_tsKyPuhWUdS8zBSeRGR2aC

struct tag_tsKyPuhWUdS8zBSeRGR2aC
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_tsKyPuhWUdS8zBSeRGR2aC */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_tsKyPuhWUdS8zBSeRGR2aC stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Custom Type definition for MATLABSystem: '<S25>/PWM Output' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_0RzKA0TA5eXyA1b3sjyvMG
#define struct_tag_0RzKA0TA5eXyA1b3sjyvMG

struct tag_0RzKA0TA5eXyA1b3sjyvMG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_0RzKA0TA5eXyA1b3sjyvMG */

#ifndef typedef_stm32cube_blocks_PWMOutput_Gr_T
#define typedef_stm32cube_blocks_PWMOutput_Gr_T

typedef struct tag_0RzKA0TA5eXyA1b3sjyvMG stm32cube_blocks_PWMOutput_Gr_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_Gr_T */

#ifndef struct_tag_pHyhMvD6ZfrUQVn8c5yClC
#define struct_tag_pHyhMvD6ZfrUQVn8c5yClC

struct tag_pHyhMvD6ZfrUQVn8c5yClC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_pHyhMvD6ZfrUQVn8c5yClC */

#ifndef typedef_stm32cube_blocks_UARTRead_Gro_T
#define typedef_stm32cube_blocks_UARTRead_Gro_T

typedef struct tag_pHyhMvD6ZfrUQVn8c5yClC stm32cube_blocks_UARTRead_Gro_T;

#endif                             /* typedef_stm32cube_blocks_UARTRead_Gro_T */

#ifndef struct_tag_Iq1q13TLZGLVDFrOgJGfXH
#define struct_tag_Iq1q13TLZGLVDFrOgJGfXH

struct tag_Iq1q13TLZGLVDFrOgJGfXH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_Iq1q13TLZGLVDFrOgJGfXH */

#ifndef typedef_stm32cube_blocks_UARTWrite_Gr_T
#define typedef_stm32cube_blocks_UARTWrite_Gr_T

typedef struct tag_Iq1q13TLZGLVDFrOgJGfXH stm32cube_blocks_UARTWrite_Gr_T;

#endif                             /* typedef_stm32cube_blocks_UARTWrite_Gr_T */

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_Group31_Proje_T
#define typedef_emxArray_char_T_Group31_Proje_T

typedef struct emxArray_char_T emxArray_char_T_Group31_Proje_T;

#endif                             /* typedef_emxArray_char_T_Group31_Proje_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_Group31_ProjectWork_E_T RT_MODEL_Group31_ProjectWork__T;

#endif                         /* Group31_ProjectWork_EmbeddedSystem_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
