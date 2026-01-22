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
#include "zsetfieldmatrix.h"
#include "libmatlbm.h"
#include "zsetfield.h"
#include "zsetfieldtype.h"
static mxArray * _mxarray0_;
static mxArray * _mxarray1_;
static mxArray * _mxarray2_;
static mxArray * _mxarray3_;
static mxArray * _mxarray4_;
static mxArray * _mxarray5_;

void InitializeModule_zsetfieldmatrix(void) {
    _mxarray0_ = mclInitializeDouble(1.0);
    _mxarray1_ = mclInitializeDouble(2.0);
    _mxarray2_ = mclInitializeDouble(12.0);
    _mxarray3_ = mclInitializeDouble(0.0);
    _mxarray4_ = mclInitializeDouble(8.0);
    _mxarray5_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
}

void TerminateModule_zsetfieldmatrix(void) {
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray1_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetfieldmatrix(int nargout_,
                                  mxArray * FieldType,
                                  mxArray * FieldDataMatrix);

_mexLocalFunctionTable _local_function_table_zsetfieldmatrix
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetfieldmatrix" contains the normal interface for the
 * "zsetfieldmatrix" M-function from file "c:\projects\mzdde\zsetfieldmatrix.m"
 * (lines 1-36). This function processes any input arguments and passes them to
 * the implementation version of the function, appearing above.
 */
mxArray * mlfZsetfieldmatrix(mxArray * FieldType, mxArray * FieldDataMatrix) {
    int nargout = 1;
    mxArray * FieldPoints = NULL;
    mlfEnterNewContext(0, 2, FieldType, FieldDataMatrix);
    FieldPoints = Mzsetfieldmatrix(nargout, FieldType, FieldDataMatrix);
    mlfRestorePreviousContext(0, 2, FieldType, FieldDataMatrix);
    return mlfReturnValue(FieldPoints);
}

/*
 * The function "mlxZsetfieldmatrix" contains the feval interface for the
 * "zsetfieldmatrix" M-function from file "c:\projects\mzdde\zsetfieldmatrix.m"
 * (lines 1-36). The feval function calls the implementation version of
 * zsetfieldmatrix through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
void mlxZsetfieldmatrix(int nlhs,
                        mxArray * plhs[],
                        int nrhs,
                        mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetfieldmatrix Line: 1 Colum"
            "n: 1 The function \"zsetfieldmatrix\" was called wi"
            "th more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetfieldmatrix Line: 1 Colum"
            "n: 1 The function \"zsetfieldmatrix\" was called wi"
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
    mplhs[0] = Mzsetfieldmatrix(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mzsetfieldmatrix" is the implementation version of the
 * "zsetfieldmatrix" M-function from file "c:\projects\mzdde\zsetfieldmatrix.m"
 * (lines 1-36). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function FieldPoints = zSetFieldMatrix(FieldType, FieldDataMatrix)
 */
static mxArray * Mzsetfieldmatrix(int nargout_,
                                  mxArray * FieldType,
                                  mxArray * FieldDataMatrix) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(
          &_local_function_table_zsetfieldmatrix);
    mxArray * FieldPoints = NULL;
    mxArray * iii = NULL;
    mxArray * ans = NULL;
    mxArray * ColCount = NULL;
    mxArray * FieldCount = NULL;
    mclCopyArray(&FieldType);
    mclCopyArray(&FieldDataMatrix);
    /*
     * % zSetFieldMatrix - sets all field points from a matrix
     * %
     * % Usage : FieldPoints = zSetFieldMatrix(FieldType, FieldDataMatrix)
     * %
     * % Create and pass a matrix having columns 8 columns of field data xf, yf, wgt, vdx, vdy, vcx, vcy, van
     * % If the matrix has fewer columns, it will be assumed that columns on the right are zero.
     * % The matrix can have from 1 to 12 rows.
     * % The function returns the number of field points set.
     * % The parameter FieldType is an integer; either 0, 1, or 2, for angles in degrees, object height, or paraxial image height,
     * % respectively, 3 for real image height.
     * %
     * % See also zGetField, zSetField
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.1 $
     * 
     * FieldCount = size(FieldDataMatrix,1);
     */
    mlfAssign(
      &FieldCount,
      mlfSize(
        mclValueVarargout(),
        mclVa(FieldDataMatrix, "FieldDataMatrix"),
        _mxarray0_));
    /*
     * ColCount = size(FieldDataMatrix,2);
     */
    mlfAssign(
      &ColCount,
      mlfSize(
        mclValueVarargout(),
        mclVa(FieldDataMatrix, "FieldDataMatrix"),
        _mxarray1_));
    /*
     * if (FieldCount > 12) FieldCount = 12; end;
     */
    if (mclGtBool(mclVv(FieldCount, "FieldCount"), _mxarray2_)) {
        mlfAssign(&FieldCount, _mxarray2_);
    }
    /*
     * if (FieldCount <= 0) FieldPoints = 0; return; end;
     */
    if (mclLeBool(mclVv(FieldCount, "FieldCount"), _mxarray3_)) {
        mlfAssign(&FieldPoints, _mxarray3_);
        goto return_;
    }
    /*
     * zSetFieldType(FieldType, FieldCount);
     */
    mclAssignAns(
      &ans,
      mlfZsetfieldtype(
        mclVa(FieldType, "FieldType"), mclVv(FieldCount, "FieldCount")));
    /*
     * if (ColCount < 8)
     */
    if (mclLtBool(mclVv(ColCount, "ColCount"), _mxarray4_)) {
        mclForLoopIterator viter__;
        /*
         * for iii = (ColCount+1):8,
         */
        for (mclForStart(
               &viter__,
               mclPlus(mclVv(ColCount, "ColCount"), _mxarray0_),
               _mxarray4_,
               NULL);
             mclForNext(&viter__, &iii);
             ) {
            /*
             * FieldDataMatrix(:,iii) = 0;
             */
            mclArrayAssign2(
              &FieldDataMatrix,
              _mxarray3_,
              mlfCreateColonIndex(),
              mclVv(iii, "iii"));
        /*
         * end
         */
        }
        mclDestroyForLoopIterator(viter__);
    /*
     * end
     */
    }
    /*
     * for iii = 1:FieldCount,
     */
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mclVv(FieldCount, "FieldCount"));
        if (v_ > e_) {
            mlfAssign(&iii, _mxarray5_);
        } else {
            /*
             * zSetField(iii, FieldDataMatrix(iii,1),FieldDataMatrix(iii,2),FieldDataMatrix(iii,3),FieldDataMatrix(iii,4),FieldDataMatrix(iii,5),FieldDataMatrix(iii,6),FieldDataMatrix(iii,7),FieldDataMatrix(iii,8));
             * end
             */
            for (; ; ) {
                mclAssignAns(
                  &ans,
                  mlfZsetfield(
                    mlfScalar(v_),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 1),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 2),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 3),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 4),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 5),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 6),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 7),
                    mclIntArrayRef2(
                      mclVa(FieldDataMatrix, "FieldDataMatrix"), v_, 8)));
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            mlfAssign(&iii, mlfScalar(v_));
        }
    }
    /*
     * FieldPoints = FieldCount;
     */
    mlfAssign(&FieldPoints, mclVv(FieldCount, "FieldCount"));
    /*
     * 
     * 
     * 
     */
    return_:
    mclValidateOutput(
      FieldPoints, 1, nargout_, "FieldPoints", "zsetfieldmatrix");
    mxDestroyArray(FieldCount);
    mxDestroyArray(ColCount);
    mxDestroyArray(ans);
    mxDestroyArray(iii);
    mxDestroyArray(FieldDataMatrix);
    mxDestroyArray(FieldType);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return FieldPoints;
}
