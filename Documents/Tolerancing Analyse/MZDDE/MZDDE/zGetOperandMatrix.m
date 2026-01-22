function OperandMatrix = zGetOperandMatrix()
% zGetOperandMatrix - Uses a sequence of calls to zGetOperand until the entire Merit Function has been retrieved.
%
% Usage : OperandMatrix = zGetOperandMatrix
% Returns a matrix of 11 columns and as many rows as there are operands in the merit function. 
%
% See also zGetOperand
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

iii = 1;
OperandType = zGetOperand(iii, 1);
while (OperandType > 0)
   OperandMatrix(iii, 1) = OperandType;
   for jjj = 2:11,
      OperandMatrix(iii, jjj) = zGetOperand(iii, jjj);
   end
   iii = iii + 1;
   OperandType = zGetOperand(iii, 1);
end

