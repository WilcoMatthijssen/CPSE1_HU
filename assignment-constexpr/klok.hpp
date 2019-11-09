#include "hwlib.hpp"
#include <math.h>

#ifndef MODELKLOK_HPP
#define MODELKLOK_HPP


class modelKlok{
   public:
  
   hwlib::xy groteWijzerArray[60];
   hwlib::xy kleineWijzerArray[60];
 

   constexpr modelKlok() {   vulArrays();  }
   
   constexpr void vulArrays(){
      double sinCalc=0;
      double cosCalc=0;
      
      for(uint8_t i=0; i<15;i++){ 
         sinCalc=sin((i*6)*3.14/180);
         cosCalc=cos((i*6)*3.14/180);
         groteWijzerArray[i]={64-int(sinCalc*31),32+int(cosCalc*31)}; //1e
         kleineWijzerArray[i]={64-int(sinCalc*21),32+int(cosCalc*21)};
         
         groteWijzerArray[i+15]={64-int(cosCalc*31),32-int(sinCalc*31)}; //2e
         kleineWijzerArray[i+15]={64-int(cosCalc*21),32-int(sinCalc*21)};
   
         groteWijzerArray[i+30]={64+int(sinCalc*31),32-int(cosCalc*31)}; //3e
         kleineWijzerArray[i+30]={64+int(sinCalc*21),32-int(cosCalc*21)};
   
         groteWijzerArray[i+45]={64+int(cosCalc*31),32+int(sinCalc*31)}; //4e
         kleineWijzerArray[i+45]={64+int(cosCalc*21),32+int(sinCalc*21)};
      }
   }


   
};
#endif
