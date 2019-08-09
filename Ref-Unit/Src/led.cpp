#include "led.h"

void Led::turn_on()
{
    this->m_state = STATE__ON;
};

void Led::turn_off()
{
    this->m_state = STATE__OFF;
};

void Led::blink(unsigned int interval)
{
    this->m_state = STATE__BLINK;
    this->m_interval = interval;
};

void Led::operate()
{
    switch (this->m_state)
    {
    case STATE__OFF:
        digitalWrite(this->m_port, LOW);
        break;
    case STATE__ON:
        digitalWrite(this->m_port, HIGH);
        break;
    case STATE__BLINK:
        if ((millis() % this->m_interval) == 0)
        {
            if (this->m_blink_state == LOW)
            {
                this->m_blink_state = HIGH;
            }
            else
            {
                this->m_blink_state = LOW;
            }
        }
        digitalWrite(this->m_port, this->m_blink_state);

        break;
    }
};