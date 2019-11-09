#ifndef _FSTREAM_PLAYER_HPP
#define _FSTREAM_PLAYER_HPP
#include <iostream>
#include <fstream>  
#include "rtttl_player.hpp"

class fstream_player: public note_player{
   public:
        std::ofstream targetfile;
        fstream_player(){
            targetfile.open ("muziekje.hpp");

            targetfile<<"#ifndef _MUZIEKJE_HPP \n";
            targetfile<<"#define _MUZIEKJE_HPP \n";
            targetfile<<"#include \"melody.hpp\" \n";
            targetfile<<"class muziekje : public melody { \n";
            targetfile<<"public: \n";
            targetfile<<"void play( note_player & p ){ \n";
        }
        ~fstream_player(){
            targetfile<<"   } \n";
            targetfile<<" }; \n";
            targetfile<<" #endif \n";
            
            targetfile.close(); 
        }
      void play(const note & n)override{
         targetfile<<"\tp.play( note{ "<<n.frequency<<" , "<<n.duration<<" } ); \n";
      }
};


# endif
