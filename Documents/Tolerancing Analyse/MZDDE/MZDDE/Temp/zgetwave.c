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
#include "zgetwave.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[10] = { 'G', 'e', 't', 'W', 'a',
                               'v', 'e', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;
static mxArray * _mxarray4_;

static mxChar _array6_[5] = { '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray5_;

static mxChar _array8_[5] = { '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray7_;

void InitializeModule_zgetwave(void) {
    _mxarray0_ = mclInitializeString(10, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeDouble(0.0);
    _mxarray5_ = mclInitializeString(5, _array6_);
    _mxarray7_ = mclInitializeString(5, _array8_);
}

void TerminateModule_zgetwave(void) {
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzgetwave(int nargout_, mxArray * WaveNumber);

_mexLocalFunctionTable _local_function_table_zgetwave
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZgetwave" contains the normal interface for the "zgetwave"
 * M-function from file "c:\projects\mzdde\zgetwave.m" (lines 1-26). This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
mxArray * mlfZgetwave(mxArray * WaveNumber) {
    int nargout = 1;
    mxArray * WaveData = NULL;
    mlfEnterNewContext(0, 1, WaveNumber);
    WaveData = Mzgetwave(nargout, WaveNumber);
    mlfRestorePreviousContext(0, 1, WaveNumber);
    return mlfReturnValue(WaveData);
}

/*
 * The function "mlxZgetwave" contains the feval interface for the "zgetwave"
 * M-function from file "c:\projects\mzdde\zgetwave.m" (lines 1-26). The feval
 * function calls the implementation version of zgetwave through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZgetwave(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zgetwave Line: 1 Column:"
            " 1 The function \"zgetwave\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zgetwave Line: 1 Column:"
            " 1 The function \"zgetwave\" was called with m"
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
    mplhs[0] = Mzgetwave(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzgetwave" is the implementation version of the "zgetwave"
 * M-function from file "c:\projects\mzdde\zgetwave.m" (lines 1-26). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function WaveData = zGetWave(WaveNumber)
 */
static mxArray * Mzgetwave(int nargout_, mxArray * WaveNumber) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zgetwave);
    mxArray * WaveData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&WaveNumber);
    /*
     * % zGetWave - Requests data on defined wavelengths from the Zemax DDE server.
     * %
     * % zGetWave(WaveNumber)
     * % Returns a row vector for wavelength number WaveNumber. The vector contains wavelength, weight
     * % If the WaveNumber is given as 0, the data returned is a 2-element row vector containing PrimaryWave, NumberWave
     * % where PrimaryWave is the primary wavelength number and NumberWave is the number of defined wavelengths.
     * %
     * % See also zSetWave.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('GetWave,%i',WaveNumber);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(NULL, _mxarray0_, mclVa(WaveNumber, "WaveNumber"), NULL));
    /*
     * Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
     */
    mlfAssign(
      &Reply,
      mlfNDdereq(
        0,
        mclValueVarargout(),
        mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
        mclVv(DDECommand, "DDECommand"),
        _mxarray2_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    /*
     * if WaveNumber == 0
     */
    if (mclEqBool(mclVa(WaveNumber, "WaveNumber"), _mxarray4_)) {
        /*
         * [col, count, errmsg] = sscanf(Reply, '%i,%i');
         */
        mlfAssign(
          &col,
          mlfSscanf(
            &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray5_, NULL));
    /*
     * else
     */
    } else {
        /*
         * [col, count, errmsg] = sscanf(Reply, '%f,%f');
         */
        mlfAssign(
          &col,
          mlfSscanf(
            &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray7_, NULL));
    /*
     * end
     */
    }
    /*
     * WaveData = col';
     */
    mlfAssign(&WaveData, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(WaveData, 1, nargout_, "WaveData", "zgetwave");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(WaveNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return WaveData;
    /*
     * 
     * 
     */
}
