.cpu cortex-m0
.text

.global print_asciz



//////////////////////////////////////
//OPDRACHT 4
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
	


		

/////////////////////////////////
print_asciz:
	push { r5, lr }
	mov r5, r0
loop:
	ldrb r0, [r5]
	add r0, r0, #0
	beq done
	
	bl toggle_case_assembly
	//bl toggle_case
	
next_char:
	bl uart_put_char
	add r5, r5, #1
   	b loop
done:
	pop { r5, pc }



