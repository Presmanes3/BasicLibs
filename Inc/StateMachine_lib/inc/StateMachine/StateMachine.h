#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include "stdint.h"

class State;

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
    StateMachine()
    {
        this->currentState = nullptr;

        for (uint8_t x = 0; x < TOTAL_ALLOWED_STATES; x++)
        {
            this->statePool[x] = nullptr;
        }
    }

    /**
         * @brief Set [State] in state array at position [id]
         * 
         * @param id 
         * @param state 
         */
    void set_state(uint8_t id, State *state);

    /**
         * @brief Get the state object
         * 
         * @param id 
         */
    State *get_state(uint8_t id);

    /**
         * @brief Update current state
         * 
         */
    void update_current_state();

    /**
         * @brief Change to new state
         * 
         * @param new_state 
         */
    void change_current_state(uint8_t new_state);

    /**
         * @brief Get the total states items
         * 
         * @return uint8_t 
         */
    uint8_t get_total_states();

private:
    State *currentState;

    State *statePool[TOTAL_ALLOWED_STATES];
};

#endif