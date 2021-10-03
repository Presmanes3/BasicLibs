#ifndef _SOFTWARE_TIMER_H_
#define _SOFTWARE_TIMER_H_

#include "Properties_lib/ActivationProperty.h"
#include "stdint.h"
#include "math.h"

#ifdef STM32F103xB
#include "stm32f1xx_hal.h"

#endif

#ifdef STM32F437xx

#endif

enum TIMER_BASE_TIME{
	BASE_MILLIS = 0,

	BASE_MICROS = 1
};

extern TIM_HandleTypeDef htim2;

class SoftwareTimer : public ActivationProperty{
	public:

		SoftwareTimer( uint32_t period, TIMER_BASE_TIME base_time){

			this->hw_timer = &htim2;

			this->base_time = base_time;

			this->set_period(period);

		}

		void set_period(uint32_t period);

		void start();
		void stop();
		void reset();

		bool check();

		float compute_percentage_done();
		float compute_percentage_left();
		uint32_t compute_time_done();
		uint32_t compute_time_left();

	private:
		bool check_time_overflow_ocurred();

		uint32_t get_current_time();
		uint32_t get_hardware_timer_autoreload();

	private:
		TIM_HandleTypeDef *hw_timer;

		uint32_t ref_time;

		uint32_t time_done;
		uint32_t time_left;

		float percentage_done;
		float percentage_left;

		float frequecy_Hz;
		float period;

		TIMER_BASE_TIME base_time;
};

#endif
