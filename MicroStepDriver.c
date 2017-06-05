#include "MicroStepDriver.h"
#include "mcc_generated_files/mcc.h"

typedef enum{
    MICROSTEP1,
    MICROSTEP2,
    MICROSTEP3,
    MICROSTEP4,
    MICROSTEP5,
    MICROSTEP6,
    MICROSTEP7,
    MICROSTEP8
}t_MicroStepMEF;

static t_MicroStepMEF EstadoActual; 