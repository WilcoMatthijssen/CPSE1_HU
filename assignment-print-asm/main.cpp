#include "hwlib.hpp"

extern "C" char toggle_case( char c){
   if(c>='a'&& c<='z'){  c-=32;}
   else if( c>='A' && c<='Z'){ c+=32; }
   return c;
}


extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );
   //while( *s != '\0'){
     // uart_put_char( *s );
    //  ++s;
  // }
   
//}

extern "C" void application(); //{
  // print_asciz( "Hello world the ANSWER is 42\n" );	
//}

int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}

/*
print_asciz:
   push { r5, lr }
   mov r5, r0
loop:
   ldrb r0, [r5]
   add r0, r0, #0
   beq done
   bl uart_put_char
   add r5, r5, #1
   b loop
done:
   pop { r5, pc } */

/* print_asciz:
	
	
	
	mov r2, #0
	
loop:
	cmp [r1], r2
	beq done
	bl uart_put_char
	add R1, R1, #1
done:
	mov pc, lr*/

   /* 
   print_asciz:
	mov r1, #0
	
loop:
	ldrb r1 [r0, #0]
	cmp r1, r2
	beq done
	bl uart_put_char
	add R0, R0, #1
done:
	mov pc, lr
   */