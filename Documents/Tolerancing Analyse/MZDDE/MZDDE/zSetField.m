function FieldData = zSetField(n, xf, yf, wgt, vdx, vdy, vcx, vcy, van)
% zSetField - Sets field data for a particular field point.
%
% Usage : FieldData = zSetField(n, xf, yf, wgt, vdx, vdy, vcx, vcy, van)
%
% If n is a valid field number (between 1 and the number of fields, inclusive) then the field x and y values, field weight,
% and vignetting factors are all set.  The returned row vector is the same as for zGetField.
%
% See also zGetField
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
DDECommand = sprintf('SetField,%i,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f,%11.9f',n, xf, yf, wgt, vdx, vdy, vcx, vcy, van);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f');
FieldData = col';


