function ObjectDatum = zGetNSCObjectData(Surface, Object, Code)
% zGetNSCObjectData - Requests various data for NSC objects from the ZEMAX DDE server.
%
% Usage : Datum = zGetNSCObjectData(Surface, Object, Code);
%
% Surface and Object refer to the surface number and object number. The Code is one of the integer values in the
% list below; the returned value is the data item indicated. 
%
% Code  -   Data returned
%  0    -   Object type name. (string)
%  1    -   Comment, which also defines the file name if the object is defined by a file. (string)
%  2    -   Color. (integer)
%  3    -   1 if object uses a user defined aperture file, 0 otherwise. (integer)
%  4    -   User defined aperture file name, if any. (string)
%  5    -   Reference object number. (integer)
%  6    -   Inside of object number. (integer)
%  7 and up Reserved for future expansion of this feature.
%
% See also zSetNSCObjectData, zSetNSCPosition
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
DDECommand = sprintf('GetNSCObjectData,%i,%i,%i', Surface, Object, Code);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
% Decide whether to return string or numeric datum
switch Code
  case {0, 1, 4}, ObjectDatum = Reply;
  case {2, 3, 5, 6}, [ObjectDatum, count, errmsg] = sscanf(Reply, '%f');
end


