TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM program0
  VAR CONSTANT
    always_true : BOOL := 1;
    always_false : BOOL := 0;
  END_VAR
  VAR
    moving_x : BOOL;
    moving_z : BOOL;
    item_detected : BOOL;
    lid_at_place : BOOL;
    lid_clamped : BOOL;
    pos_at_limit_lid : BOOL;
    base_at_place : BOOL;
    base_clamped : BOOL;
    pos_at_limit_base : BOOL;
    part_leaving : BOOL;
    start : BOOL;
    reset : BOOL;
    stop : BOOL;
    estop : BOOL;
    auto : BOOL;
    factoryio_running : BOOL;
    move_x : BOOL;
    move_z : BOOL;
    grab : BOOL;
    lids_conveyor : BOOL;
    clamp_lid : BOOL;
    pos_raise_lid : BOOL;
    bases_conveyor : BOOL;
    clamp_base : BOOL;
    pos_raise_base : BOOL;
    bases_emitter : BOOL;
    lids_emitter : BOOL;
    stop_light : BOOL;
  END_VAR
  VAR
    machine_ready : BOOL;
    start_emitters : BOOL;
    emit_next : BOOL;
    process_started : BOOL;
    process_finished : BOOL;
    step_num : INT;
    first_part : BOOL;
    base_ready : BOOL;
    lid_ready : BOOL;
    F_TRIG0 : F_TRIG;
    F_TRIG1 : F_TRIG;
    TON0 : TON;
  END_VAR

  IF start THEN
    lids_conveyor := TRUE; (*set*)
  END_IF;
  IF start THEN
    bases_conveyor := TRUE; (*set*)
  END_IF;
  F_TRIG0(CLK := lid_at_place);
  IF F_TRIG0.Q THEN
    lids_conveyor := FALSE; (*reset*)
  END_IF;
  IF F_TRIG0.Q THEN
    clamp_lid := TRUE; (*set*)
  END_IF;
  IF lid_clamped THEN
    move_z := TRUE; (*set*)
  END_IF;
  IF lid_clamped THEN
    grab := TRUE; (*set*)
  END_IF;
  IF reset THEN
    clamp_base := FALSE; (*reset*)
  END_IF;
  IF reset THEN
    clamp_lid := FALSE; (*reset*)
  END_IF;
  IF reset THEN
    grab := FALSE; (*reset*)
  END_IF;
  IF reset THEN
    move_z := FALSE; (*reset*)
  END_IF;
  IF reset THEN
    move_x := FALSE; (*reset*)
  END_IF;
  IF reset THEN
    bases_conveyor := FALSE; (*reset*)
  END_IF;
  IF reset THEN
    lids_conveyor := FALSE; (*reset*)
  END_IF;
  F_TRIG1(CLK := base_at_place);
  IF F_TRIG1.Q THEN
    bases_conveyor := FALSE; (*reset*)
  END_IF;
  IF F_TRIG1.Q THEN
    clamp_base := TRUE; (*set*)
  END_IF;
  IF item_detected THEN
    clamp_lid := FALSE; (*reset*)
  END_IF;
  IF item_detected THEN
    move_z := FALSE; (*reset*)
  END_IF;
  IF item_detected THEN
    clamp_base := FALSE; (*reset*)
  END_IF;
  TON0(IN := item_detected, PT := T#500ms);
  IF TON0.Q THEN
    move_x := TRUE; (*set*)
  END_IF;
  IF NOT(moving_x) AND grab AND move_x THEN
    move_z := TRUE; (*set*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
