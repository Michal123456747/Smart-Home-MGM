/**
 * @file Task.hpp
 * @brief Contains task methods and types from FreeRTOS and class to mock these methods
 */

#include "Types.hpp"

#include <cstdlib>

#pragma once

#ifdef NATIVE
//------------------------------------------------------------------------------
// Types

typedef void (*TaskFunction_t)(void *);
typedef void *TaskHandle_t;

//------------------------------------------------------------------------------
// Mocking class

/**
 * @brief Use only as mock
 *
 */
class Task
{
public:
    virtual BaseType_t xTaskCreate(TaskFunction_t pvTaskCode, const char *const pcName, const uint32_t usStackDepth,
                                   void *const pvParameters, UBaseType_t uxPriority, TaskHandle_t *const pxCreatedTask)
    {
        return pdTRUE;
    }

    /**
     * @brief Return pointer that will be returned by xTaskCreate function
     *
     * @return TaskHandle_t* const
     */
    virtual TaskHandle_t const getPxCreatedTask()
    {
        return NULL;
    }

    virtual void vTaskDelete(TaskHandle_t xTaskToDelete) {}

    virtual void vTaskDelay(const TickType_t xTicksToDelay) {}

    static Task *task;
};

Task *Task::task = new Task;

//------------------------------------------------------------------------------
// Methods

BaseType_t xTaskCreate(TaskFunction_t pvTaskCode, const char *const pcName, const uint32_t usStackDepth, void *const pvParameters,
                       UBaseType_t uxPriority, TaskHandle_t *const pxCreatedTask)
{
    *pxCreatedTask = Task::task->getPxCreatedTask();
    return Task::task->xTaskCreate(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
}

void vTaskDelete(TaskHandle_t xTaskToDelete)
{
    Task::task->vTaskDelete(xTaskToDelete);
}

void vTaskDelay(const TickType_t xTicksToDelay)
{
    Task::task->vTaskDelay(xTicksToDelay);
}

#endif
