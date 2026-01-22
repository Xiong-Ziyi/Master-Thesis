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
#include "zddeinit.h"
#include "ddeinit_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[5] = { 'z', 'e', 'm', 'a', 'x' };
static mxArray * _mxarray0_;
static mxArray * _mxarray2_;
static mxArray * _mxarray3_;
static mxArray * _mxarray4_;
static mxArray * _mxarray5_;

void InitializeModule_zddeinit(void) {
    _mxarray0_ = mclInitializeString(5, _array1_);
    _mxarray2_ = mclInitializeCharVector(0, 0, (mxChar *)NULL);
    _mxarray3_ = mclInitializeDouble(0.0);
    _mxarray4_ = mclInitializeDouble(-1.0);
    _mxarray5_ = mclInitializeDouble(3000.0);
}

void TerminateModule_zddeinit(void) {
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzddeinit(int nargout_);

_mexLocalFunctionTable _local_function_table_zddeinit
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZddeinit" contains the normal interface for the "zddeinit"
 * M-function from file "c:\projects\mzdde\zddeinit.m" (lines 1-23). This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
mxArray * mlfZddeinit(void) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 0);
    Status = Mzddeinit(nargout);
    mlfRestorePreviousContext(0, 0);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxZddeinit" contains the feval interface for the "zddeinit"
 * M-function from file "c:\projects\mzdde\zddeinit.m" (lines 1-23). The feval
 * function calls the implementation version of zddeinit through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZddeinit(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zddeinit Line: 1 Column:"
            " 1 The function \"zddeinit\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zddeinit Line: 1 Column:"
            " 1 The function \"zddeinit\" was called with m"
            "ore than the declared number of inputs (0)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    mlfEnterNewContext(0, 0);
    mplhs[0] = Mzddeinit(nlhs);
    mlfRestorePreviousContext(0, 0);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzddeinit" is the implementation version of the "zddeinit"
 * M-function from file "c:\projects\mzdde\zddeinit.m" (lines 1-23). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function Status = zDDEInit()
 */
static mxArray * Mzddeinit(int nargout_) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zddeinit);
    mxArray * Status = NULL;
    mxArray * ans = NULL;
    /*
     * % zDDEInit - Establish DDE link with the Zemax server.
     * %
     * % Usage : Status = zDDEInit
     * %
     * % Returns 0 if a DDE channel to ZEMAX was opened successfully. If not, -1
     * % is returned. If ZEMAX is not running, -1 will be returned.
     * % This function also sets the timeout value for all ZEMAX DDE calls to 3 seconds.
     * %
     * % See also zDDEClose, zDDEStart, zSetTimeout
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * ZemaxDDEChannel = ddeinit('zemax', '');
     */
    mlfAssign(
      mclPrepareGlobal(&ZemaxDDEChannel),
      mlfNDdeinit(0, mclValueVarargout(), _mxarray0_, _mxarray2_, NULL));
    /*
     * if (ZemaxDDEChannel)
     */
    if (mlfTobool(mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"))) {
        /*
         * Status = 0;
         */
        mlfAssign(&Status, _mxarray3_);
    /*
     * else
     */
    } else {
        /*
         * Status = -1;
         */
        mlfAssign(&Status, _mxarray4_);
    /*
     * end
     */
    }
    /*
     * ZemaxDDETimeout = 3000; % The default timeout.
     */
    mlfAssign(mclPrepareGlobal(&ZemaxDDETimeout), _mxarray5_);
    mclValidateOutput(Status, 1, nargout_, "Status", "zddeinit");
    mxDestroyArray(ans);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
}
