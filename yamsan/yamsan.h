
/*
>>:yamsys.h 03-Jun-83
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

#define CLKMHZ	4
#define SECPBLK 16	/* standard 2k blocks */
#define KTIME 200	/* delay for loop and test */
#define KTIME2 300	/* delay for normal keyboard scan */
#define DIRCOLS 4	/* number of columns for directory listing */

/* ********* following string must be in UPPER case ********* */

#define DISKS "AB"	/* legal disks for default selection */
#define MAXUSER 15

/* defines for Sanyo 8251 UART */

#define FLAVOR "YAM for Sanyo MBC-1000,"
#define VERSION "Rev 3.12 : 03-Jun-83"
#define SANYO				/* type of modem port */
#define TERMINIT "\032"			/* Clear screen	      */
#define INITBAUD
#define DEFBAUD 4800			/* initial baud rate  */
#define SPORT MSTAT			/* defined in BDSCIO.H */
#define DPORT MDATA			/* ditto */
#define MIREADY (inp(Sport)&MIMASK)	/* value != 0 if char available */
#define MIREADYERROR			/* status and error bits in same reg */
#define CDO FALSE			/* dont worry about carrier detect */
#define MIREADYMASK MIMASK
#define MIERRORMASK 0x38		/* errors in bits 3,4,5 */
#define MI_ERROR_RESET 0x37		/* error reset bit in command byte */
#define MICHAR (inp(Dport))		/* get char assuming miready */
#define MOREADY (inp(Sport)&MOMASK)	/* modem ready to load next char */

#define MODATA(data) (outp(Dport,data)) /* modem data output port */

char bios();
#define POREADY bios(15,0)

#define CIREADY (inp(CSTAT)&CIMASK)
#define CICHAR bios(3,0)		/* the alternative is too complex to
					   even think about at this stage   */
#define COREADY (TRUE)

/* the following is bank selected UARTs */

/* #define CONUSER	/* No banked UARTS */
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

/* das ende ist hier */
