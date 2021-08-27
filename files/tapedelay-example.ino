#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>
#include "effect_tapedelay10tap.h"

// GUItool: begin automatically generated code
AudioInputI2S i2s1;       // xy=206,94
AudioMixer4 mixer1;       // xy=523,76
AudioEffectTapeDelay10tap delay1;  // xy=538,236
AudioMixer4 mixer2;       // xy=766,197
AudioOutputI2S i2s2;      // xy=1099,196
AudioConnection patchCord1(i2s1, 0, mixer1, 0);
AudioConnection patchCord2(i2s1, 1, mixer1, 1);
AudioConnection patchCord3(mixer1, delay1);
AudioConnection patchCord4(mixer1, 0, mixer2, 2);
AudioConnection patchCord5(delay1, 0, mixer2, 0);
AudioConnection patchCord6(delay1, 1, mixer2, 1);
AudioConnection patchCord7(delay1, 2, mixer1, 2);
AudioConnection patchCord8(mixer2, 0, i2s2, 0);
AudioConnection patchCord9(mixer2, 0, i2s2, 1);
AudioControlSGTL5000 codec;  // xy=377,390
// GUItool: end automatically generated code

#define DELAY_MAX_LEN 22050*10  // buffer for samples @44100 samples per second, 22050 = 0.5s
//int16_t sample_delay_line[DELAY_MAX_LEN] = {};
EXTMEM int16_t sample_delay_line[DELAY_MAX_LEN] = {}; //PSRAM 8 MB

void setup(void) {
  Serial.begin(9600);
  AudioMemory(150 * (128 / AUDIO_BLOCK_SAMPLES));
  codec.enable();
  codec.volume(0.7);

  mixer1.gain(0, 0.7);
  mixer1.gain(1, 0.7);
  mixer1.gain(2, 0.5);
  mixer1.gain(3, 0.0);

  // initialise the delayline
  delay1.begin(sample_delay_line, DELAY_MAX_LEN);
}

void loop(void) {
  //Serial.println("Delay 1");
  //delay1.delayfade(0, 6, 3.0);  // (tap_number 0-9, millis of delay, milliseconds to tranistion from old to new time)
  //delay1.delayfade(1, 12, 3.0);
  //delay1.delayfade(2, 18, 3.0);
  //delay(2000);
  //Serial.println("Delay 2");
  //delay1.delayfade(0, 350, 3.0);
  //delay1.delayfade(1, 550, 3.0);
  delay1.delayfade(2, 850, 3.0);
  //delay(2000);
}
