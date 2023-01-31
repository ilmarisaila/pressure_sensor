#include "MegunoLink.h"

long loopCount;
long LastSent;
const unsigned SendInterval = 200;
TimePlot FSR_Plot;

void setup() {
  Serial.begin(9600);
  LastSent = millis();
  FSR_Plot.SetTitle("FSR voltage measurement");
  FSR_Plot.SetXlabel("Time");
  FSR_Plot.SetYlabel("Voltage");
  FSR_Plot.SetSeriesProperties("FSR A0", Plot::Magenta, Plot::Solid, 3, Plot::Circle);
  FSR_Plot.SetSeriesProperties("FSR A1", Plot::Blue, Plot::Solid, 3, Plot::Circle); 
}

void loop() {  
//digital input to voltage
  double sensorValue0_U = (analogRead(A0)/1024.0)*5.0;
  double sensorValue1_U = (analogRead(A1)/1024.0)*5.0;
  Message Msg;
  
  for (int i = 0; i = 10; i++){
    if ((millis() - LastSent) > SendInterval){
      LastSent = millis();
      FSR_Plot.SendData("FSR A0", sensorValue0_U);
      FSR_Plot.SendData("FSR A1", sensorValue1_U);
      loopCount = i;
      break;
    }
  }
    if (loopCount=0 && (millis() - LastSent) > SendInterval){
      LastSent = millis();
      Msg.Send("FSR A0", sensorValue0_U);
      Msg.Send("FSR A1", sensorValue1_U);
  }
}
