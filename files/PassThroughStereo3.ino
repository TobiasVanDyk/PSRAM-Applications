/*
 * A simple hardware test which receives audio from the audio shield
 * Line-In pins and send it to the Line-Out pins and headphone jack.
 *
 * This example code is in the public domain.
 */


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=119,204
AudioEffectDelayExternal delayExt1(AUDIO_MEMORY_PSRAM_8MB, 250);      //xy=343,123
//AudioEffectDelayExternal delayExt1;      //xy=343,123
AudioOutputI2S           i2s2;           //xy=655,199
AudioConnection          patchCord1(i2s1, 0, delayExt1, 0);
AudioConnection          patchCord2(i2s1, 1, i2s2, 1);
AudioConnection          patchCord3(delayExt1, 7, i2s2, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=347,335
// GUItool: end automatically generated code



const int myInput = AUDIO_INPUT_LINEIN;
//const int myInput = AUDIO_INPUT_MIC;


void setup() {
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(200); // 1000 more or less the max for teensy 4.1

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.7);

  delayExt1.delay(7, 320); //90 flange 200 to 300 reverb 800 to 2000 echo - more than 2000 then both channels stutter
}

elapsedMillis volmsec=0;

void loop() {

}
