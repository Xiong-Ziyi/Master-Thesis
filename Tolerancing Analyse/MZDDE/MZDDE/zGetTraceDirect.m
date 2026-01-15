function RayTraceData = zGetTraceDirect(wave, mode, startsurf, stopsurf, x, y, z, l, m, n)
% zGetTraceDirect - Direct access raytrace through the current lens in the ZEMAX DDE server. 
%
% Usage : RayTraceData = zGetTraceDirect(wave, mode, startsurf, stopsurf, x, y, z, l, m, n)
%
% zGetTraceDirect provides a more direct access to the ZEMAX ray tracing engine. Normally, rays are defined
% by the normalized field and pupil coordinates hx, hy, px, and py. ZEMAX takes these normalized coordinates and
% computes the object coordinates (x, y, and z) and the direction cosines to the entrance pupil aim point (l, m, and
% n; for the x-, y-, and z-direction cosines, respectively).
% However, there are times when it is more appropriate to trace rays by direct specification of x, y, z, l, m, and
% n. The direct specification has the added flexibility of defining the starting surface for the ray anywhere in the
% optical system. This flexibility comes at the price of requiring the client program to carefully ensure that the starting
% ray coordinates are meaningful.
% Like zGetTrace, this item requires that the client provide additional data. In order to trace a ray, ZEMAX needs
% to know x, y, z, l, m, n, the wavelength, the mode (either real, mode = 0 or paraxial, mode = 1) as well as the
% starting and stopping surfaces to trace the ray from and to. 
% The data vector comes back in the following format:
% error, vigcode, x, y, z, l, m, n, l2, m2, n2, intensity
% where the parameters are exactly the same as for zGetTrace, except for intensity. The intensity is the relative
% transmitted intensity of the ray, excluding any pupil apodization defined. Note zGetTrace includes pupil apodization,
% zGetTraceDirect does not. Both include surface apodizations.
%
% See also zGetTrace, zGetPolTrace, zGetPolTraceDirect
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
DDECommand = sprintf('GetTraceDirect,%i,%i,%i,%i,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f', wave, mode, startsurf, stopsurf, x, y, z, l, m, n);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%i,%i,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f');
RayTraceData = col';

