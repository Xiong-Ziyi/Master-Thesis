function zsApertureData = zsGetAperture(SurfaceNumber)
% zsGetAperture - Get a structure containing aperture information at a surface.
%
% Usage : zsApertureData = zsGetAperture(SurfaceNumber)
% Returns a structure having the following fields.
% type, min, max, xdec, ydec
% This function returns the type as an integer code; 0 for no aperture, 1 for circular aperture, 2 for circular
% obscuration, 3 for spider, 4 for rectangular aperture, 5 for rectangular obscuration, 6 for elliptical aperture, 7 for
% elliptical obscuration, 8 for user defined aperture, 9 for user defined obscuration, and 10 for floating aperture. The
% min and max values have different meanings for the elliptical, rectangular, and spider apertures than for circular
% apertures; see the Editors Menu chapter in the Zemax Manual for details. 
%
% See also zSetAperture, zsSetAperture, zGetAperture

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
ApertureData = zGetAperture(SurfaceNumber);
zsApertureData = struct('type', ApertureData(1), 'min', ApertureData(2), 'max', ApertureData(3), 'xdec', ApertureData(4), 'ydec', ApertureData(5));
