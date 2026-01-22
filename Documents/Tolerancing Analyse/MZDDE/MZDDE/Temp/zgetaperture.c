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
#include "zgetaperture.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[14] = { 'G', 'e', 't', 'A', 'p', 'e', 'r',
                               't', 'u', 'r', 'e', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

static mxChar _array5_[14] = { '%', 'f', ',', '%', 'f', ',', '%',
                               'f', ',', '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray4_;

void InitializeModule_zgetaperture(void) {
    _mxarray0_ = mclInitializeString(14, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeString(14, _array5_);
}

void TerminateModule_zgetaperture(void) {
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzgetaperture(int nargout_, mxArray * SurfaceNumber);

_mexLocalFunctionTable _local_function_table_zgetaperture
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZgetaperture" contains the normal interface for the
 * "zgetaperture" M-function from file "c:\projects\mzdde\zgetaperture.m"
 * (lines 1-25). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZgetaperture(mxArray * SurfaceNumber) {
    int nargout = 1;
    mxArray * ApertureInfo = NULL;
    mlfEnterNewContext(0, 1, SurfaceNumber);
    ApertureInfo = Mzgetaperture(nargout, SurfaceNumber);
    mlfRestorePreviousContext(0, 1, SurfaceNumber);
    return mlfReturnValue(ApertureInfo);
}

/*
 * The function "mlxZgetaperture" contains the feval interface for the
 * "zgetaperture" M-function from file "c:\projects\mzdde\zgetaperture.m"
 * (lines 1-25). The feval function calls the implementation version of
 * zgetaperture through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZgetaperture(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zgetaperture Line: 1 Column"
            ": 1 The function \"zgetaperture\" was called with"
            " more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zgetaperture Line: 1 Column"
            ": 1 The function \"zgetaperture\" was called with"
            " more than the declared number of inputs (1)."),
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
    mplhs[0] = Mzgetaperture(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzgetaperture" is the implementation version of the
 * "zgetaperture" M-function from file "c:\projects\mzdde\zgetaperture.m"
 * (lines 1-25). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function ApertureInfo = zGetAperture(SurfaceNumber)
 */
static mxArray * Mzgetaperture(int nargout_, mxArray * SurfaceNumber) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zgetaperture);
    mxArray * ApertureInfo = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&SurfaceNumber);
    /*
     * % zGetAperture - Requests information on a surface aperture from the Zemax DDE server.
     * %
     * % zGetAperture(SurfaceNumber)
     * %
     * % Returns a row vector containing aperture type, min, max, xdecenter, ydecenter.
     * % This function returns the type as an integer code; 0 for no aperture, 1 for circular aperture, 2 for circular
     * % obscuration, 3 for spider, 4 for rectangular aperture, 5 for rectangular obscuration, 6 for elliptical aperture, 7 for
     * % elliptical obscuration, 8 for user defined aperture, 9 for user defined obscuration, and 10 for floating aperture. The
     * % min and max values have different meanings for the elliptical, rectangular, and spider apertures than for circular
     * % apertures; see the Editors Menu chapter in the Zemax Manual for details. 
     * %
     * % See also zSetAperture.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('GetAperture,%i',SurfaceNumber);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL, _mxarray0_, mclVa(SurfaceNumber, "SurfaceNumber"), NULL));
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
     * [col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f');
     */
    mlfAssign(
      &col,
      mlfSscanf(
        &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray4_, NULL));
    /*
     * ApertureInfo = col';
     */
    mlfAssign(&ApertureInfo, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(
      ApertureInfo, 1, nargout_, "ApertureInfo", "zgetaperture");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(SurfaceNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return ApertureInfo;
    /*
     * 
     */
}
