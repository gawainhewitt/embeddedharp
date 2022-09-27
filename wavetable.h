#include "Harp_samples.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWavetable      wavetable2;     //xy=320,360
AudioSynthWavetable      wavetable5;     //xy=320,483
AudioSynthWavetable      wavetable6;     //xy=320,523
AudioSynthWavetable      wavetable1;     //xy=321,320
AudioSynthWavetable      wavetable3;     //xy=321,402
AudioSynthWavetable      wavetable4;     //xy=322,443
AudioSynthWavetable      wavetable7;     //xy=322,562
AudioSynthWavetable      wavetable8;     //xy=323,601
AudioSynthWavetable      wavetable9;     //xy=326,639
AudioSynthWavetable      wavetable10;    //xy=327,676
AudioSynthWavetable      wavetable11;    //xy=328,716
AudioMixer4              mixer1;         //xy=597,389
AudioMixer4              mixer2;         //xy=626,544
AudioMixer4              mixer3;         //xy=644,668
AudioMixer4              mixer4;         //xy=814,533
AudioAmplifier           amp1;           //xy=941,519
AudioEffectFreeverbStereo freeverbs1;     //xy=1081,521
AudioOutputI2S           i2s1;           //xy=1236,524
AudioConnection          patchCord1(wavetable2, 0, mixer1, 1);
AudioConnection          patchCord2(wavetable5, 0, mixer2, 0);
AudioConnection          patchCord3(wavetable6, 0, mixer2, 1);
AudioConnection          patchCord4(wavetable1, 0, mixer1, 0);
AudioConnection          patchCord5(wavetable3, 0, mixer1, 2);
AudioConnection          patchCord6(wavetable4, 0, mixer1, 3);
AudioConnection          patchCord7(wavetable7, 0, mixer2, 2);
AudioConnection          patchCord8(wavetable8, 0, mixer2, 3);
AudioConnection          patchCord9(wavetable9, 0, mixer3, 0);
AudioConnection          patchCord10(wavetable10, 0, mixer3, 1);
AudioConnection          patchCord11(wavetable11, 0, mixer3, 2);
AudioConnection          patchCord12(mixer1, 0, mixer4, 0);
AudioConnection          patchCord13(mixer2, 0, mixer4, 1);
AudioConnection          patchCord14(mixer3, 0, mixer4, 2);
AudioConnection          patchCord15(mixer4, amp1);
AudioConnection          patchCord16(amp1, freeverbs1);
AudioConnection          patchCord17(freeverbs1, 0, i2s1, 0);
AudioConnection          patchCord18(freeverbs1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=694,834
// GUItool: end automatically generated code


float freqnotes[24][9] = {
{16.35, 32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01}, 
{17.32, 34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 4434.92},
{18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.64},
{19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02, 4978.03},
{20.60, 41.20, 82.41, 164.81, 329.63, 659.26, 1318.51, 2637.02},
{21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83},
{23.12, 46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96},
{24.50, 49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96},
{25.96, 51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44},
{27.50, 55.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00},
{29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31},
{30.87, 61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07},
{32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01}, 
{34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 4434.92},
{36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.64},
{38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02, 4978.03},
{41.20, 82.41, 164.81, 329.63, 659.26, 1318.51, 2637.02},
{43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83},
{46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96},
{49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96},
{51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44},
{55.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00},
{58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31},
{61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07}
};

const String noteNames[24]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

String keyName = "C";

int keyPosition = 3;

void setupAudio() {

    AudioMemory(20);

    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);

    wavetable1.setInstrument(Harp);
    wavetable2.setInstrument(Harp);
    wavetable3.setInstrument(Harp);
    wavetable4.setInstrument(Harp);
    wavetable5.setInstrument(Harp);
    wavetable6.setInstrument(Harp);
    wavetable7.setInstrument(Harp);
    wavetable8.setInstrument(Harp);
    wavetable9.setInstrument(Harp);
    wavetable10.setInstrument(Harp);
    wavetable11.setInstrument(Harp);

    wavetable1.amplitude(0.6);
    wavetable2.amplitude(0.6);
    wavetable3.amplitude(0.6);
    wavetable4.amplitude(0.6);
    wavetable5.amplitude(0.6);
    wavetable6.amplitude(0.6);
    wavetable7.amplitude(0.6);
    wavetable8.amplitude(0.6);
    wavetable9.amplitude(0.6);
    wavetable10.amplitude(0.6);
    wavetable11.amplitude(0.6);

    freeverbs1.roomsize(0.3);
    freeverbs1.damping(0.6);
}

void playSound(int octave, int note) {
    keyName = noteNames[keyPosition];
    switch(note) 
    {
        case 0:
            wavetable1.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 1:
            wavetable2.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 2:
            wavetable3.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 3:
            wavetable4.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 4:
            wavetable5.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 5:
            wavetable6.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 6:
            wavetable7.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 7:
            wavetable8.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 8:
            wavetable9.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 9:
            wavetable10.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
        case 10:
            wavetable11.playFrequency(freqnotes[note + keyPosition][octave]);
            break;
    }
    
}
