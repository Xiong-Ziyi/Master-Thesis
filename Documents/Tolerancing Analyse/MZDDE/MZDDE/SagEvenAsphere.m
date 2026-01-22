function Sag = SagEvenAsphere(ProfileData, r)
% SagEvenAsphere - Computes the profile of a ZEMAX standard even aspheric surface.
%
% Usage : Sag = SagEvenAsphere(ProfileData, r)
%
% The Profile data consists of a vector having the paraxial radius of curvature,
% the conic constant and a series of coefficients for the even power of the radial
% distance.
%
% The sag of the surface is computed at the distances r from the axis.
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

lenprof = length(ProfileData);
switch lenprof
    case 0
        c = 0; k = 0;
    case 1
        if ProfileData(1) ~= 0
            c=1/ProfileData(1);
        else
            c= 0;
        end
        k = 0;
    otherwise
        if ProfileData(1) ~= 0
            c=1/ProfileData(1);
        else
            c= 0;
        end
        k = ProfileData(2);
end
Sag = (c * r.^2)./(1 + sqrt(1 - (1+k) * c^2 .* r.^2));
if lenprof > 2
    for i = 3:lenprof
        Sag = Sag + ProfileData(i)*r.^(i-1);
    end
end
