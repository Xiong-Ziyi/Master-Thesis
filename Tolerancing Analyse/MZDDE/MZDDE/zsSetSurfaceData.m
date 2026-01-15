function zsSurfaceData = zsSetSurfaceData(SurfaceNumber, SurfaceData)
% zsSetSurfaceData - Sets basic lens surface data from a Matlab structure.
%
% Usage : zsSurfaceData = zsSetSurfaceData(SurfaceNumber, SurfaceData)
%
% Must be passed a structure with the following fields.
% type (string), comment (string), curvature (numeric), thickness (numeric), glass (string),
% semidia (numeric), conic (numeric), coating (string)
% The surface SurfaceNumber will be set with these fields.
%
% See also zSetSurfaceData, zGetSurfaceData, zsGetSurfaceData

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
% $Revision: 1.2 $

zSetSurfaceData(SurfaceNumber, 0, SurfaceData.type);
zSetSurfaceData(SurfaceNumber, 1, SurfaceData.comment);
zSetSurfaceData(SurfaceNumber, 2, SurfaceData.curvature);
zSetSurfaceData(SurfaceNumber, 3, SurfaceData.thickness);
zSetSurfaceData(SurfaceNumber, 4, SurfaceData.glass);
zSetSurfaceData(SurfaceNumber, 5, SurfaceData.semidia);
zSetSurfaceData(SurfaceNumber, 6, SurfaceData.conic);
zSetSurfaceData(SurfaceNumber, 7, SurfaceData.coating);
