#include "hwlib.hpp"
#include <math.h>

#ifndef CLOCKHANDCALCULATOR_HPP
#define CLOCKHANDCALCULATOR_HPP


class clockHandCalculator{
   public:
   hwlib::xy hourHandArray[60];     //! xy positions for the hour hand
   hwlib::xy minuteHandArray[60];   //! xy positions for the minute hand
 
   //! uses function fillArrays();
   constexpr clockHandCalculator() {   fillArrays();  }
   private:

   //! fills hourHandArray and minuteHandArray with calculations of positions
   constexpr void fillArrays(){
      double sinCalc=0;
      double cosCalc=0;
      
      for(uint8_t i=0; i<15;i++){ 
         sinCalc=sin((i*6)*3.14/180);
         cosCalc=cos((i*6)*3.14/180);
         hourHandArray[i]={64-int(sinCalc*31),32+int(cosCalc*31)}; //1st quart of clock
         minuteHandArray[i]={64-int(sinCalc*21),32+int(cosCalc*21)};
         
         hourHandArray[i+15]={64-int(cosCalc*31),32-int(sinCalc*31)}; //2nd quart of clock
         minuteHandArray[i+15]={64-int(cosCalc*21),32-int(sinCalc*21)};
   
         hourHandArray[i+30]={64+int(sinCalc*31),32-int(cosCalc*31)}; //3rd quart of clock
         minuteHandArray[i+30]={64+int(sinCalc*21),32-int(cosCalc*21)};
   
         hourHandArray[i+45]={64+int(cosCalc*31),32+int(sinCalc*31)}; //4th quart of clock
         minuteHandArray[i+45]={64+int(cosCalc*21),32+int(sinCalc*21)};
      }
   }


   
};
#endif //CLOCKHANDCALCULATOR_HPP
