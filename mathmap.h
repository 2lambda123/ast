#if !defined( MATHMAP_INCLUDED ) /* Include this file only once */
#define MATHMAP_INCLUDED
/*
*+
*  Name:
*     mathmap.h

*  Type:
*     C include file.

*  Purpose:
*     Define the interface to the MathMap class.

*  Invocation:
*     #include "mathmap.h"

*  Description:
*     This include file defines the interface to the MathMap class and
*     provides the type definitions, function prototypes and macros,
*     etc.  needed to use this class.
*
*     The MathMap class implements Mappings that perform permutation
*     of the order of coordinate values, possibly also accompanied by
*     changes in the number of coordinates (between input and output).
*
*     In addition to permuting the coordinate order, coordinates may
*     also be assigned constant values which are unrelated to other
*     coordinate values.  This facility is useful when the number of
*     coordinates is being increased, as it allows fixed values to be
*     assigned to the new coordinates.

*  Inheritance:
*     The MathMap class inherits from the Mapping class.

*  Attributes Over-Ridden:
*     None.

*  New Attributes Defined:
*     None.

*  Methods Over-Ridden:
*     Public:
*        None.
*
*     Protected:
*        astTransform
*           Transform a set of points.

*  New Methods Defined:
*     None.

*  Other Class Functions:
*     Public:
*        astIsAMathMap
*           Test class membership.
*        astMathMap
*           Create a MathMap.
*
*     Protected:
*        astCheckMathMap
*           Validate class membership.
*        astInitMathMap
*           Initialise a MathMap.
*        astLoadMathMap
*           Load a MathMap.

*  Macros:
*     None.

*  Type Definitions:
*     Public:
*        AstMathMap
*           MathMap object type.
*
*     Protected:
*        AstMathMapVtab
*           MathMap virtual function table type.

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
*     RFWS: R.F. Warren-Smith (Starlink)

*  History:
*     29-FEB-1996 (RFWS):
*        Original version.
*     26-SEP-1996 (RFWS):
*        Added external interface and I/O facilities.
*-
*/

/* Include files. */
/* ============== */
/* Interface definitions. */
/* ---------------------- */
#include "mapping.h"             /* Coordinate mappings (parent class) */

#if defined(astCLASS)            /* Protected */
#include "pointset.h"            /* Sets of points/coordinates */
#include "channel.h"             /* I/O channels */
#endif

/* C header files. */
/* --------------- */
#if defined(astCLASS)            /* Protected */
#include <stddef.h>
#endif

/* Type Definitions. */
/* ================= */
/* MathMap structure. */
/* ------------------ */
/* This structure contains all information that is unique to each
   object in the class (e.g. its instance variables). */
typedef struct AstMathMap {

/* Attributes inherited from the parent class. */
   AstMapping mapping;           /* Parent class structure */

/* Attributes specific to objects in this class. */
   char **fwdfun;
   char **invfun;
   int **fwdcode;
   int **invcode;
   double **fwdcon;
   double **invcon;
   int fwdstack;
   int invstack;
   int nfwd;
   int ninv;
   int simp_fi;
   int simp_if;
} AstMathMap;

/* Virtual function table. */
/* ----------------------- */
/* This table contains all information that is the same for all
   objects in the class (e.g. pointers to its virtual functions). */
#if defined(astCLASS)            /* Protected */
typedef struct AstMathMapVtab {

/* Properties (e.g. methods) inherited from the parent class. */
   AstMappingVtab mapping_vtab;  /* Parent class virtual function table */

/* Unique flag value to determine class membership. */
   int *check;                   /* Check value */

/* Properties (e.g. methods) specific to this class. */
   int (* GetSimpFI)( AstMathMap * );
   int (* GetSimpIF)( AstMathMap * );
   int (* TestSimpFI)( AstMathMap * );
   int (* TestSimpIF)( AstMathMap * );
   void (* ClearSimpFI)( AstMathMap * );
   void (* ClearSimpIF)( AstMathMap * );
   void (* SetSimpFI)( AstMathMap *, int );
   void (* SetSimpIF)( AstMathMap *, int );
} AstMathMapVtab;
#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for standard class functions. */
/* ---------------------------------------- */
astPROTO_CHECK(MathMap)          /* Check class membership */
astPROTO_ISA(MathMap)            /* Test class membership */

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
AstMathMap *astMathMap_( int, int, const char *[], const char *[],
                         const char *, ... );
#else
AstMathMap *astMathMapId_( int, int, const char *[], const char *[],
                           const char *options, ... );
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
AstMathMap *astInitMathMap_( void *, size_t, int, AstMathMapVtab *,
                             const char *, int, int,
                             const char *[], const char *[] );

/* Loader. */
AstMathMap *astLoadMathMap_( void *, size_t, int, AstMathMapVtab *,
                             const char *, AstChannel * );
#endif

/* Prototypes for member functions. */
/* -------------------------------- */
#if defined(astCLASS)            /* Protected */
int astGetSimpFI_( AstMathMap * );
int astGetSimpIF_( AstMathMap * );
int astTestSimpFI_( AstMathMap * );
int astTestSimpIF_( AstMathMap * );
void astClearSimpFI_( AstMathMap * );
void astClearSimpIF_( AstMathMap * );
void astSetSimpFI_( AstMathMap *, int );
void astSetSimpIF_( AstMathMap *, int );
#endif

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
#define astCheckMathMap(this) astINVOKE_CHECK(MathMap,this)

/* Test class membership. */
#define astIsAMathMap(this) astINVOKE_ISA(MathMap,this)

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
#define astMathMap astINVOKE(F,astMathMap_)
#else
#define astMathMap astINVOKE(F,astMathMapId_)
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
#define astInitMathMap(mem,size,init,vtab,name,nin,nout,fwd,inv) \
astINVOKE(O,astInitMathMap_(mem,size,init,vtab,name,nin,nout,fwd,inv))

/* Loader. */
#define astLoadMathMap(mem,size,init,vtab,name,channel) \
astINVOKE(O,astLoadMathMap_(mem,size,init,vtab,name,astCheckChannel(channel)))
#endif

/* Interfaces to public member functions. */
/* -------------------------------------- */
/* Here we make use of astCheckMathMap to validate MathMap pointers
   before use. This provides a contextual error report if a pointer
   to the wrong sort of Object is supplied. */
#if defined(astCLASS)            /* Protected */
#define astClearSimpFI(this) \
astINVOKE(V,astClearSimpFI_(astCheckMathMap(this)))
#define astClearSimpIF(this) \
astINVOKE(V,astClearSimpIF_(astCheckMathMap(this)))
#define astGetSimpFI(this) \
astINVOKE(V,astGetSimpFI_(astCheckMathMap(this)))
#define astGetSimpIF(this) \
astINVOKE(V,astGetSimpIF_(astCheckMathMap(this)))
#define astSetSimpFI(this,value) \
astINVOKE(V,astSetSimpFI_(astCheckMathMap(this),value))
#define astSetSimpIF(this,value) \
astINVOKE(V,astSetSimpIF_(astCheckMathMap(this),value))
#define astTestSimpFI(this) \
astINVOKE(V,astTestSimpFI_(astCheckMathMap(this)))
#define astTestSimpIF(this) \
astINVOKE(V,astTestSimpIF_(astCheckMathMap(this)))
#endif
#endif
