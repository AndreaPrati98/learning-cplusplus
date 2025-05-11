#ifndef LIGHT_STATE_H
#define LIGHT_STATE_H

#include <map>

namespace FSM_Definitions 
{
    enum class LightState {
        Off,
        Low,
        Medium,
        High
    };
    
    // it's really important to define the variable as 'inline'
    // or 'extern' since it is in a .h file.
    inline std::map<LightState, LightState> lightTransitions = {
        {LightState::Off, LightState::Low},
        {LightState::Low, LightState::Medium},
        {LightState::Medium, LightState::High},
        {LightState::High, LightState::Off},
    };

}



#endif