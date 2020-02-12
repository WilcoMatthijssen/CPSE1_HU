
# CPSE1_HU
Assigments for CPSE1 Hogeschool Utrecht

![READMEPICTURE jpg](https://user-images.githubusercontent.com/57558724/68526776-a5bfe280-02df-11ea-8cde-0dff02076222.jpg)




## [assignment-constexpr](https://github.com/WilcoMatthijssen/CPSE1_HU/tree/master/assignment-constexpr)
Create a clock where the positions of it's hands are calculated using [constexpr](https://en.cppreference.com/w/cpp/language/constexpr).  

```c++
constexpr double pi = 3.14159265358979323846;
constexpr double sinCalc = sin((i*6)*pi/180);
constexpr double sinCos  = cos((i*6)*pi/180);

constexpr hwlib::xy hourHand{
    midPoint.x- int(sinCalc*handLenght),
    midPoint.y+ int(cosCalc*handLenght)
};
```

## [assignment-decompres](https://github.com/WilcoMatthijssen/CPSE1_HU/tree/master/assignment-decompres)
Decompress a file compressed with a version of [LZ compression](https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch) using assembly cortex-m0.
```ARM Assembly
.text 
addToBuffer:      
    PUSH    { R5 - R7, LR }
    LDRB    R5,     =buffer     
    LDRB    R6,     =buffer+40
shiftBuffer:
    CMP     R5,     R6      
    BEQ     doneShifting
    LDRB    R7,     [ R5, #1 ]
    STRB    R7,     [ R5 ]
    ADD     R5,     #1
    B       shiftBuffer
doneShifting:
    STRB    R0,     [R5]
    POP     { R5 - R7, PC }
```


## [assignment-print-asm](https://github.com/WilcoMatthijssen/CPSE1_HU/tree/master/assignment-print-asm)
Print an .asciz string and flip upper/lowercase letters using assembly cortex-m0.
```ARM Assembly
toggle_case_assembly:
	push { lr }
	cmp R0, #'A'		
	bge uppercase
	b done_toggle	
uppercase:
	cmp R0, #'Z'		
	bgt lowercase
	add r0,  #('a'-'A')
	b done_toggle
lowercase:
	cmp R0, #'a'		
	ble done_toggle
	cmp R0, #'z'		
	bgt done_toggle
	sub r0,  #('a'-'A')
done_toggle:
	pop { pc }
```


## [assignment-ringtone](https://github.com/WilcoMatthijssen/CPSE1_HU/tree/master/assignment-ringtone)
Create a function to convert const char* in the [rtttl ringtone](http://www.picaxe.com/RTTTL-Ringtones-for-Tune-Command/) format to code which another library can execute from.
```c++
class melody { 
public: 
    virtual void play( note_player & p ){ 
        p.play( note{ 523 , 125000 } ); 
        p.play( note{ 587 , 125000 } ); 
        p.play( note{ 698 , 125000 } ); 
    } 
}; 
```

## [assignment-ringtone](https://github.com/WilcoMatthijssen/CPSE1_HU/tree/master/assignment-templates)
Create a set class that contains values with a template type.
```c++
template<typename T, int maxSize>
std::ostream & operator<<(std::ostream & out, const set<T, maxSize> & setObject){
   for(int i=0 ; i<setObject.size;i++){
      out<<setObject.setArray[i];
   }
   return out;
}

```

___
## Built with
* [HWLIB](https://github.com/wovo/hwlib) - Library used for programming on Arduino hardware
* [V2CPSE1-Examples](https://github.com/wovo/v2cpse1-examples) - Used for examples and starting points to work of from.
