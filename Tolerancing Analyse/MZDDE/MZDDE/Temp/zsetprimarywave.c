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
#include "zsetprimarywave.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "zgetwave.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;
static mxArray * _mxarray0_;

static mxChar _array2_[15] = { 'S', 'e', 't', 'W', 'a', 'v', 'e', ',',
                               '0', ',', '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray1_;

static double _array4_[2] = { 1.0, 1.0 };
static mxArray * _mxarray3_;

static mxChar _array6_[5] = { '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray5_;

void InitializeModule_zsetprimarywave(void) {
    _mxarray0_ = mclInitializeDouble(0.0);
    _mxarray1_ = mclInitializeString(15, _array2_);
    _mxarray3_ = mclInitializeDoubleVector(1, 2, _array4_);
    _mxarray5_ = mclInitializeString(5, _array6_);
}

void TerminateModule_zsetprimarywave(void) {
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray1_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetprimarywave(int nargout_, mxArray * PrimaryWaveNumber);

_mexLocalFunctionTable _local_function_table_zsetprimarywave
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetprimarywave" contains the normal interface for the
 * "zsetprimarywave" M-function from file "c:\projects\mzdde\zsetprimarywave.m"
 * (lines 1-22). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZsetprimarywave(mxArray * PrimaryWaveNumber) {
    int nargout = 1;
    mxArray * WaveData = NULL;
    mlfEnterNewContext(0, 1, PrimaryWaveNumber);
    WaveData = Mzsetprimarywave(nargout, PrimaryWaveNumber);
    mlfRestorePreviousContext(0, 1, PrimaryWaveNumber);
    return mlfReturnValue(WaveData);
}

/*
 * The function "mlxZsetprimarywave" contains the feval interface for the
 * "zsetprimarywave" M-function from file "c:\projects\mzdde\zsetprimarywave.m"
 * (lines 1-22). The feval function calls the implementation version of
 * zsetprimarywave through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZsetprimarywave(int nlhs,
                        mxArray * plhs[],
                        int nrhs,
                        mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetprimarywave Line: 1 Colum"
            "n: 1 The function \"zsetprimarywave\" was called wi"
            "th more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetprimarywave Line: 1 Colum"
            "n: 1 The function \"zsetprimarywave\" was called wi"
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
    mplhs[0] = Mzsetprimarywave(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetprimarywave" is the implementation version of the
 * "zsetprimarywave" M-function from file "c:\projects\mzdde\zsetprimarywave.m"
 * (lines 1-22). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function WaveData = zSetPrimaryWave(PrimaryWaveNumber)
 */
static mxArray * Mzsetprimarywave(int nargout_, mxArray * PrimaryWaveNumber) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(
          &_local_function_table_zsetprimarywave);
    mxArray * WaveData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&PrimaryWaveNumber);
    /*
     * % zSetPrimaryWave - Set the primary wavelength number in ZEMAX.
     * %
     * % Usage : WaveData = zSetPrimaryWave(PrimaryWaveNumber)
     * %
     * % Sets the primary wavelength number to PrimaryWaveNumber.
     * % The returned data is the same as for zGetWave(WaveNumber), namely a row vector containing the
     * % primary wavelength number and the number of defined wavelengths.
     * %
     * % See also zGetWave, zSetWave, zSetWaveMatrix, zGetWaveMatrix
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.0 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * WaveData = zGetWave(0);
     */
    mlfAssign(&WaveData, mlfZgetwave(_mxarray0_));
    /*
     * DDECommand = sprintf('SetWave,0,%i,%i',PrimaryWaveNumber, WaveData(2));
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray1_,
        mclVa(PrimaryWaveNumber, "PrimaryWaveNumber"),
        mclIntArrayRef1(mclVv(WaveData, "WaveData"), 2),
        NULL));
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
        _mxarray3_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    /*
     * [col, count, errmsg] = sscanf(Reply, '%f,%f');
     */
    mlfAssign(
      &col,
      mlfSscanf(
        &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray5_, NULL));
    /*
     * WaveData = col';
     */
    mlfAssign(&WaveData, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(WaveData, 1, nargout_, "WaveData", "zsetprimarywave");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(PrimaryWaveNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return WaveData;
}
