.cpu cortex-m0
.global application
.text
string:
	.asciz "Hello world the ANSWER is 42\n"
	.align 1
application:
	push {lr}
	ldrb r0, =string
	bl print_asciz
	pop {pc}
