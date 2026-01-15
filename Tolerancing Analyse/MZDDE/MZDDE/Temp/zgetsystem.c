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
#include "zgetsystem.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[9] = { 'G', 'e', 't', 'S', 'y', 's', 't', 'e', 'm' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

static mxChar _array5_[26] = { '%', 'f', ',', '%', 'f', ',', '%', 'f', ',',
                               '%', 'f', ',', '%', 'f', ',', '%', 'f', ',',
                               '%', 'f', ',', '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray4_;

void InitializeModule_zgetsystem(void) {
    _mxarray0_ = mclInitializeString(9, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeString(26, _array5_);
}

void TerminateModule_zgetsystem(void) {
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzgetsystem(int nargout_);

_mexLocalFunctionTable _local_function_table_zgetsystem
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZgetsystem" contains the normal interface for the
 * "zgetsystem" M-function from file "c:\projects\mzdde\zgetsystem.m" (lines
 * 1-21). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZgetsystem(void) {
    int nargout = 1;
    mxArray * SystemData = NULL;
    mlfEnterNewContext(0, 0);
    SystemData = Mzgetsystem(nargout);
    mlfRestorePreviousContext(0, 0);
    return mlfReturnValue(SystemData);
}

/*
 * The function "mlxZgetsystem" contains the feval interface for the
 * "zgetsystem" M-function from file "c:\projects\mzdde\zgetsystem.m" (lines
 * 1-21). The feval function calls the implementation version of zgetsystem
 * through this function. This function processes any input arguments and
 * passes them to the implementation version of the function, appearing above.
 */
void mlxZgetsystem(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zgetsystem Line: 1 Column:"
            " 1 The function \"zgetsystem\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zgetsystem Line: 1 Column"
            ": 1 The function \"zgetsystem\" was called with"
            " more than the declared number of inputs (0)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    mlfEnterNewContext(0, 0);
    mplhs[0] = Mzgetsystem(nlhs);
    mlfRestorePreviousContext(0, 0);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzgetsystem" is the implementation version of the "zgetsystem"
 * M-function from file "c:\projects\mzdde\zgetsystem.m" (lines 1-21). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function SystemData = zGetSystem()
 */
static mxArray * Mzgetsystem(int nargout_) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zgetsystem);
    mxArray * SystemData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * ParmsCol = NULL;
    mxArray * Reply = NULL;
    mxArray * ans = NULL;
    /*
     * % zGetSystem - Gets a number of lens system operating data.
     * %
     * % Usage : SystemData = zGetSystem
     * % The returned row vector  is formatted as follows:
     * % numsurfs, unitcode, stopsurf, nonaxialflag, rayaimingtype, useenvdata, temp, pressure, globalrefsurf
     * % This item returns the number of surfaces, the unit code (0, 1, 2, or 3 for mm, cm, in , or M), the stop surf number,
     * % a flag to indicate if the system is non-axial symmetric (0 for false, that is it is axial, or 1 if the system is not axial),
     * % the ray aiming type (0, 1, 2 for none, paraxial, real), the use environment data flag (0 for no, 1 for yes), the current
     * % temperature and pressure, and the global coordinate reference surface number.
     * %
     * % See also zSetSystem and zGetSystemAper
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * Reply = ddereq(ZemaxDDEChannel, 'GetSystem', [1 1], ZemaxDDETimeout);
     */
    mlfAssign(
      &Reply,
      mlfNDdereq(
        0,
        mclValueVarargout(),
        mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
        _mxarray0_,
        _mxarray2_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    /*
     * [ParmsCol,count,errmsg]= sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f,%f');
     */
    mlfAssign(
      &ParmsCol,
      mlfSscanf(
        &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray4_, NULL));
    /*
     * SystemData = ParmsCol';
     */
    mlfAssign(&SystemData, mlfCtranspose(mclVv(ParmsCol, "ParmsCol")));
    mclValidateOutput(SystemData, 1, nargout_, "SystemData", "zgetsystem");
    mxDestroyArray(ans);
    mxDestroyArray(Reply);
    mxDestroyArray(ParmsCol);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return SystemData;
}
