function NSCObjectData = zsSetNSCObject(SurfaceNumber, ObjectNumber, ObjectData)
% zsSetNSCObject - Sets NSC Object data from a structure.
%
% Usage : NSCObjectData = zsSetNSCObject(SurfaceNumber, ObjectNumber, ObjectData)
%
% SurfaceNumber is the sequential surface number containing NSC objects (0 if in full non-sequential
% mode). ObjectNumber is the number of the NSC object to set data on. The ObjectData must be a struct
% with any number of the following fields.
%
% Field Name  -   Datum
%  type       -   Object type name. (string)
%  comment    -   Comment, which also defines the file name if the object is defined by a file. (string)
%  color      -   Color. (integer)
%  userap     -   1 if object uses a user defined aperture file, 0 otherwise. (integer)
%  apfile     -   User defined aperture file name, if any. (string)
%  refobj     -   Reference object number. (integer)
%  inobj      -   Inside of object number. (integer)
%  pos        -   Vector containing the x, y and z coordinates of the object
%  tilts      -   Vector containing tilts of the object about the x, y and z axes in degrees.
%  material   -   Name of the material of which the object consists.
%  params     -   Vector of object parameters to set.
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


% Copyright 2004, Defencetek, CSIR
% $Revision: 1.0 $




