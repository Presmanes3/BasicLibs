#include "StateMachine_lib/inc/StateMachine/StateMachine.h"

void StateMachine::set_state(uint8_t id, State *state)
{
    if (id >= 0 && id < TOTAL_ALLOWED_STATES)
    {
        this->statePool[id] = state;
    }
}

State *StateMachine::get_state(uint8_t id)
{
    if (id >= 0 && id < TOTAL_ALLOWED_STATES)
    {
        return this->statePool[id];
    }

    return nullptr;
}

uint8_t StateMachine::get_total_states()
{
    return TOTAL_ALLOWED_STATES;
}
