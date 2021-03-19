/*
 * This header file contains hardware-dependent definitions for C programs.
 *
 * For APPLE with CCS 7710A card, lifted from BDSCIO.APL (ver 1.46)
 * This should work with both pre and post 1.50 programs (maybe). 
 */

/*
 * Some console (video) terminal characteristics:
 */

#define TWIDTH	80	/* # of columns	*/
#define TLENGTH	24	/* # of lines	*/
#define CLEARS	"\033*"	/* String to clear screen on console	*/
#define INTOREV	"\176\037" /* String to switch console to highlight video */
#define OUTAREV "\176\031" /* String to switch console to normal video  */
#define ESC	'\033'	/* Standard ASCII 'escape' character	*/


/*
	The following definitions provide a portable low-level interface
	for direct I/O to the  console and modem devices. The values
	used here are only for example; be certain to go in and customize
	them for your system! Note that only one of the two sections
	(I/O port vs. memory mapped) will be needed for your system,
	so feel free to edit the unused section out of the file and remove
	the conditional compilation lines around the section you end up
	using.
*/

#define CDATA		0xE000
#define CIDATA		CDATA
#define CODATA		CDATA
#define CSTAT		0xE000
#define CISTAT		CSTAT
#define COSTAT		CSTAT
#define CIMASK		0x80			/* input data available */
#define COMASK		0x80			/* output data ready */
#define CRESET		0			/* status reset after input */
#define CRESETVAL	0			/* reset value to send */
/*
#define CON_TBE		(inp(COSTAT) & COMASK)	/* Console */
#define CON_RDA		(inp(CISTAT) & CIMASK)
#define CON_TDATA(byte)	(outp(COATA, byte))
#define CON_RDATA	(inp(CIDATA))
*/

#define MDATA		0xE0A1
#define MSTAT		0xE0A0
#define MIMASK		0x01			/* input data available */
#define MOMASK		0x02			/* output data ready */
#define MRESET		0			/* status reset after input */
#define MRESETVAL	0			/* reset value to send */
/*
#define	MOD_TBE		(inp(MSTAT) & MOMASK)	/* Modem */
#define MOD_RDA		(inp(MSTAT) & MIMASK)
#define	MOD_TDATA(byte)	(outp(MDATA, byte))
#define	MOD_RDATA	(inp(MDATA))
*/
