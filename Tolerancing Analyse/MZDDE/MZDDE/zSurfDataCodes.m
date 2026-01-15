function SurfDataCodes = zSurfDataCodes()
% zSurfDataCodes - Returns structure with surface data codes for use with zGetSurfaceData
%
% Usage : SurfDataCodes = zSurfDataCodes
%
% Returns a struct with the following fields and values, coresponding to the codes required by the
% zGetSurfaceData call.
%
% type = 0       - Surface type name. ( 8 character string)
% comment = 1    - Surface Comment. (string)
% curvature = 2  - Surface Curvature (numeric).
% thickness = 3  - Thickness. (numeric)
% glass = 4      - Glass. (string)
% semidia = 5    - Semi-Diameter. (numeric)
% conic = 6      - Conic. (numeric)
% coating = 7    - Coating. (string)
%
% See also zGetSurfaceData, zSetSurfaceData
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
% $Revision: 1.1 $

SurfDataCodes = struct('type', 0, 'comment', 1, 'curvature', 2, 'thickness', 3, 'glass', 4, 'semidia', 5, 'conic', 6, 'coating', 7);
