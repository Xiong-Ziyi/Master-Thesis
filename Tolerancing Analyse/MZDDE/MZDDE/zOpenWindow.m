function Status = zOpenWindow(ButtonCode)
% zOpenWindow - Request ZEMAX DDE server to open a new analysis window on the main ZEMAX screen. 
%
% Usage : Status = zOpenWindow(ButtonCode)
%
% The ButtonCode argument is a 3 character case-sensitive label that indicates the type of analysis to be performed.
% The 3 letter labels are identical to those used for the button bar in ZEMAX. A list of codes can be obtained
% by typing "help zemaxbuttons" in Matlab. The labels are case sensitive. 
%
% NB : The analysis data appearing in the window is for the lens in the LDE, not the lens in the DDE
% server.
%
% See also GetMetaFile.
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
DDECommand = sprintf('OpenWindow,%s',ButtonCode);
Status = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);


