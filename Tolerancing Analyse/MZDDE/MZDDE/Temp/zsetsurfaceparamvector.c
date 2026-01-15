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
#include "zsetsurfaceparamvector.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "libmmfile.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;
static mxArray * _mxarray0_;
static mxArray * _mxarray1_;
static mxArray * _mxarray2_;
static mxArray * _mxarray3_;
static mxArray * _mxarray4_;

static mxChar _array6_[32] = { 'S', 'e', 't', 'S', 'u', 'r', 'f', 'a',
                               'c', 'e', 'P', 'a', 'r', 'a', 'm', 'e',
                               't', 'e', 'r', ',', '%', 'i', ',', '%',
                               'i', ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray5_;

static double _array8_[2] = { 1.0, 1.0 };
static mxArray * _mxarray7_;

void InitializeModule_zsetsurfaceparamvector(void) {
    _mxarray0_ = mclInitializeDouble(2.0);
    _mxarray1_ = mclInitializeDouble(13.0);
    _mxarray2_ = mclInitializeDouble(1.0);
    _mxarray3_ = mclInitializeDouble(0.0);
    _mxarray4_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
    _mxarray5_ = mclInitializeString(32, _array6_);
    _mxarray7_ = mclInitializeDoubleVector(1, 2, _array8_);
}

void TerminateModule_zsetsurfaceparamvector(void) {
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray1_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetsurfaceparamvector(int nargout_,
                                         mxArray * SurfaceNumber,
                                         mxArray * ParamVector);

_mexLocalFunctionTable _local_function_table_zsetsurfaceparamvector
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetsurfaceparamvector" contains the normal interface for
 * the "zsetsurfaceparamvector" M-function from file
 * "c:\projects\mzdde\zsetsurfaceparamvector.m" (lines 1-25). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
mxArray * mlfZsetsurfaceparamvector(mxArray * SurfaceNumber,
                                    mxArray * ParamVector) {
    int nargout = 1;
    mxArray * ParameterVector = NULL;
    mlfEnterNewContext(0, 2, SurfaceNumber, ParamVector);
    ParameterVector
      = Mzsetsurfaceparamvector(nargout, SurfaceNumber, ParamVector);
    mlfRestorePreviousContext(0, 2, SurfaceNumber, ParamVector);
    return mlfReturnValue(ParameterVector);
}

/*
 * The function "mlxZsetsurfaceparamvector" contains the feval interface for
 * the "zsetsurfaceparamvector" M-function from file
 * "c:\projects\mzdde\zsetsurfaceparamvector.m" (lines 1-25). The feval
 * function calls the implementation version of zsetsurfaceparamvector through
 * this function. This function processes any input arguments and passes them
 * to the implementation version of the function, appearing above.
 */
void mlxZsetsurfaceparamvector(int nlhs,
                               mxArray * plhs[],
                               int nrhs,
                               mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetsurfaceparamvector Line: 1 Col"
            "umn: 1 The function \"zsetsurfaceparamvector\" was calle"
            "d with more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetsurfaceparamvector Line: 1 Co"
            "lumn: 1 The function \"zsetsurfaceparamvector\" was cal"
            "led with more than the declared number of inputs (2)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 2 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 2; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 2, mprhs[0], mprhs[1]);
    mplhs[0] = Mzsetsurfaceparamvector(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetsurfaceparamvector" is the implementation version of the
 * "zsetsurfaceparamvector" M-function from file
 * "c:\projects\mzdde\zsetsurfaceparamvector.m" (lines 1-25). It contains the
 * actual compiled code for that M-function. It is a static function and must
 * only be called from one of the interface functions, appearing below.
 */
/*
 * function ParameterVector = zSetSurfaceParamVector(SurfaceNumber, ParamVector)
 */
static mxArray * Mzsetsurfaceparamvector(int nargout_,
                                         mxArray * SurfaceNumber,
                                         mxArray * ParamVector) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(
          &_local_function_table_zsetsurfaceparamvector);
    mxArray * ParameterVector = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ParameterNumber = NULL;
    mxArray * iii = NULL;
    mxArray * ParamCols = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&SurfaceNumber);
    mclCopyArray(&ParamVector);
    /*
     * % zSetSurfaceParamVector - Sets all lens surface parameter data from a 13 column row vector.
     * %
     * % Usage : ParameterVector = zSetSurfaceParamVector(SurfaceNumber, ParamVector)
     * %
     * % If the vector passed has fewer than 13 columns, missing columns on the right will be set to zero.
     * %
     * % See also zGetSurfaceData and zGetSurfaceParameter
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * ParamCols = size(ParamVector,2);
     */
    mlfAssign(
      &ParamCols,
      mlfSize(
        mclValueVarargout(), mclVa(ParamVector, "ParamVector"), _mxarray0_));
    /*
     * if ParamCols < 13,
     */
    if (mclLtBool(mclVv(ParamCols, "ParamCols"), _mxarray1_)) {
        mclForLoopIterator viter__;
        /*
         * for iii = (ParamCols+1):13, ParamVector(1,iii) = 0; end;
         */
        for (mclForStart(
               &viter__,
               mclPlus(mclVv(ParamCols, "ParamCols"), _mxarray2_),
               _mxarray1_,
               NULL);
             mclForNext(&viter__, &iii);
             ) {
            mclArrayAssign2(
              &ParamVector, _mxarray3_, _mxarray2_, mclVv(iii, "iii"));
        }
        mclDestroyForLoopIterator(viter__);
    /*
     * end
     */
    }
    /*
     * for ParameterNumber = 0:12
     */
    {
        int v_ = mclForIntStart(0);
        int e_ = 12;
        if (v_ > e_) {
            mlfAssign(&ParameterNumber, _mxarray4_);
        } else {
            /*
             * DDECommand = sprintf('SetSurfaceParameter,%i,%i,%11.9f',SurfaceNumber,ParameterNumber,ParamVector(1,ParameterNumber+1));
             * ParameterVector(1,ParameterNumber+1) = str2num(ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout));
             * end
             */
            for (; ; ) {
                mlfAssign(
                  &DDECommand,
                  mlfSprintf(
                    NULL,
                    _mxarray5_,
                    mclVa(SurfaceNumber, "SurfaceNumber"),
                    mlfScalar(v_),
                    mclIntArrayRef2(
                      mclVa(ParamVector, "ParamVector"), 1, v_ + 1),
                    NULL));
                mclIntArrayAssign2(
                  &ParameterVector,
                  mlfStr2num(
                    NULL,
                    mlfNDdereq(
                      0,
                      mclValueVarargout(),
                      mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
                      mclVv(DDECommand, "DDECommand"),
                      _mxarray7_,
                      mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
                      NULL)),
                  1,
                  v_ + 1);
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            mlfAssign(&ParameterNumber, mlfScalar(v_));
        }
    }
    mclValidateOutput(
      ParameterVector,
      1,
      nargout_,
      "ParameterVector",
      "zsetsurfaceparamvector");
    mxDestroyArray(ans);
    mxDestroyArray(ParamCols);
    mxDestroyArray(iii);
    mxDestroyArray(ParameterNumber);
    mxDestroyArray(DDECommand);
    mxDestroyArray(ParamVector);
    mxDestroyArray(SurfaceNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return ParameterVector;
    /*
     * 
     * 
     */
}
