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
#include "zsetfieldtype.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[16] = { 'S', 'e', 't', 'F', 'i', 'e', 'l', 'd',
                               ',', '0', ',', '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray0_;

static double _array3_[2] = { 1.0, 1.0 };
static mxArray * _mxarray2_;

static mxChar _array5_[5] = { '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray4_;

void InitializeModule_zsetfieldtype(void) {
    _mxarray0_ = mclInitializeString(16, _array1_);
    _mxarray2_ = mclInitializeDoubleVector(1, 2, _array3_);
    _mxarray4_ = mclInitializeString(5, _array5_);
}

void TerminateModule_zsetfieldtype(void) {
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetfieldtype(int nargout_,
                                mxArray * FieldType,
                                mxArray * FieldNumber);

_mexLocalFunctionTable _local_function_table_zsetfieldtype
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetfieldtype" contains the normal interface for the
 * "zsetfieldtype" M-function from file "c:\projects\mzdde\zsetfieldtype.m"
 * (lines 1-23). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZsetfieldtype(mxArray * FieldType, mxArray * FieldNumber) {
    int nargout = 1;
    mxArray * FieldData = NULL;
    mlfEnterNewContext(0, 2, FieldType, FieldNumber);
    FieldData = Mzsetfieldtype(nargout, FieldType, FieldNumber);
    mlfRestorePreviousContext(0, 2, FieldType, FieldNumber);
    return mlfReturnValue(FieldData);
}

/*
 * The function "mlxZsetfieldtype" contains the feval interface for the
 * "zsetfieldtype" M-function from file "c:\projects\mzdde\zsetfieldtype.m"
 * (lines 1-23). The feval function calls the implementation version of
 * zsetfieldtype through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZsetfieldtype(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetfieldtype Line: 1 Column"
            ": 1 The function \"zsetfieldtype\" was called with"
            " more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetfieldtype Line: 1 Colum"
            "n: 1 The function \"zsetfieldtype\" was called wi"
            "th more than the declared number of inputs (2)."),
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
    mplhs[0] = Mzsetfieldtype(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetfieldtype" is the implementation version of the
 * "zsetfieldtype" M-function from file "c:\projects\mzdde\zsetfieldtype.m"
 * (lines 1-23). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function FieldData = zSetFieldType(FieldType, FieldNumber)
 */
static mxArray * Mzsetfieldtype(int nargout_,
                                mxArray * FieldType,
                                mxArray * FieldNumber) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetfieldtype);
    mxArray * FieldData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&FieldType);
    mclCopyArray(&FieldNumber);
    /*
     * % zSetFieldType - Sets field type and number of field points.
     * %
     * % Usage : FieldData = zSetField(FieldType, FieldNumber)
     * % The parameter FieldType is an integer; either 0, 1, or 2, for angles in degrees, object height, or paraxial image height,
     * % respectively, 3 for real image height. The parameter FieldNumber is the number of fields to be defined using zSetField.
     * % The function returns FieldType and FieldNumber in a row vector.
     * %
     * % See also zSetField, zGetField.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * DDECommand = sprintf('SetField,0,%i,%i',FieldType, FieldNumber);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mclVa(FieldType, "FieldType"),
        mclVa(FieldNumber, "FieldNumber"),
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
     * [col, count, errmsg] = sscanf(Reply, '%i,%i');
     */
    mlfAssign(
      &col,
      mlfSscanf(
        &count, &errmsg, NULL, mclVv(Reply, "Reply"), _mxarray4_, NULL));
    /*
     * FieldData = col';
     */
    mlfAssign(&FieldData, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(FieldData, 1, nargout_, "FieldData", "zsetfieldtype");
    mxDestroyArray(ans);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(FieldNumber);
    mxDestroyArray(FieldType);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return FieldData;
    /*
     * 
     * 
     * 
     */
}
