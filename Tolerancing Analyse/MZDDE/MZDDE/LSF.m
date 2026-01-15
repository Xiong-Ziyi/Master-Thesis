function LSF=LSF(Lambda, F, x)
% LSF(Wavelengths, Focal_Ratio, X-Coordinates)
%
% Computes the monochromatic diffraction-limited line spread function at
% the given wavelengths (rows) at the coordinates given by x.
% x must be monotonic upward and equi-spaced.
%
% The LSF is computed using a fast fourier transform technique on the MTF
% computed from a closed-form expression. 

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

% Ensure that Lambda is a column vector

els = size(Lambda,1) * size(Lambda,2);
if (els == size(Lambda,2))
    Lambda = Lambda';
end
if (els ~= size(Lambda,1))
    Lambda = Lambda(:,1);
end

% Ensure that x is a row vector
els = size(x,1) * size(x,2);
if (els == size(x,2))
    x = x';
end
if (els ~= size(x,1))
    x = x(:,1);
end

% Ensure F scalar, positive
F=abs(F(1));

% Establish the minimum sampling in frequency space that will be adequate
dx = abs(mean(diff(x)));
cutoff = 1/(2*dx);

% Get the next highest power of 2 on the number of x samples
pow2 = ceil(log2(length(x)));
n = 2^pow2;

% Use a minimum of 1024 points
n = max(1024,n);

% Establish the optical cutoff frequency - must sample at least to this frequency
cutoff = max(1/(min(Lambda) * F), cutoff);

% Produce a frequency grid on the maximum cutoff frequency with adequate points
f = 0:(cutoff/(n-1)):cutoff;

% Compute the MTF at these frequencies
mMTF = MTF(Lambda, F, f);

% Compute the LSF using a FFT
mLSF = abs(fft(mMTF'))';

% Clobber the data above the halfway mark to zero
mLSF(:,(size(mLSF,2)/2+1):size(mLSF,2)) = 0;

% Establish the current x increment for our data
dx = 1/(2*cutoff);

% Produce the x-coordinte row vector
ourx = 0:dx:((n-1)*dx);

% Resample the LSF onto the requested row vector using spline interpolation
LSF = interp1(ourx, mLSF', x, 'spline')';

% Normalise each row of the LSF
LSF = LSF./repmat(max(LSF')',1 ,size(LSF,2));

