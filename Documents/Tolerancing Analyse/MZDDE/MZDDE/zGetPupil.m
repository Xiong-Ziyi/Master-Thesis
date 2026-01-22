function PupilData = zGetPupil()
% zGetPupil - Gets the aperture stop and pupil data from ZEMAX.
%
% Usage : PupilData = zGetPupil
% The returned row vector is formatted as follows:
% type, value, ENPD, ENPP, EXPD, EXPP, apodization_type, apodization_factor"
% The parameter type is an integer indicating the system aperture type, a number between 0 and 5, for entrance
% pupil diameter, image space F/#, object space NA, float by stop size, paraxial working F/#, or object cone angle,
% respectively. The value is the system aperture value, unless float by stop size is being used, in which case the
% value is the stop surface semi-diameter. The next 4 values are the entrance pupil diameter, entrance pupil
% position, exit pupil diameter, and exit pupil position, all in lens units. The apodization_type is an integer which is
% set to 0 for none, 1 for Gaussian, 2 for Tangential. The apodization_factor is the number shown on the general
% data dialog box.
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
Reply = ddereq(ZemaxDDEChannel, 'GetPupil', [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f');
PupilData = col';

