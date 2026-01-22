function ParameterData = zSetSurfaceParameter(SurfaceNumber, ParameterNumber, NewValue)
% zSetSurfaceParameter - Sets lens surface parameter data.
%
% Usage : ParameterData = zSetSurfaceParameter(SurfaceNumber, ParameterNumber, NewValue)
%
% For example, to set the parameter 5 data for surface 8 to 22.5, the call should be
% zSetSurfaceParameter(8,5,22.5). The value 22.5 would be returned by the function.
%
% Returns NaN (not-a-number) if the function times out.
%
% See also zGetSurfaceData and zGetSurfaceParameter
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
DDECommand = sprintf('SetSurfaceParameter,%i,%i,%11.9f',SurfaceNumber,ParameterNumber,NewValue);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply), ParameterData = str2double(Reply); else ParameterData = NaN; end;

