.cpu cortex-m0 
.align 2
.global decompressor

.data 
buffer:    
    .skip 40

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
   


beginRefSearch:
    PUSH    { R5 - R7 }
    LDRB    R7,     =buffer+40
    LDRB    R6,     [ R4 ]
    SUB     R6,     #'0'
    SUB     R7,     R6
    ADD     R4,     #1
    LDRB    R6,     [ R4 ]
    SUB     R6,     #'0'
    ADD     R4,     #1
loopRefSearch:
    ADD     R6,     #0
    BEQ     doneRefSearch
    LDRB    R0,     [ R7 ]
    Bl      addToBuffer
    Bl      uart_put_char
    SUB     R6,     #1
    B       loopRefSearch
doneRefSearch:
    POP     { R5 - R7 }
    B       loop

 

decompressor:
    PUSH    { R0 - R4, LR }
    LDR     R4,     =string
loop:
    LDRB    R0,     [ R4 ]
    ADD     R4,     #1
    ADD     R0,     #0 
    BEQ     done
    CMP     R0,     #'@'	
    BEQ     beginRefSearch
    Bl      uart_put_char
    Bl      addToBuffer
    B       loop
done:
	POP     { R0 - R7, PC }
