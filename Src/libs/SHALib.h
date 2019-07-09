/* SHALib.h - SHA shared library header file
 *
 * This code is in the public domain. I would appreciate bug reports and
 * enhancements.
 *
 * Duncan S Wong <swong@ieee.org>
 *
 * Sep 8, 2000 - Initial Port from NTTMCL Satomi's SHA1 implementation
 * Jan 3, 2001 - Get rid of copyright stuff, port from Steve's open
 *               source implementation
 *             - Change creator to 'WSHA'
 */

// *****
// * PROJECT:		MySharedLib (MSL)
// * FILENAME: 		MySharedLib.h
// * AUTHOR:		Jeff Ishaq 05/21/99
// * 
// * DESCRIPTION:	Shared library functionality interface definition
// *
// * COPYRIGHT:		As long as this 'copyright' is intact, this code is freely modifiable
// *				and distributable.
// *****

#ifndef __SHALIB_H__
#define __SHALIB_H__

#include "sha1.h"

// Use this for SysLibFind calls.  This is what we 'name' our dispatch table, too:
#define SHALIB_NAME	"SHALib"
#define SHALIB_CREATOR	'WSHA'								// Register this with Palm

// These are possible error types that MSL might return:
typedef enum tagSHAErrEnum
{
	SHAErrNone 			= 0,			
	SHAErrParam			= -1,
	SHAErrNoGlobals = -2

	/////
	// Your custom return codes go here...
	/////
	
} SHAErr;

// These are MSL's trap identifiers.  The PalmOS constant 'sysLibTrapCustom' is
// the first trap number we can use after open, close, sleep, and wake.
typedef enum tagSHATrapNumEnum
{
	/////
	// - Trap modification checklist -
	// 
	// If you add or remove or otherwise modify something here, be sure you've
	// also done all of the following steps!
	//
	// 0) All trap identifiers must always run sequentially; no gaps!
	// 1) Modify the SHATrapNumEnum in MySharedLib.h
	// 2) Modify the DC.W to MSL_DispatchTable() in MySharedLibDispatch.c (no gaps!)
	// 3) Modify the JMP in MSL_DispatchTable() in MySharedLibDispatch.c (no gaps!)
	// 4) ** Update NUMBER_OF_FUNCTIONS in MySharedLibDispatch.c ** (0-based)
	// 5) Add or remove an "extern MyFunc(...) SYS_TRAP(SHATrapMyFunc)" prototype somewhere
	//
	/////

	SHALibTrapSHA1Init      = sysLibTrapCustom,   // libDispatchEntry(4)
	SHALibTrapSHA1Update,
	SHALibTrapSHA1Final
} SHATrapNumEnum;


// These are the four required entry points:
extern SHAErr	SHALibOpen(UInt16 uRefNum)  SYS_TRAP (sysLibTrapOpen);
extern SHAErr	SHALibClose(UInt16 uRefNum, UInt32* dwRefCountP )  SYS_TRAP(sysLibTrapClose);
extern Err		SHALibSleep(UInt16 uRefNum)  SYS_TRAP(sysLibTrapSleep);
extern Err		SHALibWake(UInt16 uRefNum)  SYS_TRAP(sysLibTrapWake);

// Here are the actual functions we want the library to extend to callers.
extern void SHALibSHA1Init(UInt16 uRefNum, SHA1_CTX *context)  SYS_TRAP(SHALibTrapSHA1Init);
extern void SHALibSHA1Update(UInt16 uRefNum, SHA1_CTX *context, unsigned char *data, unsigned long len)  SYS_TRAP(SHALibTrapSHA1Update);
extern void SHALibSHA1Final(UInt16 uRefNum, unsigned char digest[20], SHA1_CTX *context) SYS_TRAP(SHALibTrapSHA1Final);

#endif
