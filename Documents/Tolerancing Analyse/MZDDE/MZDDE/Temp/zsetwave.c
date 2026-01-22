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
#include "zsetwave.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;
static mxArray * _mxarray0_;

static mxChar _array2_[15] = { 'S', 'e', 't', 'W', 'a', 'v', 'e', ',',
                               '0', ',', '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray1_;

static mxChar _array4_[24] = { 'S', 'e', 't', 'W', 'a', 'v', 'e', ',',
                               '%', 'i', ',', '%', '1', '1', '.', '9',
                               'f', ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray3_;

static double _array6_[2] = { 1.0, 1.0 };
static mxArray * _mxarray5_;

static mxChar _array8_[5] = { '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray7_;

static mxChar _array10_[5] = { '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray9_;

void InitializeModule_zsetwave(void) {
    _mxarray0_ = mclInitializeDouble(0.0);
    _mxarray1_ = mclInitializeString(15, _array2_);
    _mxarray3_ = mclInitializeString(24, _array4_);
    _mxarray5_ = mclInitializeDoubleVector(1, 2, _array6_);
    _mxarray7_ = mclInitializeString(5, _array8_);
    _mxarray9_ = mclInitializeString(5, _array10_);
}

void TerminateModule_zsetwave(void) {
    mxDestroyArray(_mxarray9_);
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray1_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetwave(int nargout_,
                           mxArray * WaveNumber,
                           mxArray * Wavelength,
                           mxArray * Weight);

_mexLocalFunctionTable _local_function_table_zsetwave
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetwave" contains the normal interface for the "zsetwave"
 * M-function from file "c:\projects\mzdde\zsetwave.m" (lines 1-31). This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
mxArray * mlfZsetwave(mxArray * WaveNumber,
                      mxArray * Wavelength,
                      mxArray * Weight) {
    int nargout = 1;
    mxArray * WaveData = NULL;
    mlfEnterNewContext(0, 3, WaveNumber, Wavelength, Weight);
    WaveData = Mzsetwave(nargout, WaveNumber, Wavelength, Weight);
    mlfRestorePreviousContext(0, 3, WaveNumber, Wavelength, Weight);
    return mlfReturnValue(WaveData);
}

/*
 * The function "mlxZsetwave" contains the feval interface for the "zsetwave"
 * M-function from file "c:\projects\mzdde\zsetwave.m" (lines 1-31). The feval
 * function calls the implementation version of zsetwave through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZsetwave(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[3];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetwave Line: 1 Column:"
            " 1 The function \"zsetwave\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 3) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetwave Line: 1 Column:"
            " 1 The function \"zsetwave\" was called with m"
            "ore than the declared number of inputs (3)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 3 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 3; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    mplhs[0] = Mzsetwave(nlhs, mprhs[0], mprhs[1], mprhs[2]);
    mlfRestorePreviousContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetwave" is the implementation version of the "zsetwave"
 * M-function from file "c:\projects\mzdde\zsetwave.m" (lines 1-31). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function WaveData = zSetWave(WaveNumber, Wavelength, Weight)
 */
static mxArray * Mzsetwave(int nargout_,
                           mxArray * WaveNumber,
                           mxArray * Wavelength,
                           mxArray * Weight) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetwave);
    mxArray * WaveData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&WaveNumber);
    mclCopyArray(&Wavelength);
    mclCopyArray(&Weight);
    /*
     * % zSetWave - Define wavelengths and weights in ZEMAX.
     * %
     * % Usage : WaveData = zSetWave(WaveNumber, Wavelength, Weight)
     * % or    : WaveData = zSetWave(0, PrimaryWavelength, NumberOfWavelengths)
     * % If the value for WaveNumber is zero, then the primary wavelength number and the total number of wavelengths is set to
     * % the new integer values. If WaveNumber is a valid wavelength number (between 1 and the number of wavelengths, inclusive)
     * % then the wavelength in microns and the wavelength weight are both set. The returned data
     * % is the same as for zGetWave(WaveNumber)
     * %
     * % See also zGetWave
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * if WaveNumber == 0
     */
    if (mclEqBool(mclVa(WaveNumber, "WaveNumber"), _mxarray0_)) {
        /*
         * DDECommand = sprintf('SetWave,0,%i,%i',Wavelength,Weight);
         */
        mlfAssign(
          &DDECommand,
          mlfSprintf(
            NULL,
            _mxarray1_,
            mclVa(Wavelength, "Wavelength"),
            mclVa(Weight, "Weight"),
            NULL));
    /*
     * else
     */
    } else {
        /*
         * DDECommand = sprintf('SetWave,%i,%11.9f,%11.9f',WaveNumber, Wavelength, Weight);
         */
        mlfAssign(
          &DDECommand,
          mlfSprintf(
            NULL,
            _mxarray3_,
            mclVa(WaveNumber, "WaveNumber"),
            mclVa(Wavelength, "Wavelength"),
            mclVa(Weight, "Weight"),
            NULL));
    /*
     * end
     */
    }
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
        _mxarray5_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    /*
     * if WaveNumber == 0
     */
    if (mclEqBool(mclVa(WaveNumber, "WaveNumber"), _mxarray0_)) {
        /*
         * [col, count, errmsg] = sscanf(Reply, '%i,%i');
         */
        mlfAssign(
          &col,
          mlfSscanf(
            &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray7_, NULL));
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
            &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray9_, NULL));
    /*
     * end
     */
    }
    /*
     * WaveData = col';
     */
    mlfAssign(&WaveData, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(WaveData, 1, nargout_, "WaveData", "zsetwave");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(Weight);
    mxDestroyArray(Wavelength);
    mxDestroyArray(WaveNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return WaveData;
    /*
     * 
     */
}
