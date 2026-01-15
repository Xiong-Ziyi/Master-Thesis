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
#include "zsetsystemaper.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[26] = { 'S', 'e', 't', 'S', 'y', 's', 't', 'e', 'm',
                               'A', 'p', 'e', 'r', ',', '%', 'i', ',', '%',
                               'i', ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

static mxChar _array5_[8] = { '%', 'f', ',', '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray4_;

void InitializeModule_zsetsystemaper(void) {
    _mxarray0_ = mclInitializeString(26, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeString(8, _array5_);
}

void TerminateModule_zsetsystemaper(void) {
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetsystemaper(int nargout_,
                                 mxArray * Type,
                                 mxArray * StopSurf,
                                 mxArray * ApertureValue);

_mexLocalFunctionTable _local_function_table_zsetsystemaper
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetsystemaper" contains the normal interface for the
 * "zsetsystemaper" M-function from file "c:\projects\mzdde\zsetsystemaper.m"
 * (lines 1-23). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZsetsystemaper(mxArray * Type,
                            mxArray * StopSurf,
                            mxArray * ApertureValue) {
    int nargout = 1;
    mxArray * SystemApertureData = NULL;
    mlfEnterNewContext(0, 3, Type, StopSurf, ApertureValue);
    SystemApertureData
      = Mzsetsystemaper(nargout, Type, StopSurf, ApertureValue);
    mlfRestorePreviousContext(0, 3, Type, StopSurf, ApertureValue);
    return mlfReturnValue(SystemApertureData);
}

/*
 * The function "mlxZsetsystemaper" contains the feval interface for the
 * "zsetsystemaper" M-function from file "c:\projects\mzdde\zsetsystemaper.m"
 * (lines 1-23). The feval function calls the implementation version of
 * zsetsystemaper through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZsetsystemaper(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[3];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetsystemaper Line: 1 Colum"
            "n: 1 The function \"zsetsystemaper\" was called wi"
            "th more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 3) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetsystemaper Line: 1 Colum"
            "n: 1 The function \"zsetsystemaper\" was called wi"
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
    mplhs[0] = Mzsetsystemaper(nlhs, mprhs[0], mprhs[1], mprhs[2]);
    mlfRestorePreviousContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetsystemaper" is the implementation version of the
 * "zsetsystemaper" M-function from file "c:\projects\mzdde\zsetsystemaper.m"
 * (lines 1-23). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function SystemApertureData = zSetSystemAper(Type, StopSurf, ApertureValue)
 */
static mxArray * Mzsetsystemaper(int nargout_,
                                 mxArray * Type,
                                 mxArray * StopSurf,
                                 mxArray * ApertureValue) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetsystemaper);
    mxArray * SystemApertureData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&Type);
    mclCopyArray(&StopSurf);
    mclCopyArray(&ApertureValue);
    /*
     * % zSetSystemAper - Sets lens system aperture data.
     * %
     * % Usage : SystemApertureData = zSetSystemAper(Type, StopSurf, ApertureValue)
     * % The returned row vector is also formatted as follows:
     * % Type, StopSurf, ApertureValue
     * % This function sets the system aperture type (0, 1, 2, 3, 4, or 5 for Entrance Pupil Diameter, Image Space F/#,
     * % Object Space NA, Float by Stop Size, Paraxial Working F/#, or Object Cone Angle, respectively), the stop surface
     * % number, and the system aperture value. If the aperture type is Float by Stop Size, the aperture value is the stop
     * % surface semi-diameter.
     * % 
     * % See also zGetSystem and zGetSystemAper
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SetSystemAper,%i,%i,%11.9f', Type, StopSurf, ApertureValue);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mclVa(Type, "Type"),
        mclVa(StopSurf, "StopSurf"),
        mclVa(ApertureValue, "ApertureValue"),
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
        _mxarray2_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    /*
     * [col, count, errmsg] = sscanf(Reply, '%f,%f,%f');
     */
    mlfAssign(
      &col,
      mlfSscanf(
        &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray4_, NULL));
    /*
     * SystemApertureData = col';
     */
    mlfAssign(&SystemApertureData, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(
      SystemApertureData, 1, nargout_, "SystemApertureData", "zsetsystemaper");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(ApertureValue);
    mxDestroyArray(StopSurf);
    mxDestroyArray(Type);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return SystemApertureData;
}
