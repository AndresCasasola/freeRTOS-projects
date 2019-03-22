//*****************************************************************************
// APDS9960drv.c - Gesture sensor driver APIs.
// Jose Manuel Cano, Eva Gonzalez, Ignacio Herrero
// Departamento de Tecnologia Electronica.
// Este fichero contiene fragmentos de codigo de la biblioteca Sparkfun para Arduino y de la bibliotecas
// de Texas Instruments para los dispositivos BMA22 y TMP006, cuyos copyrights se citan a continuacion:
//
/**************************************************************************/

/**
 * @file    SparkFun_APDS-9960.h
 * @brief   Library for the SparkFun APDS-9960 breakout board
 * @author  Shawn Hymel (SparkFun Electronics)
******************************************************************************/

#ifndef __SF_APDS9960_H__
#define __SF_APDS9960_H__



/* Debug */
#define SF_APDS9960_DEBUG                   0

/* APDS-9960 I2C address */
#define SF_APDS9960_I2C_ADDR       0x39

/* Gesture parameters */
#define SF_APDS9960_GESTURE_THRESHOLD_OUT   10
#define SF_APDS9960_GESTURE_SENSITIVITY_1   50
#define SF_APDS9960_GESTURE_SENSITIVITY_2   20

/* Error code for returned values */
#define SF_APDS9960_ERROR                   0xFF

/* Acceptable device IDs */
#define SF_APDS9960_ID_1           0xAB
#define SF_APDS9960_ID_2           0x9C

/* Misc parameters */
#define SF_APDS9960_FIFO_PAUSE_TIME         30      // Wait period (ms) between FIFO reads

/* APDS-9960 register addresses */
#define SF_APDS9960_ENABLE         0x80
#define SF_APDS9960_ATIME          0x81
#define SF_APDS9960_WTIME          0x83
#define SF_APDS9960_AILTL          0x84
#define SF_APDS9960_AILTH          0x85
#define SF_APDS9960_AIHTL          0x86
#define SF_APDS9960_AIHTH          0x87
#define SF_APDS9960_PILT           0x89
#define SF_APDS9960_PIHT           0x8B
#define SF_APDS9960_PERS           0x8C
#define SF_APDS9960_CONFIG1        0x8D
#define SF_APDS9960_PPULSE         0x8E
#define SF_APDS9960_CONTROL        0x8F
#define SF_APDS9960_CONFIG2        0x90
#define SF_APDS9960_ID             0x92
#define SF_APDS9960_STATUS         0x93
#define SF_APDS9960_CDATAL         0x94
#define SF_APDS9960_CDATAH         0x95
#define SF_APDS9960_RDATAL         0x96
#define SF_APDS9960_RDATAH         0x97
#define SF_APDS9960_GDATAL         0x98
#define SF_APDS9960_GDATAH         0x99
#define SF_APDS9960_BDATAL         0x9A
#define SF_APDS9960_BDATAH         0x9B
#define SF_APDS9960_PDATA          0x9C
#define SF_APDS9960_POFFSET_UR     0x9D
#define SF_APDS9960_POFFSET_DL     0x9E
#define SF_APDS9960_CONFIG3        0x9F
#define SF_APDS9960_GPENTH         0xA0
#define SF_APDS9960_GEXTH          0xA1
#define SF_APDS9960_GCONF1         0xA2
#define SF_APDS9960_GCONF2         0xA3
#define SF_APDS9960_GOFFSET_U      0xA4
#define SF_APDS9960_GOFFSET_D      0xA5
#define SF_APDS9960_GOFFSET_L      0xA7
#define SF_APDS9960_GOFFSET_R      0xA9
#define SF_APDS9960_GPULSE         0xA6
#define SF_APDS9960_GCONF3         0xAA
#define SF_APDS9960_GCONF4         0xAB
#define SF_APDS9960_GFLVL          0xAE
#define SF_APDS9960_GSTATUS        0xAF
#define SF_APDS9960_IFORCE         0xE4
#define SF_APDS9960_PICLEAR        0xE5
#define SF_APDS9960_CICLEAR        0xE6
#define SF_APDS9960_AICLEAR        0xE7
#define SF_APDS9960_GFIFO_U        0xFC
#define SF_APDS9960_GFIFO_D        0xFD
#define SF_APDS9960_GFIFO_L        0xFE
#define SF_APDS9960_GFIFO_R        0xFF

/* Bit fields */
#define SF_APDS9960_PON            0b00000001
#define SF_APDS9960_AEN            0b00000010
#define SF_APDS9960_PEN            0b00000100
#define SF_APDS9960_WEN            0b00001000
#define SF_APSD9960_AIEN           0b00010000
#define SF_APDS9960_PIEN           0b00100000
#define SF_APDS9960_GEN            0b01000000
#define SF_APDS9960_GVALID         0b00000001

/* On/Off definitions */
#define SF_APDS9960_OFF                     0
#define SF_APDS9960_ON                      1

/* Acceptable parameters for setMode */
#define SF_APDS9960_POWER                   0
#define SF_APDS9960_AMBIENT_LIGHT           1
#define SF_APDS9960_PROXIMITY               2
#define SF_APDS9960_WAIT                    3
#define SF_APDS9960_AMBIENT_LIGHT_INT       4
#define SF_APDS9960_PROXIMITY_INT           5
#define SF_APDS9960_GESTURE                 6
#define SF_APDS9960_ALL                     7

/* LED Drive values */
#define SF_APDS9960_LED_DRIVE_100MA         0
#define SF_APDS9960_LED_DRIVE_50MA          1
#define SF_APDS9960_LED_DRIVE_25MA          2
#define SF_APDS9960_LED_DRIVE_12_5MA        3

/* Proximity Gain (PGAIN) values */
#define SF_APDS9960_PGAIN_1X                0
#define SF_APDS9960_PGAIN_2X                1
#define SF_APDS9960_PGAIN_4X                2
#define SF_APDS9960_PGAIN_8X                3

/* ALS Gain (AGAIN) values */
#define SF_APDS9960_AGAIN_1X                0
#define SF_APDS9960_AGAIN_4X                1
#define SF_APDS9960_AGAIN_16X               2
#define SF_APDS9960_AGAIN_64X               3

/* Gesture Gain (GGAIN) values */
#define SF_APDS9960_GGAIN_1X                0
#define SF_APDS9960_GGAIN_2X                1
#define SF_APDS9960_GGAIN_4X                2
#define SF_APDS9960_GGAIN_8X                3

/* LED Boost values */
#define SF_APDS9960_LED_BOOST_100           0
#define SF_APDS9960_LED_BOOST_150           1
#define SF_APDS9960_LED_BOOST_200           2
#define SF_APDS9960_LED_BOOST_300           3

/* Gesture wait time values */
#define SF_APDS9960_GWTIME_0MS              0
#define SF_APDS9960_GWTIME_2_8MS            1
#define SF_APDS9960_GWTIME_5_6MS            2
#define SF_APDS9960_GWTIME_8_4MS            3
#define SF_APDS9960_GWTIME_14_0MS           4
#define SF_APDS9960_GWTIME_22_4MS           5
#define SF_APDS9960_GWTIME_30_8MS           6
#define SF_APDS9960_GWTIME_39_2MS           7

/* Default values */
#define SF_APDS9960_DEFAULT_ATIME           219     // 103ms
#define SF_APDS9960_DEFAULT_WTIME           246     // 27ms
#define SF_APDS9960_DEFAULT_PROX_PPULSE     0x87    // 16us, 8 pulses
#define SF_APDS9960_DEFAULT_GESTURE_PPULSE  0x89    // 16us, 10 pulses
#define SF_APDS9960_DEFAULT_POFFSET_UR      0       // 0 offset
#define SF_APDS9960_DEFAULT_POFFSET_DL      0       // 0 offset
#define SF_APDS9960_DEFAULT_CONFIG1         0x60    // No 12x wait (WTIME) factor
#define SF_APDS9960_DEFAULT_LDRIVE          SF_APDS9960_LED_DRIVE_100MA
#define SF_APDS9960_DEFAULT_PGAIN           SF_APDS9960_PGAIN_4X
#define SF_APDS9960_DEFAULT_AGAIN           SF_APDS9960_AGAIN_4X
#define SF_APDS9960_DEFAULT_PILT            0       // Low proximity threshold
#define SF_APDS9960_DEFAULT_PIHT            50      // High proximity threshold
#define SF_APDS9960_DEFAULT_AILT            0xFFFF  // Force interrupt for calibration
#define SF_APDS9960_DEFAULT_AIHT            0
#define SF_APDS9960_DEFAULT_PERS            0x11    // 2 consecutive prox or ALS for int.
#define SF_APDS9960_DEFAULT_CONFIG2         0x01    // No saturation interrupts or LED boost
#define SF_APDS9960_DEFAULT_CONFIG3         0       // Enable all photodiodes, no SAI
#define SF_APDS9960_DEFAULT_GPENTH          40      // Threshold for entering gesture mode
#define SF_APDS9960_DEFAULT_GEXTH           30      // Threshold for exiting gesture mode
#define SF_APDS9960_DEFAULT_GCONF1          0x40    // 4 gesture events for int., 1 for exit
#define SF_APDS9960_DEFAULT_GGAIN           SF_APDS9960_GGAIN_4X
#define SF_APDS9960_DEFAULT_GLDRIVE         SF_APDS9960_LED_DRIVE_100MA
#define SF_APDS9960_DEFAULT_GWTIME          SF_APDS9960_GWTIME_2_8MS
#define SF_APDS9960_DEFAULT_GOFFSET         0       // No offset scaling for gesture mode
#define SF_APDS9960_DEFAULT_GPULSE          0xC9    // 32us, 10 pulses
#define SF_APDS9960_DEFAULT_GCONF3          0       // All photodiodes active during gesture
#define SF_APDS9960_DEFAULT_GIEN            0       // Disable gesture interrupts

/* Direction definitions */
enum {
    SF_APDS9960_DIR_NONE,
    SF_APDS9960_DIR_LEFT,
    SF_APDS9960_DIR_RIGHT,
    SF_APDS9960_DIR_UP,
    SF_APDS9960_DIR_DOWN,
    SF_APDS9960_DIR_NEAR,
    SF_APDS9960_DIR_FAR,
    SF_APDS9960_DIR_ALL
};

/* State definitions */
enum {
    SF_APDS9960_NA_STATE,
    SF_APDS9960_NEAR_STATE,
    SF_APDS9960_FAR_STATE,
    SF_APDS9960_ALL_STATE
};

/* Container for gesture data */
typedef struct SF_APDS9960_gesture_data_type {
    uint8_t u_data[32];
    uint8_t d_data[32];
    uint8_t l_data[32];
    uint8_t r_data[32];
    uint8_t index;
    uint8_t total_gestures;
    uint8_t in_threshold;
    uint8_t out_threshold;
} SF_APDS9960_gesture_data_type;


/* Initialization methods */
bool SF_APDS9960_init();
uint8_t SF_APDS9960_getMode();
bool SF_APDS9960_setMode(uint8_t mode, uint8_t enable);

/* Turn the APDS-9960 on and off */
bool SF_APDS9960_enablePower();
bool SF_APDS9960_disablePower();

/* Enable or disable specific sensors */
bool SF_APDS9960_enableLightSensor(bool interrupts);
bool SF_APDS9960_disableLightSensor();
bool SF_APDS9960_enableProximitySensor(bool interrupts );
bool SF_APDS9960_disableProximitySensor();
bool SF_APDS9960_enableGestureSensor(bool interrupts );
bool SF_APDS9960_disableGestureSensor();

/* LED drive strength control */
uint8_t SF_APDS9960_getLEDDrive();
bool SF_APDS9960_setLEDDrive(uint8_t drive);
uint8_t SF_APDS9960_getGestureLEDDrive();
bool SF_APDS9960_setGestureLEDDrive(uint8_t drive);

/* Gain control */
uint8_t SF_APDS9960_getAmbientLightGain();
bool SF_APDS9960_setAmbientLightGain(uint8_t gain);
uint8_t SF_APDS9960_getProximityGain();
bool SF_APDS9960_setProximityGain(uint8_t gain);
uint8_t SF_APDS9960_getGestureGain();
bool SF_APDS9960_setGestureGain(uint8_t gain);

/* Get and set light interrupt thresholds */
bool SF_APDS9960_getLightIntLowThreshold(uint16_t *threshold);
bool SF_APDS9960_setLightIntLowThreshold(uint16_t threshold);
bool SF_APDS9960_getLightIntHighThreshold(uint16_t *threshold);
bool SF_APDS9960_setLightIntHighThreshold(uint16_t threshold);

/* Get and set proximity interrupt thresholds */
bool SF_APDS9960_getProximityIntLowThreshold(uint8_t *threshold);
bool SF_APDS9960_setProximityIntLowThreshold(uint8_t threshold);
bool SF_APDS9960_getProximityIntHighThreshold(uint8_t *threshold);
bool SF_APDS9960_setProximityIntHighThreshold(uint8_t threshold);

/* Get and set interrupt enables */
uint8_t SF_APDS9960_getAmbientLightIntEnable();
bool SF_APDS9960_setAmbientLightIntEnable(uint8_t enable);
uint8_t SF_APDS9960_getProximityIntEnable();
bool SF_APDS9960_setProximityIntEnable(uint8_t enable);
uint8_t SF_APDS9960_getGestureIntEnable();
bool SF_APDS9960_setGestureIntEnable(uint8_t enable);

/* Clear interrupts */
bool SF_APDS9960_clearAmbientLightInt();
bool SF_APDS9960_clearProximityInt();

/* Ambient light methods */
bool SF_APDS9960_readAmbientLight(uint16_t *val);
bool SF_APDS9960_readRedLight(uint16_t *val);
bool SF_APDS9960_readGreenLight(uint16_t *val);
bool SF_APDS9960_readBlueLight(uint16_t *val);

/* Proximity methods */
bool SF_APDS9960_readProximity(uint8_t *val);

/* Gesture methods */
bool SF_APDS9960_isGestureAvailable();
int SF_APDS9960_readGesture();


bool SF_APDS9960_wireReadDataByte(uint8_t ucRegAddr, uint8_t *pucRegValue);




#endif //  __BMA222_H__
