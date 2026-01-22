function FieldData = zGetField(FieldNumber)
% zGetField - Requests data on lens field points from the Zemax DDE server.
%
% Usage : FieldData = zGetField(FieldNumber)
% Returns a row vector for field point number FieldNumber. The vector contains xfield, yfield, weight, vdx, vdy, vcx, vcy, van.
% If the FieldNumber is given as 0, the data returned is a 2-element row vector containing type, number.
% The parameter type is an integer; either 0, 1, or 2, for angles in degrees, object height, or paraxial image height,
% respectively and 3 for real image height. The parameter number is the number of fields currently defined.
%
% See also zSetField, GetField.
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
DDECommand = sprintf('GetField,%i',FieldNumber);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if FieldNumber == 0
   [col, count, errmsg] = sscanf(Reply, '%i,%i');
else
   [col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f');
end
FieldData = col';



