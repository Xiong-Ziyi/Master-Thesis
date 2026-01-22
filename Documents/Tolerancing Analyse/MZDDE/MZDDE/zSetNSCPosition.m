function [NSCPositionData, NSCMaterial] = zSetNSCPosition(SurfaceNumber, ObjectNumber, ItemCode, Datum)
% zSetNSCPosition - Sets one of the NSC position data items in the NSC data editor.
%
% Usage : [NSCPositionData, NSCMaterial] = zSetNSCPosition(SurfaceNumber, ObjectNumber, ItemCode, Datum)
% SurfaceNumber is the sequential surface number containing NSC objects (0 if in full non-sequential
% mode). ObjectNumber is the number of the NSC object to set a data item on, ItemCode is one of the
% following codes and Datum is the value to which the item should be set. Ensure that the Datum has
% the correct type as per the table.
%
% Code  -   Datum to be set
%  1    -   x position (lens units)
%  2    -   y position
%  3    -   z position
%  4    -   tilt about x (degrees)
%  5    -   tilt about y
%  6    -   tilt about z
%  7    -   material (string value)
%
% The NSCPositionData returned is a 6 component row vector with the new position and tilt of the
% component. NSCMaterial is a string containing the material of the component.
%
% To set other data for an NSC object, use zSetNSCObjectData.
%
% See also : zGetNSCObjectData, zSetNSCObjectData
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
  case num2cell(1:6), DDECommand = sprintf('SetNSCPosition,%i,%i,%i,%11.9f', SurfaceNumber, ObjectNumber, ItemCode, Datum);
  case {7},   DDECommand = sprintf('SetNSCPosition,%i,%i,%i,%s', SurfaceNumber, ObjectNumber, ItemCode, Datum);
end
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[NSCPositionData, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f');
NSCPositionData = NSCPositionData';
[NSCMaterial, count, errmsg] = sscanf(Reply, '%*f,%*f,%*f,%*f,%*f,%*f,%s'); 
