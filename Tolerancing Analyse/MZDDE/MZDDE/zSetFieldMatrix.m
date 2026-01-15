function FieldPoints = zSetFieldMatrix(FieldType, FieldDataMatrix)
% zSetFieldMatrix - sets all field points from a matrix
%
% Usage : FieldPoints = zSetFieldMatrix(FieldType, FieldDataMatrix)
%
% Create and pass a matrix having columns 8 columns of field data xf, yf, wgt, vdx, vdy, vcx, vcy, van
% If the matrix has fewer columns, it will be assumed that columns on the right are zero.
% The matrix can have from 1 to 12 rows.
% The function returns the number of field points set.
% The parameter FieldType is an integer; either 0, 1, or 2, for angles in degrees, object height, or paraxial image height,
% respectively, 3 for real image height.
%
% See also zGetField, zSetField
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
% $Revision: 1.2 $

FieldCount = size(FieldDataMatrix,1);
ColCount = size(FieldDataMatrix,2);
if (FieldCount > 12) FieldCount = 12; end;
if (FieldCount <= 0) FieldPoints = 0; return; end;
zSetFieldType(FieldType, FieldCount);
if (ColCount < 8)
   for iii = (ColCount+1):8,
      FieldDataMatrix(:,iii) = 0;
   end
end
for iii = 1:FieldCount,
   zSetField(iii, FieldDataMatrix(iii,1),FieldDataMatrix(iii,2),FieldDataMatrix(iii,3),FieldDataMatrix(iii,4),FieldDataMatrix(iii,5),FieldDataMatrix(iii,6),FieldDataMatrix(iii,7),FieldDataMatrix(iii,8));
end
FieldPoints = FieldCount;



