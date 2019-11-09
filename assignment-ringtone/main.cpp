#include "hwlib.hpp"
#include "note_player_gpio.hpp"
#include "muziekje.hpp"
#include "cout_player.hpp"

int main( void ){	
   
   namespace target = hwlib::target;   
   auto lsp = target::pin_out( target::pins::d7 );
   auto p = note_player_gpio( lsp );//note_copy();//note_player_gpio( lsp );
   hwlib::wait_ms( 10 );
   
   HWLIB_TRACE;
   muziekje noten;
   noten.play(p);
}

