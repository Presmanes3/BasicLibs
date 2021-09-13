#include "StateMachine_lib/inc/Action/Action.h"

void Action::set_callback(bool callback_function())
{
    this->execute = callback_function;

    if (callback_function != nullptr)
    {
        this->_can_be_executed = true;
    }
}

bool Action::can_be_executed()
{
    return this->_can_be_executed;
}
