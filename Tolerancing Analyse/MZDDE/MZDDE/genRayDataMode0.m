function RayData = genRayDataMode0(hx, hy, px, py, radius, raytracingmode, finalsurface, intensity, wavenumber, opdrequest)
% genRayDataMode0 - generates a raydata structure suitable for passing to zArrayTrace mode 0.
%
% Usage : RayData = genRayDataMode0(hx, hy, px, py, radius, ...
%                                   raytracingmode, finalsurface, intensity, wavenumber, opdrequest)
%
% hx and hy are scalars giving fractional field coordinates.
% px and py are vectors of fractional pupil coordinates. radius is the maximum radius for which points should
% be generated in the pupil.
% raytracingmode is set to 0 for real rays and 1 for paraxial rays.
% finalsurface is the surface at which to stop raytracing. Use -1 for the image surface.
% intensity is the initial intensity to assign to each ray.
% wavenumber is the wavelength number for the raytrace.
% opdrequest is set to 0 for no OPD calculation. Set to 1 to request OPD calculation.
%
% The structure RayData which is returned is suitable for passing directly to zArrayTrace.
%
% See also zArrayTrace, gridXYRayData

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


% Copyright 2003, Defencetek, CSIR
% $Revision: 1.0 $

% First grid the px and py data using the radius limiter.

RayData = gridXYRayData(px, py, 'z', 'l', radius);

% Then add the other non-zero fields required for each ray in mode 0
[RayData.x] = deal(hx);
[RayData.y] = deal(hy);
[RayData.intensity] = deal(intensity);
[RayData.wave] = deal(wavenumber);
[RayData.want_opd] = deal(opdrequest);

% Lastly, add the header element at the start of the array.
RayData = cat(1,RayData(1),RayData);  % Simply duplicate the first element

% Zero out the unwanted fields in element 1 to avoid confusion
RayData(1).x = 0;
RayData(1).y = 0;
RayData(1).z = 0;
RayData(1).l = 0;
RayData(1).intensity = 0;
RayData(1).wave = 0;

% Insert the non-zero elements, especially the "error" field which carries the number of rays
RayData(1).opd = 0; % Would default to zero, but state the mode selection explicitly for reference.
RayData(1).wave = raytracingmode; % Selects real or paraxial mode.
RayData(1).error = numel(RayData)-1; % This is the number of rays.
RayData(1).want_opd = finalsurface;  % Surface to raytrace to. -1 signifies image surface.

% This structure should be all good for zArrayTrace mode 0 ...


