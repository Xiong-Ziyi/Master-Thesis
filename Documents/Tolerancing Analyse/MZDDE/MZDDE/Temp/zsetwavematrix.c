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
#include "zsetwavematrix.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "zsetwave.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;
static mxArray * _mxarray0_;
static mxArray * _mxarray1_;
static mxArray * _mxarray2_;

static mxChar _array4_[24] = { 'S', 'e', 't', 'W', 'a', 'v', 'e', ',',
                               '%', 'i', ',', '%', '1', '1', '.', '9',
                               'f', ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray3_;

static double _array6_[2] = { 1.0, 1.0 };
static mxArray * _mxarray5_;

static mxChar _array8_[5] = { '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray7_;

void InitializeModule_zsetwavematrix(void) {
    _mxarray0_ = mclInitializeDouble(1.0);
    _mxarray1_ = mclInitializeDouble(0.0);
    _mxarray2_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
    _mxarray3_ = mclInitializeString(24, _array4_);
    _mxarray5_ = mclInitializeDoubleVector(1, 2, _array6_);
    _mxarray7_ = mclInitializeString(5, _array8_);
}

void TerminateModule_zsetwavematrix(void) {
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray1_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetwavematrix(int nargout_, mxArray * iWaveDataMatrix);

_mexLocalFunctionTable _local_function_table_zsetwavematrix
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetwavematrix" contains the normal interface for the
 * "zsetwavematrix" M-function from file "c:\projects\mzdde\zsetwavematrix.m"
 * (lines 1-29). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZsetwavematrix(mxArray * iWaveDataMatrix) {
    int nargout = 1;
    mxArray * oWaveDataMatrix = NULL;
    mlfEnterNewContext(0, 1, iWaveDataMatrix);
    oWaveDataMatrix = Mzsetwavematrix(nargout, iWaveDataMatrix);
    mlfRestorePreviousContext(0, 1, iWaveDataMatrix);
    return mlfReturnValue(oWaveDataMatrix);
}

/*
 * The function "mlxZsetwavematrix" contains the feval interface for the
 * "zsetwavematrix" M-function from file "c:\projects\mzdde\zsetwavematrix.m"
 * (lines 1-29). The feval function calls the implementation version of
 * zsetwavematrix through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZsetwavematrix(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetwavematrix Line: 1 Colum"
            "n: 1 The function \"zsetwavematrix\" was called wi"
            "th more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetwavematrix Line: 1 Colum"
            "n: 1 The function \"zsetwavematrix\" was called wi"
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
    mplhs[0] = Mzsetwavematrix(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetwavematrix" is the implementation version of the
 * "zsetwavematrix" M-function from file "c:\projects\mzdde\zsetwavematrix.m"
 * (lines 1-29). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function oWaveDataMatrix = zSetWaveMatrix(iWaveDataMatrix)
 */
static mxArray * Mzsetwavematrix(int nargout_, mxArray * iWaveDataMatrix) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetwavematrix);
    mxArray * oWaveDataMatrix = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * iii = NULL;
    mxArray * WaveCount = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&iWaveDataMatrix);
    /*
     * % zSetWaveMatrix - Sets wavelength and weight data from a matrix.
     * %
     * % Usage : oWaveDataMatrix = zSetWaveMatrix(iWaveDataMatrix)
     * %
     * % The wavelengths are set from column 1 of the matrix iWaveDataMatrix, and the weights are set from
     * % column 2. The primary wavelength is assumed to be wavelength 1. To change the primary wavelength,
     * % use zSetWavePrimary.
     * %
     * % Returns a matrix having colummns wavelength and weight for all defined wavelengths.
     * %
     * % See also zGetWave, zSetWave, zSetWavePrimary
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * WaveCount = size(iWaveDataMatrix,1);
     */
    mlfAssign(
      &WaveCount,
      mlfSize(
        mclValueVarargout(),
        mclVa(iWaveDataMatrix, "iWaveDataMatrix"),
        _mxarray0_));
    /*
     * zSetWave(0,1,WaveCount); % Set the primary wavelength to 1 and the number of wavelengths to the rows of iWaveDataMatrix.
     */
    mclAssignAns(
      &ans, mlfZsetwave(_mxarray1_, _mxarray0_, mclVv(WaveCount, "WaveCount")));
    /*
     * for iii = 1:WaveCount
     */
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mclVv(WaveCount, "WaveCount"));
        if (v_ > e_) {
            mlfAssign(&iii, _mxarray2_);
        } else {
            /*
             * DDECommand = sprintf('SetWave,%i,%11.9f,%11.9f',iii, iWaveDataMatrix(iii, 1), iWaveDataMatrix(iii, 2));
             * Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
             * [col, count, errmsg] = sscanf(Reply, '%f,%f');
             * oWaveDataMatrix(iii, 1) = col(1);
             * oWaveDataMatrix(iii, 2) = col(2);
             * end
             */
            for (; ; ) {
                mlfAssign(
                  &DDECommand,
                  mlfSprintf(
                    NULL,
                    _mxarray3_,
                    mlfScalar(v_),
                    mclIntArrayRef2(
                      mclVa(iWaveDataMatrix, "iWaveDataMatrix"), v_, 1),
                    mclIntArrayRef2(
                      mclVa(iWaveDataMatrix, "iWaveDataMatrix"), v_, 2),
                    NULL));
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
                mlfAssign(
                  &col,
                  mlfSscanf(
                    &count,
                    &errmsg,
                    NULL,
                    mclVv(Reply, "Reply"),
                    _mxarray7_,
                    NULL));
                mclIntArrayAssign2(
                  &oWaveDataMatrix,
                  mclIntArrayRef1(mclVv(col, "col"), 1),
                  v_,
                  1);
                mclIntArrayAssign2(
                  &oWaveDataMatrix,
                  mclIntArrayRef1(mclVv(col, "col"), 2),
                  v_,
                  2);
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            mlfAssign(&iii, mlfScalar(v_));
        }
    }
    mclValidateOutput(
      oWaveDataMatrix, 1, nargout_, "oWaveDataMatrix", "zsetwavematrix");
    mxDestroyArray(ans);
    mxDestroyArray(WaveCount);
    mxDestroyArray(iii);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(iWaveDataMatrix);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return oWaveDataMatrix;
    /*
     * 
     */
}
