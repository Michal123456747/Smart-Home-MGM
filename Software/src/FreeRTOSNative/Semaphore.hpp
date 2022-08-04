/**
 * @file Semaphore.hpp
 * @brief Contains Semaphore methods and types from FreeRTOS and class to mock these methods
 */

#include "Types.hpp"

#pragma once

#ifdef NATIVE
//------------------------------------------------------------------------------
// Types


//------------------------------------------------------------------------------
// Mocking class

/**
 * @brief Use only as mock
 *
 */
class Semaphore
{
public:
    /**
     * @return BaseType_t pxHigherPriorityTaskWoken that will be updated by xSemaphore...FromISR functions
     */
    virtual BaseType_t GetPxHigherPriorityTaskWoken()
    {
        return pdTRUE;
    }

    virtual BaseType_t xSemaphoreTake(QueueHandle_t xSemaphore, TickType_t xBlockTime)
    {
        return pdTRUE;
    }

    virtual BaseType_t xSemaphoreTakeFromISR(QueueHandle_t xSemaphore, BaseType_t *pxHigherPriorityTaskWoken)
    {
        return pdTRUE;
    }

    virtual BaseType_t xSemaphoreGive(QueueHandle_t xSemaphore)
    {
        return pdTRUE;
    }

    virtual BaseType_t xSemaphoreGiveFromISR(QueueHandle_t xSemaphore, BaseType_t *pxHigherPriorityTaskWoken)
    {
        return pdTRUE;
    }

    static Semaphore *semaphore;
};

Semaphore *Semaphore::semaphore = new Semaphore();

//------------------------------------------------------------------------------
// Methods

BaseType_t xSemaphoreTake(QueueHandle_t xSemaphore, TickType_t xBlockTime)
{
    return Semaphore::semaphore->xSemaphoreTake(xSemaphore, xBlockTime);
}

BaseType_t xSemaphoreTakeFromISR(QueueHandle_t xSemaphore, BaseType_t *pxHigherPriorityTaskWoken)
{
    *pxHigherPriorityTaskWoken = Semaphore::semaphore->GetPxHigherPriorityTaskWoken();
    return Semaphore::semaphore->xSemaphoreTakeFromISR(xSemaphore, pxHigherPriorityTaskWoken);
}

BaseType_t xSemaphoreGive(QueueHandle_t xSemaphore)
{
    return Semaphore::semaphore->xSemaphoreGive(xSemaphore);
}

BaseType_t xSemaphoreGiveFromISR(QueueHandle_t xSemaphore, BaseType_t *pxHigherPriorityTaskWoken)
{
    *pxHigherPriorityTaskWoken = Semaphore::semaphore->GetPxHigherPriorityTaskWoken();
    return Semaphore::semaphore->xSemaphoreGiveFromISR(xSemaphore, pxHigherPriorityTaskWoken);
}

#endif
