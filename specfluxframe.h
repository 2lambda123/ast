#if !defined( SPECFLUXFRAME_INCLUDED ) /* Include this file only once */
#define SPECFLUXFRAME_INCLUDED
/*
*+
*  Name:
*     specfluxframe.h

*  Type:
*     C include file.

*  Purpose:
*     Define the interface to the SpecFluxFrame class.

*  Invocation:
*     #include "specfluxframe.h"

*  Description:
*     This include file defines the interface to the SpecFluxFrame class
*     and provides the type definitions, function prototypes and
*     macros, etc. needed to use this class.

*  Inheritance:
*     The SpecFluxFrame class inherits from the Frame class.

*  Copyright:
*     <COPYRIGHT_STATEMENT>

*  Authors:
*     DSB: David S. Berry (Starlink)

*  History:
*     8-DEC-2004 (DSB):
*        Original version.
*-
*/

/* Include files. */
/* ============== */
/* Interface definitions. */
/* ---------------------- */
#include "object.h"              /* Base Object class */
#include "cmpframe.h"            /* Parent Frame class */

#if defined(astCLASS)            /* Protected */
#include "channel.h"             /* I/O channels */
#endif

/* C header files. */
/* --------------- */
#if defined(astCLASS)            /* Protected */
#include <stddef.h>
#endif

/* Macros. */
/* ------- */
#if defined(astCLASS)            /* Protected */
#endif

/* Type Definitions. */
/* ================= */
/* SpecFluxFrame structure. */
/* ------------------ */
/* This structure contains all information that is unique to each
   object in the class (e.g. its instance variables). */
typedef struct AstSpecFluxFrame {

/* Attributes inherited from the parent class. */
   AstCmpFrame cmpframe;         /* Parent class structure */

} AstSpecFluxFrame;

/* Virtual function table. */
/* ----------------------- */
/* This table contains all information that is the same for all
   objects in the class (e.g. pointers to its virtual functions). */
#if defined(astCLASS)            /* Protected */
typedef struct AstSpecFluxFrameVtab {

/* Properties (e.g. methods) inherited from the parent class. */
   AstCmpFrameVtab frame_vtab;   /* Parent class virtual function table */

/* Unique flag value to determine class membership. */
   int *check;                   /* Check value */

/* Properties (e.g. methods) specific to this class. */

} AstSpecFluxFrameVtab;
#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for standard class functions. */
/* ---------------------------------------- */
astPROTO_CHECK(SpecFluxFrame)         /* Check class membership */
astPROTO_ISA(SpecFluxFrame)           /* Test class membership */

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
AstSpecFluxFrame *astSpecFluxFrame_( void *, void *, const char *, ... );
#else
AstSpecFluxFrame *astSpecFluxFrameId_( void *, void *, const char *, ... );
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
AstSpecFluxFrame *astInitSpecFluxFrame_( void *, size_t, int, AstSpecFluxFrameVtab *,
                               const char *, AstSpecFrame *, AstFluxFrame * );

/* Vtab initialiser. */
void astInitSpecFluxFrameVtab_( AstSpecFluxFrameVtab *, const char * );

/* Loader. */
AstSpecFluxFrame *astLoadSpecFluxFrame_( void *, size_t, AstSpecFluxFrameVtab *,
                               const char *, AstChannel * );
#endif

/* Prototypes for member functions. */
/* -------------------------------- */

/* Function interfaces. */
/* ==================== */
/* These macros are wrap-ups for the functions defined by this class
   to make them easier to invoke (e.g. to avoid type mis-matches when
   passing pointers to objects from derived classes). */

/* Interfaces to standard class functions. */
/* --------------------------------------- */
/* Some of these functions provide validation, so we cannot use them
   to validate their own arguments. We must use a cast when passing
   object pointers (so that they can accept objects from derived
   classes). */

/* Check class membership. */
#define astCheckSpecFluxFrame(this) astINVOKE_CHECK(SpecFluxFrame,this)

/* Test class membership. */
#define astIsASpecFluxFrame(this) astINVOKE_ISA(SpecFluxFrame,this)

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
#define astSpecFluxFrame astINVOKE(F,astSpecFluxFrame_)
#else
#define astSpecFluxFrame astINVOKE(F,astSpecFluxFrameId_)
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
#define astInitSpecFluxFrame(mem,size,init,vtab,name,frame1,frame2) \
astINVOKE(O,astInitSpecFluxFrame_(mem,size,init,vtab,name,astCheckSpecFrame(frame1),astCheckFluxFrame(frame2)))

/* Vtab Initialiser. */
#define astInitSpecFluxFrameVtab(vtab,name) astINVOKE(V,astInitSpecFluxFrameVtab_(vtab,name))
/* Loader. */
#define astLoadSpecFluxFrame(mem,size,vtab,name,channel) \
astINVOKE(O,astLoadSpecFluxFrame_(mem,size,vtab,name,astCheckChannel(channel)))
#endif

/* Interfaces to public member functions. */
/* -------------------------------------- */
/* Here we make use of astCheckSpecFluxFrame to validate SpecFluxFrame pointers
   before use.  This provides a contextual error report if a pointer
   to the wrong sort of Object is supplied. */

#endif