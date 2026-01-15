function Status = zDDEBusy()
% zDDEBusy - Checks to see if the ZEMAX DDE server is still busy with a function.
%
% Usage example : while (zDDEBusy) end;
%
% Will return immediately with the value 0 if the ZEMAX DDE server is available
% Returns 1 after the DDE timeout period if the server is busy.;
%
% See also : zSetTimeout, zGetTimeout
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
% $Revision: 1.1 $

global ZemaxDDEChannel ZemaxDDETimeout
if (zGetDate)
    Status = 0;
else
    Status = 1;
end
