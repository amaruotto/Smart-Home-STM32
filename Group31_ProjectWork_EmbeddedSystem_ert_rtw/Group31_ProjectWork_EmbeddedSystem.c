/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Group31_ProjectWork_EmbeddedSystem.c
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

#include "Group31_ProjectWork_EmbeddedSystem.h"
#include "rtwtypes.h"
#include "Group31_ProjectWork_EmbeddedSystem_types.h"
#include <string.h>
#include <math.h>
#include "stm_timer_ll.h"
#include <stdlib.h>
#include <stddef.h>

/* Named constants for Chart: '<Root>/Chart' */
#define Gr_IN_CONFIGURAZIONE_COMPLETATA ((uint8_T)1U)
#define Group31_Pr_IN_LUCI_TEMPORIZZATE ((uint8_T)3U)
#define Group31_Pro_IN_ErrorTemperatura ((uint8_T)4U)
#define Group31_Pro_IN_setModalitaLuci1 ((uint8_T)12U)
#define Group31_Proj_IN_ErrorDurataLuci ((uint8_T)2U)
#define Group31_Proj_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Group31_Proj_IN_setModalitaLuci ((uint8_T)11U)
#define Group31_Proj_IN_setTemperatura1 ((uint8_T)14U)
#define Group31_Proje_IN_CONFIGURAZIONE ((uint8_T)1U)
#define Group31_Proje_IN_ErrorVeneziane ((uint8_T)5U)
#define Group31_Proje_IN_setDurataLuci1 ((uint8_T)10U)
#define Group31_Proje_IN_setTemperatura ((uint8_T)13U)
#define Group31_Projec_IN_setDurataLuci ((uint8_T)9U)
#define Group31_Projec_IN_setVeneziane1 ((uint8_T)16U)
#define Group31_ProjectW_IN_LUCI_ACCESE ((uint8_T)1U)
#define Group31_ProjectW_IN_LUCI_SPENTE ((uint8_T)2U)
#define Group31_ProjectWo_IN_OPERAZIONE ((uint8_T)2U)
#define Group31_ProjectWor_IN_PRECONFIG ((uint8_T)8U)
#define Group31_ProjectWork_E_IN_ACCESO ((uint8_T)1U)
#define Group31_ProjectWork_E_IN_ATTIVO ((uint8_T)1U)
#define Group31_ProjectWork_E_IN_SPENTO ((uint8_T)2U)
#define Group31_ProjectWork_Em_IN_CLEAR ((uint8_T)2U)
#define Group31_ProjectWork_Emb_IN_INIT ((uint8_T)6U)
#define Group31_ProjectWork_Emb_IN_MENU ((uint8_T)7U)
#define Group31_ProjectWork_IN_INATTIVO ((uint8_T)3U)
#define Group31_Project_IN_ErrorModLuci ((uint8_T)3U)
#define Group31_Project_IN_setVeneziane ((uint8_T)15U)

/* Block signals (default storage) */
B_Group31_ProjectWork_Embedde_T Group31_ProjectWork_EmbeddedS_B;

/* Block states (default storage) */
DW_Group31_ProjectWork_Embedd_T Group31_ProjectWork_Embedded_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Group31_ProjectWork_E_T Group31_ProjectWork_Emb_PrevZCX;

/* Real-time model */
static RT_MODEL_Group31_ProjectWork__T Group31_ProjectWork_Embedded_M_;
RT_MODEL_Group31_ProjectWork__T *const Group31_ProjectWork_Embedded_M =
  &Group31_ProjectWork_Embedded_M_;

/* Forward declaration for local functions */
static void Group31_ProjectW_emxInit_char_T(emxArray_char_T_Group31_Proje_T
  **pEmxArray, int32_T numDimensions);
static void Group3_emxEnsureCapacity_char_T(emxArray_char_T_Group31_Proje_T
  *emxArray, int32_T oldNumel);
static void Group31_ProjectWork_Em_notifica(const
  emxArray_char_T_Group31_Proje_T *printTemp_Value, const
  emxArray_char_T_Group31_Proje_T *printVen_Value, const char_T
  printLuci_Value_data[], const int32_T printLuci_Value_size[2],
  emxArray_char_T_Group31_Proje_T *msg_Value);
static void Group31_ProjectW_emxFree_char_T(emxArray_char_T_Group31_Proje_T
  **pEmxArray);
static void Group31_Proje_enter_atomic_NOT2(void);
static real_T Group31_ProjectWor_myStr2Double(const
  emxArray_char_T_Group31_Proje_T *str);
static real_T Group31_ProjectWork_E_applyConv(const
  emxArray_char_T_Group31_Proje_T *newChar_Value);
static void Group31_ProjectWo_setVeneziane1(const uint32_T *UARTUSARTRead_o2);
static void Group31_ProjectWork_Embedd_MENU(const uint32_T *UARTUSARTRead_o2);
static real_T Group31_Projec_configDurataLuci(const
  emxArray_char_T_Group31_Proje_T *msg_Value);
static void Gro_enter_atomic_setDurataLuci1(void);
static void Group31_ProjectW_setDurataLuci1(const uint32_T *UARTUSARTRead_o2);
static real_T Group31_ProjectWo_configModLuci(const
  emxArray_char_T_Group31_Proje_T *msg_Value);
static void Group31_Project_setModalitaLuci(const uint32_T *UARTUSARTRead_o2);
static void Group31_Projec_setModalitaLuci1(const uint32_T *UARTUSARTRead_o2);
static real_T Group31_Proje_configTemperatura(const
  emxArray_char_T_Group31_Proje_T *msg_Value);
static void Gr_enter_atomic_setTemperatura1(void);
static void Group31_Project_setTemperatura1(const uint32_T *UARTUSARTRead_o2);
static real_T Group31_Project_configVeneziane(const
  emxArray_char_T_Group31_Proje_T *msg_Value);
static void Group31_ProjectWor_setVeneziane(const uint32_T *UARTUSARTRead_o2);
static void Gr_exit_internal_CONFIGURAZIONE(void);
static void Group31_ProjectWo_opTemperatura(real_T temperatura, real_T *ledR,
  real_T *ledG, real_T *ledB);
static real_T Group31_ProjectWork_opVeneziane(real_T angolo);
static void Group31_ProjectW_CONFIGURAZIONE(const uint32_T *UARTUSARTRead_o2);
static void Group31_Projec_SystemCore_setup(stm32cube_blocks_UARTRead_Gro_T *obj);
static void Group31_Pro_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_Gr_T *obj);
static void Group31_Pro_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Gr_T *obj);
static void Group31_P_PWMOutput_setupImpl_p(stm32cube_blocks_PWMOutput_Gr_T *obj);
static boolean_T resultZC0;
static boolean_T resultZC1;
static boolean_T resultZC10;
static boolean_T resultZC2;
static boolean_T resultZC3;
static boolean_T resultZC4;
static boolean_T resultZC5;
static boolean_T resultZC6;
static boolean_T resultZC7;
static boolean_T resultZC8;
static boolean_T resultZC9;
static void Group31_ProjectW_emxInit_char_T(emxArray_char_T_Group31_Proje_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Group31_Proje_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Group31_Proje_T *)malloc(sizeof
    (emxArray_char_T_Group31_Proje_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Group3_emxEnsureCapacity_char_T(emxArray_char_T_Group31_Proje_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_ProjectWork_Em_notifica(const
  emxArray_char_T_Group31_Proje_T *printTemp_Value, const
  emxArray_char_T_Group31_Proje_T *printVen_Value, const char_T
  printLuci_Value_data[], const int32_T printLuci_Value_size[2],
  emxArray_char_T_Group31_Proje_T *msg_Value)
{
  int32_T i;
  int32_T loop_ub;
  static const char_T b[31] = { '\r', '\n', '=', '=', '=', ' ', 'S', 'T', 'A',
    'T', 'U', 'S', ' ', '=', '=', '=', '\r', '\n', 'T', 'e', 'm', 'p', 'e', 'r',
    'a', 't', 'u', 'r', 'a', ':', ' ' };

  static const char_T e[11] = { 'V', 'e', 'n', 'e', 'z', 'i', 'a', 'n', 'e', ':',
    ' ' };

  static const char_T f[6] = { 'L', 'u', 'c', 'i', ':', ' ' };

  int32_T i_0;
  i_0 = msg_Value->size[0] * msg_Value->size[1];
  msg_Value->size[0] = 1;
  i = printTemp_Value->size[1] + printVen_Value->size[1];
  msg_Value->size[1] = (i + printLuci_Value_size[1]) + 54;
  Group3_emxEnsureCapacity_char_T(msg_Value, i_0);
  for (i_0 = 0; i_0 < 31; i_0++) {
    msg_Value->data[i_0] = b[i_0];
  }

  loop_ub = printTemp_Value->size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&msg_Value->data[31], &printTemp_Value->data[0], (uint32_T)loop_ub *
           sizeof(char_T));
  }

  msg_Value->data[printTemp_Value->size[1] + 31] = ' ';
  msg_Value->data[printTemp_Value->size[1] + 33] = '\r';
  msg_Value->data[printTemp_Value->size[1] + 32] = 'C';
  msg_Value->data[printTemp_Value->size[1] + 34] = '\n';
  for (i_0 = 0; i_0 < 11; i_0++) {
    msg_Value->data[(i_0 + printTemp_Value->size[1]) + 35] = e[i_0];
  }

  loop_ub = printVen_Value->size[1];
  for (i_0 = 0; i_0 < loop_ub; i_0++) {
    msg_Value->data[(i_0 + printTemp_Value->size[1]) + 46] =
      printVen_Value->data[i_0];
  }

  msg_Value->data[i + 46] = '\r';
  msg_Value->data[i + 47] = '\n';
  for (i = 0; i < 6; i++) {
    msg_Value->data[((i + printTemp_Value->size[1]) + printVen_Value->size[1]) +
      48] = f[i];
  }

  loop_ub = printLuci_Value_size[1];
  for (i = 0; i < loop_ub; i++) {
    msg_Value->data[((i + printTemp_Value->size[1]) + printVen_Value->size[1]) +
      54] = printLuci_Value_data[i];
  }
}

static void Group31_ProjectW_emxFree_char_T(emxArray_char_T_Group31_Proje_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Group31_Proje_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Group31_Proje_T *)NULL;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_Proje_enter_atomic_NOT2(void)
{
  emxArray_char_T_Group31_Proje_T *c_Value;
  emxArray_char_T_Group31_Proje_T *d_Value;
  emxArray_char_T_Group31_Proje_T *f_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  int32_T loop_ub;
  char_T printLuci[7];
  char_T h_Value_data[6];
  static const char_T k_Value[6] = { 'C', 'H', 'I', 'U', 'S', 'E' };

  static const char_T l_Value[6] = { 'A', 'P', 'E', 'R', 'T', 'E' };

  static const char_T o[31] = { 'A', 'P', 'E', 'R', 'T', 'E', ' ', 'P', 'A', 'R',
    'Z', 'I', 'A', 'L', 'M', 'E', 'N', 'T', 'E', ' ', 'c', 'o', 'n', ' ', 'P',
    'r', 'e', 's', 'e', 't', ' ' };

  static const char_T m_Value[6] = { 'S', 'P', 'E', 'N', 'T', 'E' };

  static const char_T n_Value[6] = { 'A', 'C', 'C', 'E', 'S', 'E' };

  int32_T h_Value_size[2];
  Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
  Group31_ProjectW_emxInit_char_T(&c_Value, 2);
  if (Group31_ProjectWork_Embedded_DW.angolo == 0.0) {
    strncpy(&Group31_ProjectWork_EmbeddedS_B.printVen[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.printVen[255] = '\x00';
    for (b = 0; b < 6; b++) {
      Group31_ProjectWork_EmbeddedS_B.printVen[b] = k_Value[b];
    }

    Group31_ProjectWork_EmbeddedS_B.printVen[6] = '\x00';
  } else if (Group31_ProjectWork_Embedded_DW.angolo == 9.0) {
    strncpy(&Group31_ProjectWork_EmbeddedS_B.printVen[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.printVen[255] = '\x00';
    for (b = 0; b < 6; b++) {
      Group31_ProjectWork_EmbeddedS_B.printVen[b] = l_Value[b];
    }

    Group31_ProjectWork_EmbeddedS_B.printVen[6] = '\x00';
  } else {
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.strAngolo[0]);
    loop_ub = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(obj_Value, loop_ub);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_Embedded_DW.strAngolo[0],
            (uint32_T)b);
    loop_ub = c_Value->size[0] * c_Value->size[1];
    c_Value->size[0] = 1;
    c_Value->size[1] = obj_Value->size[1] + 31;
    Group3_emxEnsureCapacity_char_T(c_Value, loop_ub);
    for (b = 0; b < 31; b++) {
      c_Value->data[b] = o[b];
    }

    loop_ub = obj_Value->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&c_Value->data[31], &obj_Value->data[0], (uint32_T)loop_ub * sizeof
             (char_T));
    }

    strncpy(&Group31_ProjectWork_EmbeddedS_B.printVen[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.printVen[255] = '\x00';
    if (c_Value->size[1] <= 255) {
      b = obj_Value->size[1] + 31;
    } else {
      b = 255;
    }

    if (b - 1 >= 0) {
      memcpy(&Group31_ProjectWork_EmbeddedS_B.printVen[0], &c_Value->data[0],
             (uint32_T)b * sizeof(char_T));
    }

    Group31_ProjectWork_EmbeddedS_B.printVen[b] = '\x00';
  }

  if ((Group31_ProjectWork_EmbeddedS_B.rele_luci == 1.0) ||
      (Group31_ProjectWork_Embedded_DW.mod_luci == 1.0)) {
    strncpy(&printLuci[0], "", 6U);
    for (b = 0; b < 6; b++) {
      printLuci[b] = n_Value[b];
    }

    printLuci[6] = '\x00';
  } else {
    strncpy(&printLuci[0], "", 6U);
    for (b = 0; b < 6; b++) {
      printLuci[b] = m_Value[b];
    }

    printLuci[6] = '\x00';
  }

  b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.strTemperatura[0]);
  Group31_ProjectW_emxInit_char_T(&d_Value, 2);
  loop_ub = d_Value->size[0] * d_Value->size[1];
  d_Value->size[0] = 1;
  d_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(d_Value, loop_ub);
  strncpy(&d_Value->data[0], &Group31_ProjectWork_Embedded_DW.strTemperatura[0],
          (uint32_T)b);
  b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.printVen[0]);
  Group31_ProjectW_emxInit_char_T(&f_Value, 2);
  loop_ub = f_Value->size[0] * f_Value->size[1];
  f_Value->size[0] = 1;
  f_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(f_Value, loop_ub);
  strncpy(&f_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.printVen[0],
          (uint32_T)b);
  b = (int32_T)strlen(&printLuci[0]);
  h_Value_size[0] = 1;
  h_Value_size[1] = b;
  strncpy(&h_Value_data[0], &printLuci[0], (uint32_T)b);
  Group31_ProjectWork_Em_notifica(d_Value, f_Value, h_Value_data, h_Value_size,
    c_Value);
  Group31_ProjectW_emxFree_char_T(&f_Value);
  Group31_ProjectW_emxFree_char_T(&d_Value);
  loop_ub = obj_Value->size[0] * obj_Value->size[1];
  obj_Value->size[0] = 1;
  obj_Value->size[1] = c_Value->size[1] + 4;
  Group3_emxEnsureCapacity_char_T(obj_Value, loop_ub);
  obj_Value->data[0] = '\r';
  obj_Value->data[1] = '\n';
  loop_ub = c_Value->size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Value->data[2], &c_Value->data[0], (uint32_T)loop_ub * sizeof
           (char_T));
  }

  obj_Value->data[c_Value->size[1] + 2] = '\r';
  obj_Value->data[c_Value->size[1] + 3] = '\n';
  strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
  Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
  if (obj_Value->size[1] <= 255) {
    b = c_Value->size[1] + 4;
  } else {
    b = 255;
  }

  Group31_ProjectW_emxFree_char_T(&c_Value);
  for (loop_ub = 0; loop_ub < b; loop_ub++) {
    Group31_ProjectWork_EmbeddedS_B.msgOut[loop_ub] = obj_Value->data[0 +
      loop_ub];
  }

  Group31_ProjectW_emxFree_char_T(&obj_Value);
  Group31_ProjectWork_EmbeddedS_B.msgOut[b] = '\x00';
}

/* Function for Chart: '<Root>/Chart' */
static real_T Group31_ProjectWor_myStr2Double(const
  emxArray_char_T_Group31_Proje_T *str)
{
  real_T val;
  int32_T b;
  int32_T i;
  val = 0.0;
  b = str->size[1];
  Group31_ProjectWork_Embedded_DW.i = 1.0;
  for (i = 0; i < b; i++) {
    Group31_ProjectWork_Embedded_DW.i = (real_T)i + 1.0;
    val = ((real_T)str->data[(int32_T)Group31_ProjectWork_Embedded_DW.i - 1] -
           48.0) + val * 10.0;
  }

  return val;
}

/* Function for Chart: '<Root>/Chart' */
static real_T Group31_ProjectWork_E_applyConv(const
  emxArray_char_T_Group31_Proje_T *newChar_Value)
{
  real_T newVal;
  newVal = Group31_ProjectWor_myStr2Double(newChar_Value);
  return newVal;
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_ProjectWo_setVeneziane1(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *c_Value;
  emxArray_char_T_Group31_Proje_T *e_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  boolean_T out;
  static const char_T h_Value[61] = { '\r', '\n', 'V', 'a', 'l', 'o', 'r', 'e',
    ' ', 'V', 'E', 'N', 'E', 'Z', 'I', 'A', 'N', 'E', ' ', 'n', 'o', 'n', ' ',
    'v', 'a', 'l', 'i', 'd', 'o', '.', '\r', '\n', 'P', 'r', 'e', 'm', 'i', ' ',
    'I', 'N', 'V', 'I', 'O', ' ', 'p', 'e', 'r', ' ', 'r', 'e', 'i', 'n', 's',
    'e', 'r', 'i', 'r', 'l', 'o', '\r', '\n' };

  static const char_T j_Value[102] = { '\r', '\n', '\r', '\n', '=', '=', '=',
    '=', ' ', 'M', 'E', 'N', 'U', ' ', '=', '=', '=', '=', '\r', '\n', '1', '.',
    ' ', 'L', 'u', 'c', 'i', ' ', 'O', 'N', '/', 'O', 'F', 'F', '\r', '\n', '2',
    '.', ' ', 'L', 'u', 'c', 'i', ' ', 'T', 'e', 'm', 'p', 'o', 'r', 'i', 'z',
    'z', 'a', 't', 'e', '\r', '\n', '3', '.', ' ', 'T', 'e', 'm', 'p', 'e', 'r',
    'a', 't', 'u', 'r', 'a', '\r', '\n', '4', '.', ' ', 'V', 'e', 'n', 'e', 'z',
    'i', 'a', 'n', 'e', '\r', '\n', 'P', 'r', 'e', 'm', 'i', ' ', 'C', 'O', 'N',
    'F', 'I', 'G', '\r', '\n' };

  static const char_T i_Value[106] = { '\r', '\n', '\r', '\n', 'C', 'o', 'n',
    'f', 'i', 'g', 'u', 'r', 'a', 'z', 'i', 'o', 'n', 'e', ' ', 'i', 'n', 'i',
    'z', 'i', 'a', 'l', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 't', 'a', 't',
    'a', '.', '\r', '\n', 'P', 'e', 'r', ' ', 'e', 'n', 't', 'r', 'a', 'r', 'e',
    ' ', 'n', 'e', 'l', 'l', 'a', ' ', 'm', 'o', 'd', 'a', 'l', 'i', 't', 'a',
    ' ', 'o', 'p', 'e', 'r', 'a', 't', 'i', 'v', 'a', ',', ' ', 'p', 'r', 'e',
    'm', 'e', 'r', 'e', ' ', 'i', 'l', ' ', 'p', 'u', 'l', 's', 'a', 'n', 't',
    'e', ' ', 'C', 'O', 'N', 'F', 'I', 'G', '.' };

  int32_T tmp;
  boolean_T guard1;
  if ((Group31_ProjectWork_Embedded_DW.config_comp_ven == 1.0) &&
      (*UARTUSARTRead_o2 > 0U)) {
    b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
    tmp = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString
            [0], (uint32_T)b);
    out = false;
    if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
      out = true;
    }

    Group31_ProjectW_emxFree_char_T(&obj_Value);
  } else {
    out = false;
  }

  Group31_ProjectW_emxInit_char_T(&c_Value, 2);
  Group31_ProjectW_emxInit_char_T(&e_Value, 2);
  Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
  guard1 = false;
  if (out) {
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    tmp = c_Value->size[0] * c_Value->size[1];
    c_Value->size[0] = 1;
    c_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(c_Value, tmp);
    strncpy(&c_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    Group31_ProjectWork_Embedded_DW.angolo = Group31_ProjectWork_E_applyConv
      (c_Value);
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    tmp = e_Value->size[0] * e_Value->size[1];
    e_Value->size[0] = 1;
    e_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(e_Value, tmp);
    strncpy(&e_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    strncpy(&Group31_ProjectWork_Embedded_DW.strAngolo[0], "", 255U);
    Group31_ProjectWork_Embedded_DW.strAngolo[255] = '\x00';
    if (e_Value->size[1] <= 255) {
      b = e_Value->size[1];
    } else {
      b = 255;
    }

    if (b - 1 >= 0) {
      memcpy(&Group31_ProjectWork_Embedded_DW.strAngolo[0], &e_Value->data[0],
             (uint32_T)b * sizeof(char_T));
    }

    Group31_ProjectWork_Embedded_DW.strAngolo[b] = '\x00';
    if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 0.0) {
      Group31_ProjectWork_Embedded_DW.tp_MENU = 1U;
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_ProjectWork_Emb_IN_MENU;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &j_Value[0], 102U *
             sizeof(char_T));
      Group31_ProjectWork_EmbeddedS_B.msgOut[102] = '\x00';
    } else if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 1.0) {
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Gr_IN_CONFIGURAZIONE_COMPLETATA;
      Group31_ProjectWork_Embedded_DW.config_comp_init = 1.0;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &i_Value[0], 106U *
             sizeof(char_T));
      Group31_ProjectWork_EmbeddedS_B.msgOut[106] = '\x00';
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if ((Group31_ProjectWork_Embedded_DW.config_comp_ven == 0.0) &&
        (*UARTUSARTRead_o2 > 0U)) {
      b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
      tmp = b_obj_Value->size[0] * b_obj_Value->size[1];
      b_obj_Value->size[0] = 1;
      b_obj_Value->size[1] = b;
      Group3_emxEnsureCapacity_char_T(b_obj_Value, tmp);
      strncpy(&b_obj_Value->data[0],
              &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
      out = false;
      if ((b_obj_Value->size[1] == 1) && (b_obj_Value->data[0] == '\r')) {
        out = true;
      }
    } else {
      out = false;
    }

    if (out) {
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_Proje_IN_ErrorVeneziane;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      for (b = 0; b < 61; b++) {
        Group31_ProjectWork_EmbeddedS_B.msgOut[b] = h_Value[b];
      }

      Group31_ProjectWork_EmbeddedS_B.msgOut[61] = '\x00';
    } else {
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
    }
  }

  Group31_ProjectW_emxFree_char_T(&b_obj_Value);
  Group31_ProjectW_emxFree_char_T(&e_Value);
  Group31_ProjectW_emxFree_char_T(&c_Value);
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_ProjectWork_Embedd_MENU(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *c_obj_Value;
  emxArray_char_T_Group31_Proje_T *d_obj_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  boolean_T out;
  static const char_T f_Value[41] = { '\r', '\n', 'M', 'O', 'D', 'A', 'L', 'I',
    'T', 'A', ' ', 'L', 'U', 'C', 'I', ':', ' ', '(', '0', ':', ' ', 's', 'p',
    'e', 'n', 't', 'o', ',', ' ', '1', ':', ' ', 'a', 'c', 'c', 'e', 's', 'o',
    ')', '\r', '\n' };

  static const char_T g_Value[34] = { '\r', '\n', 'T', 'E', 'M', 'P', 'E', 'R',
    'A', 'T', 'U', 'R', 'A', ':', ' ', 'R', 'a', 'n', 'g', 'e', ' ', '1', '6',
    ' ', 'C', ' ', '-', ' ', '3', '0', ' ', 'C', '\r', '\n' };

  static const char_T h_Value[20] = { '\r', '\n', 'V', 'E', 'N', 'E', 'Z', 'I',
    'A', 'N', 'E', ':', ' ', '0', ' ', '-', ' ', '9', '\r', '\n' };

  static const char_T i_Value[81] = { '\r', '\n', 'M', 'O', 'D', 'A', 'L', 'I',
    'T', 'A', ' ', 'L', 'U', 'C', 'I', ' ', 'T', 'E', 'M', 'P', 'O', 'R', 'I',
    'Z', 'Z', 'A', 'T', 'E', ':', ' ', 'd', 'u', 'r', 'a', 't', 'a', ' ', 'd',
    'i', ' ', 'a', 'c', 'c', 'e', 'n', 's', 'i', 'o', 'n', 'e', ' ', '(', '5',
    ' ', '-', ' ', '3', '0', ' ', 's', ',', ' ', '0', ' ', 's', ':', ' ', 'd',
    'i', 's', 'a', 't', 't', 'i', 'v', 'a', 't', 'a', ')', '\r', '\n' };

  int32_T tmp;
  Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
  if (*UARTUSARTRead_o2 > 0U) {
    b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    tmp = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString
            [0], (uint32_T)b);
    out = false;
    if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '1')) {
      out = true;
    }
  } else {
    out = false;
  }

  if (out) {
    Group31_ProjectWork_Embedded_DW.tp_MENU = 0U;
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_setModalitaLuci;
    strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
    for (b = 0; b < 41; b++) {
      Group31_ProjectWork_EmbeddedS_B.msgOut[b] = f_Value[b];
    }

    Group31_ProjectWork_EmbeddedS_B.msgOut[41] = '\x00';
  } else {
    if (*UARTUSARTRead_o2 > 0U) {
      b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
      Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
      tmp = b_obj_Value->size[0] * b_obj_Value->size[1];
      b_obj_Value->size[0] = 1;
      b_obj_Value->size[1] = b;
      Group3_emxEnsureCapacity_char_T(b_obj_Value, tmp);
      strncpy(&b_obj_Value->data[0],
              &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
      out = false;
      if ((b_obj_Value->size[1] == 1) && (b_obj_Value->data[0] == '3')) {
        out = true;
      }

      Group31_ProjectW_emxFree_char_T(&b_obj_Value);
    } else {
      out = false;
    }

    if (out) {
      Group31_ProjectWork_Embedded_DW.tp_MENU = 0U;
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_Proje_IN_setTemperatura;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      for (b = 0; b < 34; b++) {
        Group31_ProjectWork_EmbeddedS_B.msgOut[b] = g_Value[b];
      }

      Group31_ProjectWork_EmbeddedS_B.msgOut[34] = '\x00';
    } else {
      if (*UARTUSARTRead_o2 > 0U) {
        b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
        Group31_ProjectW_emxInit_char_T(&c_obj_Value, 2);
        tmp = c_obj_Value->size[0] * c_obj_Value->size[1];
        c_obj_Value->size[0] = 1;
        c_obj_Value->size[1] = b;
        Group3_emxEnsureCapacity_char_T(c_obj_Value, tmp);
        strncpy(&c_obj_Value->data[0],
                &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
        out = false;
        if ((c_obj_Value->size[1] == 1) && (c_obj_Value->data[0] == '4')) {
          out = true;
        }

        Group31_ProjectW_emxFree_char_T(&c_obj_Value);
      } else {
        out = false;
      }

      if (out) {
        Group31_ProjectWork_Embedded_DW.tp_MENU = 0U;
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Project_IN_setVeneziane;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        for (b = 0; b < 20; b++) {
          Group31_ProjectWork_EmbeddedS_B.msgOut[b] = h_Value[b];
        }

        Group31_ProjectWork_EmbeddedS_B.msgOut[20] = '\x00';
      } else {
        if (*UARTUSARTRead_o2 > 0U) {
          b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
          Group31_ProjectW_emxInit_char_T(&d_obj_Value, 2);
          tmp = d_obj_Value->size[0] * d_obj_Value->size[1];
          d_obj_Value->size[0] = 1;
          d_obj_Value->size[1] = b;
          Group3_emxEnsureCapacity_char_T(d_obj_Value, tmp);
          strncpy(&d_obj_Value->data[0],
                  &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
          out = false;
          if ((d_obj_Value->size[1] == 1) && (d_obj_Value->data[0] == '2')) {
            out = true;
          }

          Group31_ProjectW_emxFree_char_T(&d_obj_Value);
        } else {
          out = false;
        }

        if (out) {
          Group31_ProjectWork_Embedded_DW.tp_MENU = 0U;
          Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
            Group31_Projec_IN_setDurataLuci;
          strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
          Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
          memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &i_Value[0], 81U *
                 sizeof(char_T));
          Group31_ProjectWork_EmbeddedS_B.msgOut[81] = '\x00';
        } else {
          strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
          Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
          Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
        }
      }
    }
  }

  Group31_ProjectW_emxFree_char_T(&obj_Value);
}

/* Function for Chart: '<Root>/Chart' */
static real_T Group31_Projec_configDurataLuci(const
  emxArray_char_T_Group31_Proje_T *msg_Value)
{
  real_T numDurataLuci;
  real_T valDurataLuci;
  numDurataLuci = Group31_ProjectWor_myStr2Double(msg_Value);
  valDurataLuci = 0.0;
  if (((numDurataLuci > 4.0) && (numDurataLuci < 31.0)) || (numDurataLuci == 0.0))
  {
    valDurataLuci = 1.0;
  }

  return valDurataLuci;
}

/* Function for Chart: '<Root>/Chart' */
static void Gro_enter_atomic_setDurataLuci1(void)
{
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *d_Value;
  emxArray_char_T_Group31_Proje_T *e_Value;
  emxArray_char_T_Group31_Proje_T *g_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  int32_T i;
  int32_T loop_ub;
  b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
  Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
  i = obj_Value->size[0] * obj_Value->size[1];
  obj_Value->size[0] = 1;
  obj_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(obj_Value, i);
  strncpy(&obj_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
          (uint32_T)b);
  b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
  Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
  i = b_obj_Value->size[0] * b_obj_Value->size[1];
  b_obj_Value->size[0] = 1;
  b_obj_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(b_obj_Value, i);
  strncpy(&b_obj_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString
          [0], (uint32_T)b);
  Group31_ProjectW_emxInit_char_T(&d_Value, 2);
  i = d_Value->size[0] * d_Value->size[1];
  d_Value->size[0] = 1;
  b = obj_Value->size[1] + b_obj_Value->size[1];
  d_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(d_Value, i);
  loop_ub = obj_Value->size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&d_Value->data[0], &obj_Value->data[0], (uint32_T)loop_ub * sizeof
           (char_T));
  }

  loop_ub = b_obj_Value->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_Value->data[i + obj_Value->size[1]] = b_obj_Value->data[i];
  }

  Group31_ProjectW_emxFree_char_T(&b_obj_Value);
  Group31_ProjectW_emxFree_char_T(&obj_Value);
  strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
  Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
  if (d_Value->size[1] > 255) {
    b = 255;
  }

  if (b - 1 >= 0) {
    memcpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], &d_Value->data[0],
           (uint32_T)b * sizeof(char_T));
  }

  Group31_ProjectW_emxFree_char_T(&d_Value);
  Group31_ProjectWork_Embedded_DW.uartMsg[b] = '\x00';
  b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
  Group31_ProjectW_emxInit_char_T(&e_Value, 2);
  i = e_Value->size[0] * e_Value->size[1];
  e_Value->size[0] = 1;
  e_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(e_Value, i);
  strncpy(&e_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0],
          (uint32_T)b);
  strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
  Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
  if (e_Value->size[1] <= 255) {
    b = e_Value->size[1];
  } else {
    b = 255;
  }

  if (b - 1 >= 0) {
    memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &e_Value->data[0],
           (uint32_T)b * sizeof(char_T));
  }

  Group31_ProjectW_emxFree_char_T(&e_Value);
  Group31_ProjectWork_EmbeddedS_B.msgOut[b] = '\x00';
  Group31_ProjectWork_Embedded_DW.i++;
  if ((Group31_ProjectWork_Embedded_DW.i > 0.0) &&
      (Group31_ProjectWork_Embedded_DW.i < 3.0)) {
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    Group31_ProjectW_emxInit_char_T(&g_Value, 2);
    i = g_Value->size[0] * g_Value->size[1];
    g_Value->size[0] = 1;
    g_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(g_Value, i);
    strncpy(&g_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    Group31_ProjectWork_Embedded_DW.config_comp_durata_luci =
      Group31_Projec_configDurataLuci(g_Value);
    Group31_ProjectW_emxFree_char_T(&g_Value);
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_ProjectW_setDurataLuci1(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *c_Value;
  emxArray_char_T_Group31_Proje_T *e_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  boolean_T out;
  static const char_T h_Value[63] = { '\r', '\n', 'V', 'a', 'l', 'o', 'r', 'e',
    ' ', 'D', 'U', 'R', 'A', 'T', 'A', ' ', 'L', 'U', 'C', 'I', ' ', 'n', 'o',
    'n', ' ', 'v', 'a', 'l', 'i', 'd', 'o', '.', '\r', '\n', 'P', 'r', 'e', 'm',
    'i', ' ', 'I', 'N', 'V', 'I', 'O', ' ', 'p', 'e', 'r', ' ', 'r', 'e', 'i',
    'n', 's', 'e', 'r', 'i', 'r', 'l', 'o', '\r', '\n' };

  static const char_T i_Value[34] = { '\r', '\n', 'T', 'E', 'M', 'P', 'E', 'R',
    'A', 'T', 'U', 'R', 'A', ':', ' ', 'R', 'a', 'n', 'g', 'e', ' ', '1', '6',
    ' ', 'C', ' ', '-', ' ', '3', '0', ' ', 'C', '\r', '\n' };

  static const char_T j_Value[102] = { '\r', '\n', '\r', '\n', '=', '=', '=',
    '=', ' ', 'M', 'E', 'N', 'U', ' ', '=', '=', '=', '=', '\r', '\n', '1', '.',
    ' ', 'L', 'u', 'c', 'i', ' ', 'O', 'N', '/', 'O', 'F', 'F', '\r', '\n', '2',
    '.', ' ', 'L', 'u', 'c', 'i', ' ', 'T', 'e', 'm', 'p', 'o', 'r', 'i', 'z',
    'z', 'a', 't', 'e', '\r', '\n', '3', '.', ' ', 'T', 'e', 'm', 'p', 'e', 'r',
    'a', 't', 'u', 'r', 'a', '\r', '\n', '4', '.', ' ', 'V', 'e', 'n', 'e', 'z',
    'i', 'a', 'n', 'e', '\r', '\n', 'P', 'r', 'e', 'm', 'i', ' ', 'C', 'O', 'N',
    'F', 'I', 'G', '\r', '\n' };

  int32_T tmp;
  boolean_T guard1;
  if ((Group31_ProjectWork_Embedded_DW.config_comp_durata_luci == 1.0) &&
      (*UARTUSARTRead_o2 > 0U)) {
    b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
    tmp = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString
            [0], (uint32_T)b);
    out = false;
    if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
      out = true;
    }

    Group31_ProjectW_emxFree_char_T(&obj_Value);
  } else {
    out = false;
  }

  Group31_ProjectW_emxInit_char_T(&c_Value, 2);
  Group31_ProjectW_emxInit_char_T(&e_Value, 2);
  Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
  guard1 = false;
  if (out) {
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    tmp = c_Value->size[0] * c_Value->size[1];
    c_Value->size[0] = 1;
    c_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(c_Value, tmp);
    strncpy(&c_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    Group31_ProjectWork_Embedded_DW.durata_luci =
      Group31_ProjectWork_E_applyConv(c_Value);
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    tmp = e_Value->size[0] * e_Value->size[1];
    e_Value->size[0] = 1;
    e_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(e_Value, tmp);
    strncpy(&e_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 0.0) {
      Group31_ProjectWork_Embedded_DW.tp_MENU = 1U;
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_ProjectWork_Emb_IN_MENU;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &j_Value[0], 102U *
             sizeof(char_T));
      Group31_ProjectWork_EmbeddedS_B.msgOut[102] = '\x00';
    } else if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 1.0) {
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_Proje_IN_setTemperatura;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      for (b = 0; b < 34; b++) {
        Group31_ProjectWork_EmbeddedS_B.msgOut[b] = i_Value[b];
      }

      Group31_ProjectWork_EmbeddedS_B.msgOut[34] = '\x00';
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if ((Group31_ProjectWork_Embedded_DW.config_comp_durata_luci == 0.0) &&
        (*UARTUSARTRead_o2 > 0U)) {
      b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
      tmp = b_obj_Value->size[0] * b_obj_Value->size[1];
      b_obj_Value->size[0] = 1;
      b_obj_Value->size[1] = b;
      Group3_emxEnsureCapacity_char_T(b_obj_Value, tmp);
      strncpy(&b_obj_Value->data[0],
              &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
      out = false;
      if ((b_obj_Value->size[1] == 1) && (b_obj_Value->data[0] == '\r')) {
        out = true;
      }
    } else {
      out = false;
    }

    if (out) {
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_Proj_IN_ErrorDurataLuci;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      for (b = 0; b < 63; b++) {
        Group31_ProjectWork_EmbeddedS_B.msgOut[b] = h_Value[b];
      }

      Group31_ProjectWork_EmbeddedS_B.msgOut[63] = '\x00';
    } else if (resultZC0) {
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_Proje_IN_setDurataLuci1;
      Gro_enter_atomic_setDurataLuci1();
    } else {
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
    }
  }

  Group31_ProjectW_emxFree_char_T(&b_obj_Value);
  Group31_ProjectW_emxFree_char_T(&e_Value);
  Group31_ProjectW_emxFree_char_T(&c_Value);
}

/* Function for Chart: '<Root>/Chart' */
static real_T Group31_ProjectWo_configModLuci(const
  emxArray_char_T_Group31_Proje_T *msg_Value)
{
  real_T numLights;
  real_T valModLuci;
  numLights = Group31_ProjectWor_myStr2Double(msg_Value);
  valModLuci = 0.0;
  if ((numLights == 1.0) || (numLights == 0.0)) {
    valModLuci = 1.0;
  }

  return valModLuci;
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_Project_setModalitaLuci(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *b_Value;
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *f_Value;
  emxArray_char_T_Group31_Proje_T *h_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T c;
  int32_T loop_ub;
  int32_T tmp;
  Group31_ProjectW_emxInit_char_T(&b_Value, 2);
  if (*UARTUSARTRead_o2 > 0U) {
    strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
    Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
    Group31_ProjectWork_Embedded_DW.uartMsg[0] = '\x00';
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Pro_IN_setModalitaLuci1;
    c = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
    loop_ub = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(obj_Value, loop_ub);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)c);
    c = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
    loop_ub = b_obj_Value->size[0] * b_obj_Value->size[1];
    b_obj_Value->size[0] = 1;
    b_obj_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(b_obj_Value, loop_ub);
    strncpy(&b_obj_Value->data[0],
            &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)c);
    loop_ub = b_Value->size[0] * b_Value->size[1];
    b_Value->size[0] = 1;
    tmp = obj_Value->size[1] + b_obj_Value->size[1];
    b_Value->size[1] = tmp;
    Group3_emxEnsureCapacity_char_T(b_Value, loop_ub);
    loop_ub = obj_Value->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&b_Value->data[0], &obj_Value->data[0], (uint32_T)loop_ub * sizeof
             (char_T));
    }

    loop_ub = b_obj_Value->size[1];
    for (c = 0; c < loop_ub; c++) {
      b_Value->data[c + obj_Value->size[1]] = b_obj_Value->data[c];
    }

    Group31_ProjectW_emxFree_char_T(&b_obj_Value);
    Group31_ProjectW_emxFree_char_T(&obj_Value);
    strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
    Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
    if (b_Value->size[1] > 255) {
      tmp = 255;
    }

    if (tmp - 1 >= 0) {
      memcpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], &b_Value->data[0],
             (uint32_T)tmp * sizeof(char_T));
    }

    Group31_ProjectWork_Embedded_DW.uartMsg[tmp] = '\x00';
    c = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&f_Value, 2);
    loop_ub = f_Value->size[0] * f_Value->size[1];
    f_Value->size[0] = 1;
    f_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(f_Value, loop_ub);
    strncpy(&f_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0],
            (uint32_T)c);
    strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
    if (f_Value->size[1] <= 255) {
      tmp = f_Value->size[1];
    } else {
      tmp = 255;
    }

    if (tmp - 1 >= 0) {
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &f_Value->data[0],
             (uint32_T)tmp * sizeof(char_T));
    }

    Group31_ProjectW_emxFree_char_T(&f_Value);
    Group31_ProjectWork_EmbeddedS_B.msgOut[tmp] = '\x00';
    c = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    Group31_ProjectW_emxInit_char_T(&h_Value, 2);
    loop_ub = h_Value->size[0] * h_Value->size[1];
    h_Value->size[0] = 1;
    h_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(h_Value, loop_ub);
    strncpy(&h_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)c);
    Group31_ProjectWork_Embedded_DW.config_comp_mod_luci =
      Group31_ProjectWo_configModLuci(h_Value);
    Group31_ProjectW_emxFree_char_T(&h_Value);
  } else {
    strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
    Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
  }

  Group31_ProjectW_emxFree_char_T(&b_Value);
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_Projec_setModalitaLuci1(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *d_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  boolean_T out;
  static const char_T g_Value[65] = { '\r', '\n', 'V', 'a', 'l', 'o', 'r', 'e',
    ' ', 'M', 'O', 'D', 'A', 'L', 'I', 'T', 'A', ' ', 'L', 'U', 'C', 'I', ' ',
    'n', 'o', 'n', ' ', 'v', 'a', 'l', 'i', 'd', 'o', '.', '\r', '\n', 'P', 'r',
    'e', 'm', 'i', ' ', 'I', 'N', 'V', 'I', 'O', ' ', 'p', 'e', 'r', ' ', 'r',
    'e', 'i', 'n', 's', 'e', 'r', 'i', 'r', 'l', 'o', '\r', '\n' };

  static const char_T h_Value[81] = { '\r', '\n', 'M', 'O', 'D', 'A', 'L', 'I',
    'T', 'A', ' ', 'L', 'U', 'C', 'I', ' ', 'T', 'E', 'M', 'P', 'O', 'R', 'I',
    'Z', 'Z', 'A', 'T', 'E', ':', ' ', 'd', 'u', 'r', 'a', 't', 'a', ' ', 'd',
    'i', ' ', 'a', 'c', 'c', 'e', 'n', 's', 'i', 'o', 'n', 'e', ' ', '(', '5',
    ' ', '-', ' ', '3', '0', ' ', 's', ',', ' ', '0', ' ', 's', ':', ' ', 'd',
    'i', 's', 'a', 't', 't', 'i', 'v', 'a', 't', 'a', ')', '\r', '\n' };

  static const char_T i_Value[102] = { '\r', '\n', '\r', '\n', '=', '=', '=',
    '=', ' ', 'M', 'E', 'N', 'U', ' ', '=', '=', '=', '=', '\r', '\n', '1', '.',
    ' ', 'L', 'u', 'c', 'i', ' ', 'O', 'N', '/', 'O', 'F', 'F', '\r', '\n', '2',
    '.', ' ', 'L', 'u', 'c', 'i', ' ', 'T', 'e', 'm', 'p', 'o', 'r', 'i', 'z',
    'z', 'a', 't', 'e', '\r', '\n', '3', '.', ' ', 'T', 'e', 'm', 'p', 'e', 'r',
    'a', 't', 'u', 'r', 'a', '\r', '\n', '4', '.', ' ', 'V', 'e', 'n', 'e', 'z',
    'i', 'a', 'n', 'e', '\r', '\n', 'P', 'r', 'e', 'm', 'i', ' ', 'C', 'O', 'N',
    'F', 'I', 'G', '\r', '\n' };

  int32_T tmp;
  if ((Group31_ProjectWork_Embedded_DW.config_comp_mod_luci == 1.0) &&
      (*UARTUSARTRead_o2 > 0U)) {
    b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
    tmp = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString
            [0], (uint32_T)b);
    out = false;
    if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
      out = true;
    }

    Group31_ProjectW_emxFree_char_T(&obj_Value);
  } else {
    out = false;
  }

  Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
  if (out) {
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    tmp = b_obj_Value->size[0] * b_obj_Value->size[1];
    b_obj_Value->size[0] = 1;
    b_obj_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(b_obj_Value, tmp);
    strncpy(&b_obj_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    Group31_ProjectWork_Embedded_DW.mod_luci = Group31_ProjectWork_E_applyConv
      (b_obj_Value);
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    Group31_ProjectW_emxInit_char_T(&d_Value, 2);
    tmp = d_Value->size[0] * d_Value->size[1];
    d_Value->size[0] = 1;
    d_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(d_Value, tmp);
    strncpy(&d_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    Group31_ProjectW_emxFree_char_T(&d_Value);
    if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 1.0) {
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_Projec_IN_setDurataLuci;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &h_Value[0], 81U *
             sizeof(char_T));
      Group31_ProjectWork_EmbeddedS_B.msgOut[81] = '\x00';
    } else {
      Group31_ProjectWork_Embedded_DW.tp_MENU = 1U;
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_ProjectWork_Emb_IN_MENU;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &i_Value[0], 102U *
             sizeof(char_T));
      Group31_ProjectWork_EmbeddedS_B.msgOut[102] = '\x00';
    }
  } else {
    if ((Group31_ProjectWork_Embedded_DW.config_comp_mod_luci == 0.0) &&
        (*UARTUSARTRead_o2 > 0U)) {
      b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
      tmp = b_obj_Value->size[0] * b_obj_Value->size[1];
      b_obj_Value->size[0] = 1;
      b_obj_Value->size[1] = b;
      Group3_emxEnsureCapacity_char_T(b_obj_Value, tmp);
      strncpy(&b_obj_Value->data[0],
              &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
      out = false;
      if ((b_obj_Value->size[1] == 1) && (b_obj_Value->data[0] == '\r')) {
        out = true;
      }
    } else {
      out = false;
    }

    if (out) {
      Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
        Group31_Project_IN_ErrorModLuci;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &g_Value[0], 65U *
             sizeof(char_T));
      Group31_ProjectWork_EmbeddedS_B.msgOut[65] = '\x00';
    } else {
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
    }
  }

  Group31_ProjectW_emxFree_char_T(&b_obj_Value);
}

/* Function for Chart: '<Root>/Chart' */
static real_T Group31_Proje_configTemperatura(const
  emxArray_char_T_Group31_Proje_T *msg_Value)
{
  real_T numTemp;
  real_T valTemp;
  numTemp = Group31_ProjectWor_myStr2Double(msg_Value);
  valTemp = 0.0;
  if ((numTemp > 15.0) && (numTemp < 31.0)) {
    valTemp = 1.0;
  }

  return valTemp;
}

/* Function for Chart: '<Root>/Chart' */
static void Gr_enter_atomic_setTemperatura1(void)
{
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *d_Value;
  emxArray_char_T_Group31_Proje_T *e_Value;
  emxArray_char_T_Group31_Proje_T *g_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  int32_T i;
  int32_T loop_ub;
  b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
  Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
  i = obj_Value->size[0] * obj_Value->size[1];
  obj_Value->size[0] = 1;
  obj_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(obj_Value, i);
  strncpy(&obj_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
          (uint32_T)b);
  b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
  Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
  i = b_obj_Value->size[0] * b_obj_Value->size[1];
  b_obj_Value->size[0] = 1;
  b_obj_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(b_obj_Value, i);
  strncpy(&b_obj_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString
          [0], (uint32_T)b);
  Group31_ProjectW_emxInit_char_T(&d_Value, 2);
  i = d_Value->size[0] * d_Value->size[1];
  d_Value->size[0] = 1;
  b = obj_Value->size[1] + b_obj_Value->size[1];
  d_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(d_Value, i);
  loop_ub = obj_Value->size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&d_Value->data[0], &obj_Value->data[0], (uint32_T)loop_ub * sizeof
           (char_T));
  }

  loop_ub = b_obj_Value->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_Value->data[i + obj_Value->size[1]] = b_obj_Value->data[i];
  }

  Group31_ProjectW_emxFree_char_T(&b_obj_Value);
  Group31_ProjectW_emxFree_char_T(&obj_Value);
  strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
  Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
  if (d_Value->size[1] > 255) {
    b = 255;
  }

  if (b - 1 >= 0) {
    memcpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], &d_Value->data[0],
           (uint32_T)b * sizeof(char_T));
  }

  Group31_ProjectW_emxFree_char_T(&d_Value);
  Group31_ProjectWork_Embedded_DW.uartMsg[b] = '\x00';
  b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
  Group31_ProjectW_emxInit_char_T(&e_Value, 2);
  i = e_Value->size[0] * e_Value->size[1];
  e_Value->size[0] = 1;
  e_Value->size[1] = b;
  Group3_emxEnsureCapacity_char_T(e_Value, i);
  strncpy(&e_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0],
          (uint32_T)b);
  strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
  Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
  if (e_Value->size[1] <= 255) {
    b = e_Value->size[1];
  } else {
    b = 255;
  }

  if (b - 1 >= 0) {
    memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &e_Value->data[0],
           (uint32_T)b * sizeof(char_T));
  }

  Group31_ProjectW_emxFree_char_T(&e_Value);
  Group31_ProjectWork_EmbeddedS_B.msgOut[b] = '\x00';
  Group31_ProjectWork_Embedded_DW.i++;
  if (Group31_ProjectWork_Embedded_DW.i == 2.0) {
    b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    Group31_ProjectW_emxInit_char_T(&g_Value, 2);
    i = g_Value->size[0] * g_Value->size[1];
    g_Value->size[0] = 1;
    g_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(g_Value, i);
    strncpy(&g_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)b);
    Group31_ProjectWork_Embedded_DW.config_comp_temp =
      Group31_Proje_configTemperatura(g_Value);
    Group31_ProjectW_emxFree_char_T(&g_Value);
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_Project_setTemperatura1(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *d_Value;
  emxArray_char_T_Group31_Proje_T *f_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  boolean_T out;
  static const char_T h_Value[63] = { '\r', '\n', 'V', 'a', 'l', 'o', 'r', 'e',
    ' ', 'T', 'E', 'M', 'P', 'E', 'R', 'A', 'T', 'U', 'R', 'A', ' ', 'n', 'o',
    'n', ' ', 'v', 'a', 'l', 'i', 'd', 'o', '.', '\r', '\n', 'P', 'r', 'e', 'm',
    'i', ' ', 'I', 'N', 'V', 'I', 'O', ' ', 'p', 'e', 'r', ' ', 'r', 'e', 'i',
    'n', 's', 'e', 'r', 'i', 'r', 'l', 'o', '\r', '\n' };

  static const char_T i_Value[20] = { '\r', '\n', 'V', 'E', 'N', 'E', 'Z', 'I',
    'A', 'N', 'E', ':', ' ', '0', ' ', '-', ' ', '9', '\r', '\n' };

  static const char_T j_Value[102] = { '\r', '\n', '\r', '\n', '=', '=', '=',
    '=', ' ', 'M', 'E', 'N', 'U', ' ', '=', '=', '=', '=', '\r', '\n', '1', '.',
    ' ', 'L', 'u', 'c', 'i', ' ', 'O', 'N', '/', 'O', 'F', 'F', '\r', '\n', '2',
    '.', ' ', 'L', 'u', 'c', 'i', ' ', 'T', 'e', 'm', 'p', 'o', 'r', 'i', 'z',
    'z', 'a', 't', 'e', '\r', '\n', '3', '.', ' ', 'T', 'e', 'm', 'p', 'e', 'r',
    'a', 't', 'u', 'r', 'a', '\r', '\n', '4', '.', ' ', 'V', 'e', 'n', 'e', 'z',
    'i', 'a', 'n', 'e', '\r', '\n', 'P', 'r', 'e', 'm', 'i', ' ', 'C', 'O', 'N',
    'F', 'I', 'G', '\r', '\n' };

  int32_T tmp;
  boolean_T guard1;
  if ((Group31_ProjectWork_Embedded_DW.config_comp_temp == 0.0) &&
      (*UARTUSARTRead_o2 > 0U)) {
    b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
    tmp = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = b;
    Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString
            [0], (uint32_T)b);
    out = false;
    if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
      out = true;
    }

    Group31_ProjectW_emxFree_char_T(&obj_Value);
  } else {
    out = false;
  }

  if (out) {
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Pro_IN_ErrorTemperatura;
    strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
    for (b = 0; b < 63; b++) {
      Group31_ProjectWork_EmbeddedS_B.msgOut[b] = h_Value[b];
    }

    Group31_ProjectWork_EmbeddedS_B.msgOut[63] = '\x00';
  } else {
    if ((Group31_ProjectWork_Embedded_DW.config_comp_temp == 1.0) &&
        (*UARTUSARTRead_o2 > 0U)) {
      b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
      Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
      tmp = b_obj_Value->size[0] * b_obj_Value->size[1];
      b_obj_Value->size[0] = 1;
      b_obj_Value->size[1] = b;
      Group3_emxEnsureCapacity_char_T(b_obj_Value, tmp);
      strncpy(&b_obj_Value->data[0],
              &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
      out = false;
      if ((b_obj_Value->size[1] == 1) && (b_obj_Value->data[0] == '\r')) {
        out = true;
      }

      Group31_ProjectW_emxFree_char_T(&b_obj_Value);
    } else {
      out = false;
    }

    Group31_ProjectW_emxInit_char_T(&d_Value, 2);
    Group31_ProjectW_emxInit_char_T(&f_Value, 2);
    guard1 = false;
    if (out) {
      b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
      tmp = d_Value->size[0] * d_Value->size[1];
      d_Value->size[0] = 1;
      d_Value->size[1] = b;
      Group3_emxEnsureCapacity_char_T(d_Value, tmp);
      strncpy(&d_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
              (uint32_T)b);
      Group31_ProjectWork_Embedded_DW.temperatura =
        Group31_ProjectWork_E_applyConv(d_Value);
      b = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
      tmp = f_Value->size[0] * f_Value->size[1];
      f_Value->size[0] = 1;
      f_Value->size[1] = b;
      Group3_emxEnsureCapacity_char_T(f_Value, tmp);
      strncpy(&f_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
              (uint32_T)b);
      strncpy(&Group31_ProjectWork_Embedded_DW.strTemperatura[0], "", 255U);
      Group31_ProjectWork_Embedded_DW.strTemperatura[255] = '\x00';
      if (f_Value->size[1] <= 255) {
        b = f_Value->size[1];
      } else {
        b = 255;
      }

      if (b - 1 >= 0) {
        memcpy(&Group31_ProjectWork_Embedded_DW.strTemperatura[0],
               &f_Value->data[0], (uint32_T)b * sizeof(char_T));
      }

      Group31_ProjectWork_Embedded_DW.strTemperatura[b] = '\x00';
      if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 0.0) {
        Group31_ProjectWork_Embedded_DW.tp_MENU = 1U;
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_ProjectWork_Emb_IN_MENU;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &j_Value[0], 102U *
               sizeof(char_T));
        Group31_ProjectWork_EmbeddedS_B.msgOut[102] = '\x00';
      } else if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 1.0) {
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Project_IN_setVeneziane;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        for (b = 0; b < 20; b++) {
          Group31_ProjectWork_EmbeddedS_B.msgOut[b] = i_Value[b];
        }

        Group31_ProjectWork_EmbeddedS_B.msgOut[20] = '\x00';
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (resultZC1) {
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Proj_IN_setTemperatura1;
        Gr_enter_atomic_setTemperatura1();
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
    }

    Group31_ProjectW_emxFree_char_T(&f_Value);
    Group31_ProjectW_emxFree_char_T(&d_Value);
  }
}

/* Function for Chart: '<Root>/Chart' */
static real_T Group31_Project_configVeneziane(const
  emxArray_char_T_Group31_Proje_T *msg_Value)
{
  real_T numPreset;
  real_T valAngle;
  numPreset = Group31_ProjectWor_myStr2Double(msg_Value);
  valAngle = 0.0;
  if (numPreset < 10.0) {
    valAngle = 1.0;
  }

  return valAngle;
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_ProjectWor_setVeneziane(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *b_Value;
  emxArray_char_T_Group31_Proje_T *b_obj_Value;
  emxArray_char_T_Group31_Proje_T *f_Value;
  emxArray_char_T_Group31_Proje_T *h_Value;
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T c;
  int32_T loop_ub;
  int32_T tmp;
  Group31_ProjectW_emxInit_char_T(&b_Value, 2);
  if (*UARTUSARTRead_o2 > 0U) {
    strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
    Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
    Group31_ProjectWork_Embedded_DW.uartMsg[0] = '\x00';
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Projec_IN_setVeneziane1;
    c = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
    loop_ub = obj_Value->size[0] * obj_Value->size[1];
    obj_Value->size[0] = 1;
    obj_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(obj_Value, loop_ub);
    strncpy(&obj_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)c);
    c = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&b_obj_Value, 2);
    loop_ub = b_obj_Value->size[0] * b_obj_Value->size[1];
    b_obj_Value->size[0] = 1;
    b_obj_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(b_obj_Value, loop_ub);
    strncpy(&b_obj_Value->data[0],
            &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)c);
    loop_ub = b_Value->size[0] * b_Value->size[1];
    b_Value->size[0] = 1;
    tmp = obj_Value->size[1] + b_obj_Value->size[1];
    b_Value->size[1] = tmp;
    Group3_emxEnsureCapacity_char_T(b_Value, loop_ub);
    loop_ub = obj_Value->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&b_Value->data[0], &obj_Value->data[0], (uint32_T)loop_ub * sizeof
             (char_T));
    }

    loop_ub = b_obj_Value->size[1];
    for (c = 0; c < loop_ub; c++) {
      b_Value->data[c + obj_Value->size[1]] = b_obj_Value->data[c];
    }

    Group31_ProjectW_emxFree_char_T(&b_obj_Value);
    Group31_ProjectW_emxFree_char_T(&obj_Value);
    strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
    Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
    if (b_Value->size[1] > 255) {
      tmp = 255;
    }

    if (tmp - 1 >= 0) {
      memcpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], &b_Value->data[0],
             (uint32_T)tmp * sizeof(char_T));
    }

    Group31_ProjectWork_Embedded_DW.uartMsg[tmp] = '\x00';
    c = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
    Group31_ProjectW_emxInit_char_T(&f_Value, 2);
    loop_ub = f_Value->size[0] * f_Value->size[1];
    f_Value->size[0] = 1;
    f_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(f_Value, loop_ub);
    strncpy(&f_Value->data[0], &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0],
            (uint32_T)c);
    strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
    if (f_Value->size[1] <= 255) {
      tmp = f_Value->size[1];
    } else {
      tmp = 255;
    }

    if (tmp - 1 >= 0) {
      memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &f_Value->data[0],
             (uint32_T)tmp * sizeof(char_T));
    }

    Group31_ProjectW_emxFree_char_T(&f_Value);
    Group31_ProjectWork_EmbeddedS_B.msgOut[tmp] = '\x00';
    c = (int32_T)strlen(&Group31_ProjectWork_Embedded_DW.uartMsg[0]);
    Group31_ProjectW_emxInit_char_T(&h_Value, 2);
    loop_ub = h_Value->size[0] * h_Value->size[1];
    h_Value->size[0] = 1;
    h_Value->size[1] = c;
    Group3_emxEnsureCapacity_char_T(h_Value, loop_ub);
    strncpy(&h_Value->data[0], &Group31_ProjectWork_Embedded_DW.uartMsg[0],
            (uint32_T)c);
    Group31_ProjectWork_Embedded_DW.config_comp_ven =
      Group31_Project_configVeneziane(h_Value);
    Group31_ProjectW_emxFree_char_T(&h_Value);
  } else {
    strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
    Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
  }

  Group31_ProjectW_emxFree_char_T(&b_Value);
}

/* Function for Chart: '<Root>/Chart' */
static void Gr_exit_internal_CONFIGURAZIONE(void)
{
  switch (Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE) {
   case Gr_IN_CONFIGURAZIONE_COMPLETATA:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Proj_IN_ErrorDurataLuci:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Project_IN_ErrorModLuci:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Pro_IN_ErrorTemperatura:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Proje_IN_ErrorVeneziane:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_ProjectWork_Emb_IN_INIT:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_ProjectWork_Emb_IN_MENU:
    Group31_ProjectWork_Embedded_DW.tp_MENU = 0U;
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_ProjectWor_IN_PRECONFIG:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Projec_IN_setDurataLuci:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Proje_IN_setDurataLuci1:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Proj_IN_setModalitaLuci:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Pro_IN_setModalitaLuci1:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Proje_IN_setTemperatura:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Proj_IN_setTemperatura1:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Project_IN_setVeneziane:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;

   case Group31_Projec_IN_setVeneziane1:
    Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
      Group31_Proj_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_ProjectWo_opTemperatura(real_T temperatura, real_T *ledR,
  real_T *ledG, real_T *ledB)
{
  if ((temperatura >= 16.0) && (temperatura <= 18.0)) {
    *ledR = 0.0;
    *ledG = 0.0;
    *ledB = 100.0;
  } else if ((temperatura >= 19.0) && (temperatura <= 21.0)) {
    *ledR = 50.0;
    *ledG = 0.0;
    *ledB = 50.0;
  } else if ((temperatura >= 22.0) && (temperatura <= 24.0)) {
    *ledR = 100.0;
    *ledG = 100.0;
    *ledB = 0.0;
  } else if ((temperatura >= 25.0) && (temperatura <= 27.0)) {
    *ledR = 100.0;
    *ledG = 50.0;
    *ledB = 0.0;
  } else if ((temperatura >= 28.0) && (temperatura <= 30.0)) {
    *ledR = 100.0;
    *ledG = 0.0;
    *ledB = 0.0;
  } else {
    *ledR = 0.0;
    *ledG = 0.0;
    *ledB = 0.0;
  }
}

/* Function for Chart: '<Root>/Chart' */
static real_T Group31_ProjectWork_opVeneziane(real_T angolo)
{
  real_T duty_cycle;
  angolo *= 20.0;
  if ((angolo >= 0.0) && (angolo <= 180.0)) {
    duty_cycle = angolo / 180.0 * 5.0 + 5.0;
  } else {
    duty_cycle = 0.0;
  }

  return duty_cycle;
}

/* Function for Chart: '<Root>/Chart' */
static void Group31_ProjectW_CONFIGURAZIONE(const uint32_T *UARTUSARTRead_o2)
{
  emxArray_char_T_Group31_Proje_T *obj_Value;
  int32_T b;
  boolean_T b_out;
  static const char_T f_Value[41] = { '\r', '\n', 'M', 'O', 'D', 'A', 'L', 'I',
    'T', 'A', ' ', 'L', 'U', 'C', 'I', ':', ' ', '(', '0', ':', ' ', 's', 'p',
    'e', 'n', 't', 'o', ',', ' ', '1', ':', ' ', 'a', 'c', 'c', 'e', 's', 'o',
    ')', '\r', '\n' };

  static const char_T g_Value[102] = { '\r', '\n', '\r', '\n', '=', '=', '=',
    '=', ' ', 'M', 'E', 'N', 'U', ' ', '=', '=', '=', '=', '\r', '\n', '1', '.',
    ' ', 'L', 'u', 'c', 'i', ' ', 'O', 'N', '/', 'O', 'F', 'F', '\r', '\n', '2',
    '.', ' ', 'L', 'u', 'c', 'i', ' ', 'T', 'e', 'm', 'p', 'o', 'r', 'i', 'z',
    'z', 'a', 't', 'e', '\r', '\n', '3', '.', ' ', 'T', 'e', 'm', 'p', 'e', 'r',
    'a', 't', 'u', 'r', 'a', '\r', '\n', '4', '.', ' ', 'V', 'e', 'n', 'e', 'z',
    'i', 'a', 'n', 'e', '\r', '\n', 'P', 'r', 'e', 'm', 'i', ' ', 'C', 'O', 'N',
    'F', 'I', 'G', '\r', '\n' };

  static const char_T h_Value[107] = { 'B', 'e', 'n', 'v', 'e', 'n', 'u', 't',
    'o', ' ', 'n', 'e', 'l', 'l', ' ', 'a', 'm', 'b', 'i', 'e', 'n', 't', 'e',
    ' ', 'd', 'o', 'm', 'o', 't', 'i', 'c', 'o', '!', '\r', '\n', 'A', 'l', 'l',
    'a', ' ', 'p', 'r', 'i', 'm', 'a', ' ', 'a', 't', 't', 'i', 'v', 'a', 'z',
    'i', 'o', 'n', 'e', ',', ' ', 'e', ' ', 'n', 'e', 'c', 'e', 's', 's', 'a',
    'r', 'i', 'o', ' ', 'c', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 'r', 'e',
    ' ', 't', 'u', 't', 't', 'e', ' ', 'l', 'e', ' ', 'f', 'u', 'n', 'z', 'i',
    'o', 'n', 'a', 'l', 'i', 't', 'a', '\r', '\n' };

  static const char_T i_Value[81] = { '\r', '\n', 'M', 'O', 'D', 'A', 'L', 'I',
    'T', 'A', ' ', 'L', 'U', 'C', 'I', ' ', 'T', 'E', 'M', 'P', 'O', 'R', 'I',
    'Z', 'Z', 'A', 'T', 'E', ':', ' ', 'd', 'u', 'r', 'a', 't', 'a', ' ', 'd',
    'i', ' ', 'a', 'c', 'c', 'e', 'n', 's', 'i', 'o', 'n', 'e', ' ', '(', '5',
    ' ', '-', ' ', '3', '0', ' ', 's', ',', ' ', '0', ' ', 's', ':', ' ', 'd',
    'i', 's', 'a', 't', 't', 'i', 'v', 'a', 't', 'a', ')', '\r', '\n' };

  static const char_T k_Value[34] = { '\r', '\n', 'T', 'E', 'M', 'P', 'E', 'R',
    'A', 'T', 'U', 'R', 'A', ':', ' ', 'R', 'a', 'n', 'g', 'e', ' ', '1', '6',
    ' ', 'C', ' ', '-', ' ', '3', '0', ' ', 'C', '\r', '\n' };

  static const char_T l_Value[20] = { '\r', '\n', 'V', 'E', 'N', 'E', 'Z', 'I',
    'A', 'N', 'E', ':', ' ', '0', ' ', '-', ' ', '9', '\r', '\n' };

  int32_T tmp;
  if (resultZC7 && (Group31_ProjectWork_Embedded_DW.config_comp_init == 1.0)) {
    Gr_exit_internal_CONFIGURAZIONE();
    Group31_ProjectWork_Embedded_DW.prima_attivazione = 0.0;
    Group31_ProjectWork_Embedded_DW.is_MAIN = Group31_ProjectWo_IN_OPERAZIONE;
    Group31_ProjectWo_opTemperatura(Group31_ProjectWork_Embedded_DW.temperatura,
      &Group31_ProjectWork_EmbeddedS_B.ledR,
      &Group31_ProjectWork_EmbeddedS_B.ledG,
      &Group31_ProjectWork_EmbeddedS_B.ledB);
    Group31_ProjectWork_Embedded_DW.temporalCounter_i2 = 0U;
    Group31_Proje_enter_atomic_NOT2();
    if (Group31_ProjectWork_Embedded_DW.mod_luci == 1.0) {
      Group31_ProjectWork_Embedded_DW.is_LUCI = Group31_ProjectW_IN_LUCI_ACCESE;
      Group31_ProjectWork_EmbeddedS_B.rele_luci = 1.0;
    } else {
      Group31_ProjectWork_Embedded_DW.is_LUCI = Group31_ProjectW_IN_LUCI_SPENTE;
      Group31_ProjectWork_EmbeddedS_B.rele_luci = 0.0;
      Group31_ProjectWork_Embedded_DW.mod_luci = 0.0;
    }

    Group31_ProjectWork_EmbeddedS_B.duty_cycle = Group31_ProjectWork_opVeneziane
      (Group31_ProjectWork_Embedded_DW.angolo);
  } else {
    Group31_ProjectW_emxInit_char_T(&obj_Value, 2);
    switch (Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE) {
     case Gr_IN_CONFIGURAZIONE_COMPLETATA:
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      break;

     case Group31_Proj_IN_ErrorDurataLuci:
      if (*UARTUSARTRead_o2 > 0U) {
        b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
        tmp = obj_Value->size[0] * obj_Value->size[1];
        obj_Value->size[0] = 1;
        obj_Value->size[1] = b;
        Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
        strncpy(&obj_Value->data[0],
                &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
        b_out = false;
        if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
          b_out = true;
        }
      } else {
        b_out = false;
      }

      if (b_out) {
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Projec_IN_setDurataLuci;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &i_Value[0], 81U *
               sizeof(char_T));
        Group31_ProjectWork_EmbeddedS_B.msgOut[81] = '\x00';
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;

     case Group31_Project_IN_ErrorModLuci:
      if (*UARTUSARTRead_o2 > 0U) {
        b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
        tmp = obj_Value->size[0] * obj_Value->size[1];
        obj_Value->size[0] = 1;
        obj_Value->size[1] = b;
        Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
        strncpy(&obj_Value->data[0],
                &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
        b_out = false;
        if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
          b_out = true;
        }
      } else {
        b_out = false;
      }

      if (b_out) {
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Proj_IN_setModalitaLuci;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        for (b = 0; b < 41; b++) {
          Group31_ProjectWork_EmbeddedS_B.msgOut[b] = f_Value[b];
        }

        Group31_ProjectWork_EmbeddedS_B.msgOut[41] = '\x00';
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;

     case Group31_Pro_IN_ErrorTemperatura:
      if (*UARTUSARTRead_o2 > 0U) {
        b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
        tmp = obj_Value->size[0] * obj_Value->size[1];
        obj_Value->size[0] = 1;
        obj_Value->size[1] = b;
        Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
        strncpy(&obj_Value->data[0],
                &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
        b_out = false;
        if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
          b_out = true;
        }
      } else {
        b_out = false;
      }

      if (b_out) {
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Proje_IN_setTemperatura;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        for (b = 0; b < 34; b++) {
          Group31_ProjectWork_EmbeddedS_B.msgOut[b] = k_Value[b];
        }

        Group31_ProjectWork_EmbeddedS_B.msgOut[34] = '\x00';
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;

     case Group31_Proje_IN_ErrorVeneziane:
      if (*UARTUSARTRead_o2 > 0U) {
        b = (int32_T)strlen(&Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0]);
        tmp = obj_Value->size[0] * obj_Value->size[1];
        obj_Value->size[0] = 1;
        obj_Value->size[1] = b;
        Group3_emxEnsureCapacity_char_T(obj_Value, tmp);
        strncpy(&obj_Value->data[0],
                &Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0], (uint32_T)b);
        b_out = false;
        if ((obj_Value->size[1] == 1) && (obj_Value->data[0] == '\r')) {
          b_out = true;
        }
      } else {
        b_out = false;
      }

      if (b_out) {
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Project_IN_setVeneziane;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        for (b = 0; b < 20; b++) {
          Group31_ProjectWork_EmbeddedS_B.msgOut[b] = l_Value[b];
        }

        Group31_ProjectWork_EmbeddedS_B.msgOut[20] = '\x00';
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;

     case Group31_ProjectWork_Emb_IN_INIT:
      if (Group31_ProjectWork_Embedded_DW.temporalCounter_i1 >= 30) {
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Proj_IN_setModalitaLuci;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        for (b = 0; b < 41; b++) {
          Group31_ProjectWork_EmbeddedS_B.msgOut[b] = f_Value[b];
        }

        Group31_ProjectWork_EmbeddedS_B.msgOut[41] = '\x00';
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;

     case Group31_ProjectWork_Emb_IN_MENU:
      Group31_ProjectWork_Embedd_MENU(UARTUSARTRead_o2);
      break;

     case Group31_ProjectWor_IN_PRECONFIG:
      if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 0.0) {
        Group31_ProjectWork_Embedded_DW.tp_MENU = 1U;
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_ProjectWork_Emb_IN_MENU;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &g_Value[0], 102U *
               sizeof(char_T));
        Group31_ProjectWork_EmbeddedS_B.msgOut[102] = '\x00';
      } else if (Group31_ProjectWork_Embedded_DW.prima_attivazione == 1.0) {
        Group31_ProjectWork_Embedded_DW.temporalCounter_i1 = 0U;
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_ProjectWork_Emb_IN_INIT;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        memcpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], &h_Value[0], 107U *
               sizeof(char_T));
        Group31_ProjectWork_EmbeddedS_B.msgOut[107] = '\x00';
      }
      break;

     case Group31_Projec_IN_setDurataLuci:
      if (*UARTUSARTRead_o2 > 0U) {
        strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
        Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
        Group31_ProjectWork_Embedded_DW.uartMsg[0] = '\x00';
        Group31_ProjectWork_Embedded_DW.i = 0.0;
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Proje_IN_setDurataLuci1;
        Gro_enter_atomic_setDurataLuci1();
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;

     case Group31_Proje_IN_setDurataLuci1:
      Group31_ProjectW_setDurataLuci1(UARTUSARTRead_o2);
      break;

     case Group31_Proj_IN_setModalitaLuci:
      Group31_Project_setModalitaLuci(UARTUSARTRead_o2);
      break;

     case Group31_Pro_IN_setModalitaLuci1:
      Group31_Projec_setModalitaLuci1(UARTUSARTRead_o2);
      break;

     case Group31_Proje_IN_setTemperatura:
      if (*UARTUSARTRead_o2 > 0U) {
        strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
        Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
        Group31_ProjectWork_Embedded_DW.uartMsg[0] = '\x00';
        Group31_ProjectWork_Embedded_DW.i = 1.0;
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_Proj_IN_setTemperatura1;
        Gr_enter_atomic_setTemperatura1();
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;

     case Group31_Proj_IN_setTemperatura1:
      Group31_Project_setTemperatura1(UARTUSARTRead_o2);
      break;

     case Group31_Project_IN_setVeneziane:
      Group31_ProjectWor_setVeneziane(UARTUSARTRead_o2);
      break;

     default:
      /* case IN_setVeneziane1: */
      Group31_ProjectWo_setVeneziane1(UARTUSARTRead_o2);
      break;
    }

    Group31_ProjectW_emxFree_char_T(&obj_Value);
  }
}

static void Group31_Projec_SystemCore_setup(stm32cube_blocks_UARTRead_Gro_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<Root>/UART//USART Read' */
  obj->isInitialized = 1;
  b.buffer.rxBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 1.0;

  /* Start for MATLABSystem: '<Root>/UART//USART Read' */
  b.mode = UART_RX_INTERRUPT_MODE;
  b.peripheralPtr = LPUART1;

  /* Start for MATLABSystem: '<Root>/UART//USART Read' */
  b.rxdmaPeripheralPtr = NULL;
  b.rxdmastream = 0;
  b.disableDMAIntOnError = false;

  /* Start for MATLABSystem: '<Root>/UART//USART Read' */
  b.buffer.rxBufferSize = 128U;
  obj->UARTHandle = MW_LPUART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void Group31_Pro_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_Gr_T *obj)
{
  UART_Type_T b;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = LPUART1;

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_LPUART_Initialize(&b);
}

static void Group31_Pro_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Gr_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S23>/PWM Output' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S23>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S23>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Group31_P_PWMOutput_setupImpl_p(stm32cube_blocks_PWMOutput_Gr_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S25>/PWM Output' */
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S25>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S25>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Group31_ProjectWork_EmbeddedSystem_step(void)
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;
  uint32_T dataBytesToRead;
  uint32_T pinReadLoc;
  uint8_T uartWriteData[127];
  uint8_T uartReadData;
  boolean_T DigitalPortRead;
  boolean_T DigitalPortRead_c;
  boolean_T DigitalPortRead_k;
  boolean_T DigitalPortRead_o;
  static const char_T d_Value[58] = { 'P', 'r', 'e', 'm', 'e', 'r', 'e', ' ',
    'i', 'l', ' ', 'p', 'u', 'l', 's', 'a', 'n', 't', 'e', ' ', 'A', 'T', 'T',
    'I', 'V', 'A', ' ', 'p', 'e', 'r', ' ', 'a', 't', 't', 'i', 'v', 'a', 'r',
    'e', ' ', 'i', 'l', ' ', 'd', 'i', 's', 'p', 'o', 's', 'i', 't', 'i', 'v',
    'o', '\r', '\n', '\r', '\n' };

  static const char_T c_Value[10] = { '\x1b', '[', '0', ';', '0', 'H', '\x1b',
    '[', '2', 'J' };

  /* MATLABSystem: '<S11>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S11>/Digital Port Read' */
  DigitalPortRead_o = ((pinReadLoc & 1U) != 0U);

  /* MATLABSystem: '<S13>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S13>/Digital Port Read' */
  DigitalPortRead_k = ((pinReadLoc & 8192U) != 0U);

  /* MATLABSystem: '<S15>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S15>/Digital Port Read' */
  DigitalPortRead_c = ((pinReadLoc & 1024U) != 0U);

  /* MATLABSystem: '<S17>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* MATLABSystem: '<S17>/Digital Port Read' */
  DigitalPortRead = ((pinReadLoc & 32768U) != 0U);

  /* MATLABSystem: '<Root>/UART//USART Read' */
  dataBytesToRead = getBytesToBeReadFromBuffer
    (Group31_ProjectWork_Embedded_DW.obj.UARTHandle, 1U, 0U);
  if (dataBytesToRead > 0U) {
    MW_LPUART_ReceiveUsingBuffer(Group31_ProjectWork_Embedded_DW.obj.UARTHandle,
      &uartReadData, dataBytesToRead, &pinReadLoc);
  } else {
    MW_LPUART_GetReadErrorStatus(Group31_ProjectWork_Embedded_DW.obj.UARTHandle);
    pinReadLoc = 0U;
  }

  /* ASCIIToString: '<Root>/ASCII to String' incorporates:
   *  MATLABSystem: '<Root>/UART//USART Read'
   * */
  Group31_ProjectWork_EmbeddedS_B.ASCIItoString[0] = (int8_T)uartReadData;
  Group31_ProjectWork_EmbeddedS_B.ASCIItoString[1] = '\x00';

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/UART//USART Read'
   * */
  Group31_ProjectWork_Embedded_DW.temporalCounter_i1++;
  if ((uint8_T)Group31_ProjectWork_Embedded_DW.temporalCounter_i2 < 127) {
    Group31_ProjectWork_Embedded_DW.temporalCounter_i2 = (uint8_T)((uint8_T)
      Group31_ProjectWork_Embedded_DW.temporalCounter_i2 + 1);
  }

  if (Group31_ProjectWork_Embedded_DW.temporalCounter_i3 < 7) {
    Group31_ProjectWork_Embedded_DW.temporalCounter_i3++;
  }

  resultZC10 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_aw,
    ((real_T)DigitalPortRead_k)) != 0);
  resultZC9 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_a,
    ((real_T)DigitalPortRead_k)) != 0);
  resultZC8 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_fx,
    ((real_T)DigitalPortRead_o)) != 0);
  resultZC7 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_n,
    ((real_T)DigitalPortRead_o)) != 0);
  resultZC6 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_f,
    ((real_T)DigitalPortRead)) != 0);
  resultZC5 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_h,
    ((real_T)DigitalPortRead_c)) != 0);
  resultZC4 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_l,
    ((real_T)DigitalPortRead_c)) != 0);
  resultZC3 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_m,
    ((real_T)DigitalPortRead_c)) != 0);
  resultZC2 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_i,
    ((real_T)DigitalPortRead)) != 0);
  resultZC1 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC_d,
    ((real_T)pinReadLoc)) != 0);
  resultZC0 = ((int32_T)rt_ZCFcn(RISING_ZERO_CROSSING,
    &Group31_ProjectWork_Embedded_DW.previousZC,
    ((real_T)pinReadLoc)) != 0);
  if (Group31_ProjectWork_Embedded_DW.is_active_c3_Group31_ProjectWor == 0) {
    Group31_ProjectWork_Embedded_DW.is_active_c3_Group31_ProjectWor = 1U;
    Group31_ProjectWork_Embedded_DW.prima_attivazione = 1.0;
    Group31_ProjectWork_Embedded_DW.is_Group31_ProjectWork_Embedded =
      Group31_ProjectWork_Em_IN_CLEAR;
    strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
    Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
    for (c = 0; c < 10; c++) {
      Group31_ProjectWork_EmbeddedS_B.msgOut[c] = c_Value[c];
    }

    Group31_ProjectWork_EmbeddedS_B.msgOut[10] = '\x00';
  } else {
    switch (Group31_ProjectWork_Embedded_DW.is_Group31_ProjectWork_Embedded) {
     case Group31_ProjectWork_E_IN_ATTIVO:
      if (resultZC10 && (Group31_ProjectWork_Embedded_DW.config_comp_init == 1.0))
      {
        switch (Group31_ProjectWork_Embedded_DW.is_LED_UTENTE) {
         case Group31_ProjectWork_E_IN_ACCESO:
          Group31_ProjectWork_Embedded_DW.is_LED_UTENTE =
            Group31_Proj_IN_NO_ACTIVE_CHILD;
          break;

         case Group31_ProjectWork_E_IN_SPENTO:
          Group31_ProjectWork_Embedded_DW.is_LED_UTENTE =
            Group31_Proj_IN_NO_ACTIVE_CHILD;
          break;
        }

        switch (Group31_ProjectWork_Embedded_DW.is_MAIN) {
         case Group31_Proje_IN_CONFIGURAZIONE:
          Gr_exit_internal_CONFIGURAZIONE();
          Group31_ProjectWork_Embedded_DW.prima_attivazione = 0.0;
          Group31_ProjectWork_Embedded_DW.is_MAIN =
            Group31_Proj_IN_NO_ACTIVE_CHILD;
          break;

         case Group31_ProjectWo_IN_OPERAZIONE:
          switch (Group31_ProjectWork_Embedded_DW.is_LUCI) {
           case Group31_ProjectW_IN_LUCI_ACCESE:
            Group31_ProjectWork_Embedded_DW.is_LUCI =
              Group31_Proj_IN_NO_ACTIVE_CHILD;
            break;

           case Group31_ProjectW_IN_LUCI_SPENTE:
            Group31_ProjectWork_Embedded_DW.is_LUCI =
              Group31_Proj_IN_NO_ACTIVE_CHILD;
            break;

           case Group31_Pr_IN_LUCI_TEMPORIZZATE:
            Group31_ProjectWork_Embedded_DW.is_LUCI =
              Group31_Proj_IN_NO_ACTIVE_CHILD;
            break;
          }

          Group31_ProjectWork_Embedded_DW.is_MAIN =
            Group31_Proj_IN_NO_ACTIVE_CHILD;
          break;
        }

        Group31_ProjectWork_Embedded_DW.is_Group31_ProjectWork_Embedded =
          Group31_ProjectWork_IN_INATTIVO;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        for (c = 0; c < 58; c++) {
          Group31_ProjectWork_EmbeddedS_B.msgOut[c] = d_Value[c];
        }

        Group31_ProjectWork_EmbeddedS_B.msgOut[58] = '\x00';
      } else {
        if (Group31_ProjectWork_Embedded_DW.is_MAIN ==
            Group31_Proje_IN_CONFIGURAZIONE) {
          Group31_ProjectW_CONFIGURAZIONE(&pinReadLoc);

          /* case IN_OPERAZIONE: */
        } else if (resultZC8) {
          switch (Group31_ProjectWork_Embedded_DW.is_LUCI) {
           case Group31_ProjectW_IN_LUCI_ACCESE:
            Group31_ProjectWork_Embedded_DW.is_LUCI =
              Group31_Proj_IN_NO_ACTIVE_CHILD;
            break;

           case Group31_ProjectW_IN_LUCI_SPENTE:
            Group31_ProjectWork_Embedded_DW.is_LUCI =
              Group31_Proj_IN_NO_ACTIVE_CHILD;
            break;

           case Group31_Pr_IN_LUCI_TEMPORIZZATE:
            Group31_ProjectWork_Embedded_DW.is_LUCI =
              Group31_Proj_IN_NO_ACTIVE_CHILD;
            break;
          }

          Group31_ProjectWork_Embedded_DW.is_MAIN =
            Group31_Proje_IN_CONFIGURAZIONE;
          Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
            Group31_ProjectWor_IN_PRECONFIG;
          strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
          Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
          Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
        } else {
          if ((uint8_T)Group31_ProjectWork_Embedded_DW.temporalCounter_i2 >= 100)
          {
            Group31_ProjectWork_Embedded_DW.temporalCounter_i2 = 0U;
            Group31_Proje_enter_atomic_NOT2();
          } else {
            strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
            Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
            Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
          }

          switch (Group31_ProjectWork_Embedded_DW.is_LUCI) {
           case Group31_ProjectW_IN_LUCI_ACCESE:
            Group31_ProjectWork_EmbeddedS_B.rele_luci = 1.0;
            if (resultZC6 && (Group31_ProjectWork_Embedded_DW.durata_luci > 0.0))
            {
              Group31_ProjectWork_Embedded_DW.temporalCounter_i1 = 0U;
              Group31_ProjectWork_Embedded_DW.is_LUCI =
                Group31_Pr_IN_LUCI_TEMPORIZZATE;
            } else if (resultZC4) {
              Group31_ProjectWork_Embedded_DW.is_LUCI =
                Group31_ProjectW_IN_LUCI_SPENTE;
              Group31_ProjectWork_EmbeddedS_B.rele_luci = 0.0;
              Group31_ProjectWork_Embedded_DW.mod_luci = 0.0;
            }
            break;

           case Group31_ProjectW_IN_LUCI_SPENTE:
            Group31_ProjectWork_EmbeddedS_B.rele_luci = 0.0;
            if (resultZC5) {
              Group31_ProjectWork_Embedded_DW.is_LUCI =
                Group31_ProjectW_IN_LUCI_ACCESE;
              Group31_ProjectWork_EmbeddedS_B.rele_luci = 1.0;
            } else if (resultZC2 && (Group31_ProjectWork_Embedded_DW.durata_luci
                        > 0.0)) {
              Group31_ProjectWork_Embedded_DW.temporalCounter_i1 = 0U;
              Group31_ProjectWork_Embedded_DW.is_LUCI =
                Group31_Pr_IN_LUCI_TEMPORIZZATE;
              Group31_ProjectWork_EmbeddedS_B.rele_luci = 1.0;
            }
            break;

           default:
            /* case IN_LUCI_TEMPORIZZATE: */
            Group31_ProjectWork_EmbeddedS_B.rele_luci = 1.0;
            if (resultZC3 || (Group31_ProjectWork_Embedded_DW.temporalCounter_i1
                              >= (uint32_T)ceil
                              (Group31_ProjectWork_Embedded_DW.durata_luci *
                               10.0))) {
              Group31_ProjectWork_Embedded_DW.is_LUCI =
                Group31_ProjectW_IN_LUCI_SPENTE;
              Group31_ProjectWork_EmbeddedS_B.rele_luci = 0.0;
              Group31_ProjectWork_Embedded_DW.mod_luci = 0.0;
            }
            break;
          }
        }

        if (Group31_ProjectWork_Embedded_DW.is_LED_UTENTE ==
            Group31_ProjectWork_E_IN_ACCESO) {
          Group31_ProjectWork_EmbeddedS_B.led_utente = 1.0;
          if (Group31_ProjectWork_Embedded_DW.temporalCounter_i3 >= 5) {
            Group31_ProjectWork_Embedded_DW.temporalCounter_i3 = 0U;
            Group31_ProjectWork_Embedded_DW.is_LED_UTENTE =
              Group31_ProjectWork_E_IN_SPENTO;
            Group31_ProjectWork_EmbeddedS_B.led_utente = 0.0;
          }
        } else {
          /* case IN_SPENTO: */
          Group31_ProjectWork_EmbeddedS_B.led_utente = 0.0;
          if (Group31_ProjectWork_Embedded_DW.temporalCounter_i3 >= 5) {
            Group31_ProjectWork_Embedded_DW.temporalCounter_i3 = 0U;
            Group31_ProjectWork_Embedded_DW.is_LED_UTENTE =
              Group31_ProjectWork_E_IN_ACCESO;
            Group31_ProjectWork_EmbeddedS_B.led_utente = 1.0;
          }
        }
      }
      break;

     case Group31_ProjectWork_Em_IN_CLEAR:
      Group31_ProjectWork_Embedded_DW.is_Group31_ProjectWork_Embedded =
        Group31_ProjectWork_IN_INATTIVO;
      strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
      Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
      for (c = 0; c < 58; c++) {
        Group31_ProjectWork_EmbeddedS_B.msgOut[c] = d_Value[c];
      }

      Group31_ProjectWork_EmbeddedS_B.msgOut[58] = '\x00';
      break;

     default:
      /* case IN_INATTIVO: */
      if (resultZC9) {
        Group31_ProjectWork_Embedded_DW.is_Group31_ProjectWork_Embedded =
          Group31_ProjectWork_E_IN_ATTIVO;
        Group31_ProjectWork_Embedded_DW.is_MAIN =
          Group31_Proje_IN_CONFIGURAZIONE;
        Group31_ProjectWork_Embedded_DW.is_CONFIGURAZIONE =
          Group31_ProjectWor_IN_PRECONFIG;
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
        Group31_ProjectWork_Embedded_DW.temporalCounter_i3 = 0U;
        Group31_ProjectWork_Embedded_DW.is_LED_UTENTE =
          Group31_ProjectWork_E_IN_SPENTO;
        Group31_ProjectWork_EmbeddedS_B.led_utente = 0.0;
      } else {
        strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
        Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';
        Group31_ProjectWork_EmbeddedS_B.msgOut[0] = '\x00';
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* StringToASCII: '<Root>/String to ASCII' incorporates:
   *  MATLABSystem: '<Root>/UART//USART Write'
   */
  strncpy((char_T *)&uartWriteData[0], &Group31_ProjectWork_EmbeddedS_B.msgOut[0],
          127U);

  /* MATLABSystem: '<Root>/UART//USART Write' */
  MW_LPUART_TransmitUsingInterrupt
    (Group31_ProjectWork_Embedded_DW.obj_n.UARTHandle, &uartWriteData[0], 127U,
     0U, &pinReadLoc);

  /* MATLABSystem: '<S19>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (Group31_ProjectWork_EmbeddedS_B.led_utente != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S19>/Digital Port Write' */

  /* MATLABSystem: '<S21>/Digital Port Write' */
  portNameLoc = GPIOC;
  if (Group31_ProjectWork_EmbeddedS_B.rele_luci != 0.0) {
    c = 4;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 4U);

  /* End of MATLABSystem: '<S21>/Digital Port Write' */

  /* MATLABSystem: '<S23>/PWM Output' */
  setDutyCycleInPercentageChannel1
    (Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle,
     Group31_ProjectWork_EmbeddedS_B.ledR);
  setDutyCycleInPercentageChannel2
    (Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle,
     Group31_ProjectWork_EmbeddedS_B.ledG);
  setDutyCycleInPercentageChannel4
    (Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle,
     Group31_ProjectWork_EmbeddedS_B.ledB);

  /* MATLABSystem: '<S25>/PWM Output' */
  setDutyCycleInPercentageChannel1
    (Group31_ProjectWork_Embedded_DW.obj_b.TimerHandle,
     Group31_ProjectWork_EmbeddedS_B.duty_cycle);
}

/* Model initialize function */
void Group31_ProjectWork_EmbeddedSystem_initialize(void)
{
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectionSignal_Z =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectionSignal_h =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectionSigna_ha =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectionSign_ha5 =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectionSig_ha50 =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectionSi_ha50t =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectionS_ha50ta =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetection_ha50tat =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetectio_ha50tato =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetecti_ha50tatof =
    UNINITIALIZED_ZCSIG;
  Group31_ProjectWork_Emb_PrevZCX.SFunction_edgeDetect_ha50tatof1 =
    UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  Group31_ProjectWork_Embedded_DW.previousZC = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_d = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_i = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_m = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_l = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_h = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_f = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_n = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_fx = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_a = 3U;
  Group31_ProjectWork_Embedded_DW.previousZC_aw = 3U;
  Group31_ProjectWork_EmbeddedS_B.ledB = 255.0;
  Group31_ProjectWork_EmbeddedS_B.duty_cycle = 5.0;
  Group31_ProjectWork_Embedded_DW.temperatura = 16.0;
  Group31_ProjectWork_Embedded_DW.prima_attivazione = 1.0;
  strncpy(&Group31_ProjectWork_EmbeddedS_B.msgOut[0], "", 255U);
  Group31_ProjectWork_EmbeddedS_B.msgOut[255] = '\x00';

  /* SystemInitialize for Chart: '<Root>/Chart' */
  strncpy(&Group31_ProjectWork_Embedded_DW.uartMsg[0], "", 255U);
  Group31_ProjectWork_Embedded_DW.uartMsg[255] = '\x00';
  strncpy(&Group31_ProjectWork_Embedded_DW.strTemperatura[0], "", 255U);
  Group31_ProjectWork_Embedded_DW.strTemperatura[255] = '\x00';
  strncpy(&Group31_ProjectWork_Embedded_DW.strAngolo[0], "", 255U);
  Group31_ProjectWork_Embedded_DW.strAngolo[255] = '\x00';

  /* Start for MATLABSystem: '<Root>/UART//USART Read' */
  Group31_ProjectWork_Embedded_DW.obj.isInitialized = 0;
  Group31_ProjectWork_Embedded_DW.obj.matlabCodegenIsDeleted = false;
  Group31_Projec_SystemCore_setup(&Group31_ProjectWork_Embedded_DW.obj);

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  Group31_ProjectWork_Embedded_DW.obj_n.matlabCodegenIsDeleted = false;
  Group31_ProjectWork_Embedded_DW.obj_n.isSetupComplete = false;
  Group31_ProjectWork_Embedded_DW.obj_n.isInitialized = 1;
  Group31_Pro_UARTWrite_setupImpl(&Group31_ProjectWork_Embedded_DW.obj_n);
  Group31_ProjectWork_Embedded_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S23>/PWM Output' */
  Group31_ProjectWork_Embedded_DW.obj_i.matlabCodegenIsDeleted = false;
  Group31_ProjectWork_Embedded_DW.obj_i.isSetupComplete = false;
  Group31_ProjectWork_Embedded_DW.obj_i.isInitialized = 1;
  Group31_Pro_PWMOutput_setupImpl(&Group31_ProjectWork_Embedded_DW.obj_i);
  Group31_ProjectWork_Embedded_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S25>/PWM Output' */
  Group31_ProjectWork_Embedded_DW.obj_b.matlabCodegenIsDeleted = false;
  Group31_ProjectWork_Embedded_DW.obj_b.isSetupComplete = false;
  Group31_ProjectWork_Embedded_DW.obj_b.isInitialized = 1;
  Group31_P_PWMOutput_setupImpl_p(&Group31_ProjectWork_Embedded_DW.obj_b);
  Group31_ProjectWork_Embedded_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void Group31_ProjectWork_EmbeddedSystem_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/UART//USART Read' */
  if (!Group31_ProjectWork_Embedded_DW.obj.matlabCodegenIsDeleted) {
    Group31_ProjectWork_Embedded_DW.obj.matlabCodegenIsDeleted = true;
    if ((Group31_ProjectWork_Embedded_DW.obj.isInitialized == 1) &&
        Group31_ProjectWork_Embedded_DW.obj.isSetupComplete) {
      MW_LPUART_DeInit(Group31_ProjectWork_Embedded_DW.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UART//USART Read' */

  /* Terminate for MATLABSystem: '<Root>/UART//USART Write' */
  if (!Group31_ProjectWork_Embedded_DW.obj_n.matlabCodegenIsDeleted) {
    Group31_ProjectWork_Embedded_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Group31_ProjectWork_Embedded_DW.obj_n.isInitialized == 1) &&
        Group31_ProjectWork_Embedded_DW.obj_n.isSetupComplete) {
      MW_LPUART_DeInit(Group31_ProjectWork_Embedded_DW.obj_n.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UART//USART Write' */

  /* Terminate for MATLABSystem: '<S23>/PWM Output' */
  if (!Group31_ProjectWork_Embedded_DW.obj_i.matlabCodegenIsDeleted) {
    Group31_ProjectWork_Embedded_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Group31_ProjectWork_Embedded_DW.obj_i.isInitialized == 1) &&
        Group31_ProjectWork_Embedded_DW.obj_i.isSetupComplete) {
      disableCounter(Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle);
      disableTimerInterrupts(Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle,
        0);
      disableTimerChannel1(Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel2(Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel4(Group31_ProjectWork_Embedded_DW.obj_i.TimerHandle,
                           ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/PWM Output' */

  /* Terminate for MATLABSystem: '<S25>/PWM Output' */
  if (!Group31_ProjectWork_Embedded_DW.obj_b.matlabCodegenIsDeleted) {
    Group31_ProjectWork_Embedded_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Group31_ProjectWork_Embedded_DW.obj_b.isInitialized == 1) &&
        Group31_ProjectWork_Embedded_DW.obj_b.isSetupComplete) {
      disableCounter(Group31_ProjectWork_Embedded_DW.obj_b.TimerHandle);
      disableTimerInterrupts(Group31_ProjectWork_Embedded_DW.obj_b.TimerHandle,
        0);
      disableTimerChannel1(Group31_ProjectWork_Embedded_DW.obj_b.TimerHandle,
                           ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S25>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
