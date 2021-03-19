/*
>>:yamsys.h 03-Jun-83
 *
 * global equates for specific installation and modem ports
 * Other modem specific stuff is in yam5.c

 <<<<<<<<<<  DATAMAX  8000   HEADER    [ Zilog  SIO ]  >>>>>>>>>>

 *
 */

/* files have single letter ext so pip yam?????.? gets all source but no crl */

#define HELPFILE "YAMHELP.T"
#define PHONES "YAMPHONE.T"
#define USQ
#define CPM
#define BDSC
#define CRCK		   /* conditional for YAM89, may be removed */
/* #define LOGFILE "YAM.LOG" */  /* conditional, may be removed */

/*
#define LOGCLOCK
*/

#define USERINIT

char inp();		/* for tighter compiled code ... */

#define CLKMHZ 4	/* CPU speed in Mhz */
#define SECPBLK 16	/* standard 2k blocks on DISK-1 */
#define KTIME 200	/* delay for loop and test */
#define KTIME2 300	/* delay for normal console scan */
#define DIRCOLS	4	/* number of columns in directory display */

/* ********* following string must be in UPPER case ********* */

#define DISKS "ABCD"	/* legal disks for default selection */
#define MAXUSER 15

/* defines for DATAMAX  8000  Zilog SIO */

#define VERSION "Rev 3.12 : 03-Jun-83"
#define FLAVOR "YAM for DATAMAX 8000 SIO: Baud fixed by SET-UP"

#define ZSIO         			/* Dummy type of modem port */
/*                                      /* allows use of DIRR funtion */
#define NOBAUDINIT
*/
#define INITBAUD
#define DEFBAUD 300
#define SPORT MSTAT			/* defined in BDSCIO.H */
#define DPORT MDATA			/* ditto */
#define MPORT                           /* 2651 mode port */
#define CPORT                           /* 2651 command port */
#define MIREADY (inp(Sport)&MIMASK)	/* value != 0 if char available */
/*
#define MIREADYERROR			/* status and error bits in same reg */
#define CDMASK 0x40			/* carrier detect status bit */
*/
#define CDO FALSE                       /* value == 0 if carrier lost */
#define MIREADYMASK MIMASK		
#define MIERRORMASK 0x70 		/* errors in bits 3,4,5 */
#define MI_ERROR_RESET 0x30		/* error reset bit for command byte */
#define MICHAR (inp(Dport))		/* get char assuming miready */
#define MOREADY (inp(Sport)&MOMASK)	/* modem ready to load next char */
/*
#define MODE1 0X6E			/* 2651 mode byte 1 */
#define MODE2 0X30			/* 2651 mode byte 2, baud rate in low
					   nibble */
#define CMMDB 0X27			/* Tx & Rx enable, no break, RTS & DTR
					   high, no reset */
*/

#define BPORT  25 			/* DATAMAX Dummy Baud rate port  */
                                        /* allows use of ZSIO for DIRR funct */


/* At the present time the DATAMAX baud rate is set on the disk by the
program  SET-UP.COM and not dynamically altered in YAM.  However, by
including this define and dummy port, the DIRR function of YAM will work
at 'different' baud settings (e.g. if you go b9600 in YAM the baud rate
of the port on the DATAMAX will not change but, the DIRR function will
work to give an estimate of the transmission time at that baud rate */


#define MODATA(data)  outp(Dport,data)	/* modem data output port */

char bios();
#define POREADY bios(15,0)

#define CIREADY bios(2,0)
#define CICHAR bios(3,0)

#define COREADY TRUE

/* the following is bank selected UARTs */

/* #define CONUSER   */
/* #define MODEMUSER */

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

/* The following routine must be included to initialise the DATAMAX
SIO ports.  It must follow the include bdscio.h statement */


userinit()				/* DATAMAX SIO init routines */
{
	outp(MSTAT,1);
	outp(MSTAT,0);			/* disable interrupts in WR0 */
	outp(MSTAT,3);
	outp(MSTAT,0xc1);		/* rx 8 bits/char, rx enable */
	outp(MSTAT,4);			
	outp(MSTAT,0x46);		/* x 16 clock mode, 1 s.bit, no parity */
	outp(MSTAT,5);
	outp(MSTAT,0xe8);		/* DTR, 8 bits/char, tx enable */
}

/*  The following code is included in YAM5.C to define the ZSIO. 
    This is not used in the present version of YAMDMX as the baud
    rate is fixed on the disk by the SET-UP program.  However, by
    defining  ZSIO, the DIRR function at different baud rates can
    be used [see previous note]


#ifdef ZSIO
#define MODEMSTUFF

	char command;
	char baudcmd;

	command=0;

	switch(nbaud) {
	case    50: baudcmd=  0;break;
	case    75: baudcmd=  1;break;
	case   110: baudcmd=  2;break;
	case   134: baudcmd=  3;break;
	case   150: baudcmd=  4;break;
	case   300: baudcmd=  5;break;
	case   600: baudcmd=  6;break;
	case  1200: baudcmd=  7;break;
	case  1800: baudcmd=  8;break;
	case  2000: baudcmd=  9;break;
	case  2400: baudcmd= 10;break;
	case  3600: baudcmd= 11;break;
	case  4800: baudcmd= 12;break;
	case  7200: baudcmd= 13;break;
	case  9600: baudcmd= 14;break;
	case 19200: baudcmd= 15;break; 

	default:
		return ERROR;
	}
	outp(BPORT, baudcmd);
	Baudrate=nbaud;
	return OK;

*/

/* das ende ist hier */
