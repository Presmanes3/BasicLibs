#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include "stdint.h"
#include "Vector_lib/ArrayPointerVector.h"
#include "SoftwareTimer_lib/ExecutionTimeCalculator/ExecutionTimeCalculator.h"

class State;
class TransitionCheck;

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
    StateMachine(){

    }

    void add_state_pool(State** pool, uint32_t size){
    	this->statePool.set_pool(pool, size);
    }

    void add_check_transitions_pool(TransitionCheck** pool, uint32_t size){
    	this->transitionChecksPool.set_pool(pool, size);
    }


private:
    State *currentState;
    ArrayPointerVector<State> statePool;

    TransitionCheck* currentTransitionCheck;
    ArrayPointerVector<TransitionCheck> transitionChecksPool;

    ExecutionTimeCalculator update_time	= ExecutionTimeCalculator();
};

#endif
