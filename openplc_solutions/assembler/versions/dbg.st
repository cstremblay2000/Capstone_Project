PROGRAM program0
  VAR CONSTANT
    always_true : BOOL := 1;
    always_false : BOOL := 0;
  END_VAR
  VAR
    moving_x AT %IX100.0 : BOOL;
    moving_z AT %IX100.1 : BOOL;
    item_detected AT %IX100.2 : BOOL;
    lid_at_place AT %IX100.3 : BOOL;
    lid_clamped AT %IX100.4 : BOOL;
    pos_at_limit_lid AT %IX100.5 : BOOL;
    base_at_place AT %IX100.6 : BOOL;
    base_clamped AT %IX100.7 : BOOL;
    pos_at_limit_base AT %IX101.0 : BOOL;
    part_leaving AT %IX101.1 : BOOL;
    start AT %IX101.2 : BOOL;
    reset AT %IX101.3 : BOOL;
    stop AT %IX101.4 : BOOL;
    estop AT %IX101.5 : BOOL;
    auto AT %IX101.6 : BOOL;
    factoryio_running AT %IX101.7 : BOOL;
    move_x AT %QX100.0 : BOOL;
    move_z AT %QX100.1 : BOOL;
    grab AT %QX100.2 : BOOL;
    lids_conveyor AT %QX100.3 : BOOL;
    clamp_lid AT %QX100.4 : BOOL;
    pos_raise_lid AT %QX100.5 : BOOL;
    bases_conveyor AT %QX100.6 : BOOL;
    clamp_base AT %QX100.7 : BOOL;
    pos_raise_base AT %QX101.0 : BOOL;
    bases_emitter AT %QX101.1 : BOOL;
    lids_emitter AT %QX101.2 : BOOL;
    stop_light AT %QX101.3 : BOOL;
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
    TON1 : TON;
    TON2 : TON;
    F_TRIG3 : F_TRIG;
    R_TRIG0 : R_TRIG;
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
  TON0(IN := NOT(move_z) AND grab AND item_detected, PT := T#750ms);
  IF NOT(moving_z) AND TON0.Q THEN
    move_x := TRUE; (*set*)
  END_IF;
  TON1(IN := move_x AND NOT(move_z) AND grab AND item_detected, PT := T#750ms);
  IF NOT(moving_x) AND TON1.Q THEN
    move_z := TRUE; (*set*)
  END_IF;
  TON2(IN := move_z AND move_x AND grab AND item_detected, PT := T#750ms);
  IF NOT(moving_z) AND TON2.Q THEN
    grab := FALSE; (*reset*)
  END_IF;
  IF move_z AND move_x AND NOT(grab) AND item_detected THEN
    pos_raise_base := TRUE; (*set*)
  END_IF;
  IF pos_raise_base THEN
    move_z := FALSE; (*reset*)
  END_IF;
  IF pos_raise_base THEN
    move_x := FALSE; (*reset*)
  END_IF;
  F_TRIG3(CLK := part_leaving);
  IF F_TRIG3.Q THEN
    pos_raise_base := FALSE; (*reset*)
  END_IF;
  IF reset THEN
    pos_raise_base := FALSE; (*reset*)
  END_IF;
  R_TRIG0(CLK := pos_at_limit_lid AND pos_raise_base);
  IF R_TRIG0.Q THEN
    bases_conveyor := TRUE; (*set*)
  END_IF;
  IF R_TRIG0.Q THEN
    lids_conveyor := TRUE; (*set*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
