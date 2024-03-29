#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,ALWAYS_TRUE)
  __DECLARE_VAR(BOOL,ALWAYS_FALSE)
  __DECLARE_VAR(BOOL,MOVING_X)
  __DECLARE_VAR(BOOL,MOVING_Z)
  __DECLARE_VAR(BOOL,ITEM_DETECTED)
  __DECLARE_VAR(BOOL,LID_AT_PLACE)
  __DECLARE_VAR(BOOL,LID_CLAMPED)
  __DECLARE_VAR(BOOL,POS_AT_LIMIT_LID)
  __DECLARE_VAR(BOOL,BASE_AT_PLACE)
  __DECLARE_VAR(BOOL,BASE_CLAMPED)
  __DECLARE_VAR(BOOL,POS_AT_LIMIT_BASE)
  __DECLARE_VAR(BOOL,PART_LEAVING)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,RESET)
  __DECLARE_VAR(BOOL,STOP)
  __DECLARE_VAR(BOOL,ESTOP)
  __DECLARE_VAR(BOOL,AUTO)
  __DECLARE_VAR(BOOL,FACTORYIO_RUNNING)
  __DECLARE_VAR(BOOL,MOVE_X)
  __DECLARE_VAR(BOOL,MOVE_Z)
  __DECLARE_VAR(BOOL,GRAB)
  __DECLARE_VAR(BOOL,LIDS_CONVEYOR)
  __DECLARE_VAR(BOOL,CLAMP_LID)
  __DECLARE_VAR(BOOL,POS_RAISE_LID)
  __DECLARE_VAR(BOOL,BASES_CONVEYOR)
  __DECLARE_VAR(BOOL,CLAMP_BASE)
  __DECLARE_VAR(BOOL,POS_RAISE_BASE)
  __DECLARE_VAR(BOOL,BASES_EMITTER)
  __DECLARE_VAR(BOOL,LIDS_EMITTER)
  __DECLARE_VAR(BOOL,STOP_LIGHT)
  __DECLARE_VAR(BOOL,MACHINE_READY)
  __DECLARE_VAR(BOOL,START_EMITTERS)
  __DECLARE_VAR(BOOL,EMIT_NEXT)
  __DECLARE_VAR(BOOL,PROCESS_STARTED)
  __DECLARE_VAR(BOOL,PROCESS_FINISHED)
  __DECLARE_VAR(INT,STEP_NUM)
  __DECLARE_VAR(BOOL,FIRST_PART)
  __DECLARE_VAR(BOOL,BASE_READY)
  __DECLARE_VAR(BOOL,LID_READY)
  F_TRIG F_TRIG0;
  F_TRIG F_TRIG1;
  TON TON0;
  TON TON1;
  TON TON2;
  F_TRIG F_TRIG3;
  R_TRIG R_TRIG0;

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
