/**
 * @file Types.hpp
 * @brief Macros and types used by FreeRTOS
 */

#include <cstdlib>

#pragma once

#ifdef NATIVE

typedef int BaseType_t;
typedef unsigned int UBaseType_t;

    // ESP_PLATFORM
    #define pdFALSE ((BaseType_t)0)
    #define pdTRUE ((BaseType_t)1)

    #define pdPASS (pdTRUE)
    #define pdFAIL (pdFALSE)
    #define errQUEUE_EMPTY ((BaseType_t)0)
    #define errQUEUE_FULL ((BaseType_t)0)

    /* FreeRTOS error definitions. */
    #define errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY (-1)
    #define errQUEUE_BLOCKED (-4)
    #define errQUEUE_YIELD (-5)

typedef uint32_t TickType_t;

    #define portTICK_PERIOD_MS

struct QueueDefinition;
typedef struct QueueDefinition *QueueHandle_t;
typedef struct QueueDefinition *QueueSetHandle_t;
typedef struct QueueDefinition *QueueSetMemberHandle_t;
typedef QueueHandle_t SemaphoreHandle_t;

#endif
