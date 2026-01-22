function WaveData = zSetWave(WaveNumber, Wavelength, Weight)
% zSetWave - Define wavelengths and weights in ZEMAX.
%
% Usage : WaveData = zSetWave(WaveNumber, Wavelength, Weight)
% or    : WaveData = zSetWave(0, PrimaryWavelength, NumberOfWavelengths)
% If the value for WaveNumber is zero, then the primary wavelength number and the total number of wavelengths is set to
% the new integer values. If WaveNumber is a valid wavelength number (between 1 and the number of wavelengths, inclusive)
% then the wavelength in microns and the wavelength weight are both set. The returned data
% is the same as for zGetWave(WaveNumber)
%
% See also zGetWave
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
if WaveNumber == 0
   DDECommand = sprintf('SetWave,0,%i,%i',Wavelength,Weight);
else
   DDECommand = sprintf('SetWave,%i,%11.9f,%11.9f',WaveNumber, Wavelength, Weight);
end
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if WaveNumber == 0
   [col, count, errmsg] = sscanf(Reply, '%i,%i');
else
   [col, count, errmsg] = sscanf(Reply, '%f,%f');
end
WaveData = col';

