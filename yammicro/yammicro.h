/*
>>:yamsys.h 04-Jun-83
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

#define CLKMHZ 4
#define SECPBLK 16	/* standard 2k blocks on Micro D */
#define KTIME 200	/* delay for loop and test */
#define KTIME2 300	/* delay for normal console scan */
#define DIRCOLS 4	/* number of columns for directory listing */

/* ********* following string must be in UPPER case ********* */

#define DISKS "AB"	/* legal disks for default selection */
#define MAXUSER 15

/* defines for Morrow Micro Decision (8251 mk 1) */

#define FLAVOR "Software Tools, YAM for Morrow Designs Micro Decision,"
#define VERSION "Rev 3.12 : 04-Jun-83"
#define 8251		/* type of modem port */
#define NOBAUDINIT
#define DEFBAUD 300	/* initial baud rate setting */
#define SPORT MSTAT
#define DPORT MDATA
#define MIREADY (inp(Sport)&MIMASK)	/* value != 0 if char available */
#define MIREADYERROR			/* status and error bits in same reg */
#define CDO FALSE			/* dont worry about carrier detect */
#define MIREADYMASK MIMASK		
#define MIERRORMASK 0x38		/* errors in bits 3,4,5 */
#define MICHAR (inp(Dport))		/* get char assuming miready */
#define MOREADY (inp(Sport)&MOMASK)	/* modem ready to load next char */

#define MODATA(data) outp(Dport,data)	/* modem data output port */

char bios();
#define POREADY bios(15,0)

#define CIREADY (inp(CSTAT)&CIMASK)
#define CICHAR (inp(CDATA))

#define COREADY (inp(CSTAT)&COMASK)

/* the following is for bank selected UARTs */

/* #define CONUSER   */
/* #define MODEMUSER */

#ifdef MODEMUSER

#define UPORT				/* UART bank select port */
#define MODREL 6			/* user number of MODEM UART */
#define MODEMON	outp(UPORT,MODREL);	/* switch UART bank to modem UART */

#else					/* if not banked UART on modem */

#define MODEMON ;			/* just a dummy statement */ 

#endif /* MODEMUSER */

#ifdef CONUSER

#define UPORT				/* UART bank select port */
#define CONREL 0			/* user number of CONSOLE UART */
#define CONSOLON outp(UPORT,CONREL);	/* switch UART bank to console UART */

#else					/* if not banked UART on console */

#define CONSOLON ;			/*just a dummy statement */

#endif /* CONUSER */

#include "bdscio.h"

/* das ende ist hier */
