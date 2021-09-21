#ifndef _EXECUTION_TIME_CALCULATOR_H_
#define _EXECUTION_TIME_CALCULATOR_H_

#include "stdint.h"
#include "math.h"

#ifdef STM32F103xB
#include "stm32f1xx_hal.h"

#endif

#ifdef STM32F437xx

#endif


class ExecutionTimeCalculator {
	public:
		ExecutionTimeCalculator(TIM_HandleTypeDef *hw_timer) {

			this->hw_timer = hw_timer;

		}

		void start();

		void stop();

		uint32_t get_time_past();

	private:

		uint32_t get_current_time();

		uint32_t get_hardware_timer_autoreload();

	private:
		TIM_HandleTypeDef *hw_timer;

		uint32_t start_time = 0;
		uint32_t stop_time = 0;

		uint32_t time_past = 0;
};

#endif // _EXECUTION_TIME_CALCULATOR_H_
