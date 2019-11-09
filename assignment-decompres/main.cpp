#include "hwlib.hpp"

/*
doSomething:
	sub r1, r0, #'0'
	add r5, r5, #1
	ldrb r2, [r5]
	sub r2, r2, #'0'
	add r5, r5, #1
	
	b done
*/
extern "C"  void uart_put_char( char c ){
   hwlib::cout << c;
}



extern "C" void decompressor(); //{
  // print_asciz( "Hello world the ANSWER is 42\n" );	
//}

int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );
   //hwlib::cout<<"start";

   decompressor();
}


/*search:
    //stop hoeveel terug in r1 en hoeveel char in r2
    //lees de buffer uit en update de buffer
    ADD R5, #1
    LDRB R1, =buffer+39     //Address van begin reference
    LDRB R2, [R5]           
    SUB R2, R2, #'0'
    ADD R5, #1   
    SUB R1, R1, R2

    LDRB R2, [R5]          //hoeveel char lang
    SUB R2, #'0'
    
    



loopSearch:
    add r2, r2, #0  //ALs er geen chars meer zijn stap uit functie
	beq doneSearch

    LDRB R0, [R1]
    BL beginBuffer
    SUB R2, #1
    b loopSearch


doneSearch:
  
    b loop



  
  */
