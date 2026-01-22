function [TolTypes, TolMatrix] = zGetTolMatrix()
% zGetTolMatrix - Extracts a matrix containing all tolerance data from the ZEMAX tolerance editor.
%
% Usage: [TolTypes, TolMatrix] = zGetTolMatrix
%
% Retrieves all tolerance types in a column vector (TolTypes) of 4-letter mnemonics.
% TolMatrix is a matrix of tolerance parameters as defined for zGetTol.
%
% See also zGetTolCount, zGetTol
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
TolCount = zGetTolCount;
for iii = 1:TolCount 
  DDECommand = sprintf('GetTol,%i',iii);
  Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
  [Mnemonic, Reply] = strtok(Reply, ' ,');
  TolTypes(iii,:) = Mnemonic;
  [col, count, errmsg] = sscanf(Reply, ',%f,%f,%f,%f');
  TolMatrix(iii,1) = col(1);
  TolMatrix(iii,2) = col(2);
  TolMatrix(iii,3) = col(3);
  TolMatrix(iii,4) = col(4);
end



