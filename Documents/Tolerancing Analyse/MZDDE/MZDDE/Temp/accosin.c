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
#include "accosin.h"
#include "libmatlbm.h"
#include "libmmfile.h"
#include "libmwsglm.h"
#include "zddeclose.h"
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
#include "zsgetsystem.h"
#include "zssetsystem.h"

static mxChar _array1_[16] = { '$', 'R', 'e', 'v', 'i', 's', 'i', 'o',
                               'n', ':', ' ', '1', '.', '3', ' ', '$' };
static mxArray * _mxarray0_;

static mxChar _array3_[31] = { '$', 'D', 'a', 't', 'e', ':', ' ', '2',
                               '0', '0', '2', '-', '1', '1', '-', '1',
                               '9', ' ', '1', '4', ':', '0', '6', ':',
                               '4', '6', '+', '0', '2', ' ', '$' };
static mxArray * _mxarray2_;
static mxArray * _mxarray4_;
static mxArray * _mxarray5_;
static mxArray * _mxarray6_;
static mxArray * _mxarray7_;

static mxChar _array9_[38] = { 'A', 'C', 'C', 'O', 'S', ' ', 'L', 'e', 'n', 'o',
                               ' ', 'I', 'm', 'p', 'o', 'r', 't', 'e', 'r', ' ',
                               'f', 'o', 'r', ' ', 'Z', 'E', 'M', 'A', 'X', '.',
                               ' ', 'V', 'e', 'r', 's', 'i', 'o', 'n' };
static mxArray * _mxarray8_;

static mxChar _array11_[15] = { 'D', 'e', 'r', 'e', 'k', ' ', 'G', 'r',
                                'i', 'f', 'f', 'i', 't', 'h', ',' };
static mxArray * _mxarray10_;

static mxChar _array13_[21] = { 'Z', 'E', 'M', 'A', 'X', ' ', 'i',
                                's', ' ', 'n', 'o', 't', ' ', 'R',
                                'u', 'n', 'n', 'i', 'n', 'g', '.' };
static mxArray * _mxarray12_;

static mxChar _array15_[11] = { 'Z', 'E', 'M', 'A', 'X', ' ',
                                'E', 'r', 'r', 'o', 'r' };
static mxArray * _mxarray14_;

static mxChar _array17_[5] = { 'e', 'r', 'r', 'o', 'r' };
static mxArray * _mxarray16_;

static mxChar _array19_[5] = { 'm', 'o', 'd', 'a', 'l' };
static mxArray * _mxarray18_;

static mxChar _array21_[10] = { 'c', ':', 0x005c, 'p', 'o',
                                'p', 'd', 'i', 's', 't' };
static mxArray * _mxarray20_;

static mxChar _array23_[3] = { 'd', 'i', 'r' };
static mxArray * _mxarray22_;

static mxChar _array25_[3] = { 'c', ':', 0x005c };
static mxArray * _mxarray24_;

static mxChar _array27_[5] = { 'A', 'C', 'C', 'O', 'S' };
static mxArray * _mxarray26_;
static mxArray * _mxarray28_;

static mxChar _array32_[6] = { 'c', 'p', 'f', 'i', 'l', 'e' };
static mxArray * _mxarray31_;

static mxChar _array34_[12] = { '*', '.', 'l', 'e', 'n', ';',
                                '*', '.', 'l', 'e', 'n', 'o' };
static mxArray * _mxarray33_;

static mxChar _array36_[3] = { '*', '.', '*' };
static mxArray * _mxarray35_;

static mxChar _array38_[12] = { 'A', 'C', 'C', 'O', 'S', ' ',
                                'C', 'P', 'F', 'I', 'L', 'E' };
static mxArray * _mxarray37_;

static mxChar _array40_[16] = { 'A', 'C', 'C', 'O', 'S', ' ', 'L', 'e',
                                'n', 'o', ' ', 'F', 'i', 'l', 'e', 's' };
static mxArray * _mxarray39_;

static mxChar _array42_[9] = { 'A', 'l', 'l', ' ', 'F', 'i', 'l', 'e', 's' };
static mxArray * _mxarray41_;

static mxArray * _array30_[6] = { NULL /*_mxarray31_*/, NULL /*_mxarray33_*/,
                                  NULL /*_mxarray35_*/, NULL /*_mxarray37_*/,
                                  NULL /*_mxarray39_*/, NULL /*_mxarray41_*/ };
static mxArray * _mxarray29_;

static mxChar _array44_[15] = { 'O', 'p', 'e', 'n', ' ', 'A', 'C', 'C',
                                'O', 'S', ' ', 'F', 'i', 'l', 'e' };
static mxArray * _mxarray43_;
static mxArray * _mxarray45_;

static mxChar _array49_[4] = { 'G', 'E', 'R', 'M' };
static mxArray * _mxarray48_;

static mxChar _array51_[5] = { 'A', 'R', 'T', 'R', 'I' };
static mxArray * _mxarray50_;

static mxChar _array53_[6] = { 'S', 'I', 'L', 'I', 'C', 'N' };
static mxArray * _mxarray52_;

static mxChar _array55_[6] = { 'S', 'A', 'P', 'H', 'I', 'R' };
static mxArray * _mxarray54_;

static mxChar _array57_[3] = { 'B', 'A', 'F' };
static mxArray * _mxarray56_;

static mxChar _array59_[6] = { 'S', 'I', 'L', 'I', 'C', 'A' };
static mxArray * _mxarray58_;

static mxChar _array61_[4] = { 'I', 'R', 'T', '2' };
static mxArray * _mxarray60_;

static mxChar _array63_[4] = { 'I', 'R', 'T', '4' };
static mxArray * _mxarray62_;

static mxChar _array65_[4] = { 'C', 'A', 'F', 'L' };
static mxArray * _mxarray64_;

static mxChar _array67_[3] = { 'N', 'A', 'F' };
static mxArray * _mxarray66_;

static mxChar _array69_[3] = { 'L', 'I', 'F' };
static mxArray * _mxarray68_;

static mxChar _array71_[4] = { 'N', 'A', 'C', 'L' };
static mxArray * _mxarray70_;

static mxChar _array73_[2] = { 'K', 'I' };
static mxArray * _mxarray72_;

static mxChar _array75_[3] = { 'K', 'C', 'L' };
static mxArray * _mxarray74_;

static mxChar _array77_[3] = { 'K', 'B', 'R' };
static mxArray * _mxarray76_;

static mxChar _array79_[6] = { 'A', 'M', 'T', 'I', 'R', '1' };
static mxArray * _mxarray78_;

static mxChar _array81_[5] = { 'R', 'Z', 'N', 'S', 'E' };
static mxArray * _mxarray80_;

static mxChar _array83_[4] = { 'R', 'Z', 'N', 'S' };
static mxArray * _mxarray82_;

static mxChar _array85_[6] = { 'W', 'A', 'T', '2', '0', 'C' };
static mxArray * _mxarray84_;

static mxChar _array87_[4] = { 'I', 'R', 'T', '1' };
static mxArray * _mxarray86_;

static mxChar _array89_[4] = { 'P', 'B', 'F', '2' };
static mxArray * _mxarray88_;

static mxChar _array91_[4] = { 'C', 'D', 'F', '2' };
static mxArray * _mxarray90_;

static mxChar _array93_[4] = { 'G', 'A', 'A', 'S' };
static mxArray * _mxarray92_;

static mxChar _array95_[3] = { 'Z', 'N', 'S' };
static mxArray * _mxarray94_;

static mxChar _array97_[4] = { 'Z', 'N', 'S', 'E' };
static mxArray * _mxarray96_;

static mxChar _array99_[4] = { 'C', 'D', 'T', 'E' };
static mxArray * _mxarray98_;

static mxChar _array101_[6] = { 'S', 'C', 'G', 'E', 'R', 'M' };
static mxArray * _mxarray100_;

static mxChar _array103_[4] = { 'M', 'G', 'F', '2' };
static mxArray * _mxarray102_;

static mxChar _array105_[5] = { 'K', 'R', 'S', '-', '5' };
static mxArray * _mxarray104_;

static mxChar _array107_[4] = { 'L', 'I', 'F', 'X' };
static mxArray * _mxarray106_;

static mxChar _array109_[4] = { 'K', 'B', 'R', 'X' };
static mxArray * _mxarray108_;

static mxChar _array111_[4] = { 'K', 'C', 'L', 'X' };
static mxArray * _mxarray110_;

static mxChar _array113_[3] = { 'K', 'I', 'X' };
static mxArray * _mxarray112_;

static mxChar _array115_[5] = { 'N', 'A', 'C', 'L', 'X' };
static mxArray * _mxarray114_;

static mxChar _array117_[6] = { 'C', 'A', 'L', 'X', '-', 'O' };
static mxArray * _mxarray116_;

static mxChar _array119_[6] = { 'C', 'A', 'L', 'X', '-', 'E' };
static mxArray * _mxarray118_;

static mxChar _array121_[5] = { 'C', 'S', 'B', 'R', 'X' };
static mxArray * _mxarray120_;

static mxChar _array123_[4] = { 'C', 'S', 'I', 'X' };
static mxArray * _mxarray122_;

static mxChar _array125_[6] = { 'I', 'R', 'G', 'N', '6', 'X' };
static mxArray * _mxarray124_;

static mxChar _array127_[6] = { 'I', 'R', 'G', '1', '1', 'X' };
static mxArray * _mxarray126_;

static mxChar _array129_[6] = { 'M', 'G', 'F', 'X', '-', 'O' };
static mxArray * _mxarray128_;

static mxChar _array131_[6] = { 'M', 'G', 'F', 'X', '-', 'E' };
static mxArray * _mxarray130_;

static mxChar _array133_[6] = { 'K', 'D', 'P', 'X', '-', 'O' };
static mxArray * _mxarray132_;

static mxChar _array135_[6] = { 'K', 'D', 'P', 'X', '-', 'E' };
static mxArray * _mxarray134_;

static mxChar _array137_[5] = { 'A', 'G', 'C', 'L', 'X' };
static mxArray * _mxarray136_;

static mxChar _array139_[6] = { 'S', 'T', 'R', 'T', 'I', 'X' };
static mxArray * _mxarray138_;

static mxChar _array141_[5] = { 'K', 'R', 'S', '5', 'X' };
static mxArray * _mxarray140_;

static mxChar _array143_[6] = { 'Q', 'R', 'Z', 'X', '-', 'O' };
static mxArray * _mxarray142_;

static mxChar _array145_[6] = { 'Q', 'R', 'Z', 'X', '-', 'E' };
static mxArray * _mxarray144_;

static mxChar _array147_[5] = { 'M', 'G', 'A', 'L', 'O' };
static mxArray * _mxarray146_;

static mxChar _array149_[4] = { 'S', 'F', '5', '6' };
static mxArray * _mxarray148_;

static mxChar _array151_[5] = { 'L', 'A', 'F', '2', '1' };
static mxArray * _mxarray150_;

static mxChar _array153_[6] = { 'L', 'A', 'S', 'F', '3', '0' };
static mxArray * _mxarray152_;

static mxArray * _array47_[55] = { NULL /*_mxarray48_*/, NULL /*_mxarray50_*/,
                                   NULL /*_mxarray52_*/, NULL /*_mxarray54_*/,
                                   NULL /*_mxarray56_*/, NULL /*_mxarray58_*/,
                                   NULL /*_mxarray60_*/, NULL /*_mxarray62_*/,
                                   NULL /*_mxarray64_*/, NULL /*_mxarray66_*/,
                                   NULL /*_mxarray68_*/, NULL /*_mxarray70_*/,
                                   NULL /*_mxarray72_*/, NULL /*_mxarray74_*/,
                                   NULL /*_mxarray76_*/, NULL /*_mxarray78_*/,
                                   NULL /*_mxarray80_*/, NULL /*_mxarray82_*/,
                                   NULL /*_mxarray84_*/, NULL /*_mxarray86_*/,
                                   NULL /*_mxarray88_*/, NULL /*_mxarray90_*/,
                                   NULL /*_mxarray92_*/, NULL /*_mxarray94_*/,
                                   NULL /*_mxarray96_*/, NULL /*_mxarray98_*/,
                                   NULL /*_mxarray100_*/, NULL /*_mxarray102_*/,
                                   NULL /*_mxarray104_*/, NULL /*_mxarray106_*/,
                                   NULL /*_mxarray108_*/, NULL /*_mxarray110_*/,
                                   NULL /*_mxarray112_*/, NULL /*_mxarray114_*/,
                                   NULL /*_mxarray116_*/, NULL /*_mxarray118_*/,
                                   NULL /*_mxarray120_*/, NULL /*_mxarray122_*/,
                                   NULL /*_mxarray124_*/, NULL /*_mxarray126_*/,
                                   NULL /*_mxarray128_*/, NULL /*_mxarray130_*/,
                                   NULL /*_mxarray132_*/, NULL /*_mxarray134_*/,
                                   NULL /*_mxarray136_*/, NULL /*_mxarray138_*/,
                                   NULL /*_mxarray140_*/, NULL /*_mxarray124_*/,
                                   NULL /*_mxarray126_*/, NULL /*_mxarray142_*/,
                                   NULL /*_mxarray144_*/, NULL /*_mxarray146_*/,
                                   NULL /*_mxarray148_*/, NULL /*_mxarray150_*/,
                                   NULL /*_mxarray152_*/ };
static mxArray * _mxarray46_;

static mxChar _array157_[9] = { 'G', 'E', 'R', 'M', 'A', 'N', 'I', 'U', 'M' };
static mxArray * _mxarray156_;

static mxChar _array159_[7] = { 'S', 'I', 'L', 'I', 'C', 'O', 'N' };
static mxArray * _mxarray158_;

static mxChar _array161_[8] = { 'S', 'A', 'P', 'P', 'H', 'I', 'R', 'E' };
static mxArray * _mxarray160_;

static mxChar _array163_[8] = { 'F', '_', 'S', 'I', 'L', 'I', 'C', 'A' };
static mxArray * _mxarray162_;

static mxChar _array165_[9] = { 'C', 'L', 'E', 'A', 'R', 'T', 'R', 'A', 'N' };
static mxArray * _mxarray164_;

static mxChar _array167_[5] = { 'W', 'A', 'T', 'E', 'R' };
static mxArray * _mxarray166_;

static mxChar _array169_[9] = { 'Z', 'N', 'S', '_', 'B', 'R', 'O', 'A', 'D' };
static mxArray * _mxarray168_;

static mxChar _array171_[4] = { 'K', 'R', 'S', '5' };
static mxArray * _mxarray170_;

static mxChar _array173_[7] = { 'C', 'A', 'L', 'C', 'I', 'T', 'E' };
static mxArray * _mxarray172_;

static mxChar _array175_[9] = { 'C', 'A', 'L', 'C', 'I', 'T', 'E', '-', 'E' };
static mxArray * _mxarray174_;

static mxChar _array177_[4] = { 'C', 'S', 'B', 'R' };
static mxArray * _mxarray176_;

static mxChar _array179_[3] = { 'C', 'S', 'I' };
static mxArray * _mxarray178_;

static mxChar _array181_[5] = { 'I', 'R', 'G', 'N', '6' };
static mxArray * _mxarray180_;

static mxChar _array183_[5] = { 'I', 'R', 'G', '1', '1' };
static mxArray * _mxarray182_;

static mxChar _array185_[6] = { 'M', 'G', 'F', '2', '-', 'E' };
static mxArray * _mxarray184_;

static mxChar _array187_[3] = { 'K', 'D', 'P' };
static mxArray * _mxarray186_;

static mxChar _array189_[5] = { 'K', 'D', 'P', '-', 'E' };
static mxArray * _mxarray188_;

static mxChar _array191_[4] = { 'A', 'G', 'C', 'L' };
static mxArray * _mxarray190_;

static mxChar _array193_[5] = { 'S', 'T', 'R', 'T', 'I' };
static mxArray * _mxarray192_;

static mxChar _array195_[6] = { 'Q', 'U', 'A', 'R', 'T', 'Z' };
static mxArray * _mxarray194_;

static mxChar _array197_[8] = { 'Q', 'U', 'A', 'R', 'T', 'Z', '-', 'E' };
static mxArray * _mxarray196_;

static mxChar _array199_[6] = { 'N', '-', 'S', 'F', '5', '6' };
static mxArray * _mxarray198_;

static mxChar _array201_[6] = { 'L', 'A', 'F', 'N', '2', '1' };
static mxArray * _mxarray200_;

static mxChar _array203_[7] = { 'L', 'A', 'S', 'F', 'N', '3', '0' };
static mxArray * _mxarray202_;

static mxArray * _array155_[55] = { NULL /*_mxarray156_*/, NULL /*_mxarray50_*/,
                                    NULL /*_mxarray158_*/,
                                    NULL /*_mxarray160_*/, NULL /*_mxarray56_*/,
                                    NULL /*_mxarray162_*/, NULL /*_mxarray60_*/,
                                    NULL /*_mxarray62_*/, NULL /*_mxarray64_*/,
                                    NULL /*_mxarray66_*/, NULL /*_mxarray68_*/,
                                    NULL /*_mxarray70_*/, NULL /*_mxarray72_*/,
                                    NULL /*_mxarray74_*/, NULL /*_mxarray76_*/,
                                    NULL /*_mxarray78_*/, NULL /*_mxarray96_*/,
                                    NULL /*_mxarray164_*/,
                                    NULL /*_mxarray166_*/, NULL /*_mxarray86_*/,
                                    NULL /*_mxarray88_*/, NULL /*_mxarray90_*/,
                                    NULL /*_mxarray92_*/, NULL /*_mxarray168_*/,
                                    NULL /*_mxarray96_*/, NULL /*_mxarray98_*/,
                                    NULL /*_mxarray100_*/,
                                    NULL /*_mxarray102_*/,
                                    NULL /*_mxarray170_*/, NULL /*_mxarray68_*/,
                                    NULL /*_mxarray76_*/, NULL /*_mxarray74_*/,
                                    NULL /*_mxarray72_*/, NULL /*_mxarray70_*/,
                                    NULL /*_mxarray172_*/,
                                    NULL /*_mxarray174_*/,
                                    NULL /*_mxarray176_*/,
                                    NULL /*_mxarray178_*/,
                                    NULL /*_mxarray180_*/,
                                    NULL /*_mxarray182_*/,
                                    NULL /*_mxarray102_*/,
                                    NULL /*_mxarray184_*/,
                                    NULL /*_mxarray186_*/,
                                    NULL /*_mxarray188_*/,
                                    NULL /*_mxarray190_*/,
                                    NULL /*_mxarray192_*/,
                                    NULL /*_mxarray170_*/,
                                    NULL /*_mxarray180_*/,
                                    NULL /*_mxarray182_*/,
                                    NULL /*_mxarray194_*/,
                                    NULL /*_mxarray196_*/,
                                    NULL /*_mxarray146_*/,
                                    NULL /*_mxarray198_*/,
                                    NULL /*_mxarray200_*/,
                                    NULL /*_mxarray202_*/ };
static mxArray * _mxarray154_;
static mxArray * _mxarray204_;
static mxArray * _mxarray205_;

static mxChar _array207_[2] = { 'r', 't' };
static mxArray * _mxarray206_;

static mxChar _array209_[2] = { ' ', ',' };
static mxArray * _mxarray208_;

static mxChar _array211_[4] = { 'L', 'E', 'N', 'S' };
static mxArray * _mxarray210_;

static double _array213_[5] = { .5876, .48613, .65627, .43584, .70653 };
static mxArray * _mxarray212_;
static mxArray * _mxarray214_;

static double _array216_[5] = { 1.0, 1.0, 1.0, 1.0, 1.0 };
static mxArray * _mxarray215_;
static mxArray * _mxarray217_;
static mxArray * _mxarray218_;

static mxChar _array220_[2] = { 'L', 'I' };
static mxArray * _mxarray219_;
static mxArray * _mxarray221_;

static mxChar _array223_[9] = { 'R', 'e', 'a', 'd', 'i', 'n', 'g', ' ', ':' };
static mxArray * _mxarray222_;

static mxChar _array225_[3] = { 'L', 'I', 'C' };
static mxArray * _mxarray224_;

static mxChar _array227_[1] = { 'C' };
static mxArray * _mxarray226_;

static mxChar _array229_[7] = { 'S', 'U', 'R', 'F', 'A', 'C', 'E' };
static mxArray * _mxarray228_;

static mxChar _array231_[3] = { 'S', 'A', 'Y' };
static mxArray * _mxarray230_;

static mxChar _array233_[3] = { 'S', 'C', 'Y' };
static mxArray * _mxarray232_;

static mxChar _array235_[4] = { 'F', 'A', 'N', 'G' };
static mxArray * _mxarray234_;

static mxChar _array237_[3] = { 'S', 'C', 'X' };
static mxArray * _mxarray236_;

static mxChar _array239_[2] = { 'R', 'D' };
static mxArray * _mxarray238_;

static mxChar _array241_[2] = { 'C', 'V' };
static mxArray * _mxarray240_;

static mxChar _array243_[2] = { 'C', 'C' };
static mxArray * _mxarray242_;
static mxArray * _mxarray244_;

static mxChar _array246_[4] = { 'A', 'S', 'P', 'H' };
static mxArray * _mxarray245_;

static mxChar _array248_[5] = { 'R', 'S', 'I', 'R', 'S' };
static mxArray * _mxarray247_;

static mxChar _array250_[56] = { 'R', 'o', 't', 'a', 't', 'i', 'o', 'n',
                                 'a', 'l', 'l', 'y', ' ', 'S', 'y', 'm',
                                 'm', 'e', 't', 'r', 'i', 'c', ' ', 'S',
                                 'p', 'l', 'i', 'n', 'e', ' ', 'S', 'u',
                                 'r', 'f', 'a', 'c', 'e', ' ', 'D', 'e',
                                 'f', 'i', 'n', 'i', 't', 'i', 'o', 'n',
                                 ' ', 'I', 'g', 'n', 'o', 'r', 'e', 'd' };
static mxArray * _mxarray249_;

static mxChar _array252_[3] = { 'I', 'R', 'S' };
static mxArray * _mxarray251_;

static mxChar _array254_[44] = { 'A', 's', 'y', 'm', 'm', 'e', 't', 'r', 'i',
                                 'c', ' ', 'S', 'p', 'l', 'i', 'n', 'e', ' ',
                                 'S', 'u', 'r', 'f', 'a', 'c', 'e', ' ', 'D',
                                 'e', 'f', 'i', 'n', 'i', 't', 'i', 'o', 'n',
                                 ' ', 'I', 'g', 'n', 'o', 'r', 'e', 'd' };
static mxArray * _mxarray253_;

static mxChar _array256_[8] = { 'E', 'V', 'E', 'N', 'A', 'S', 'P', 'H' };
static mxArray * _mxarray255_;

static mxChar _array258_[2] = { 'T', 'H' };
static mxArray * _mxarray257_;
static mxArray * _mxarray259_;
static mxArray * _mxarray260_;
static mxArray * _mxarray261_;
static mxArray * _mxarray262_;

static double _array264_[3] = { 0.0, 0.0, 1.0 };
static mxArray * _mxarray263_;
static mxArray * _mxarray265_;

static mxChar _array267_[4] = { 'C', 'L', 'A', 'P' };
static mxArray * _mxarray266_;

static double _array269_[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
static mxArray * _mxarray268_;

static mxChar _array271_[4] = { 'R', 'E', 'C', 'T' };
static mxArray * _mxarray270_;

static mxChar _array273_[4] = { 'E', 'L', 'I', 'P' };
static mxArray * _mxarray272_;

static mxChar _array275_[4] = { 'C', 'O', 'B', 'S' };
static mxArray * _mxarray274_;
static mxArray * _mxarray276_;

static mxChar _array278_[3] = { 'A', 'I', 'R' };
static mxArray * _mxarray277_;

static mxChar _array280_[6] = { 'S', 'C', 'H', 'O', 'T', 'T' };
static mxArray * _mxarray279_;

static mxChar _array282_[4] = { 'H', 'O', 'Y', 'A' };
static mxArray * _mxarray281_;

static mxChar _array284_[5] = { 'O', 'H', 'A', 'R', 'A' };
static mxArray * _mxarray283_;

static mxChar _array286_[4] = { 'R', 'E', 'F', 'L' };
static mxArray * _mxarray285_;

static mxChar _array288_[6] = { 'M', 'I', 'R', 'R', 'O', 'R' };
static mxArray * _mxarray287_;

static mxChar _array290_[5] = { 'G', 'L', 'A', 'S', 'S' };
static mxArray * _mxarray289_;

static mxChar _array292_[5] = { 'M', 'O', 'D', 'E', 'L' };
static mxArray * _mxarray291_;

static mxChar _array294_[4] = { 'M', 'A', 'T', 'L' };
static mxArray * _mxarray293_;

static mxChar _array296_[5] = { 'A', 'S', 'T', 'O', 'P' };
static mxArray * _mxarray295_;

static mxChar _array298_[5] = { 'U', 'N', 'I', 'T', 'S' };
static mxArray * _mxarray297_;

static mxChar _array300_[2] = { 'M', 'M' };
static mxArray * _mxarray299_;

static mxChar _array302_[2] = { 'C', 'M' };
static mxArray * _mxarray301_;

static mxChar _array304_[6] = { 'I', 'N', 'C', 'H', 'E', 'S' };
static mxArray * _mxarray303_;

static mxChar _array306_[5] = { 'P', 'I', 'K', 'U', 'P' };
static mxArray * _mxarray305_;

static mxChar _array308_[24] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ',
                                 'P', 'I', 'K', 'U', 'P', 's', ' ', 'o',
                                 'f', ' ', 't', 'y', 'p', 'e', ' ', '"' };
static mxArray * _mxarray307_;

static mxChar _array310_[18] = { '"', ' ', 'w', 'i', 'l', 'l', ' ', 'b', 'e',
                                 ' ', 'I', 'g', 'n', 'o', 'r', 'e', 'd', '.' };
static mxArray * _mxarray309_;

static mxChar _array312_[2] = { 'P', 'Y' };
static mxArray * _mxarray311_;
static mxArray * _mxarray313_;

static mxChar _array315_[2] = { 'W', 'V' };
static mxArray * _mxarray314_;
static mxArray * _mxarray316_;

static mxChar _array318_[5] = { 'S', 'P', 'T', 'W', 'T' };
static mxArray * _mxarray317_;

static mxChar _array320_[2] = { 'C', 'W' };
static mxArray * _mxarray319_;

static mxChar _array322_[7] = { 'C', 'O', 'N', 'F', 'I', 'G', 'S' };
static mxArray * _mxarray321_;

static mxChar _array324_[6] = { 'C', 'O', 'N', 'F', 'I', 'G' };
static mxArray * _mxarray323_;

static mxChar _array326_[3] = { 'O', 'L', 'D' };
static mxArray * _mxarray325_;

static mxChar _array328_[3] = { 'E', 'O', 'S' };
static mxArray * _mxarray327_;

static mxChar _array330_[3] = { 'L', 'I', 'B' };
static mxArray * _mxarray329_;

static mxChar _array332_[3] = { 'P', 'U', 'T' };
static mxArray * _mxarray331_;

static mxChar _array334_[71] = { 'L', 'I', 'B', ' ', 'P', 'U', 'T', ' ', 'R',
                                 'e', 'q', 'u', 'e', 's', 't', 'e', 'd', '.',
                                 ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ', 'S',
                                 'e', 'l', 'e', 'c', 't', ' ', 'a', ' ', 'S',
                                 'u', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'P',
                                 'l', 'a', 'c', 'e', ' ', 'f', 'o', 'r', ' ',
                                 't', 'h', 'e', ' ', 'L', 'i', 'b', 'r', 'a',
                                 'r', 'y', ' ', 'D', 'u', 'm', 'p', '.' };
static mxArray * _mxarray333_;

static mxChar _array336_[9] = { 'D', 'u', 'm', 'm', 'y', '.', 'z', 'm', 'x' };
static mxArray * _mxarray335_;

static mxChar _array338_[34] = { 'N', 'a', 'v', 'i', 'g', 'a', 't', 'e', ' ',
                                 't', 'o', ' ', 'D', 'i', 'r', 'e', 'c', 't',
                                 'o', 'r', 'y', ' ', 'f', 'o', 'r', ' ', 'L',
                                 'i', 'b', ' ', 'D', 'u', 'm', 'p' };
static mxArray * _mxarray337_;
static mxArray * _mxarray339_;

static mxChar _array341_[115] = { 'Z', 'E', 'M', 'A', 'X', ' ', 'i', 's', ' ',
                                  'n', 'o', 't', ' ', 'r', 'e', 's', 'p', 'o',
                                  'n', 'd', 'i', 'n', 'g', ' ', 't', 'o', ' ',
                                  't', 'h', 'e', ' ', 'C', 'o', 'n', 'v', 'e',
                                  'r', 's', 'i', 'o', 'n', ' ', 'U', 't', 'i',
                                  'l', 'i', 't', 'y', '.', ' ', 'Z', 'E', 'M',
                                  'A', 'X', ' ', 'm', 'a', 'y', ' ', 'b', 'e',
                                  ' ', 'w', 'a', 'i', 't', 'i', 'n', 'g', ' ',
                                  'f', 'o', 'r', ' ', 'y', 'o', 'u', 'r', ' ',
                                  'i', 'n', 'p', 'u', 't', '.', ' ', 'W', 'h',
                                  'a', 't', ' ', 'w', 'o', 'u', 'l', 'd', ' ',
                                  'y', 'o', 'u', ' ', 'l', 'i', 'k', 'e', ' ',
                                  't', 'o', ' ', 'd', 'o', ' ', '?' };
static mxArray * _mxarray340_;

static mxChar _array343_[30] = { 'Z', 'E', 'M', 'A', 'X', ' ', 'U', 'n',
                                 'r', 'e', 's', 'p', 'o', 'n', 's', 'i',
                                 'v', 'e', '.', ' ', 'W', 'h', 'a', 't',
                                 ' ', 'N', 'o', 'w', ' ', '?' };
static mxArray * _mxarray342_;

static mxChar _array345_[8] = { 'C', 'o', 'n', 't', 'i', 'n', 'u', 'e' };
static mxArray * _mxarray344_;

static mxChar _array347_[7] = { 'A', 'b', 'a', 'n', 'd', 'o', 'n' };
static mxArray * _mxarray346_;

static mxChar _array349_[1] = { 0x005c };
static mxArray * _mxarray348_;

static mxChar _array351_[4] = { '.', 'z', 'm', 'x' };
static mxArray * _mxarray350_;

static mxChar _array353_[6] = { 'B', 'l', 'o', 'c', 'k', ' ' };
static mxArray * _mxarray352_;

static mxChar _array355_[20] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n',
                                 ' ', 'D', 'i', 'r', 'e', 'c', 't',
                                 'i', 'v', 'e', 's', ' ', '"' };
static mxArray * _mxarray354_;

static mxChar _array357_[9] = { '/', 0x005c, ':', '*', '?',
                                '<', '>', '|', ',' };
static mxArray * _mxarray356_;

static mxChar _array359_[9] = { '#', '%', ';', '+', '&', '{', '}', '!', '-' };
static mxArray * _mxarray358_;

static mxChar _array361_[1] = { '.' };
static mxArray * _mxarray360_;

static mxChar _array363_[27] = { 'D', 'i', 's', 'c', 'a', 'r', 'd', 'i', 'n',
                                 'g', ' ', 'O', 'l', 'd', ' ', 'C', 'o', 'n',
                                 'f', 'i', 'g', ' ', 'D', 'a', 't', 'a', '.' };
static mxArray * _mxarray362_;

static mxChar _array365_[27] = { 'D', 'i', 's', 'c', 'a', 'r', 'd', 'i', 'n',
                                 'g', ' ', 'N', 'e', 'w', ' ', 'C', 'o', 'n',
                                 'f', 'i', 'g', ' ', 'D', 'a', 't', 'a', '.' };
static mxArray * _mxarray364_;

void InitializeModule_accosin(void) {
    _mxarray0_ = mclInitializeString(16, _array1_);
    _mxarray2_ = mclInitializeString(31, _array3_);
    _mxarray4_ = mclInitializeDouble(11.0);
    _mxarray5_ = mclInitializeDouble(2.0);
    _mxarray6_ = mclInitializeDouble(1.0);
    _mxarray7_ = mclInitializeDouble(7.0);
    _mxarray8_ = mclInitializeString(38, _array9_);
    _mxarray10_ = mclInitializeString(15, _array11_);
    _mxarray12_ = mclInitializeString(21, _array13_);
    _mxarray14_ = mclInitializeString(11, _array15_);
    _mxarray16_ = mclInitializeString(5, _array17_);
    _mxarray18_ = mclInitializeString(5, _array19_);
    _mxarray20_ = mclInitializeString(10, _array21_);
    _mxarray22_ = mclInitializeString(3, _array23_);
    _mxarray24_ = mclInitializeString(3, _array25_);
    _mxarray26_ = mclInitializeString(5, _array27_);
    _mxarray28_ = mclInitializeCharVector(0, 0, (mxChar *)NULL);
    _mxarray31_ = mclInitializeString(6, _array32_);
    _array30_[0] = _mxarray31_;
    _mxarray33_ = mclInitializeString(12, _array34_);
    _array30_[1] = _mxarray33_;
    _mxarray35_ = mclInitializeString(3, _array36_);
    _array30_[2] = _mxarray35_;
    _mxarray37_ = mclInitializeString(12, _array38_);
    _array30_[3] = _mxarray37_;
    _mxarray39_ = mclInitializeString(16, _array40_);
    _array30_[4] = _mxarray39_;
    _mxarray41_ = mclInitializeString(9, _array42_);
    _array30_[5] = _mxarray41_;
    _mxarray29_ = mclInitializeCellVector(3, 2, _array30_);
    _mxarray43_ = mclInitializeString(15, _array44_);
    _mxarray45_ = mclInitializeDouble(-1.0);
    _mxarray48_ = mclInitializeString(4, _array49_);
    _array47_[0] = _mxarray48_;
    _mxarray50_ = mclInitializeString(5, _array51_);
    _array47_[1] = _mxarray50_;
    _mxarray52_ = mclInitializeString(6, _array53_);
    _array47_[2] = _mxarray52_;
    _mxarray54_ = mclInitializeString(6, _array55_);
    _array47_[3] = _mxarray54_;
    _mxarray56_ = mclInitializeString(3, _array57_);
    _array47_[4] = _mxarray56_;
    _mxarray58_ = mclInitializeString(6, _array59_);
    _array47_[5] = _mxarray58_;
    _mxarray60_ = mclInitializeString(4, _array61_);
    _array47_[6] = _mxarray60_;
    _mxarray62_ = mclInitializeString(4, _array63_);
    _array47_[7] = _mxarray62_;
    _mxarray64_ = mclInitializeString(4, _array65_);
    _array47_[8] = _mxarray64_;
    _mxarray66_ = mclInitializeString(3, _array67_);
    _array47_[9] = _mxarray66_;
    _mxarray68_ = mclInitializeString(3, _array69_);
    _array47_[10] = _mxarray68_;
    _mxarray70_ = mclInitializeString(4, _array71_);
    _array47_[11] = _mxarray70_;
    _mxarray72_ = mclInitializeString(2, _array73_);
    _array47_[12] = _mxarray72_;
    _mxarray74_ = mclInitializeString(3, _array75_);
    _array47_[13] = _mxarray74_;
    _mxarray76_ = mclInitializeString(3, _array77_);
    _array47_[14] = _mxarray76_;
    _mxarray78_ = mclInitializeString(6, _array79_);
    _array47_[15] = _mxarray78_;
    _mxarray80_ = mclInitializeString(5, _array81_);
    _array47_[16] = _mxarray80_;
    _mxarray82_ = mclInitializeString(4, _array83_);
    _array47_[17] = _mxarray82_;
    _mxarray84_ = mclInitializeString(6, _array85_);
    _array47_[18] = _mxarray84_;
    _mxarray86_ = mclInitializeString(4, _array87_);
    _array47_[19] = _mxarray86_;
    _mxarray88_ = mclInitializeString(4, _array89_);
    _array47_[20] = _mxarray88_;
    _mxarray90_ = mclInitializeString(4, _array91_);
    _array47_[21] = _mxarray90_;
    _mxarray92_ = mclInitializeString(4, _array93_);
    _array47_[22] = _mxarray92_;
    _mxarray94_ = mclInitializeString(3, _array95_);
    _array47_[23] = _mxarray94_;
    _mxarray96_ = mclInitializeString(4, _array97_);
    _array47_[24] = _mxarray96_;
    _mxarray98_ = mclInitializeString(4, _array99_);
    _array47_[25] = _mxarray98_;
    _mxarray100_ = mclInitializeString(6, _array101_);
    _array47_[26] = _mxarray100_;
    _mxarray102_ = mclInitializeString(4, _array103_);
    _array47_[27] = _mxarray102_;
    _mxarray104_ = mclInitializeString(5, _array105_);
    _array47_[28] = _mxarray104_;
    _mxarray106_ = mclInitializeString(4, _array107_);
    _array47_[29] = _mxarray106_;
    _mxarray108_ = mclInitializeString(4, _array109_);
    _array47_[30] = _mxarray108_;
    _mxarray110_ = mclInitializeString(4, _array111_);
    _array47_[31] = _mxarray110_;
    _mxarray112_ = mclInitializeString(3, _array113_);
    _array47_[32] = _mxarray112_;
    _mxarray114_ = mclInitializeString(5, _array115_);
    _array47_[33] = _mxarray114_;
    _mxarray116_ = mclInitializeString(6, _array117_);
    _array47_[34] = _mxarray116_;
    _mxarray118_ = mclInitializeString(6, _array119_);
    _array47_[35] = _mxarray118_;
    _mxarray120_ = mclInitializeString(5, _array121_);
    _array47_[36] = _mxarray120_;
    _mxarray122_ = mclInitializeString(4, _array123_);
    _array47_[37] = _mxarray122_;
    _mxarray124_ = mclInitializeString(6, _array125_);
    _array47_[38] = _mxarray124_;
    _mxarray126_ = mclInitializeString(6, _array127_);
    _array47_[39] = _mxarray126_;
    _mxarray128_ = mclInitializeString(6, _array129_);
    _array47_[40] = _mxarray128_;
    _mxarray130_ = mclInitializeString(6, _array131_);
    _array47_[41] = _mxarray130_;
    _mxarray132_ = mclInitializeString(6, _array133_);
    _array47_[42] = _mxarray132_;
    _mxarray134_ = mclInitializeString(6, _array135_);
    _array47_[43] = _mxarray134_;
    _mxarray136_ = mclInitializeString(5, _array137_);
    _array47_[44] = _mxarray136_;
    _mxarray138_ = mclInitializeString(6, _array139_);
    _array47_[45] = _mxarray138_;
    _mxarray140_ = mclInitializeString(5, _array141_);
    _array47_[46] = _mxarray140_;
    _array47_[47] = _mxarray124_;
    _array47_[48] = _mxarray126_;
    _mxarray142_ = mclInitializeString(6, _array143_);
    _array47_[49] = _mxarray142_;
    _mxarray144_ = mclInitializeString(6, _array145_);
    _array47_[50] = _mxarray144_;
    _mxarray146_ = mclInitializeString(5, _array147_);
    _array47_[51] = _mxarray146_;
    _mxarray148_ = mclInitializeString(4, _array149_);
    _array47_[52] = _mxarray148_;
    _mxarray150_ = mclInitializeString(5, _array151_);
    _array47_[53] = _mxarray150_;
    _mxarray152_ = mclInitializeString(6, _array153_);
    _array47_[54] = _mxarray152_;
    _mxarray46_ = mclInitializeCellVector(55, 1, _array47_);
    _mxarray156_ = mclInitializeString(9, _array157_);
    _array155_[0] = _mxarray156_;
    _array155_[1] = _mxarray50_;
    _mxarray158_ = mclInitializeString(7, _array159_);
    _array155_[2] = _mxarray158_;
    _mxarray160_ = mclInitializeString(8, _array161_);
    _array155_[3] = _mxarray160_;
    _array155_[4] = _mxarray56_;
    _mxarray162_ = mclInitializeString(8, _array163_);
    _array155_[5] = _mxarray162_;
    _array155_[6] = _mxarray60_;
    _array155_[7] = _mxarray62_;
    _array155_[8] = _mxarray64_;
    _array155_[9] = _mxarray66_;
    _array155_[10] = _mxarray68_;
    _array155_[11] = _mxarray70_;
    _array155_[12] = _mxarray72_;
    _array155_[13] = _mxarray74_;
    _array155_[14] = _mxarray76_;
    _array155_[15] = _mxarray78_;
    _array155_[16] = _mxarray96_;
    _mxarray164_ = mclInitializeString(9, _array165_);
    _array155_[17] = _mxarray164_;
    _mxarray166_ = mclInitializeString(5, _array167_);
    _array155_[18] = _mxarray166_;
    _array155_[19] = _mxarray86_;
    _array155_[20] = _mxarray88_;
    _array155_[21] = _mxarray90_;
    _array155_[22] = _mxarray92_;
    _mxarray168_ = mclInitializeString(9, _array169_);
    _array155_[23] = _mxarray168_;
    _array155_[24] = _mxarray96_;
    _array155_[25] = _mxarray98_;
    _array155_[26] = _mxarray100_;
    _array155_[27] = _mxarray102_;
    _mxarray170_ = mclInitializeString(4, _array171_);
    _array155_[28] = _mxarray170_;
    _array155_[29] = _mxarray68_;
    _array155_[30] = _mxarray76_;
    _array155_[31] = _mxarray74_;
    _array155_[32] = _mxarray72_;
    _array155_[33] = _mxarray70_;
    _mxarray172_ = mclInitializeString(7, _array173_);
    _array155_[34] = _mxarray172_;
    _mxarray174_ = mclInitializeString(9, _array175_);
    _array155_[35] = _mxarray174_;
    _mxarray176_ = mclInitializeString(4, _array177_);
    _array155_[36] = _mxarray176_;
    _mxarray178_ = mclInitializeString(3, _array179_);
    _array155_[37] = _mxarray178_;
    _mxarray180_ = mclInitializeString(5, _array181_);
    _array155_[38] = _mxarray180_;
    _mxarray182_ = mclInitializeString(5, _array183_);
    _array155_[39] = _mxarray182_;
    _array155_[40] = _mxarray102_;
    _mxarray184_ = mclInitializeString(6, _array185_);
    _array155_[41] = _mxarray184_;
    _mxarray186_ = mclInitializeString(3, _array187_);
    _array155_[42] = _mxarray186_;
    _mxarray188_ = mclInitializeString(5, _array189_);
    _array155_[43] = _mxarray188_;
    _mxarray190_ = mclInitializeString(4, _array191_);
    _array155_[44] = _mxarray190_;
    _mxarray192_ = mclInitializeString(5, _array193_);
    _array155_[45] = _mxarray192_;
    _array155_[46] = _mxarray170_;
    _array155_[47] = _mxarray180_;
    _array155_[48] = _mxarray182_;
    _mxarray194_ = mclInitializeString(6, _array195_);
    _array155_[49] = _mxarray194_;
    _mxarray196_ = mclInitializeString(8, _array197_);
    _array155_[50] = _mxarray196_;
    _array155_[51] = _mxarray146_;
    _mxarray198_ = mclInitializeString(6, _array199_);
    _array155_[52] = _mxarray198_;
    _mxarray200_ = mclInitializeString(6, _array201_);
    _array155_[53] = _mxarray200_;
    _mxarray202_ = mclInitializeString(7, _array203_);
    _array155_[54] = _mxarray202_;
    _mxarray154_ = mclInitializeCellVector(55, 1, _array155_);
    _mxarray204_ = mclInitializeCellVector(0, 0, (mxArray * *)NULL);
    _mxarray205_ = mclInitializeDouble(0.0);
    _mxarray206_ = mclInitializeString(2, _array207_);
    _mxarray208_ = mclInitializeString(2, _array209_);
    _mxarray210_ = mclInitializeString(4, _array211_);
    _mxarray212_ = mclInitializeDoubleVector(5, 1, _array213_);
    _mxarray214_ = mclInitializeDouble(5.0);
    _mxarray215_ = mclInitializeDoubleVector(5, 1, _array216_);
    _mxarray217_ = mclInitializeDouble(1001.0);
    _mxarray218_ = mclInitializeDouble(1002.0);
    _mxarray219_ = mclInitializeString(2, _array220_);
    _mxarray221_ = mclInitializeDouble(4.0);
    _mxarray222_ = mclInitializeString(9, _array223_);
    _mxarray224_ = mclInitializeString(3, _array225_);
    _mxarray226_ = mclInitializeString(1, _array227_);
    _mxarray228_ = mclInitializeString(7, _array229_);
    _mxarray230_ = mclInitializeString(3, _array231_);
    _mxarray232_ = mclInitializeString(3, _array233_);
    _mxarray234_ = mclInitializeString(4, _array235_);
    _mxarray236_ = mclInitializeString(3, _array237_);
    _mxarray238_ = mclInitializeString(2, _array239_);
    _mxarray240_ = mclInitializeString(2, _array241_);
    _mxarray242_ = mclInitializeString(2, _array243_);
    _mxarray244_ = mclInitializeDouble(6.0);
    _mxarray245_ = mclInitializeString(4, _array246_);
    _mxarray247_ = mclInitializeString(5, _array248_);
    _mxarray249_ = mclInitializeString(56, _array250_);
    _mxarray251_ = mclInitializeString(3, _array252_);
    _mxarray253_ = mclInitializeString(44, _array254_);
    _mxarray255_ = mclInitializeString(8, _array256_);
    _mxarray257_ = mclInitializeString(2, _array258_);
    _mxarray259_ = mclInitializeDouble(3.0);
    _mxarray260_ = mclInitializeDouble(1e+10);
    _mxarray261_ = mclInitializeDouble(360.0);
    _mxarray262_ = mclInitializeDouble(6.283185308);
    _mxarray263_ = mclInitializeDoubleVector(1, 3, _array264_);
    _mxarray265_ = mclInitializeDouble(.7);
    _mxarray266_ = mclInitializeString(4, _array267_);
    _mxarray268_ = mclInitializeDoubleVector(1, 5, _array269_);
    _mxarray270_ = mclInitializeString(4, _array271_);
    _mxarray272_ = mclInitializeString(4, _array273_);
    _mxarray274_ = mclInitializeString(4, _array275_);
    _mxarray276_ = mclInitializeDouble(10000.0);
    _mxarray277_ = mclInitializeString(3, _array278_);
    _mxarray279_ = mclInitializeString(6, _array280_);
    _mxarray281_ = mclInitializeString(4, _array282_);
    _mxarray283_ = mclInitializeString(5, _array284_);
    _mxarray285_ = mclInitializeString(4, _array286_);
    _mxarray287_ = mclInitializeString(6, _array288_);
    _mxarray289_ = mclInitializeString(5, _array290_);
    _mxarray291_ = mclInitializeString(5, _array292_);
    _mxarray293_ = mclInitializeString(4, _array294_);
    _mxarray295_ = mclInitializeString(5, _array296_);
    _mxarray297_ = mclInitializeString(5, _array298_);
    _mxarray299_ = mclInitializeString(2, _array300_);
    _mxarray301_ = mclInitializeString(2, _array302_);
    _mxarray303_ = mclInitializeString(6, _array304_);
    _mxarray305_ = mclInitializeString(5, _array306_);
    _mxarray307_ = mclInitializeString(24, _array308_);
    _mxarray309_ = mclInitializeString(18, _array310_);
    _mxarray311_ = mclInitializeString(2, _array312_);
    _mxarray313_ = mclInitializeDouble(.1);
    _mxarray314_ = mclInitializeString(2, _array315_);
    _mxarray316_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
    _mxarray317_ = mclInitializeString(5, _array318_);
    _mxarray319_ = mclInitializeString(2, _array320_);
    _mxarray321_ = mclInitializeString(7, _array322_);
    _mxarray323_ = mclInitializeString(6, _array324_);
    _mxarray325_ = mclInitializeString(3, _array326_);
    _mxarray327_ = mclInitializeString(3, _array328_);
    _mxarray329_ = mclInitializeString(3, _array330_);
    _mxarray331_ = mclInitializeString(3, _array332_);
    _mxarray333_ = mclInitializeString(71, _array334_);
    _mxarray335_ = mclInitializeString(9, _array336_);
    _mxarray337_ = mclInitializeString(34, _array338_);
    _mxarray339_ = mclInitializeDouble(-998.0);
    _mxarray340_ = mclInitializeString(115, _array341_);
    _mxarray342_ = mclInitializeString(30, _array343_);
    _mxarray344_ = mclInitializeString(8, _array345_);
    _mxarray346_ = mclInitializeString(7, _array347_);
    _mxarray348_ = mclInitializeString(1, _array349_);
    _mxarray350_ = mclInitializeString(4, _array351_);
    _mxarray352_ = mclInitializeString(6, _array353_);
    _mxarray354_ = mclInitializeString(20, _array355_);
    _mxarray356_ = mclInitializeString(9, _array357_);
    _mxarray358_ = mclInitializeString(9, _array359_);
    _mxarray360_ = mclInitializeString(1, _array361_);
    _mxarray362_ = mclInitializeString(27, _array363_);
    _mxarray364_ = mclInitializeString(27, _array365_);
}

void TerminateModule_accosin(void) {
    mxDestroyArray(_mxarray364_);
    mxDestroyArray(_mxarray362_);
    mxDestroyArray(_mxarray360_);
    mxDestroyArray(_mxarray358_);
    mxDestroyArray(_mxarray356_);
    mxDestroyArray(_mxarray354_);
    mxDestroyArray(_mxarray352_);
    mxDestroyArray(_mxarray350_);
    mxDestroyArray(_mxarray348_);
    mxDestroyArray(_mxarray346_);
    mxDestroyArray(_mxarray344_);
    mxDestroyArray(_mxarray342_);
    mxDestroyArray(_mxarray340_);
    mxDestroyArray(_mxarray339_);
    mxDestroyArray(_mxarray337_);
    mxDestroyArray(_mxarray335_);
    mxDestroyArray(_mxarray333_);
    mxDestroyArray(_mxarray331_);
    mxDestroyArray(_mxarray329_);
    mxDestroyArray(_mxarray327_);
    mxDestroyArray(_mxarray325_);
    mxDestroyArray(_mxarray323_);
    mxDestroyArray(_mxarray321_);
    mxDestroyArray(_mxarray319_);
    mxDestroyArray(_mxarray317_);
    mxDestroyArray(_mxarray316_);
    mxDestroyArray(_mxarray314_);
    mxDestroyArray(_mxarray313_);
    mxDestroyArray(_mxarray311_);
    mxDestroyArray(_mxarray309_);
    mxDestroyArray(_mxarray307_);
    mxDestroyArray(_mxarray305_);
    mxDestroyArray(_mxarray303_);
    mxDestroyArray(_mxarray301_);
    mxDestroyArray(_mxarray299_);
    mxDestroyArray(_mxarray297_);
    mxDestroyArray(_mxarray295_);
    mxDestroyArray(_mxarray293_);
    mxDestroyArray(_mxarray291_);
    mxDestroyArray(_mxarray289_);
    mxDestroyArray(_mxarray287_);
    mxDestroyArray(_mxarray285_);
    mxDestroyArray(_mxarray283_);
    mxDestroyArray(_mxarray281_);
    mxDestroyArray(_mxarray279_);
    mxDestroyArray(_mxarray277_);
    mxDestroyArray(_mxarray276_);
    mxDestroyArray(_mxarray274_);
    mxDestroyArray(_mxarray272_);
    mxDestroyArray(_mxarray270_);
    mxDestroyArray(_mxarray268_);
    mxDestroyArray(_mxarray266_);
    mxDestroyArray(_mxarray265_);
    mxDestroyArray(_mxarray263_);
    mxDestroyArray(_mxarray262_);
    mxDestroyArray(_mxarray261_);
    mxDestroyArray(_mxarray260_);
    mxDestroyArray(_mxarray259_);
    mxDestroyArray(_mxarray257_);
    mxDestroyArray(_mxarray255_);
    mxDestroyArray(_mxarray253_);
    mxDestroyArray(_mxarray251_);
    mxDestroyArray(_mxarray249_);
    mxDestroyArray(_mxarray247_);
    mxDestroyArray(_mxarray245_);
    mxDestroyArray(_mxarray244_);
    mxDestroyArray(_mxarray242_);
    mxDestroyArray(_mxarray240_);
    mxDestroyArray(_mxarray238_);
    mxDestroyArray(_mxarray236_);
    mxDestroyArray(_mxarray234_);
    mxDestroyArray(_mxarray232_);
    mxDestroyArray(_mxarray230_);
    mxDestroyArray(_mxarray228_);
    mxDestroyArray(_mxarray226_);
    mxDestroyArray(_mxarray224_);
    mxDestroyArray(_mxarray222_);
    mxDestroyArray(_mxarray221_);
    mxDestroyArray(_mxarray219_);
    mxDestroyArray(_mxarray218_);
    mxDestroyArray(_mxarray217_);
    mxDestroyArray(_mxarray215_);
    mxDestroyArray(_mxarray214_);
    mxDestroyArray(_mxarray212_);
    mxDestroyArray(_mxarray210_);
    mxDestroyArray(_mxarray208_);
    mxDestroyArray(_mxarray206_);
    mxDestroyArray(_mxarray205_);
    mxDestroyArray(_mxarray204_);
    mxDestroyArray(_mxarray154_);
    mxDestroyArray(_mxarray202_);
    mxDestroyArray(_mxarray200_);
    mxDestroyArray(_mxarray198_);
    mxDestroyArray(_mxarray196_);
    mxDestroyArray(_mxarray194_);
    mxDestroyArray(_mxarray192_);
    mxDestroyArray(_mxarray190_);
    mxDestroyArray(_mxarray188_);
    mxDestroyArray(_mxarray186_);
    mxDestroyArray(_mxarray184_);
    mxDestroyArray(_mxarray182_);
    mxDestroyArray(_mxarray180_);
    mxDestroyArray(_mxarray178_);
    mxDestroyArray(_mxarray176_);
    mxDestroyArray(_mxarray174_);
    mxDestroyArray(_mxarray172_);
    mxDestroyArray(_mxarray170_);
    mxDestroyArray(_mxarray168_);
    mxDestroyArray(_mxarray166_);
    mxDestroyArray(_mxarray164_);
    mxDestroyArray(_mxarray162_);
    mxDestroyArray(_mxarray160_);
    mxDestroyArray(_mxarray158_);
    mxDestroyArray(_mxarray156_);
    mxDestroyArray(_mxarray46_);
    mxDestroyArray(_mxarray152_);
    mxDestroyArray(_mxarray150_);
    mxDestroyArray(_mxarray148_);
    mxDestroyArray(_mxarray146_);
    mxDestroyArray(_mxarray144_);
    mxDestroyArray(_mxarray142_);
    mxDestroyArray(_mxarray140_);
    mxDestroyArray(_mxarray138_);
    mxDestroyArray(_mxarray136_);
    mxDestroyArray(_mxarray134_);
    mxDestroyArray(_mxarray132_);
    mxDestroyArray(_mxarray130_);
    mxDestroyArray(_mxarray128_);
    mxDestroyArray(_mxarray126_);
    mxDestroyArray(_mxarray124_);
    mxDestroyArray(_mxarray122_);
    mxDestroyArray(_mxarray120_);
    mxDestroyArray(_mxarray118_);
    mxDestroyArray(_mxarray116_);
    mxDestroyArray(_mxarray114_);
    mxDestroyArray(_mxarray112_);
    mxDestroyArray(_mxarray110_);
    mxDestroyArray(_mxarray108_);
    mxDestroyArray(_mxarray106_);
    mxDestroyArray(_mxarray104_);
    mxDestroyArray(_mxarray102_);
    mxDestroyArray(_mxarray100_);
    mxDestroyArray(_mxarray98_);
    mxDestroyArray(_mxarray96_);
    mxDestroyArray(_mxarray94_);
    mxDestroyArray(_mxarray92_);
    mxDestroyArray(_mxarray90_);
    mxDestroyArray(_mxarray88_);
    mxDestroyArray(_mxarray86_);
    mxDestroyArray(_mxarray84_);
    mxDestroyArray(_mxarray82_);
    mxDestroyArray(_mxarray80_);
    mxDestroyArray(_mxarray78_);
    mxDestroyArray(_mxarray76_);
    mxDestroyArray(_mxarray74_);
    mxDestroyArray(_mxarray72_);
    mxDestroyArray(_mxarray70_);
    mxDestroyArray(_mxarray68_);
    mxDestroyArray(_mxarray66_);
    mxDestroyArray(_mxarray64_);
    mxDestroyArray(_mxarray62_);
    mxDestroyArray(_mxarray60_);
    mxDestroyArray(_mxarray58_);
    mxDestroyArray(_mxarray56_);
    mxDestroyArray(_mxarray54_);
    mxDestroyArray(_mxarray52_);
    mxDestroyArray(_mxarray50_);
    mxDestroyArray(_mxarray48_);
    mxDestroyArray(_mxarray45_);
    mxDestroyArray(_mxarray43_);
    mxDestroyArray(_mxarray29_);
    mxDestroyArray(_mxarray41_);
    mxDestroyArray(_mxarray39_);
    mxDestroyArray(_mxarray37_);
    mxDestroyArray(_mxarray35_);
    mxDestroyArray(_mxarray33_);
    mxDestroyArray(_mxarray31_);
    mxDestroyArray(_mxarray28_);
    mxDestroyArray(_mxarray26_);
    mxDestroyArray(_mxarray24_);
    mxDestroyArray(_mxarray22_);
    mxDestroyArray(_mxarray20_);
    mxDestroyArray(_mxarray18_);
    mxDestroyArray(_mxarray16_);
    mxDestroyArray(_mxarray14_);
    mxDestroyArray(_mxarray12_);
    mxDestroyArray(_mxarray10_);
    mxDestroyArray(_mxarray8_);
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray4_);
    mxDestroyArray(_mxarray2_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * mlfAccosin_ReadACCOSFile(mxArray * Filename);
static void mlxAccosin_ReadACCOSFile(int nlhs,
                                     mxArray * plhs[],
                                     int nrhs,
                                     mxArray * prhs[]);
static mxArray * mlfAccosin_NewSurface(mxArray * * ACCOSout,
                                       mxArray * ZEMAXin,
                                       mxArray * ACCOSin);
static void mlxAccosin_NewSurface(int nlhs,
                                  mxArray * plhs[],
                                  int nrhs,
                                  mxArray * prhs[]);
static mxArray * mlfAccosin_CleanFileName(mxArray * DirtyName);
static void mlxAccosin_CleanFileName(int nlhs,
                                     mxArray * plhs[],
                                     int nrhs,
                                     mxArray * prhs[]);
static void mlfAccosin_ReadOldConfigData(mxArray * fID);
static void mlxAccosin_ReadOldConfigData(int nlhs,
                                         mxArray * plhs[],
                                         int nrhs,
                                         mxArray * prhs[]);
static void mlfAccosin_ReadNewConfigData(mxArray * fID,
                                         mxArray * Config,
                                         mxArray * Surface);
static void mlxAccosin_ReadNewConfigData(int nlhs,
                                         mxArray * plhs[],
                                         int nrhs,
                                         mxArray * prhs[]);
static mxArray * Maccosin(int nargout_, mxArray * varargin);
static mxArray * Maccosin_ReadACCOSFile(int nargout_, mxArray * Filename);
static mxArray * Maccosin_NewSurface(mxArray * * ACCOSout,
                                     int nargout_,
                                     mxArray * ZEMAXin,
                                     mxArray * ACCOSin);
static mxArray * Maccosin_CleanFileName(int nargout_, mxArray * DirtyName);
static void Maccosin_ReadOldConfigData(mxArray * fID);
static void Maccosin_ReadNewConfigData(mxArray * fID,
                                       mxArray * Config,
                                       mxArray * Surface);

static mexFunctionTableEntry local_function_table_[5]
  = { { "ReadACCOSFile", mlxAccosin_ReadACCOSFile, 1, 1, NULL },
      { "NewSurface", mlxAccosin_NewSurface, 2, 2, NULL },
      { "CleanFileName", mlxAccosin_CleanFileName, 1, 1, NULL },
      { "ReadOldConfigData", mlxAccosin_ReadOldConfigData, 1, 0, NULL },
      { "ReadNewConfigData", mlxAccosin_ReadNewConfigData, 3, 0, NULL } };

_mexLocalFunctionTable _local_function_table_accosin
  = { 5, local_function_table_ };

/*
 * The function "mlfAccosin" contains the normal interface for the "accosin"
 * M-function from file "c:\projects\mzdde\accosin.m" (lines 1-57). This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
mxArray * mlfAccosin(mxArray * synthetic_varargin_argument, ...) {
    mxArray * varargin = NULL;
    int nargout = 1;
    mxArray * Status = NULL;
    mlfVarargin(&varargin, synthetic_varargin_argument, 1);
    mlfEnterNewContext(0, -1, varargin);
    Status = Maccosin(nargout, varargin);
    mlfRestorePreviousContext(0, 0);
    mxDestroyArray(varargin);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxAccosin" contains the feval interface for the "accosin"
 * M-function from file "c:\projects\mzdde\accosin.m" (lines 1-57). The feval
 * function calls the implementation version of accosin through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxAccosin(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin Line: 1 Column: "
            "1 The function \"accosin\" was called with mor"
            "e than the declared number of outputs (1)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    mlfEnterNewContext(0, 0);
    mprhs[0] = NULL;
    mlfAssign(&mprhs[0], mclCreateVararginCell(nrhs, prhs));
    mplhs[0] = Maccosin(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 0);
    plhs[0] = mplhs[0];
    mxDestroyArray(mprhs[0]);
}

/*
 * The function "mlfAccosin_ReadACCOSFile" contains the normal interface for
 * the "accosin/ReadACCOSFile" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 57-287). This function processes any
 * input arguments and passes them to the implementation version of the
 * function, appearing above.
 */
static mxArray * mlfAccosin_ReadACCOSFile(mxArray * Filename) {
    int nargout = 1;
    mxArray * Status = NULL;
    mlfEnterNewContext(0, 1, Filename);
    Status = Maccosin_ReadACCOSFile(nargout, Filename);
    mlfRestorePreviousContext(0, 1, Filename);
    return mlfReturnValue(Status);
}

/*
 * The function "mlxAccosin_ReadACCOSFile" contains the feval interface for the
 * "accosin/ReadACCOSFile" M-function from file "c:\projects\mzdde\accosin.m"
 * (lines 57-287). The feval function calls the implementation version of
 * accosin/ReadACCOSFile through this function. This function processes any
 * input arguments and passes them to the implementation version of the
 * function, appearing above.
 */
static void mlxAccosin_ReadACCOSFile(int nlhs,
                                     mxArray * plhs[],
                                     int nrhs,
                                     mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/ReadACCOSFile Line: 57 Co"
            "lumn: 1 The function \"accosin/ReadACCOSFile\" was call"
            "ed with more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/ReadACCOSFile Line: 57 Co"
            "lumn: 1 The function \"accosin/ReadACCOSFile\" was call"
            "ed with more than the declared number of inputs (1)."),
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
    mplhs[0] = Maccosin_ReadACCOSFile(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "mlfAccosin_NewSurface" contains the normal interface for the
 * "accosin/NewSurface" M-function from file "c:\projects\mzdde\accosin.m"
 * (lines 287-293). This function processes any input arguments and passes them
 * to the implementation version of the function, appearing above.
 */
static mxArray * mlfAccosin_NewSurface(mxArray * * ACCOSout,
                                       mxArray * ZEMAXin,
                                       mxArray * ACCOSin) {
    int nargout = 1;
    mxArray * ZEMAXout = NULL;
    mxArray * ACCOSout__ = NULL;
    mlfEnterNewContext(1, 2, ACCOSout, ZEMAXin, ACCOSin);
    if (ACCOSout != NULL) {
        ++nargout;
    }
    ZEMAXout = Maccosin_NewSurface(&ACCOSout__, nargout, ZEMAXin, ACCOSin);
    mlfRestorePreviousContext(1, 2, ACCOSout, ZEMAXin, ACCOSin);
    if (ACCOSout != NULL) {
        mclCopyOutputArg(ACCOSout, ACCOSout__);
    } else {
        mxDestroyArray(ACCOSout__);
    }
    return mlfReturnValue(ZEMAXout);
}

/*
 * The function "mlxAccosin_NewSurface" contains the feval interface for the
 * "accosin/NewSurface" M-function from file "c:\projects\mzdde\accosin.m"
 * (lines 287-293). The feval function calls the implementation version of
 * accosin/NewSurface through this function. This function processes any input
 * arguments and passes them to the implementation version of the function,
 * appearing above.
 */
static void mlxAccosin_NewSurface(int nlhs,
                                  mxArray * plhs[],
                                  int nrhs,
                                  mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[2];
    int i;
    if (nlhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/NewSurface Line: 287 Col"
            "umn: 1 The function \"accosin/NewSurface\" was called "
            "with more than the declared number of outputs (2)."),
          NULL);
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/NewSurface Line: 287 Co"
            "lumn: 1 The function \"accosin/NewSurface\" was calle"
            "d with more than the declared number of inputs (2)."),
          NULL);
    }
    for (i = 0; i < 2; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 2 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 2; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 2, mprhs[0], mprhs[1]);
    mplhs[0] = Maccosin_NewSurface(&mplhs[1], nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
    for (i = 1; i < 2 && i < nlhs; ++i) {
        plhs[i] = mplhs[i];
    }
    for (; i < 2; ++i) {
        mxDestroyArray(mplhs[i]);
    }
}

/*
 * The function "mlfAccosin_CleanFileName" contains the normal interface for
 * the "accosin/CleanFileName" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 293-310). This function processes any
 * input arguments and passes them to the implementation version of the
 * function, appearing above.
 */
static mxArray * mlfAccosin_CleanFileName(mxArray * DirtyName) {
    int nargout = 1;
    mxArray * CleanName = NULL;
    mlfEnterNewContext(0, 1, DirtyName);
    CleanName = Maccosin_CleanFileName(nargout, DirtyName);
    mlfRestorePreviousContext(0, 1, DirtyName);
    return mlfReturnValue(CleanName);
}

/*
 * The function "mlxAccosin_CleanFileName" contains the feval interface for the
 * "accosin/CleanFileName" M-function from file "c:\projects\mzdde\accosin.m"
 * (lines 293-310). The feval function calls the implementation version of
 * accosin/CleanFileName through this function. This function processes any
 * input arguments and passes them to the implementation version of the
 * function, appearing above.
 */
static void mlxAccosin_CleanFileName(int nlhs,
                                     mxArray * plhs[],
                                     int nrhs,
                                     mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/CleanFileName Line: 293 Co"
            "lumn: 1 The function \"accosin/CleanFileName\" was calle"
            "d with more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/CleanFileName Line: 293 C"
            "olumn: 1 The function \"accosin/CleanFileName\" was cal"
            "led with more than the declared number of inputs (1)."),
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
    mplhs[0] = Maccosin_CleanFileName(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "mlfAccosin_ReadOldConfigData" contains the normal interface
 * for the "accosin/ReadOldConfigData" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 310-325). This function processes any
 * input arguments and passes them to the implementation version of the
 * function, appearing above.
 */
static void mlfAccosin_ReadOldConfigData(mxArray * fID) {
    mlfEnterNewContext(0, 1, fID);
    Maccosin_ReadOldConfigData(fID);
    mlfRestorePreviousContext(0, 1, fID);
}

/*
 * The function "mlxAccosin_ReadOldConfigData" contains the feval interface for
 * the "accosin/ReadOldConfigData" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 310-325). The feval function calls the
 * implementation version of accosin/ReadOldConfigData through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
static void mlxAccosin_ReadOldConfigData(int nlhs,
                                         mxArray * plhs[],
                                         int nrhs,
                                         mxArray * prhs[]) {
    mxArray * mprhs[1];
    int i;
    if (nlhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/ReadOldConfigData Line: 310 "
            "Column: 1 The function \"accosin/ReadOldConfigData\" was c"
            "alled with more than the declared number of outputs (0)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/ReadOldConfigData Line: 310 "
            "Column: 1 The function \"accosin/ReadOldConfigData\" was c"
            "alled with more than the declared number of inputs (1)."),
          NULL);
    }
    for (i = 0; i < 1 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 1; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 1, mprhs[0]);
    Maccosin_ReadOldConfigData(mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
}

/*
 * The function "mlfAccosin_ReadNewConfigData" contains the normal interface
 * for the "accosin/ReadNewConfigData" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 325-337). This function processes any
 * input arguments and passes them to the implementation version of the
 * function, appearing above.
 */
static void mlfAccosin_ReadNewConfigData(mxArray * fID,
                                         mxArray * Config,
                                         mxArray * Surface) {
    mlfEnterNewContext(0, 3, fID, Config, Surface);
    Maccosin_ReadNewConfigData(fID, Config, Surface);
    mlfRestorePreviousContext(0, 3, fID, Config, Surface);
}

/*
 * The function "mlxAccosin_ReadNewConfigData" contains the feval interface for
 * the "accosin/ReadNewConfigData" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 325-337). The feval function calls the
 * implementation version of accosin/ReadNewConfigData through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
static void mlxAccosin_ReadNewConfigData(int nlhs,
                                         mxArray * plhs[],
                                         int nrhs,
                                         mxArray * prhs[]) {
    mxArray * mprhs[3];
    int i;
    if (nlhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/ReadNewConfigData Line: 325 "
            "Column: 1 The function \"accosin/ReadNewConfigData\" was c"
            "alled with more than the declared number of outputs (0)."),
          NULL);
    }
    if (nrhs > 3) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: accosin/ReadNewConfigData Line: 325 "
            "Column: 1 The function \"accosin/ReadNewConfigData\" was c"
            "alled with more than the declared number of inputs (3)."),
          NULL);
    }
    for (i = 0; i < 3 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 3; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
    Maccosin_ReadNewConfigData(mprhs[0], mprhs[1], mprhs[2]);
    mlfRestorePreviousContext(0, 3, mprhs[0], mprhs[1], mprhs[2]);
}

/*
 * The function "Maccosin" is the implementation version of the "accosin"
 * M-function from file "c:\projects\mzdde\accosin.m" (lines 1-57). It contains
 * the actual compiled code for that M-function. It is a static function and
 * must only be called from one of the interface functions, appearing below.
 */
/*
 * function Status = ACCOSin(varargin)
 */
static mxArray * Maccosin(int nargout_, mxArray * varargin) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_accosin);
    mxArray * Status = NULL;
    mxArray * iPath = NULL;
    mxArray * iFile = NULL;
    mxArray * FilterSpec = NULL;
    mxArray * ACCDir = NULL;
    mxArray * DefaultDir = NULL;
    mxArray * oldPWD = NULL;
    mxArray * ans = NULL;
    mxArray * RevDate = NULL;
    mxArray * Revision = NULL;
    mclCopyArray(&varargin);
    /*
     * % ACCOSin - Read an ACCOS .len file into ZEMAX.
     * %
     * % Usage : Status = ACCOSin
     * %
     * % The following return values are possible
     * %
     * %  0 : Success
     * % -1 : User Canceled operation or file not found
     * 
     * % Copyright 2002, Defencetek, CSIR
     * % $Revision: 1.3 $
     * 
     * % Still to implement and fix
     * % 1) Multiple configurations, both old and new ACCOS implementations, possibly with user assist.
     * % 2) Model glasses - at least get the refractive index close to right - the dispersion factor seems to be close to
     * %    impossible to handle elegantly.
     * % 3) Write index file for later fixup by ZPL to include lens title and comments, or perform manual
     * %    fix of .ZMX file after zSaveFile.
     * % 4) Copy penultimate surface shape to IMA surface and delete penultimate surface
     * % 5) Do something with last lens which does not have a LIB PUT command.
     * 
     * Revision = '$Revision: 1.3 $';
     */
    mlfAssign(&Revision, _mxarray0_);
    /*
     * RevDate = '$Date: 2002-11-19 14:06:46+02 $';
     */
    mlfAssign(&RevDate, _mxarray2_);
    /*
     * 
     * Revision = Revision(11:(size(Revision,2)-1));
     */
    mlfAssign(
      &Revision,
      mclArrayRef1(
        mclVv(Revision, "Revision"),
        mlfColon(
          _mxarray4_,
          mclMinus(
            mlfSize(
              mclValueVarargout(), mclVv(Revision, "Revision"), _mxarray5_),
            _mxarray6_),
          NULL)));
    /*
     * RevDate = RevDate(7:(size(RevDate,2)-1));
     */
    mlfAssign(
      &RevDate,
      mclArrayRef1(
        mclVv(RevDate, "RevDate"),
        mlfColon(
          _mxarray7_,
          mclMinus(
            mlfSize(mclValueVarargout(), mclVv(RevDate, "RevDate"), _mxarray5_),
            _mxarray6_),
          NULL)));
    /*
     * 
     * disp(['ACCOS Leno Importer for ZEMAX. Version' Revision]);
     */
    mlfDisp(mlfHorzcat(_mxarray8_, mclVv(Revision, "Revision"), NULL));
    /*
     * disp(['Derek Griffith,' RevDate]);
     */
    mlfDisp(mlfHorzcat(_mxarray10_, mclVv(RevDate, "RevDate"), NULL));
    /*
     * 
     * Status = zDDEInit;
     */
    mlfAssign(&Status, mlfZddeinit());
    /*
     * if (Status)
     */
    if (mlfTobool(mclVv(Status, "Status"))) {
        /*
         * uiwait(msgbox('ZEMAX is not Running.', 'ZEMAX Error', 'error', 'modal'));
         */
        mlfUiwait(
          mlfNMsgbox(
            0,
            mclValueVarargout(),
            _mxarray12_,
            _mxarray14_,
            _mxarray16_,
            _mxarray18_,
            NULL));
        /*
         * return;
         */
        goto return_;
    /*
     * end;
     */
    }
    /*
     * 
     * oldPWD = PWD;
     */
    mlfAssign(&oldPWD, mlfPwd());
    /*
     * DefaultDir = 'c:\popdist';
     */
    mlfAssign(&DefaultDir, _mxarray20_);
    /*
     * if (~exist(DefaultDir, 'dir')), DefaultDir = 'c:\'; end;
     */
    if (mclNotBool(mlfExist(mclVv(DefaultDir, "DefaultDir"), _mxarray22_))) {
        mlfAssign(&DefaultDir, _mxarray24_);
    }
    /*
     * 
     * 
     * ACCDir = getenv('ACCOS');
     */
    mlfAssign(&ACCDir, mlfGetenv(_mxarray26_));
    /*
     * if (strcmp(ACCDir, '')), ACCDir = DefaultDir; end;
     */
    if (mlfTobool(mlfStrcmp(mclVv(ACCDir, "ACCDir"), _mxarray28_))) {
        mlfAssign(&ACCDir, mclVv(DefaultDir, "DefaultDir"));
    }
    /*
     * cd(ACCDir);
     */
    mclAssignAns(&ans, mlfNCd(0, mclVv(ACCDir, "ACCDir")));
    /*
     * FilterSpec = {'cpfile', 'ACCOS CPFILE'; '*.len;*.leno', 'ACCOS Leno Files'; '*.*', 'All Files' }; 
     */
    mlfAssign(&FilterSpec, _mxarray29_);
    /*
     * [iFile, iPath] = uigetfile(FilterSpec, 'Open ACCOS File');
     */
    mlfAssign(
      &iFile,
      mlfUigetfile(
        &iPath, mclVv(FilterSpec, "FilterSpec"), _mxarray43_, NULL, NULL));
    /*
     * if (iFile) % Seem to have a file to read ACCOS input from
     */
    if (mlfTobool(mclVv(iFile, "iFile"))) {
        /*
         * Status = ReadACCOSFile(fullfile(iPath, iFile));    
         */
        mlfAssign(
          &Status,
          mlfAccosin_ReadACCOSFile(
            mlfFullfile(mclVv(iPath, "iPath"), mclVv(iFile, "iFile"), NULL)));
    /*
     * else
     */
    } else {
        /*
         * Status = -1; zddeclose; cd(oldPWD); return;
         */
        mlfAssign(&Status, _mxarray45_);
        mclAssignAns(&ans, mlfZddeclose());
        mclAssignAns(&ans, mlfNCd(0, mclVv(oldPWD, "oldPWD")));
        goto return_;
    /*
     * end
     */
    }
    /*
     * 
     * cd(oldPWD);
     */
    mclAssignAns(&ans, mlfNCd(0, mclVv(oldPWD, "oldPWD")));
    /*
     * 
     * 
     */
    return_:
    mclValidateOutput(Status, 1, nargout_, "Status", "accosin");
    mxDestroyArray(Revision);
    mxDestroyArray(RevDate);
    mxDestroyArray(ans);
    mxDestroyArray(oldPWD);
    mxDestroyArray(DefaultDir);
    mxDestroyArray(ACCDir);
    mxDestroyArray(FilterSpec);
    mxDestroyArray(iFile);
    mxDestroyArray(iPath);
    mxDestroyArray(varargin);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
}

/*
 * The function "Maccosin_ReadACCOSFile" is the implementation version of the
 * "accosin/ReadACCOSFile" M-function from file "c:\projects\mzdde\accosin.m"
 * (lines 57-287). It contains the actual compiled code for that M-function. It
 * is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function Status = ReadACCOSFile(Filename)
 */
static mxArray * Maccosin_ReadACCOSFile(int nargout_, mxArray * Filename) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_accosin);
    mxArray * Status = NULL;
    mxArray * LensFileName = NULL;
    mxArray * CleanTitle = NULL;
    mxArray * Block = NULL;
    mxArray * Answer = NULL;
    mxArray * Reply = NULL;
    mxArray * DummyFile = NULL;
    mxArray * DummySurface = NULL;
    mxArray * Surface = NULL;
    mxArray * Config = NULL;
    mxArray * PrimaryWave = NULL;
    mxArray * Weight = NULL;
    mxArray * NumWeights = NULL;
    mxArray * Wv = NULL;
    mxArray * RayHeight = NULL;
    mxArray * Offset = NULL;
    mxArray * Ofset = NULL;
    mxArray * ScaleFactor = NULL;
    mxArray * ScaleFac = NULL;
    mxArray * ZEMAXPikupSurface = NULL;
    mxArray * ACCOSPikupSurface = NULL;
    mxArray * PikupSurf = NULL;
    mxArray * LenSys = NULL;
    mxArray * DF = NULL;
    mxArray * RN = NULL;
    mxArray * Glass = NULL;
    mxArray * Found = NULL;
    mxArray * CLAPRadius = NULL;
    mxArray * COBSRadius = NULL;
    mxArray * Aper = NULL;
    mxArray * ParmCount = NULL;
    mxArray * Parms = NULL;
    mxArray * Type = NULL;
    mxArray * FieldPoints = NULL;
    mxArray * Thick = NULL;
    mxArray * Ag = NULL;
    mxArray * Af = NULL;
    mxArray * Ae = NULL;
    mxArray * Ad = NULL;
    mxArray * Conic = NULL;
    mxArray * Curv = NULL;
    mxArray * Radius = NULL;
    mxArray * PupilRadius = NULL;
    mxArray * CheckACCOSSurface = NULL;
    mxArray * Token = NULL;
    mxArray * Comment = NULL;
    mxArray * StopSurface = NULL;
    mxArray * LITitle = NULL;
    mxArray * NumberComments = NULL;
    mxArray * LensComments = NULL;
    mxArray * FieldType = NULL;
    mxArray * WaveWeights = NULL;
    mxArray * NumWaves = NULL;
    mxArray * Wavelengths = NULL;
    mxArray * YObjectHeight = NULL;
    mxArray * XObjectHeight = NULL;
    mxArray * YObjectAngle = NULL;
    mxArray * XObjectAngle = NULL;
    mxArray * ACCOSSurface = NULL;
    mxArray * ZEMAXSurface = NULL;
    mxArray * Title = NULL;
    mxArray * ans = NULL;
    mxArray * Rest = NULL;
    mxArray * Directive = NULL;
    mxArray * LenLine = NULL;
    mxArray * fID = NULL;
    mxArray * UnknownPikups = NULL;
    mxArray * UnknownDirectives = NULL;
    mxArray * ZEMAXMaterials = NULL;
    mxArray * ACCOSMaterials = NULL;
    mxArray * LibDumpPath = NULL;
    mclCopyArray(&Filename);
    /*
     * % Read in the ACCOS LEN File
     * LibDumpPath = '';
     */
    mlfAssign(&LibDumpPath, _mxarray28_);
    /*
     * % Here are the known ACCOS materials
     * ACCOSMaterials = {...
     */
    mlfAssign(&ACCOSMaterials, _mxarray46_);
    /*
     * 'GERM','ARTRI','SILICN','SAPHIR','BAF','SILICA','IRT2','IRT4',...
     * 'CAFL','NAF','LIF','NACL','KI','KCL','KBR','AMTIR1',...
     * 'RZNSE','RZNS','WAT20C','IRT1','PBF2','CDF2','GAAS','ZNS',...
     * 'ZNSE','CDTE','SCGERM','MGF2','KRS-5','LIFX','KBRX','KCLX',...
     * 'KIX','NACLX','CALX-O','CALX-E','CSBRX','CSIX','IRGN6X','IRG11X',...
     * 'MGFX-O','MGFX-E','KDPX-O','KDPX-E','AGCLX','STRTIX','KRS5X','IRGN6X',...
     * 'IRG11X','QRZX-O','QRZX-E','MGALO'...
     * 'SF56', 'LAF21', 'LASF30'...
     * }';
     * 
     * % and the best known equivalent ZEMAX materials
     * % There may still be errors in this list
     * ZEMAXMaterials = {...
     */
    mlfAssign(&ZEMAXMaterials, _mxarray154_);
    /*
     * 'GERMANIUM','ARTRI','SILICON','SAPPHIRE','BAF','F_SILICA','IRT2','IRT4',...
     * 'CAFL','NAF','LIF','NACL','KI','KCL','KBR','AMTIR1',...
     * 'ZNSE','CLEARTRAN','WATER','IRT1','PBF2','CDF2','GAAS','ZNS_BROAD',...
     * 'ZNSE','CDTE','SCGERM','MGF2','KRS5','LIF','KBR','KCL',...
     * 'KI','NACL','CALCITE','CALCITE-E','CSBR','CSI','IRGN6','IRG11',...
     * 'MGF2','MGF2-E','KDP','KDP-E','AGCL','STRTI','KRS5','IRGN6',...
     * 'IRG11','QUARTZ','QUARTZ-E','MGALO'...
     * 'N-SF56', 'LAFN21', 'LASFN30'...
     * }';
     * 
     * UnknownDirectives = {};
     */
    mlfAssign(&UnknownDirectives, _mxarray204_);
    /*
     * UnknownPikups = {};
     */
    mlfAssign(&UnknownPikups, _mxarray204_);
    /*
     * Status = 0;
     */
    mlfAssign(&Status, _mxarray205_);
    /*
     * 
     * fID = fopen(Filename, 'rt');
     */
    mlfAssign(
      &fID,
      mlfFopen(NULL, NULL, mclVa(Filename, "Filename"), _mxarray206_, NULL));
    /*
     * % Now process the entire contents of the file
     * while 1
     */
    for (;;) {
        /*
         * LenLine = fgetl(fID);
         */
        mlfAssign(&LenLine, mlfFgetl(mclVv(fID, "fID")));
        /*
         * if ~ischar(LenLine), break, end; % End of file
         */
        if (mclNotBool(mlfIschar(mclVv(LenLine, "LenLine")))) {
            break;
        }
        /*
         * LenLine = upper(LenLine); % Convert to upper case
         */
        mlfAssign(&LenLine, mlfUpper(mclVv(LenLine, "LenLine")));
        /*
         * [Directive, Rest] = strtok(LenLine, ' ,'); % Take the directive from the start of the line
         */
        mlfAssign(
          &Directive,
          mlfNStrtok(2, &Rest, mclVv(LenLine, "LenLine"), _mxarray208_));
        /*
         * if (Directive)
         */
        if (mlfTobool(mclVv(Directive, "Directive"))) {
            /*
             * switch Directive
             */
            mxArray * v_ = mclInitialize(mclVv(Directive, "Directive"));
            if (mclSwitchCompare(v_, _mxarray210_)) {
                /*
                 * case 'LENS', zNewLens; Title = Rest(2:size(Rest,2)); % Great, but currently no way to change the lens title in the DDE server !
                 */
                mclAssignAns(&ans, mlfZnewlens());
                mlfAssign(
                  &Title,
                  mclArrayRef1(
                    mclVv(Rest, "Rest"),
                    mlfColon(
                      _mxarray5_,
                      mlfSize(
                        mclValueVarargout(), mclVv(Rest, "Rest"), _mxarray5_),
                      NULL)));
                /*
                 * ZEMAXSurface = 0; ACCOSSurface = 0;     % Maintain two pointers, because coordinate breaks will cause a mismatch
                 */
                mlfAssign(&ZEMAXSurface, _mxarray205_);
                mlfAssign(&ACCOSSurface, _mxarray205_);
                /*
                 * XObjectAngle = 0; YObjectAngle = 0; XObjectHeight = 0; YObjectHeight = 0;
                 */
                mlfAssign(&XObjectAngle, _mxarray205_);
                mlfAssign(&YObjectAngle, _mxarray205_);
                mlfAssign(&XObjectHeight, _mxarray205_);
                mlfAssign(&YObjectHeight, _mxarray205_);
                /*
                 * Wavelengths = [0.5876; 0.48613; 0.65627; 0.43584; 0.70653]; NumWaves = 5;
                 */
                mlfAssign(&Wavelengths, _mxarray212_);
                mlfAssign(&NumWaves, _mxarray214_);
                /*
                 * WaveWeights = [1.0   ; 1.0    ; 1.0    ; 1.0    ; 1.0    ]; FieldType = 0;
                 */
                mlfAssign(&WaveWeights, _mxarray215_);
                mlfAssign(&FieldType, _mxarray205_);
                /*
                 * zSetWaveMatrix([Wavelengths WaveWeights]); LensComments = {}; NumberComments = 0; LITitle = '';
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetwavematrix(
                    mlfHorzcat(
                      mclVv(Wavelengths, "Wavelengths"),
                      mclVv(WaveWeights, "WaveWeights"),
                      NULL)));
                mlfAssign(&LensComments, _mxarray204_);
                mlfAssign(&NumberComments, _mxarray205_);
                mlfAssign(&LITitle, _mxarray28_);
                /*
                 * StopSurface = 0;
                 */
                mlfAssign(&StopSurface, _mxarray205_);
                /*
                 * zSetLabel(1,1001); zSetLabel(2,1002);   % Label these surfaces high for later fixup
                 */
                mclAssignAns(&ans, mlfZsetlabel(_mxarray6_, _mxarray217_));
                mclAssignAns(&ans, mlfZsetlabel(_mxarray5_, _mxarray218_));
            /*
             * case 'LI',   LITitle = LenLine(4:size(LenLine,2));         % Same dilemma
             */
            } else if (mclSwitchCompare(v_, _mxarray219_)) {
                mlfAssign(
                  &LITitle,
                  mclArrayRef1(
                    mclVv(LenLine, "LenLine"),
                    mlfColon(
                      _mxarray221_,
                      mlfSize(
                        mclValueVarargout(),
                        mclVv(LenLine, "LenLine"),
                        _mxarray5_),
                      NULL)));
                /*
                 * disp(['Reading :' LITitle]);
                 */
                mlfDisp(
                  mlfHorzcat(_mxarray222_, mclVv(LITitle, "LITitle"), NULL));
            /*
             * case 'LIC',  NumberComments = NumberComments + 1; LensComments{NumberComments} = Rest(2:size(Rest,2));
             */
            } else if (mclSwitchCompare(v_, _mxarray224_)) {
                mlfAssign(
                  &NumberComments,
                  mclPlus(mclVv(NumberComments, "NumberComments"), _mxarray6_));
                mlfIndexAssign(
                  &LensComments,
                  "{?}",
                  mclVv(NumberComments, "NumberComments"),
                  mclArrayRef1(
                    mclVv(Rest, "Rest"),
                    mlfColon(
                      _mxarray5_,
                      mlfSize(
                        mclValueVarargout(), mclVv(Rest, "Rest"), _mxarray5_),
                      NULL)));
            /*
             * case 'C',    Comment = LenLine(2:size(LenLine,2));
             */
            } else if (mclSwitchCompare(v_, _mxarray226_)) {
                mlfAssign(
                  &Comment,
                  mclArrayRef1(
                    mclVv(LenLine, "LenLine"),
                    mlfColon(
                      _mxarray5_,
                      mlfSize(
                        mclValueVarargout(),
                        mclVv(LenLine, "LenLine"),
                        _mxarray5_),
                      NULL)));
                /*
                 * [Token, Rest] = strtok(Rest, ' ,');
                 */
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * switch Token
                 */
                {
                    mxArray * v_0 = mclInitialize(mclVv(Token, "Token"));
                    if (mclSwitchCompare(v_0, _mxarray228_)) {
                        /*
                         * case 'SURFACE', CheckACCOSSurface = str2num(strtok(Rest, ' ,'));
                         */
                        mlfAssign(
                          &CheckACCOSSurface,
                          mlfStr2num(
                            NULL,
                            mlfNStrtok(
                              1, NULL, mclVv(Rest, "Rest"), _mxarray208_)));
                    /*
                     * otherwise,
                     */
                    } else {
                    /*
                     * end;
                     */
                    }
                    mxDestroyArray(v_0);
                }
            /*
             * case 'SAY', Token = strtok(Rest, ' ,'); PupilRadius = str2double(Token); zSetSystemAper(0, 1, 2*PupilRadius);
             */
            } else if (mclSwitchCompare(v_, _mxarray230_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(&PupilRadius, mlfStr2double(mclVv(Token, "Token")));
                mclAssignAns(
                  &ans,
                  mlfZsetsystemaper(
                    _mxarray205_,
                    _mxarray6_,
                    mclMtimes(_mxarray5_, mclVv(PupilRadius, "PupilRadius"))));
            /*
             * case 'SCY', [Token, Rest] = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray232_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * if (strcmp(Token, 'FANG'))
                 */
                if (mlfTobool(mlfStrcmp(mclVv(Token, "Token"), _mxarray234_))) {
                    /*
                     * [Token, Rest] = strtok(Rest, ' ,'); YObjectAngle = str2double(Token); YObjectHeight = 0.0; FieldType = 0;
                     */
                    mlfAssign(
                      &Token,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                    mlfAssign(
                      &YObjectAngle, mlfStr2double(mclVv(Token, "Token")));
                    mlfAssign(&YObjectHeight, _mxarray205_);
                    mlfAssign(&FieldType, _mxarray205_);
                /*
                 * else
                 */
                } else {
                    /*
                     * YObjectHeight = str2double(Token); YObjectAngle = 0.0; FieldType = 1;
                     */
                    mlfAssign(
                      &YObjectHeight, mlfStr2double(mclVv(Token, "Token")));
                    mlfAssign(&YObjectAngle, _mxarray205_);
                    mlfAssign(&FieldType, _mxarray6_);
                /*
                 * end;
                 */
                }
            /*
             * case 'SCX', [Token, Rest] = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray236_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * if (strcmp(Token, 'FANG'))
                 */
                if (mlfTobool(mlfStrcmp(mclVv(Token, "Token"), _mxarray234_))) {
                    /*
                     * [Token, Rest] = strtok(Rest, ' ,'); XObjectAngle = str2double(Token); XObjectHeight = 0.0; FieldType = 0;
                     */
                    mlfAssign(
                      &Token,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                    mlfAssign(
                      &XObjectAngle, mlfStr2double(mclVv(Token, "Token")));
                    mlfAssign(&XObjectHeight, _mxarray205_);
                    mlfAssign(&FieldType, _mxarray205_);
                /*
                 * else
                 */
                } else {
                    /*
                     * XObjectHeight = str2double(Token); XObjectAngle = 0.0; FieldType = 1;
                     */
                    mlfAssign(
                      &XObjectHeight, mlfStr2double(mclVv(Token, "Token")));
                    mlfAssign(&XObjectAngle, _mxarray205_);
                    mlfAssign(&FieldType, _mxarray6_);
                /*
                 * end;
                 */
                }
            /*
             * case 'RD', Token = strtok(Rest, ' ,'); Radius = str2double(Token); if (Radius ~= 0), zSetSurfaceData(ZEMAXSurface, 2, 1/Radius); end;
             */
            } else if (mclSwitchCompare(v_, _mxarray238_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(&Radius, mlfStr2double(mclVv(Token, "Token")));
                if (mclNeBool(mclVv(Radius, "Radius"), _mxarray205_)) {
                    mclAssignAns(
                      &ans,
                      mlfZsetsurfacedata(
                        mclVv(ZEMAXSurface, "ZEMAXSurface"),
                        _mxarray5_,
                        mclMrdivide(_mxarray6_, mclVv(Radius, "Radius"))));
                }
            /*
             * case 'CV', Token = strtok(Rest, ' ,'); Curv = str2double(Token); zSetSurfaceData(ZEMAXSurface, 2, Curv);
             */
            } else if (mclSwitchCompare(v_, _mxarray240_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(&Curv, mlfStr2double(mclVv(Token, "Token")));
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray5_,
                    mclVv(Curv, "Curv")));
            /*
             * case 'CC', Token = strtok(Rest, ' ,'); Conic = str2double(Token); zSetSurfaceData(ZEMAXSurface, 6, Conic);
             */
            } else if (mclSwitchCompare(v_, _mxarray242_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(&Conic, mlfStr2double(mclVv(Token, "Token")));
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray244_,
                    mclVv(Conic, "Conic")));
            /*
             * case 'ASPH', [Token, Rest] = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray245_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * switch (Token) 
                 */
                {
                    mxArray * v_1 = mclInitialize(mclVv(Token, "Token"));
                    if (mclSwitchCompare(v_1, _mxarray247_)) {
                        /*
                         * case 'RSIRS', disp('Rotationally Symmetric Spline Surface Definition Ignored');
                         */
                        mlfDisp(_mxarray249_);
                    /*
                     * case 'IRS'  , disp('Asymmetric Spline Surface Definition Ignored');
                     */
                    } else if (mclSwitchCompare(v_1, _mxarray251_)) {
                        mlfDisp(_mxarray253_);
                    /*
                     * otherwise   , if (Token), Ad = str2double(Token); else Ad = 0.0; end;
                     */
                    } else {
                        if (mlfTobool(mclVv(Token, "Token"))) {
                            mlfAssign(
                              &Ad, mlfStr2double(mclVv(Token, "Token")));
                        } else {
                            mlfAssign(&Ad, _mxarray205_);
                        }
                        /*
                         * [Token, Rest] = strtok(Rest, ' ,'); if (Token), Ae = str2double(Token); else Ae = 0.0; end;
                         */
                        mlfAssign(
                          &Token,
                          mlfNStrtok(
                            2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                        if (mlfTobool(mclVv(Token, "Token"))) {
                            mlfAssign(
                              &Ae, mlfStr2double(mclVv(Token, "Token")));
                        } else {
                            mlfAssign(&Ae, _mxarray205_);
                        }
                        /*
                         * [Token, Rest] = strtok(Rest, ' ,'); if (Token), Af = str2double(Token); else Af = 0.0; end;
                         */
                        mlfAssign(
                          &Token,
                          mlfNStrtok(
                            2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                        if (mlfTobool(mclVv(Token, "Token"))) {
                            mlfAssign(
                              &Af, mlfStr2double(mclVv(Token, "Token")));
                        } else {
                            mlfAssign(&Af, _mxarray205_);
                        }
                        /*
                         * [Token, Rest] = strtok(Rest, ' ,'); if (Token), Ag = str2double(Token); else Ag = 0.0; end;
                         */
                        mlfAssign(
                          &Token,
                          mlfNStrtok(
                            2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                        if (mlfTobool(mclVv(Token, "Token"))) {
                            mlfAssign(
                              &Ag, mlfStr2double(mclVv(Token, "Token")));
                        } else {
                            mlfAssign(&Ag, _mxarray205_);
                        }
                        /*
                         * zSetSurfaceData(ZEMAXSurface, 0, 'EVENASPH'); zSetSurfaceParamVector(ZEMAXSurface, [0, 0, Ad, Ae, Af, Ag]);
                         */
                        mclAssignAns(
                          &ans,
                          mlfZsetsurfacedata(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray205_,
                            _mxarray255_));
                        mclAssignAns(
                          &ans,
                          mlfZsetsurfaceparamvector(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            mlfHorzcat(
                              _mxarray205_,
                              _mxarray205_,
                              mclVv(Ad, "Ad"),
                              mclVv(Ae, "Ae"),
                              mclVv(Af, "Af"),
                              mclVv(Ag, "Ag"),
                              NULL)));
                    /*
                     * end;
                     */
                    }
                    mxDestroyArray(v_1);
                }
            /*
             * case 'TH', Token = strtok(Rest, ' ,'); Thick = str2Double(Token); zSetSurfaceData(ZEMAXSurface, 3, Thick);
             */
            } else if (mclSwitchCompare(v_, _mxarray257_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(&Thick, mlfStr2double(mclVv(Token, "Token")));
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray259_,
                    mclVv(Thick, "Thick")));
                /*
                 * if (ZEMAXSurface == 0) % Set the field angles depending on whether object distance is 'infinity'
                 */
                if (mclEqBool(
                      mclVv(ZEMAXSurface, "ZEMAXSurface"), _mxarray205_)) {
                    /*
                     * if (Thick >= 1e10)
                     */
                    if (mclGeBool(mclVv(Thick, "Thick"), _mxarray260_)) {
                        /*
                         * if (FieldType == 1), YObjectAngle = 360.0 * atan(YObjectHeight / Thick) / 6.283185308; FieldType = 0;
                         */
                        if (mclEqBool(
                              mclVv(FieldType, "FieldType"), _mxarray6_)) {
                            mlfAssign(
                              &YObjectAngle,
                              mclMrdivide(
                                mclMtimes(
                                  _mxarray261_,
                                  mlfAtan(
                                    mclMrdivide(
                                      mclVv(YObjectHeight, "YObjectHeight"),
                                      mclVv(Thick, "Thick")))),
                                _mxarray262_));
                            mlfAssign(&FieldType, _mxarray205_);
                            /*
                             * XObjectAngle = 360.0 * atan(XObjectHeight / Thick) / 6.283185308; end;    
                             */
                            mlfAssign(
                              &XObjectAngle,
                              mclMrdivide(
                                mclMtimes(
                                  _mxarray261_,
                                  mlfAtan(
                                    mclMrdivide(
                                      mclVv(XObjectHeight, "XObjectHeight"),
                                      mclVv(Thick, "Thick")))),
                                _mxarray262_));
                        }
                    /*
                     * end;
                     */
                    }
                    /*
                     * switch (FieldType)
                     */
                    {
                        mxArray * v_2
                          = mclInitialize(mclVv(FieldType, "FieldType"));
                        if (mclSwitchCompare(v_2, _mxarray205_)) {
                            /*
                             * case 0, FieldPoints = [0, 0, 1; XObjectAngle, 0.7 * YObjectAngle, 1; 0, YObjectAngle, 1]; zSetFieldMatrix(0, FieldPoints);
                             */
                            mlfAssign(
                              &FieldPoints,
                              mlfVertcat(
                                _mxarray263_,
                                mlfHorzcat(
                                  mclVv(XObjectAngle, "XObjectAngle"),
                                  mclMtimes(
                                    _mxarray265_,
                                    mclVv(YObjectAngle, "YObjectAngle")),
                                  _mxarray6_,
                                  NULL),
                                mlfHorzcat(
                                  _mxarray205_,
                                  mclVv(YObjectAngle, "YObjectAngle"),
                                  _mxarray6_,
                                  NULL),
                                NULL));
                            mclAssignAns(
                              &ans,
                              mlfZsetfieldmatrix(
                                _mxarray205_,
                                mclVv(FieldPoints, "FieldPoints")));
                        /*
                         * case 1, FieldPoints = [0, 0, 1; XObjectHeight, 0.7 * YObjectHeight, 1; 0, YObjectHeight, 1]; zSetFieldMatrix(1, FieldPoints);
                         */
                        } else if (mclSwitchCompare(v_2, _mxarray6_)) {
                            mlfAssign(
                              &FieldPoints,
                              mlfVertcat(
                                _mxarray263_,
                                mlfHorzcat(
                                  mclVv(XObjectHeight, "XObjectHeight"),
                                  mclMtimes(
                                    _mxarray265_,
                                    mclVv(YObjectHeight, "YObjectHeight")),
                                  _mxarray6_,
                                  NULL),
                                mlfHorzcat(
                                  _mxarray205_,
                                  mclVv(YObjectHeight, "YObjectHeight"),
                                  _mxarray6_,
                                  NULL),
                                NULL));
                            mclAssignAns(
                              &ans,
                              mlfZsetfieldmatrix(
                                _mxarray6_, mclVv(FieldPoints, "FieldPoints")));
                        /*
                         * end;
                         */
                        }
                        mxDestroyArray(v_2);
                    }
                /*
                 * end;
                 */
                }
            /*
             * case 'CLAP',   [Type, Rest] = strtok(Rest, ' ,'); [Token, Rest] = strtok(Rest, ' ,');  % Get all the numerical parameters of the command
             */
            } else if (mclSwitchCompare(v_, _mxarray266_)) {
                mlfAssign(
                  &Type,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * Parms = [0 0 0 0 0];
                 */
                mlfAssign(&Parms, _mxarray268_);
                /*
                 * ParmCount = 0; while (Token), ParmCount = ParmCount + 1; Parms(ParmCount) = str2double(Token); [Token, Rest] = strtok(Rest, ' ,'); end;
                 */
                mlfAssign(&ParmCount, _mxarray205_);
                while (mlfTobool(mclVv(Token, "Token"))) {
                    mlfAssign(
                      &ParmCount,
                      mclPlus(mclVv(ParmCount, "ParmCount"), _mxarray6_));
                    mclArrayAssign1(
                      &Parms,
                      mlfStr2double(mclVv(Token, "Token")),
                      mclVv(ParmCount, "ParmCount"));
                    mlfAssign(
                      &Token,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                }
                /*
                 * switch Type
                 */
                {
                    mxArray * v_3 = mclInitialize(mclVv(Type, "Type"));
                    if (mclSwitchCompare(v_3, _mxarray270_)) {
                        /*
                         * case 'RECT', zSetAperture(ZEMAXSurface, 4, Parms(2), Parms(1), Parms(4), Parms(3), '');
                         */
                        mclAssignAns(
                          &ans,
                          mlfZsetaperture(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray221_,
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 2),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 1),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 4),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 3),
                            _mxarray28_));
                    /*
                     * case 'ELIP', zSetAperture(ZEMAXSurface, 6, Parms(2), Parms(1), Parms(4), Parms(3), '');
                     */
                    } else if (mclSwitchCompare(v_3, _mxarray272_)) {
                        mclAssignAns(
                          &ans,
                          mlfZsetaperture(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray244_,
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 2),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 1),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 4),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 3),
                            _mxarray28_));
                    /*
                     * otherwise  , Aper = zGetAperture(ZEMAXSurface); if (Aper(1)==1), COBSRadius = Aper(2); else COBSRadius = 0; end;
                     */
                    } else {
                        mlfAssign(
                          &Aper,
                          mlfZgetaperture(mclVv(ZEMAXSurface, "ZEMAXSurface")));
                        if (mclEqBool(
                              mclIntArrayRef1(mclVv(Aper, "Aper"), 1),
                              _mxarray6_)) {
                            mlfAssign(
                              &COBSRadius,
                              mclIntArrayRef1(mclVv(Aper, "Aper"), 2));
                        } else {
                            mlfAssign(&COBSRadius, _mxarray205_);
                        }
                        /*
                         * CLAPRadius = str2double(Type); zSetAperture(ZEMAXSurface, 1, COBSRadius, CLAPRadius, Parms(3), Parms(2), '');
                         */
                        mlfAssign(
                          &CLAPRadius, mlfStr2double(mclVv(Type, "Type")));
                        mclAssignAns(
                          &ans,
                          mlfZsetaperture(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray6_,
                            mclVv(COBSRadius, "COBSRadius"),
                            mclVv(CLAPRadius, "CLAPRadius"),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 3),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 2),
                            _mxarray28_));
                    /*
                     * end;
                     */
                    }
                    mxDestroyArray(v_3);
                }
            /*
             * case 'COBS',   [Type, Rest] = strtok(Rest, ' ,'); [Token, Rest] = strtok(Rest, ' ,');  % Get all the numerical parameters of the command
             */
            } else if (mclSwitchCompare(v_, _mxarray274_)) {
                mlfAssign(
                  &Type,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * Parms = [0 0 0 0 0];
                 */
                mlfAssign(&Parms, _mxarray268_);
                /*
                 * ParmCount = 0; while (Token), ParmCount = ParmCount + 1; Parms(ParmCount) = str2double(Token); [Token, Rest] = strtok(Rest, ' ,'); end;
                 */
                mlfAssign(&ParmCount, _mxarray205_);
                while (mlfTobool(mclVv(Token, "Token"))) {
                    mlfAssign(
                      &ParmCount,
                      mclPlus(mclVv(ParmCount, "ParmCount"), _mxarray6_));
                    mclArrayAssign1(
                      &Parms,
                      mlfStr2double(mclVv(Token, "Token")),
                      mclVv(ParmCount, "ParmCount"));
                    mlfAssign(
                      &Token,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                }
                /*
                 * switch Type
                 */
                {
                    mxArray * v_4 = mclInitialize(mclVv(Type, "Type"));
                    if (mclSwitchCompare(v_4, _mxarray270_)) {
                        /*
                         * case 'RECT', zSetAperture(ZEMAXSurface, 5, Parms(2), Parms(1), Parms(4), Parms(3), '');
                         */
                        mclAssignAns(
                          &ans,
                          mlfZsetaperture(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray214_,
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 2),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 1),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 4),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 3),
                            _mxarray28_));
                    /*
                     * case 'ELIP', zSetAperture(ZEMAXSurface, 7, Parms(2), Parms(1), Parms(4), Parms(3), '');
                     */
                    } else if (mclSwitchCompare(v_4, _mxarray272_)) {
                        mclAssignAns(
                          &ans,
                          mlfZsetaperture(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray7_,
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 2),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 1),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 4),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 3),
                            _mxarray28_));
                    /*
                     * otherwise  , Aper = zGetAperture(ZEMAXSurface); if (Aper(1)==1), CLAPRadius = Aper(3); else CLAPRadius = 10000; end;
                     */
                    } else {
                        mlfAssign(
                          &Aper,
                          mlfZgetaperture(mclVv(ZEMAXSurface, "ZEMAXSurface")));
                        if (mclEqBool(
                              mclIntArrayRef1(mclVv(Aper, "Aper"), 1),
                              _mxarray6_)) {
                            mlfAssign(
                              &CLAPRadius,
                              mclIntArrayRef1(mclVv(Aper, "Aper"), 3));
                        } else {
                            mlfAssign(&CLAPRadius, _mxarray276_);
                        }
                        /*
                         * COBSRadius = str2double(Type); zSetAperture(ZEMAXSurface, 1, COBSRadius, CLAPRadius, Parms(3), Parms(2), '');
                         */
                        mlfAssign(
                          &COBSRadius, mlfStr2double(mclVv(Type, "Type")));
                        mclAssignAns(
                          &ans,
                          mlfZsetaperture(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray6_,
                            mclVv(COBSRadius, "COBSRadius"),
                            mclVv(CLAPRadius, "CLAPRadius"),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 3),
                            mclIntArrayRef1(mclVv(Parms, "Parms"), 2),
                            _mxarray28_));
                    /*
                     * end;
                     */
                    }
                    mxDestroyArray(v_4);
                }
            /*
             * case 'AIR',    [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface);
             */
            } else if (mclSwitchCompare(v_, _mxarray277_)) {
                mlfAssign(
                  &ZEMAXSurface,
                  mlfAccosin_NewSurface(
                    &ACCOSSurface,
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    mclVv(ACCOSSurface, "ACCOSSurface")));
            /*
             * case 'SCHOTT', Token = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray279_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * Found = find(strcmp(ACCOSMaterials, Token)); % Look for ZEMAX equivalent
                 */
                mlfAssign(
                  &Found,
                  mlfFind(
                    NULL,
                    NULL,
                    mlfStrcmp(
                      mclVv(ACCOSMaterials, "ACCOSMaterials"),
                      mclVv(Token, "Token"))));
                /*
                 * if (Found) Glass = ZEMAXMaterials{Found(1)}; else Glass = Token; end; % Take a flyer if not found
                 */
                if (mlfTobool(mclVv(Found, "Found"))) {
                    mlfAssign(
                      &Glass,
                      mlfIndexRef(
                        mclVv(ZEMAXMaterials, "ZEMAXMaterials"),
                        "{?}",
                        mclIntArrayRef1(mclVv(Found, "Found"), 1)));
                } else {
                    mlfAssign(&Glass, mclVv(Token, "Token"));
                }
                /*
                 * zSetSurfaceData(ZEMAXSurface, 4, Glass); [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface);
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray221_,
                    mclVv(Glass, "Glass")));
                mlfAssign(
                  &ZEMAXSurface,
                  mlfAccosin_NewSurface(
                    &ACCOSSurface,
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    mclVv(ACCOSSurface, "ACCOSSurface")));
            /*
             * case 'HOYA',   Token = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray281_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * Found = find(strcmp(ACCOSMaterials, Token)); % Look for ZEMAX equivalent
                 */
                mlfAssign(
                  &Found,
                  mlfFind(
                    NULL,
                    NULL,
                    mlfStrcmp(
                      mclVv(ACCOSMaterials, "ACCOSMaterials"),
                      mclVv(Token, "Token"))));
                /*
                 * if (Found) Glass = ZEMAXMaterials{Found(1)}; else Glass = Token; end; % Take a flyer if not found
                 */
                if (mlfTobool(mclVv(Found, "Found"))) {
                    mlfAssign(
                      &Glass,
                      mlfIndexRef(
                        mclVv(ZEMAXMaterials, "ZEMAXMaterials"),
                        "{?}",
                        mclIntArrayRef1(mclVv(Found, "Found"), 1)));
                } else {
                    mlfAssign(&Glass, mclVv(Token, "Token"));
                }
                /*
                 * zSetSurfaceData(ZEMAXSurface, 4, Glass); [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface);
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray221_,
                    mclVv(Glass, "Glass")));
                mlfAssign(
                  &ZEMAXSurface,
                  mlfAccosin_NewSurface(
                    &ACCOSSurface,
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    mclVv(ACCOSSurface, "ACCOSSurface")));
            /*
             * case 'OHARA',  Token = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray283_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * Found = find(strcmp(ACCOSMaterials, Token)); % Look for ZEMAX equivalent
                 */
                mlfAssign(
                  &Found,
                  mlfFind(
                    NULL,
                    NULL,
                    mlfStrcmp(
                      mclVv(ACCOSMaterials, "ACCOSMaterials"),
                      mclVv(Token, "Token"))));
                /*
                 * if (Found) Glass = ZEMAXMaterials{Found(1)}; else Glass = Token; end; % Take a flyer if not found
                 */
                if (mlfTobool(mclVv(Found, "Found"))) {
                    mlfAssign(
                      &Glass,
                      mlfIndexRef(
                        mclVv(ZEMAXMaterials, "ZEMAXMaterials"),
                        "{?}",
                        mclIntArrayRef1(mclVv(Found, "Found"), 1)));
                } else {
                    mlfAssign(&Glass, mclVv(Token, "Token"));
                }
                /*
                 * zSetSurfaceData(ZEMAXSurface, 4, Glass); [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface);
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray221_,
                    mclVv(Glass, "Glass")));
                mlfAssign(
                  &ZEMAXSurface,
                  mlfAccosin_NewSurface(
                    &ACCOSSurface,
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    mclVv(ACCOSSurface, "ACCOSSurface")));
            /*
             * case 'REFL',   Glass = 'MIRROR'; zSetSurfaceData(ZEMAXSurface, 4, Glass); [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface);
             */
            } else if (mclSwitchCompare(v_, _mxarray285_)) {
                mlfAssign(&Glass, _mxarray287_);
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray221_,
                    mclVv(Glass, "Glass")));
                mlfAssign(
                  &ZEMAXSurface,
                  mlfAccosin_NewSurface(
                    &ACCOSSurface,
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    mclVv(ACCOSSurface, "ACCOSSurface")));
            /*
             * case 'GLASS',  [Token, Rest] = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray289_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * if (strcmp(Token, 'MODEL'))
                 */
                if (mlfTobool(mlfStrcmp(mclVv(Token, "Token"), _mxarray291_))) {
                    /*
                     * [Token, Rest] = strtok(Rest, ' ,'); RN = str2double(Token);
                     */
                    mlfAssign(
                      &Token,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                    mlfAssign(&RN, mlfStr2double(mclVv(Token, "Token")));
                    /*
                     * [Token, Rest] = strtok(Rest, ' ,'); DF = str2double(Token);
                     */
                    mlfAssign(
                      &Token,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                    mlfAssign(&DF, mlfStr2double(mclVv(Token, "Token")));
                    /*
                     * zSetSolve(ZEMAXSurface, 2, 1, RN); 
                     */
                    mclAssignAns(
                      &ans,
                      mlfZsetsolve(
                        mclVv(ZEMAXSurface, "ZEMAXSurface"),
                        _mxarray5_,
                        _mxarray6_,
                        mclVv(RN, "RN"), NULL));
                /*
                 * else
                 */
                } else {
                    /*
                     * Found = find(strcmp(ACCOSMaterials, Token)); % Look for ZEMAX equivalent
                     */
                    mlfAssign(
                      &Found,
                      mlfFind(
                        NULL,
                        NULL,
                        mlfStrcmp(
                          mclVv(ACCOSMaterials, "ACCOSMaterials"),
                          mclVv(Token, "Token"))));
                    /*
                     * if (Found) Glass = ZEMAXMaterials{Found(1)}; else Glass = Token; end;
                     */
                    if (mlfTobool(mclVv(Found, "Found"))) {
                        mlfAssign(
                          &Glass,
                          mlfIndexRef(
                            mclVv(ZEMAXMaterials, "ZEMAXMaterials"),
                            "{?}",
                            mclIntArrayRef1(mclVv(Found, "Found"), 1)));
                    } else {
                        mlfAssign(&Glass, mclVv(Token, "Token"));
                    }
                    /*
                     * zSetSurfaceData(ZEMAXSurface, 4, Glass);
                     */
                    mclAssignAns(
                      &ans,
                      mlfZsetsurfacedata(
                        mclVv(ZEMAXSurface, "ZEMAXSurface"),
                        _mxarray221_,
                        mclVv(Glass, "Glass")));
                /*
                 * end;
                 */
                }
                /*
                 * [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface); 
                 */
                mlfAssign(
                  &ZEMAXSurface,
                  mlfAccosin_NewSurface(
                    &ACCOSSurface,
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    mclVv(ACCOSSurface, "ACCOSSurface")));
            /*
             * case 'MATL', Token = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray293_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * Found = find(strcmp(ACCOSMaterials, Token)); % Look for ZEMAX equivalent
                 */
                mlfAssign(
                  &Found,
                  mlfFind(
                    NULL,
                    NULL,
                    mlfStrcmp(
                      mclVv(ACCOSMaterials, "ACCOSMaterials"),
                      mclVv(Token, "Token"))));
                /*
                 * if (Found) Glass = ZEMAXMaterials{Found(1)}; else Glass = Token; end; % Take a flyer if not found
                 */
                if (mlfTobool(mclVv(Found, "Found"))) {
                    mlfAssign(
                      &Glass,
                      mlfIndexRef(
                        mclVv(ZEMAXMaterials, "ZEMAXMaterials"),
                        "{?}",
                        mclIntArrayRef1(mclVv(Found, "Found"), 1)));
                } else {
                    mlfAssign(&Glass, mclVv(Token, "Token"));
                }
                /*
                 * zSetSurfaceData(ZEMAXSurface, 4, Glass);
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetsurfacedata(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray221_,
                    mclVv(Glass, "Glass")));
                /*
                 * [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface);
                 */
                mlfAssign(
                  &ZEMAXSurface,
                  mlfAccosin_NewSurface(
                    &ACCOSSurface,
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    mclVv(ACCOSSurface, "ACCOSSurface")));
            /*
             * case 'ASTOP', Token = strtok(Rest, ' ,'); StopSurface = ZEMAXSurface; LenSys = zsGetSystem; LenSys.stopsurf = StopSurface; zsSetSystem(LenSys);  
             */
            } else if (mclSwitchCompare(v_, _mxarray295_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(&StopSurface, mclVv(ZEMAXSurface, "ZEMAXSurface"));
                mlfAssign(&LenSys, mlfZsgetsystem());
                mlfIndexAssign(
                  &LenSys, ".stopsurf", mclVv(StopSurface, "StopSurface"));
                mclAssignAns(&ans, mlfZssetsystem(mclVv(LenSys, "LenSys")));
            /*
             * case 'UNITS', Token = strtok(Rest, ' ,'); LenSys = zsGetSystem; 
             */
            } else if (mclSwitchCompare(v_, _mxarray297_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(&LenSys, mlfZsgetsystem());
                /*
                 * switch Token
                 */
                {
                    mxArray * v_5 = mclInitialize(mclVv(Token, "Token"));
                    if (mclSwitchCompare(v_5, _mxarray299_)) {
                        /*
                         * case 'MM',     LenSys.unitcode = 0;
                         */
                        mlfIndexAssign(&LenSys, ".unitcode", _mxarray205_);
                    /*
                     * case 'CM',     LenSys.unitcode = 1;
                     */
                    } else if (mclSwitchCompare(v_5, _mxarray301_)) {
                        mlfIndexAssign(&LenSys, ".unitcode", _mxarray6_);
                    /*
                     * case 'INCHES', LenSys.unitcode = 2;
                     */
                    } else if (mclSwitchCompare(v_5, _mxarray303_)) {
                        mlfIndexAssign(&LenSys, ".unitcode", _mxarray5_);
                    /*
                     * end
                     */
                    }
                    mxDestroyArray(v_5);
                }
                /*
                 * zsSetSystem(LenSys);
                 */
                mclAssignAns(&ans, mlfZssetsystem(mclVv(LenSys, "LenSys")));
            /*
             * case 'PIKUP', [Type, Rest] = strtok(Rest, ' ,'); [PikupSurf, Rest] = strtok(Rest, ' ,'); ACCOSPikupSurface = str2num(PikupSurf);
             */
            } else if (mclSwitchCompare(v_, _mxarray305_)) {
                mlfAssign(
                  &Type,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(
                  &PikupSurf,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                mlfAssign(
                  &ACCOSPikupSurface,
                  mlfStr2num(NULL, mclVv(PikupSurf, "PikupSurf")));
                /*
                 * if (ACCOSPikupSurface < 0), ACCOSPikupSurface = ACCOSSurface + ACCOSPikupSurface; end;
                 */
                if (mclLtBool(
                      mclVv(ACCOSPikupSurface, "ACCOSPikupSurface"),
                      _mxarray205_)) {
                    mlfAssign(
                      &ACCOSPikupSurface,
                      mclPlus(
                        mclVv(ACCOSSurface, "ACCOSSurface"),
                        mclVv(ACCOSPikupSurface, "ACCOSPikupSurface")));
                }
                /*
                 * ZEMAXPikupSurface = zFindLabel(ACCOSPikupSurface);
                 */
                mlfAssign(
                  &ZEMAXPikupSurface,
                  mlfZfindlabel(mclVv(ACCOSPikupSurface, "ACCOSPikupSurface")));
                /*
                 * [ScaleFac, Rest] = strtok(Rest, ' ,'); if (ScaleFac), ScaleFactor = str2num(ScaleFac); else ScaleFactor = 0; end;
                 */
                mlfAssign(
                  &ScaleFac,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                if (mlfTobool(mclVv(ScaleFac, "ScaleFac"))) {
                    mlfAssign(
                      &ScaleFactor,
                      mlfStr2num(NULL, mclVv(ScaleFac, "ScaleFac")));
                } else {
                    mlfAssign(&ScaleFactor, _mxarray205_);
                }
                /*
                 * [Ofset, Rest] = strtok(Rest, ' ,');    if (Ofset),    Offset = str2num(Ofset); else Offset = 0; end;
                 */
                mlfAssign(
                  &Ofset,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                if (mlfTobool(mclVv(Ofset, "Ofset"))) {
                    mlfAssign(&Offset, mlfStr2num(NULL, mclVv(Ofset, "Ofset")));
                } else {
                    mlfAssign(&Offset, _mxarray205_);
                }
                /*
                 * % Debug disp('PIKUP '); disp(Type); disp(PikupSurface); disp(ScaleFactor); disp(Offset);
                 * switch Type
                 */
                {
                    mxArray * v_6 = mclInitialize(mclVv(Type, "Type"));
                    if (mclSwitchCompare(v_6, _mxarray238_)) {
                        /*
                         * case 'RD', zSetSolve(ZEMAXSurface, 0, 4, ZEMAXPikupSurface, ScaleFactor);
                         */
                        mclAssignAns(
                          &ans,
                          mlfZsetsolve(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray205_,
                            _mxarray221_,
                            mclVv(ZEMAXPikupSurface, "ZEMAXPikupSurface"),
                            mclVv(ScaleFactor, "ScaleFactor"),
                            NULL));
                    /*
                     * case 'CV', zSetSolve(ZEMAXSurface, 0, 4, ZEMAXPikupSurface, ScaleFactor);
                     */
                    } else if (mclSwitchCompare(v_6, _mxarray240_)) {
                        mclAssignAns(
                          &ans,
                          mlfZsetsolve(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray205_,
                            _mxarray221_,
                            mclVv(ZEMAXPikupSurface, "ZEMAXPikupSurface"),
                            mclVv(ScaleFactor, "ScaleFactor"),
                            NULL));
                    /*
                     * case 'CC', zSetSolve(ZEMAXSurface, 4, 2, ZEMAXPikupSurface);
                     */
                    } else if (mclSwitchCompare(v_6, _mxarray242_)) {
                        mclAssignAns(
                          &ans,
                          mlfZsetsolve(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray221_,
                            _mxarray5_,
                            mclVv(ZEMAXPikupSurface, "ZEMAXPikupSurface"),
                            NULL));
                    /*
                     * case 'TH', zSetSolve(ZEMAXSurface, 1, 5, ZEMAXPikupSurface, ScaleFactor, Offset);
                     */
                    } else if (mclSwitchCompare(v_6, _mxarray257_)) {
                        mclAssignAns(
                          &ans,
                          mlfZsetsolve(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray6_,
                            _mxarray214_,
                            mclVv(ZEMAXPikupSurface, "ZEMAXPikupSurface"),
                            mclVv(ScaleFactor, "ScaleFactor"),
                            mclVv(Offset, "Offset"),
                            NULL));
                    /*
                     * case 'CLAP', zSetSolve(ZEMAXSurface, 3, 2, ZEMAXPikupSurface);
                     */
                    } else if (mclSwitchCompare(v_6, _mxarray266_)) {
                        mclAssignAns(
                          &ans,
                          mlfZsetsolve(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray259_,
                            _mxarray5_,
                            mclVv(ZEMAXPikupSurface, "ZEMAXPikupSurface"),
                            NULL));
                    /*
                     * case 'GLASS', zSetSolve(ZEMAXSurface, 2, 2, ZEMAXPikupSurface); [ZEMAXSurface, ACCOSSurface] = NewSurface(ZEMAXSurface, ACCOSSurface);
                     */
                    } else if (mclSwitchCompare(v_6, _mxarray289_)) {
                        mclAssignAns(
                          &ans,
                          mlfZsetsolve(
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            _mxarray5_,
                            _mxarray5_,
                            mclVv(ZEMAXPikupSurface, "ZEMAXPikupSurface"),
                            NULL));
                        mlfAssign(
                          &ZEMAXSurface,
                          mlfAccosin_NewSurface(
                            &ACCOSSurface,
                            mclVv(ZEMAXSurface, "ZEMAXSurface"),
                            mclVv(ACCOSSurface, "ACCOSSurface")));
                    /*
                     * otherwise, Found = find(strcmp(UnknownPikups, Type));
                     */
                    } else {
                        mlfAssign(
                          &Found,
                          mlfFind(
                            NULL,
                            NULL,
                            mlfStrcmp(
                              mclVv(UnknownPikups, "UnknownPikups"),
                              mclVv(Type, "Type"))));
                        /*
                         * if (Found)
                         */
                        if (mlfTobool(mclVv(Found, "Found"))) {
                        /*
                         * else
                         */
                        } else {
                            /*
                             * disp(['Unknown PIKUPs of type "' Type '" will be Ignored.']);
                             */
                            mlfDisp(
                              mlfHorzcat(
                                _mxarray307_,
                                mclVv(Type, "Type"),
                                _mxarray309_,
                                NULL));
                            /*
                             * UnknownPikups = cat(1, UnknownPikups, {Type});
                             */
                            mlfAssign(
                              &UnknownPikups,
                              mlfCat(
                                _mxarray6_,
                                mclVv(UnknownPikups, "UnknownPikups"),
                                mlfCellhcat(mclVv(Type, "Type"), NULL),
                                NULL));
                        /*
                         * end;
                         */
                        }
                    /*
                     * end;
                     */
                    }
                    mxDestroyArray(v_6);
                }
            /*
             * case 'PY', Token = strtok(Rest, ' ,'); if (Token), RayHeight = str2double(Token); else RayHeight = 0.0; end;
             */
            } else if (mclSwitchCompare(v_, _mxarray311_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                if (mlfTobool(mclVv(Token, "Token"))) {
                    mlfAssign(&RayHeight, mlfStr2double(mclVv(Token, "Token")));
                } else {
                    mlfAssign(&RayHeight, _mxarray205_);
                }
                /*
                 * zSetSolve(ZEMAXSurface, 1, 2, RayHeight, 0.1, 0);
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetsolve(
                    mclVv(ZEMAXSurface, "ZEMAXSurface"),
                    _mxarray6_,
                    _mxarray5_,
                    mclVv(RayHeight, "RayHeight"),
                    _mxarray313_,
                    _mxarray205_,
                    NULL));
            /*
             * case 'WV', NumWaves = 0; Wavelengths = []; [Wv, Rest] = strtok(Rest, ' ,'); 
             */
            } else if (mclSwitchCompare(v_, _mxarray314_)) {
                mlfAssign(&NumWaves, _mxarray205_);
                mlfAssign(&Wavelengths, _mxarray316_);
                mlfAssign(
                  &Wv, mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * while (Wv), NumWaves = NumWaves + 1; Wavelengths(NumWaves,1) = str2double(Wv); [Wv, Rest] = strtok(Rest, ' ,'); end;
                 */
                while (mlfTobool(mclVv(Wv, "Wv"))) {
                    mlfAssign(
                      &NumWaves,
                      mclPlus(mclVv(NumWaves, "NumWaves"), _mxarray6_));
                    mclArrayAssign2(
                      &Wavelengths,
                      mlfStr2double(mclVv(Wv, "Wv")),
                      mclVv(NumWaves, "NumWaves"),
                      _mxarray6_);
                    mlfAssign(
                      &Wv,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                }
                /*
                 * Wavelengths = Wavelengths(Wavelengths > 0);
                 */
                mlfAssign(
                  &Wavelengths,
                  mclArrayRef1(
                    mclVv(Wavelengths, "Wavelengths"),
                    mclGt(mclVv(Wavelengths, "Wavelengths"), _mxarray205_)));
                /*
                 * zSetWaveMatrix([Wavelengths WaveWeights(1:size(Wavelengths,1),1)]);
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetwavematrix(
                    mlfHorzcat(
                      mclVv(Wavelengths, "Wavelengths"),
                      mclArrayRef2(
                        mclVv(WaveWeights, "WaveWeights"),
                        mlfColon(
                          _mxarray6_,
                          mlfSize(
                            mclValueVarargout(),
                            mclVv(Wavelengths, "Wavelengths"),
                            _mxarray6_),
                          NULL),
                        _mxarray6_),
                      NULL)));
            /*
             * case 'SPTWT', NumWeights = 0; [Weight, Rest] = strtok(Rest, ' ,'); while (Weight), NumWeights = NumWeights + 1; WaveWeights(NumWeights,1) = str2double(Weight); [Weight, Rest] = strtok(Rest, ' ,'); end;
             */
            } else if (mclSwitchCompare(v_, _mxarray317_)) {
                mlfAssign(&NumWeights, _mxarray205_);
                mlfAssign(
                  &Weight,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                while (mlfTobool(mclVv(Weight, "Weight"))) {
                    mlfAssign(
                      &NumWeights,
                      mclPlus(mclVv(NumWeights, "NumWeights"), _mxarray6_));
                    mclArrayAssign2(
                      &WaveWeights,
                      mlfStr2double(mclVv(Weight, "Weight")),
                      mclVv(NumWeights, "NumWeights"),
                      _mxarray6_);
                    mlfAssign(
                      &Weight,
                      mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                }
                /*
                 * zSetWaveMatrix([Wavelengths WaveWeights(1:size(Wavelengths,1),1)]);
                 */
                mclAssignAns(
                  &ans,
                  mlfZsetwavematrix(
                    mlfHorzcat(
                      mclVv(Wavelengths, "Wavelengths"),
                      mclArrayRef2(
                        mclVv(WaveWeights, "WaveWeights"),
                        mlfColon(
                          _mxarray6_,
                          mlfSize(
                            mclValueVarargout(),
                            mclVv(Wavelengths, "Wavelengths"),
                            _mxarray6_),
                          NULL),
                        _mxarray6_),
                      NULL)));
            /*
             * case 'CW', PrimaryWave = str2num(strtok(Rest, ' ,')); zSetPrimaryWave(PrimaryWave);
             */
            } else if (mclSwitchCompare(v_, _mxarray319_)) {
                mlfAssign(
                  &PrimaryWave,
                  mlfStr2num(
                    NULL,
                    mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_)));
                mclAssignAns(
                  &ans, mlfZsetprimarywave(mclVv(PrimaryWave, "PrimaryWave")));
            /*
             * case 'CONFIGS', ReadOldConfigData(fID);
             */
            } else if (mclSwitchCompare(v_, _mxarray321_)) {
                mlfAccosin_ReadOldConfigData(mclVv(fID, "fID"));
            /*
             * case 'CONFIG', [Token, Rest] = strtok(Rest, ' ,');
             */
            } else if (mclSwitchCompare(v_, _mxarray323_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * if (strcmp(Token, 'OLD')), ReadOldConfigData(fID);
                 */
                if (mlfTobool(mlfStrcmp(mclVv(Token, "Token"), _mxarray325_))) {
                    mlfAccosin_ReadOldConfigData(mclVv(fID, "fID"));
                /*
                 * else if (Token), 
                 */
                } else {
                    if (mlfTobool(mclVv(Token, "Token"))) {
                        /*
                         * Config = str2num(Token); Token = strtok(Rest, ' ,'); 
                         */
                        mlfAssign(
                          &Config, mlfStr2num(NULL, mclVv(Token, "Token")));
                        mlfAssign(
                          &Token,
                          mlfNStrtok(
                            1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                        /*
                         * if (Token) Surface = str2num(Token); end;
                         */
                        if (mlfTobool(mclVv(Token, "Token"))) {
                            mlfAssign(
                              &Surface,
                              mlfStr2num(NULL, mclVv(Token, "Token")));
                        }
                        /*
                         * ReadNewConfigData(fID, Config, Surface); 
                         */
                        mlfAccosin_ReadNewConfigData(
                          mclVv(fID, "fID"),
                          mclVv(Config, "Config"),
                          mclVv(Surface, "Surface"));
                    /*
                     * end;
                     */
                    }
                /*
                 * end;
                 */
                }
            /*
             * case 'EOS', DummySurface = zFindLabel(1001); zDeleteSurface(DummySurface);
             */
            } else if (mclSwitchCompare(v_, _mxarray327_)) {
                mlfAssign(&DummySurface, mlfZfindlabel(_mxarray217_));
                mclAssignAns(
                  &ans, mlfZdeletesurface(mclVv(DummySurface, "DummySurface")));
                /*
                 * if (StopSurface == 0), StopSurface = 1; LenSys = zsGetSystem; LenSys.stopsurf = StopSurface; zsSetSystem(LenSys); end
                 */
                if (mclEqBool(
                      mclVv(StopSurface, "StopSurface"), _mxarray205_)) {
                    mlfAssign(&StopSurface, _mxarray6_);
                    mlfAssign(&LenSys, mlfZsgetsystem());
                    mlfIndexAssign(
                      &LenSys, ".stopsurf", mclVv(StopSurface, "StopSurface"));
                    mclAssignAns(&ans, mlfZssetsystem(mclVv(LenSys, "LenSys")));
                }
            /*
             * case 'LIB', [Token, Rest] = strtok(Rest, ' ,');
             */
            } else if (mclSwitchCompare(v_, _mxarray329_)) {
                mlfAssign(
                  &Token,
                  mlfNStrtok(2, &Rest, mclVv(Rest, "Rest"), _mxarray208_));
                /*
                 * if (strcmp(Token, 'PUT'))
                 */
                if (mlfTobool(mlfStrcmp(mclVv(Token, "Token"), _mxarray331_))) {
                    /*
                     * if (strcmp(LibDumpPath, ''))
                     */
                    if (mlfTobool(
                          mlfStrcmp(
                            mclVv(LibDumpPath, "LibDumpPath"), _mxarray28_))) {
                        /*
                         * disp('LIB PUT Requested. Please Select a Suitable Place for the Library Dump.');
                         */
                        mlfDisp(_mxarray333_);
                        /*
                         * % LibDumpPath = uigetdir('c:\', 'Select Directory for Library Dump.');      % Won't compile for standalone mode
                         * % LibDumpPath = uigetfolder('Select Directory for Library Dump.', 'c:\');   % Compiles, but won't run in standalone mode
                         * [DummyFile, LibDumpPath] = uiputfile('Dummy.zmx', 'Navigate to Directory for Lib Dump'); % Use this workaround for the standalone version
                         */
                        mlfAssign(
                          &DummyFile,
                          mlfUiputfile(
                            &LibDumpPath,
                            _mxarray335_,
                            _mxarray337_,
                            NULL,
                            NULL));
                    /*
                     * end;
                     */
                    }
                    /*
                     * Reply = zPushLens(5);
                     */
                    mlfAssign(&Reply, mlfZpushlens(_mxarray214_));
                    /*
                     * while (Reply == -998) % Timeout on zPushLens
                     */
                    while (mclEqBool(mclVv(Reply, "Reply"), _mxarray339_)) {
                        /*
                         * Answer = questdlg('ZEMAX is not responding to the Conversion Utility. ZEMAX may be waiting for your input. What would you like to do ?',...
                         */
                        mlfAssign(
                          &Answer,
                          mlfNQuestdlg(
                            1,
                            _mxarray340_,
                            _mxarray342_,
                            _mxarray344_,
                            _mxarray346_,
                            _mxarray344_,
                            NULL));
                        /*
                         * 'ZEMAX Unresponsive. What Now ?', 'Continue', 'Abandon', 'Continue');
                         * switch Answer
                         */
                        {
                            mxArray * v_7
                              = mclInitialize(mclVv(Answer, "Answer"));
                            if (mclSwitchCompare(v_7, _mxarray344_)) {
                                /*
                                 * case 'Continue', Reply = zPushLens(5);
                                 */
                                mlfAssign(&Reply, mlfZpushlens(_mxarray214_));
                            /*
                             * case 'Abandon', Status = -1; return;
                             */
                            } else if (mclSwitchCompare(v_7, _mxarray346_)) {
                                mlfAssign(&Status, _mxarray45_);
                                mxDestroyArray(v_7);
                                mxDestroyArray(v_);
                                goto return_;
                            /*
                             * end;
                             */
                            }
                            mxDestroyArray(v_7);
                        }
                    /*
                     * end;
                     */
                    }
                    /*
                     * Token = strtok(Rest, ' ,'); Block = str2num(Token); 
                     */
                    mlfAssign(
                      &Token,
                      mlfNStrtok(1, NULL, mclVv(Rest, "Rest"), _mxarray208_));
                    mlfAssign(&Block, mlfStr2num(NULL, mclVv(Token, "Token")));
                    /*
                     * if (LITitle), 
                     */
                    if (mlfTobool(mclVv(LITitle, "LITitle"))) {
                        /*
                         * CleanTitle = CleanFileName(LITitle);
                         */
                        mlfAssign(
                          &CleanTitle,
                          mlfAccosin_CleanFileName(mclVv(LITitle, "LITitle")));
                        /*
                         * LensFileName = [LibDumpPath '\' CleanTitle '.zmx']; 
                         */
                        mlfAssign(
                          &LensFileName,
                          mlfHorzcat(
                            mclVv(LibDumpPath, "LibDumpPath"),
                            _mxarray348_,
                            mclVv(CleanTitle, "CleanTitle"),
                            _mxarray350_,
                            NULL));
                    /*
                     * else LensFileName = ['Block ' num2str(Block) '.zmx']; 
                     */
                    } else {
                        mlfAssign(
                          &LensFileName,
                          mlfHorzcat(
                            _mxarray352_,
                            mlfNum2str(mclVv(Block, "Block"), NULL),
                            _mxarray350_,
                            NULL));
                    /*
                     * end;
                     */
                    }
                    /*
                     * zSaveFile(LensFileName);
                     */
                    mclAssignAns(
                      &ans, mlfZsavefile(mclVv(LensFileName, "LensFileName")));
                /*
                 * end;
                 */
                }
            /*
             * 
             * otherwise, Found = find(strcmp(UnknownDirectives, Directive));
             */
            } else {
                mlfAssign(
                  &Found,
                  mlfFind(
                    NULL,
                    NULL,
                    mlfStrcmp(
                      mclVv(UnknownDirectives, "UnknownDirectives"),
                      mclVv(Directive, "Directive"))));
                /*
                 * if (Found)
                 */
                if (mlfTobool(mclVv(Found, "Found"))) {
                /*
                 * else
                 */
                } else {
                    /*
                     * disp(['Unknown Directives "' Directive '" will be Ignored.']);
                     */
                    mlfDisp(
                      mlfHorzcat(
                        _mxarray354_,
                        mclVv(Directive, "Directive"),
                        _mxarray309_,
                        NULL));
                    /*
                     * UnknownDirectives = cat(1, UnknownDirectives, {Directive});
                     */
                    mlfAssign(
                      &UnknownDirectives,
                      mlfCat(
                        _mxarray6_,
                        mclVv(UnknownDirectives, "UnknownDirectives"),
                        mlfCellhcat(mclVv(Directive, "Directive"), NULL),
                        NULL));
                /*
                 * end;
                 */
                }
            /*
             * end;
             */
            }
            mxDestroyArray(v_);
        /*
         * end;
         */
        }
    /*
     * end;
     */
    }
    /*
     * zPushLens(5);
     */
    mclAssignAns(&ans, mlfZpushlens(_mxarray214_));
    /*
     * fclose(fID);
     */
    mclAssignAns(&ans, mlfFclose(mclVv(fID, "fID")));
    /*
     * 
     * 
     */
    return_:
    mclValidateOutput(Status, 1, nargout_, "Status", "accosin/ReadACCOSFile");
    mxDestroyArray(LibDumpPath);
    mxDestroyArray(ACCOSMaterials);
    mxDestroyArray(ZEMAXMaterials);
    mxDestroyArray(UnknownDirectives);
    mxDestroyArray(UnknownPikups);
    mxDestroyArray(fID);
    mxDestroyArray(LenLine);
    mxDestroyArray(Directive);
    mxDestroyArray(Rest);
    mxDestroyArray(ans);
    mxDestroyArray(Title);
    mxDestroyArray(ZEMAXSurface);
    mxDestroyArray(ACCOSSurface);
    mxDestroyArray(XObjectAngle);
    mxDestroyArray(YObjectAngle);
    mxDestroyArray(XObjectHeight);
    mxDestroyArray(YObjectHeight);
    mxDestroyArray(Wavelengths);
    mxDestroyArray(NumWaves);
    mxDestroyArray(WaveWeights);
    mxDestroyArray(FieldType);
    mxDestroyArray(LensComments);
    mxDestroyArray(NumberComments);
    mxDestroyArray(LITitle);
    mxDestroyArray(StopSurface);
    mxDestroyArray(Comment);
    mxDestroyArray(Token);
    mxDestroyArray(CheckACCOSSurface);
    mxDestroyArray(PupilRadius);
    mxDestroyArray(Radius);
    mxDestroyArray(Curv);
    mxDestroyArray(Conic);
    mxDestroyArray(Ad);
    mxDestroyArray(Ae);
    mxDestroyArray(Af);
    mxDestroyArray(Ag);
    mxDestroyArray(Thick);
    mxDestroyArray(FieldPoints);
    mxDestroyArray(Type);
    mxDestroyArray(Parms);
    mxDestroyArray(ParmCount);
    mxDestroyArray(Aper);
    mxDestroyArray(COBSRadius);
    mxDestroyArray(CLAPRadius);
    mxDestroyArray(Found);
    mxDestroyArray(Glass);
    mxDestroyArray(RN);
    mxDestroyArray(DF);
    mxDestroyArray(LenSys);
    mxDestroyArray(PikupSurf);
    mxDestroyArray(ACCOSPikupSurface);
    mxDestroyArray(ZEMAXPikupSurface);
    mxDestroyArray(ScaleFac);
    mxDestroyArray(ScaleFactor);
    mxDestroyArray(Ofset);
    mxDestroyArray(Offset);
    mxDestroyArray(RayHeight);
    mxDestroyArray(Wv);
    mxDestroyArray(NumWeights);
    mxDestroyArray(Weight);
    mxDestroyArray(PrimaryWave);
    mxDestroyArray(Config);
    mxDestroyArray(Surface);
    mxDestroyArray(DummySurface);
    mxDestroyArray(DummyFile);
    mxDestroyArray(Reply);
    mxDestroyArray(Answer);
    mxDestroyArray(Block);
    mxDestroyArray(CleanTitle);
    mxDestroyArray(LensFileName);
    mxDestroyArray(Filename);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return Status;
}

/*
 * The function "Maccosin_NewSurface" is the implementation version of the
 * "accosin/NewSurface" M-function from file "c:\projects\mzdde\accosin.m"
 * (lines 287-293). It contains the actual compiled code for that M-function.
 * It is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function [ZEMAXout,ACCOSout] = NewSurface(ZEMAXin, ACCOSin)
 */
static mxArray * Maccosin_NewSurface(mxArray * * ACCOSout,
                                     int nargout_,
                                     mxArray * ZEMAXin,
                                     mxArray * ACCOSin) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_accosin);
    mxArray * ZEMAXout = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&ZEMAXin);
    mclCopyArray(&ACCOSin);
    /*
     * zSetLabel(ZEMAXin, ACCOSin);
     */
    mclAssignAns(
      &ans, mlfZsetlabel(mclVa(ZEMAXin, "ZEMAXin"), mclVa(ACCOSin, "ACCOSin")));
    /*
     * ZEMAXout = ZEMAXin + 1; ACCOSout = ACCOSin + 1;
     */
    mlfAssign(&ZEMAXout, mclPlus(mclVa(ZEMAXin, "ZEMAXin"), _mxarray6_));
    mlfAssign(ACCOSout, mclPlus(mclVa(ACCOSin, "ACCOSin"), _mxarray6_));
    /*
     * zInsertSurface(ZEMAXout);
     */
    mclAssignAns(&ans, mlfZinsertsurface(mclVv(ZEMAXout, "ZEMAXout")));
    mclValidateOutput(ZEMAXout, 1, nargout_, "ZEMAXout", "accosin/NewSurface");
    mclValidateOutput(*ACCOSout, 2, nargout_, "ACCOSout", "accosin/NewSurface");
    mxDestroyArray(ans);
    mxDestroyArray(ACCOSin);
    mxDestroyArray(ZEMAXin);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return ZEMAXout;
    /*
     * 
     * 
     */
}

/*
 * The function "Maccosin_CleanFileName" is the implementation version of the
 * "accosin/CleanFileName" M-function from file "c:\projects\mzdde\accosin.m"
 * (lines 293-310). It contains the actual compiled code for that M-function.
 * It is a static function and must only be called from one of the interface
 * functions, appearing below.
 */
/*
 * function CleanName = CleanFileName(DirtyName)
 */
static mxArray * Maccosin_CleanFileName(int nargout_, mxArray * DirtyName) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_accosin);
    mxArray * CleanName = NULL;
    mxArray * Len = NULL;
    mxArray * i = NULL;
    mxArray * AltChars = NULL;
    mxArray * BadChars = NULL;
    mclCopyArray(&DirtyName);
    /*
     * % Replace Bad characters with alternatives, remove leading and trailing blanks and trailing
     * % fullstops
     * 
     * BadChars = '/\:*?<>|,';
     */
    mlfAssign(&BadChars, _mxarray356_);
    /*
     * AltChars = '#%;+&{}!-';
     */
    mlfAssign(&AltChars, _mxarray358_);
    /*
     * DirtyName = deblank(fliplr(deblank(fliplr(DirtyName))));
     */
    mlfAssign(
      &DirtyName,
      mlfDeblank(
        mlfFliplr(mlfDeblank(mlfFliplr(mclVa(DirtyName, "DirtyName"))))));
    /*
     * 
     * for i = 1:size(BadChars,2)
     */
    {
        int v_ = mclForIntStart(1);
        int e_
          = mclForIntEnd(
              mlfSize(
                mclValueVarargout(), mclVv(BadChars, "BadChars"), _mxarray5_));
        if (v_ > e_) {
            mlfAssign(&i, _mxarray316_);
        } else {
            /*
             * DirtyName(find(DirtyName==BadChars(i))) = AltChars(i);
             * end;
             */
            for (; ; ) {
                mclArrayAssign1(
                  &DirtyName,
                  mclIntArrayRef1(mclVv(AltChars, "AltChars"), v_),
                  mlfFind(
                    NULL,
                    NULL,
                    mclEq(
                      mclVa(DirtyName, "DirtyName"),
                      mclIntArrayRef1(mclVv(BadChars, "BadChars"), v_))));
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            mlfAssign(&i, mlfScalar(v_));
        }
    }
    /*
     * 
     * Len = size(DirtyName,2);
     */
    mlfAssign(
      &Len,
      mlfSize(mclValueVarargout(), mclVa(DirtyName, "DirtyName"), _mxarray5_));
    /*
     * if (DirtyName(Len) == '.'), DirtyName = DirtyName(1:(Len-1)); end;
     */
    if (mclEqBool(
          mclArrayRef1(mclVa(DirtyName, "DirtyName"), mclVv(Len, "Len")),
          _mxarray360_)) {
        mlfAssign(
          &DirtyName,
          mclArrayRef1(
            mclVa(DirtyName, "DirtyName"),
            mlfColon(
              _mxarray6_, mclMinus(mclVv(Len, "Len"), _mxarray6_), NULL)));
    }
    /*
     * CleanName = DirtyName;
     */
    mlfAssign(&CleanName, mclVa(DirtyName, "DirtyName"));
    mclValidateOutput(
      CleanName, 1, nargout_, "CleanName", "accosin/CleanFileName");
    mxDestroyArray(BadChars);
    mxDestroyArray(AltChars);
    mxDestroyArray(i);
    mxDestroyArray(Len);
    mxDestroyArray(DirtyName);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return CleanName;
    /*
     * 
     * 
     */
}

/*
 * The function "Maccosin_ReadOldConfigData" is the implementation version of
 * the "accosin/ReadOldConfigData" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 310-325). It contains the actual
 * compiled code for that M-function. It is a static function and must only be
 * called from one of the interface functions, appearing below.
 */
/*
 * function ReadOldConfigData(fID)
 */
static void Maccosin_ReadOldConfigData(mxArray * fID) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_accosin);
    mxArray * Rest = NULL;
    mxArray * Directive = NULL;
    mxArray * CfgLine = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&fID);
    /*
     * disp('Discarding Old Config Data.')
     */
    mlfDisp(_mxarray362_);
    /*
     * while 1
     */
    for (;;) {
        /*
         * CfgLine = fgetl(fID);
         */
        mlfAssign(&CfgLine, mlfFgetl(mclVa(fID, "fID")));
        /*
         * if ~ischar(CfgLine), return; end; % (Unexpected) End of file
         */
        if (mclNotBool(mlfIschar(mclVv(CfgLine, "CfgLine")))) {
            goto return_;
        }
        /*
         * CfgLine = upper(CfgLine); % Convert to upper case
         */
        mlfAssign(&CfgLine, mlfUpper(mclVv(CfgLine, "CfgLine")));
        /*
         * [Directive, Rest] = strtok(CfgLine, ' ,'); % Take the directive from the start of the line
         */
        mlfAssign(
          &Directive,
          mlfNStrtok(2, &Rest, mclVv(CfgLine, "CfgLine"), _mxarray208_));
        /*
         * switch Directive
         */
        {
            mxArray * v_ = mclInitialize(mclVv(Directive, "Directive"));
            if (mclSwitchCompare(v_, _mxarray327_)) {
                /*
                 * case 'EOS', return;
                 */
                mxDestroyArray(v_);
                goto return_;
            /*
             * otherwise,
             */
            } else {
            /*
             * end;
             */
            }
            mxDestroyArray(v_);
        }
    /*
     * end;
     */
    }
    /*
     * 
     * 
     * 
     */
    return_:
    mxDestroyArray(ans);
    mxDestroyArray(CfgLine);
    mxDestroyArray(Directive);
    mxDestroyArray(Rest);
    mxDestroyArray(fID);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
}

/*
 * The function "Maccosin_ReadNewConfigData" is the implementation version of
 * the "accosin/ReadNewConfigData" M-function from file
 * "c:\projects\mzdde\accosin.m" (lines 325-337). It contains the actual
 * compiled code for that M-function. It is a static function and must only be
 * called from one of the interface functions, appearing below.
 */
/*
 * function ReadNewConfigData(fID, Config, Surface)
 */
static void Maccosin_ReadNewConfigData(mxArray * fID,
                                       mxArray * Config,
                                       mxArray * Surface) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_accosin);
    mxArray * Rest = NULL;
    mxArray * Directive = NULL;
    mxArray * CfgLine = NULL;
    mxArray * ans = NULL;
    mclCopyArray(&fID);
    mclCopyArray(&Config);
    mclCopyArray(&Surface);
    /*
     * disp('Discarding New Config Data.');
     */
    mlfDisp(_mxarray364_);
    /*
     * while 1
     */
    for (;;) {
        /*
         * CfgLine = fgetl(fID);
         */
        mlfAssign(&CfgLine, mlfFgetl(mclVa(fID, "fID")));
        /*
         * if ~ischar(CfgLine), return; end; % (Unexpected) End of file
         */
        if (mclNotBool(mlfIschar(mclVv(CfgLine, "CfgLine")))) {
            goto return_;
        }
        /*
         * CfgLine = upper(CfgLine); % Convert to upper case
         */
        mlfAssign(&CfgLine, mlfUpper(mclVv(CfgLine, "CfgLine")));
        /*
         * [Directive, Rest] = strtok(CfgLine, ' ,'); % Take the directive from the start of the line
         */
        mlfAssign(
          &Directive,
          mlfNStrtok(2, &Rest, mclVv(CfgLine, "CfgLine"), _mxarray208_));
        /*
         * switch Directive
         */
        {
            mxArray * v_ = mclInitialize(mclVv(Directive, "Directive"));
            if (mclSwitchCompare(v_, _mxarray327_)) {
                /*
                 * case 'EOS', return;
                 */
                mxDestroyArray(v_);
                goto return_;
            /*
             * otherwise,
             */
            } else {
            /*
             * end;
             */
            }
            mxDestroyArray(v_);
        }
    /*
     * end;
     */
    }
    return_:
    mxDestroyArray(ans);
    mxDestroyArray(CfgLine);
    mxDestroyArray(Directive);
    mxDestroyArray(Rest);
    mxDestroyArray(Surface);
    mxDestroyArray(Config);
    mxDestroyArray(fID);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
}
