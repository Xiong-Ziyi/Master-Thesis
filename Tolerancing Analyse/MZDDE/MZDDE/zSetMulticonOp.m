function [rOpType, Numbers] = zSetMulticonOp(RowNumber, OpType, Number1, Number2, Number3)
% zSetMulticonOp - Set an operand type and associated numerical parameters in the ZEMAX
% multi-configuration editor.
%
% Usage : [rOpType, Numbers] = zSetMulticonOp(RowNumber, OpType, Number1, Number2, Number3)
% where RowNumber is the row number in the multiconfiguration editor, OpType is the four letter
% multi-configuration operand name, and the 3 numbers complete the definition of the operand
% according to the 'Summary of Multi-Configuration Operands' section in the ZEMAX manual.
% The function echos the OpType and Numbers. Numbers is a 3-column row vector.
%
% See also zSetMulticon, zGetMulticon
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
DDECommand = sprintf('SetMulticon,0,%i,%s,%11.9f,%11.9f,%11.9f',RowNumber, OpType, Number1, Number2, Number3);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[rOpType, Reply] = strtok(Reply, ',');
[col, count, errmsg] = sscanf(Reply, ',%f,%f,%f');
Numbers = col';
