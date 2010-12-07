#if !defined( FITSTABLE_INCLUDED )  /* Include this file only once */
#define FITSTABLE_INCLUDED
/*
*+
*  Name:
*     fitstable.h

*  Type:
*     C include file.

*  Purpose:
*     Define the interface to the FitsTable class.

*  Invocation:
*     #include "fitstable.h"

*  Description:
*     This include file defines the interface to the FitsTable class and
*     provides the type definitions, function prototypes and macros,
*     etc. needed to use this class.

*  Inheritance:
*     The FitsTable class inherits from the Table class.

*  Copyright:
*     Copyright (C) 2010 Science & Technology Facilities Council.
*     All Rights Reserved.

*  Licence:
*     This program is free software; you can redistribute it and/or
*     modify it under the terms of the GNU General Public Licence as
*     published by the Free Software Foundation; either version 2 of
*     the Licence, or (at your option) any later version.
*
*     This program is distributed in the hope that it will be
*     useful,but WITHOUT ANY WARRANTY; without even the implied
*     warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
*     PURPOSE. See the GNU General Public Licence for more details.
*
*     You should have received a copy of the GNU General Public Licence
*     along with this program; if not, write to the Free Software
*     Foundation, Inc., 59 Temple Place,Suite 330, Boston, MA
*     02111-1307, USA

*  Authors:
*     DSB: David S. Berry (Starlink)

*  History:
*     25-NOV-2010 (DSB):
*        Original version.
*-
*/

/* Include files. */
/* ============== */
/* Interface definitions. */
/* ---------------------- */
#include "table.h"               /* Parent class */
#include "fitschan.h"

#if defined(astCLASS)            /* Protected */
#include "channel.h"             /* I/O channels */
#endif

/* C header files. */
/* --------------- */
#if defined(astCLASS)            /* Protected */
#include <stddef.h>
#endif

/* Macros */
/* ====== */

/* Define a dummy __attribute__ macro for use on non-GNU compilers. */
#ifndef __GNUC__
#  define  __attribute__(x)  /*NOTHING*/
#endif

/* Type Definitions. */
/* ================= */
/* FitsTable structure. */
/* ----------------- */
/* This structure contains all information that is unique to each
   object in the class (e.g. its instance variables). */
typedef struct AstFitsTable {

/* Attributes inherited from the parent class. */
   AstTable table;              /* Parent class structure */

/* Attributes specific to objects in this class. */
   AstFitsChan *header;         /* FitsChan containing table headers */
} AstFitsTable;

/* Virtual function table. */
/* ----------------------- */
/* This table contains all information that is the same for all
   objects in the class (e.g. pointers to its virtual functions). */
#if defined(astCLASS)            /* Protected */
typedef struct AstFitsTableVtab {

/* Properties (e.g. methods) inherited from the parent class. */
   AstTableVtab table_vtab;  /* Parent class virtual function table */

/* A Unique identifier to determine class membership. */
   AstClassIdentifier id;

/* Properties (e.g. methods) specific to this class. */
   AstFitsChan *(* GetTableHeader)( AstFitsTable *, int * );
   void (* PutTableHeader)( AstFitsTable *, AstFitsChan *, int * );
   int (* ColumnNull)( AstFitsTable *, const char *, int, int, int *, int *, int * );
   size_t (* ColumnSize)( AstFitsTable *, const char *, int * );
   void (* GetColumnData)( AstFitsTable *, const char *, float, double, size_t, void *, size_t *, int * );

} AstFitsTableVtab;

#if defined(THREAD_SAFE)

/* Define a structure holding all data items that are global within the
   object.c file. */

typedef struct AstFitsTableGlobals {
   AstFitsTableVtab Class_Vtab;
   int Class_Init;
} AstFitsTableGlobals;


/* Thread-safe initialiser for all global data used by this module. */
void astInitFitsTableGlobals_( AstFitsTableGlobals * );

#endif


#endif

/* Function prototypes. */
/* ==================== */
/* Prototypes for standard class functions. */
/* ---------------------------------------- */
astPROTO_CHECK(FitsTable)           /* Check class membership */
astPROTO_ISA(FitsTable)             /* Test class membership */

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
AstFitsTable *astFitsTable_( const char *, int *, ...);
#else
AstFitsTable *astFitsTableId_( const char *, ... )__attribute__((format(printf,1,2)));
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
AstFitsTable *astInitFitsTable_( void *, size_t, int, AstFitsTableVtab *,
                                 const char *, int * );

/* Vtab initialiser. */
void astInitFitsTableVtab_( AstFitsTableVtab *, const char *, int * );

/* Loader. */
AstFitsTable *astLoadFitsTable_( void *, size_t, AstFitsTableVtab *,
                                 const char *, AstChannel *, int * );
#endif

/* Prototypes for member functions. */
/* -------------------------------- */
AstFitsChan *astGetTableHeader_( AstFitsTable *, int * );
void astPutTableHeader_( AstFitsTable *, AstFitsChan *, int * );
int astColumnNull_( AstFitsTable *, const char *, int, int, int *, int *, int * );
size_t astColumnSize_( AstFitsTable *, const char *, int * );
void astGetColumnData_( AstFitsTable *, const char *, float, double, size_t, void *, size_t *, int * );

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
#define astCheckFitsTable(this) astINVOKE_CHECK(FitsTable,this,0)
#define astVerifyFitsTable(this) astINVOKE_CHECK(FitsTable,this,1)

/* Test class membership. */
#define astIsAFitsTable(this) astINVOKE_ISA(FitsTable,this)

/* Constructor. */
#if defined(astCLASS)            /* Protected. */
#define astFitsTable astINVOKE(F,astFitsTable_)
#else
#define astFitsTable astINVOKE(F,astFitsTableId_)
#endif

#if defined(astCLASS)            /* Protected */

/* Initialiser. */
#define astInitFitsTable(mem,size,init,vtab,name) \
astINVOKE(O,astInitFitsTable_(mem,size,init,vtab,name,STATUS_PTR))

/* Vtab Initialiser. */
#define astInitFitsTableVtab(vtab,name) astINVOKE(V,astInitFitsTableVtab_(vtab,name,STATUS_PTR))
/* Loader. */
#define astLoadFitsTable(mem,size,vtab,name,channel) \
astINVOKE(O,astLoadFitsTable_(mem,size,vtab,name,astCheckChannel(channel),STATUS_PTR))
#endif

/* Interfaces to public member functions. */
/* -------------------------------------- */
/* Here we make use of astCheckFitsTable to validate FitsTable pointers
   before use.  This provides a contextual error report if a pointer
   to the wrong sort of Object is supplied. */

#define astGetTableHeader(this) \
astINVOKE(O,astGetTableHeader_(astCheckFitsTable(this),STATUS_PTR))
#define astPutTableHeader(this,header) \
astINVOKE(V,astPutTableHeader_(astCheckFitsTable(this),astCheckFitsChan(header),STATUS_PTR))
#define astColumnNull(this,column,set,newval,wasset,hasnull) \
astINVOKE(V,astColumnNull_(astCheckFitsTable(this),column,set,newval,wasset,hasnull,STATUS_PTR))
#define astColumnSize(this,column) \
astINVOKE(V,astColumnSize_(astCheckFitsTable(this),column,STATUS_PTR))
#define astGetColumnData(this,column,fnull,dnull,mxsize,coldata,size) \
astINVOKE(V,astGetColumnData_(astCheckFitsTable(this),column,fnull,dnull,mxsize,coldata,size,STATUS_PTR))

#if defined(astCLASS)            /* Protected */
#endif

#endif