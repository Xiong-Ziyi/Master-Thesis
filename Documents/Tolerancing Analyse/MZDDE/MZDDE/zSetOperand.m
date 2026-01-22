function OperandDatum = zSetOperand(Row, Column, Value)
% zSetOperand - Inserts data into the Merit Function Editor in ZEMAX.
%
% Usage : OperandDatum = zSetOperand(Row, Column, Value)
% Row is the operand row number in the Merit Function Editor. Column is 1 for type, 2 for int1, 3 for int2, 4-7 for
% hx-py, 8 for target, and 9 for weight. The returned value is the same as for zGetOperand. 
%
% For a list of type codes, type "help zemaxoperands" at the Matlab prompt.
% Returns the Value or NaN (not-a-number) if the command times out.
%
% See also zSetOperandMatrix, zGetOperand, zGetOperandMatrix
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
DDECommand = sprintf('SetOperand,%i,%i,%11.9f',Row, Column, Value);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply), OperandDatum = str2double(Reply); else OperandDatum = NaN; end;


