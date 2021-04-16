/\*

- This header file contains hardware-dependent definitions for C programs.
-
- For Morrow Micro Decision, lifted from BDSCIO.MD (ver 1.46)
- This should work with both pre and post 1.50 programs. \*/

/\*

- Some console (video) terminal characteristics: \*/

#define TWIDTH 80 /_ # of columns _/ #define TLENGTH 24 /_ # of lines _/ #define
CLEARS "\033*" /* String to clear screen on console _/ #define INTOREV "\033)"
/_ String to switch console to highlight video _/ #define OUTAREV "\033(" /_
String to switch console OUT of highlight video _/ #define CURSOROFF "" /_
String to turn cursor off _/ #define CURSORON "" /_ String to turn cursor on _/
#define ESC '\033' /_ Standard ASCII 'escape' character \*/

/_ The following definitions provide a portable low-level interface for direct
I/O to the console and modem devices. The values used here are only for example;
be certain to go in and customize them for your system! Note that only one of
the two sections (I/O port vs. memory mapped) will be needed for your system, so
feel free to edit the unused section out of the file and remove the conditional
compilation lines around the section you end up using. _/

#define CDATA 0x00 #define CIDATA CDATA #define CODATA CDATA #define CSTAT 0x01
#define CISTAT CSTAT #define COSTAT CSTAT #define CIMASK 0x02 /_ input data
available _/ #define COMASK 0x01 /_ output data ready _/ #define CRESET 0 /_
status reset after input _/ #define CRESETVAL 0 /_ reset value to send _/
#define CON*TBE (inp(COSTAT) & COMASK) /* Console \_/ #define CON_RDA
(inp(CISTAT) & CIMASK) #define CON_TDATA(byte) (outp(COATA, byte)) #define
CON_RDATA (inp(CIDATA))

#define MDATA 0x02 #define MSTAT 0x03 #define MIMASK 0x02 /_ input data
available _/ #define MOMASK 0x01 /_ output data ready _/ #define MRESET 0 /_
status reset after input _/ #define MRESETVAL 0 /_ reset value to send _/
#define MOD*TBE (inp(MSTAT) & MOMASK) /* Modem \_/ #define MOD_RDA (inp(MSTAT) &
MIMASK) #define MOD_TDATA(byte) (outp(MDATA, byte)) #define MOD_RDATA
(inp(MDATA))
