function [x, y] = SpiralSpot(Hy, Hx, Wave, Spirals, Rays)
% SpiralSpot - Produces a series of x, y values of rays traced in a spiral over the entrance pupil
%
% Usage : [x, y] = SpiralSpot(ObjectHeighty, ObjectHeightx, Wave, Spirals, Rays)
%         plot(x,y)
% Where the x and y data is the ray landing  data at the image surface in lens units.
%       ObjectHeighty is the fractional object height in y from which the rays are traced.
%       ObjectHeightx is the fractional object height in y from which the rays are traced.
%       Wave is the wavelength number to use.
%       Spirals is the number of spirals to execute.
%       Rays is the number of rays to trace, and therefore the number of x,y pairs as well.

% MZDDE - The ZEMAX DDE Toolbox for Matlab.
% Copyright (C) 2002-2005 Defencetek, CSIR
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

% $Revision: 1.0 $
% $Author: dgriffith $

zGetRefresh;  % Get the latest lens

FinishAngle = Spirals * 2 * pi;
dTheta = FinishAngle / (Rays-1);
Theta = 0:dTheta:FinishAngle;
R = Theta / FinishAngle;
Px = R .* cos(Theta);
Py = R .* sin(Theta);

for i = 1:length(Px)
  RayTraceData = zGetTrace(Wave, 0, -1, Hx, Hy, Px(i), Py(i));
  if RayTraceData(1) == 0
      x(i) = RayTraceData(3);
      y(i) = RayTraceData(4);
  else
      error('Raytrace Error');
  end
end



