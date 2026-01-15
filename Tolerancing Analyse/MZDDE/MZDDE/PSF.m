function PSF = PSF(Lambda, F, r, e)
% PSF(Wavelengths, Focal_Ratio, Radial_Image_Coordinates, Central_Obscuration_Ratio)
%
% Computes the monochromatic Diffraction Point Spread Function for a number of wavelengths and radial image coordinates.
% The radial image coordinate will be in the same length units as that used for the wavelength.
% The focal ratio is the ratio of the focal length to the lens diameter.
% The central obscuration ratio is the ratio of the diameter of the central obscuration to the total clear diameter.
%
% A matrix is returned with the results corresponding to varying radial image coordinate along the columns,
% and the results corresponding to varying wavelength along the rows.

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
% $Revision: 1.2 $

% Check to see if Lambda is a column vector - if not make it one.
% If it is a matrix select only the first column

fuzz = 1e-12; % This is the amount added to values of r which are zero

els = size(Lambda,1) * size(Lambda,2);
if (els == size(Lambda,2))
    Lambda = Lambda';
end
if (els ~= size(Lambda,1))
    Lambda = Lambda(:,1);
end

% Check to see if r is a row vector - if not make it one
% If it is a matrix select only the first row.

els = size(r,1) * size(r,2);
if (els == size(r,1))
    r=r';
end
if (els ~= size(r,2))
    r=r(:,1);
end


% We only want a scalars for F and e
F = abs(F(1));
e = abs(e(1));

% Find any zeros in r
i = find(r==0);

% If there is a zero in r, add a tiny amount
r(i) = r(i) + fuzz;
    
% Now mesh the wavelengths and the radial image coordinates to find the matrix of inputs to the bessel functions
[x,y]=meshgrid(r, Lambda);
nu = pi*(x./y)/F;
enu = e*nu;
if (e ~= 0.0)
    PSF = (2*besselj(1,nu)./nu - e*2*besselj(1,enu)./nu).^2;
else
    PSF = (2*besselj(1,nu)./nu).^2;
end
