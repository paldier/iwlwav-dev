/******************************************************************************

                               Copyright (c) 2012
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
#include "mtlkinc.h"
#include "mtlk_param_db.h"
#include "core_pdb_def.h"
#include "radio_pdb_def.h"

/* include section for the parameter definitions from each module */
/* #include "mtlk_module1_params.h"*/
/* #include "mtlk_module2_params.h"*/

const mtlk_pdb_initial_value *mtlk_pdb_initial_values[] = {
  mtlk_core_parameters,             /* core module parameters */
  NULL,
};

/* Radio module parameters */

#ifdef CPTCFG_IWLWAV_LINDRV_HW_PCIEG5
const mtlk_pdb_initial_value *wave_pdb_initial_values_pcieg5_wrx300[] = {
  wave_radio_parameters_pcieg5_wrx300, /* radio parameters */
  NULL,
};
const mtlk_pdb_initial_value *wave_pdb_initial_values_pcieg5_wrx500[] = {
  wave_radio_parameters_pcieg5_wrx500, /* radio parameters */
  NULL,
};
#endif /* CPTCFG_IWLWAV_LINDRV_HW_PCIEG5 */

#ifdef CPTCFG_IWLWAV_LINDRV_HW_PCIEG6
const mtlk_pdb_initial_value *wave_pdb_initial_values_pcieg6_wrx300[] = {
  wave_radio_parameters_pcieg6_wrx300, /* radio parameters */
  NULL,
};
const mtlk_pdb_initial_value *wave_pdb_initial_values_pcieg6_wrx500[] = {
  wave_radio_parameters_pcieg6_wrx500, /* radio parameters */
  NULL,
};
#endif /* CPTCFG_IWLWAV_LINDRV_HW_PCIEG6 */

const mtlk_pdb_initial_value *wave_pdb_initial_values_radio[] = {
  wave_radio_parameters,
  NULL
};
