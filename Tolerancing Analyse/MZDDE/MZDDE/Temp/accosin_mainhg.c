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

#ifndef MLF_V2
#define MLF_V2 1
#endif

#include "libmatlb.h"
#include "libsgl.h"
#include "accosin.h"
#include "zddeinit.h"
#include "zdeletesurface.h"
#include "zfindlabel.h"
#include "zgetaperture.h"
#include "zinsertsurface.h"
#include "znewlens.h"
#include "zpushlens.h"
#include "zsavefile.h"
#include "zsetaperture.h"
#include "zsetfieldmatrix.h"
#include "zsetlabel.h"
#include "zsetprimarywave.h"
#include "zsetsolve.h"
#include "zsetsurfacedata.h"
#include "zsetsurfaceparamvector.h"
#include "zsetsystemaper.h"
#include "zsetwavematrix.h"
#include "zddeclose.h"
#include "zsgetsystem.h"
#include "zssetsystem.h"
#include "ddeinit_mex_interface.h"
#include "ddereq_mex_interface.h"
#include "zsetfield.h"
#include "zsetfieldtype.h"
#include "zgetwave.h"
#include "zsetwave.h"
#include "ddeterm_mex_interface.h"
#include "zgetsystem.h"
#include "libmmfile.h"
#include "libmwsglm.h"

extern _mex_information _main_info;

mxArray * ZemaxDDEChannel = NULL;

mxArray * ZemaxDDETimeout = NULL;

static mexGlobalTableEntry global_table[2]
  = { { "ZemaxDDEChannel", &ZemaxDDEChannel },
      { "ZemaxDDETimeout", &ZemaxDDETimeout } };

static mexFunctionTableEntry function_table[29]
  = { { "accosin", mlxAccosin, -1, 1, &_local_function_table_accosin },
      { "zddeinit", mlxZddeinit, 0, 1, &_local_function_table_zddeinit },
      { "zdeletesurface", mlxZdeletesurface, 1, 1,
        &_local_function_table_zdeletesurface },
      { "zfindlabel", mlxZfindlabel, 1, 1, &_local_function_table_zfindlabel },
      { "zgetaperture", mlxZgetaperture, 1, 1,
        &_local_function_table_zgetaperture },
      { "zinsertsurface", mlxZinsertsurface, 1, 1,
        &_local_function_table_zinsertsurface },
      { "znewlens", mlxZnewlens, 0, 1, &_local_function_table_znewlens },
      { "zpushlens", mlxZpushlens, 1, 1, &_local_function_table_zpushlens },
      { "zsavefile", mlxZsavefile, 1, 1, &_local_function_table_zsavefile },
      { "zsetaperture", mlxZsetaperture, 7, 1,
        &_local_function_table_zsetaperture },
      { "zsetfieldmatrix", mlxZsetfieldmatrix, 2, 1,
        &_local_function_table_zsetfieldmatrix },
      { "zsetlabel", mlxZsetlabel, 2, 1, &_local_function_table_zsetlabel },
      { "zsetprimarywave", mlxZsetprimarywave, 1, 1,
        &_local_function_table_zsetprimarywave },
      { "zsetsolve", mlxZsetsolve, -4, 1, &_local_function_table_zsetsolve },
      { "zsetsurfacedata", mlxZsetsurfacedata, 3, 1,
        &_local_function_table_zsetsurfacedata },
      { "zsetsurfaceparamvector", mlxZsetsurfaceparamvector,
        2, 1, &_local_function_table_zsetsurfaceparamvector },
      { "zsetsystemaper", mlxZsetsystemaper, 3, 1,
        &_local_function_table_zsetsystemaper },
      { "zsetwavematrix", mlxZsetwavematrix, 1, 1,
        &_local_function_table_zsetwavematrix },
      { "zddeclose", mlxZddeclose, 0, 1, &_local_function_table_zddeclose },
      { "zsgetsystem", mlxZsgetsystem, 0, 1,
        &_local_function_table_zsgetsystem },
      { "zssetsystem", mlxZssetsystem, 1, 1,
        &_local_function_table_zssetsystem },
      { "ddeinit", mlxDdeinit, -1, -1, &_local_function_table_ddeinit },
      { "ddereq", mlxDdereq, -1, -1, &_local_function_table_ddereq },
      { "zsetfield", mlxZsetfield, 9, 1, &_local_function_table_zsetfield },
      { "zsetfieldtype", mlxZsetfieldtype, 2, 1,
        &_local_function_table_zsetfieldtype },
      { "zgetwave", mlxZgetwave, 1, 1, &_local_function_table_zgetwave },
      { "zsetwave", mlxZsetwave, 3, 1, &_local_function_table_zsetwave },
      { "ddeterm", mlxDdeterm, -1, -1, &_local_function_table_ddeterm },
      { "zgetsystem", mlxZgetsystem, 0, 1,
        &_local_function_table_zgetsystem } };

static const char * path_list_[1]
  = { "c:\\matlab6p5\\toolbox\\matlab\\winfun" };

static _mexInitTermTableEntry init_term_table[31]
  = { { libmmfileInitialize, libmmfileTerminate },
      { libmwsglmInitialize, libmwsglmTerminate },
      { InitializeModule_accosin, TerminateModule_accosin },
      { InitializeModule_zddeinit, TerminateModule_zddeinit },
      { InitializeModule_zdeletesurface, TerminateModule_zdeletesurface },
      { InitializeModule_zfindlabel, TerminateModule_zfindlabel },
      { InitializeModule_zgetaperture, TerminateModule_zgetaperture },
      { InitializeModule_zinsertsurface, TerminateModule_zinsertsurface },
      { InitializeModule_znewlens, TerminateModule_znewlens },
      { InitializeModule_zpushlens, TerminateModule_zpushlens },
      { InitializeModule_zsavefile, TerminateModule_zsavefile },
      { InitializeModule_zsetaperture, TerminateModule_zsetaperture },
      { InitializeModule_zsetfieldmatrix, TerminateModule_zsetfieldmatrix },
      { InitializeModule_zsetlabel, TerminateModule_zsetlabel },
      { InitializeModule_zsetprimarywave, TerminateModule_zsetprimarywave },
      { InitializeModule_zsetsolve, TerminateModule_zsetsolve },
      { InitializeModule_zsetsurfacedata, TerminateModule_zsetsurfacedata },
      { InitializeModule_zsetsurfaceparamvector,
        TerminateModule_zsetsurfaceparamvector },
      { InitializeModule_zsetsystemaper, TerminateModule_zsetsystemaper },
      { InitializeModule_zsetwavematrix, TerminateModule_zsetwavematrix },
      { InitializeModule_zddeclose, TerminateModule_zddeclose },
      { InitializeModule_zsgetsystem, TerminateModule_zsgetsystem },
      { InitializeModule_zssetsystem, TerminateModule_zssetsystem },
      { InitializeModule_ddeinit_mex_interface,
        TerminateModule_ddeinit_mex_interface },
      { InitializeModule_ddereq_mex_interface,
        TerminateModule_ddereq_mex_interface },
      { InitializeModule_zsetfield, TerminateModule_zsetfield },
      { InitializeModule_zsetfieldtype, TerminateModule_zsetfieldtype },
      { InitializeModule_zgetwave, TerminateModule_zgetwave },
      { InitializeModule_zsetwave, TerminateModule_zsetwave },
      { InitializeModule_ddeterm_mex_interface,
        TerminateModule_ddeterm_mex_interface },
      { InitializeModule_zgetsystem, TerminateModule_zgetsystem } };

_mex_information _main_info
  = { 1, 29, function_table, 2, global_table, 1,
      path_list_, 31, init_term_table };

/*
 * The function "main" is a Compiler-generated main wrapper, suitable for
 * building a stand-alone application.  It calls a library function to perform
 * initialization, call the main function, and perform library termination.
 */
int main(int argc, const char * * argv) {
    return mclMainhg(argc, argv, mlxAccosin, 1, &_main_info);
}
