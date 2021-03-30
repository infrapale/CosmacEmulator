
#include <stdint.h>
#include "registers.h"

//cosmac_register_st register;
uint32_t register;

void cpu_reset(void)
{
    memset(&register,0x00, sizeof(cosmac_register_st));
}
