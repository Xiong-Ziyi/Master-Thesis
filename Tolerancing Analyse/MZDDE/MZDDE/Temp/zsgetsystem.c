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
#include "zsgetsystem.h"
#include "libmatlbm.h"
#include "zgetsystem.h"

static mxChar _array1_[8] = { 'n', 'u', 'm', 's', 'u', 'r', 'f', 's' };
static mxArray * _mxarray0_;

static mxChar _array3_[8] = { 'u', 'n', 'i', 't', 'c', 'o', 'd', 'e' };
static mxArray * _mxarray2_;

static mxChar _array5_[8] = { 's', 't', 'o', 'p', 's', 'u', 'r', 'f' };
static mxArray * _mxarray4_;

static mxChar _array7_[12] = { 'n', 'o', 'n', 'a', 'x', 'i',
                               'a', 'l', 'f', 'l', 'a', 'g' };
static mxArray * _mxarray6_;

static mxChar _array9_[13] = { 'r', 'a', 'y', 'a', 'i', 'm', 'i',
                               'n', 'g', 't', 'y', 'p', 'e' };
static mxArray * _mxarray8_;

static mxChar _array11_[10] = { 'u', 's', 'e', 'e', 'n',
                                'v', 'd', 'a', 't', 'a' };
static mxArray * _mxarray10_;

static mxChar _array13_[4] = { 't', 'e', 'm', 'p' };
static mxArray * _mxarray12_;

static mxChar _array15_[8] = { 'p', 'r', 'e', 's', 's', 'u', 'r', 'e' };
static mxArray * _mxarray14_;

static mxChar _array17_[13] = { 'g', 'l', 'o', 'b', 'a', 'l', 'r',
                                'e', 'f', 's', 'u', 'r', 'f' };
static mxArray * _mxarray16_;

void InitializeModule_zsgetsystem(void) {
    _mxarray0_ = mclInitializeString(8, _array1_);
    _mxarray2_ = mclInitializeString(8, _array3_);
    _mxarray4_ = mclInitializeString(8, _array5_);
    _mxarray6_ = mclInitializeString(12, _array7_);
    _mxarray8_ = mclInitializeString(13, _array9_);
    _mxarray10_ = mclInitializeString(10, _array11_);
    _mxarray12_ = mclInitializeString(4, _array13_);
    _mxarray14_ = mclInitializeString(8, _array15_);
    _mxarray16_ = mclInitializeString(13, _array17_);
}

void TerminateModule_zsgetsystem(void) {
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

static mxArray * Mzsgetsystem(int nargout_);

_mexLocalFunctionTable _local_function_table_zsgetsystem
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsgetsystem" contains the normal interface for the
 * "zsgetsystem" M-function from file "c:\projects\mzdde\zsgetsystem.m" (lines
 * 1-27). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZsgetsystem(void) {
    int nargout = 1;
    mxArray * zsSystemParms = NULL;
    mlfEnterNewContext(0, 0);
    zsSystemParms = Mzsgetsystem(nargout);
    mlfRestorePreviousContext(0, 0);
    return mlfReturnValue(zsSystemParms);
}

/*
 * The function "mlxZsgetsystem" contains the feval interface for the
 * "zsgetsystem" M-function from file "c:\projects\mzdde\zsgetsystem.m" (lines
 * 1-27). The feval function calls the implementation version of zsgetsystem
 * through this function. This function processes any input arguments and
 * passes them to the implementation version of the function, appearing above.
 */
void mlxZsgetsystem(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsgetsystem Line: 1 Column"
            ": 1 The function \"zsgetsystem\" was called with"
            " more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsgetsystem Line: 1 Column"
            ": 1 The function \"zsgetsystem\" was called with"
            " more than the declared number of inputs (0)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    mlfEnterNewContext(0, 0);
    mplhs[0] = Mzsgetsystem(nlhs);
    mlfRestorePreviousContext(0, 0);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsgetsystem" is the implementation version of the
 * "zsgetsystem" M-function from file "c:\projects\mzdde\zsgetsystem.m" (lines
 * 1-27). It contains the actual compiled code for that M-function. It is a
 * static function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function zsSystemParms = zsGetSystem()
 */
static mxArray * Mzsgetsystem(int nargout_) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsgetsystem);
    mxArray * zsSystemParms = NULL;
    mxArray * ZemaxParms = NULL;
    mxArray * ans = NULL;
    /*
     * % zsGetSystem - Get lens system global operating parameters in a struct.
     * %
     * % Usage : zsSystemParms = zsGetSystem
     * % Returns a structure with the following fields.
     * % numsurfs, unitcode, stopsurf, nonaxialflag, rayaimingtype, useenvdata, temp, pressure, globalrefsurf
     * % This structure contains the number of surfaces, the unit code (0, 1, 2, or 3 for mm, cm, in , or M), the stop surf number,
     * % a flag to indicate if the system is non-axial symmetric (0 for false, that is it is axial, or 1 if the system is not axial),
     * % the ray aiming type (0, 1, 2 for none, paraxial, real), the use environment data flag (0 for no, 1 for yes), the current
     * % temperature and pressure, and the global coordinate reference surface number.
     * %
     * % See also zSetSystem, zsSetSystem, zGetSystem
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * ZemaxParms = zGetSystem;
     */
    mlfAssign(&ZemaxParms, mlfZgetsystem());
    /*
     * zsSystemParms = struct('numsurfs',ZemaxParms(1),'unitcode', ZemaxParms(2), 'stopsurf', ZemaxParms(3), 'nonaxialflag', ZemaxParms(4), 'rayaimingtype', ZemaxParms(5), 'useenvdata', ZemaxParms(6), 'temp', ZemaxParms(7), 'pressure', ZemaxParms(8), 'globalrefsurf', ZemaxParms(9));
     */
    mlfAssign(
      &zsSystemParms,
      mlfStruct(
        _mxarray0_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 1),
        _mxarray2_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 2),
        _mxarray4_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 3),
        _mxarray6_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 4),
        _mxarray8_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 5),
        _mxarray10_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 6),
        _mxarray12_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 7),
        _mxarray14_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 8),
        _mxarray16_,
        mclIntArrayRef1(mclVv(ZemaxParms, "ZemaxParms"), 9),
        NULL));
    mclValidateOutput(
      zsSystemParms, 1, nargout_, "zsSystemParms", "zsgetsystem");
    mxDestroyArray(ans);
    mxDestroyArray(ZemaxParms);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return zsSystemParms;
    /*
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     */
}
