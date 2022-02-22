// TDA7416 | rcl-radio.ru | liman324@yandex.ru | Автор: Лиман А.А.
#ifndef  TDA7416_H
#define  TDA7416_H

#define  TDA7416_ADDR          0b1000110 
#define  TDA7416_SOURCE_SEL    0b00000000
#define  TDA7416_LOUDNESS      0b00000001
#define  TDA7416_VOLUME        0b00000010
#define  TDA7416_EQ_F1         0b00000011
#define  TDA7416_EQ_F2         0b00000100
#define  TDA7416_EQ_F3         0b00000101
#define  TDA7416_EQ_F4         0b00000110
#define  TDA7416_EQ_F5         0b00000111
#define  TDA7416_EQ_F6         0b00001000
#define  TDA7416_EQ_F7         0b00001001
#define  TDA7416_MIX_PROG      0b00001010
#define  TDA7416_SOFT_MUTE     0b00001011
#define  TDA7416_SUB_SPEC_HPAS 0b00001100
#define  TDA7416_CONF_AUDIO    0b00001101
#define  TDA7416_MIX_LEVEL     0b00001110
#define  TDA7416_ATT_LF        0b00001111
#define  TDA7416_ATT_RF        0b00010000
#define  TDA7416_ATT_LR        0b00010001
#define  TDA7416_ATT_RR        0b00010010
#define  TDA7416_ATT_SUB       0b00010011
#define  TDA7416_TEST          0b00010100

#include <Arduino.h>
class  TDA7416
{
  public:
     TDA7416();
        void set_input(byte sourse_sel, byte input_gain, bool mute); 
// Source selector 1...4 === byte 0...3
// Input gain 0...15 dB === byte 0...15
// Mute bool 0=off, 1=on
        void set_loudness(byte att_loud, byte center_f, bool loud_order);   
// Attenuation 0...-19 dB === byte 0...19
// Center frequency 200/400/600/800 Hz === byte 0...3
// Loudness order bool 0 = First order, bool 1 = Second order 
        void set_volume(int volume);
// Volume +32.0...-79.5 dB step 0.5 dB === int +64...-159 /// int 1 = 0.5 dB
        void set_eq1(int eq1_gain, byte q1_factor, bool f1_f2);
// 62/100 Hz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
// Equalizer center frequency 62/100 Hz === bool 0...1
        void set_eq2(int eq2_gain, byte q2_factor);
// 157 Hz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        void set_eq3(int eq3_gain, byte q3_factor);
// 396 Hz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        void set_eq4(int eq4_gain, byte q4_factor);
// 1 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        void set_eq5(int eq5_gain, byte q5_factor);
// 2.51 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
        void set_eq6(int eq6_gain, byte q6_factor, bool f3_f4);
// 4/6.34 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
// Equalizer center frequency 4/6.34 kHz === bool 0...1
        void set_eq7(int eq7_gain, byte q7_factor, bool f5_f6);
// 15/16 kHz
// Equalizer cut/boost level -15...+15 dB === int -15...+15
// Equalizer Q-Factor 2.2/1.8/1.4/1.0 === byte 0...3
// Equalizer center frequency 15/16 kHz === bool 0...1
        void set_miz_prog(bool mix_on_off, byte read_sourse_sel, bool mix_target_lf, bool mix_target_rf, bool zero, bool spec_detect);
// Mixing mute/eneble === bool 0...1
// Rear Source Selector input 1...4 === byte 0...3
// Mixing Target Speaker LF off/on === bool 0...1
// Mixing Target Speaker RF off/on === bool 0...1
// ZeroCross on HPF2 on/off === bool 0...1
// Spectrum Analyzer Detect Point  After EQ/Before EQ === bool 0...1
        void set_soft_mute(bool mute, byte mute_time, bool high_pass, byte high_pass_eff);
// Soft-mute on/off === bool 0...1
// Soft-mute time 0.48/0.96/123 ms === byte 0...2
// Secondary high-pass enable Filter available/No Filter (Gain) === bool 0...1
// Secondary high-pass effect (with ZeroCross) 4/6/8/10/12/14/16/18/20/22/0 dB === byte 0...10
        void set_sub(byte sub_filter, bool sub_coupling, bool spec_q_factor, bool high_pass_en, byte high_pass_cut_f);
// Subwoofer Filter off/80/120/160 Hz === byte 0...3
// Subwoofer Coupling  AC using SWIn pin/DC === bool 0...1
// Spectrum Analyzer Q-Factor 3.5/1.8 === bool 0...1
// High-pass enable off/on === bool 0...1
// High-pass cut-off frequency 90/135/180/225 === byte 0...3
        void set_conf_audio(bool pd_in_mode, bool pd_in_gain, bool soft_step_vol, byte soft_step_time, bool loud, bool front_ac, bool rear_effect);
// PD input mode  single ended/pseudo differential === bool 0...1
// PD Input Gain -6/0 dB === bool 0...1
// Soft-step volume off/on === 0...1
// Soft-step time 0.32/1.28/5.12/20.4 ms === byte 0...3
// Loudness  flat/filter On === bool 0...1 
// Front AC speaker  AC coupling (ACin)/DC coupling === bool 0...1
// Rear effect  No effect signal/Equalizing signal === bool 0...1
        void set_mix_att(int mix_att);
// Gain/Attenuation +15...-79 dB === int 15...-79
        void set_lf_att(int lf_att, bool soft_step_lf);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        void set_rf_att(int rf_att, bool soft_step_rf);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        void set_lr_att(int lr_att, bool soft_step_lr);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        void set_rr_att(int rr_att, bool soft_step_rr);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        void set_sub_att(int sub_att, bool soft_step_sub);
// Gain/Attenuation -79...+15 dB === int -79...15
// Soft-step on/off === bool 0...1
        void set_test(byte test);
// off === byte 0



  private:
	void writeWire(char a, char b);
};
	
#endif // TDA7416_H
