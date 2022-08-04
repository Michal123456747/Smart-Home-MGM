/**
 * @file Queue.hpp
 * @brief Contains Queue methods and types from FreeRTOS and class to mock these methods
 */

//TODO: Add possibility of manipulating data received from queue

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
class Queue
{
public:
    virtual BaseType_t xQueueSend(QueueHandle_t xQueue, const void *pvItemToQueue, TickType_t xTicksToWait)
    {
        return pdTRUE;
    }

    virtual BaseType_t xQueueSendFromISR(QueueHandle_t xQueue, const void *pvItemToQueue, BaseType_t *pxHigherPriorityTaskWoken)
    {
        return pdTRUE;
    }

    virtual BaseType_t xQueueReceive(QueueHandle_t xQueue, void const *pvBuffer, TickType_t xTicksToWait)
    {
        return pdTRUE;
    }

    virtual BaseType_t xQueueReceiveFromISR(QueueHandle_t xQueue, void const *pvBuffer, BaseType_t *pxHigherPriorityTaskWoken)
    {
        return pdTRUE;
    }

    virtual BaseType_t xQueuePeek(QueueHandle_t xQueue, void *const pvBuffer, TickType_t xTicksToWait)
    {
        return pdTRUE;
    }

    /**
     * @return BaseType_t pxHigherPriorityTaskWoken that will be updated by xQueue...FromISR functions
     */
    virtual BaseType_t GetPxHigherPriorityTaskWoken()
    {
        return pdTRUE;
    }

    static Queue *queue;
};

Queue *Queue::queue = new Queue;
//------------------------------------------------------------------------------
// Methods

BaseType_t xQueueSend(QueueHandle_t xQueue, const void *pvItemToQueue, TickType_t xTicksToWait)
{
    return Queue::queue->xQueueSend(xQueue, pvItemToQueue, xTicksToWait);
}

BaseType_t xQueueSendFromISR(QueueHandle_t xQueue, const void *pvItemToQueue, BaseType_t *pxHigherPriorityTaskWoken)
{
    *pxHigherPriorityTaskWoken = Queue::queue->GetPxHigherPriorityTaskWoken();
    return Queue::queue->xQueueSendFromISR(xQueue, pvItemToQueue, pxHigherPriorityTaskWoken);
}

BaseType_t xQueueReceive(QueueHandle_t xQueue, void *const pvBuffer, TickType_t xTicksToWait)
{
    return Queue::queue->xQueueReceive(xQueue, pvBuffer, xTicksToWait);
}

BaseType_t xQueueReceiveFromISR(QueueHandle_t xQueue, void *const pvBuffer, BaseType_t *const pxHigherPriorityTaskWoken)
{
    *pxHigherPriorityTaskWoken = Queue::queue->GetPxHigherPriorityTaskWoken();
    return Queue::queue->xQueueReceiveFromISR(xQueue, pvBuffer, pxHigherPriorityTaskWoken);
}

BaseType_t xQueuePeek(QueueHandle_t xQueue, void *const pvBuffer, TickType_t xTicksToWait)
{
    return Queue::queue->xQueuePeek(xQueue, pvBuffer, xTicksToWait);
}
#endif
