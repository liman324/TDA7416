#include <Arduino.h>
#include <Wire.h>
#include "TDA7416.h"

TDA7416::TDA7416(){
	Wire.begin();
}

void TDA7416::set_input(byte sourse_sel, byte input_gain, bool mute){
  writeWire(TDA7416_SOURCE_SEL, sourse_sel | (input_gain << 3) | (mute << 7));
}

void TDA7416::set_loudness(byte att_loud, byte center_f, bool loud_order){
  writeWire(TDA7416_LOUDNESS, att_loud | (center_f << 5) | (loud_order << 7));
}

void TDA7416::set_volume(int volume){
  byte vol_byte;
  if(volume>=0){vol_byte = 64 - volume;}
  if(volume<0){vol_byte = 64 + abs(volume);}
  writeWire(TDA7416_VOLUME , vol_byte);
}

void TDA7416::set_eq1(int eq1_gain, byte q1_factor, bool f1_f2){
  byte eq1_gain_byte;
  if(eq1_gain<0){eq1_gain_byte = eq1_gain + 15;}
  if(eq1_gain>=0){eq1_gain_byte = eq1_gain + 0b10000;}
  writeWire(TDA7416_EQ_F1, eq1_gain_byte | (q1_factor << 5) | (f1_f2 << 7));
}

void TDA7416::set_eq2(int eq2_gain, byte q2_factor){
  byte eq2_gain_byte;
  if(eq2_gain<0){eq2_gain_byte = eq2_gain + 15;}
  if(eq2_gain>=0){eq2_gain_byte = eq2_gain + 0b10000;}
  writeWire(TDA7416_EQ_F2, eq2_gain_byte | (q2_factor << 5));
}

void TDA7416::set_eq3(int eq3_gain, byte q3_factor){
  byte eq3_gain_byte;
  if(eq3_gain<0){eq3_gain_byte = eq3_gain + 15;}
  if(eq3_gain>=0){eq3_gain_byte = eq3_gain + 0b10000;}
  writeWire(TDA7416_EQ_F3, eq3_gain_byte | (q3_factor << 5));
}

void TDA7416::set_eq4(int eq4_gain, byte q4_factor){
  byte eq4_gain_byte;
  if(eq4_gain<0){eq4_gain_byte = eq4_gain + 15;}
  if(eq4_gain>=0){eq4_gain_byte = eq4_gain + 0b10000;}
  writeWire(TDA7416_EQ_F4, eq4_gain_byte | (q4_factor << 5));
}

void TDA7416::set_eq5(int eq5_gain, byte q5_factor){
  byte eq5_gain_byte;
  if(eq5_gain<0){eq5_gain_byte = eq5_gain + 15;}
  if(eq5_gain>=0){eq5_gain_byte = eq5_gain + 0b10000;}
  writeWire(TDA7416_EQ_F5, eq5_gain_byte | (q5_factor << 5));
}

void TDA7416::set_eq6(int eq6_gain, byte q6_factor, bool f3_f4){
  byte eq6_gain_byte;
  if(eq6_gain<0){eq6_gain_byte = eq6_gain + 15;}
  if(eq6_gain>=0){eq6_gain_byte = eq6_gain + 0b10000;}
  writeWire(TDA7416_EQ_F6, eq6_gain_byte | (q6_factor << 5) | (f3_f4 << 7));
}

void TDA7416::set_eq7(int eq7_gain, byte q7_factor, bool f5_f6){
  byte eq7_gain_byte;
  if(eq7_gain<0){eq7_gain_byte = eq7_gain + 15;}
  if(eq7_gain>=0){eq7_gain_byte = eq7_gain + 0b10000;}
  writeWire(TDA7416_EQ_F7, eq7_gain_byte | (q7_factor << 5) | (f5_f6 << 7));
}

void TDA7416::set_miz_prog(bool mix_on_off, byte read_sourse_sel, bool mix_target_lf, bool mix_target_rf, bool zero, bool spec_detect){
  writeWire(TDA7416_MIX_PROG, mix_on_off | (read_sourse_sel << 1) | (mix_target_lf << 3)| (mix_target_rf << 4) | (zero << 6) | (spec_detect << 7));
}

void TDA7416::set_soft_mute(bool mute, byte mute_time, bool high_pass, byte high_pass_eff){
  writeWire(TDA7416_SOFT_MUTE, mute | (mute_time << 1) | (high_pass << 3) | (high_pass_eff << 4));
}

void TDA7416::set_sub(byte sub_filter, bool sub_coupling, bool spec_q_factor, bool high_pass_en, byte high_pass_cut_f){
  writeWire(TDA7416_SUB_SPEC_HPAS, sub_filter | (sub_coupling << 2) | (spec_q_factor << 4) | (high_pass_en << 5) | (high_pass_cut_f << 6));
}

void TDA7416::set_conf_audio(bool pd_in_mode, bool pd_in_gain, bool soft_step_vol, byte soft_step_time, bool loud, bool front_ac, bool rear_effect){
  writeWire(TDA7416_CONF_AUDIO, pd_in_mode | (pd_in_gain << 1) | (soft_step_vol << 2) | (soft_step_time << 3) | (loud << 5) | (front_ac << 6) | (rear_effect << 7));
}

void TDA7416::set_mix_att(int mix_att){
  byte mix_att_byte;
  if(mix_att>0){mix_att_byte = mix_att + 0b10000000;}
  if(mix_att<=0){mix_att_byte = abs(mix_att);}
  writeWire(TDA7416_MIX_LEVEL, mix_att_byte);
}

void TDA7416::set_lf_att(int lf_att, bool soft_step_lf){
  byte lf_att_byte;
  if(lf_att>0){lf_att_byte = lf_att;}
  if(lf_att<=0){lf_att_byte = abs(lf_att)+16;}
  writeWire(TDA7416_ATT_LF, lf_att_byte | (soft_step_lf << 7));
}

void TDA7416::set_rf_att(int rf_att, bool soft_step_rf){
  byte rf_att_byte;
  if(rf_att>0){rf_att_byte = rf_att;}
  if(rf_att<=0){rf_att_byte = abs(rf_att)+16;}
  writeWire(TDA7416_ATT_RF, rf_att_byte | (soft_step_rf << 7));
}

void TDA7416::set_lr_att(int lr_att, bool soft_step_lr){
  byte lr_att_byte;
  if(lr_att>0){lr_att_byte = lr_att;}
  if(lr_att<=0){lr_att_byte = abs(lr_att)+16;}
  writeWire(TDA7416_ATT_LR, lr_att_byte | (soft_step_lr << 7));
}

void TDA7416::set_rr_att(int rr_att, bool soft_step_rr){
  byte rr_att_byte;
  if(rr_att>0){rr_att_byte = rr_att;}
  if(rr_att<=0){rr_att_byte = abs(rr_att)+16;}
  writeWire(TDA7416_ATT_RR, rr_att_byte | (soft_step_rr << 7));
}

void TDA7416::set_sub_att(int sub_att, bool soft_step_sub){
  byte sub_att_byte;
  if(sub_att>0){sub_att_byte = sub_att;}
  if(sub_att<=0){sub_att_byte = abs(sub_att)+16;}
  writeWire(TDA7416_ATT_SUB, sub_att_byte | (soft_step_sub << 7));
}

void TDA7416::set_test(byte test){
  writeWire(TDA7416_TEST, 0b00000000);
}



void TDA7416::writeWire(char a, char b){
  Wire.beginTransmission(TDA7416_ADDR);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
