#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "Harp_samples.h"

// GUItool: begin automatically generated code
AudioSynthWavetable      wavetable1;     //xy=648,281
AudioOutputI2S           i2s1;           //xy=1044,387
AudioConnection          patchCord1(wavetable1, 0, i2s1, 0);
AudioConnection          patchCord2(wavetable1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=694,834
// GUItool: end automatically generated code

float freqnotes[12][9] = {{16.35, 32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01}, {17.32, 34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 4434.92},{18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.64},{19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02, 4978.03},{20.60, 41.20, 82.41, 164.81, 329.63, 659.26, 1318.51, 2637.02},{21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83},{23.12, 46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96},{24.50, 49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96},{25.96, 51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44},{27.50, 55.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00},{29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31},{30.87, 61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07}};

void setupAudio() {

    AudioMemory(20);

    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);

    wavetable1.setInstrument(Harp);
    wavetable1.amplitude(1);
}