#ifndef _STATE_H_
#define _STATE_H_

#include "stdint.h"
#include "stdio.h"
#include "StateMachine_lib/inc/Action/Action.h"

/**
 * @brief
 *
 * @tparam N
 */
template <int N>
class State
{
	// Public methods
public:
	/**
   * @brief Construct a new State object
   *
   */
	State()
	{
		for (uint8_t x = 0; x < N; x++)
		{
			this->action_pool[x] = nullptr;
		}

		this->current_action = 0;
	}

	/**
   * @brief Virtual method for updating the state
   *
   */
	void update()
	{
		uint8_t action_id = this->current_action;
		if (this->action_pool[action_id] != nullptr)
		{
			if (this->action_pool[action_id]->can_be_executed())
			{
				this->action_pool[action_id]->execute();
			}
		}

		this->update_new_action();
	}

	/**
   * @brief Virtual method for entering to the state
   *
   */
	void enter() {}

	/**
   * @brief Virtual method for initialization of the state
   *
   */
	void init() {}

	/**
   * @brief Handle current_action variable in orde to not overflow it
   *
   */
	void update_new_action()
	{
		if (this->current_action + 1 >= N)
		{
			this->current_action = 0;
		}
		else
		{
			this->current_action++;
		}
	}

	/**
   * @brief Add a new Action to the array
   *
   * @param t
   */
	void add_action(Action *t)
	{
		for (uint32_t x = 0; x < N; x++)
		{
			if (this->action_pool[x] == nullptr)
			{
				this->action_pool[x] = t;
				break;
			}
		}
	}

public:
	Action *action_pool[N];
	uint32_t current_action;
};

#endif /*_STATE_H_*/
