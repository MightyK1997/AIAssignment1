#pragma once
#include <cstdint>

enum TaskStatus :uint8_t
{
	e_SUCCESS,
	e_FAILURE,
	e_RUNNING,
	e_STOPPED,
};
