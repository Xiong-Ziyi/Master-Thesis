function [ZEMAXPath, LensPath] = zGetPath()
% zGetPath - Get the full path name to the directory where ZMEAX is installed.
%
% Usage : [ZEMAXPath, LensPath] = zGetPath
%
% This item extracts the full path name to the directory where ZEMAX is installed, and the path name to the
% default directory for lenses.
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
Paths = ddereq(ZemaxDDEChannel, 'GetPath', [1 1], ZemaxDDETimeout);
[ZEMAXPath, Paths] = strtok(Paths,' ,');
[LensPath, count, errmsg] = sscanf(Paths, ',%s');



