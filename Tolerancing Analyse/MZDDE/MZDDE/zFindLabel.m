function Surface = zFindLabel(Label)
% zFindLabel - Finds a previously labeled surface in the Zemax DDE client lens.
%
% Example : 
% LabeledSurface = zFindLabel(10)
%
% Finds the surface number which was labeled number 10 using the zSetLabel function.
%
% The returned value is the surface number of the first surface with the identical integer label, or -1 
% if no surface has the specified label. A return value of NaN (Not-a-Number) indicates that the command has timed out.
%
% See also zSetLabel and zGetLabel.
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
% $Revision: 1.4 $

global ZemaxDDEChannel ZemaxDDETimeout
DDECommand = sprintf('FindLabel,%i',Label);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply), Surface = str2num(Reply); else Surface = NaN; end;

