#include <stdio.h>      // printf(3)
#include <unistd.h>     // write(2)
#include <stdint.h>     // uint64_t
#include <inttypes.h>   // PRIx65
int main(){
    volatile char printbuf[20], temp;
    int i;
    uint64_t printme = 0xdecafbad02468aceULL;
    printbuf[0] = '0';
    printbuf[1] = 'x';
    printbuf[19] = '\0';
    printbuf[18] = '\n';
    for(i=17; i>1; i--){
        temp = printme & 0xf;    // put the least significant remaining hex digit into temp
        printme = printme >> 4;  // right-shift printme
        // The difference between 0xa (10) and 'a' (97) is 97-10=87.
        // The difference between 0x9 ( 9) and '9' (57) is 57- 9=48.
        if( temp > 9 ){
            temp += 87;
        }else{
            temp += 48;
        }
        printbuf[i] = temp;
#ifdef DEBUG_ME
        printf("i=%2d temp=%#04x printme=%#"PRIx64" printbuf[i]=%c\n", i, temp, printme, printbuf[i]);
#endif
    }
    write(1, (const void*)printbuf, 20);
    return 0;
}

# if 0

[Results of running gcc 12.2.0 with -Oz optimization]

test_Oz.o:     file format elf64-littleaarch64


Disassembly of section .text.startup:

0000000000000000 <main>:
   0:	a9bd7bfd 	stp	x29, x30, [sp, #-48]!                               Store x29 and x30 on the stack.  Restored at 94:
   4:	52800600 	mov	w0, #0x30                  	// #48                  w0 gets an ascii '0'
   8:	d29159c3 	mov	x3, #0x8ace                	// #35534               x3 gets the least significant bits of printme
   c:	910003fd 	mov	x29, sp                                             x29 gets a copy of the stack pointer
  10:	390063e0 	strb	w0, [sp, #24]                                   w0 gets put on the stack at offset #24.  Implements line 9 of the C code.
  14:	f2a048c3 	movk	x3, #0x246, lsl #16                             x3 gets 12 more bytes of printme.  x3 now equals 0x02468ace.
  18:	52800f00 	mov	w0, #0x78                  	// #120                 w0 gets an ascii 'x'
  1c:	390067e0 	strb	w0, [sp, #25]                                   w0 gets put on the stack at offset #25.  Implements line 10.
  20:	f2df75a3 	movk	x3, #0xfbad, lsl #32                            x3 gets 16 more bytes of printme.  X3 now equals 0xfbad02468ace
  24:	52800140 	mov	w0, #0xa                   	// #10                  w0 gets an ascii '\n'
  28:	910063e1 	add	x1, sp, #0x18                                       x1 gets a copy of the stack pointer with an 18 byte offset
  2c:	3900afff 	strb	wzr, [sp, #43]                                  Store a 0 at 43 bytes into the stack.  Implements line 11.
  30:	f2fbd943 	movk	x3, #0xdeca, lsl #48                            x3 gets the rest of printme.
  34:	3900abe0 	strb	w0, [sp, #42]                                   w0 gets put on the stack.  Implements line 12.
  38:	52800220 	mov	w0, #0x11                  	// #17                  w0 gets 0x11
  3c:	12000c62 	and	w2, w3, #0xf                                        w2 gets the low 4 bits of printme
  40:	39005fe2 	strb	w2, [sp, #23]                                   w2 gets stored on the stack at offset 23.  ???
  44:	d344fc63 	lsr	x3, x3, #4                                          x3 (printme) gets left-shifted by 4 (little endian)
  48:	39405fe2 	ldrb	w2, [sp, #23]                                   w2 gets reloaded from the stack ???
  4c:	12001c42 	and	w2, w2, #0xff                                       remove all but the last 8 bits from x2.  ???
  50:	7100245f 	cmp	w2, #0x9                                            compare the contents of w2 to 9
  54:	39405fe2 	ldrb	w2, [sp, #23]                                   load w2 from the stack again  ???
  58:	12001c42 	and	w2, w2, #0xff                                       strip off the all but the last 8 bits again.  ???
  5c:	54000209 	b.ls	9c <main+0x9c>  // b.plast                      if w2<=9 (verify?) then jump to main+0x9c
  60:	11015c42 	add	w2, w2, #0x57                                       add 0x57 to w2
  64:	12001c42 	and	w2, w2, #0xff                                       retain the bottom 8 bits (because the processor only understands "byte", not "ascii")
  68:	39005fe2 	strb	w2, [sp, #23]                                   store w2 on the stack (why a special case?)
  6c:	93407c04 	sxtw	x4, w0                                          x4 gets a sign-exteded copy of w0 (last seen with value 0x11)
  70:	51000400 	sub	w0, w0, #0x1                                        x0 decremented by 1
  74:	39405fe2 	ldrb	w2, [sp, #23]                                   w2 gets restored from the stack AGAIN
  78:	12001c42 	and	w2, w2, #0xff                                       w2 gets top 56 bits zeroed out AGAIN
  7c:	38246822 	strb	w2, [x1, x4]                                    ???
  80:	7100041f 	cmp	w0, #0x1
  84:	54fffdc1 	b.ne	3c <main+0x3c>  // b.any
  88:	d2800282 	mov	x2, #0x14                  	// #20
  8c:	94000000 	bl	0 <write>
  90:	52800000 	mov	w0, #0x0                   	// #0
  94:	a8c37bfd 	ldp	x29, x30, [sp], #48
  98:	d65f03c0 	ret
  9c:	1100c042 	add	w2, w2, #0x30
  a0:	17fffff1 	b	64 <main+0x64>


#endif //0
