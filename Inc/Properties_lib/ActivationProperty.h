#ifndef _ACTIVATION_PROPERTY_H_
#define	_ACTIVATION_PROPERTY_H_

class ActivationProperty{
	public:
		ActivationProperty(){

		}

		bool is_initialized(){
			return this->_is_initialized;
		}

		bool is_active(){
			return this->_is_active;
		}

		void initialize(){
			this->_is_initialized = true;
		}

		void activate(){
			this->_is_active = true;
		}

		void deactivate(){
			this->_is_active = false;
		}

	private:
		bool _is_initialized = false;
		bool _is_active		 = false;
};

#endif
