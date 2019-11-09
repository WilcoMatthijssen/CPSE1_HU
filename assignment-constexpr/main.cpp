#include "klok.hpp"
#include "displayKlok.hpp"

int main( void ){	 
    namespace target = hwlib::target;
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );
   auto sw0= target::pin_in(target::pins::d40);
   auto sw1= target::pin_in(target::pins::d38);

   constexpr modelKlok klokje;
   displayKlok drawK(display, klokje);
   
   while(true){
      drawK.draw();
      if(!sw0.read()){ drawK.tijdsAanpassing(4,0); }
      if(!sw1.read()){ drawK.tijdsAanpassing(0,4);}
   }
}
