function WaveDataMatrix = zGetWaveMatrix()
% zGetWaveMatrix - Gets data on all defined wavelengths from the Zemax DDE server.
%
% Usage : WaveDataMatrix = zGetWaveMatrix
%
% Returns a matrix having colummns wavelength and weight for all defined wavelengths.
%
% See also zGetWave, zSetWave
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
WaveCount = zGetWave(0);
WaveCount = WaveCount(2);
for iii = 1:WaveCount
  DDECommand = sprintf('GetWave,%i',iii);
  Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
  [col, count, errmsg] = sscanf(Reply, '%f,%f');
  WaveDataMatrix(iii, 1) = col(1);
  WaveDataMatrix(iii, 2) = col(2);
end



