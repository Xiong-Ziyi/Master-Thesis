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
#include "zfindlabel.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "libmmfile.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[12] = { 'F', 'i', 'n', 'd', 'L', 'a',
                               'b', 'e', 'l', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

void InitializeModule_zfindlabel(void) {
    _mxarray0_ = mclInitializeString(12, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
}

void TerminateModule_zfindlabel(void) {
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzfindlabel(int nargout_, mxArray * Label);

_mexLocalFunctionTable _local_function_table_zfindlabel
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZfindlabel" contains the normal interface for the
 * "zfindlabel" M-function from file "c:\projects\mzdde\zfindlabel.m" (lines
 * 1-22). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZfindlabel(mxArray * Label) {
    int nargout = 1;
    mxArray * Surface = NULL;
    mlfEnterNewContext(0, 1, Label);
    Surface = Mzfindlabel(nargout, Label);
    mlfRestorePreviousContext(0, 1, Label);
    return mlfReturnValue(Surface);
}

/*
 * The function "mlxZfindlabel" contains the feval interface for the
 * "zfindlabel" M-function from file "c:\projects\mzdde\zfindlabel.m" (lines
 * 1-22). The feval function calls the implementation version of zfindlabel
 * through this function. This function processes any input arguments and
 * passes them to the implementation version of the function, appearing above.
 */
void mlxZfindlabel(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zfindlabel Line: 1 Column:"
            " 1 The function \"zfindlabel\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zfindlabel Line: 1 Column"
            ": 1 The function \"zfindlabel\" was called with"
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
    mplhs[0] = Mzfindlabel(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzfindlabel" is the implementation version of the "zfindlabel"
 * M-function from file "c:\projects\mzdde\zfindlabel.m" (lines 1-22). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function Surface = zFindLabel(Label)
 */
static mxArray * Mzfindlabel(int nargout_, mxArray * Label) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zfindlabel);
    mxArray * Surface = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&Label);
    /*
     * % zFindLabel - Finds a previously labeled surface in the Zemax DDE client lens.
     * %
     * % Example : 
     * % LabeledSurface = zFindLabel(10)
     * %
     * % Finds the surface number which was labeled number 10 using the zSetLabel function.
     * %
     * % The returned value is the surface number of the first surface with the identical integer label, or -1 
     * % if no surface has the specified label. 
     * %
     * % See also zSetLabel and zGetLabel.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('FindLabel,%i',Label);
     */
    mlfAssign(
      &DDECommand, mlfSprintf(NULL, _mxarray0_, mclVa(Label, "Label"), NULL));
    /*
     * Surface = str2num(ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout));
     */
    mlfAssign(
      &Surface,
      mlfStr2num(
        NULL,
        mlfNDdereq(
          0,
          mclValueVarargout(),
          mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
          mclVv(DDECommand, "DDECommand"),
          _mxarray2_,
          mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
          NULL)));
    mclValidateOutput(Surface, 1, nargout_, "Surface", "zfindlabel");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Label);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Surface;
    /*
     * 
     */
}
