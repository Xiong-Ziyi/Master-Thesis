function PMTF=PMTF(Lambda, w, F, f)
% PMTF(Wavelengths, Wavelength_Weights, Focal_Ratio, Spatial_Frequencies)
%
% Computes the polychromatic diffraction-limited MTF for the given wavelengths
% summed with the given weights.

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

% First ensure the wavlengths are a column vector
els = size(Lambda,1) * size(Lambda,2);
if (els == size(Lambda,2))
    Lambda = Lambda';
end
if (els ~= size(Lambda,1))
    Lambda = Lambda(:,1);
end
% Similar for the weights
els = size(w,1) * size(w,2);
if (els == size(w,2))
    w = w';
end
if (els ~= size(w,1))
    w = w(:,1);
end

% Ensure that weights and Lambda are same length
if size(w,1) < size(Lambda,1)
    w = cat(1, w, ones(size(Lambda,1)-size(w,1),1));
end
if size(w,1) > size(Lambda,1)
    w = w(1:1:size(Lambda,1));
end


% Compute the monochromatic MTFs
mMTF = MTF(Lambda, F, f);

% Create matrix of weights
Weights = repmat(w, 1, size(mMTF,2));

% Weigh and sum over wavelengths
PMTF = sum(Weights .* mMTF,1);

% Finally the result is normalised
PMTF = PMTF / max(PMTF);
