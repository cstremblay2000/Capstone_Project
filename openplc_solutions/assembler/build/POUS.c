#include "POUS.h"
void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->ALWAYS_TRUE,1,retain)
  __INIT_VAR(data__->ALWAYS_FALSE,0,retain)
  __INIT_VAR(data__->MOVING_X,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVING_Z,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ITEM_DETECTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LID_AT_PLACE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LID_CLAMPED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POS_AT_LIMIT_LID,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BASE_AT_PLACE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BASE_CLAMPED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POS_AT_LIMIT_BASE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PART_LEAVING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ESTOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FACTORYIO_RUNNING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE_X,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE_Z,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GRAB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LIDS_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLAMP_LID,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POS_RAISE_LID,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BASES_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLAMP_BASE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POS_RAISE_BASE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BASES_EMITTER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LIDS_EMITTER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MACHINE_READY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START_EMITTERS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EMIT_NEXT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PROCESS_STARTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PROCESS_FINISHED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STEP_NUM,0,retain)
  __INIT_VAR(data__->FIRST_PART,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BASE_READY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LID_READY,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG0,retain);
  F_TRIG_init__(&data__->F_TRIG1,retain);
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  F_TRIG_init__(&data__->F_TRIG2,retain);
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  if (__GET_VAR(data__->START,)) {
    __SET_VAR(data__->,LIDS_CONVEYOR,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->START,)) {
    __SET_VAR(data__->,BASES_CONVEYOR,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->F_TRIG0.,CLK,,__GET_VAR(data__->LID_AT_PLACE,));
  F_TRIG_body__(&data__->F_TRIG0);
  if (__GET_VAR(data__->F_TRIG0.Q,)) {
    __SET_VAR(data__->,LIDS_CONVEYOR,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->F_TRIG0.Q,)) {
    __SET_VAR(data__->,CLAMP_LID,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->LID_CLAMPED,)) {
    __SET_VAR(data__->,MOVE_Z,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->LID_CLAMPED,)) {
    __SET_VAR(data__->,GRAB,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,CLAMP_BASE,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,CLAMP_LID,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,GRAB,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,MOVE_Z,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,MOVE_X,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,BASES_CONVEYOR,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RESET,)) {
    __SET_VAR(data__->,LIDS_CONVEYOR,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->BASE_AT_PLACE,));
  F_TRIG_body__(&data__->F_TRIG1);
  if (__GET_VAR(data__->F_TRIG1.Q,)) {
    __SET_VAR(data__->,BASES_CONVEYOR,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->F_TRIG1.Q,)) {
    __SET_VAR(data__->,CLAMP_BASE,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->ITEM_DETECTED,)) {
    __SET_VAR(data__->,CLAMP_LID,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->ITEM_DETECTED,)) {
    __SET_VAR(data__->,MOVE_Z,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->ITEM_DETECTED,)) {
    __SET_VAR(data__->,CLAMP_BASE,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TON0.,IN,,((!(__GET_VAR(data__->MOVE_Z,)) && __GET_VAR(data__->GRAB,)) && __GET_VAR(data__->ITEM_DETECTED,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  if ((!(__GET_VAR(data__->MOVING_Z,)) && __GET_VAR(data__->TON0.Q,))) {
    __SET_VAR(data__->,MOVE_X,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON1.,IN,,(((__GET_VAR(data__->MOVE_X,) && !(__GET_VAR(data__->MOVE_Z,))) && __GET_VAR(data__->GRAB,)) && __GET_VAR(data__->ITEM_DETECTED,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  if ((!(__GET_VAR(data__->MOVING_X,)) && __GET_VAR(data__->TON1.Q,))) {
    __SET_VAR(data__->,MOVE_Z,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON2.,IN,,(((__GET_VAR(data__->MOVE_Z,) && __GET_VAR(data__->MOVE_X,)) && __GET_VAR(data__->GRAB,)) && __GET_VAR(data__->ITEM_DETECTED,)));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON2);
  if ((!(__GET_VAR(data__->MOVING_Z,)) && __GET_VAR(data__->TON2.Q,))) {
    __SET_VAR(data__->,GRAB,,__BOOL_LITERAL(FALSE));
  };
  if ((((__GET_VAR(data__->MOVE_Z,) && __GET_VAR(data__->MOVE_X,)) && !(__GET_VAR(data__->GRAB,))) && __GET_VAR(data__->ITEM_DETECTED,))) {
    __SET_VAR(data__->,MOVE_Z,,__BOOL_LITERAL(FALSE));
  };
  if ((((__GET_VAR(data__->MOVE_Z,) && __GET_VAR(data__->MOVE_X,)) && !(__GET_VAR(data__->GRAB,))) && __GET_VAR(data__->ITEM_DETECTED,))) {
    __SET_VAR(data__->,MOVE_X,,__BOOL_LITERAL(FALSE));
  };
  if ((((__GET_VAR(data__->MOVE_Z,) && __GET_VAR(data__->MOVE_X,)) && !(__GET_VAR(data__->GRAB,))) && __GET_VAR(data__->ITEM_DETECTED,))) {
    __SET_VAR(data__->,POS_RAISE_BASE,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->POS_AT_LIMIT_BASE,) && __GET_VAR(data__->POS_RAISE_BASE,))) {
    __SET_VAR(data__->,BASES_CONVEYOR,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->POS_AT_LIMIT_BASE,) && __GET_VAR(data__->POS_RAISE_BASE,))) {
    __SET_VAR(data__->,LIDS_CONVEYOR,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->F_TRIG2.,CLK,,(__GET_VAR(data__->PART_LEAVING,) && __GET_VAR(data__->POS_AT_LIMIT_BASE,)));
  F_TRIG_body__(&data__->F_TRIG2);
  if (__GET_VAR(data__->F_TRIG2.Q,)) {
    __SET_VAR(data__->,POS_RAISE_BASE,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





