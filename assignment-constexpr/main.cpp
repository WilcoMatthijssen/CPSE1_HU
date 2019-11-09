#include "clock.hpp"
#include "displayclock.hpp"

int main( void ){	 
    namespace target = hwlib::target;
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );
   auto sw0= target::pin_in(target::pins::d40);
   auto sw1= target::pin_in(target::pins::d38);

   constexpr clockHandCalculator clock;
   displayclock drawKC(display, clock);
   
   while(true){
      drawC.draw();
      if(   !sw0.read() ){ drawC.timeOffset(4,0);   }
      if(   !sw1.read() ){ drawC.timeOffset(0,4);   }
   }
}
