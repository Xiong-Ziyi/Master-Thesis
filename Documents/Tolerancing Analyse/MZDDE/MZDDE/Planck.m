function Planck = Planck(wv, T)
% Planck(Wavelength, Temperature)
%
% Returns spectral radiance of a Black Body
% in watts per square centimetre per micron of spectral bandwidth
% Parameters are wavelength and temperature
% Wavelength is in microns
% Temperature is in Kelvins (Celsius + 273)
% Both wavelength and temperature can be vectors.
% 
% Returns a matrix with wavelength varying from row to row and T varying from column to column
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

% First meshgrid the data
[T,wv] = meshgrid(T,wv);

% Now compute the black body data set
Planck = 1.191066e4 * ones(size(wv)) ./ (wv .^ 5 .* (exp(1.43879e4 * ones(size(wv)) ./ (wv .* T)) - 1));

% Duarte's expression L = 1.191066e4*ones(size(lambda))./(lambda.^5.*(exp(1.43883e4*ones(size(lambda))./(lambda*T)) - 1));
