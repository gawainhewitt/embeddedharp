#include "Harp_samples.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWavetable      wavetable2;     //xy=248,126
AudioSynthWavetable      wavetable5;     //xy=248,249
AudioSynthWavetable      wavetable6;     //xy=248,289
AudioSynthWavetable      wavetable1;     //xy=249,86
AudioSynthWavetable      wavetable3;     //xy=249,168
AudioSynthWavetable      wavetable4;     //xy=250,209
AudioSynthWavetable      wavetable7;     //xy=250,328
AudioSynthWavetable      wavetable8;     //xy=251,367
AudioSynthWavetable      wavetable9;     //xy=254,405
AudioSynthWavetable      wavetable10;    //xy=255,442
AudioSynthWavetable      wavetable11;    //xy=256,482
AudioEffectEnvelope      envelope8;      //xy=384,357
AudioEffectEnvelope      envelope2;      //xy=385,124
AudioEffectEnvelope      envelope4;      //xy=385,205
AudioEffectEnvelope      envelope5;      //xy=385,240
AudioEffectEnvelope      envelope3;      //xy=386,164
AudioEffectEnvelope      envelope7;      //xy=386,321
AudioEffectEnvelope      envelope1;      //xy=387,86
AudioEffectEnvelope      envelope6;      //xy=389,284
AudioEffectEnvelope      envelope9;      //xy=394,397
AudioEffectEnvelope      envelope10;     //xy=401,440
AudioEffectEnvelope      envelope11;     //xy=415,482
AudioMixer4              mixer1;         //xy=525,155
AudioMixer4              mixer2;         //xy=554,310
AudioMixer4              mixer3;         //xy=572,434
AudioMixer4              mixer4;         //xy=742,299
AudioAmplifier           amp1;           //xy=869,285
AudioOutputI2S           i2s1;           //xy=1164,290
AudioConnection          patchCord1(wavetable2, envelope2);
AudioConnection          patchCord2(wavetable5, envelope5);
AudioConnection          patchCord3(wavetable6, envelope6);
AudioConnection          patchCord4(wavetable1, envelope1);
AudioConnection          patchCord5(wavetable3, envelope3);
AudioConnection          patchCord6(wavetable4, envelope4);
AudioConnection          patchCord7(wavetable7, envelope7);
AudioConnection          patchCord8(wavetable8, envelope8);
AudioConnection          patchCord9(wavetable9, envelope9);
AudioConnection          patchCord10(wavetable10, envelope10);
AudioConnection          patchCord11(wavetable11, envelope11);
AudioConnection          patchCord12(envelope8, 0, mixer2, 3);
AudioConnection          patchCord13(envelope2, 0, mixer1, 1);
AudioConnection          patchCord14(envelope4, 0, mixer1, 3);
AudioConnection          patchCord15(envelope5, 0, mixer2, 0);
AudioConnection          patchCord16(envelope3, 0, mixer1, 2);
AudioConnection          patchCord17(envelope7, 0, mixer2, 2);
AudioConnection          patchCord18(envelope1, 0, mixer1, 0);
AudioConnection          patchCord19(envelope6, 0, mixer2, 1);
AudioConnection          patchCord20(envelope9, 0, mixer3, 0);
AudioConnection          patchCord21(envelope10, 0, mixer3, 1);
AudioConnection          patchCord22(envelope11, 0, mixer3, 2);
AudioConnection          patchCord23(mixer1, 0, mixer4, 0);
AudioConnection          patchCord24(mixer2, 0, mixer4, 1);
AudioConnection          patchCord25(mixer3, 0, mixer4, 2);
AudioConnection          patchCord26(mixer4, amp1);
AudioConnection          patchCord27(amp1, 0, i2s1, 0);
AudioConnection          patchCord28(amp1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=622,600
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

int octave = 48;

const int numberOfSensors = 11;

byte major[] = {0, 4, 7, 12, 16, 19, 24, 28, 31, 36, 40};
byte minor[] = {0, 3, 7, 12, 15, 19, 24, 27, 31, 36, 39};
byte dom7[] = {0, 4, 7, 10, 12, 16, 19, 22, 24, 28, 31};
byte maj7[] = {0, 4, 7, 11, 12, 16, 19, 23, 24, 28, 31};
byte min7[] = {0, 3, 7, 10, 12, 15, 19, 22, 24, 27, 31};

byte chord[] = {0, 4, 7, 12, 16, 19, 24, 28, 31, 36, 40}; // default to major

int currentChord = 0;
int numChords = 5;

String chordTypeName = "";


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

    int attackAmount = 3;

    envelope1.attack(attackAmount);
    envelope2.attack(attackAmount);
    envelope3.attack(attackAmount);
    envelope4.attack(attackAmount);
    envelope5.attack(attackAmount);
    envelope6.attack(attackAmount);
    envelope7.attack(attackAmount);
    envelope8.attack(attackAmount);
    envelope9.attack(attackAmount);
    envelope10.attack(attackAmount);
    envelope11.attack(attackAmount);


    mixer1.gain(0, 0.8);
    mixer1.gain(1, 0.8);
    mixer1.gain(2, 0.8);
    mixer1.gain(3, 0.8);

    mixer2.gain(0, 0.8);
    mixer2.gain(1, 0.8);
    mixer2.gain(2, 0.8);
    mixer2.gain(3, 0.8);

    mixer3.gain(0, 0.8);
    mixer3.gain(1, 0.8);
    mixer3.gain(2, 0.8);
    mixer3.gain(3, 0);

    mixer4.gain(0, 0.8);
    mixer4.gain(1, 0.8);
    mixer4.gain(2, 0.8);
    mixer4.gain(3, 0);

}

void playSound(int octave, int note) {
    switch(note) 
    {
        case 0:
            wavetable1.playFrequency(freqnotes[keyPosition + chord[note]+ octave]);
            envelope1.noteOn();
            break;
        case 1:
            wavetable2.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope2.noteOn();
            break;
        case 2:
            wavetable3.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope3.noteOn();
            break;
        case 3:
            wavetable4.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope4.noteOn();
            break;
        case 4:
            wavetable5.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope5.noteOn();
            break;
        case 5:
            wavetable6.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope6.noteOn();
            break;
        case 6:
            wavetable7.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope7.noteOn();
            break;
        case 7:
            wavetable8.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope8.noteOn();
            break;
        case 8:
            wavetable9.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope9.noteOn();
            break;
        case 9:
            wavetable10.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope10.noteOn();
            break;
        case 10:
            wavetable11.playFrequency(freqnotes[keyPosition + chord[note] + octave]);
            envelope11.noteOn();
            break;
    }
}

void changeChord(int chordType) {
    
    switch(chordType) {
        case 0: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        chord[i] = major[i];
        chordTypeName = "";
        }
        break;
        case 1: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        chord[i] = minor[i];
        chordTypeName = "Minor";
        }
        break;
        case 2: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        chord[i] = dom7[i];
        chordTypeName = "Dom7";
        }
        break;
        case 3: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        chord[i] = maj7[i];
        chordTypeName = "Maj7";
        }
        break;
        case 4: 
        for (uint8_t i=0; i < numberOfSensors; i++) {
        chord[i] = min7[i];
        chordTypeName = "min7";
        }
    }
}
