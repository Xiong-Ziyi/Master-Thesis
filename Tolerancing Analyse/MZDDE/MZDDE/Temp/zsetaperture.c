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
#include "zsetaperture.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[48] = { 'S', 'e', 't', 'A', 'p', 'e', 'r', 't', 'u', 'r',
                               'e', ',', '%', 'i', ',', '%', 'i', ',', '%', '1',
                               '1', '.', '9', 'f', ',', '%', '1', '1', '.', '9',
                               'f', ',', '%', '1', '1', '.', '9', 'f', ',', '%',
                               '1', '1', '.', '9', 'f', ',', '%', 's' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

static mxChar _array5_[14] = { '%', 'f', ',', '%', 'f', ',', '%',
                               'f', ',', '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray4_;

void InitializeModule_zsetaperture(void) {
    _mxarray0_ = mclInitializeString(48, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeString(14, _array5_);
}

void TerminateModule_zsetaperture(void) {
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetaperture(int nargout_,
                               mxArray * SurfaceNumber,
                               mxArray * Type,
                               mxArray * Min,
                               mxArray * Max,
                               mxArray * xDecenter,
                               mxArray * yDecenter,
                               mxArray * ApertureFile);

_mexLocalFunctionTable _local_function_table_zsetaperture
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetaperture" contains the normal interface for the
 * "zsetaperture" M-function from file "c:\projects\mzdde\zsetaperture.m"
 * (lines 1-31). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZsetaperture(mxArray * SurfaceNumber,
                          mxArray * Type,
                          mxArray * Min,
                          mxArray * Max,
                          mxArray * xDecenter,
                          mxArray * yDecenter,
                          mxArray * ApertureFile) {
    int nargout = 1;
    mxArray * ApertureInfo = NULL;
    mlfEnterNewContext(
      0, 7, SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile);
    ApertureInfo
      = Mzsetaperture(
          nargout,
          SurfaceNumber,
          Type,
          Min,
          Max,
          xDecenter,
          yDecenter,
          ApertureFile);
    mlfRestorePreviousContext(
      0, 7, SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile);
    return mlfReturnValue(ApertureInfo);
}

/*
 * The function "mlxZsetaperture" contains the feval interface for the
 * "zsetaperture" M-function from file "c:\projects\mzdde\zsetaperture.m"
 * (lines 1-31). The feval function calls the implementation version of
 * zsetaperture through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZsetaperture(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[7];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetaperture Line: 1 Column"
            ": 1 The function \"zsetaperture\" was called with"
            " more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 7) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetaperture Line: 1 Column"
            ": 1 The function \"zsetaperture\" was called with"
            " more than the declared number of inputs (7)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 7 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 7; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(
      0,
      7,
      mprhs[0],
      mprhs[1],
      mprhs[2],
      mprhs[3],
      mprhs[4],
      mprhs[5],
      mprhs[6]);
    mplhs[0]
      = Mzsetaperture(
          nlhs,
          mprhs[0],
          mprhs[1],
          mprhs[2],
          mprhs[3],
          mprhs[4],
          mprhs[5],
          mprhs[6]);
    mlfRestorePreviousContext(
      0,
      7,
      mprhs[0],
      mprhs[1],
      mprhs[2],
      mprhs[3],
      mprhs[4],
      mprhs[5],
      mprhs[6]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetaperture" is the implementation version of the
 * "zsetaperture" M-function from file "c:\projects\mzdde\zsetaperture.m"
 * (lines 1-31). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function ApertureInfo = zSetAperture(SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile)
 */
static mxArray * Mzsetaperture(int nargout_,
                               mxArray * SurfaceNumber,
                               mxArray * Type,
                               mxArray * Min,
                               mxArray * Max,
                               mxArray * xDecenter,
                               mxArray * yDecenter,
                               mxArray * ApertureFile) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetaperture);
    mxArray * ApertureInfo = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&SurfaceNumber);
    mclCopyArray(&Type);
    mclCopyArray(&Min);
    mclCopyArray(&Max);
    mclCopyArray(&xDecenter);
    mclCopyArray(&yDecenter);
    mclCopyArray(&ApertureFile);
    /*
     * % zSetAperture - Set aperture details at a ZEMAX lens surface.
     * %
     * % Usage : ApertureInfo = zSetAperture(SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile)
     * %
     * % The returned row vector is formatted as follows:
     * % Type, Min, Max, xDecenter, yDecenter
     * %
     * % This function uses an integer code for the surface aperture type; 0 for no aperture, 1 for circular aperture, 2 for
     * % circular obscuration, 3 for spider, 4 for rectangular aperture, 5 for rectangular obscuration, 6 for elliptical aperture,
     * % 7 for elliptical obscuration, 8 for user defined aperture, 9 for user defined obscuration, and 10 for floating aperture.
     * % The min and max values have different meanings for the elliptical, rectangular, and spider apertures than for
     * % circular apertures; see 'Aperture type and other aperture controls' in the ZEMAX manual for details.
     * % If zSetAperture is used to set user defined apertures or obscurations, the ApertureFile must be the name of a
     * % file which lists the x, y, coordinates of the user defined aperture file in a two column format. For more information
     * % on user defined apertures, see 'User defined apertures and obscurations' in the ZEMAX manual.
     * %
     * % See also zGetAperture.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SetAperture,%i,%i,%11.9f,%11.9f,%11.9f,%11.9f,%s',SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mclVa(SurfaceNumber, "SurfaceNumber"),
        mclVa(Type, "Type"),
        mclVa(Min, "Min"),
        mclVa(Max, "Max"),
        mclVa(xDecenter, "xDecenter"),
        mclVa(yDecenter, "yDecenter"),
        mclVa(ApertureFile, "ApertureFile"),
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
      ApertureInfo, 1, nargout_, "ApertureInfo", "zsetaperture");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(ApertureFile);
    mxDestroyArray(yDecenter);
    mxDestroyArray(xDecenter);
    mxDestroyArray(Max);
    mxDestroyArray(Min);
    mxDestroyArray(Type);
    mxDestroyArray(SurfaceNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return ApertureInfo;
    /*
     * 
     * 
     */
}
