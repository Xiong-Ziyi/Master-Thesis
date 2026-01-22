function zmxOTF = zGetMTF(DataFile, SettingsFile)
% zmxOTF = zGetMTF(DataFile, SettingsFile)
%
% Requests ZEMAX to compute the thru-frequency MTF analysis for the current lens and configuration.
% The text data is written to Datafile, and the settings for the analysis are read from SettingsFile.
%
% The analysis is performed on the lens in the LDE.
%
% The data is returned as for ReadZemaxOTF.

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


% Copyright 2003, Defencetek, CSIR
% $Revision: 1.1 $

zGetTextFile(DataFile, 'Mtf', SettingsFile, 1);
zmxOTF = ReadZemaxOTF(DataFile);

