function oWaveDataMatrix = zSetWaveMatrix(iWaveDataMatrix)
% zSetWaveMatrix - Sets wavelength and weight data from a matrix.
%
% Usage : oWaveDataMatrix = zSetWaveMatrix(iWaveDataMatrix)
%
% The wavelengths are set from column 1 of the matrix iWaveDataMatrix, and the weights are set from
% column 2. The primary wavelength is assumed to be wavelength 1. To change the primary wavelength,
% use zSetWavePrimary.
%
% Returns a matrix having colummns wavelength and weight for all defined wavelengths.
%
% See also zGetWave, zSetWave, zSetWavePrimary
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
% $Revision: 1.3 $

global ZemaxDDEChannel ZemaxDDETimeout
WaveCount = size(iWaveDataMatrix,1);
zSetWave(0,1,WaveCount); % Set the primary wavelength to 1 and the number of wavelengths to the rows of iWaveDataMatrix.
for iii = 1:WaveCount
  DDECommand = sprintf('SetWave,%i,%11.9f,%11.9f',iii, iWaveDataMatrix(iii, 1), iWaveDataMatrix(iii, 2));
  Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
  [col, count, errmsg] = sscanf(Reply, '%f,%f');
  oWaveDataMatrix(iii, 1) = col(1);
  oWaveDataMatrix(iii, 2) = col(2);
end

