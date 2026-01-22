function SurfaceDatum = zGetSurfaceData(SurfaceNumber, Code)
% zGetSurfaceData - Gets various data on a sequential lens surface.
%
% Usage : SurfaceDatum = zGetSurfaceData(SurfaceNumber,Code)
% Returns a single numeric or string depending on the code according to the following table.
% Code      - Datum returned by zGetSurfaceData
% 0         - Surface type name. ( 8 character string)
% 1         - Comment. (string)
% 2         - Curvature (numeric).
% 3         - Thickness. (numeric)
% 4         - Glass. (string)
% 5         - Semi-Diameter. (numeric)
% 6         - Conic. (numeric)
% 7         - Coating. (string)
% 8 and up  - Reserved for future expansion of this feature.
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
DDECommand = sprintf('GetSurfaceData,%i,%i',SurfaceNumber,Code);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
switch Code
  case {0,1,4,7}, SurfaceDatum = Reply;
  case {2,3,5,6}, SurfaceDatum = str2num(Reply);
  otherwise, SurfaceDatum = Reply;
end
if (Code == 0) SurfaceDatum = SurfaceDatum(1,1:8); end;

