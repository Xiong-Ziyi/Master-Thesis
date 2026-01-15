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
#include "zssetsystem.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[38] = { 'S', 'e', 't', 'S', 'y', 's', 't', 'e', 'm', ',',
                               '%', 'i', ',', '%', 'i', ',', '%', 'i', ',', '%',
                               'i', ',', '%', '1', '1', '.', '9', 'f', ',', '%',
                               '1', '1', '.', '9', 'f', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

static mxChar _array5_[26] = { '%', 'f', ',', '%', 'f', ',', '%', 'f', ',',
                               '%', 'f', ',', '%', 'f', ',', '%', 'f', ',',
                               '%', 'f', ',', '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray4_;

static mxChar _array7_[8] = { 'n', 'u', 'm', 's', 'u', 'r', 'f', 's' };
static mxArray * _mxarray6_;

static mxChar _array9_[8] = { 'u', 'n', 'i', 't', 'c', 'o', 'd', 'e' };
static mxArray * _mxarray8_;

static mxChar _array11_[8] = { 's', 't', 'o', 'p', 's', 'u', 'r', 'f' };
static mxArray * _mxarray10_;

static mxChar _array13_[12] = { 'n', 'o', 'n', 'a', 'x', 'i',
                                'a', 'l', 'f', 'l', 'a', 'g' };
static mxArray * _mxarray12_;

static mxChar _array15_[13] = { 'r', 'a', 'y', 'a', 'i', 'm', 'i',
                                'n', 'g', 't', 'y', 'p', 'e' };
static mxArray * _mxarray14_;

static mxChar _array17_[10] = { 'u', 's', 'e', 'e', 'n',
                                'v', 'd', 'a', 't', 'a' };
static mxArray * _mxarray16_;

static mxChar _array19_[4] = { 't', 'e', 'm', 'p' };
static mxArray * _mxarray18_;

static mxChar _array21_[8] = { 'p', 'r', 'e', 's', 's', 'u', 'r', 'e' };
static mxArray * _mxarray20_;

static mxChar _array23_[13] = { 'g', 'l', 'o', 'b', 'a', 'l', 'r',
                                'e', 'f', 's', 'u', 'r', 'f' };
static mxArray * _mxarray22_;

void InitializeModule_zssetsystem(void) {
    _mxarray0_ = mclInitializeString(38, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeString(26, _array5_);
    _mxarray6_ = mclInitializeString(8, _array7_);
    _mxarray8_ = mclInitializeString(8, _array9_);
    _mxarray10_ = mclInitializeString(8, _array11_);
    _mxarray12_ = mclInitializeString(12, _array13_);
    _mxarray14_ = mclInitializeString(13, _array15_);
    _mxarray16_ = mclInitializeString(10, _array17_);
    _mxarray18_ = mclInitializeString(4, _array19_);
    _mxarray20_ = mclInitializeString(8, _array21_);
    _mxarray22_ = mclInitializeString(13, _array23_);
}

void TerminateModule_zssetsystem(void) {
    mxDestroyArray(_mxarray22_);
    mxDestroyArray(_mxarray20_);
    mxDestroyArray(_mxarray18_);
    mxDestroyArray(_mxarray16_);
    mxDestroyArray(_mxarray14_);
    mxDestroyArray(_mxarray12_);
    mxDestroyArray(_mxarray10_);
    mxDestroyArray(_mxarray8_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzssetsystem(int nargout_, mxArray * iSystemData);

_mexLocalFunctionTable _local_function_table_zssetsystem
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZssetsystem" contains the normal interface for the
 * "zssetsystem" M-function from file "c:\projects\mzdde\zssetsystem.m" (lines
 * 1-28). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZssetsystem(mxArray * iSystemData) {
    int nargout = 1;
    mxArray * oSystemData = NULL;
    mlfEnterNewContext(0, 1, iSystemData);
    oSystemData = Mzssetsystem(nargout, iSystemData);
    mlfRestorePreviousContext(0, 1, iSystemData);
    return mlfReturnValue(oSystemData);
}

/*
 * The function "mlxZssetsystem" contains the feval interface for the
 * "zssetsystem" M-function from file "c:\projects\mzdde\zssetsystem.m" (lines
 * 1-28). The feval function calls the implementation version of zssetsystem
 * through this function. This function processes any input arguments and
 * passes them to the implementation version of the function, appearing above.
 */
void mlxZssetsystem(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zssetsystem Line: 1 Column"
            ": 1 The function \"zssetsystem\" was called with"
            " more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zssetsystem Line: 1 Column"
            ": 1 The function \"zssetsystem\" was called with"
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
    mplhs[0] = Mzssetsystem(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzssetsystem" is the implementation version of the
 * "zssetsystem" M-function from file "c:\projects\mzdde\zssetsystem.m" (lines
 * 1-28). It contains the actual compiled code for that M-function. It is a
 * static function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function oSystemData = zsSetSystem(iSystemData)
 */
static mxArray * Mzssetsystem(int nargout_, mxArray * iSystemData) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zssetsystem);
    mxArray * oSystemData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * ZemaxParms = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&iSystemData);
    /*
     * % zsSetSystem - Sets a number of lens system operating data.
     * %
     * % Usage : oSystemData = zsSetSystem(iSystemData)
     * %
     * % This function sets the lens units code (0, 1, 2, or 3 for mm, cm, in , or M), the stop surf number,
     * % the ray aiming type (0, 1, 2 for none, paraxial, real), the use environment data flag (0 for no, 1 for yes), the current
     * % temperature and pressure, and the global coordinate reference surface number from an input
     * % structure iSystemData.
     * %
     * % The input and returned structures must have the following fields
     * % numsurfs, unitcode, stopsurf, nonaxialflag, rayaimingtype, useenvdata, temp, pressure, globalrefsurf
     * % where in addition to the above input parameters, numsurfs is the number of surfaces in the lens and  nonaxialflag is 
     * % a flag to indicate if the system is non-axial symmetric (0 for false, i.e. it is axial, or 1 if
     * % the system is not axial).
     * %
     * % See also zGetSystem and zGetSystemAper
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.0 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SetSystem,%i,%i,%i,%i,%11.9f,%11.9f,%i', iSystemData.unitcode, iSystemData.stopsurf, iSystemData.rayaimingtype, iSystemData.useenvdata, iSystemData.temp, iSystemData.pressure, iSystemData.globalrefsurf);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mlfIndexRef(mclVa(iSystemData, "iSystemData"), ".unitcode"),
        mlfIndexRef(mclVa(iSystemData, "iSystemData"), ".stopsurf"),
        mlfIndexRef(mclVa(iSystemData, "iSystemData"), ".rayaimingtype"),
        mlfIndexRef(mclVa(iSystemData, "iSystemData"), ".useenvdata"),
        mlfIndexRef(mclVa(iSystemData, "iSystemData"), ".temp"),
        mlfIndexRef(mclVa(iSystemData, "iSystemData"), ".pressure"),
        mlfIndexRef(mclVa(iSystemData, "iSystemData"), ".globalrefsurf"),
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
     * [ZemaxParms,count,errmsg]= sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f,%f');
     */
    mlfAssign(
      &ZemaxParms,
      mlfSscanf(
        &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray4_, NULL));
    /*
     * oSystemData = struct('numsurfs',ZemaxParms(1),'unitcode', ZemaxParms(2), 'stopsurf', ZemaxParms(3), 'nonaxialflag', ZemaxParms(4), 'rayaimingtype', ZemaxParms(5), 'useenvdata', ZemaxParms(6), 'temp', ZemaxParms(7), 'pressure', ZemaxParms(8), 'globalrefsurf', ZemaxParms(9));
     */
    mlfAssign(
      &oSystemData,
      mlfStruct(
        _mxarray6_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 1),
        _mxarray8_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 2),
        _mxarray10_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 3),
        _mxarray12_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 4),
        _mxarray14_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 5),
        _mxarray16_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 6),
        _mxarray18_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 7),
        _mxarray20_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 8),
        _mxarray22_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 9),
        NULL));
    mclValidateOutput(oSystemData, 1, nargout_, "oSystemData", "zssetsystem");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(ZemaxParms);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(iSystemData);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return oSystemData;
}
