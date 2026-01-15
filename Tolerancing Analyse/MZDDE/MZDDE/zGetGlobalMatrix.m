function [RotationMatrix,ColVector] = zGetGlobalMatrix(SurfaceNumber)
% zGetGlobalMatrix - Requests global matrix transform for a lens surface.
%
% Usage : [RotationMatrix,ColVector] = zGetGlobalMatrix(SurfaceNumber)
%
% Returns the matrix required to convert any local coordinates (such as from a ray trace) into global
% coordinates. For details on the global coordinate matrix, see the section “Global Coordinate Reference Surface“
% in the System Menu chapter of the ZEMAX manual. Also returns the column vector which must be added
% to the rotated vector to yield the global coordinates.
%
% That is GlobalColVector = ColVector + RotationMatrix * LocalColVector
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
DDECommand = sprintf('GetGlobalMatrix,%i',SurfaceNumber);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f');
RotationMatrix(1,1) = col(1);
RotationMatrix(1,2) = col(2);
RotationMatrix(1,3) = col(3);
RotationMatrix(2,1) = col(4);
RotationMatrix(2,2) = col(5);
RotationMatrix(2,3) = col(6);
RotationMatrix(3,1) = col(7);
RotationMatrix(3,2) = col(8);
RotationMatrix(3,3) = col(9);
ColVector(1,1) = col(10);
ColVector(2,1) = col(11);
ColVector(3,1) = col(12);



