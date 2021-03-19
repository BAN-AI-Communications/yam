/*
 * This header file contains hardware-dependent definitions for C programs.
 *
 * For Morrow Micro Decision, lifted from BDSCIO.MD (ver 1.46)
 * This should work with both pre and post 1.50 programs.
 */

/*
 * Some console (video) terminal characteristics:
 */

#define TWIDTH	80	/* # of columns	*/
#define TLENGTH	24	/* # of lines	*/
#define CLEARS	"\033*"	/* String to clear screen on console	*/
#define INTOREV	"\033)"	/* String to switch console to highlight video */
#define OUTAREV "\033("	/* String to switch console OUT of highlight video */
#define CURSOROFF ""	/* String to turn cursor off	*/
#define CURSORON ""	/* String to turn cursor on	*/
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

#define CDATA		0x00
#define CIDATA		CDATA
#define CODATA		CDATA
#define CSTAT		0x01
#define CISTAT		CSTAT
#define COSTAT		CSTAT
#define CIMASK		0x02			/* input data available */
#define COMASK		0x01			/* output data ready */
#define CRESET		0			/* status reset after input */
#define CRESETVAL	0			/* reset value to send */
#define CON_TBE		(inp(COSTAT) & COMASK)	/* Console */
#define CON_RDA		(inp(CISTAT) & CIMASK)
#define CON_TDATA(byte)	(outp(COATA, byte))
#define CON_RDATA	(inp(CIDATA))

#define MDATA		0x02
#define MSTAT		0x03
#define MIMASK		0x02			/* input data available */
#define MOMASK		0x01			/* output data ready */
#define MRESET		0			/* status reset after input */
#define MRESETVAL	0			/* reset value to send */
#define	MOD_TBE		(inp(MSTAT) & MOMASK)	/* Modem */
#define MOD_RDA		(inp(MSTAT) & MIMASK)
#define	MOD_TDATA(byte)	(outp(MDATA, byte))
#define	MOD_RDATA	(inp(MDATA))

