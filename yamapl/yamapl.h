/*
>>:yamsys.h 15-07-83
 */

#define HELPFILE "YAMHELP.T"
#define PHONES "YAMPHONE.T"
#define USQ
#define CPM
#define BDSC

char inp();		/* for tighter compiled code ... */

#define CLKMHZ 2
#define SECPBLK 8	/* standard 2k blocks on Disk-1 */

#define DIRCOLS 4	/* number of columns is directory display */

/* ********* following string must be in UPPER case ********* */

#define DISKS "AB"	/* legal disks for default selection */
#define MAXUSER 15
#define KTIME	100	/* delay for lopp and test */
#define KTIME2	300	/* delay for normal keyboard scan */	

/* defines for Apple/CCS 7710 */

#define VERSION "Rev 3.12 : 15-Jul-83"
#define FLAVOR "YAM for Apple 2 + CCS 7710,"
#define NOBAUDINIT
#define TERMINIT CLEARS /* clear the screen	     */
#define DEFBAUD 300	/* initial baud rate setting */
#define IOTYPE unsigned /* cause is memory mapped    */
#define SPORT MSTAT
#define DPORT MDATA
#define MIREADY (peek(Sport)&MIMASK )	/* value != 0 if char available */
#define CDO FALSE			/* dont worry about carrier detect */
#define MICHAR (peek(Dport))		/* get char assuming miready */
#define MOREADY (peek(Sport)&MOMASK)	/* modem ready to load next char */
#define UPORT USERPORT			/* set in bdscio.h */

#define MODATA(data) (poke(Dport,data)) /* modem data output port */

char bios();
#define POREADY bios(15,0)


#define CIREADY bios(2,0)
#define CICHAR bios(3,0)

#define COREADY TRUE

/* the following is bank selected UARTs */

/*  #define CONUSER
    #define MODEMUSER

*/

#ifdef MODEMUSER or CONUSER

#define UPORT 0x17			/* UART bank select port */

#endif /*MODEMUSER or CONUSER */

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

#include "bdscio.h"

#undef CDATA
#undef CODATA
#undef CIDATA

userinit()

{
	poke(MSTAT,3);
	poke(MSTAT,0x11);
}


/* das ende ist hier */
