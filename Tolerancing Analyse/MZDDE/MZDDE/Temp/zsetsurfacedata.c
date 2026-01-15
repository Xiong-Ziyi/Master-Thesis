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
#include "zsetsurfacedata.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "libmmfile.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[21] = { 'S', 'e', 't', 'S', 'u', 'r', 'f',
                               'a', 'c', 'e', 'D', 'a', 't', 'a',
                               ',', '%', 'i', ',', '%', 'i', ',' };
static mxArray * _mxarray0_;
static mxArray * _mxarray4_;
static mxArray * _mxarray5_;
static mxArray * _mxarray6_;
static mxArray * _mxarray7_;

static mxArray * _array3_[4] = { NULL /*_mxarray4_*/, NULL /*_mxarray5_*/,
                                 NULL /*_mxarray6_*/, NULL /*_mxarray7_*/ };
static mxArray * _mxarray2_;
static mxArray * _mxarray10_;
static mxArray * _mxarray11_;
static mxArray * _mxarray12_;
static mxArray * _mxarray13_;

static mxArray * _array9_[4] = { NULL /*_mxarray10_*/, NULL /*_mxarray11_*/,
                                 NULL /*_mxarray12_*/, NULL /*_mxarray13_*/ };
static mxArray * _mxarray8_;

static mxChar _array15_[6] = { '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray14_;

static double _array17_[2] = { 1.0, 1.0 };
static mxArray * _mxarray16_;

void InitializeModule_zsetsurfacedata(void) {
    _mxarray0_ = mclInitializeString(21, _array1_);
    _mxarray4_ = mclInitializeDouble(0.0);
    _array3_[0] = _mxarray4_;
    _mxarray5_ = mclInitializeDouble(1.0);
    _array3_[1] = _mxarray5_;
    _mxarray6_ = mclInitializeDouble(4.0);
    _array3_[2] = _mxarray6_;
    _mxarray7_ = mclInitializeDouble(7.0);
    _array3_[3] = _mxarray7_;
    _mxarray2_ = mclInitializeCellVector(1, 4, _array3_);
    _mxarray10_ = mclInitializeDouble(2.0);
    _array9_[0] = _mxarray10_;
    _mxarray11_ = mclInitializeDouble(3.0);
    _array9_[1] = _mxarray11_;
    _mxarray12_ = mclInitializeDouble(5.0);
    _array9_[2] = _mxarray12_;
    _mxarray13_ = mclInitializeDouble(6.0);
    _array9_[3] = _mxarray13_;
    _mxarray8_ = mclInitializeCellVector(1, 4, _array9_);
    _mxarray14_ = mclInitializeString(6, _array15_);
    _mxarray16_ = mclInitializeDoubleVector(1, 2, _array17_);
}

void TerminateModule_zsetsurfacedata(void) {
    mxDestroyArray(_mxarray16_);
    mxDestroyArray(_mxarray14_);
    mxDestroyArray(_mxarray8_);
    mxDestroyArray(_mxarray13_);
    mxDestroyArray(_mxarray12_);
    mxDestroyArray(_mxarray11_);
    mxDestroyArray(_mxarray10_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetsurfacedata(int nargout_,
                                  mxArray * SurfaceNumber,
                                  mxArray * Code,
                                  mxArray * Value);

_mexLocalFunctionTable _local_function_table_zsetsurfacedata
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetsurfacedata" contains the normal interface for the
 * "zsetsurfacedata" M-function from file "c:\projects\mzdde\zsetsurfacedata.m"
 * (lines 1-39). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZsetsurfacedata(mxArray * SurfaceNumber,
                             mxArray * Code,
                             mxArray * Value) {
    int nargout = 1;
    mxArray * SurfaceDatum = NULL;
    mlfEnterNewContext(0, 3, SurfaceNumber, Code, Value);
    SurfaceDatum = Mzsetsurfacedata(nargout, SurfaceNumber, Code, Value);
    mlfRestorePreviousContext(0, 3, SurfaceNumber, Code, Value);
    return mlfReturnValue(SurfaceDatum);
}

/*
 * The function "mlxZsetsurfacedata" contains the feval interface for the
 * "zsetsurfacedata" M-function from file "c:\projects\mzdde\zsetsurfacedata.m"
 * (lines 1-39). The feval function calls the implementation version of
 * zsetsurfacedata through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZsetsurfacedata(int nlhs,
                        mxArray * plhs[],
                        int nrhs,
                        mxArray * prhs[]) {
    mxArray * mprhs[3];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetsurfacedata Line: 1 Colum"
            "n: 1 The function \"zsetsurfacedata\" was called wi"
            "th more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 3) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetsurfacedata Line: 1 Colum"
            "n: 1 The function \"zsetsurfacedata\" was called wi"
            "th more than the declared number of inputs (3)."),
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
    mplhs[0] = Mzsetsurfacedata(nlhs, mprhs[0], mprhs[1], mprhs[2]);
    mlfRestorePreviousContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetsurfacedata" is the implementation version of the
 * "zsetsurfacedata" M-function from file "c:\projects\mzdde\zsetsurfacedata.m"
 * (lines 1-39). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function SurfaceDatum = zSetSurfaceData(SurfaceNumber, Code, Value)
 */
static mxArray * Mzsetsurfacedata(int nargout_,
                                  mxArray * SurfaceNumber,
                                  mxArray * Code,
                                  mxArray * Value) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(
          &_local_function_table_zsetsurfacedata);
    mxArray * SurfaceDatum = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&SurfaceNumber);
    mclCopyArray(&Code);
    mclCopyArray(&Value);
    /*
     * % zSetSurfaceData - Sets various data on a sequential lens surface.
     * %
     * % Usage : SurfaceDatum = zSetSurfaceData(SurfaceNumber, Code, Value)
     * % Sets surface datum at SurfaceNumber depending on the code according to the following table.
     * % The Value is the required value to which the datum should be set. Supply a string or a numeric
     * % Value according to the following table.
     * % Code      - Datum to be set by by zSetSurfaceData
     * % 0         - Surface type name. (string)
     * % 1         - Comment. (string)
     * % 2         - Curvature (numeric).
     * % 3         - Thickness. (numeric)
     * % 4         - Glass. (string)
     * % 5         - Semi-Diameter. (numeric)
     * % 6         - Conic. (numeric)
     * % 7         - Coating. (string)
     * % 8 and up  - Reserved for future expansion of this feature.
     * %
     * % See also zGetSurfaceData
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SetSurfaceData,%i,%i,',SurfaceNumber,Code);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mclVa(SurfaceNumber, "SurfaceNumber"),
        mclVa(Code, "Code"),
        NULL));
    /*
     * switch Code
     */
    {
        mxArray * v_ = mclInitialize(mclVa(Code, "Code"));
        if (mclSwitchCompare(v_, _mxarray2_)) {
            /*
             * case {0,1,4,7}, DDECommand = [DDECommand Value]; % String Value
             */
            mlfAssign(
              &DDECommand,
              mlfHorzcat(
                mclVv(DDECommand, "DDECommand"), mclVa(Value, "Value"), NULL));
        /*
         * case {2,3,5,6}, DDECommand = [DDECommand sprintf('%11.9f', Value)]; % Numeric Value
         */
        } else if (mclSwitchCompare(v_, _mxarray8_)) {
            mlfAssign(
              &DDECommand,
              mlfHorzcat(
                mclVv(DDECommand, "DDECommand"),
                mlfSprintf(NULL, _mxarray14_, mclVa(Value, "Value"), NULL),
                NULL));
        /*
         * otherwise, DDECommand = [DDECommand Value]; % Assume String Value
         */
        } else {
            mlfAssign(
              &DDECommand,
              mlfHorzcat(
                mclVv(DDECommand, "DDECommand"), mclVa(Value, "Value"), NULL));
        /*
         * end
         */
        }
        mxDestroyArray(v_);
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
        _mxarray16_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    /*
     * switch Code
     */
    {
        mxArray * v_ = mclInitialize(mclVa(Code, "Code"));
        if (mclSwitchCompare(v_, _mxarray2_)) {
            /*
             * case {0,1,4,7}, SurfaceDatum = Reply;
             */
            mlfAssign(&SurfaceDatum, mclVv(Reply, "Reply"));
        /*
         * case {2,3,5,6}, SurfaceDatum = str2num(Reply);
         */
        } else if (mclSwitchCompare(v_, _mxarray8_)) {
            mlfAssign(&SurfaceDatum, mlfStr2num(NULL, mclVv(Reply, "Reply")));
        /*
         * otherwise, SurfaceDatum = Reply;
         */
        } else {
            mlfAssign(&SurfaceDatum, mclVv(Reply, "Reply"));
        /*
         * end
         */
        }
        mxDestroyArray(v_);
    }
    mclValidateOutput(
      SurfaceDatum, 1, nargout_, "SurfaceDatum", "zsetsurfacedata");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(Value);
    mxDestroyArray(Code);
    mxDestroyArray(SurfaceNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return SurfaceDatum;
    /*
     * 
     */
}
