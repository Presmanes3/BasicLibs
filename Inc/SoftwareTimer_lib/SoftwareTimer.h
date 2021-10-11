#ifndef _SOFTWARE_TIMER_H_
#define _SOFTWARE_TIMER_H_

#include "Properties_lib/ActivationProperty.h"
#include "SoftwareTimer_config.h"
#include "stdint.h"
#include "math.h"

#ifdef STM32F103xB
#include "stm32f1xx_hal.h"

#endif

#ifdef STM32F437xx

#endif

enum TIMER_BASE_TIME{
	BASE_SECONDS 	= 0,

	BASE_MILLIS 	= 1,

	BASE_MICROS 	= 2
};

extern TIM_HandleTypeDef HW_TIMER_INSTANCE;

class SoftwareTimer : public ActivationProperty{
	public:

		SoftwareTimer( uint32_t period, TIMER_BASE_TIME base_time){

			this->hw_timer = &HW_TIMER_INSTANCE;
			this->compute_hardware_timer_values();

			this->base_time = base_time;

			this->set_period(period);

			this->reset();
		}

		void set_period(uint32_t period);

		void start();
		void stop();
		void reset();
		void restart();

		bool check();

		void run_overflow();

	private:
		bool check_time_overflow_ocurred();

		uint32_t get_current_tick();
		uint32_t get_hardware_timer_autoreload();

		float compute_percentage_done();
		float compute_percentage_left();

		float compute_time_done();
		float compute_time_left();

		void compute_hardware_timer_values();



	private:
		TIM_HandleTypeDef *hw_timer;

		float hw_timer_frequency	= 0;
		float hw_timer_period		= 0;

		uint32_t reference			= 0;

		float time_from_overflow 	= 0;

		float time_done 			= 0;
		float time_left				= 0;

		float percentage_done		= 0;
		float percentage_left		= 0;

		float frequecy_Hz			= 0;
		float period				= 0;

		uint64_t overflows			= 0;
		TIMER_BASE_TIME base_time;
};

#endif
