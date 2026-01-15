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
#include "zsetsolve.h"
#include "ddereq_mex_interface.h"
#include "libmatlbm.h"

extern mxArray * ZemaxDDEChannel;
extern mxArray * ZemaxDDETimeout;

static mxChar _array1_[17] = { 'S', 'e', 't', 'S', 'o', 'l', 'v', 'e', ',',
                               '%', 'i', ',', '%', 'i', ',', '%', 'i' };
static mxArray * _mxarray0_;
static mxArray * _mxarray3_;
static mxArray * _mxarray2_;

static mxChar _array5_[7] = { ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray4_;
static mxArray * _mxarray7_;
static mxArray * _mxarray6_;

static mxChar _array9_[14] = { ',', '%', '1', '1', '.', '9', 'f',
                               ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray8_;
static mxArray * _mxarray11_;
static mxArray * _mxarray10_;

static mxChar _array13_[21] = { ',', '%', '1', '1', '.', '9', 'f',
                                ',', '%', '1', '1', '.', '9', 'f',
                                ',', '%', '1', '1', '.', '9', 'f' };
static mxArray * _mxarray12_;

static double _array15_[2] = { 1.0, 1.0 };
static mxArray * _mxarray14_;

static mxChar _array17_[14] = { '%', 'f', ',', '%', 'f', ',', '%',
                                'f', ',', '%', 'f', ',', '%', 'f' };
static mxArray * _mxarray16_;

void InitializeModule_zsetsolve(void) {
    _mxarray0_ = mclInitializeString(17, _array1_);
    _mxarray3_ = mclInitializeDouble(1.0);
    _mxarray2_ = mclInitializeCell(_mxarray3_);
    _mxarray4_ = mclInitializeString(7, _array5_);
    _mxarray7_ = mclInitializeDouble(2.0);
    _mxarray6_ = mclInitializeCell(_mxarray7_);
    _mxarray8_ = mclInitializeString(14, _array9_);
    _mxarray11_ = mclInitializeDouble(3.0);
    _mxarray10_ = mclInitializeCell(_mxarray11_);
    _mxarray12_ = mclInitializeString(21, _array13_);
    _mxarray14_ = mclInitializeDoubleVector(1, 2, _array15_);
    _mxarray16_ = mclInitializeString(14, _array17_);
}

void TerminateModule_zsetsolve(void) {
    mxDestroyArray(_mxarray16_);
    mxDestroyArray(_mxarray14_);
    mxDestroyArray(_mxarray12_);
    mxDestroyArray(_mxarray10_);
    mxDestroyArray(_mxarray11_);
    mxDestroyArray(_mxarray8_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mzsetsolve(int nargout_,
                            mxArray * Surface,
                            mxArray * Code,
                            mxArray * SolveType,
                            mxArray * varargin);

_mexLocalFunctionTable _local_function_table_zsetsolve
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfZsetsolve" contains the normal interface for the
 * "zsetsolve" M-function from file "c:\projects\mzdde\zsetsolve.m" (lines
 * 1-50). This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
mxArray * mlfZsetsolve(mxArray * Surface,
                       mxArray * Code,
                       mxArray * SolveType,
                       ...) {
    mxArray * varargin = NULL;
    int nargout = 1;
    mxArray * SolveData = NULL;
    mlfVarargin(&varargin, SolveType, 0);
    mlfEnterNewContext(0, -4, Surface, Code, SolveType, varargin);
    SolveData = Mzsetsolve(nargout, Surface, Code, SolveType, varargin);
    mlfRestorePreviousContext(0, 3, Surface, Code, SolveType);
    mxDestroyArray(varargin);
    return mlfReturnValue(SolveData);
}

/*
 * The function "mlxZsetsolve" contains the feval interface for the "zsetsolve"
 * M-function from file "c:\projects\mzdde\zsetsolve.m" (lines 1-50). The feval
 * function calls the implementation version of zsetsolve through this
 * function. This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxZsetsolve(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[4];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: zsetsolve Line: 1 Column:"
            " 1 The function \"zsetsolve\" was called with m"
            "ore than the declared number of outputs (1)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 3 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 3; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    mprhs[3] = NULL;
    mlfAssign(&mprhs[3], mclCreateVararginCell(nrhs - 3, prhs + 3));
    mplhs[0] = Mzsetsolve(nlhs, mprhs[0], mprhs[1], mprhs[2], mprhs[3]);
    mlfRestorePreviousContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    plhs[0] = mplhs[0];
    mxDestroyArray(mprhs[3]);
}

/*
 * The function "Mzsetsolve" is the implementation version of the "zsetsolve"
 * M-function from file "c:\projects\mzdde\zsetsolve.m" (lines 1-50). It
 * contains the actual compiled code for that M-function. It is a static
 * function and must only be called from one of the interface functions,
 * appearing below.
 */
/*
 * function SolveData = zSetSolve(Surface, Code, SolveType, varargin)
 */
static mxArray * Mzsetsolve(int nargout_,
                            mxArray * Surface,
                            mxArray * Code,
                            mxArray * SolveType,
                            mxArray * varargin) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_zsetsolve);
    int nargin_ = mclNargin(-4, Surface, Code, SolveType, varargin, NULL);
    mxArray * SolveData = NULL;
    mxArray * errmsg = NULL;
    mxArray * count = NULL;
    mxArray * col = NULL;
    mxArray * Reply = NULL;
    mxArray * DDECommand = NULL;
    mxArray * Numerics = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&Surface);
    mclCopyArray(&Code);
    mclCopyArray(&SolveType);
    mclCopyArray(&varargin);
    /*
     * % zSetSolve - Sets data for solves and/or pickups on lens surfaces.
     * %
     * % Usage : SolveData = zSetSolve(Surface, Code, SolveType, Parameter1, ...)
     * %
     * % where Surface is the surface number at which the solve is to be set and Code is
     * % an integer code indicating which parameter the solve data is for. The solve data is specified in the following
     * % formats, depending upon the code value according to the following table. The solve takes up to
     * % three parameters, also depending on the type of solve.
     * % ------------------------|------------------------------------------------|
     * % zSetSolve Code         -|- Returned data format                          |
     * % ------------------------|------------------------------------------------|
     * % 0, curvature           -|- solvetype, parameter1, parameter2             |
     * % 1, thickness           -|- solvetype, parameter1, parameter2, parameter3 |
     * % 2, glass               -|- solvetype, pickupsurf                         |
     * % 3, semi-diameter       -|- solvetype, pickupsurf                         |
     * % 4, conic               -|- solvetype, pickupsurf                         |
     * % 5-12, parameters 1-8   -|- solvetype, pickupsurf, offset, scalefactor    |
     * % 1001+, extra data values|- solvetype, pickupsurf, scalefactor            |
     * %-------------------------|------------------------------------------------|
     * % The solvetype is an integer code, and the parameters have meanings that depend upon the solve type; see
     * % the chapter "Solves" for details. The Introduction gives a summary for the various solve types.
     * % Note that code 5 corresponds to parameter 1, not 0. It is not possible to set a solve on parameter
     * % number 0.
     * %
     * % See also zGetSolve.
     * %
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.2 $
     * 
     * global ZemaxDDEChannel ZemaxDDETimeout
     * % Decide how many parameters there should be in the input arguments.
     * %switch Code
     * %  case {0},       Numerics = 2; 
     * %  case {2, 3, 4}, Numerics = 1;
     * %  case {1, 5, 6, 7, 8, 9, 10, 11, 12}, Numerics = 3;
     * %  otherwise,      Numerics = 2;
     * %end
     * Numerics = nargin - 3; % Rely on the user to pass the correct number of parameters
     */
    mlfAssign(&Numerics, mlfScalar(nargin_ - 3));
    /*
     * DDECommand = sprintf('SetSolve,%i,%i,%i', Surface, Code, SolveType);
     */
    mlfAssign(
      &DDECommand,
      mlfSprintf(
        NULL,
        _mxarray0_,
        mclVa(Surface, "Surface"),
        mclVa(Code, "Code"),
        mclVa(SolveType, "SolveType"),
        NULL));
    /*
     * switch Numerics
     */
    {
        mxArray * v_ = mclInitialize(mclVv(Numerics, "Numerics"));
        if (mclSwitchCompare(v_, _mxarray2_)) {
            /*
             * case {1}, DDECommand = [DDECommand sprintf(',%11.9f', varargin{1})];
             */
            mlfAssign(
              &DDECommand,
              mlfHorzcat(
                mclVv(DDECommand, "DDECommand"),
                mlfSprintf(
                  NULL,
                  _mxarray4_,
                  mlfIndexRef(mclVa(varargin, "varargin"), "{?}", _mxarray3_),
                  NULL),
                NULL));
        /*
         * case {2}, DDECommand = [DDECommand sprintf(',%11.9f,%11.9f', varargin{1}, varargin{2})];
         */
        } else if (mclSwitchCompare(v_, _mxarray6_)) {
            mlfAssign(
              &DDECommand,
              mlfHorzcat(
                mclVv(DDECommand, "DDECommand"),
                mlfSprintf(
                  NULL,
                  _mxarray8_,
                  mlfIndexRef(mclVa(varargin, "varargin"), "{?}", _mxarray3_),
                  mlfIndexRef(mclVa(varargin, "varargin"), "{?}", _mxarray7_),
                  NULL),
                NULL));
        /*
         * case {3}, DDECommand = [DDECommand sprintf(',%11.9f,%11.9f,%11.9f', varargin{1}, varargin{2}, varargin{3})];
         */
        } else if (mclSwitchCompare(v_, _mxarray10_)) {
            mlfAssign(
              &DDECommand,
              mlfHorzcat(
                mclVv(DDECommand, "DDECommand"),
                mlfSprintf(
                  NULL,
                  _mxarray12_,
                  mlfIndexRef(mclVa(varargin, "varargin"), "{?}", _mxarray3_),
                  mlfIndexRef(mclVa(varargin, "varargin"), "{?}", _mxarray7_),
                  mlfIndexRef(mclVa(varargin, "varargin"), "{?}", _mxarray11_),
                  NULL),
                NULL));
        /*
         * end
         */
        }
        mxDestroyArray(v_);
    }
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
        _mxarray14_,
        mclVg(&ZemaxDDETimeout, "ZemaxDDETimeout"),
        NULL));
    /*
     * [col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f', Numerics+1);
     */
    mlfAssign(
      &col,
      mlfSscanf(
        &count,
        &errmsg,
        NULL,
        mclVv(Reply, "Reply"),
        _mxarray16_,
        mclPlus(mclVv(Numerics, "Numerics"), _mxarray3_)));
    /*
     * SolveData = col';
     */
    mlfAssign(&SolveData, mlfCtranspose(mclVv(col, "col")));
    mclValidateOutput(SolveData, 1, nargout_, "SolveData", "zsetsolve");
    mxDestroyArray(ans);
    mxDestroyArray(Numerics);
    mxDestroyArray(DDECommand);
    mxDestroyArray(Reply);
    mxDestroyArray(col);
    mxDestroyArray(count);
    mxDestroyArray(errmsg);
    mxDestroyArray(varargin);
    mxDestroyArray(SolveType);
    mxDestroyArray(Code);
    mxDestroyArray(Surface);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return SolveData;
}
