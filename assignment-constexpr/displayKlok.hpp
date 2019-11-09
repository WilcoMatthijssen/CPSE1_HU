
#ifndef DISPLAYKLOK_HPP
#define DISPLAYKLOK_HPP

class displayKlok{
   public:
    uint8_t urenOffset=0;
   uint8_t minutenOffset=0;
      hwlib::window & display;
      modelKlok updateKlok;
      hwlib::xy midden={64,32};

  displayKlok( hwlib::window & display, const modelKlok updateKlok)
      :display(display) , 
      updateKlok(updateKlok)
      {}

  
   

   void tekenKlok(){
      hwlib::circle klok(midden, 31);
      klok.draw(display);
      for(int i=0; i<60;i+=5){
         hwlib::circle punt(updateKlok.groteWijzerArray[i], 3);
         punt.draw(display);
      }
   }

   void tekenGroteWijzer(int n){
      hwlib::line groteWijzer(midden,updateKlok.groteWijzerArray[n]);
      groteWijzer.draw(display);
   }

   void tekenKleineWijzer(int n){
      hwlib::line kleineWijzer(midden,updateKlok.kleineWijzerArray[n]);
      kleineWijzer.draw(display);
   }
   void draw(){
      display.clear();
        tekenKlok();
        tekenGroteWijzer((hwlib::now_us()/15000000+minutenOffset)%60);
        tekenKleineWijzer((hwlib::now_us()/1000000+urenOffset)%60);
        display.flush();
   }
   void tijdsAanpassing(uint8_t uren, uint8_t minuten){
        urenOffset+=uren;
        urenOffset= urenOffset %60;
        minutenOffset+=minuten;
        minutenOffset= minutenOffset%60;
    }

};
#endif