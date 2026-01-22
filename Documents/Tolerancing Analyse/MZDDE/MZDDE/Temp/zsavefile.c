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
#include "zsavefile.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"
#include "libmmfile.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[11] = { 'S', 'a', 'v', 'e', 'F', 'i',
                               'l', 'e', ',', '%', 's' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

void InitializeModule_zsavefile(void) {
    _mxarray0_ = mclInitializeString(11, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
}

void TerminateModule_zsavefile(void) {
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsavefile(int nargout_, mxArray * FileName);

_mexLocalFunctionTable _local_function_table_zsavefile
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsavefile" contains the normal interface for the
 * "zsavefile" M-function from file "c:\projects\mzdde\zsavefile.m" (lines
 * 1-19). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZsavefile(mxArray * FileName) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 1, FileName);
    Status = Mzsavefile(nargout, FileName);
    mlfRestorePreviousContext(0, 1, FileName);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxZsavefile" contains the feval interface for the "zsavefile"
 * M-function from file "c:\projects\mzdde\zsavefile.m" (lines 1-19). The feval
 * function calls the implementation version of zsavefile through this
 * function. This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZsavefile(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsavefile Line: 1 Column:"
            " 1 The function \"zsavefile\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsavefile Line: 1 Column:"
            " 1 The function \"zsavefile\" was called with m"
            "ore than the declared number of inputs (1)."),
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
    mplhs[0] = Mzsavefile(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsavefile" is the implementation version of the "zsavefile"
 * M-function from file "c:\projects\mzdde\zsavefile.m" (lines 1-19). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function Status = zSaveFile(FileName)
 */
static mxArray * Mzsavefile(int nargout_, mxArray * FileName) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsavefile);
    mxArray * Status = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&FileName);
    /*
     * % zSaveFile - Save the lens in the ZEMAX DDE server to a file.
     * %
     * % Usage : Status = zSaveFile(FileName)
     * % Saves the lens currently loaded in the server to a ZEMAX file. The file name to be used for the save
     * % must include the full path. For example: zSaveFile('C:\ZEMAX\SAMPLES\COOKE.ZMX'). The returned string 
     * % is the same as for the zGetUpdate item; after updating the newly saved
     * % lens file. If a value other than 0 is returned, the Update failed, if -999 is returned, the file could not be saved. 
     * %
     * % See also zGetPath, zGetRefresh, zLoadFile, and zPushLens.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SaveFile,%s',FileName);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(NULL, _mxarray0_, mclVa(FileName, "FileName"), NULL));
    /*
     * Status = str2num(ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout));
     */
    mlfAssign(
      &Status,
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
    mclValidateOutput(Status, 1, nargout_, "Status", "zsavefile");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(FileName);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
}
