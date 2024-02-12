#include<strain_guage.h>
ADS1220_WE ads = ADS1220_WE(ADS1220_CS_PIN, ADS1220_DRDY_PIN);
double read_strain_guage()
{

 return ads.getRawData();

}
void initialize_strian_guage()
{
Serial.println("scale_initialize");
  if(!ads.init()){
    Serial.println("ADS1220 is not connected!");
    while(1);
  }
  ads.setDataRate(ADS1220_DR_LVL_6);
  ads.setOperatingMode( ADS1220_TURBO_MODE);
     ads.setAvddAvssAsVrefAndCalibrate();
 ads.setCompareChannels(ADS1220_MUX_0_1); 
}