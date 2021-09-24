#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include "stdint.h"
#include "StateMachine_lib/inc/ExecutionTimeCalculator/ExecutionTimeCalculator.h"

class State;
class TransitionCheck;
class ExecutionTimeCalculator;

// ================== DEFINES ================== //
#define TOTAL_ALLOWED_STATES 3

/**
 * @brief Construct a new StateMachine object
 * 
 */
class StateMachine
{

public:
    /**
         * @brief Construct a new State Machine object
         * 
         */
    StateMachine();

    void add_state_pool(State);


private:
    State *currentState;
    State **statePool;

    TransitionCheck* currentTransitionCheck;
    TransitionCheck** transitionChecksPool;

    ExecutionTimeCalculator update_time   = ExecutionTimeCalculator();
};

#endif
