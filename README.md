# PSRAM-Applications
A number of 64Mb (8MB) [**AP Memory Technology APS6404L-3SQN QSPI PSRAM**](https://www.mouser.com/ProductDetail/AP-Memory/APS6404L-3SQN-SN?qs=IS%252B4QmGtzzqCot9%252BeIJwKw%3D%3D) had been obtained from [**Mouser (Texas)**](https://www.mouser.com/), and are being tested through their single and quad SPI memory interface modes, for the latter using the RP2040 Pico (for which there is potential r/w QSPI support), and the established QSPI support for the Teensy 4.1 and ESP32's. 

Pictures 1 to 3. Two External PSRAM 8-pin DIP modules and a Teensy 4.1 with another PSRAM module soldered to its bottom.

<p align="left">
<img src="images/AP-psram7.jpg" width="164" />  
<img src="images/AP-psram8.jpg" width="650" /> 
<img src="images/Teensy41-psram1.jpg" width="817" />  
<br>
  
### Method 1. External PSRAM module connected via Teensy SPI 
An external PSRAM 8-pin DIP module was connected to a Teensy 4.1 (with another PSRAM module soldered to its bottom), which in turn, was connected to a Teensy Audio 3 board rev B as shown in picture 4 below:
  
Table 1: Connections between the external PSRAM module and a Teensy 4.1: 

| PSRAM  | Teensy 4.1 | 
|:-------|:-----------|
| 1      | 6          |
| 2      | 12         | 
| 3  NC  |	     	    | 
| 4      | GND        | 
| 5      | 11         | 
| 6      | 13         |
| 7      | 3v3        | 
| 8      | 3v3        | 
  
Picture 4. Two External PSRAM 8-pin DIP modules, a socketed 23LC1024, and a Teensy 4.1 (with another PSRAM module soldered to its bottom) connected to a Teensy Audio 3 board revision B.
  
<p align="left">
<img src="images/setup-teensy41-audio3.jpg" width="550" />  
<br>
  
As an initial check the 8MB-PSRAM module was tested with the direct SPI read/write code from here: [**Problem with 23LC1024 RAM memory - 31 August 2016**](https://forum.pjrc.com/threads/36563-Problem-with-23LC1024-RAM-memory). *The file used is also available here as 23LC1024a.ino.*
  
After it was established that the PSRAM can be accessed (read/write) using the same code as for the 23LC1024 SRAM, the Teensy audio code changes as suggested [**here on 12 August 2021**](https://forum.pjrc.com/threads/29276-Limits-of-delay-effect-in-audio-library/page5), were made, where the PSRAM was tested as a direct replacement for the 23LC1024 in the audio external-delay module. But as the delayed audio had significant audible distortion,  any further examination were postponed. *The files used are available here as effect_delay_ext.h, effect_delay_ext.cpp, and PassThroughStereo3.ino.*
  
### Method 2. PSRAM module directly connected to Teensy 4.1 bottom via QSPI 
Another approach the PSRAM connected to the bottom of the Teensy 4.1 was tested as an audio delay storage array, as suggested here: [**Audio Effect Delay Pops & Clicks when changing tap times - 5 September 2020**](https://forum.pjrc.com/threads/62739-Audio-Effect-Delay-Pops-amp-Clicks-when-changing-tap-times). *The files used are available [**here**](/files) as effect_tapedelay10tap.h, effect_tapedelay10tap.cpp, and tapedelay-example.ino.* To compile, keep all three files in the same folder named tapedelay-example.
  
`As this third approach worked very well, with no audible distortion and capable of exceptionally long delays, it will be investigated further.`


  
Note that all of this should be regarded as a work-in-progress, it is unfinished and documents infrequent experiments. **In addition the copyright of the various code sections and code files, belong to their owners, as identified by the links provided. Specifically, all [Teensy libraries](https://www.pjrc.com/teensy/) are the property of pjrc.com.**
