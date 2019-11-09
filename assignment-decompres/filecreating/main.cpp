#include <iostream>
#include <fstream>

#include "compressor.hpp"
#include "decompressor.hpp"

int main( void ){	
   lz_compressor< 4096 > compressor;
 
   std::ifstream f1;
   f1.open( "wilhelmus.txt" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened";
      return -1;      
   }
   
   std::ofstream f2;
   f2.open( "compressed.txt" );
   if( ! f2.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }

   std::ofstream f3;
   f3.open( "ascizFile.asm" );
   if( ! f3.is_open()){
      std::cerr << "output file not opened";
      return -1;      
   }
   f3<<".cpu cortex-m0 \n.global application\n.text\nstring:\n	.asciz \"";
   compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f3 ]( char c ){ std::cout<<c; f3.put( c ); }
  );
   f3<<"	\" \n.align 1\napplication:\n	push {lr}\n	ldrb r0, =string\n	bl print_asciz\n	pop {pc}";
   
   f1.close();
   f2.close();
   f3.close();
}