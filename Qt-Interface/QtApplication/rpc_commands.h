#ifndef RPCCOMMANDS_H
#define RPCCOMMANDS_H

#include <stdint.h>

//Códigos de los comandos y definicion de parametros para el protocolo RPC

// El estudiante debe añadir aqui cada nuevo comando que implemente. IMPORTANTE el orden de los comandos
// debe SER EL MISMO aqui, y en el codigo equivalente en la parte del microcontrolador (Code Composer)
typedef enum {
    COMMAND_REJECTED,
    COMMAND_PING,
    COMMAND_LED_GPIO,
    COMMAND_LED_PWM_BRIGHTNESS,
    COMMAND_GPIO_PWM_MODE,
    COMMAND_LED_PWM_COLOR,
    COMMAND_SWITCHES_SOUND, // Sondeo
    COMMAND_SWITCHES_INTERRUPT_ENABLE,
    COMMAND_SWITCHES_INTERRUPT,
    COMMAND_ADC_SAMPLE,
    COMMAND_ADC8_PACKET,
    COMMAND_ADC12_PACKET,
    COMMAND_SWITCH_ADC,
    COMMAND_ADC_FREQUENCY,
    COMMAND_ADC_RESOLUTION,
    COMMAND_SENSOR_READ,
    COMMAND_PROXIMITY_SENSOR_STATE,
    COMMAND_PROXIMITY_SENSOR,
    COMMAND_GESTURE_SENSOR,
    COMMAND_GESTURE_SENSOR2,

    //etc, etc...
} commandTypes;

//Estructuras relacionadas con los parametros de los comandos. El estuadiante debera crear las
// estructuras adecuadas a los comandos usados, y asegurarse de su compatibilidad en ambos extremos

#pragma pack(1)	//Cambia el alineamiento de datos en memoria a 1 byte.

typedef struct {
    uint8_t command;
} PARAMETERS_COMMAND_REJECTED;

typedef union{
    struct {
         uint8_t padding:1;
         uint8_t red:1;        
         uint8_t blue:1;
         uint8_t green:1;
    } leds;
    uint8_t value;
} PARAMETERS_LED_GPIO;

typedef struct {
    float rIntensity;
} PARAMETERS_LED_PWM_BRIGHTNESS;

typedef struct {
    uint32_t rgb[3];
} PARAMETERS_LED_PWM_COLOR;

typedef struct {
    bool mode;
} PARAMETERS_GPIO_PWM_MODE;

typedef struct {
    bool state1;
    bool state2;
} PARAMETERS_SWITCHES_SOUND;

typedef struct {
    bool check;
} PARAMETERS_SWITCHES_INTERRUPT_ENABLE;

typedef struct {
    bool state1;
    bool state2;
} PARAMETERS_SWITCHES_INTERRUPT;

typedef struct {
    uint16_t chan1;
    uint16_t chan2;
    uint16_t chan3;
    uint16_t chan4;
} PARAMETERS_ADC_SAMPLE;

typedef struct{
    uint16_t chan1[8];
    uint16_t chan2[8];
    uint16_t chan3[8];
    uint16_t chan4[8];
} PARAMETERS_ADC12_PACKET;

typedef struct{
    uint8_t chan1[8];
    uint8_t chan2[8];
    uint8_t chan3[8];
    uint8_t chan4[8];
} PARAMETERS_ADC8_PACKET;

typedef struct {
    bool active;
} PARAMETERS_SWITCH_ADC;

typedef struct {
    double freq;
} PARAMETERS_ADC_FREQUENCY;

typedef struct {
    bool resolution;
} PARAMETERS_ADC_RESOLUTION;

typedef struct {
    uint16_t r, g, b, c;
} PARAMETERS_SENSOR_READ;

typedef struct {
    bool state;
} PARAMETERS_PROXIMITY_SENSOR_STATE;

typedef struct {
    uint8_t value;
    bool state;
} PARAMETERS_PROXIMITY_SENSOR;

typedef struct {
    uint8_t mode;
} PARAMETERS_GESTURE_SENSOR;

typedef struct {
    uint8_t fifo[128];
    int16_t bytes_read;
} PARAMETERS_GESTURE_SENSOR2;

#pragma pack()	//...Pero solo para los comandos que voy a intercambiar, no para el resto.

#endif // RPCCOMMANDS_H
