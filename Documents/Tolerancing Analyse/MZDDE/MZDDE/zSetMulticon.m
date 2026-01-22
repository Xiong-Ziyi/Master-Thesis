function [OperandType, OperandValue, OperandData] = zSetMulticon(ConfigNumber, RowNumber, Value)
% zSetMulticon - Set data in the ZEMAX multi-configuration editor.
%
% Usage : [OperandType, OperandValue, OperandData] = zSetMulticon(ConfigNumber, RowNumber, Value)
%
% If ConfigNumber is greater than 1 and less than or equal to the number of configurations, the returned
% parameters are as follows :
% OperandType is the four letter operand type name as detailed in the 'Multi-Configurations/Summary' 
% section of the ZEMAX manual.
% OperandValue could be numeric or a string depending on OperandType. If OperandType is 'GLSS',
% 'MOFF', 'MCOM', or 'COTN', then OperandValue is a string. Otherwise it is numeric.
% OperandData will be a row vector comprising NumberConfig and NumberRow which are the total number of 
% configs and rows in the multi-configuration editor.
%
% If the ConfigNumber is zero, the multicon operand type data is returned as follows:
% OperandType is the type of multicon operand as before
% OperandValue is zero and OperandData is a row vector comprising Number1, Number2, Number3
% These numbers are described in 'Summary of multi-configuration operands' in the ZEMAX manual.
%
% See also zSetMulticonOp, zGetMulticon.
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
% $Revision: 1.4 $

global ZemaxDDEChannel ZemaxDDETimeout

% First find out what type of operand we have at this row in the multicon editor
DDECommand = sprintf('GetMulticon,0,%i', RowNumber);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[OperandType, Reply] = strtok(Reply, ' ,');

% If the config number is zero, we don't set anything, just return the relevant stuff
if ConfigNumber == 0
   [col, count, errmsg] = sscanf(Reply, ',%f,%f,%f');
   OperandValue = 0;
   OperandData = col';
else % The config number is not zero
   if (OperandType == 'GLSS') | (OperandType == 'MCOM') | (OperandType == 'COTN') | (OperandType == 'MOFF') 
     DDECommand = sprintf('SetMulticon,%i,%i,%s',ConfigNumber, RowNumber, Value);
   else
     DDECommand = sprintf('SetMulticon,%i,%i,%f',ConfigNumber, RowNumber, Value);
   end
   Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1]);
   if (OperandType == 'GLSS') | (OperandType == 'MCOM') | (OperandType == 'COTN') | (OperandType == 'MOFF')
      [OperandValue, Reply] = strtok(Reply, ',');
      [col, count, errmsg] = sscanf(Reply, ',%f,%f');
      OperandData = col';
   else
      [col, count, errmsg] = sscanf(Reply, '%f,%f,%f');
      OperandValue = col(1);
      OperandData = col(2:3)';
   end
end
