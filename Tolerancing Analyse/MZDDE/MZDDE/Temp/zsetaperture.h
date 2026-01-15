/*
 * MATLAB Compiler: 3.0
 * Date: Tue Nov 19 14:23:56 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-d"
 * "c:\Projects\MZDDE\Temp" "-m" "-W" "main" "-L" "C" "-t" "-T" "link:exe" "-h"
 * "libmmfile.mlib" "-B" "sgl" "-m" "-W" "main" "-L" "C" "-t" "-T" "link:exe"
 * "-h" "libmmfile.mlib" "-W" "mainhg" "libmwsglm.mlib" "accosin" 
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __zsetaperture_h
#define __zsetaperture_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_zsetaperture(void);
extern void TerminateModule_zsetaperture(void);
extern _mexLocalFunctionTable _local_function_table_zsetaperture;

extern mxArray * mlfZsetaperture(mxArray * SurfaceNumber,
                                 mxArray * Type,
                                 mxArray * Min,
                                 mxArray * Max,
                                 mxArray * xDecenter,
                                 mxArray * yDecenter,
                                 mxArray * ApertureFile);
extern void mlxZsetaperture(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
