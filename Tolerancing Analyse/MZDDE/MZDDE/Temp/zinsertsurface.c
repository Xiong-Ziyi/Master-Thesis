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
#include "zinsertsurface.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[16] = { 'I', 'n', 's', 'e', 'r', 't', 'S', 'u',
                               'r', 'f', 'a', 'c', 'e', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

void InitializeModule_zinsertsurface(void) {
    _mxarray0_ = mclInitializeString(16, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
}

void TerminateModule_zinsertsurface(void) {
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzinsertsurface(int nargout_, mxArray * SurfaceNumber);

_mexLocalFunctionTable _local_function_table_zinsertsurface
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZinsertsurface" contains the normal interface for the
 * "zinsertsurface" M-function from file "c:\projects\mzdde\zinsertsurface.m"
 * (lines 1-18). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZinsertsurface(mxArray * SurfaceNumber) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 1, SurfaceNumber);
    Status = Mzinsertsurface(nargout, SurfaceNumber);
    mlfRestorePreviousContext(0, 1, SurfaceNumber);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxZinsertsurface" contains the feval interface for the
 * "zinsertsurface" M-function from file "c:\projects\mzdde\zinsertsurface.m"
 * (lines 1-18). The feval function calls the implementation version of
 * zinsertsurface through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZinsertsurface(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zinsertsurface Line: 1 Colum"
            "n: 1 The function \"zinsertsurface\" was called wi"
            "th more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zinsertsurface Line: 1 Colum"
            "n: 1 The function \"zinsertsurface\" was called wi"
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
    mplhs[0] = Mzinsertsurface(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzinsertsurface" is the implementation version of the
 * "zinsertsurface" M-function from file "c:\projects\mzdde\zinsertsurface.m"
 * (lines 1-18). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function Status = zInsertSurface(SurfaceNumber)
 */
static mxArray * Mzinsertsurface(int nargout_, mxArray * SurfaceNumber) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zinsertsurface);
    mxArray * Status = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&SurfaceNumber);
    /*
     * % zInsertSurface - Insert a lens surface in the ZEMAX DDE server.
     * %
     * % Usage : Status = zInsertSurface(SurfaceNumber)
     * % The new surface will be placed at the location indicated by the parameter surf. See also zSetSurface to define
     * % data for the new surface.
     * %
     * % See also zDeleteSurface
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('InsertSurface,%i',SurfaceNumber);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL, _mxarray0_, mclVa(SurfaceNumber, "SurfaceNumber"), NULL));
    /*
     * Status = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
     */
    mlfAssign(
      &Status,
      mlfNDdereq(
        0,
        mclValueVarargout(),
        mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
        mclVv(DDECommand, "DDECommand"),
        _mxarray2_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    mclValidateOutput(Status, 1, nargout_, "Status", "zinsertsurface");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(SurfaceNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
    /*
     * 
     */
}
