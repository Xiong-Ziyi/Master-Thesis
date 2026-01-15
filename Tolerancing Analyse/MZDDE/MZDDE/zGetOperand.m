function OperandDatum = zGetOperand(Row, Column)
% zGetOperand - Requests data from the Merit Function Editor in ZEMAX.
%
% Usage : OperandDatum = zGetOperand(Row, Column)
% Row is the operand row number in the Merit Function Editor. Column is 1 for type, 2 for int1, 3 for int2, 4-7 for
% hx-py, 8 for target, 9 for weight, 10 for value, and 11 for percent contribution. The returned datum is the numeric
% value of the requested parameter. All return types are numeric, including the operand type. If the command times out,
% NaN (Not-a-Number) is returned.
%
% For a list of type codes, type "help zemaxoperands" at the Matlab prompt.
%
% See also zSetOperand.
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
DDECommand = sprintf('GetOperand,%i,%i',Row, Column);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply) OperandDatum = str2num(Reply); else OperandDatum = NaN; end;


