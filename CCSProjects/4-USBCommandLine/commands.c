/*
*	FreeRTOS USB Command Line
*/


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* Standard TIVA includes */
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
/* Other TIVA includes */
#include "utils/cpu_usage.h"
#include "utils/cmdline.h"
#include "utils/uartstdio.h"
#include "drivers/rgb.h"

// ==============================================================================
// The CPU usage in percent, in 16.16 fixed point format.
// ==============================================================================
extern uint32_t g_ui32CPUUsage;

// ==============================================================================
// Show CPU use
// ==============================================================================
int  Cmd_cpu(int argc, char *argv[])
{
    UARTprintf("ARM Cortex-M4F %u MHz - ",SysCtlClockGet() / 1000000);
    UARTprintf("%2u%% in use\n", (g_ui32CPUUsage+32768) >> 16);

    // Return success.
    return(0);
}

// ==============================================================================
// Show free heap memory in freeRTOS system
// ==============================================================================
int Cmd_free(int argc, char *argv[])
{
    UARTprintf("%d free bytes\n", xPortGetFreeHeapSize());

    // Return success.
    return(0);
}

// ==============================================================================
// Only possible if configUSE_TRACE_FACILITY option is enabled
// ==============================================================================
#if ( configUSE_TRACE_FACILITY == 1 )

extern char *__stack;
int Cmd_tasks(int argc, char *argv[])
{
	char*	pcBuffer;
	uint8_t*	pi8Stack;
	portBASE_TYPE	x;
	
	pcBuffer = pvPortMalloc(1024);
	vTaskList(pcBuffer);
	UARTprintf("\t\t\t\tUnused\nTaskName\tStatus\tPri\tStack\tTask ID\n");
	UARTprintf("=======================================================\n");
	UARTprintf("%s", pcBuffer);
	
	// Calculate kernel stack usage
	x = 0;
	pi8Stack = (uint8_t *) &__stack;
	while (*pi8Stack++ == 0xA5)
	{
		x++;	//Esto s�lo funciona si hemos rellenado la pila del sistema con 0xA5 en el arranque
	}
	sprintf((char *) pcBuffer, "%%%us", configMAX_TASK_NAME_LEN);
	sprintf((char *) &pcBuffer[10], (const char *) pcBuffer, "kernel");
	UARTprintf("%s\t-\t*%u\t%u\t-\n", &pcBuffer[10], configKERNEL_INTERRUPT_PRIORITY, x/sizeof(portBASE_TYPE));
	vPortFree(pcBuffer);
	return 0;
}

#endif /* configUSE_TRACE_FACILITY */

#if configGENERATE_RUN_TIME_STATS
// ==============================================================================
// Stats command
// ==============================================================================
Cmd_stats(int argc, char *argv[])
{
	char* pBuffer;
	pBuffer = pvPortMalloc(1024);
	if (pBuffer)
	{
		vTaskGetRunTimeStats(pBuffer); // That line is not sure... But can be used at the moment...
		UARTprintf("TaskName\tCycles\t\tPercent\r\n");
		UARTprintf("===============================================\r\n");
		UARTprintf("%s", pBuffer);
		vPortFree(pBuffer);
	}
	return 0;
}
#endif

// ==============================================================================
// Show available commands
// ==============================================================================
int Cmd_help(int argc, char *argv[])
{
    tCmdLineEntry *pEntry;

    UARTprintf("  -------------------------------------------------------\n");
    UARTprintf("  |  Available commands:                                |\n");
    UARTprintf("  -------------------------------------------------------\n");

    // Point at the beginning of the command table.
    pEntry = &g_psCmdTable[0];

    // Enter a loop to read each entry from the command table. The end of the
    // table has been reached when the command name is NULL.
    while(pEntry->pcCmd)
    {
        // Print the command name and the brief description.
        UARTprintf("  - %s%s\n", pEntry->pcCmd, pEntry->pcHelp);

        // Advance to the next entry in the table.
        pEntry++;
    }

    UARTprintf("  -------------------------------------------------------\n");
    // Return success.
    return(0);
}

// ==============================================================================
// Digital LED control
// ==============================================================================
int Cmd_led(int argc, char *argv[])
{
	if (argc != 2)
	{
		// Show correct syntax (No enough parameters)
		UARTprintf("Correct syntax: led [on|off]\n");
	}
	else
	{
		//seconds = strtoul(argv[1], NULL, 10);

		if (strncmp( argv[1], "on",2) == 0)
		{
			UARTprintf("Turn on LED\n");
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,GPIO_PIN_3);
		}
		else if (strncmp( argv[1], "off",3) == 0)
		{
			UARTprintf("Turn off LED\n");
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0);
		}
		else
		{

			// Show correct syntax (Wrong parameter)
			UARTprintf("Correct syntax: led [on|off]\n");
		}
	}
    return 0;
}

// ==============================================================================
// Select LEDs mode (GPIO / PWM)
// ==============================================================================
int Cmd_mode(int argc, char *argv[])
{
	if (argc != 2)
	{
		// Show correct syntax (No enough parameters)
		UARTprintf("Correct syntax: mode [gpio|pwm]\n");
	}
	else
	{
		if (strncmp(argv[1], "gpio",4) == 0)
		{
			UARTprintf("Leds changed to GPIO mode\n");
			RGBDisable();
			ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
		}
		else if (strncmp(argv[1], "pwm",3) == 0)
		{
			UARTprintf("Leds changed to PWM mode\n");
			RGBEnable();
		}
		else
		{
			// Show correct syntax (Wrong parameter)
			UARTprintf("Correct syntax: mode [gpio|pwm]\n");
		}
	}
    return 0;
}

// ==============================================================================
// Select RGB values to LEDs in PWM mode
// ==============================================================================
int Cmd_rgb(int argc, char *argv[])
{
	uint32_t arrayRGB[3];

	if (argc != 4)
	{
		// Show correct syntax (No enough parameters)
		UARTprintf("Correct syntax: rgb [red] [green] [blue]\n");
	}
	else
	{
		arrayRGB[0]=strtoul(argv[1], NULL, 10)<<8;
		arrayRGB[1]=strtoul(argv[2], NULL, 10)<<8;
		arrayRGB[2]=strtoul(argv[3], NULL, 10)<<8;

		if ((arrayRGB[0]>=65535)||(arrayRGB[1]>=65535)||(arrayRGB[2]>=65535))
		{
			UARTprintf(" \n");
		}
		else{
			RGBColorSet(arrayRGB);
		}
	}
    return 0;
}




// ==============================================================================
// Commands table with definitions
// ==============================================================================
tCmdLineEntry g_psCmdTable[] =
{
    { "help",     Cmd_help,      "       Show available commands" },
    { "cpu",      Cmd_cpu,       "        Show CPU use " },
    { "led",      Cmd_led,       "        Set GPIO value of leds" },
    { "mode",  	  Cmd_mode,      "       Set LEDs mode (GPIO / PWM)" },
    { "rgb",  	  Cmd_rgb,       "        Set RGB values to LEDs in PWM mode" },
    { "free",     Cmd_free,      "       Show free heap memory in freeRTOS system" },

	#if ( configUSE_TRACE_FACILITY == 1 )
	{ "tasks",    Cmd_tasks,     "      Show tasks information" },
#endif
#if (configGENERATE_RUN_TIME_STATS)
	{ "stats",    Cmd_stats,     "      Show tasks statistics" },
#endif

	{ 0, 0, 0 }
};

// ==============================================================================
// Waits for incoming commands by serial port and executes them when arrives
// ==============================================================================
//extern xSemaphoreHandle g_xRxLineSemaphore;
void UARTStdioIntHandler(void);

void vUARTTask( void *pvParameters )
{
    char    pcCmdBuf[64];
    int32_t i32Status;
	
    // Welcome message
    UARTprintf("\n        Welcome to FreeRTOS USB Command Line\n");
	//UARTprintf("        FreeRTOS %s \n",tskKERNEL_VERSION_NUMBER);
	UARTprintf("        Type help to show available commands\n\n");
	UARTprintf("> ");

	/* Loop forever */
	while (1)
	{
		/* Read data from the UART and process the command line */
		UARTgets(pcCmdBuf, sizeof(pcCmdBuf));
		if (strlen(pcCmdBuf) == 0)
		{
			UARTprintf("> ");
			continue;
		}

		// Pass the line from the user to the command processor. It will be
		// parsed and valid commands executed
		i32Status = CmdLineProcess(pcCmdBuf);

		// Handle the case of bad command
		if(i32Status == CMDLINE_BAD_CMD)
		{
			UARTprintf("(!)Wrong command\n");
		}

		// Handle the case of too many arguments.
		else if(i32Status == CMDLINE_TOO_MANY_ARGS)
		{
			UARTprintf("(!)Too much parameters\n");	//El maximo, CMDLINE_MAX_ARGS, esta definido en cmdline.c
		}

		// Otherwise the command was executed. Print the error code if one was
		// returned
		else if(i32Status != 0)
		{
			UARTprintf("(!)The command returns the error: %d\n",i32Status);
		}
		UARTprintf("> ");
	}
}
