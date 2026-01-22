function RayTraceData = zGetTrace(wave, mode, surf, hx, hy, px, py)
% zGetTrace - Trace a ray through the current lens in the ZEMAX DDE server. 
%
% Usage : RayTraceData = zGetTrace(wave, mode, surf, hx, hy, px, py)
%
% In order to trace a ray, ZEMAX needs to know the
% relative field and pupil coordinates, the wavelength, the mode (either real, mode = 0 or paraxial, mode = 1) as
% well as the surface to trace the ray to. 
% For example, to trace the real chief ray to surface 5 at wavelength 3, the call would be
% RayTraceData = zGetTrace(3,0,5,0.0,1.0,0.0,0.0);
% Usually, the ray data is only needed at the image surface; setting the surface
% number to -1 will yield data at the image surface. Note 0 is reserved for the object surface.
% The raytrace data message comes back in the following row vector:
% error, vigcode, x, y, z, l, m, n, l2, m2, n2, intensity
% The integer error will be zero if the ray traced successfully, otherwise it will be a positive or negative number.
% If positive, then the ray missed the surface number indicated by error. If negative, then the ray total internal
% reflected (TIR) at the surface given by the absolute value of the error number. Always check to verify the ray data
% is valid before using the rest of the vector.
% The parameter vigcode is the first surface where the ray was vignetted. Unless an error occurs at that surface
% or subsequent to that surface, the ray will continue to trace to the requested surface.
% The x, y, and z values are the coordinates on the requested surface.
% The l, m, and n values are the direction cosines after refraction into the media following the requested surface.
% The l2, m2, and n2 values are the surface intercept direction normals at the requested surface.
% The intensity is the relative transmitted intensity of the ray, including any pupil or surface apodization defined.
%
% See also zGetTraceDirect, zGetPolTrace, zGetPolTraceDirect
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
DDECommand = sprintf('GetTrace,%i,%i,%i,%11.9f,%11.9f,%11.9f,%11.9f', wave, mode, surf, hx, hy, px, py);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%i,%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f');
RayTraceData = col';



