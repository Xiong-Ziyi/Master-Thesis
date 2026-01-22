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
#include "zddeclose.h"
#include "ddeterm_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;

void InitializeModule_zddeclose(void) {
}

void TerminateModule_zddeclose(void) {
}

static mxArray * Mzddeclose(int nargout_);

_mexLocalFunctionTable _local_function_table_zddeclose
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZddeclose" contains the normal interface for the
 * "zddeclose" M-function from file "c:\projects\mzdde\zddeclose.m" (lines
 * 1-14). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZddeclose(void) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 0);
    Status = Mzddeclose(nargout);
    mlfRestorePreviousContext(0, 0);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxZddeclose" contains the feval interface for the "zddeclose"
 * M-function from file "c:\projects\mzdde\zddeclose.m" (lines 1-14). The feval
 * function calls the implementation version of zddeclose through this
 * function. This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZddeclose(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zddeclose Line: 1 Column:"
            " 1 The function \"zddeclose\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zddeclose Line: 1 Column:"
            " 1 The function \"zddeclose\" was called with m"
            "ore than the declared number of inputs (0)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    mlfEnterNewContext(0, 0);
    mplhs[0] = Mzddeclose(nlhs);
    mlfRestorePreviousContext(0, 0);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzddeclose" is the implementation version of the "zddeclose"
 * M-function from file "c:\projects\mzdde\zddeclose.m" (lines 1-14). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function Status = zDDEClose()
 */
static mxArray * Mzddeclose(int nargout_) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zddeclose);
    mxArray * Status = NULL;
    mxArray * ans = NULL;
    /*
     * % zDDEClose - Close the DDEchannel to ZEMAX.
     * %
     * % Usage : Reply = zDDEClose
     * % Returns zero on success.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.1 $
     * 
     * global ZemaxDDEChannel
     * Status = ddeterm(ZemaxDDEChannel);
     */
    mlfAssign(
      &Status,
      mlfNDdeterm(
        0,
        mclValueVarargout(),
        mclVg(&ZemaxDDEChannel, "ZemaxDDEChannel"),
        NULL));
    mclValidateOutput(Status, 1, nargout_, "Status", "zddeclose");
    mxDestroyArray(ans);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
    /*
     * 
     */
}
