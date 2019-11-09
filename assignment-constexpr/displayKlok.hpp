
#ifndef DISPLAYCLOCK_HPP
#define DISPLAYCLOCK_HPP

class displayclock{
   public:
    uint8_t hoursOffset=0;
   uint8_t minutesOffset=0;
      hwlib::window & display;
      clockHandCalculator updateclock;
      hwlib::xy middle={64,32};

  displayclock( hwlib::window & display, const clockHandCalculator updateclock)
      :display(display) , 
      updateclock(updateclock)
      {}

  
   void drawclock(){
      hwlib::circle clock(middle, 31);
      clock.draw(display);
      for(int i=0; i<60;i+=5){
         hwlib::circle point(updateclock.hourHandArray[i], 3);
         point.draw(display);
      }
   }

   void drawHourHand(int n){
      hwlib::line hourHand(middle,updateclock.hourHandArray[n]);
      hourHand.draw(display);
   }

   void drawMinuteHand(int n){
      hwlib::line MinuteHand(middle,updateclock.MinuteHandArray[n]);
      MinuteHand.draw(display);
   }
   void draw(){
      display.clear();
        drawclock();
        drawHourHand((hwlib::now_us()/15000000+minutesOffset)%60);
        drawMinuteHand((hwlib::now_us()/1000000+hoursOffset)%60);
        display.flush();
   }
   void timeOffset(uint8_t hours, uint8_t minutes){
        hoursOffset+=hours;
        hoursOffset= hoursOffset %60;
        minutesOffset+=minutes;
        minutesOffset= minutesOffset%60;
    }

};
#endif //DISPLAYCLOCK_HPP