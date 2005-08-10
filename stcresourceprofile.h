#if !defined( STCRESOURCEPROFILE_INCLUDED ) /* Include this file only once */
#define STCRESOURCEPROFILE_INCLUDED
/*
*+
*  Name:
*     stcresourceprofile.h

*  Type:
*     C include file.

*  Purpose:
*     Define the interface to the StcResourceProfile class.

*  Invocation:
*     #include "stcresourceprofile.h"

*  Description:
*     This include file defines the interface to the StcResourceProfile class 
*     and provides the type definitions, function prototypes and macros,
*     etc.  needed to use this class.
*
*     The StcResourceProfile class is a sub-class of Stc used to describe 
*     the coverage of the datasets contained in some VO resource.
*
*     See http://hea-www.harvard.edu/~arots/nvometa/STC.html

*  Inheritance:
*     The StcResourceProfile class inherits from the Stc class.

*  Feature Test Macros:
*     astCLASS
*        If the astCLASS macro is undefined, only public symbols are
*        made available, otherwise protected symbols (for use in other
*        class implementations) are defined. This macro also affects
*        the reporting of error context information, which is only
*        provided for external calls to the AST library.

*  Copyright:
*     <COPYRIGHT_STATEMENT>

*  Authors:
*     DSB: David S. Berry (Starlink)

*  History:
*     26-NOV-2004 (DSB):
*        Original version.
*-
*/

/* Include files. */
/* ============== */
/* Interface definitions. */
/* ---------------------- */
#include "stc.h"                 /* Coordinate stcs (parent class) */

#if defined(astCLASS)            /* Protected */
#include "channel.h"             /* I/O channels */
#endif

/* C header files. */
/* --------------- */
#if defined(astCLASS)            /* Protected */
#include <stddef.h>
#endif

/* Type Definitions. */
/* ================= */
/* StcResourceProfile structure. */
/* ----------------------------- */
/* This structure contains all information that is unique to each object in
   the class (e.g. its instance variables). */
typedef struct AstStcResourceProfile {

/* Attributes inherited from the parent class. */
   AstStc stc;             /* Parent class structure */

} AstStcResourceProfile;

/* Virtual function table. */
/* ----------------------- */
/* This table contains all information that is the same for all
   objects in the class (e.g. pointers to its virtual functions). */
#if defined(astCLASS)            /* Protected */
typedef struct AstStcResourceProfileVtab {

/* Properties (e.g. methods) inherited from the parent class. */
   AstStcVtab stc_vtab;    /* Parent class virtual function table */

/* Unique flag value to determine class membership. */
   int *check;                   /* Check value */

/* Properties (e.g. methods) specific to this class. */
} AstStcResourceProfileVtab;
#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for standard class functions. */
/* ---------------------------------------- */
astPROTO_CHECK(StcResourceProfile)          /* Check class membership */
astPROTO_ISA(StcResourceProfile)            /* Test class membership */

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
AstStcResourceProfile *astStcResourceProfile_( void *, int, AstKeyMap **, const char *, ... );
#else
AstStcResourceProfile *astStcResourceProfileId_( void *, int, AstKeyMap **, const char *, ... );
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
AstStcResourceProfile *astInitStcResourceProfile_( void *, size_t, int, AstStcResourceProfileVtab *, const char *, AstRegion *, int, AstKeyMap ** );

/* Vtab initialiser. */
void astInitStcResourceProfileVtab_( AstStcResourceProfileVtab *, const char * );

/* Loader. */
AstStcResourceProfile *astLoadStcResourceProfile_( void *, size_t, AstStcResourceProfileVtab *,
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
#define astCheckStcResourceProfile(this) astINVOKE_CHECK(StcResourceProfile,this)

/* Test class membership. */
#define astIsAStcResourceProfile(this) astINVOKE_ISA(StcResourceProfile,this)

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
#define astStcResourceProfile astINVOKE(F,astStcResourceProfile_)
#else
#define astStcResourceProfile astINVOKE(F,astStcResourceProfileId_)
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
#define astInitStcResourceProfile(mem,size,init,vtab,name,region,ncoords,coords) \
astINVOKE(O,astInitStcResourceProfile_(mem,size,init,vtab,name,region,ncoords,coords))

/* Vtab Initialiser. */
#define astInitStcResourceProfileVtab(vtab,name) astINVOKE(V,astInitStcResourceProfileVtab_(vtab,name))
/* Loader. */
#define astLoadStcResourceProfile(mem,size,vtab,name,channel) \
astINVOKE(O,astLoadStcResourceProfile_(mem,size,vtab,name,astCheckChannel(channel)))
#endif

/* Interfaces to public member functions. */
/* -------------------------------------- */
/* Here we make use of astCheckStcResourceProfile to validate StcResourceProfile pointers
   before use.  This provides a contextual error report if a pointer
   to the wrong sort of Object is supplied. */

#if defined(astCLASS)            /* Protected */
#endif
#endif