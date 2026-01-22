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
#include "zsetfield.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[67] = { 'S', 'e', 't', 'F', 'i', 'e', 'l', 'd', ',', '%',
                               'i', ',', '%', '1', '1', '.', '9', 'f', ',', '%',
                               '1', '1', '.', '9', 'f', ',', '%', '1', '1', '.',
                               '9', 'f', ',', '%', '1', '1', '.', '9', 'f', ',',
                               '%', '1', '1', '.', '9', 'f', ',', '%', '1', '1',
                               '.', '9', 'f', ',', '%', '1', '1', '.', '9', 'f',
                               ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

static mxChar _array5_[23] = { '%', 'f', ',', '%', 'f', ',', '%', 'f',
                               ',', '%', 'f', ',', '%', 'f', ',', '%',
                               'f', ',', '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray4_;

void InitializeModule_zsetfield(void) {
    _mxarray0_ = mclInitializeString(67, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeString(23, _array5_);
}

void TerminateModule_zsetfield(void) {
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetfield(int nargout_,
                            mxArray * n,
                            mxArray * xf,
                            mxArray * yf,
                            mxArray * wgt,
                            mxArray * vdx,
                            mxArray * vdy,
                            mxArray * vcx,
                            mxArray * vcy,
                            mxArray * van);

_mexLocalFunctionTable _local_function_table_zsetfield
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetfield" contains the normal interface for the
 * "zsetfield" M-function from file "c:\projects\mzdde\zsetfield.m" (lines
 * 1-22). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZsetfield(mxArray * n,
                       mxArray * xf,
                       mxArray * yf,
                       mxArray * wgt,
                       mxArray * vdx,
                       mxArray * vdy,
                       mxArray * vcx,
                       mxArray * vcy,
                       mxArray * van) {
    int nargout = 1;
    mxArray * FieldData = NULL;
    mlfEnterNewContext(0, 9, n, xf, yf, wgt, vdx, vdy, vcx, vcy, van);
    FieldData = Mzsetfield(nargout, n, xf, yf, wgt, vdx, vdy, vcx, vcy, van);
    mlfRestorePreviousContext(0, 9, n, xf, yf, wgt, vdx, vdy, vcx, vcy, van);
    return mlfReturnValue(FieldData);
}

/*
 * The function "mlxZsetfield" contains the feval interface for the "zsetfield"
 * M-function from file "c:\projects\mzdde\zsetfield.m" (lines 1-22). The feval
 * function calls the implementation version of zsetfield through this
 * function. This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZsetfield(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[9];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetfield Line: 1 Column:"
            " 1 The function \"zsetfield\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 9) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetfield Line: 1 Column:"
            " 1 The function \"zsetfield\" was called with m"
            "ore than the declared number of inputs (9)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 9 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 9; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(
      0,
      9,
      mprhs[0],
      mprhs[1],
      mprhs[2],
      mprhs[3],
      mprhs[4],
      mprhs[5],
      mprhs[6],
      mprhs[7],
      mprhs[8]);
    mplhs[0]
      = Mzsetfield(
          nlhs,
          mprhs[0],
          mprhs[1],
          mprhs[2],
          mprhs[3],
          mprhs[4],
          mprhs[5],
          mprhs[6],
          mprhs[7],
          mprhs[8]);
    mlfRestorePreviousContext(
      0,
      9,
      mprhs[0],
      mprhs[1],
      mprhs[2],
      mprhs[3],
      mprhs[4],
      mprhs[5],
      mprhs[6],
      mprhs[7],
      mprhs[8]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetfield" is the implementation version of the "zsetfield"
 * M-function from file "c:\projects\mzdde\zsetfield.m" (lines 1-22). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function FieldData = zSetField(n, xf, yf, wgt, vdx, vdy, vcx, vcy, van)
 */
static mxArray * Mzsetfield(int nargout_,
                            mxArray * n,
                            mxArray * xf,
                            mxArray * yf,
                            mxArray * wgt,
                            mxArray * vdx,
                            mxArray * vdy,
                            mxArray * vcx,
                            mxArray * vcy,
                            mxArray * van) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetfield);
    mxArray * FieldData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&n);
    mclCopyArray(&xf);
    mclCopyArray(&yf);
    mclCopyArray(&wgt);
    mclCopyArray(&vdx);
    mclCopyArray(&vdy);
    mclCopyArray(&vcx);
    mclCopyArray(&vcy);
    mclCopyArray(&van);
    /*
     * % zSetField - Sets field data for a particular field point.
     * %
     * % Usage : FieldData = zSetField(n, xf, yf, wgt, vdx, vdy, vcx, vcy, van)
     * %
     * % If n is a valid field number (between 1 and the number of fields, inclusive) then the field x and y values, field weight,
     * % and vignetting factors are all set.  The returned row vector is the same as for zGetField.
     * %
     * % See also zGetField
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SetField,%i,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f',n, xf, yf, wgt, vdx, vdy, vcx, vcy, van);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mclVa(n, "n"),
        mclVa(xf, "xf"),
        mclVa(yf, "yf"),
        mclVa(wgt, "wgt"),
        mclVa(vdx, "vdx"),
        mclVa(vdy, "vdy"),
        mclVa(vcx, "vcx"),
        mclVa(vcy, "vcy"),
        mclVa(van, "van"),
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
     * [col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f');
     */
    mlfAssign(
      &col,
      mlfSscanf(
        &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray4_, NULL));
    /*
     * FieldData = col';
     */
    mlfAssign(&FieldData, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(FieldData, 1, nargout_, "FieldData", "zsetfield");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(van);
    mxDestroyArray(vcy);
    mxDestroyArray(vcx);
    mxDestroyArray(vdy);
    mxDestroyArray(vdx);
    mxDestroyArray(wgt);
    mxDestroyArray(yf);
    mxDestroyArray(xf);
    mxDestroyArray(n);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return FieldData;
    /*
     * 
     * 
     */
}
