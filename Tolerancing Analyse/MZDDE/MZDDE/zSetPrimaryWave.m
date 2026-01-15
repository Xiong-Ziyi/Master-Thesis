function WaveData = zSetPrimaryWave(PrimaryWaveNumber)
% zSetPrimaryWave - Set the primary wavelength number in ZEMAX.
%
% Usage : WaveData = zSetPrimaryWave(PrimaryWaveNumber)
%
% Sets the primary wavelength number to PrimaryWaveNumber.
% The returned data is the same as for zGetWave(WaveNumber), namely a row vector containing the
% primary wavelength number and the number of defined wavelengths.
%
% See also zGetWave, zSetWave, zSetWaveMatrix, zGetWaveMatrix
%

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
% $Revision: 1.1 $

global ZemaxDDEChannel ZemaxDDETimeout
WaveData = zGetWave(0);
DDECommand = sprintf('SetWave,0,%i,%i',PrimaryWaveNumber, WaveData(2));
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f');
WaveData = col';
