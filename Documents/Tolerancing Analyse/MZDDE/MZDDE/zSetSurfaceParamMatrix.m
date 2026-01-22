function ParameterMatrix = zSetSurfaceParamMatrix(ParamMatrix)
% zSetSurfaceParamMatrix - Sets all lens surface parameter data from a 13 column matrix.
%
% Usage : ParameterMatrix = zSetSurfaceParamMatrix(ParamMatrix)
%
% If the matrix passed has fewer than 13 columns, missing columns on the right will be set to zero.
% Returns NaN (not-a-number) if data requests to ZEMAX time out.
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
ParamCols = size(ParamMatrix,2);
if ParamCols < 13,
    for iii = (ParamCols+1):13, ParamMatrix(:,iii) = zeros(size(ParamMatrix,1),13); end;
end
for SurfaceNumber = 0:(size(ParamMatrix,1)-1)
  for ParameterNumber = 0:12
    DDECommand = sprintf('SetSurfaceParameter,%i,%i,%11.9f',SurfaceNumber,ParameterNumber,ParamMatrix(SurfaceNumber+1,ParameterNumber+1));
    Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
    if (Reply), ParameterMatrix(SurfaceNumber+1,ParameterNumber+1) = str2double(Reply); else ParameterMatrix = [NaN]; return; end;
  end
end


