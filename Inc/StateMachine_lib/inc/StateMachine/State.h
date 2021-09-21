#ifndef _STATE_H_
#define _STATE_H_

#include "stdint.h"
#include "stdio.h"
#include "StateMachine_lib/inc/Action/Action.h"
#include "StateMachine_lib/inc/Action/ActionVector.h"
#include "StateMachine_lib/inc/ExecutionTimeCalculator/ExecutionTimeCalculator.h"

#ifdef STM32F103xB
#include "stm32f1xx_hal.h"

#endif

#ifdef STM32F437xx

#endif

enum ActionType {
	ACTION_UPDATE = 0,

	ACTION_ENTER = 1,

	ACTION_EXIT = 2
};

class State {
		// Public methods
	public:
		/**
		 * @brief Construct a new State object
		 *
		 */
		State();

		void update();

		void enter();

		void exit();

		void init();

		ActionVector* get_action_vector(ActionType type);

		void add_action(ActionType type, Action *action_);

		void set_execution_time_calculator_timer();

	private:

		bool action_exist(Action *action);

		void next_update_action();

	public:

		ActionVector update_actions;
		ActionVector enter_actions;
		ActionVector exit_actions;

		ExecutionTimeCalculator* update_actions_time;
		ExecutionTimeCalculator* enter_actions_time;
		ExecutionTimeCalculator* exit_actions_time;

		uint8_t current_update_action = 0;
};

#endif /*_STATE_H_*/
