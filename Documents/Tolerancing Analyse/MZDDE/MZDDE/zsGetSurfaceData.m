function zsSurfaceData = zsGetSurfaceData(SurfaceNumber)
% zsGetSurfaceData - Get a structure containing the basic lens surface data.
%
% Usage : zsSurfaceData = zsGetSurfaceData(SurfaceNumber)
% Returns a structure having the following fields.
% type (string), comment (string), curvature (numeric), thickness (numeric), glass (string),
% semidia (numeric), conic (numeric), coating (string)
%
% See also zsSetSurfaceData, zSetSurfaceData, zGetSurfaceData

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
zsSurfaceData = struct('type', zGetSurfaceData(SurfaceNumber, 0), 'comment', zGetSurfaceData(SurfaceNumber, 1), 'curvature', zGetSurfaceData(SurfaceNumber, 2),'thickness',   zGetSurfaceData(SurfaceNumber, 3), 'glass', zGetSurfaceData(SurfaceNumber, 4), 'semidia', zGetSurfaceData(SurfaceNumber, 5), 'conic', zGetSurfaceData(SurfaceNumber, 6), 'coating', zGetSurfaceData(SurfaceNumber, 7));
                
