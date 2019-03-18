/*
*	================================================================	*

*			Basic resume for Tiva Cortex M4 and freeRTOS API	
*			Andres Casasola Dominguez

*	================================================================	*


	
*	================================================================	*
*	========================   freeRTOS   ==========================	*
*	================================================================	*
*/
	
	-Tasks (task.h):
		
		- Type: TaskHandle_t
		
		- BaseType_t xTaskCreate(   TaskFunction_t pvTaskCode,
                        			const char * const pcName,
                        			unsigned short usStackDepth,
                        			void *pvParameters,
                        			UBaseType_t uxPriority,
                        			TaskHandle_t *pxCreatedTask
                        		);									// Return pdPASS if success.
                            			
		- void vTaskDelete(TaskHandle_t xTask);
		
		- void vTaskDelay(const TickType_t xTicksToDelay);		// To convert in seconds: (x * configTICK_RATE_HZ), where "x" are seconds
																// and "configTICK_RATE_HZ" are ticks per second of the operative system.
		- void vTaskResume(TaskHandle_t xTaskToResume);
		
		- void vTaskSuspend(TaskHandle_t xTaskToSuspend);
			
	-Queues (queue.h):
	
		- Type: QueueHandle_t
			
		- QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength, UBaseType_t uxItemSize );
		   
		- void vQueueDelete(QueueHandle_t xQueue);

		- BaseType_t xQueueSend(QueueHandle_t xQueue, const void * pvItemToQueue, TickType_t xTicksToWait);
		
		- BaseType_t xQueueSendFromISR(QueueHandle_t xQueue, const void *pvItemToQueue, BaseType_t *pxHigherPriorityTaskWoken);
		
		- BaseType_t xQueueReceive(QueueHandle_t xQueue, void *pvBuffer, TickType_t xTicksToWait);
		
		- BaseType_t xQueueReceiveFromISR(QueueHandle_t xQueue, void *pvBuffer, BaseType_t *pxHigherPriorityTaskWoken);
		
		- BaseType_t xQueueReset(QueueHandle_t xQueue);

	-Semaphores (semphr.h):
	
		- Type: SemaphoreHandle_t
		
		- void vSemaphoreCreateBinary(SemaphoreHandle_t xSemaphore);

		- SemaphoreHandle_t xSemaphoreCreateCounting( UBaseType_t uxMaxCount, UBaseType_t uxInitialCount);
		
		- SemaphoreHandle_t xSemaphoreCreateMutex(void);
		
		- void vSemaphoreDelete(SemaphoreHandle_t xSemaphore);
		
		- xSemaphoreTake(SemaphoreHandle_t xSemaphore, TickType_t xTicksToWait);
		
		- xSemaphoreTakeFromISR(SemaphoreHandle_t xSemaphore, signed BaseType_t *pxHigherPriorityTaskWoken);
		
		- xSemaphoreGive(SemaphoreHandle_t xSemaphore);
		
		- xSemaphoreGiveFromISR(SemaphoreHandle_t xSemaphore, signed BaseType_t *pxHigherPriorityTaskWoken);
		
	-Event Groups (event_groups.h):
	
		- Type: EventGroupHandle_t
		
		- EventGroupHandle_t xEventGroupCreate(void);
		
		- void vEventGroupDelete(EventGroupHandle_t xEventGroup);
		
		- EventBits_t xEventGroupWaitBits(	   
							const EventGroupHandle_t xEventGroup,
							const EventBits_t uxBitsToWaitFor,
							const BaseType_t xClearOnExit,
							const BaseType_t xWaitForAllBits,
							TickType_t xTicksToWait);
										 
		- EventBits_t xEventGroupSetBits(EventGroupHandle_t xEventGroup, const EventBits_t uxBitsToSet);
		
		- BaseType_t xEventGroupSetBitsFromISR(
							EventGroupHandle_t xEventGroup,
							const EventBits_t uxBitsToSet,
							BaseType_t *pxHigherPriorityTaskWoken );

/*
*	================================================================	*
*	=====================   Tiva Cortex M4   =======================	*
*	================================================================	*	
*/

		- SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
		
		- SysCtlPeripheralEnable(uint32_t ui32Peripheral);
		
		- SysCtlPeripheralSleepEnable(uint32_t ui32Peripheral);
		
		- GPIOIntTypeSet(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32IntType);
		
		- IntPrioritySet(uint32_t ui32Interrupt, uint8_t ui8Priority);
		  Example: IntPrioritySet(INT_GPIOF,configMAX_SYSCALL_INTERRUPT_PRIORITY);
		
		- GPIOIntEnable(uint32_t ui32Port, uint32_t ui32IntFlags);
		
		- GPIOIntDisable(uint32_t ui32Port, uint32_t ui32IntFlags);
		
		- IntEnable(uint32_t ui32Interrupt);
		
		- GPIOIntClear(uint32_t ui32Port, uint32_t ui32IntFlags);
		
		- 


	-Examples of parameters:

		ui32Peripheral == SYSCTL_PERIPH_GPIOF
		ui32Port == GPIO_PORTF_BASE
		ui8Pins == ALL_BUTTONS
		ui32IntType == GPIO_FALLING_EDGE
		ui32Interrupt == INT_GPIOF
		ui8Priority == configMAX_SYSCALL_INTERRUPT_PRIORITY
		ui32IntFlags == ALL_BUTTONS














		
