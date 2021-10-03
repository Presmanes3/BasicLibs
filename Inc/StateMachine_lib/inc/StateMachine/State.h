#ifndef _STATE_H_
#define _STATE_H_

#include "stdint.h"
#include "stdio.h"
#include "StateMachine_lib/inc/Action/Action.h"
#include "Vector_lib/ArrayPointerVector.h"
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

		ArrayPointerVector<Action>* get_action_vector(ActionType type);

		void add_action(ActionType type, Action *action_);

		void set_execution_time_calculator_timer();

	private:

		bool action_exist(Action *action);

		void next_update_action();

	public:

		ArrayPointerVector<Action> update_actions 	= ArrayPointerVector<Action>();
		ArrayPointerVector<Action> enter_actions	= ArrayPointerVector<Action>();
		ArrayPointerVector<Action> exit_actions		= ArrayPointerVector<Action>();

		ExecutionTimeCalculator update_actions_time = ExecutionTimeCalculator();
		ExecutionTimeCalculator enter_actions_time  = ExecutionTimeCalculator();
		ExecutionTimeCalculator exit_actions_time   = ExecutionTimeCalculator();

		uint32_t current_update_action = 0;
};

#endif /*_STATE_H_*/
