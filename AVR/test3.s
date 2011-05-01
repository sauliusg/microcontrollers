	.file	"test3.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__tmp_reg__ = 0
__zero_reg__ = 1
	.global __do_copy_data
	.global __do_clear_bss
	.stabs	"/home/saulius/src/AVR/",100,0,2,.Ltext0
	.stabs	"test3.c",100,0,2,.Ltext0
	.text
.Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t(0,1)=r(0,1);-32768;32767;",128,0,0,0
	.stabs	"char:t(0,2)=r(0,2);0;127;",128,0,0,0
	.stabs	"long int:t(0,3)=@s32;r(0,3);020000000000;017777777777;",128,0,0,0
	.stabs	"unsigned int:t(0,4)=r(0,4);0;0177777;",128,0,0,0
	.stabs	"long unsigned int:t(0,5)=@s32;r(0,5);0;037777777777;",128,0,0,0
	.stabs	"long long int:t(0,6)=@s64;r(0,6);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t(0,7)=@s64;r(0,7);0;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t(0,8)=r(0,8);-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t(0,9)=r(0,9);0;0177777;",128,0,0,0
	.stabs	"signed char:t(0,10)=@s8;r(0,10);-128;127;",128,0,0,0
	.stabs	"unsigned char:t(0,11)=@s8;r(0,11);0;255;",128,0,0,0
	.stabs	"float:t(0,12)=r(0,1);4;0;",128,0,0,0
	.stabs	"double:t(0,13)=r(0,1);4;0;",128,0,0,0
	.stabs	"long double:t(0,14)=r(0,1);4;0;",128,0,0,0
	.stabs	"void:t(0,15)=(0,15)",128,0,0,0
	.stabs	"/usr/lib/gcc/avr/4.2.2/../../../../avr/include/avr/io.h",130,0,0,0
	.stabs	"/usr/lib/gcc/avr/4.2.2/../../../../avr/include/avr/sfr_defs.h",130,0,0,0
	.stabs	"/usr/lib/gcc/avr/4.2.2/../../../../avr/include/inttypes.h",130,0,0,0
	.stabs	"/usr/lib/gcc/avr/4.2.2/../../../../avr/include/stdint.h",130,0,0,0
	.stabs	"int8_t:t(4,1)=(0,10)",128,0,121,0
	.stabs	"uint8_t:t(4,2)=(0,11)",128,0,122,0
	.stabs	"int16_t:t(4,3)=(0,1)",128,0,123,0
	.stabs	"uint16_t:t(4,4)=(0,4)",128,0,124,0
	.stabs	"int32_t:t(4,5)=(0,3)",128,0,125,0
	.stabs	"uint32_t:t(4,6)=(0,5)",128,0,126,0
	.stabs	"int64_t:t(4,7)=(0,6)",128,0,128,0
	.stabs	"uint64_t:t(4,8)=(0,7)",128,0,129,0
	.stabs	"intptr_t:t(4,9)=(4,3)",128,0,142,0
	.stabs	"uintptr_t:t(4,10)=(4,4)",128,0,147,0
	.stabs	"int_least8_t:t(4,11)=(4,1)",128,0,159,0
	.stabs	"uint_least8_t:t(4,12)=(4,2)",128,0,164,0
	.stabs	"int_least16_t:t(4,13)=(4,3)",128,0,169,0
	.stabs	"uint_least16_t:t(4,14)=(4,4)",128,0,174,0
	.stabs	"int_least32_t:t(4,15)=(4,5)",128,0,179,0
	.stabs	"uint_least32_t:t(4,16)=(4,6)",128,0,184,0
	.stabs	"int_least64_t:t(4,17)=(4,7)",128,0,192,0
	.stabs	"uint_least64_t:t(4,18)=(4,8)",128,0,199,0
	.stabs	"int_fast8_t:t(4,19)=(4,1)",128,0,213,0
	.stabs	"uint_fast8_t:t(4,20)=(4,2)",128,0,218,0
	.stabs	"int_fast16_t:t(4,21)=(4,3)",128,0,223,0
	.stabs	"uint_fast16_t:t(4,22)=(4,4)",128,0,228,0
	.stabs	"int_fast32_t:t(4,23)=(4,5)",128,0,233,0
	.stabs	"uint_fast32_t:t(4,24)=(4,6)",128,0,238,0
	.stabs	"int_fast64_t:t(4,25)=(4,7)",128,0,246,0
	.stabs	"uint_fast64_t:t(4,26)=(4,8)",128,0,253,0
	.stabs	"intmax_t:t(4,27)=(4,7)",128,0,273,0
	.stabs	"uintmax_t:t(4,28)=(4,8)",128,0,278,0
	.stabn	162,0,0,0
	.stabs	"int_farptr_t:t(3,1)=(4,5)",128,0,77,0
	.stabs	"uint_farptr_t:t(3,2)=(4,6)",128,0,81,0
	.stabn	162,0,0,0
	.stabn	162,0,0,0
	.stabn	162,0,0,0
	.stabs	"delay_ms:F(0,15)",36,0,9,delay_ms
	.stabs	"ms:p(0,9)",160,0,6,7
.global	delay_ms
	.type	delay_ms, @function
delay_ms:
	.stabd	46,0,0
	.stabn	68,0,9,.LM0-.LFBB1
.LM0:
.LFBB1:
/* prologue: frame size=8 */
	ldi r26,lo8(8)
	ldi r27,hi8(8)
	ldi r30,pm_lo8(1f)
	ldi r31,pm_hi8(1f)
	rjmp __prologue_saves__+32
1:
/* prologue end (size=5) */
	std Y+8,r25
	std Y+7,r24
	.stabn	68,0,26,.LM1-.LFBB1
.LM1:
	ldd r24,Y+7
	ldd r25,Y+8
	std Y+6,r25
	std Y+5,r24
	.stabn	68,0,27,.LM2-.LFBB1
.LM2:
	rjmp .L2
.L3:
	.stabn	68,0,28,.LM3-.LFBB1
.LM3:
	ldi r24,lo8(10000)
	ldi r25,hi8(10000)
	std Y+4,r25
	std Y+3,r24
	.stabn	68,0,29,.LM4-.LFBB1
.LM4:
	rjmp .L4
.L5:
	.stabn	68,0,30,.LM5-.LFBB1
.LM5:
	ldi r24,lo8(10)
	ldi r25,hi8(10)
	std Y+2,r25
	std Y+1,r24
	.stabn	68,0,31,.LM6-.LFBB1
.LM6:
	rjmp .L6
.L7:
	ldd r24,Y+1
	ldd r25,Y+2
	sbiw r24,1
	std Y+2,r25
	std Y+1,r24
.L6:
	ldd r24,Y+1
	ldd r25,Y+2
	sbiw r24,0
	brne .L7
	.stabn	68,0,32,.LM7-.LFBB1
.LM7:
	ldd r24,Y+3
	ldd r25,Y+4
	sbiw r24,1
	std Y+4,r25
	std Y+3,r24
.L4:
	.stabn	68,0,29,.LM8-.LFBB1
.LM8:
	ldd r24,Y+3
	ldd r25,Y+4
	sbiw r24,0
	brne .L5
	.stabn	68,0,34,.LM9-.LFBB1
.LM9:
	ldd r24,Y+5
	ldd r25,Y+6
	sbiw r24,1
	std Y+6,r25
	std Y+5,r24
.L2:
	.stabn	68,0,27,.LM10-.LFBB1
.LM10:
	ldd r24,Y+5
	ldd r25,Y+6
	sbiw r24,0
	brne .L3
/* epilogue: frame size=8 */
	ldi r30,2
	adiw r28,8
	rjmp __epilogue_restores__+32
/* epilogue end (size=3) */
/* function delay_ms size 52 (44) */
	.size	delay_ms, .-delay_ms
	.stabs	"outer:(0,9)",128,0,24,5
	.stabs	"inner:(0,9)",128,0,24,3
	.stabs	"innermost:(0,9)",128,0,24,1
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.stabs	"main:F(0,1)",36,0,40,main
.global	main
	.type	main, @function
main:
	.stabd	46,0,0
	.stabn	68,0,40,.LM11-.LFBB2
.LM11:
.LFBB2:
/* prologue: frame size=0 */
	ldi r28,lo8(__stack - 0)
	ldi r29,hi8(__stack - 0)
	out __SP_H__,r29
	out __SP_L__,r28
/* prologue end (size=4) */
	.stabn	68,0,42,.LM12-.LFBB2
.LM12:
	ldi r26,lo8(49)
	ldi r27,hi8(49)
	ldi r30,lo8(49)
	ldi r31,hi8(49)
	ld r24,Z
	ori r24,lo8(1)
	st X,r24
.L13:
	.stabn	68,0,45,.LM13-.LFBB2
.LM13:
	ldi r26,lo8(50)
	ldi r27,hi8(50)
	ldi r30,lo8(50)
	ldi r31,hi8(50)
	ld r24,Z
	andi r24,lo8(-2)
	st X,r24
	.stabn	68,0,46,.LM14-.LFBB2
.LM14:
	ldi r24,lo8(10)
	ldi r25,hi8(10)
	rcall delay_ms
	.stabn	68,0,48,.LM15-.LFBB2
.LM15:
	ldi r26,lo8(50)
	ldi r27,hi8(50)
	ldi r30,lo8(50)
	ldi r31,hi8(50)
	ld r24,Z
	ori r24,lo8(1)
	st X,r24
	.stabn	68,0,49,.LM16-.LFBB2
.LM16:
	ldi r24,lo8(10)
	ldi r25,hi8(10)
	rcall delay_ms
	.stabn	68,0,50,.LM17-.LFBB2
.LM17:
	rjmp .L13
/* epilogue: frame size=0 */
/* epilogue: noreturn */
/* epilogue end (size=0) */
/* function main size 32 (28) */
	.size	main, .-main
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
	.stabs	"",100,0,0,.Letext0
.Letext0:
/* File "test3.c": code   84 = 0x0054 (  72), prologues   9, epilogues   3 */
