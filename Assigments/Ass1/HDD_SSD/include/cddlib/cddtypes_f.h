/* generated automatically from /home/jule/proj/cddlib/cddlib/lib-src/cddtypes.h */
/* cddtypes.h: Header file for cddlib.c 
   written by Komei Fukuda, fukuda@math.ethz.ch
*/

/* cddlib.c : C-Implementation of the double description method for
   computing all vertices and extreme rays of the polyhedron 
   P= {x :  b - A x >= 0}.  
   Please read COPYING (GNU General Public Licence) and
   the manual cddlibman.tex for detail.
*/

#ifndef  _CDDTYPES_HF
#define  _CDDTYPES_HF
#endif  /* _CDDTYPES_HF */

#define ddf_COPYRIGHT   "Copyright (C) Komei Fukuda, fukuda@math.ethz.ch"
#define ddf_DDVERSION   "Version 0.94m"
#include <time.h>

#define ddf_wordlenmax    1024 
#define ddf_linelenmax    4096
#define ddf_datawidth       10
#define ddf_filenamelen    255

#define ddf_FALSE 0
#define ddf_TRUE 1

typedef int ddf_boolean;

typedef long ddf_rowrange;
typedef long ddf_colrange;
typedef long ddf_bigrange;

typedef set_type ddf_rowset;
typedef set_type ddf_colset;
typedef long *ddf_rowindex;   
typedef int *ddf_rowflag;   
typedef long *ddf_colindex;
typedef myfloat **ddf_Amatrix;
typedef myfloat *ddf_Arow;
typedef set_type *ddf_SetVector;
typedef myfloat **ddf_Bmatrix;
typedef set_type *ddf_Aincidence;

/* typedef char ddf_FilenameType[ddf_filenamelen]; deleted 000505*/
typedef char ddf_DataFileType[ddf_filenamelen];
typedef char ddf_LineType[ddf_linelenmax];
typedef char ddf_WordType[ddf_wordlenmax];

typedef struct ddf_raydata *ddf_RayPtr;

typedef struct ddf_raydata {
  myfloat *Ray;
  ddf_rowset ZeroSet;
  ddf_rowrange FirstInfeasIndex;  /* the first inequality the ray violates */
  ddf_boolean feasible;  /* flag to store the feasibility */
  myfloat ARay;   /* temporary area to store some row of A*Ray */
  ddf_RayPtr Next;
} ddf_RayType;

typedef struct ddf_adjacencydata *ddf_AdjacencyPtr;
typedef struct ddf_adjacencydata {
  ddf_RayPtr Ray1, Ray2;
  ddf_AdjacencyPtr Next;
} ddf_AdjacencyType;

typedef enum {
  ddf_Combinatorial, ddf_Algebraic
} ddf_AdjacencyTestType;

typedef enum {
  ddf_MaxIndex, ddf_MinIndex, ddf_MinCutoff, ddf_MaxCutoff, ddf_MixCutoff,
   ddf_LexMin, ddf_LexMax, ddf_RandomRow
} ddf_RowOrderType;

typedef enum {
  ddf_Unknown=0, ddf_Real, ddf_Rational, ddf_Integer
} ddf_NumberType;

typedef enum {
  ddf_Unspecified=0, ddf_Inequality, ddf_Generator
} ddf_RepresentationType;

typedef enum {
  ddf_IneToGen, ddf_GenToIne, ddf_LPMax, ddf_LPMin, ddf_InteriorFind
} ddf_ConversionType;

typedef enum {
  ddf_IncOff=0, ddf_IncCardinality, ddf_IncSet
} ddf_IncidenceOutputType;

typedef enum {
  ddf_AdjOff=0, ddf_AdjacencyList,  ddf_AdjacencyDegree
} ddf_AdjacencyOutputType;

typedef enum {
  ddf_Auto, ddf_SemiAuto, ddf_Manual
} ddf_FileInputModeType;   
   /* Auto if a input filename is specified by command arguments */

typedef enum {
  ddf_DimensionTooLarge, ddf_ImproperInputFormat, 
  ddf_NegativeMatrixSize, ddf_EmptyVrepresentation, ddf_EmptyHrepresentation, ddf_EmptyRepresentation,
  ddf_IFileNotFound, ddf_OFileNotOpen, ddf_NoLPObjective, ddf_NoRealNumberSupport,
  ddf_NotAvailForH, ddf_NotAvailForV, ddf_CannotHandleLinearity,
  ddf_RowIndexOutOfRange, ddf_ColIndexOutOfRange,
  ddf_LPCycling, ddf_NumericallyInconsistent,
  ddf_NoError
} ddf_ErrorType;

typedef enum {
  ddf_InProgress, ddf_AllFound, ddf_RegionEmpty
} ddf_CompStatusType;

/* --- LP types ---- */

typedef enum {
  ddf_LPnone=0, ddf_LPmax, ddf_LPmin
} ddf_LPObjectiveType;

typedef enum {
  ddf_CrissCross, ddf_DualSimplex
} ddf_LPSolverType;

typedef enum {
  ddf_LPSundecided, ddf_Optimal, ddf_Inconsistent, ddf_DualInconsistent,
  ddf_StrucInconsistent, ddf_StrucDualInconsistent,
  ddf_Unbounded, ddf_DualUnbounded
} ddf_LPStatusType;

typedef struct ddf_lpsolution *ddf_LPSolutionPtr;
typedef struct ddf_lpsolution {
  ddf_DataFileType filename;
  ddf_LPObjectiveType objective;
  ddf_LPSolverType solver; 
  ddf_rowrange m;
  ddf_colrange d;
  ddf_NumberType numbtype;

  ddf_LPStatusType LPS;  /* the current solution status */
  myfloat optvalue;  /* optimal value */
  ddf_Arow sol;   /* primal solution */
  ddf_Arow dsol;  /* dual solution */
  ddf_colindex nbindex;  /* current basis represented by nonbasic indices */
  ddf_rowrange re;  /* row index as a certificate in the case of inconsistency */
  ddf_colrange se;  /* col index as a certificate in the case of dual inconsistency */
  long pivots[5]; 
   /* pivots[0]=setup (to find a basis), pivots[1]=PhaseI or Criss-Cross,
      pivots[2]=Phase II, pivots[3]=Anticycling, pivots[4]=GMP postopt. */
  long total_pivots;
} ddf_LPSolutionType;


typedef struct ddf_lpdata *ddf_LPPtr;
typedef struct ddf_lpdata {
  ddf_DataFileType filename;
  ddf_LPObjectiveType objective;
  ddf_LPSolverType solver; 
  ddf_boolean Homogeneous;  
     /* The first column except for the obj row is all zeros. */
  ddf_rowrange m;
  ddf_colrange d;
  ddf_Amatrix A;
  ddf_Bmatrix B;
  ddf_rowrange objrow;
  ddf_colrange rhscol;
  ddf_NumberType numbtype;
  ddf_rowrange eqnumber;  /* the number of equalities */
  ddf_rowset equalityset;  

  ddf_boolean redcheck_extensive;  /* Apply the extensive redundancy check. */
  ddf_rowrange ired; /* the row index for the redundancy checking */
  ddf_rowset redset_extra;  /* a set of rows that are newly recognized redundan by the extensive search. */
  ddf_rowset redset_accum;  /* the accumulated set of rows that are recognized redundant */
  ddf_rowset posset_extra;  /* a set of rows that are recognized non-linearity */

  ddf_boolean lexicopivot;  /* flag to use the lexicogrphic pivot rule (symbolic perturbation). */

  ddf_LPStatusType LPS;  /* the current solution status */
  ddf_rowrange m_alloc; /* the allocated row size of matrix A */
  ddf_colrange d_alloc; /* the allocated col size of matrix A */
  myfloat optvalue;  /* optimal value */
  ddf_Arow sol;   /* primal solution */
  ddf_Arow dsol;  /* dual solution */
  ddf_colindex nbindex;  /* current basis represented by nonbasic indices */
  ddf_rowrange re;  /* row index as a certificate in the case of inconsistency */
  ddf_colrange se;  /* col index as a certificate in the case of dual inconsistency */
  long pivots[5]; 
   /* pivots[0]=setup (to find a basis), pivots[1]=PhaseI or Criss-Cross,
      pivots[2]=Phase II, pivots[3]=Anticycling, pivots[4]=GMP postopt. */
  long total_pivots;
  int use_given_basis;  /* switch to indicate the use of the given basis */
  ddf_colindex given_nbindex;  /* given basis represented by nonbasic indices */
  time_t starttime;
  time_t endtime;
} ddf_LPType;


/*----  end of LP Types ----- */


typedef struct  ddf_matrixdata *ddf_MatrixPtr;
typedef struct  ddf_matrixdata {
  ddf_rowrange rowsize;
  ddf_rowset linset; 
    /*  a subset of rows of linearity (ie, generators of
        linearity space for V-representation, and equations
        for H-representation. */
  ddf_colrange colsize;
  ddf_RepresentationType representation;
  ddf_NumberType numbtype;
  ddf_Amatrix matrix;
  ddf_LPObjectiveType objective;
  ddf_Arow rowvec;
} ddf_MatrixType;

typedef struct ddf_setfamily *ddf_SetFamilyPtr;
typedef struct ddf_setfamily {
  ddf_bigrange famsize;
  ddf_bigrange setsize;
  ddf_SetVector set;  
} ddf_SetFamilyType;


typedef struct ddf_nodedata *ddf_NodePtr;
typedef struct ddf_nodedata {ddf_bigrange key; ddf_NodePtr next;} ddf_NodeType;

typedef struct ddf_graphdata *ddf_GraphPtr;
typedef struct ddf_graphdata {
  ddf_bigrange vsize;
  ddf_NodePtr *adjlist;  /* should be initialized to have vsize components */
} ddf_GraphType;


typedef struct ddf_polyhedradata *ddf_PolyhedraPtr;
typedef struct ddf_conedata *ddf_ConePtr;

typedef struct ddf_polyhedradata {
  ddf_RepresentationType representation;  /* given representation */
  ddf_boolean homogeneous;
  ddf_colrange d;
  ddf_rowrange m;
  ddf_Amatrix A;   /* Inequality System:  m times d matrix */
  ddf_NumberType numbtype;
  ddf_ConePtr child;  /* pointing to the homogenized cone data */
  ddf_rowrange m_alloc; /* allocated row size of matrix A */
  ddf_colrange d_alloc; /* allocated col size of matrix A */
  ddf_Arow c;           /* cost vector */

  ddf_rowflag EqualityIndex;  
    /* ith component is 1 if it is equality, -1 if it is strict inequality, 0 otherwise. */

  ddf_boolean IsEmpty;  /* This is to tell whether the set is empty or not */
  
  ddf_boolean NondegAssumed;
  ddf_boolean InitBasisAtBottom;
  ddf_boolean RestrictedEnumeration;
  ddf_boolean RelaxedEnumeration;

  ddf_rowrange m1; 
    /* = m or m+1 (when representation=Inequality && !homogeneous)
       This data is written after ddf_ConeDataLoad is called.  This
       determines the size of Ainc. */
  ddf_boolean AincGenerated;
    /* Indicates whether Ainc, Ared, Adom are all computed.
       All the variables below are valid only when this is TRUE */
  ddf_colrange ldim;   /* linearity dimension */
  ddf_bigrange n; 
    /* the size of output = total number of rays 
       in the computed cone + linearity dimension */
  ddf_Aincidence Ainc;
    /* incidence of input and output */
  ddf_rowset Ared;  
    /* redundant set of rows whose removal results in a minimal system */
  ddf_rowset Adom;  
    /* dominant set of rows (those containing all rays). */

} ddf_PolyhedraType;


typedef struct ddf_conedata {
  ddf_RepresentationType representation;
  ddf_rowrange m;
  ddf_colrange d;
  ddf_Amatrix A;
  ddf_NumberType numbtype;
  ddf_PolyhedraPtr parent;  /* pointing to the original polyhedra data */
  ddf_rowrange m_alloc; /* allocated row size of matrix A */
  ddf_colrange d_alloc; /* allocated col size of matrix A */

/* CONTROL: variables to control computation */
  ddf_rowrange Iteration;
  ddf_RowOrderType HalfspaceOrder;
  ddf_RayPtr FirstRay, LastRay, ArtificialRay; /* The second description: Generator */
  ddf_RayPtr PosHead, ZeroHead, NegHead, PosLast, ZeroLast, NegLast;
  ddf_AdjacencyType **Edges;  /* adjacency relation storage for iteration k */
  unsigned int rseed;  /* random seed for random row permutation */

  ddf_boolean ColReduced;  /* flag to indicate that a column basis is computed and reduced */
  ddf_bigrange LinearityDim;   
           /*  the dimension of the linearity space (when input is H), and
               the size of a minimal system of equations to determine the space (when V). */
  ddf_colrange d_orig;  /* the size d of the original matrix A */
  ddf_colindex newcol;  /* the size d of the original matrix A */
  
  ddf_colindex InitialRayIndex;   /* InitialRayIndex[s] (s>=1) stores the corr. row index */
  ddf_rowindex OrderVector;
  ddf_boolean RecomputeRowOrder;
  ddf_boolean PreOrderedRun;
  ddf_rowset GroundSet, EqualitySet, NonequalitySet, 
       AddedHalfspaces, WeaklyAddedHalfspaces, InitialHalfspaces;
  long RayCount, FeasibleRayCount, WeaklyFeasibleRayCount,
       TotalRayCount, ZeroRayCount;
  long EdgeCount, TotalEdgeCount;
  long count_int,count_int_good,count_int_bad; /* no. of intersection operations */

  ddf_Bmatrix B;
  ddf_Bmatrix Bsave;  /* a copy of the dual basis inverse used to reduce the matrix A */

/* STATES: variables to represent current state. */
  ddf_ErrorType Error;
  ddf_CompStatusType CompStatus;  /* Computation Status */
  time_t starttime, endtime;
} ddf_ConeType;

/* Global Variables */
extern ddf_boolean ddf_debug;
extern ddf_boolean ddf_log;

/* end of cddtypes.h */
