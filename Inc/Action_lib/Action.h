#ifndef _ACTION_H_
#define _ACTION_H_

#include "Properties_lib/ActivationProperty.h"
#include "SoftwareTimer_lib/ExecutionTimeCalculator/ExecutionTimeCalculator.h"
#include "stdint.h"
#include "math.h"

#ifdef STM32F103xB
#include "stm32f1xx_hal.h"

#endif

#ifdef STM32F437xx

#endif

class SoftwareTimer;

class Action: public ActivationProperty {
	public:
		Action(bool func(), SoftwareTimer *timer) {
			this->set_callback(func);
			this->set_timer(timer);
		}

		Action(bool func(), SoftwareTimer *timer, ExecutionTimeCalculator* time_calculator) {

			this->set_callback(func);
			this->set_timer(timer);
			this->set_execution_time_calculator(time_calculator);
		}

		bool (*callback)();

		void set_timer(SoftwareTimer *timer);
		void set_execution_time_calculator(ExecutionTimeCalculator *time_calculator);
		void set_repetition(uint32_t repetitions);
		void set_callback(bool func());

		void reset();

		bool execute();

		bool is_executable();

		bool is_bloqued();

	private:

		void add_time_executed();

		bool check_repetitions();

		bool check_execution_conditions();

	private:
		SoftwareTimer *timer = nullptr;
		ExecutionTimeCalculator execution_time_calculator = ExecutionTimeCalculator();

		uint32_t times_executed = 0;
		uint32_t repetitions = 0;

		bool _is_periodic = false;
		bool _is_executable = false;
		bool _has_repetitions = false;
		bool _has_exceed_repetitions = false;
};

#endif
