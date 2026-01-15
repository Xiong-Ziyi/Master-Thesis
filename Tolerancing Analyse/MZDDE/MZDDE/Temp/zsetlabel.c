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
#include "zsetlabel.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "libmmfile.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[14] = { 'S', 'e', 't', 'L', 'a', 'b', 'e',
                               'l', ',', '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

void InitializeModule_zsetlabel(void) {
    _mxarray0_ = mclInitializeString(14, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
}

void TerminateModule_zsetlabel(void) {
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetlabel(int nargout_,
                            mxArray * SurfaceNumber,
                            mxArray * LabelNumber);

_mexLocalFunctionTable _local_function_table_zsetlabel
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetlabel" contains the normal interface for the
 * "zsetlabel" M-function from file "c:\projects\mzdde\zsetlabel.m" (lines
 * 1-17). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZsetlabel(mxArray * SurfaceNumber, mxArray * LabelNumber) {
    int nargout = 1;
    mxArray * Label = NULL;
    mlfEnterNewContext(0, 2, SurfaceNumber, LabelNumber);
    Label = Mzsetlabel(nargout, SurfaceNumber, LabelNumber);
    mlfRestorePreviousContext(0, 2, SurfaceNumber, LabelNumber);
    return mlfReturnValue(Label);
}

/*
 * The function "mlxZsetlabel" contains the feval interface for the "zsetlabel"
 * M-function from file "c:\projects\mzdde\zsetlabel.m" (lines 1-17). The feval
 * function calls the implementation version of zsetlabel through this
 * function. This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZsetlabel(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetlabel Line: 1 Column:"
            " 1 The function \"zsetlabel\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetlabel Line: 1 Column:"
            " 1 The function \"zsetlabel\" was called with m"
            "ore than the declared number of inputs (2)."),
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
    mplhs[0] = Mzsetlabel(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetlabel" is the implementation version of the "zsetlabel"
 * M-function from file "c:\projects\mzdde\zsetlabel.m" (lines 1-17). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function Label = zSetLabel(SurfaceNumber,LabelNumber)
 */
static mxArray * Mzsetlabel(int nargout_,
                            mxArray * SurfaceNumber,
                            mxArray * LabelNumber) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetlabel);
    mxArray * Label = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&SurfaceNumber);
    mclCopyArray(&LabelNumber);
    /*
     * % zSetLabel - Attach an integer label to a surface in the ZEMAX lens.
     * %
     * % zSetLabel(SurfaceNumber, LabelNumber)
     * % The returned value is the label.
     * % 
     * % See also : zGetLabel, zFindLabel
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SetLabel,%i,%i',SurfaceNumber,LabelNumber);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mclVa(SurfaceNumber, "SurfaceNumber"),
        mclVa(LabelNumber, "LabelNumber"),
        NULL));
    /*
     * Label = str2num(ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout));
     */
    mlfAssign(
      &Label,
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
    mclValidateOutput(Label, 1, nargout_, "Label", "zsetlabel");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(LabelNumber);
    mxDestroyArray(SurfaceNumber);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Label;
    /*
     * 
     */
}
