PROGRAM main
  VAR
    Conveyor AT %QX0.0 : BOOL;
    Prox AT %IX0.0 : BOOL;
    StartButton AT %IX0.1 : BOOL;
  END_VAR

  IF Prox THEN
    Conveyor := FALSE; (*reset*)
  END_IF;
  IF StartButton THEN
    Conveyor := TRUE; (*set*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : main;
  END_RESOURCE
END_CONFIGURATION
