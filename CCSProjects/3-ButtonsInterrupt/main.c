/********************
*
* - FreeRTOS starting example with Tiva C Series TM4C123GH6PM
* - GitHub: AndresCasasola
*
********************/

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/interrupt.h"
#include "driverlib/adc.h"
#include "driverlib/timer.h"
#include "utils/uartstdio.h"
#include "drivers/buttons.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "utils/cpu_usage.h"
#include "drivers/rgb.h"

// Global variables
uint32_t g_ui32CPUUsage;
uint32_t g_ulSystemClock; // System clock speed
uint8_t buttons_intstatus=0;

// Routine functions (RTI)
void ButtonHandler(void);

// The error routine that is called if the driver library or freeRTOS encounters an error.
#ifdef DEBUG
void __error__(char *nombrefich, uint32_t linea){
    while(1){}
}
#endif

/********** Events links for FreeRTOS **********/

// Stack overflow detected
void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName){
	while(1){}
}

// CPU monitoring every system tick
void vApplicationTickHook( void ){
	static uint8_t count = 0;
	if (++count == 10){
		g_ui32CPUUsage = CPUUsageTick();
		count = 0;
	}
}

// Executes when Idle task runs
void vApplicationIdleHook (void){
	SysCtlSleep();
}
// Executes when Idle task runs
void vApplicationMallocFailedHook (void){
	while(1){}
}

void system_config(){
	/******************** System Configuration ********************/
	// Set clock to 40 MHz (200 MHz from PLL with divider of 5)
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);	//

	// Get the system clock speed
	g_ulSystemClock = SysCtlClockGet();

	// Enables clock gating of peripherals in low power
	// Enable peripherals in sleep mode with SysCtlPeripheralSleepEnable()
	ROM_SysCtlPeripheralClockGating(true);

	// CPU usage measure subsystem (It measures the time that CPU is awake. It uses timer 3)
	CPUUsageInit(g_ulSystemClock, configTICK_RATE_HZ/10, 3);

	// UART initialization and configuration
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
	ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
	ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTStdioConfig(0, 115200, SysCtlClockGet());

	// Enables UART and GPIOA even if CPU is in sleep mode
	ROM_SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_UART0);
	ROM_SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_GPIOA);

	// Buttons and interruptions configuration
	ButtonsInit();
	IntRegister(INT_GPIOF, ButtonHandler);
	GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_FALLING_EDGE);
	IntPrioritySet(INT_GPIOF, configMAX_SYSCALL_INTERRUPT_PRIORITY);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralSleepEnable(SYSCTL_PERIPH_GPIOF);
	GPIOIntEnable(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0);
	IntEnable(INT_GPIOF);
	IntMasterEnable();

	// Initialize LEDs through RGB library. It uses Timers 0 y 1
	RGBInit(1);
	SysCtlPeripheralSleepEnable(GREEN_TIMER_PERIPH);
	SysCtlPeripheralSleepEnable(BLUE_TIMER_PERIPH);
	SysCtlPeripheralSleepEnable(RED_TIMER_PERIPH);	// BLUE_TIMER_PERIPH y GREEN_TIMER_PERIPH are the same

	// Configure LEDs in GPIO mode
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	/******************** System Configuration ********************/
}

void Heartbeat( void *pvParameters ){
	while(1){
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
		vTaskDelay((TickType_t) configTICK_RATE_HZ * 0.1);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		vTaskDelay((TickType_t) configTICK_RATE_HZ * 0.1);

		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
		vTaskDelay((TickType_t) configTICK_RATE_HZ * 0.08);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		vTaskDelay((TickType_t) configTICK_RATE_HZ * 1);
	}
}

// Main function
int main(void){

	system_config();

    // Tasks Creation
	//int t1 = xTaskCreate(Heartbeat, (portCHAR *)"Heartbeat", 512, NULL, tskIDLE_PRIORITY + 1, NULL);
	//if(t1 != pdTRUE)
	//	while(1){}

	vTaskStartScheduler();	// Start scheduler, RTOS enables interruptions here.

	while(1){} // Something was wrong if the program executes this loop (with scheduler started).
}

/********** ISRs **********/

void ButtonHandler(void){

	uint32_t status;
	status=GPIOIntStatus(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);
	GPIOIntDisable(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);
	GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);

	if (status&GPIO_PIN_4){
		if(buttons_intstatus == 0){
			GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_RISING_EDGE);
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
		}else{
			GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_FALLING_EDGE);
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
		}
		buttons_intstatus = 1-buttons_intstatus;
	}
	GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);
}


