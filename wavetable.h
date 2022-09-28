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
AudioConnection          patchCord16(amp1, 0, i2s1, 0);
AudioConnection          patchCord17(amp1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=694,834
// GUItool: end automatically generated code

float freqnotes[] = {
16.35,      17.32,      18.35,      19.45,      20.60,      21.83,      23.12,      24.50,      25.96,      27.50,      29.14,      30.87, 
32.70,      34.65,      36.71,      38.89,      41.20,      43.65,      46.25,      49.00,      51.91,      55.00,      58.27,      61.74, 
65.41,      69.30,      73.42,      77.78,      82.41,      87.31,      92.50,      98.00,      103.83,     110.00,     116.54,     123.47, 
130.81,     138.59,     146.83,     155.56,     164.81,     174.61,     185.00,     196.00,     207.65,     220.00,     233.08,     246.94, 
261.63,     277.18,     293.66,     311.13,     329.63,     349.23,     369.99,     392.00,     415.30,     440.00,     466.16,     493.88, 
523.25,     554.37,     587.33,     622.25,     659.26,     698.46,     739.99,     783.99,     830.61,     880.00,     932.33,     987.77,       
1046.50,    1108.73,    1174.66,    1244.51,    1318.51,    1396.91,    1479.98,    1567.98,    1661.22,    1760.00,    1864.66,    1975.53, 
2093.00,    2217.46,    2349.32,    2489.02,    2637.02,    2793.83,    2959.96,    3135.96,    3322.44,    3520.00,    3729.31,    3951.07,      
4186.01,    4434.92,    4698.64,    4978.03};

const String noteNames[24]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

String keyName = "C";
int keyPosition = 0;
// keyName = noteNames[keyPosition];

int octave = 48;

const int numberOfSensors = 11;

byte chromatic[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
byte major[] = {0, 4, 7, 12, 16, 19, 24, 28, 31, 36, 40};
byte minor[] = {0, 3, 7, 12, 15, 19, 24, 27, 31, 36, 39};
byte dom7[] = {0, 4, 7, 10, 12, 16, 19, 22, 24, 28, 31};
byte maj7[] = {0, 4, 7, 11, 12, 16, 19, 23, 24, 28, 31};
byte min7[] = {0, 3, 7, 10, 12, 15, 19, 22, 24, 27, 31};

byte scale[] = {0, 4, 7, 12, 16, 19, 24, 28, 31, 36, 40}; // default to major

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

    int wavetableAmplitude = 1;

    wavetable1.amplitude(wavetableAmplitude);
    wavetable2.amplitude(wavetableAmplitude);
    wavetable3.amplitude(wavetableAmplitude);
    wavetable4.amplitude(wavetableAmplitude);
    wavetable5.amplitude(wavetableAmplitude);
    wavetable6.amplitude(wavetableAmplitude);
    wavetable7.amplitude(wavetableAmplitude);
    wavetable8.amplitude(wavetableAmplitude);
    wavetable9.amplitude(wavetableAmplitude);
    wavetable10.amplitude(wavetableAmplitude);
    wavetable11.amplitude(wavetableAmplitude);

    mixer1.gain(0, 0.5);
    mixer1.gain(1, 0.5);
    mixer1.gain(2, 0.5);
    mixer1.gain(3, 0.5);

    mixer2.gain(0, 0.5);
    mixer2.gain(1, 0.5);
    mixer2.gain(2, 0.5);
    mixer2.gain(3, 0.5);

    mixer3.gain(0, 0.5);
    mixer3.gain(1, 0.5);
    mixer3.gain(2, 0.5);
    mixer3.gain(3, 0);

    mixer4.gain(0, 0.5);
    mixer4.gain(1, 0.5);
    mixer4.gain(2, 0.5);
    mixer4.gain(3, 0);

}

void playSound(int octave, int note) {
    switch(note) 
    {
        case 0:
            wavetable1.playFrequency(freqnotes[keyPosition + scale[note]+ octave]);
            break;
        case 1:
            wavetable2.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 2:
            wavetable3.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 3:
            wavetable4.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 4:
            wavetable5.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 5:
            wavetable6.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 6:
            wavetable7.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 7:
            wavetable8.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 8:
            wavetable9.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 9:
            wavetable10.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
        case 10:
            wavetable11.playFrequency(freqnotes[keyPosition + scale[note] + octave]);
            break;
    }
}

void changeScale(int scaleType) {
    
    switch(scaleType) {
        case 0: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        scale[i] = major[i];
        }
        case 1: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        scale[i] = minor[i];
        }
        case 2: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        scale[i] = dom7[i];
        }
        case 3: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        scale[i] = maj7[i];
        }
        case 4: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        scale[i] = min7[i];
        }
    }
}
