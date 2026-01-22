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
#include "zpushlens.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "libmmfile.h"

extern mxArray * ZemaxDDEChannel;

static mxChar _array1_[8] = { 'P', 'u', 's', 'h', 'L', 'e', 'n', 's' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;
static mxArray * _mxarray4_;
static mxArray * _mxarray5_;
static mxArray * _mxarray6_;

void InitializeModule_zpushlens(void) {
    _mxarray0_ = mclInitializeString(8, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeDouble(1000.0);
    _mxarray5_ = mclInitializeDouble(0.0);
    _mxarray6_ = mclInitializeDouble(-998.0);
}

void TerminateModule_zpushlens(void) {
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzpushlens(int nargout_, mxArray * Timeout);

_mexLocalFunctionTable _local_function_table_zpushlens
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZpushlens" contains the normal interface for the
 * "zpushlens" M-function from file "c:\projects\mzdde\zpushlens.m" (lines
 * 1-29). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZpushlens(mxArray * Timeout) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 1, Timeout);
    Status = Mzpushlens(nargout, Timeout);
    mlfRestorePreviousContext(0, 1, Timeout);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxZpushlens" contains the feval interface for the "zpushlens"
 * M-function from file "c:\projects\mzdde\zpushlens.m" (lines 1-29). The feval
 * function calls the implementation version of zpushlens through this
 * function. This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZpushlens(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zpushlens Line: 1 Column:"
            " 1 The function \"zpushlens\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zpushlens Line: 1 Column:"
            " 1 The function \"zpushlens\" was called with m"
            "ore than the declared number of inputs (1)."),
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
    mplhs[0] = Mzpushlens(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzpushlens" is the implementation version of the "zpushlens"
 * M-function from file "c:\projects\mzdde\zpushlens.m" (lines 1-29). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function Status = zPushLens(Timeout)
 */
static mxArray * Mzpushlens(int nargout_, mxArray * Timeout) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zpushlens);
    mxArray * Status = NULL;
    mxArray * Reply = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&Timeout);
    /*
     * % zPushLens - Copy lens in the ZEMAX DDE server into the Lens Data Editor (LDE).
     * %
     * % Usage : Status = zPushLens(Timeout)
     * % zPushLens will take the lens currently loaded in the server's memory and push it into the Lens Data Editor. A
     * % dialog box will appear from the ZEMAX main window asking the user for permission to accept the lens data being
     * % pushed by the client. The client will wait Timeout seconds before returning a timeout error.
     * % If the lens data in the LDE has not been saved, an additional dialog box will appear asking
     * % if the old data should be saved first. The returned string is the same as for the zGetUpdate function; after updating the
     * % newly pushed lens file. If a value other than 0 is returned, the Update failed, if -999 is returned, the lens could not
     * % be pushed into the LDE. If -998 is returned, the function timed out.
     * %
     * % See also zGetPath, zGetRefresh, zLoadFile, and zSaveFile.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.1 $
     * 
     * global ZemaxDDEChannel
     * Reply = ddereq(ZemaxDDEChannel, 'PushLens', [1 1], Timeout * 1000);
     */
    mlfAssign(
      &Reply,
      mlfNDdereq(
        0,
        mclValueVarargout(),
        mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
        _mxarray0_,
        _mxarray2_,
        mclMtimes(mclVa(Timeout, "Timeout"), _mxarray4_),
        NULL));
    /*
     * if (Reply==0)
     */
    if (mclEqBool(mclVv(Reply, "Reply"), _mxarray5_)) {
        /*
         * Status = -998;
         */
        mlfAssign(&Status, _mxarray6_);
    /*
     * return;
     * else
     */
    } else {
        /*
         * Status = str2num(Reply);
         */
        mlfAssign(&Status, mlfStr2num(NULL, mclVv(Reply, "Reply")));
    /*
     * end
     */
    }
    mclValidateOutput(Status, 1, nargout_, "Status", "zpushlens");
    mxDestroyArray(ans);
    mxDestroyArray(Reply);
    mxDestroyArray(Timeout);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
    /*
     * 
     * 
     */
}
