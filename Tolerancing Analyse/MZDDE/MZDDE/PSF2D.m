function PSF2D=PSF2D(Lambda, w, F, xres, yres, ds, e)
% PSF2D(Wavelengths, Wavelength_Weights, Focal_Ratio, Number_of_X_Pixels, Number_of_Y_Pixels, Pixel_Pitch, Central_Obscuration_Ratio)
%
% Computes a normalised 2-dimensional image of the polychromatic diffraction-limited point spread function.
% The number of pixels in x and y can be specified, along with the pixel pitch.
% A central obscuration can be specified with the ratio of the obscuration diameter to the total diameter.
% The x and y pixel counts should be even.
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


% Copyright 2003, Defencetek, CSIR
% $Revision: 1.1 $

% First find the length of the image semidiagonal in pixels.
semidiag = sqrt((xres/2)^2 + (yres/2)^2);

% Next compute the radial distances to compute the 1D PSF
r = 0:ds:(ds*(semidiag + 0.01 * semidiag)); % Ensure we get far enough out

% semidiag = round(semidiag);

% Compute the 1D PSF
apPSF = PPSF(Lambda, w, F, r, e);

% Now compute the radial distance of the centre of each pixel from the centre of the image
x = -xres/2:1:xres/2;
y = -yres/2:1:yres/2;
[x,y] = meshgrid(x,y);
rr = ds * sqrt(x.*x + y.*y); % Radial distance of each pixel

% Interpolate the 2D image
PSF2D = interp1(r, apPSF, rr, 'spline');



