void lamp_indicator(){
  if(curent_alarm==HIGH&&Mole_curent_state==HIGH)
  {
    digitalWrite(G_indicator,indicator_on);
    digitalWrite(R_indicator,indicator_off);
  }
  else
  {
    if(curent_alarm==LOW&&Mole_curent_state==HIGH)
    {
      digitalWrite(G_indicator,indicator_off);
      digitalWrite(R_indicator,indicator_on);
    }
  }
}
