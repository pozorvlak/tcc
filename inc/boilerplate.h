#ifndef BOILERPLATE_H
#define BOILERPLATE_H

#ifdef linux

#define ASM_BOILERPLATE_START \
"	.file	\"%s\"\n" \
"	.text\n" \
".globl main\n" \
"	.type	main, @function\n" \
"main:\n" \
"	pushl	%%ebp\n" \
"	movl	%%esp, %%ebp\n"

#define ASM_RETURN_LINE \
"	movl	$%d,	%%eax\n" \
"	popl	%%ebp\n"\
"	ret\n"

#define ASM_BOILERPLATE_END \
"	.size	main, .-main\n"\
"	.ident	\"TCC 0.0.1\"\n"\
"	.section	.note.GNU-stack,\"\",@progbits\n"\

#else /* linux */

/* Assume that our user is on the other operating system, ie OS X */

#define ASM_BOILERPLATE_START \
"       .text\n" \
".globl _main\n" \
"_main:\n" \
"LFB2:\n" \
"       pushq   %rbp\n" \
"LCFI0:\n" \
"       movq    %rsp, %rbp\n" \
"LCFI1:\n"

#define ASM_RETURN_LINE \
"       movl    $0, %eax\n" \
"       leave\n" \
"       ret\n"

#define ASM_BOILERPLATE_END \
"LFE2:\n" \
"       .section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support\n" \
"EH_frame1:\n" \
"       .set L$set$0,LECIE1-LSCIE1\n" \
"       .long L$set$0\n" \
"LSCIE1:\n" \
"       .long   0x0\n" \
"       .byte   0x1\n" \
"       .ascii "zR\0"\n" \
"       .byte   0x1\n" \
"       .byte   0x78\n" \
"       .byte   0x10\n" \
"       .byte   0x1\n" \
"       .byte   0x10\n" \
"       .byte   0xc\n" \
"       .byte   0x7\n" \
"       .byte   0x8\n" \
"       .byte   0x90\n" \
"       .byte   0x1\n" \
"       .align 3\n" \
"LECIE1:\n" \
".globl _main.eh\n" \
"_main.eh:\n" \
"LSFDE1:\n" \
"       .set L$set$1,LEFDE1-LASFDE1\n" \
"       .long L$set$1\n" \
"LASFDE1:\n" \
"       .long   LASFDE1-EH_frame1\n" \
"       .quad   LFB2-.\n" \
"       .set L$set$2,LFE2-LFB2\n" \
"       .quad L$set$2\n" \
"       .byte   0x0\n" \
"       .byte   0x4\n" \
"       .set L$set$3,LCFI0-LFB2\n" \
"       .long L$set$3\n" \
"       .byte   0xe\n" \
"       .byte   0x10\n" \
"       .byte   0x86\n" \
"       .byte   0x2\n" \
"       .byte   0x4\n" \
"       .set L$set$4,LCFI1-LCFI0\n" \
"       .long L$set$4\n" \
"       .byte   0xd\n" \
"       .byte   0x6\n" \
"       .align 3\n" \
"LEFDE1:\n" \
"       .subsections_via_symbols\n" \

#endif /* linux */

#endif /* BOILERPLATE_H */
