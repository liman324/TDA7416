#include <TDA7416.h>
#include <Wire.h>
TDA7416 tda;

void setup() {
  delay(500); 
  audio();
}

void loop() {
 
}

void audio(){
  tda.set_input(0, 0, 0); 
// Source selector 1...4 === byte 0...3
// Input gain 0...15 dB === byte 0...15
// Mute bool 0=off, 1=on
        tda.set_loudness(0, 0, 1);   
// Attenuation 0...-19 dB === byte 0...19
// Center frequency 200/400/600/800 Hz === byte 0...3
// Loudness order bool 0 = First order, bool 1 = Second order 
        tda.set_volume(0);
// Volume +32.0...-79.5 dB step 0.5 dB === int +64...-159 /// int 1 = 0.5 dB
        tda.set_eq1(0, 0, 0);
// 62/100 Hz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
// Equalizer center frequency 62/100 Hz === bool 0...1
        tda.set_eq2(0, 0);
// 157 Hz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        tda.set_eq3(0, 0);
// 396 Hz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        tda.set_eq4(0, 0);
// 1 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        tda.set_eq5(0, 0);
// 2.51 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        tda.set_eq6(0, 0, 0);
// 4/6.34 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
// Equalizer center frequency 4/6.34 kHz === bool 0...1
        tda.set_eq7(0, 0, 0);
// 15/16 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
// Equalizer center frequency 15/16 kHz === bool 0...1
        tda.set_miz_prog(0, 3, 0, 0, 1, 1);
// Mixing mute/eneble === bool 0...1
// Rear Source Selector input 1...4 === byte 0...3
// Mixing Target Speaker LF off/on === bool 0...1
// Mixing Target Speaker RF off/on === bool 0...1
// ZeroCross on HPF2 on/off === bool 0...1
// Spectrum Analyzer Detect Point  After EQ/Before EQ === bool 0...1
        tda.set_soft_mute(0, 2, 1, 10);
// Soft-mute on/off === bool 0...1
// Soft-mute time 0.48/0.96/123 ms === byte 0...2
// Secondary high-pass enable Filter available/No Filter (Gain) === bool 0...1
// Secondary high-pass effect (with ZeroCross) 4/6/8/10/12/14/16/18/20/22/0 dB === byte 0...10
        tda.set_sub(2, 1, 1, 1, 3);
// Subwoofer Filter off/80/120/160 Hz === byte 0...3
// Subwoofer Coupling  AC using SWIn pin/DC === bool 0...1
// Spectrum Analyzer Q-Factor 3.5/1.8 === bool 0...1
// High-pass enable off/on === bool 0...1
// High-pass cut-off frequency 90/135/180/225 === byte 0...3
        tda.set_conf_audio(0, 1, 1, 3, 1, 1, 1);
// PD input mode  single ended/pseudo differential === bool 0...1
// PD Input Gain -6/0 dB === bool 0...1
// Soft-step volume off/on === 0...1
// Soft-step time 0.32/1.28/5.12/20.4 ms === byte 0...3
// Loudness  flat/filter On === bool 0...1 
// Front AC speaker  AC coupling (ACin)/DC coupling === bool 0...1
// Rear effect  No effect signal/Equalizing signal === bool 0...1
        tda.set_mix_att(0);
// Gain/Attenuation +15...-79 dB === int 15...-79
        tda.set_lf_att(0, 1);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        tda.set_rf_att(0, 1);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        tda.set_lr_att(0, 1);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        tda.set_rr_att(0, 1);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        tda.set_sub_att(0, 1);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        tda.set_test(0);// 0b10000000 SC-Clock Normal mode
// off === byte 0

  }
 
