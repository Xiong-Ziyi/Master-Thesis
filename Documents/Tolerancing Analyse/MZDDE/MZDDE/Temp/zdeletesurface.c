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
#include "zdeletesurface.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "libmmfile.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[16] = { 'D', 'e', 'l', 'e', 't', 'e', 'S', 'u',
                               'r', 'f', 'a', 'c', 'e', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

void InitializeModule_zdeletesurface(void) {
    _mxarray0_ = mclInitializeString(16, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
}

void TerminateModule_zdeletesurface(void) {
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzdeletesurface(int nargout_, mxArray * SurfaceNumber);

_mexLocalFunctionTable _local_function_table_zdeletesurface
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZdeletesurface" contains the normal interface for the
 * "zdeletesurface" M-function from file "c:\projects\mzdde\zdeletesurface.m"
 * (lines 1-15). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZdeletesurface(mxArray * SurfaceNumber) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 1, SurfaceNumber);
    Status = Mzdeletesurface(nargout, SurfaceNumber);
    mlfRestorePreviousContext(0, 1, SurfaceNumber);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxZdeletesurface" contains the feval interface for the
 * "zdeletesurface" M-function from file "c:\projects\mzdde\zdeletesurface.m"
 * (lines 1-15). The feval function calls the implementation version of
 * zdeletesurface through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZdeletesurface(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zdeletesurface Line: 1 Colum"
            "n: 1 The function \"zdeletesurface\" was called wi"
            "th more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zdeletesurface Line: 1 Colum"
            "n: 1 The function \"zdeletesurface\" was called wi"
            "th more than the declared number of inputs (1)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 1 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 1; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 1, mprhs[0]);
    mplhs[0] = Mzdeletesurface(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzdeletesurface" is the implementation version of the
 * "zdeletesurface" M-function from file "c:\projects\mzdde\zdeletesurface.m"
 * (lines 1-15). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function Status = zDeleteSurface(SurfaceNumber)
 */
static mxArray * Mzdeletesurface(int nargout_, mxArray * SurfaceNumber) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zdeletesurface);
    mxArray * Status = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&SurfaceNumber);
    /*
     * % zDeleteSurface - Delete a lens surface in the ZEMAX DDE server.
     * %
     * % Usage : Status = zDeleteSurface(SurfaceNumber)
     * % 
     * % See also zInsertSurface
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('DeleteSurface,%i',SurfaceNumber);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL, _mxarray0_, mclVa(SurfaceNumber, "SurfaceNumber"), NULL));
    /*
     * Status = str2num(ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout));
     */
    mlfAssign(
      &Status,
      mlfStr2num(
        NULL,
        mlfNDdereq(
          0,
          mclValueVarargout(),
          mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
          mclVv(DDECommand, "DDECommand"),
          _mxarray2_,
          mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
          NULL)));
    mclValidateOutput(Status, 1, nargout_, "Status", "zdeletesurface");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(SurfaceNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
}
