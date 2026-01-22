function DefaultPolState = zGetPolState()
% zGetPolState - Gets the default polarization state set by the user.
%
% Usage : DefaultPolState = zGetPolState
% The row vector returned is formatted as follows:
% nIsPolarized, Ex, Ey, Phax, Phay
% If nIsPolarized is anything other than zero, then the default polarization state is unpolarized. Otherwise, the
% Ex, Ey, Phax, and Phay values are used to define the polarization state. Ex and Ey should each be normalized
% to a magnitude of unity, although this is not required. Phax and Phay are in degrees. 
%
% See also zSetPolState.
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
Reply = ddereq(ZemaxDDEChannel, 'GetPolState', [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f');
DefaultPolState = col';
