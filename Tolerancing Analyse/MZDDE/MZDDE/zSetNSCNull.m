function Status = zSetNSCNull(SurfaceNumber, FirstObject, LastObject)
% zSetNSCNull - Sets NSC objects to the Null Object at specified surface
%
% Usage : Status = zSetNSCNull(SurfaceNumber, FirstObject, LastObject)
%
% Sets the NSC objects FirstObject through to LastObject at the surface SurfaceNumber to
% be the 'Null Object'
%
% 
% Returns a status of 0 if successfull or -1 if not all objects could be set.

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


% Copyright 2004 Defencetek, CSIR
% $Revision: 1.0 $

Status = 0;
for ObjectNumber = FirstObject:LastObject
    NSCObjectDatum = zSetNSCObjectData(SurfaceNumber, ObjectNumber, 0, 'Null Object');
    if strncmp(NSCObjectDatum, 'BAD COMMAND', 11)
        Status = -1;
    end
end

