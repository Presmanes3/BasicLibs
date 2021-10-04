#ifndef _TRANSITION_CHECKS_H_
#define _TRANSITION_CHECKS_H_

#include "Vector_lib/ArrayPointerVector.h"
#include "SoftwareTimer_lib/ExecutionTimeCalculator/ExecutionTimeCalculator.h"

class Action;
class State;

class TransitionChecks {
	public:

		TransitionChecks();
		TransitionChecks(State* dst);
		TransitionChecks(State* dst, Action** checks, uint32_t size);

		State* check_all_transitions();
		State* check_new_transition();

		void add_checking(Action* action);

		ArrayPointerVector<Action>* get_checkings_vector();

		void set_destiny(State* dts);

		State* get_destiny();

	private:
		ArrayPointerVector<Action> 	checks;

		State*	destiny_state;

		ExecutionTimeCalculator exec_time_calculator;
};

#endif
