% Read CIE Data into Workspace variables
% The following data files are read.
% You can load these workspace variables also using load('CIE.mat');
%
% CIEsia.txt
% 	CIE 15.2-1986 Table 1.1 
% 	Part 1: CIE Standard Illuminant A relative spectral power distribution
% 	300 nm - 830 nm at 5 nm intervals (CIEsLambda)
% 
% CIEsid65.txt
% 	CIE 15.2-1986 Table 1.1
% 	Part 2: CIE Standard Illuminant D65 relative spectral power distribution
% 	300 nm - 830 nm at 5 nm intervals (CIEsLambda)
% 
% CIEs0.txt
% 	CIE 15.2-1986 Table 1.2
% 	Part 1. Component S0 of daylight used in the calculation of relative
% 	spectral power distribution of daylight illuminants of different 
% 	correlated colour temperatures, for wavelength 300 to 830 nm at 5 nm
% 	intervals (CIEsLambda)
% 
% CIEs1.txt
% 	CIE 15.2-1986 Table 1.2
% 	Part 2. Component S1 of daylight used in the calculation of relative
% 	spectral power distribution f daylight illuminants of different
% 	correlated colour temperatures, for wavelength 300 to 830 nm at 5 nm
% 	intervals (CIEsLambda)
% 
% CIEs2.txt
% 	CIE 15.2-1986 Table 1.2
% 	Part 3. Component S2 of daylight used in the calculation of relative
% 	spectral power distribution of daylight illuminants of different
% 	correlated colour temperatures, for wavelength 300 to 830 nm at 5 nm
% 	intervals (CIEsLambda)
% 
% CIEx2.txt
% 	CIE 15.2-1986 Table 2.1 data
% 	CIE 1931 Standard Colorimetric Observer x2(lambda) data between
% 	380 nm and 780 nm at 5 nm intervals (CIExyzLambda)
% 
% CIEy2.txt
% 	CIE 15.2-1986 Table 2.1 data
% 	CIE 1931 Standard Colorimetric Observer y2(lambda) data between
% 	380 nm and 780 nm at 5 nm intervals (CIExyzLambda)
% 
% CIEz2.txt
% 	CIE 15.2-1986 Table 2.1 data
% 	CIE 1931 Standard Colorimetric Observer z2(lambda) data between
% 	380 nm and 630 nm at 5 nm intervals (CIExyzLambda)
% 
% CIEx10.txt
% 	CIE 15.2-1986 Table 2.2 data
% 	CIE 1964 Supplementary Standard Colorimetric Observer x10(lambda)
% 	data between 380 nm and 780 nm at 5 nm intervals (CIExyzLambda)
% 
% CIEy10.txt
% 	CIE 15.2-1986 Table 2.2 data
% 	CIE 1964 Supplementary Standard Colorimetric Observer y10(lambda)
% 	data between 380 nm and 780 nm at 5 nm intervals (CIExyzLambda)
% 
% CIEz10.txt
% 	CIE 15.2-1986 Table 2.2 data
% 	CIE 1964 Supplementary Standard Colorimetric Observer z10(lambda)
% 	data between 380 nm and 560 nm at 5 nm intervals (CIExyzLambda)


% MZDDE - The ZEMAX DDE Toolbox for Matlab.
% Copyright (C) 2002-2004 Defencetek, CSIR
% Contact : dgriffith@csir.co.za
% 
% This file is part of MZDDE.
% 
%  MZDDE is free software; you can redistribute it and/or modify
%  it under the terms of the GNU General Public License as published by
%  the Free Software Foundation; either version 2 of the License, or
%  (at your option) any later version.
%
%  MZDDE is distributed in the hope that it will be useful,
%  but WITHOUT ANY WARRANTY; without even the implied warranty of
%  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%  GNU General Public License for more details.
%
%  You should have received a copy of the GNU General Public License
%  along with MZDDE (COPYING.html); if not, write to the Free Software
%  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
%

% Copyright 2002, Defencetek, CSIR
% $Revision: 1.2 $
% $Author: dgriffith $

fullpath = which('ReadCIE');
[pathstr,name,ext,versn] = fileparts(fullpath);

CIEsLambda = (300:5:830)';
CIEsia = textread([pathstr '\CIE\CIEsia.txt'],'%f', 'headerlines', 3);
CIEsid65 = textread([pathstr '\CIE\CIEsid65.txt'],'%f', 'headerlines', 3);
CIEs0 = textread([pathstr '\CIE\CIEs0.txt'],'%f', 'headerlines', 4);
CIEs1 = textread([pathstr '\CIE\CIEs1.txt'],'%f', 'headerlines', 4);
CIEs2 = textread([pathstr '\CIE\CIEs2.txt'],'%f', 'headerlines', 4);

CIExyzLambda = (380:5:780)';
CIEx2 = textread([pathstr '\CIE\CIEx2.txt'],'%f', 'headerlines', 3);
CIEy2 = textread([pathstr '\CIE\CIEy2.txt'],'%f', 'headerlines', 3);
CIEz2 = textread([pathstr '\CIE\CIEz2.txt'],'%f', 'headerlines', 3); CIEz2(size(CIExyzLambda)) = 0;
CIEx10 = textread([pathstr '\CIE\CIEx10.txt'],'%f', 'headerlines', 3);
CIEy10 = textread([pathstr '\CIE\CIEy10.txt'],'%f', 'headerlines', 3);
CIEz10 = textread([pathstr '\CIE\CIEz10.txt'],'%f', 'headerlines', 3); CIEz10(size(CIExyzLambda)) = 0;


