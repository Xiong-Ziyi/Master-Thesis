function ParameterVector = zSetSurfaceParamVector(SurfaceNumber, ParamVector)
% zSetSurfaceParamVector - Sets all lens surface parameter data from a 13 column row vector.
%
% Usage : ParameterVector = zSetSurfaceParamVector(SurfaceNumber, ParamVector)
%
% If the vector passed has fewer than 13 columns, missing columns on the right will be set to zero.
% If DDE requests to ZEMAX time out, the function will return NaN
% (not-a-number).
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
ParamCols = size(ParamVector,2);
if ParamCols < 13,
    for iii = (ParamCols+1):13, ParamVector(1,iii) = 0; end;
end
for ParameterNumber = 0:12
  DDECommand = sprintf('SetSurfaceParameter,%i,%i,%11.9f',SurfaceNumber,ParameterNumber,ParamVector(1,ParameterNumber+1));
  Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
  if (Reply), ParameterVector(1,ParameterNumber+1) = str2double(Reply); else ParameterVector = [NaN]; return; end;
end


