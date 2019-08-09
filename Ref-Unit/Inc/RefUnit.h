#ifndef __REF_UNIT_H__
#define __REF_UNIT_H__

#include "pinout.h"
#include "led.h"

class RefUnit
{
public:
    enum State
    {
        STATE__NO_MATCH,
        STATE__WAITING,
        STATE__READY
    };
    RefUnit() : m_state{STATE__NO_MATCH},
                m_button_port{D2},
                m_led{D2}
                {};

    RefUnit(DigitalInputOutput button_port, DigitalInputOutput led_port) : m_state{STATE__NO_MATCH},
                                                                           m_button_port{button_port},
                                                                           m_led{Led(led_port)}
                                                                           {pinMode(button_port, INPUT);};

    void on_button_pressed();

    Led& get_led();

private:
    State m_state;
    DigitalInputOutput m_button_port;
    Led m_led;
};

#endif /* __REF_UNIT_H__ */