# Projects with TM4C123G microcontroller.

![Figure 1](https://github.com/AndresCasasola/freeRTOS-projects/raw/master/Resources/Images/tiva.jpg "Figure 1")
<p align="center">
  <img width="400" height="300" src="https://github.com/AndresCasasola/freeRTOS-projects/raw/master/Resources/Images/tiva.jpg">
</p>

In this repository will be shown how to program the launchpad Tiva C Series with TM4C123GH6PM microcontroller from Texas Instruments. 
The software used will be Code Composer Studio and Qt for the interface applications.

### FreeRTOS projects
In the CCSProjects folder there are examples of projects in Code Composer Studio using the launchpad pheriperals like buttons, leds, timers... The major part of them running under FreeRTOS.

### Tivaria - Interface application with Qt
In the Qt-Interface folder there are a real time interface application implemented with Qt. It contains a CCS project named *CCSApplication* for the tiva launchpad and another project for Qt named *QtApplication*. To get ready with this application is necessary to connect the tiva with both usb connectors to PC. The main usb connector (*Device/Debug*) will be used to power the launchpad and load the CCS project to the microcontroller. The second usb connector (set on the lateral) will be used to implement the communication between the microcontroller and the interface running on Qt.

In the following figure is shown the interface application with the ADC graph plotter running.

![Figure 2](https://github.com/AndresCasasola/freeRTOS-projects/raw/master/Resources/Images/tivaia_capture.png "Figure 2")

##### Qt Interface features
- GPIO or RGB control for leds
- Buttons state capture
- Oscilloscope

