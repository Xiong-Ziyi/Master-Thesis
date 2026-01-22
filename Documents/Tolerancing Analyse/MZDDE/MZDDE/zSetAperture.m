function ApertureInfo = zSetAperture(SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile)
% zSetAperture - Set aperture details at a ZEMAX lens surface.
%
% Usage : ApertureInfo = zSetAperture(SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile)
%
% The returned row vector is formatted as follows:
% Type, Min, Max, xDecenter, yDecenter
%
% This function uses an integer code for the surface aperture type; 0 for no aperture, 1 for circular aperture, 2 for
% circular obscuration, 3 for spider, 4 for rectangular aperture, 5 for rectangular obscuration, 6 for elliptical aperture,
% 7 for elliptical obscuration, 8 for user defined aperture, 9 for user defined obscuration, and 10 for floating aperture.
% The min and max values have different meanings for the elliptical, rectangular, and spider apertures than for
% circular apertures; see 'Aperture type and other aperture controls' in the ZEMAX manual for details.
% If zSetAperture is used to set user defined apertures or obscurations, the ApertureFile must be the name of a
% file which lists the x, y, coordinates of the user defined aperture file in a two column format. For more information
% on user defined apertures, see 'User defined apertures and obscurations' in the ZEMAX manual.
%
% See also zGetAperture.
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
DDECommand = sprintf('SetAperture,%i,%i,%11.9f,%11.9f,%11.9f,%11.9f,%s',SurfaceNumber, Type, Min, Max, xDecenter, yDecenter, ApertureFile);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f');
ApertureInfo = col';


