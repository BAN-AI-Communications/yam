/*
>>:yamsys.h 01/Jun/83 for SORCERER
 *
 * global equates for specific installation and modem ports
 * Other modem specific stuff is in yam5.c
 *
 */

/* files have single letter ext so pip yam?????.? gets all source but no crl */

/* #define XMODEM	*/
/* #define RESTRICTED	*/
#define USQ

#define HELPFILE "YAMHELP.T"
#define PHONES	 "YAMPHONE.T"
/* #define LOGFILE "A:XYAM.LOG" */
/* #define BYEPROG "A:BYE"	*/
#define CPM
#define BDSC
#define KTIME 10	/* scans of moment() during test & loop */
#define KTIME2 300	/* delay for normal keyboard scan */
#define DIRCOLS 3	/* only 64 char screen	    */


#define CLKMHZ 2
#define SECPBLK 16	/* 2k blocks on Micropolis 5 1/4" disk */

/* ********* following string must be in UPPER case ********* */
#define DISKS "ABCD"	/* legal disks for default selection */
#define MAXUSER 15	/* maximum user number */

/* defines for Sorcerer */
#define STATLINE	   /* do special status line information */
#define SORCERER			   /* terminal type */

#define FLAVOR "YAm for Sorcerer,"
#define VERSION "Rev 3.12 : 01-Jun-83"
#define DEFBAUD 300	/* initial baudrate setting */
#define INITBAUD	/* do a setbaud first	    */

#define DPORT MDATA
#define SPORT MSTAT

char inp();				/* for fastest 8080 code */
#define MIREADY (inp(Sport)&Simask)	/* value != 0 if char available */
#define CDO FALSE		/* don't bother with carrier detect */
#define MICHAR (inp(Dport))		/* get char assuming miready */

#define MIREADYERROR			/* use errors detect on ports */
#define MIREADYMASK Simask		/* Receive ready    */
#define MIERRORMASK Semask		/* Receive error    */

#define MOREADY (inp(Sport)&Somask)	/* modem ready to load next char */


#define MODATA(data) (outp(Dport,data)) /* modem data output port */

char bios();
#define POREADY bios(15,0)

#define CIREADY (bios(2,0))
#define CICHAR (bios(3,0))

#define COREADY (1)
#define CONSOLOUT(c) (bios(4,c))

/* the following is UART bank selection if needed */

/* #define CONUSER   */
/* #define MODEMUSER */


#ifdef MODEMUSER

#define UPORT  xx			/* UART bank select port */

#endif /* MODEMUSER */

#ifdef CONUSER

#define UPORT  xx			/* UART bank select port */

#endif /* CONUSER */
       /* DONE THIS WAY CAUSE I CAN'T DO IT WITH AN OR */



#ifdef MODEMUSER

#define MODREL 6			/* user number of MODEM UART */
#define MODEMON outp(UPORT,MODREL);	/* switch UART bank to modem UART */

#else					/* if not banked UART on modem */

#define MODEMON ;			/* just a dummy statement */ 

#endif /* MODEMUSER */

#ifdef CONUSER

#define CONREL 0			/* user number of CONSOLE UART */
#define CONSOLON outp(UPORT,CONREL);	/* switch UART bank to console UART */

#else					/* if not banked UART on console */

#define CONSOLON ;			/*just a dummy statement */

#endif /* CONUSER */



/*  I'm using the IO byte to steer console type data to real
    console, or to modem */

#define MODEMON (*Iobyte = Ioval);  /* Restore to original */

#define CONSOLON (*Iobyte = (Ioval & 0xfc) | 0x01);
				    /* Steer console stuff to CRT device */




/* System dependent globals out of YAM.H */


#ifdef SORCERER
char *mwacol,statpos;
int *mwalin;
char bitrate;
char Simask,Somask;	/* data ready, tx ready		    */
char Semask;		/* rx error mask		    */
#endif /*SORCERER */

#define USERINIT

char *Iobyte,Ioval;	/* used to save and modify CP/M iobyte */

userinit()

{
    Iobyte = 3;		/* read value of iobyte */
    Ioval  = *Iobyte;
}


/* STDIO file included here to simplify cross-compiles of cyams */

#include "bdscio.h"

/* end of yamsys.h  */
