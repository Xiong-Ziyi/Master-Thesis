function SystemData = zGetSystem()
% zGetSystem - Gets a number of lens system operating data.
%
% Usage : SystemData = zGetSystem
% The returned row vector  is formatted as follows:
% numsurfs, unitcode, stopsurf, nonaxialflag, rayaimingtype, useenvdata, temp, pressure, globalrefsurf
% This item returns the number of surfaces, the unit code (0, 1, 2, or 3 for mm, cm, in , or M), the stop surf number,
% a flag to indicate if the system is non-axial symmetric (0 for false, that is it is axial, or 1 if the system is not axial),
% the ray aiming type (0, 1, 2 for none, paraxial, real), the use environment data flag (0 for no, 1 for yes), the current
% temperature and pressure, and the global coordinate reference surface number.
%
% See also zSetSystem and zGetSystemAper
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
Reply = ddereq(ZemaxDDEChannel, 'GetSystem', [1 1], ZemaxDDETimeout);
[ParmsCol,count,errmsg]= sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f,%f');
SystemData = ParmsCol';
