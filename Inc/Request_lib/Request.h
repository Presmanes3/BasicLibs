#ifndef _REQUEST_H_
#define _REQUEST_H_

#include "Properties_lib/ActivationProperty.h"
#include "SoftwareTimer_lib/ExecutionTimeCalculator/ExecutionTimeCalculator.h"
#include "SoftwareTimer_lib/SoftwareTimer.h"
#include "Action_lib/Action.h"
#include "stdint.h"
#include "math.h"

#ifdef STM32F103xB
#include "stm32f1xx_hal.h"

#endif

#ifdef STM32F437xx

#endif

class SoftwareTimer;

class Request: public ActivationProperty {
	public:
		Request(bool petition_f(), bool response_f(), uint32_t retry_timeout, uint32_t num_petitions);

		void reset();

		void init();

		void stop();

		void start();

		bool update();

		bool check_response();

		bool has_failed();

		bool has_success();

		void change_number_petitiosn(uint32_t new_val);

		uint32_t get_number_petitions();

	private:

		void trying();

		void failed();

		void success();

		void add_fail();

		void add_success();
	private:
		SoftwareTimer retry_timer = SoftwareTimer(50, TIMER_BASE_TIME::BASE_MILLIS);

		Action petition = Action(nullptr, &retry_timer);
		Action response = Action(nullptr, nullptr);

		ExecutionTimeCalculator execution_time_calculator;

		bool _has_failed 	= false;
		bool _has_success 	= false;
		bool _is_trying 	= false;

		uint32_t times_failed	= 0;
		uint32_t times_success 	= 0;
		uint32_t tries			= 0;
};

#endif
