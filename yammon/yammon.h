/*
>>:yamsys.h  for Monroe 03-Jun-83
 *
 * global equates for specific installation and modem ports
 * Other modem specific stuff is in yam5.c
 *
 * A tidier implementation of Bills modem (on/off) stuff.
 */

/* files have single letter ext so pip yam?????.? gets all source but no crl */
#define HELPFILE "YAMHELP.T"
#define PHONES "YAMPHONE.T"
#define USQ
#define LOOPBACKNONO ""
#define CPM
#define BDSC
#define KBMASK 0xff	/* don't strip top bit  */

#define KTIME 100	/* delay for keyscans during loop & test */
#define KTIME2 300	/* delay for normal keyboard scan */
#define DIRCOLS 4	/* number of columns to display */
#define CLKMHZ 3
#define SECPBLK 16	/* 2k blocks on Micropolis 5 1/4" disk */

/* ********* following string must be in UPPER case ********* */
#define DISKS "AB"    /* legal disks for default selection */
#define MAXUSER 15	/* maximum user number */

#define MONROE
#define CTCPRT 168		/* CTC command for COM port	*/
#define FLAVOR "Yam for Monroe,"
#define VERSION "Rev 3.12 : 03-Jun-83"
#define TERMINIT "\032"		/* Clear screen			*/

#define DEFBAUD 9600	/* initial baud rate setting */
#define INITBAUD	/* must do a setbaud call    */

#define DPORT MDATA
#define SPORT MSTAT
#define DRMSK MIMASK
#define DTMSK MOMASK

char inp();				/* for fastest 8080 code */
#define MIREADY (inp(Sport)&DRMSK) /* value != 0 if char available */
#define MICHAR (inp(Dport))		/* get char assuming miready */

#define MOREADY (inp(Sport)&DTMSK)	/* modem ready to load next char */

#define MODATA(data) outp(Dport,data)	/* modem data output port */

char bios();
#define POREADY bios(15,0)

#define CIREADY bios(2)			/* console character ready	*/
#define CICHAR	bios(3)			/* get character pressed	*/

#define CONSOLOUT(c) bios(4,c)
#define COREADY (1)


/* the following is UART bank selection if needed */

/* #define CONUSER   */
/* #define MODEMUSER */

#ifdef MODEMUSER

#define UPORT				/* UART bank select port */

#endif /*MODEMUSER */

#ifdef CONUSER

#define UPORT				/* UART bank select port */

#endif /*CONUSER */

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

/* das ende ist hier */
