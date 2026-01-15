function NSCObjectDatum = zSetNSCObjectData(SurfaceNumber, ObjectNumber, ItemCode, Datum)
% zSetNSCObjectData - Sets one of the NSC data items in the NSC data editor.
%
% Usage : NSCObjectDatum = zSetNSCObjectData(SurfaceNumber, ObjectNumber, ItemCode, Datum)
% SurfaceNumber is the sequential surface number containing NSC objects (0 if in full non-sequential
% mode). ObjectNumber is the number of the NSC object to set a data item on, ItemCode is one of the
% following codes and Datum is the value to which the item should be set. Ensure that the Datum has
% the correct type as per the table.
%
% Code  -   Datum to be set
%  0    -   Object type name. (string)
%  1    -   Comment, which also defines the file name if the object is defined by a file. (string)
%  2    -   Color. (integer)
%  3    -   1 if object uses a user defined aperture file, 0 otherwise. (integer)
%  4    -   User defined aperture file name, if any. (string)
%  5    -   Reference object number. (integer)
%  6    -   Inside of object number. (integer)
%  7 and up Reserved for future expansion of this feature.
%
% To set the position, rotation and material of the NSC object, use zSetNSCPosition.
%
% The returned value is just the Datum.
%
% See also : zGetNSCObjectData, zSetNSCPosition
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
% Decide whether item is string or numeric - should check that the user has sent the right thing
switch ItemCode
  case {0, 1, 4},    DDECommand = sprintf('SetNSCObjectData,%i,%i,%i,%s', SurfaceNumber, ObjectNumber, ItemCode, Datum);
  case {2, 3, 5, 6}, DDECommand = sprintf('SetNSCObjectData,%i,%i,%i,%11.9f', SurfaceNumber, ObjectNumber, ItemCode, Datum);
end
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
% Decide whether to return string or numeric datum
switch ItemCode
  case {0, 1, 4}, NSCObjectDatum = Reply;
  case {2, 3, 5, 6}, [NSCObjectDatum, count, errmsg] = sscanf(Reply, '%f');
end


