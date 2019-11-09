#ifndef _COUT_PLAYER_HPP
#define _COUT_PLAYER_HPP
#include "hwlib.hpp"

class cout_player: public note_player{
   public:
      void play(const note & n)override{
         hwlib::cout<<"frequency = " << n.frequency<<"\t duration = "<<n.duration<<"\n";
      }
};


# endif
