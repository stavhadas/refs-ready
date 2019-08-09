#include "RefUnit.h"

void RefUnit::on_button_pressed()
{
    switch (this->m_state)
    {
    case STATE__NO_MATCH:
        break;
    case STATE__WAITING:
        this->m_led.blink(500);
        break;
    case STATE__READY:
        /* TODO: Should blink again */
        this->m_led.turn_on();
    
    default:
        break;
    }
};

Led& RefUnit::get_led()
{
    return this->m_led;
};