#ifndef __LED_H__
#define __LED_H__

#include "pinout.h"

class Led
{
public:
    enum State
    {
        STATE__OFF,
        STATE__ON,
        STATE__BLINK
    };
    Led (DigitalInputOutput port) : m_port{port}, m_state{STATE__OFF}, m_interval{0} ,m_blink_state{LOW}{ pinMode(port, OUTPUT); };

        void turn_on();
        void turn_off();
        void blink(unsigned int interval);

        void operate();

private:
    DigitalInputOutput m_port;
    State m_state;
    int m_blink_state;
    unsigned int m_interval;
};

#endif /* __LED_H__ */