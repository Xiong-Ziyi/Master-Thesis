function [TolType, TolData] = zGetTol(TolNumber)
% zGetTol - Extracts lens tolerance data from the ZEMAX tolerance editor.
%
% Usage: [TolType, TolData] = zGetTol(TolNumber)

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


% where TolNumber the tolerance operand number. 
% If TolNumber is not zero, and corresponds to a valid
% tolerance operand number, the returned data contains the following
% TolType is a four letter mnemonic for the tolerance type
% TolData is a row vector containing the int1, int2, min, max
%
% If TolNumber is out of range, TolType returns 'TOFF' and Toldata returns the total number of operands
% as for zGetTolCount.
%
% See also zGetTolCount
%

% $Revision: 1.3 $

global ZemaxDDEChannel ZemaxDDETimeout
TolCount = zGetTolCount;
if (TolNumber >= 1) & (TolNumber <= TolCount) 
  DDECommand = sprintf('GetTol,%i',TolNumber);
  Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
  [TolType, Reply] = strtok(Reply, ' ,');
  [col, count, errmsg] = sscanf(Reply, ',%f,%f,%f,%f');
  TolData = col';
else
   TolType = 'TOFF';
   TolData = TolCount;
end


