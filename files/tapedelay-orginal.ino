#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>

// GUItool: begin automatically generated code
AudioInputI2S i2s1;       // xy=206,94
AudioMixer4 mixer1;       // xy=523,76
AudioEffectDelay delay1;  // xy=538,236
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


void setup(void) {
  Serial.begin(9600);
  AudioMemory(150 * (128 / AUDIO_BLOCK_SAMPLES));
  codec.enable();
  codec.volume(0.5);

  mixer1.gain(0, 0.7);
  mixer1.gain(1, 0.7);
  mixer1.gain(2, 0.5);
  mixer1.gain(3, 0.0);

  delay1.delay(0, 150);
  delay1.delay(1, 250);
  delay1.delay(2, 400);
}

void loop(void) {
  //Serial.println("Delay 1");
  //delay1.delay(0, 50);
  //delay1.delay(1, 75);
  //delay1.delay(2, 400);
  //delay(2000);
  //Serial.println("Delay 2");
  //delay1.delay(0, 150);
  //delay1.delay(1, 250);
  //delay1.delay(2, 400);
  //delay(9000);
}
