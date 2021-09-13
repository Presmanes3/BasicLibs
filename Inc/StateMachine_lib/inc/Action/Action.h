#ifndef _ACTION_H_
#define _ACTION_H_

#include "stdint.h"

class SoftwareTimer;

class Action
{
public:
    Action()
    {
        this->execute = nullptr;
    }

    /**
   * @brief Set the callback function
   *
   * @param callback_function
   */
    void set_callback(bool callback_function());

    /**
   * @brief execute the action
   *
   */
    bool (*execute)();

    /**
     * @brief Return is action can be executed
     * 
     * @return true 
     * @return false 
     */
    bool can_be_executed();

private:
    bool _can_be_executed = false;
    bool _is_periodic = false;

    SoftwareTimer *timer;

    uint32_t total_repetitions = 0;
};

#endif