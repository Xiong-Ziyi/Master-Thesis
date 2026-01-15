/*
 * MATLAB Compiler: 3.0
 * Date: Tue Nov 19 14:23:55 2002
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-d"
 * "c:\Projects\MZDDE\Temp" "-m" "-W" "main" "-L" "C" "-t" "-T" "link:exe" "-h"
 * "libmmfile.mlib" "-B" "sgl" "-m" "-W" "main" "-L" "C" "-t" "-T" "link:exe"
 * "-h" "libmmfile.mlib" "-W" "mainhg" "libmwsglm.mlib" "accosin" 
 */
#include "znewlens.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[7] = { 'N', 'e', 'w', 'L', 'e', 'n', 's' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

void InitializeModule_znewlens(void) {
    _mxarray0_ = mclInitializeString(7, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
}

void TerminateModule_znewlens(void) {
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mznewlens(int nargout_);

_mexLocalFunctionTable _local_function_table_znewlens
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZnewlens" contains the normal interface for the "znewlens"
 * M-function from file "c:\projects\mzdde\znewlens.m" (lines 1-16). This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
mxArray * mlfZnewlens(void) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 0);
    Status = Mznewlens(nargout);
    mlfRestorePreviousContext(0, 0);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxZnewlens" contains the feval interface for the "znewlens"
 * M-function from file "c:\projects\mzdde\znewlens.m" (lines 1-16). The feval
 * function calls the implementation version of znewlens through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZnewlens(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: znewlens Line: 1 Column:"
            " 1 The function \"znewlens\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: znewlens Line: 1 Column:"
            " 1 The function \"znewlens\" was called with m"
            "ore than the declared number of inputs (0)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    mlfEnterNewContext(0, 0);
    mplhs[0] = Mznewlens(nlhs);
    mlfRestorePreviousContext(0, 0);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mznewlens" is the implementation version of the "znewlens"
 * M-function from file "c:\projects\mzdde\znewlens.m" (lines 1-16). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function Status = zNewLens()
 */
static mxArray * Mznewlens(int nargout_) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_znewlens);
    mxArray * Status = NULL;
    mxArray * ans = NULL;
    /*
     * % zNewLens - Erases the current lens in the ZEMAX DDE server.
     * %
     * % Usage : Status = zNewLens
     * %
     * % This function erases the current lens. The 'minimum' lens that remains is identical to the lens in the Lens Data
     * % Editor when 'File, New' is selected. No prompt to save the existing lens is given.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout 
     * Status = ddereq(ZemaxDDEChannel, 'NewLens', [1 1], ZemaxDDETimeout);
     */
    mlfAssign(
      &Status,
      mlfNDdereq(
        0,
        mclValueVarargout(),
        mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
        _mxarray0_,
        _mxarray2_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    mclValidateOutput(Status, 1, nargout_, "Status", "znewlens");
    mxDestroyArray(ans);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
    /*
     * 
     */
}
