
/*
>>:yamsys.h 02-Jun-83
 *
 * global equates for specific installation and modem ports
 * Other modem specific stuff is in yam5.c
 *
 */

/* files have single letter ext so pip yam?????.? gets all source but no crl */

#define HELPFILE "YAMHELP.T"
#define PHONES "YAMPHONE.T"
#define USQ
#define CPM
#define BDSC

char inp();		/* for tighter compiled code ... */

#define CLKMHZ	7
#define SECPBLK 32	/* standard 4k blocks on M20 */
#define KTIME 200	/* delay for loop and test */
#define KTIME2 300	/* delay for normal console scan */
#define DIRCOLS 4	/* number of columns for directory listing */

/* ********* following string must be in UPPER case ********* */

#define DISKS "ABCDEFG"	/* legal disks for default selection */
#define MAXUSER 15

/* defines for Godbout 2651 UART (Interfacer 3 board) */

#define FLAVOR "YAM for Godbout Interfacer 3,"
#define VERSION " Rev 3.12 : 02-Jun-83"
#define U2651				/* type of modem port */
#define NOBAUDINIT
#define SPORT MSTAT			/* defined in BDSCIO.H */
#define DPORT MDATA			/* ditto */
#define MPORT MSTAT+1			/* 2651 mode port */
#define CPORT MSTAT+2			/* 2651 command port */
#define MIREADY (inp(Sport)&MIMASK)	/* value != 0 if char available */
#define MIREADYERROR			/* status and error bits in same reg */
#define CDO FALSE			/* dont worry about carrier detect */
#define MIREADYMASK MIMASK		
#define MIERRORMASK 0x38		/* errors in bits 3,4,5 */
#define MI_ERROR_RESET 0x10		/* error reset bit in command byte */
#define MICHAR (inp(Dport))		/* get char assuming miready */
#define MOREADY (inp(Sport)&MOMASK)	/* modem ready to load next char */
#define MODE1 0X6E			/* 2651 mode byte 1 */
#define MODE2 0X30			/* 2651 mode byte 2, baud rate in low
					   nibble */
#define CMMDB 0X27			/* Tx & Rx enable, no break, RTS & DTR
					   high, no reset */

#define MODATA(data)  outp(Dport,data)	/* modem data output port */

char bios();
#define POREADY bios(15,0)

#define CIREADY (inp(CSTAT)&CIMASK)
#define CICHAR (inp(CDATA))

#define COREADY (inp(CSTAT)&COMASK)

/* the following is bank selected UARTs */

/* #define CONUSER */
#define MODEMUSER

#ifdef MODEMUSER

#define UPORT 0x17			/* UART bank select port */
#define MODREL 6			/* user number of MODEM UART */
#define MODEMON	outp(UPORT,MODREL);	/* switch UART bank to modem UART */

#else					/* if not banked UART on modem */

#define MODEMON ;			/* just a dummy statement */ 

#endif /* MODEMUSER */

#ifdef CONUSER

#define UPORT 0x17			/* UART bank select port */
#define CONREL 0			/* user number of CONSOLE UART */
#define CONSOLON outp(UPORT,CONREL);	/* switch UART bank to console UART */

#else					/* if not banked UART on console */

#define CONSOLON ;			/*just a dummy statement */

#endif /* CONUSER */

#include "bdscio.h"

/* das ende ist hier */
