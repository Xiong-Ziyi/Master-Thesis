function ParameterData = zGetSurfaceParameter(SurfaceNumber,ParameterNumber)
% zGetSurfaceParameter - extracts surface parameter data.
%
% Usage : ParameterData = zGetSurfaceParameter(SurfaceNumber,ParameterNumber)
%
% For example, to get the parameter 5 data for surface 8, the call should be
% GetSurfaceParameter(8,5)
%
% Returns NaN (Not-a-Number) if the command times out.
%
% See also zGetSurfaceData and zSetSurfaceParameter
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
% $Revision: 1.4 $

global ZemaxDDEChannel ZemaxDDETimeout
DDECommand = sprintf('GetSurfaceParameter,%i,%i',SurfaceNumber,ParameterNumber);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply), ParameterData = str2num(Reply); else ParameterData = NaN; end;

