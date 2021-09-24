#pragma once

#ifndef RingBufferLib_h
#define RingBufferLib_h

#include <stdint.h>

template<class infoType, uint8_t buffSize>
class RingBuffer {
private:
	infoType buffer[buffSize];
	uint8_t head;
	uint8_t tail;
	uint8_t occupiedSpaces;
	uint8_t bufferSize;
	bool overwrite;
public:
	RingBuffer(bool setoverwrite);
	bool is_bufferEmpty();
	bool is_bufferFull();
	bool write(infoType message);
	infoType read();
	uint8_t get_headIndex();
	uint8_t get_tailIndex();
	uint8_t get_occupiedSpaces();
	bool get_overwrite();
};

template<class infoType, uint8_t buffSize>
RingBuffer<infoType, buffSize>::RingBuffer(bool setoverwrite) {
	this->head = 0;
	this->tail = 0;
	this->occupiedSpaces = 0;
	this->overwrite = setoverwrite;
	this->bufferSize = buffSize;
}

template<class infoType, uint8_t buffSize>
bool RingBuffer<infoType, buffSize>::is_bufferEmpty() {
	return (this->occupiedSpaces == 0);
}

template<class infoType, uint8_t buffSize>
bool RingBuffer<infoType, buffSize>::is_bufferFull() {
	return (this->occupiedSpaces == this->bufferSize);
}

template<class infoType, uint8_t buffSize>
bool RingBuffer<infoType, buffSize>::write(infoType message) {
	if ((!this->is_bufferFull()) || this->overwrite) {
		if (this->occupiedSpaces == this->bufferSize) {
			this->head = (this->head + 1) % this->bufferSize;
			this->occupiedSpaces--;
		}
		this->buffer[this->tail] = message;
		this->occupiedSpaces++;
		this->tail = (this->tail + 1) % this->bufferSize;
		return true;
	}
	return false;
}

template<class infoType, uint8_t buffSize>
infoType RingBuffer<infoType, buffSize>::read() {
	if (!this->is_bufferEmpty()) {
		infoType message;
		message = this->buffer[this->head];
		this->head = (this->head + 1) % this->bufferSize;
		this->occupiedSpaces--;
		return message;
	}
}

template<class infoType, uint8_t buffSize>
uint8_t RingBuffer<infoType, buffSize>::get_headIndex() {
	return this->head;
}

template<class infoType, uint8_t buffSize>
uint8_t RingBuffer<infoType, buffSize>::get_tailIndex() {
	return this->tail;
}

template<class infoType, uint8_t buffSize>
uint8_t RingBuffer<infoType, buffSize>::get_occupiedSpaces() {
	return this->occupiedSpaces;
}

template<class infoType, uint8_t buffSize>
bool RingBuffer<infoType, buffSize>::get_overwrite() {
	return this->overwrite;
}

#endif


